/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "correlation.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/sequencestatistics.hpp>
#include <qlo/correlation.hpp>
#include <qlo/curvestate.hpp>
#include <qlo/evolutiondescription.hpp>
#include <qlo/indexes/iborindex.hpp>
#include <qlo/indexes/swapindex.hpp>
#include <ql/models/marketmodels/correlations/expcorrelations.hpp>
#include <ql/models/marketmodels/historicalforwardratesanalysis.hpp>
#include <ql/models/marketmodels/historicalratesanalysis.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void MarketModelLmLinearExponentialCorrelationModelWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMarketModelLmLinearExponentialCorrelationModel(
          mObjectID,
          mSize,
          mRho,
          mBeta,
          mFactors,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::LmLinearExponentialCorrelationModel(
          valueObject,
          mSize,
          mRho,
          mBeta,
          mFactors,
          false
      ));

    // Store the Object in the Repository
    mReturnValue = ObjectHandler::Repository::instance().storeObject(mObjectID, object, false, valueObject);
    
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelLmLinearExponentialCorrelationModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelLmLinearExponentialCorrelationModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Size is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Rho is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Factors is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long SizeCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  double RhoCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  long FactorsCpp = Nan::To<int32_t>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelLmLinearExponentialCorrelationModelWorker(
    callback
    ,ObjectIDCpp
    ,SizeCpp
    ,RhoCpp
    ,BetaCpp
    ,FactorsCpp
  ));

}

//MarketModelLmLinearExponentialCorrelationModelWorker::~MarketModelLmLinearExponentialCorrelationModelWorker(){
//
//}

//void MarketModelLmLinearExponentialCorrelationModelWorker::Destroy(){
//
//}

void HistoricalForwardRatesAnalysisWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(SequenceStatsLibObjPtr, mSequenceStats,
      QuantLibAddin::SequenceStatistics, QuantLib::SequenceStatistics)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EndDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEndDate, "EndDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period StepLib;
  QuantLibAddin::cppToLibrary(mStep, StepLib);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period InitialGapLib;
  QuantLibAddin::cppToLibrary(mInitialGap, InitialGapLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period HorizonLib;
  QuantLibAddin::cppToLibrary(mHorizon, HorizonLib);


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::IborIndex> > IborIndexesLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::IborIndex, QuantLib::IborIndex>(mIborIndexes);


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::SwapIndex> > SwapIndexesLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::SwapIndex, QuantLib::SwapIndex>(mSwapIndexes);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlHistoricalForwardRatesAnalysis(
          mObjectID,
          mSequenceStats,
          mStartDate,
          mEndDate,
          mStep,
          mIborIndex,
          mInitialGap,
          mHorizon,
          mIborIndexes,
          mSwapIndexes,
          mDayCounter,
          mTraitsID,
          mInterpolatorID,
          mBootstrapAccuracy,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::HistoricalForwardRatesAnalysis(
          valueObject,
          SequenceStatsLibObjPtr,
          StartDateLib,
          EndDateLib,
          StepLib,
          IborIndexLibObjPtr,
          InitialGapLib,
          HorizonLib,
          IborIndexesLibObjPtr,
          SwapIndexesLibObjPtr,
          DayCounterEnum,
          mTraitsID,
          mInterpolatorID,
          mBootstrapAccuracy,
          false
      ));

    // Store the Object in the Repository
    mReturnValue = ObjectHandler::Repository::instance().storeObject(mObjectID, object, false, valueObject);
    
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HistoricalForwardRatesAnalysisWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HistoricalForwardRatesAnalysis) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("SequenceStats is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Step is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("InitialGap is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("Horizon is required.");
  }
  if (info.Length() == 8 || !info[8]->IsArray()) {
      return Nan::ThrowError("IborIndexes is required.");
  }
  if (info.Length() == 9 || !info[9]->IsArray()) {
      return Nan::ThrowError("SwapIndexes is required.");
  }
  if (info.Length() == 10 || !info[10]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 11 || !info[11]->IsString()) {
      return Nan::ThrowError("TraitsID is required.");
  }
  if (info.Length() == 12 || !info[12]->IsString()) {
      return Nan::ThrowError("InterpolatorID is required.");
  }
  if (info.Length() == 13 || !info[13]->IsNumber()) {
      return Nan::ThrowError("BootstrapAccuracy is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strSequenceStats(info[1]->ToString());
  string SequenceStatsCpp(strdup(*strSequenceStats));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t EndDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strStep(info[4]->ToString());
  string StepCpp(strdup(*strStep));

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[5]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  String::Utf8Value strInitialGap(info[6]->ToString());
  string InitialGapCpp(strdup(*strInitialGap));

  // convert js argument to c++ type
  String::Utf8Value strHorizon(info[7]->ToString());
  string HorizonCpp(strdup(*strHorizon));

  // convert js argument to c++ type
  std::vector<string>IborIndexesCpp;

  Local<Array> IborIndexesArray = info[8].As<Array>();
  for (unsigned int i = 0; i < IborIndexesArray->Length(); i++){
    String::Utf8Value strIborIndexes(Nan::Get(IborIndexesArray, i).ToLocalChecked()->ToString());
    IborIndexesCpp.push_back(strdup(*strIborIndexes));
  }

  // convert js argument to c++ type
  std::vector<string>SwapIndexesCpp;

  Local<Array> SwapIndexesArray = info[9].As<Array>();
  for (unsigned int i = 0; i < SwapIndexesArray->Length(); i++){
    String::Utf8Value strSwapIndexes(Nan::Get(SwapIndexesArray, i).ToLocalChecked()->ToString());
    SwapIndexesCpp.push_back(strdup(*strSwapIndexes));
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[10]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strTraitsID(info[11]->ToString());
  string TraitsIDCpp(strdup(*strTraitsID));

  // convert js argument to c++ type
  String::Utf8Value strInterpolatorID(info[12]->ToString());
  string InterpolatorIDCpp(strdup(*strInterpolatorID));

  // convert js argument to c++ type
  double BootstrapAccuracyCpp = Nan::To<double>(info[13]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[14].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HistoricalForwardRatesAnalysisWorker(
    callback
    ,ObjectIDCpp
    ,SequenceStatsCpp
    ,StartDateCpp
    ,EndDateCpp
    ,StepCpp
    ,IborIndexCpp
    ,InitialGapCpp
    ,HorizonCpp
    ,IborIndexesCpp
    ,SwapIndexesCpp
    ,DayCounterCpp
    ,TraitsIDCpp
    ,InterpolatorIDCpp
    ,BootstrapAccuracyCpp
  ));

}

//HistoricalForwardRatesAnalysisWorker::~HistoricalForwardRatesAnalysisWorker(){
//
//}

//void HistoricalForwardRatesAnalysisWorker::Destroy(){
//
//}

void HistoricalRatesAnalysisWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(SequenceStatsLibObjPtr, mSequenceStats,
      QuantLibAddin::SequenceStatistics, QuantLib::SequenceStatistics)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EndDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEndDate, "EndDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period StepLib;
  QuantLibAddin::cppToLibrary(mStep, StepLib);


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::InterestRateIndex> > InterestRateIndexesLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::InterestRateIndex, QuantLib::InterestRateIndex>(mInterestRateIndexes);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlHistoricalRatesAnalysis(
          mObjectID,
          mSequenceStats,
          mStartDate,
          mEndDate,
          mStep,
          mInterestRateIndexes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::HistoricalRatesAnalysis(
          valueObject,
          SequenceStatsLibObjPtr,
          StartDateLib,
          EndDateLib,
          StepLib,
          InterestRateIndexesLibObjPtr,
          false
      ));

    // Store the Object in the Repository
    mReturnValue = ObjectHandler::Repository::instance().storeObject(mObjectID, object, false, valueObject);
    
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HistoricalRatesAnalysisWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HistoricalRatesAnalysis) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("SequenceStats is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Step is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("InterestRateIndexes is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strSequenceStats(info[1]->ToString());
  string SequenceStatsCpp(strdup(*strSequenceStats));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t EndDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strStep(info[4]->ToString());
  string StepCpp(strdup(*strStep));

  // convert js argument to c++ type
  std::vector<string>InterestRateIndexesCpp;

  Local<Array> InterestRateIndexesArray = info[5].As<Array>();
  for (unsigned int i = 0; i < InterestRateIndexesArray->Length(); i++){
    String::Utf8Value strInterestRateIndexes(Nan::Get(InterestRateIndexesArray, i).ToLocalChecked()->ToString());
    InterestRateIndexesCpp.push_back(strdup(*strInterestRateIndexes));
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HistoricalRatesAnalysisWorker(
    callback
    ,ObjectIDCpp
    ,SequenceStatsCpp
    ,StartDateCpp
    ,EndDateCpp
    ,StepCpp
    ,InterestRateIndexesCpp
  ));

}

//HistoricalRatesAnalysisWorker::~HistoricalRatesAnalysisWorker(){
//
//}

//void HistoricalRatesAnalysisWorker::Destroy(){
//
//}

void TimeHomogeneousForwardCorrelationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix FwdCorrMatrixLib = QuantLibAddin::vvToQlMatrix(mFwdCorrMatrix);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlTimeHomogeneousForwardCorrelation(
          mObjectID,
          mFwdCorrMatrix,
          mRateTimes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::TimeHomogeneousForwardCorrelation(
          valueObject,
          FwdCorrMatrixLib,
          mRateTimes,
          false
      ));

    // Store the Object in the Repository
    mReturnValue = ObjectHandler::Repository::instance().storeObject(mObjectID, object, false, valueObject);
    
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TimeHomogeneousForwardCorrelationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TimeHomogeneousForwardCorrelation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("FwdCorrMatrix is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FwdCorrMatrixCpp;

  Local<Array> FwdCorrMatrixMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FwdCorrMatrixMatrix->Length(); i++){
	  Local<Array> FwdCorrMatrixArray = FwdCorrMatrixMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FwdCorrMatrixArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FwdCorrMatrixArray, j).ToLocalChecked()).FromJust());
	  }
	  FwdCorrMatrixCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RateTimesCpp;

  Local<Array> RateTimesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RateTimesArray->Length(); i++){
    RateTimesCpp.push_back(Nan::To<double>(Nan::Get(RateTimesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TimeHomogeneousForwardCorrelationWorker(
    callback
    ,ObjectIDCpp
    ,FwdCorrMatrixCpp
    ,RateTimesCpp
  ));

}

//TimeHomogeneousForwardCorrelationWorker::~TimeHomogeneousForwardCorrelationWorker(){
//
//}

//void TimeHomogeneousForwardCorrelationWorker::Destroy(){
//
//}

void ExponentialForwardCorrelationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlExponentialForwardCorrelation(
          mObjectID,
          mRateTimes,
          mLongTermCorr,
          mBeta,
          mGamma,
          mTimes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ExponentialForwardCorrelation(
          valueObject,
          mRateTimes,
          mLongTermCorr,
          mBeta,
          mGamma,
          mTimes,
          false
      ));

    // Store the Object in the Repository
    mReturnValue = ObjectHandler::Repository::instance().storeObject(mObjectID, object, false, valueObject);
    
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ExponentialForwardCorrelationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ExponentialForwardCorrelation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("LongTermCorr is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Gamma is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("Times is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>RateTimesCpp;

  Local<Array> RateTimesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < RateTimesArray->Length(); i++){
    RateTimesCpp.push_back(Nan::To<double>(Nan::Get(RateTimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double LongTermCorrCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double GammaCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  std::vector<double>TimesCpp;

  Local<Array> TimesArray = info[5].As<Array>();
  for (unsigned int i = 0; i < TimesArray->Length(); i++){
    TimesCpp.push_back(Nan::To<double>(Nan::Get(TimesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ExponentialForwardCorrelationWorker(
    callback
    ,ObjectIDCpp
    ,RateTimesCpp
    ,LongTermCorrCpp
    ,BetaCpp
    ,GammaCpp
    ,TimesCpp
  ));

}

//ExponentialForwardCorrelationWorker::~ExponentialForwardCorrelationWorker(){
//
//}

//void ExponentialForwardCorrelationWorker::Destroy(){
//
//}

void CotSwapFromFwdCorrelationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(FwdCorrLibObjPtr, mFwdCorr,
      QuantLibAddin::PiecewiseConstantCorrelation, QuantLib::PiecewiseConstantCorrelation)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCotSwapFromFwdCorrelation(
          mObjectID,
          mFwdCorr,
          mCurveState,
          mDisplacement,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CotSwapFromFwdCorrelation(
          valueObject,
          FwdCorrLibObjPtr,
          CurveStateLibObj,
          mDisplacement,
          false
      ));

    // Store the Object in the Repository
    mReturnValue = ObjectHandler::Repository::instance().storeObject(mObjectID, object, false, valueObject);
    
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CotSwapFromFwdCorrelationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CotSwapFromFwdCorrelation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("FwdCorr is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strFwdCorr(info[1]->ToString());
  string FwdCorrCpp(strdup(*strFwdCorr));

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[2]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CotSwapFromFwdCorrelationWorker(
    callback
    ,ObjectIDCpp
    ,FwdCorrCpp
    ,CurveStateCpp
    ,DisplacementCpp
  ));

}

//CotSwapFromFwdCorrelationWorker::~CotSwapFromFwdCorrelationWorker(){
//
//}

//void CotSwapFromFwdCorrelationWorker::Destroy(){
//
//}

void HistoricalForwardRatesAnalysisSkippedDatesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::HistoricalForwardRatesAnalysis, QuantLib::HistoricalForwardRatesAnalysis)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Date> returnValue = ObjectIDLibObjPtr->skippedDates(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HistoricalForwardRatesAnalysisSkippedDatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Number>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HistoricalForwardRatesAnalysisSkippedDates) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HistoricalForwardRatesAnalysisSkippedDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//HistoricalForwardRatesAnalysisSkippedDatesWorker::~HistoricalForwardRatesAnalysisSkippedDatesWorker(){
//
//}

//void HistoricalForwardRatesAnalysisSkippedDatesWorker::Destroy(){
//
//}

void HistoricalForwardRatesAnalysisSkippedDatesErrorMessageWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::HistoricalForwardRatesAnalysis, QuantLib::HistoricalForwardRatesAnalysis)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->skippedDatesErrorMessage(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HistoricalForwardRatesAnalysisSkippedDatesErrorMessageWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<String>(mReturnValue[i]).ToLocalChecked());
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HistoricalForwardRatesAnalysisSkippedDatesErrorMessage) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HistoricalForwardRatesAnalysisSkippedDatesErrorMessageWorker(
    callback
    ,ObjectIDCpp
  ));

}

//HistoricalForwardRatesAnalysisSkippedDatesErrorMessageWorker::~HistoricalForwardRatesAnalysisSkippedDatesErrorMessageWorker(){
//
//}

//void HistoricalForwardRatesAnalysisSkippedDatesErrorMessageWorker::Destroy(){
//
//}

void HistoricalForwardRatesAnalysisFailedDatesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::HistoricalForwardRatesAnalysis, QuantLib::HistoricalForwardRatesAnalysis)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Date> returnValue = ObjectIDLibObjPtr->failedDates(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HistoricalForwardRatesAnalysisFailedDatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Number>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HistoricalForwardRatesAnalysisFailedDates) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HistoricalForwardRatesAnalysisFailedDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//HistoricalForwardRatesAnalysisFailedDatesWorker::~HistoricalForwardRatesAnalysisFailedDatesWorker(){
//
//}

//void HistoricalForwardRatesAnalysisFailedDatesWorker::Destroy(){
//
//}

void HistoricalForwardRatesAnalysisFailedDatesErrorMessageWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::HistoricalForwardRatesAnalysis, QuantLib::HistoricalForwardRatesAnalysis)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->failedDatesErrorMessage(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HistoricalForwardRatesAnalysisFailedDatesErrorMessageWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<String>(mReturnValue[i]).ToLocalChecked());
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HistoricalForwardRatesAnalysisFailedDatesErrorMessage) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HistoricalForwardRatesAnalysisFailedDatesErrorMessageWorker(
    callback
    ,ObjectIDCpp
  ));

}

