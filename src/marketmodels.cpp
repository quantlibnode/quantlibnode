/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "marketmodels.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/marketmodels.hpp>
#include <qlo/curvestate.hpp>
#include <qlo/evolutiondescription.hpp>
#include <qlo/correlation.hpp>
#include <qlo/ctsmmcapletcalibration.hpp>
#include <qlo/yieldtermstructures.hpp>
#include <ql/models/marketmodels/models/fwdperiodadapter.hpp>
#include <ql/models/marketmodels/swapforwardmappings.hpp>
#include <ql/models/marketmodels/models/capletcoterminalalphacalibration.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void FlatVolWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(CorrelationsLibObjPtr, mCorrelations,
      QuantLibAddin::PiecewiseConstantCorrelation, QuantLib::PiecewiseConstantCorrelation)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionDescriptionLibObj, mEvolutionDescription,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFlatVol(
          mObjectID,
          mVolatilities,
          mCorrelations,
          mEvolutionDescription,
          mFactors,
          mInitialRates,
          mDisplacements,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FlatVol(
          valueObject,
          mVolatilities,
          CorrelationsLibObjPtr,
          EvolutionDescriptionLibObj,
          mFactors,
          mInitialRates,
          mDisplacements,
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

void FlatVolWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FlatVol) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Volatilities is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Correlations is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("EvolutionDescription is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("InitialRates is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("Displacements is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>VolatilitiesCpp;

  Local<Array> VolatilitiesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < VolatilitiesArray->Length(); i++){
    VolatilitiesCpp.push_back(Nan::To<double>(Nan::Get(VolatilitiesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strCorrelations(info[2]->ToString());
  string CorrelationsCpp(strdup(*strCorrelations));

  // convert js argument to c++ type
  String::Utf8Value strEvolutionDescription(info[3]->ToString());
  string EvolutionDescriptionCpp(strdup(*strEvolutionDescription));

  // convert js argument to c++ type
  long FactorsCpp = Nan::To<int32_t>(info[4]).FromJust();

  // convert js argument to c++ type
  std::vector<double>InitialRatesCpp;

  Local<Array> InitialRatesArray = info[5].As<Array>();
  for (unsigned int i = 0; i < InitialRatesArray->Length(); i++){
    InitialRatesCpp.push_back(Nan::To<double>(Nan::Get(InitialRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>DisplacementsCpp;

  Local<Array> DisplacementsArray = info[6].As<Array>();
  for (unsigned int i = 0; i < DisplacementsArray->Length(); i++){
    DisplacementsCpp.push_back(Nan::To<double>(Nan::Get(DisplacementsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FlatVolWorker(
    callback
    ,ObjectIDCpp
    ,VolatilitiesCpp
    ,CorrelationsCpp
    ,EvolutionDescriptionCpp
    ,FactorsCpp
    ,InitialRatesCpp
    ,DisplacementsCpp
  ));

}

//FlatVolWorker::~FlatVolWorker(){
//
//}

//void FlatVolWorker::Destroy(){
//
//}

void AbcdVolWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(CorrelationsLibObjPtr, mCorrelations,
      QuantLibAddin::PiecewiseConstantCorrelation, QuantLib::PiecewiseConstantCorrelation)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionDescriptionLibObj, mEvolutionDescription,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlAbcdVol(
          mObjectID,
          mA,
          mB,
          mC,
          mD,
          mKs,
          mCorrelations,
          mEvolutionDescription,
          mFactors,
          mInitialRates,
          mDisplacements,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::AbcdVol(
          valueObject,
          mA,
          mB,
          mC,
          mD,
          mKs,
          CorrelationsLibObjPtr,
          EvolutionDescriptionLibObj,
          mFactors,
          mInitialRates,
          mDisplacements,
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

void AbcdVolWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdVol) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("A is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("B is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("C is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("D is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("Ks is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("Correlations is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("EvolutionDescription is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 9 || !info[9]->IsArray()) {
      return Nan::ThrowError("InitialRates is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("Displacements is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double ACpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double BCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double CCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  std::vector<double>KsCpp;

  Local<Array> KsArray = info[5].As<Array>();
  for (unsigned int i = 0; i < KsArray->Length(); i++){
    KsCpp.push_back(Nan::To<double>(Nan::Get(KsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strCorrelations(info[6]->ToString());
  string CorrelationsCpp(strdup(*strCorrelations));

  // convert js argument to c++ type
  String::Utf8Value strEvolutionDescription(info[7]->ToString());
  string EvolutionDescriptionCpp(strdup(*strEvolutionDescription));

  // convert js argument to c++ type
  long FactorsCpp = Nan::To<int32_t>(info[8]).FromJust();

  // convert js argument to c++ type
  std::vector<double>InitialRatesCpp;

  Local<Array> InitialRatesArray = info[9].As<Array>();
  for (unsigned int i = 0; i < InitialRatesArray->Length(); i++){
    InitialRatesCpp.push_back(Nan::To<double>(Nan::Get(InitialRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>DisplacementsCpp;

  Local<Array> DisplacementsArray = info[10].As<Array>();
  for (unsigned int i = 0; i < DisplacementsArray->Length(); i++){
    DisplacementsCpp.push_back(Nan::To<double>(Nan::Get(DisplacementsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[11].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdVolWorker(
    callback
    ,ObjectIDCpp
    ,ACpp
    ,BCpp
    ,CCpp
    ,DCpp
    ,KsCpp
    ,CorrelationsCpp
    ,EvolutionDescriptionCpp
    ,FactorsCpp
    ,InitialRatesCpp
    ,DisplacementsCpp
  ));

}

//AbcdVolWorker::~AbcdVolWorker(){
//
//}

//void AbcdVolWorker::Destroy(){
//
//}

void PseudoRootFacadeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(CalibratorLibObjPtr, mCalibrator,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlPseudoRootFacade(
          mObjectID,
          mCalibrator,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::PseudoRootFacade(
          valueObject,
          CalibratorLibObjPtr,
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

void PseudoRootFacadeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PseudoRootFacade) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Calibrator is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCalibrator(info[1]->ToString());
  string CalibratorCpp(strdup(*strCalibrator));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PseudoRootFacadeWorker(
    callback
    ,ObjectIDCpp
    ,CalibratorCpp
  ));

}

//PseudoRootFacadeWorker::~PseudoRootFacadeWorker(){
//
//}

//void PseudoRootFacadeWorker::Destroy(){
//
//}

void CotSwapToFwdAdapterWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(CoterminalModelLibObjPtr, mCoterminalModel,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCotSwapToFwdAdapter(
          mObjectID,
          mCoterminalModel,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CotSwapToFwdAdapter(
          valueObject,
          CoterminalModelLibObjPtr,
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

void CotSwapToFwdAdapterWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CotSwapToFwdAdapter) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CoterminalModel is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCoterminalModel(info[1]->ToString());
  string CoterminalModelCpp(strdup(*strCoterminalModel));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CotSwapToFwdAdapterWorker(
    callback
    ,ObjectIDCpp
    ,CoterminalModelCpp
  ));

}

//CotSwapToFwdAdapterWorker::~CotSwapToFwdAdapterWorker(){
//
//}

//void CotSwapToFwdAdapterWorker::Destroy(){
//
//}

void FwdPeriodAdapterWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(LargeModelLibObjPtr, mLargeModel,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size PeriodLib;
  QuantLibAddin::cppToLibrary(mPeriod, PeriodLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size OffsetLib;
  QuantLibAddin::cppToLibrary(mOffset, OffsetLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFwdPeriodAdapter(
          mObjectID,
          mLargeModel,
          mPeriod,
          mOffset,
          mDisplacements,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FwdPeriodAdapter(
          valueObject,
          LargeModelLibObjPtr,
          PeriodLib,
          OffsetLib,
          mDisplacements,
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

void FwdPeriodAdapterWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FwdPeriodAdapter) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("LargeModel is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Period is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Offset is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("Displacements is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strLargeModel(info[1]->ToString());
  string LargeModelCpp(strdup(*strLargeModel));

  // convert js argument to c++ type
  long PeriodCpp = Nan::To<int32_t>(info[2]).FromJust();

  // convert js argument to c++ type
  long OffsetCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  std::vector<double>DisplacementsCpp;

  Local<Array> DisplacementsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < DisplacementsArray->Length(); i++){
    DisplacementsCpp.push_back(Nan::To<double>(Nan::Get(DisplacementsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FwdPeriodAdapterWorker(
    callback
    ,ObjectIDCpp
    ,LargeModelCpp
    ,PeriodCpp
    ,OffsetCpp
    ,DisplacementsCpp
  ));

}

//FwdPeriodAdapterWorker::~FwdPeriodAdapterWorker(){
//
//}

//void FwdPeriodAdapterWorker::Destroy(){
//
//}

void FwdToCotSwapAdapterWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ForwardModelLibObjPtr, mForwardModel,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFwdToCotSwapAdapter(
          mObjectID,
          mForwardModel,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FwdToCotSwapAdapter(
          valueObject,
          ForwardModelLibObjPtr,
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

void FwdToCotSwapAdapterWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FwdToCotSwapAdapter) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("ForwardModel is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strForwardModel(info[1]->ToString());
  string ForwardModelCpp(strdup(*strForwardModel));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FwdToCotSwapAdapterWorker(
    callback
    ,ObjectIDCpp
    ,ForwardModelCpp
  ));

}

//FwdToCotSwapAdapterWorker::~FwdToCotSwapAdapterWorker(){
//
//}

//void FwdToCotSwapAdapterWorker::Destroy(){
//
//}

void FlatVolFactoryWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFlatVolFactory(
          mObjectID,
          mLongTermCorr,
          mBeta,
          mTimes,
          mVolatilities,
          mYieldCurve,
          mDisplacement,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FlatVolFactory(
          valueObject,
          mLongTermCorr,
          mBeta,
          mTimes,
          mVolatilities,
          YieldCurveLibObj,
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

void FlatVolFactoryWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FlatVolFactory) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("LongTermCorr is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Times is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("Volatilities is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double LongTermCorrCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  std::vector<double>TimesCpp;

  Local<Array> TimesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TimesArray->Length(); i++){
    TimesCpp.push_back(Nan::To<double>(Nan::Get(TimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>VolatilitiesCpp;

  Local<Array> VolatilitiesArray = info[4].As<Array>();
  for (unsigned int i = 0; i < VolatilitiesArray->Length(); i++){
    VolatilitiesCpp.push_back(Nan::To<double>(Nan::Get(VolatilitiesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[5]).FromJust()));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FlatVolFactoryWorker(
    callback
    ,ObjectIDCpp
    ,LongTermCorrCpp
    ,BetaCpp
    ,TimesCpp
    ,VolatilitiesCpp
    ,YieldCurveCpp
    ,DisplacementCpp
  ));

}

//FlatVolFactoryWorker::~FlatVolFactoryWorker(){
//
//}

//void FlatVolFactoryWorker::Destroy(){
//
//}

void MarketModelInitialRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->initialRates(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelInitialRatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MarketModelInitialRates) {

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
  Nan::AsyncQueueWorker(new MarketModelInitialRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelInitialRatesWorker::~MarketModelInitialRatesWorker(){
//
//}

//void MarketModelInitialRatesWorker::Destroy(){
//
//}

void MarketModelDisplacementsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->displacements(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelDisplacementsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MarketModelDisplacements) {

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
  Nan::AsyncQueueWorker(new MarketModelDisplacementsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelDisplacementsWorker::~MarketModelDisplacementsWorker(){
//
//}

//void MarketModelDisplacementsWorker::Destroy(){
//
//}

void MarketModelNumberOfRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->numberOfRates(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelNumberOfRatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelNumberOfRates) {

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
  Nan::AsyncQueueWorker(new MarketModelNumberOfRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelNumberOfRatesWorker::~MarketModelNumberOfRatesWorker(){
//
//}

//void MarketModelNumberOfRatesWorker::Destroy(){
//
//}

void MarketModelNumberOfFactorsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->numberOfFactors(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelNumberOfFactorsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelNumberOfFactors) {

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
  Nan::AsyncQueueWorker(new MarketModelNumberOfFactorsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelNumberOfFactorsWorker::~MarketModelNumberOfFactorsWorker(){
//
//}

//void MarketModelNumberOfFactorsWorker::Destroy(){
//
//}

void MarketModelNumberOfStepsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->numberOfSteps(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelNumberOfStepsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelNumberOfSteps) {

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
  Nan::AsyncQueueWorker(new MarketModelNumberOfStepsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelNumberOfStepsWorker::~MarketModelNumberOfStepsWorker(){
//
//}

//void MarketModelNumberOfStepsWorker::Destroy(){
//
//}

void MarketModelPseudoRootWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexLib;
  QuantLibAddin::cppToLibrary(mIndex, IndexLib);

       QuantLib::Matrix returnValue;


  // invoke the member function
  returnValue = ObjectIDLibObjPtr->pseudoRoot(
        IndexLib
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelPseudoRootWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MarketModelPseudoRoot) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Index is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long IndexCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelPseudoRootWorker(
    callback
    ,ObjectIDCpp
    ,IndexCpp
  ));

}

//MarketModelPseudoRootWorker::~MarketModelPseudoRootWorker(){
//
//}

//void MarketModelPseudoRootWorker::Destroy(){
//
//}

void MarketModelCovarianceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexLib;
  QuantLibAddin::cppToLibrary(mIndex, IndexLib);

       QuantLib::Matrix returnValue;


  // invoke the member function
  returnValue = ObjectIDLibObjPtr->covariance(
        IndexLib
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelCovarianceWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MarketModelCovariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Index is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long IndexCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelCovarianceWorker(
    callback
    ,ObjectIDCpp
    ,IndexCpp
  ));

}

//MarketModelCovarianceWorker::~MarketModelCovarianceWorker(){
//
//}

//void MarketModelCovarianceWorker::Destroy(){
//
//}

void MarketModelTotalCovarianceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexLib;
  QuantLibAddin::cppToLibrary(mIndex, IndexLib);

       QuantLib::Matrix returnValue;


  // invoke the member function
  returnValue = ObjectIDLibObjPtr->totalCovariance(
        IndexLib
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelTotalCovarianceWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MarketModelTotalCovariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Index is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long IndexCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelTotalCovarianceWorker(
    callback
    ,ObjectIDCpp
    ,IndexCpp
  ));

}

//MarketModelTotalCovarianceWorker::~MarketModelTotalCovarianceWorker(){
//
//}

//void MarketModelTotalCovarianceWorker::Destroy(){
//
//}

void MarketModelTimeDependentVolatilityWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexLib;
  QuantLibAddin::cppToLibrary(mIndex, IndexLib);

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->timeDependentVolatility(
        IndexLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelTimeDependentVolatilityWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MarketModelTimeDependentVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Index is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long IndexCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelTimeDependentVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,IndexCpp
  ));

}

//MarketModelTimeDependentVolatilityWorker::~MarketModelTimeDependentVolatilityWorker(){
//
//}

//void MarketModelTimeDependentVolatilityWorker::Destroy(){
//
//}

void CoterminalSwapForwardJacobianWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::SwapForwardMappings::coterminalSwapForwardJacobian(
        CurveStateLibObj
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CoterminalSwapForwardJacobianWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CoterminalSwapForwardJacobian) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[0]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CoterminalSwapForwardJacobianWorker(
    callback
    ,CurveStateCpp
  ));

}

//CoterminalSwapForwardJacobianWorker::~CoterminalSwapForwardJacobianWorker(){
//
//}

//void CoterminalSwapForwardJacobianWorker::Destroy(){
//
//}

void CoterminalSwapZedMatrixWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::SwapForwardMappings::coterminalSwapZedMatrix(
        CurveStateLibObj
       ,
         mDisplacement
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CoterminalSwapZedMatrixWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CoterminalSwapZedMatrix) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[0]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CoterminalSwapZedMatrixWorker(
    callback
    ,CurveStateCpp
    ,DisplacementCpp
  ));

}

//CoterminalSwapZedMatrixWorker::~CoterminalSwapZedMatrixWorker(){
//
//}

//void CoterminalSwapZedMatrixWorker::Destroy(){
//
//}

void CoinitialSwapForwardJacobianWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::SwapForwardMappings::coinitialSwapForwardJacobian(
        CurveStateLibObj
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CoinitialSwapForwardJacobianWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CoinitialSwapForwardJacobian) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[0]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CoinitialSwapForwardJacobianWorker(
    callback
    ,CurveStateCpp
  ));

}

//CoinitialSwapForwardJacobianWorker::~CoinitialSwapForwardJacobianWorker(){
//
//}

//void CoinitialSwapForwardJacobianWorker::Destroy(){
//
//}

void CoinitialSwapZedMatrixWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::SwapForwardMappings::coinitialSwapZedMatrix(
        CurveStateLibObj
       ,
         mDisplacement
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CoinitialSwapZedMatrixWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CoinitialSwapZedMatrix) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[0]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CoinitialSwapZedMatrixWorker(
    callback
    ,CurveStateCpp
    ,DisplacementCpp
  ));

}

//CoinitialSwapZedMatrixWorker::~CoinitialSwapZedMatrixWorker(){
//
//}

//void CoinitialSwapZedMatrixWorker::Destroy(){
//
//}

void CmSwapForwardJacobianWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SpanningForwardsLib;
  QuantLibAddin::cppToLibrary(mSpanningForwards, SpanningForwardsLib);

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::SwapForwardMappings::cmSwapForwardJacobian(
        CurveStateLibObj
       ,
         SpanningForwardsLib
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CmSwapForwardJacobianWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CmSwapForwardJacobian) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("SpanningForwards is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[0]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  long SpanningForwardsCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CmSwapForwardJacobianWorker(
    callback
    ,CurveStateCpp
    ,SpanningForwardsCpp
  ));

}

//CmSwapForwardJacobianWorker::~CmSwapForwardJacobianWorker(){
//
//}

//void CmSwapForwardJacobianWorker::Destroy(){
//
//}

void CmSwapZedMatrixWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SpanningForwardsLib;
  QuantLibAddin::cppToLibrary(mSpanningForwards, SpanningForwardsLib);

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::SwapForwardMappings::cmSwapZedMatrix(
        CurveStateLibObj
       ,
         SpanningForwardsLib
       ,
         mDisplacement
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CmSwapZedMatrixWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CmSwapZedMatrix) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("SpanningForwards is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[0]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  long SpanningForwardsCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CmSwapZedMatrixWorker(
    callback
    ,CurveStateCpp
    ,SpanningForwardsCpp
    ,DisplacementCpp
  ));

}

//CmSwapZedMatrixWorker::~CmSwapZedMatrixWorker(){
//
//}

//void CmSwapZedMatrixWorker::Destroy(){
//
//}

void AnnuityWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size StartIndexLib;
  QuantLibAddin::cppToLibrary(mStartIndex, StartIndexLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size EndIndexLib;
  QuantLibAddin::cppToLibrary(mEndIndex, EndIndexLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumeraireIndexLib;
  QuantLibAddin::cppToLibrary(mNumeraireIndex, NumeraireIndexLib);

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::SwapForwardMappings::annuity(
      CurveStateLibObj
      ,
       StartIndexLib
      ,
       EndIndexLib
      ,
       NumeraireIndexLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AnnuityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Annuity) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("StartIndex is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("EndIndex is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("NumeraireIndex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[0]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  long StartIndexCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  long EndIndexCpp = Nan::To<int32_t>(info[2]).FromJust();

  // convert js argument to c++ type
  long NumeraireIndexCpp = Nan::To<int32_t>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AnnuityWorker(
    callback
    ,CurveStateCpp
    ,StartIndexCpp
    ,EndIndexCpp
    ,NumeraireIndexCpp
  ));

}

//AnnuityWorker::~AnnuityWorker(){
//
//}

//void AnnuityWorker::Destroy(){
//
//}

void SwapDerivativeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size StartIndexLib;
  QuantLibAddin::cppToLibrary(mStartIndex, StartIndexLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size EndIndexLib;
  QuantLibAddin::cppToLibrary(mEndIndex, EndIndexLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size FwdRateIndexLib;
  QuantLibAddin::cppToLibrary(mFwdRateIndex, FwdRateIndexLib);

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::SwapForwardMappings::swapDerivative(
      CurveStateLibObj
      ,
       StartIndexLib
      ,
       EndIndexLib
      ,
       FwdRateIndexLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwapDerivativeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwapDerivative) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("StartIndex is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("EndIndex is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("FwdRateIndex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[0]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  long StartIndexCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  long EndIndexCpp = Nan::To<int32_t>(info[2]).FromJust();

  // convert js argument to c++ type
  long FwdRateIndexCpp = Nan::To<int32_t>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwapDerivativeWorker(
    callback
    ,CurveStateCpp
    ,StartIndexCpp
    ,EndIndexCpp
    ,FwdRateIndexCpp
  ));

}

//SwapDerivativeWorker::~SwapDerivativeWorker(){
//
//}

//void SwapDerivativeWorker::Destroy(){
//
//}

void RateVolDifferencesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(MarketModel1LibObj, mMarketModel1,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(MarketModel2LibObj, mMarketModel2,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlRateVolDifferences(
      MarketModel1LibObj
      ,
       MarketModel2LibObj
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RateVolDifferencesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RateVolDifferences) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("MarketModel1 is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("MarketModel2 is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strMarketModel1(info[0]->ToString());
  string MarketModel1Cpp(strdup(*strMarketModel1));

  // convert js argument to c++ type
  String::Utf8Value strMarketModel2(info[1]->ToString());
  string MarketModel2Cpp(strdup(*strMarketModel2));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RateVolDifferencesWorker(
    callback
    ,MarketModel1Cpp
    ,MarketModel2Cpp
  ));

}

//RateVolDifferencesWorker::~RateVolDifferencesWorker(){
//
//}

//void RateVolDifferencesWorker::Destroy(){
//
//}

void RateInstVolDifferencesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(MarketModel1LibObj, mMarketModel1,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(MarketModel2LibObj, mMarketModel2,
      QuantLibAddin::MarketModel, QuantLib::MarketModel)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexLib;
  QuantLibAddin::cppToLibrary(mIndex, IndexLib);

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlRateInstVolDifferences(
      MarketModel1LibObj
      ,
       MarketModel2LibObj
      ,
       IndexLib
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RateInstVolDifferencesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RateInstVolDifferences) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("MarketModel1 is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("MarketModel2 is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Index is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strMarketModel1(info[0]->ToString());
  string MarketModel1Cpp(strdup(*strMarketModel1));

  // convert js argument to c++ type
  String::Utf8Value strMarketModel2(info[1]->ToString());
  string MarketModel2Cpp(strdup(*strMarketModel2));

  // convert js argument to c++ type
  long IndexCpp = Nan::To<int32_t>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RateInstVolDifferencesWorker(
    callback
    ,MarketModel1Cpp
    ,MarketModel2Cpp
    ,IndexCpp
  ));

}

//RateInstVolDifferencesWorker::~RateInstVolDifferencesWorker(){
//
//}

//void RateInstVolDifferencesWorker::Destroy(){
//
//}
 