/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "ctsmmcapletcalibration.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/ctsmmcapletcalibration.hpp>
#include <qlo/evolutiondescription.hpp>
#include <qlo/correlation.hpp>
#include <qlo/curvestate.hpp>
#include <qlo/volatility.hpp>
#include <qlo/alphaform.hpp>
#include <ql/models/marketmodels/models/capletcoterminalalphacalibration.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void CTSMMCapletOriginalCalibrationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionLibObj, mEvolution,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)


  // convert object IDs into library objects
  OH_GET_REFERENCE(CorrelationsLibObjPtr, mCorrelations,
      QuantLibAddin::PiecewiseConstantCorrelation, QuantLib::PiecewiseConstantCorrelation)


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::PiecewiseConstantVariance> > SwapPiecewiseConstantVariancesLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance>(mSwapPiecewiseConstantVariances);


  // convert object IDs into library objects
  OH_GET_REFERENCE(CurveStateLibObjPtr, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> AlphasLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mAlphas);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCTSMMCapletOriginalCalibration(
          mObjectID,
          mEvolution,
          mCorrelations,
          mSwapPiecewiseConstantVariances,
          mCapletVols,
          mCurveState,
          mDisplacement,
          mAlphas,
          mLowestRoot,
          mUseFullApprox,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CTSMMCapletOriginalCalibration(
          valueObject,
          EvolutionLibObj,
          CorrelationsLibObjPtr,
          SwapPiecewiseConstantVariancesLibObjPtr,
          mCapletVols,
          CurveStateLibObjPtr,
          mDisplacement,
          mAlphas,
          mLowestRoot,
          mUseFullApprox,
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

void CTSMMCapletOriginalCalibrationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletOriginalCalibration) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Evolution is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Correlations is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("SwapPiecewiseConstantVariances is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("CapletVols is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  if (info.Length() == 7 || !info[7]->IsArray()) {
      return Nan::ThrowError("Alphas is required.");
  }
  if (info.Length() == 8 || !info[8]->IsBoolean()) {
      return Nan::ThrowError("LowestRoot is required.");
  }
  if (info.Length() == 9 || !info[9]->IsBoolean()) {
      return Nan::ThrowError("UseFullApprox is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strEvolution(info[1]->ToString());
  string EvolutionCpp(strdup(*strEvolution));

  // convert js argument to c++ type
  String::Utf8Value strCorrelations(info[2]->ToString());
  string CorrelationsCpp(strdup(*strCorrelations));

  // convert js argument to c++ type
  std::vector<string>SwapPiecewiseConstantVariancesCpp;

  Local<Array> SwapPiecewiseConstantVariancesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < SwapPiecewiseConstantVariancesArray->Length(); i++){
    String::Utf8Value strSwapPiecewiseConstantVariances(Nan::Get(SwapPiecewiseConstantVariancesArray, i).ToLocalChecked()->ToString());
    SwapPiecewiseConstantVariancesCpp.push_back(strdup(*strSwapPiecewiseConstantVariances));
  }

  // convert js argument to c++ type
  std::vector<double>CapletVolsCpp;

  Local<Array> CapletVolsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < CapletVolsArray->Length(); i++){
    CapletVolsCpp.push_back(Nan::To<double>(Nan::Get(CapletVolsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[5]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  std::vector<double>AlphasCpp;

  Local<Array> AlphasArray = info[7].As<Array>();
  for (unsigned int i = 0; i < AlphasArray->Length(); i++){
    AlphasCpp.push_back(Nan::To<double>(Nan::Get(AlphasArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool LowestRootCpp = Nan::To<bool>(info[8]).FromJust();

  // convert js argument to c++ type
  bool UseFullApproxCpp = Nan::To<bool>(info[9]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CTSMMCapletOriginalCalibrationWorker(
    callback
    ,ObjectIDCpp
    ,EvolutionCpp
    ,CorrelationsCpp
    ,SwapPiecewiseConstantVariancesCpp
    ,CapletVolsCpp
    ,CurveStateCpp
    ,DisplacementCpp
    ,AlphasCpp
    ,LowestRootCpp
    ,UseFullApproxCpp
  ));

}

//CTSMMCapletOriginalCalibrationWorker::~CTSMMCapletOriginalCalibrationWorker(){
//
//}

//void CTSMMCapletOriginalCalibrationWorker::Destroy(){
//
//}

void CTSMMCapletAlphaFormCalibrationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionLibObj, mEvolution,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)


  // convert object IDs into library objects
  OH_GET_REFERENCE(CorrelationsLibObjPtr, mCorrelations,
      QuantLibAddin::PiecewiseConstantCorrelation, QuantLib::PiecewiseConstantCorrelation)


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::PiecewiseConstantVariance> > SwapPiecewiseConstantVariancesLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance>(mSwapPiecewiseConstantVariances);


  // convert object IDs into library objects
  OH_GET_REFERENCE(CurveStateLibObjPtr, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> AlphaInitialLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mAlphaInitial);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> AlphaMaxLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mAlphaMax);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> AlphaMinLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mAlphaMin);


  // convert object IDs into library objects
  OH_GET_REFERENCE(AlphaFormLibObjPtr, mAlphaForm,
      QuantLibAddin::AlphaForm, QuantLib::AlphaForm)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCTSMMCapletAlphaFormCalibration(
          mObjectID,
          mEvolution,
          mCorrelations,
          mSwapPiecewiseConstantVariances,
          mCapletVols,
          mCurveState,
          mDisplacement,
          mAlphaInitial,
          mAlphaMax,
          mAlphaMin,
          mMaximizeHomogeneity,
          mAlphaForm,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CTSMMCapletAlphaFormCalibration(
          valueObject,
          EvolutionLibObj,
          CorrelationsLibObjPtr,
          SwapPiecewiseConstantVariancesLibObjPtr,
          mCapletVols,
          CurveStateLibObjPtr,
          mDisplacement,
          mAlphaInitial,
          mAlphaMax,
          mAlphaMin,
          mMaximizeHomogeneity,
          AlphaFormLibObjPtr,
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

void CTSMMCapletAlphaFormCalibrationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletAlphaFormCalibration) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Evolution is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Correlations is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("SwapPiecewiseConstantVariances is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("CapletVols is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  if (info.Length() == 7 || !info[7]->IsArray()) {
      return Nan::ThrowError("AlphaInitial is required.");
  }
  if (info.Length() == 8 || !info[8]->IsArray()) {
      return Nan::ThrowError("AlphaMax is required.");
  }
  if (info.Length() == 9 || !info[9]->IsArray()) {
      return Nan::ThrowError("AlphaMin is required.");
  }
  if (info.Length() == 10 || !info[10]->IsBoolean()) {
      return Nan::ThrowError("MaximizeHomogeneity is required.");
  }
  if (info.Length() == 11 || !info[11]->IsString()) {
      return Nan::ThrowError("AlphaForm is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strEvolution(info[1]->ToString());
  string EvolutionCpp(strdup(*strEvolution));

  // convert js argument to c++ type
  String::Utf8Value strCorrelations(info[2]->ToString());
  string CorrelationsCpp(strdup(*strCorrelations));

  // convert js argument to c++ type
  std::vector<string>SwapPiecewiseConstantVariancesCpp;

  Local<Array> SwapPiecewiseConstantVariancesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < SwapPiecewiseConstantVariancesArray->Length(); i++){
    String::Utf8Value strSwapPiecewiseConstantVariances(Nan::Get(SwapPiecewiseConstantVariancesArray, i).ToLocalChecked()->ToString());
    SwapPiecewiseConstantVariancesCpp.push_back(strdup(*strSwapPiecewiseConstantVariances));
  }

  // convert js argument to c++ type
  std::vector<double>CapletVolsCpp;

  Local<Array> CapletVolsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < CapletVolsArray->Length(); i++){
    CapletVolsCpp.push_back(Nan::To<double>(Nan::Get(CapletVolsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[5]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  std::vector<double>AlphaInitialCpp;

  Local<Array> AlphaInitialArray = info[7].As<Array>();
  for (unsigned int i = 0; i < AlphaInitialArray->Length(); i++){
    AlphaInitialCpp.push_back(Nan::To<double>(Nan::Get(AlphaInitialArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>AlphaMaxCpp;

  Local<Array> AlphaMaxArray = info[8].As<Array>();
  for (unsigned int i = 0; i < AlphaMaxArray->Length(); i++){
    AlphaMaxCpp.push_back(Nan::To<double>(Nan::Get(AlphaMaxArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>AlphaMinCpp;

  Local<Array> AlphaMinArray = info[9].As<Array>();
  for (unsigned int i = 0; i < AlphaMinArray->Length(); i++){
    AlphaMinCpp.push_back(Nan::To<double>(Nan::Get(AlphaMinArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool MaximizeHomogeneityCpp = Nan::To<bool>(info[10]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strAlphaForm(info[11]->ToString());
  string AlphaFormCpp(strdup(*strAlphaForm));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[12].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CTSMMCapletAlphaFormCalibrationWorker(
    callback
    ,ObjectIDCpp
    ,EvolutionCpp
    ,CorrelationsCpp
    ,SwapPiecewiseConstantVariancesCpp
    ,CapletVolsCpp
    ,CurveStateCpp
    ,DisplacementCpp
    ,AlphaInitialCpp
    ,AlphaMaxCpp
    ,AlphaMinCpp
    ,MaximizeHomogeneityCpp
    ,AlphaFormCpp
  ));

}

//CTSMMCapletAlphaFormCalibrationWorker::~CTSMMCapletAlphaFormCalibrationWorker(){
//
//}

//void CTSMMCapletAlphaFormCalibrationWorker::Destroy(){
//
//}

void CTSMMCapletMaxHomogeneityCalibrationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionLibObj, mEvolution,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)


  // convert object IDs into library objects
  OH_GET_REFERENCE(CorrelationsLibObjPtr, mCorrelations,
      QuantLibAddin::PiecewiseConstantCorrelation, QuantLib::PiecewiseConstantCorrelation)


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::PiecewiseConstantVariance> > SwapPiecewiseConstantVariancesLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance>(mSwapPiecewiseConstantVariances);


  // convert object IDs into library objects
  OH_GET_REFERENCE(CurveStateLibObjPtr, mCurveState,
      QuantLibAddin::CurveState, QuantLib::CurveState)


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCTSMMCapletMaxHomogeneityCalibration(
          mObjectID,
          mEvolution,
          mCorrelations,
          mSwapPiecewiseConstantVariances,
          mCapletVols,
          mCurveState,
          mDisplacement,
          mCaplet0Swaption1Priority,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CTSMMCapletMaxHomogeneityCalibration(
          valueObject,
          EvolutionLibObj,
          CorrelationsLibObjPtr,
          SwapPiecewiseConstantVariancesLibObjPtr,
          mCapletVols,
          CurveStateLibObjPtr,
          mDisplacement,
          mCaplet0Swaption1Priority,
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

void CTSMMCapletMaxHomogeneityCalibrationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletMaxHomogeneityCalibration) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Evolution is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Correlations is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("SwapPiecewiseConstantVariances is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("CapletVols is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Caplet0Swaption1Priority is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strEvolution(info[1]->ToString());
  string EvolutionCpp(strdup(*strEvolution));

  // convert js argument to c++ type
  String::Utf8Value strCorrelations(info[2]->ToString());
  string CorrelationsCpp(strdup(*strCorrelations));

  // convert js argument to c++ type
  std::vector<string>SwapPiecewiseConstantVariancesCpp;

  Local<Array> SwapPiecewiseConstantVariancesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < SwapPiecewiseConstantVariancesArray->Length(); i++){
    String::Utf8Value strSwapPiecewiseConstantVariances(Nan::Get(SwapPiecewiseConstantVariancesArray, i).ToLocalChecked()->ToString());
    SwapPiecewiseConstantVariancesCpp.push_back(strdup(*strSwapPiecewiseConstantVariances));
  }

  // convert js argument to c++ type
  std::vector<double>CapletVolsCpp;

  Local<Array> CapletVolsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < CapletVolsArray->Length(); i++){
    CapletVolsCpp.push_back(Nan::To<double>(Nan::Get(CapletVolsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[5]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double Caplet0Swaption1PriorityCpp = Nan::To<double>(info[7]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CTSMMCapletMaxHomogeneityCalibrationWorker(
    callback
    ,ObjectIDCpp
    ,EvolutionCpp
    ,CorrelationsCpp
    ,SwapPiecewiseConstantVariancesCpp
    ,CapletVolsCpp
    ,CurveStateCpp
    ,DisplacementCpp
    ,Caplet0Swaption1PriorityCpp
  ));

}

//CTSMMCapletMaxHomogeneityCalibrationWorker::~CTSMMCapletMaxHomogeneityCalibrationWorker(){
//
//}

//void CTSMMCapletMaxHomogeneityCalibrationWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationCalibrateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural NumberOfFactorsLib = ObjectHandler::convert2<long>(
      mNumberOfFactors, "NumberOfFactors", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural MaxIterLib = ObjectHandler::convert2<long>(
      mMaxIter, "MaxIter", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural InnerMaxIterLib = ObjectHandler::convert2<long>(
      mInnerMaxIter, "InnerMaxIter", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib datatypes
     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->calibrate(
        NumberOfFactorsLib
        ,
         MaxIterLib
        ,
         mTol
        ,
         InnerMaxIterLib
        ,
         mInnerTol
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationCalibrateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationCalibrate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Tol is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("InnerTol is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t NumberOfFactorsCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t MaxIterCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  double TolCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t InnerMaxIterCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  double InnerTolCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationCalibrateWorker(
    callback
    ,ObjectIDCpp
    ,NumberOfFactorsCpp
    ,MaxIterCpp
    ,TolCpp
    ,InnerMaxIterCpp
    ,InnerTolCpp
  ));

}

//CTSMMCapletCalibrationCalibrateWorker::~CTSMMCapletCalibrationCalibrateWorker(){
//
//}

//void CTSMMCapletCalibrationCalibrateWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationFailuresWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // invoke the member function
  QuantLib::Natural returnValue = ObjectIDLibObjPtr->failures(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationFailuresWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationFailures) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationFailuresWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationFailuresWorker::~CTSMMCapletCalibrationFailuresWorker(){
//
//}

//void CTSMMCapletCalibrationFailuresWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationDeformationSizeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->deformationSize(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationDeformationSizeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationDeformationSize) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationDeformationSizeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationDeformationSizeWorker::~CTSMMCapletCalibrationDeformationSizeWorker(){
//
//}

//void CTSMMCapletCalibrationDeformationSizeWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationMarketCapletVolsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->mktCapletVols(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationMarketCapletVolsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationMarketCapletVols) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationMarketCapletVolsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationMarketCapletVolsWorker::~CTSMMCapletCalibrationMarketCapletVolsWorker(){
//
//}

//void CTSMMCapletCalibrationMarketCapletVolsWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationModelCapletVolsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->mdlCapletVols(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationModelCapletVolsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationModelCapletVols) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationModelCapletVolsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationModelCapletVolsWorker::~CTSMMCapletCalibrationModelCapletVolsWorker(){
//
//}

//void CTSMMCapletCalibrationModelCapletVolsWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationCapletRmsErrorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->capletRmsError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationCapletRmsErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationCapletRmsError) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationCapletRmsErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationCapletRmsErrorWorker::~CTSMMCapletCalibrationCapletRmsErrorWorker(){
//
//}

//void CTSMMCapletCalibrationCapletRmsErrorWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationCapletMaxErrorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->capletMaxError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationCapletMaxErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationCapletMaxError) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationCapletMaxErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationCapletMaxErrorWorker::~CTSMMCapletCalibrationCapletMaxErrorWorker(){
//
//}

//void CTSMMCapletCalibrationCapletMaxErrorWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationMarketSwaptionVolsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->mktSwaptionVols(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationMarketSwaptionVolsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationMarketSwaptionVols) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationMarketSwaptionVolsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationMarketSwaptionVolsWorker::~CTSMMCapletCalibrationMarketSwaptionVolsWorker(){
//
//}

//void CTSMMCapletCalibrationMarketSwaptionVolsWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationModelSwaptionVolsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->mdlSwaptionVols(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationModelSwaptionVolsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationModelSwaptionVols) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationModelSwaptionVolsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationModelSwaptionVolsWorker::~CTSMMCapletCalibrationModelSwaptionVolsWorker(){
//
//}

//void CTSMMCapletCalibrationModelSwaptionVolsWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationSwaptionRmsErrorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->swaptionRmsError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationSwaptionRmsErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationSwaptionRmsError) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationSwaptionRmsErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationSwaptionRmsErrorWorker::~CTSMMCapletCalibrationSwaptionRmsErrorWorker(){
//
//}

//void CTSMMCapletCalibrationSwaptionRmsErrorWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationSwaptionMaxErrorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->swaptionMaxError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationSwaptionMaxErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationSwaptionMaxError) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationSwaptionMaxErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletCalibrationSwaptionMaxErrorWorker::~CTSMMCapletCalibrationSwaptionMaxErrorWorker(){
//
//}

//void CTSMMCapletCalibrationSwaptionMaxErrorWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationSwapPseudoRootWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexLib;
  QuantLibAddin::cppToLibrary(mIndex, IndexLib);

       QuantLib::Matrix returnValue;


  // invoke the member function
  returnValue = ObjectIDLibObjPtr->swapPseudoRoot(
        IndexLib
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationSwapPseudoRootWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationSwapPseudoRoot) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationSwapPseudoRootWorker(
    callback
    ,ObjectIDCpp
    ,IndexCpp
  ));

}

//CTSMMCapletCalibrationSwapPseudoRootWorker::~CTSMMCapletCalibrationSwapPseudoRootWorker(){
//
//}

//void CTSMMCapletCalibrationSwapPseudoRootWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVolsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexLib;
  QuantLibAddin::cppToLibrary(mIndex, IndexLib);

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->timeDependentCalibratedSwaptionVols(
        IndexLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVolsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVols) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVolsWorker(
    callback
    ,ObjectIDCpp
    ,IndexCpp
  ));

}

//CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVolsWorker::~CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVolsWorker(){
//
//}

//void CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVolsWorker::Destroy(){
//
//}

void CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVolsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletCalibration, QuantLib::CTSMMCapletCalibration)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexLib;
  QuantLibAddin::cppToLibrary(mIndex, IndexLib);

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->timeDependentUnCalibratedSwaptionVols(
        IndexLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVolsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVols) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVolsWorker(
    callback
    ,ObjectIDCpp
    ,IndexCpp
  ));

}

//CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVolsWorker::~CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVolsWorker(){
//
//}

//void CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVolsWorker::Destroy(){
//
//}

void CTSMMCapletAlphaFormCalibrationAlphaWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CTSMMCapletAlphaFormCalibration, QuantLib::CTSMMCapletAlphaFormCalibration)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->alpha(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CTSMMCapletAlphaFormCalibrationAlphaWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CTSMMCapletAlphaFormCalibrationAlpha) {

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
  Nan::AsyncQueueWorker(new CTSMMCapletAlphaFormCalibrationAlphaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CTSMMCapletAlphaFormCalibrationAlphaWorker::~CTSMMCapletAlphaFormCalibrationAlphaWorker(){
//
//}

//void CTSMMCapletAlphaFormCalibrationAlphaWorker::Destroy(){
//
//}
 