//HistoricalForwardRatesAnalysisFailedDatesErrorMessageWorker::~HistoricalForwardRatesAnalysisFailedDatesErrorMessageWorker(){
//
//}

//void HistoricalForwardRatesAnalysisFailedDatesErrorMessageWorker::Destroy(){
//
//}

void HistoricalForwardRatesAnalysisFixingPeriodsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::HistoricalForwardRatesAnalysis, QuantLib::HistoricalForwardRatesAnalysis)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Period> returnValue = ObjectIDLibObjPtr->fixingPeriods(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HistoricalForwardRatesAnalysisFixingPeriodsWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<String>(mReturnValue[i]).ToLocalChecked());
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HistoricalForwardRatesAnalysisFixingPeriods) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HistoricalForwardRatesAnalysisFixingPeriodsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//HistoricalForwardRatesAnalysisFixingPeriodsWorker::~HistoricalForwardRatesAnalysisFixingPeriodsWorker(){
//
//}

//void HistoricalForwardRatesAnalysisFixingPeriodsWorker::Destroy(){
//
//}

void HistoricalRatesAnalysisSkippedDatesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::HistoricalRatesAnalysis, QuantLib::HistoricalRatesAnalysis)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Date> returnValue = ObjectIDLibObjPtr->skippedDates(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HistoricalRatesAnalysisSkippedDatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Number>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HistoricalRatesAnalysisSkippedDates) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HistoricalRatesAnalysisSkippedDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//HistoricalRatesAnalysisSkippedDatesWorker::~HistoricalRatesAnalysisSkippedDatesWorker(){
//
//}

//void HistoricalRatesAnalysisSkippedDatesWorker::Destroy(){
//
//}

void HistoricalRatesAnalysisSkippedDatesErrorMessageWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::HistoricalRatesAnalysis, QuantLib::HistoricalRatesAnalysis)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->skippedDatesErrorMessage(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HistoricalRatesAnalysisSkippedDatesErrorMessageWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<String>(mReturnValue[i]).ToLocalChecked());
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HistoricalRatesAnalysisSkippedDatesErrorMessage) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HistoricalRatesAnalysisSkippedDatesErrorMessageWorker(
    callback
    ,ObjectIDCpp
  ));

}

//HistoricalRatesAnalysisSkippedDatesErrorMessageWorker::~HistoricalRatesAnalysisSkippedDatesErrorMessageWorker(){
//
//}

//void HistoricalRatesAnalysisSkippedDatesErrorMessageWorker::Destroy(){
//
//}

void PiecewiseConstantCorrelationCorrelationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantCorrelation, QuantLib::PiecewiseConstantCorrelation)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size TimeIndexLib;
  QuantLibAddin::cppToLibrary(mTimeIndex, TimeIndexLib);

       QuantLib::Matrix returnValue;


  // invoke the member function
  returnValue = ObjectIDLibObjPtr->correlation(
        TimeIndexLib
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantCorrelationCorrelationWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpMatrix = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Local<Array> tmpArray = Nan::New<Array>(mReturnValue[i].size());
      for (unsigned int j = 0; j < mReturnValue[i].size(); j++) {
        Nan::Set(tmpArray,j,Nan::New<Number>(mReturnValue[i][j]));
      }
      Nan::Set(tmpMatrix,i,tmpArray);
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpMatrix
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseConstantCorrelationCorrelation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeIndex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long TimeIndexCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseConstantCorrelationCorrelationWorker(
    callback
    ,ObjectIDCpp
    ,TimeIndexCpp
  ));

}

//PiecewiseConstantCorrelationCorrelationWorker::~PiecewiseConstantCorrelationCorrelationWorker(){
//
//}

//void PiecewiseConstantCorrelationCorrelationWorker::Destroy(){
//
//}

void PiecewiseConstantCorrelationTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantCorrelation, QuantLib::PiecewiseConstantCorrelation)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->times(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantCorrelationTimesWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Number>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseConstantCorrelationTimes) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseConstantCorrelationTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseConstantCorrelationTimesWorker::~PiecewiseConstantCorrelationTimesWorker(){
//
//}

//void PiecewiseConstantCorrelationTimesWorker::Destroy(){
//
//}

void PiecewiseConstantCorrelationNumberOfRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantCorrelation, QuantLib::PiecewiseConstantCorrelation)

     
  // invoke the member function
  QuantLib::Size returnValue = ObjectIDLibObjPtr->numberOfRates(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantCorrelationNumberOfRatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseConstantCorrelationNumberOfRates) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseConstantCorrelationNumberOfRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseConstantCorrelationNumberOfRatesWorker::~PiecewiseConstantCorrelationNumberOfRatesWorker(){
//
//}

//void PiecewiseConstantCorrelationNumberOfRatesWorker::Destroy(){
//
//}

void ExponentialCorrelationsWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::exponentialCorrelations(
        mRateTimes
       ,
         mLongTermCorr
       ,
         mBeta
       ,
         mGamma
       ,
         mTime
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ExponentialCorrelationsWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpMatrix = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Local<Array> tmpArray = Nan::New<Array>(mReturnValue[i].size());
      for (unsigned int j = 0; j < mReturnValue[i].size(); j++) {
        Nan::Set(tmpArray,j,Nan::New<Number>(mReturnValue[i][j]));
      }
      Nan::Set(tmpMatrix,i,tmpArray);
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpMatrix
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ExponentialCorrelations) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("LongTermCorr is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Gamma is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Time is required.");
  }
  // convert js argument to c++ type
  std::vector<double>RateTimesCpp;

  Local<Array> RateTimesArray = info[0].As<Array>();
  for (unsigned int i = 0; i < RateTimesArray->Length(); i++){
    RateTimesCpp.push_back(Nan::To<double>(Nan::Get(RateTimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double LongTermCorrCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double GammaCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double TimeCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ExponentialCorrelationsWorker(
    callback
    ,RateTimesCpp
    ,LongTermCorrCpp
    ,BetaCpp
    ,GammaCpp
    ,TimeCpp
  ));

}

//ExponentialCorrelationsWorker::~ExponentialCorrelationsWorker(){
//
//}

//void ExponentialCorrelationsWorker::Destroy(){
//
//}
 