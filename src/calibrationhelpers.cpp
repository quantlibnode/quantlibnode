/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "calibrationhelpers.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/calibrationhelpers.hpp>
#include <qlo/shortratemodels.hpp>
#include <qlo/pricingengines.hpp>
#include <qlo/indexes/ibor/euribor.hpp>
#include <qlo/optimization.hpp>
#include <ql/models/shortrate/calibrationhelpers/swaptionhelper.hpp>
#include <ql/indexes/ibor/euribor.hpp>
#include <ql/models/shortrate/onefactormodel.hpp>
#include <ql/models/shortrate/twofactormodels/g2.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void SwaptionHelperWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Period OptionTenorLib;
  QuantLibAddin::cppToLibrary(mOptionTenor, OptionTenorLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period LengthLib;
  QuantLibAddin::cppToLibrary(mLength, LengthLib);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> VolatilityLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mVolatility, "Volatility");


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period FixedLegTenorLib;
  QuantLibAddin::cppToLibrary(mFixedLegTenor, FixedLegTenorLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter FixedLegDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mFixedLegDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter FloatingLegDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mFloatingLegDayCounter);


  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSwaptionHelper(
          mObjectID,
          mOptionTenor,
          mLength,
          mVolatility,
          mIborIndex,
          mFixedLegTenor,
          mFixedLegDayCounter,
          mFloatingLegDayCounter,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SwaptionHelper(
          valueObject,
          OptionTenorLib,
          LengthLib,
          VolatilityLibObj,
          IborIndexLibObjPtr,
          FixedLegTenorLib,
          FixedLegDayCounterEnum,
          FloatingLegDayCounterEnum,
          YieldCurveLibObj,
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

void SwaptionHelperWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionHelper) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Length is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("FixedLegTenor is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("FixedLegDayCounter is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("FloatingLegDayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strOptionTenor(info[1]->ToString());
  string OptionTenorCpp(strdup(*strOptionTenor));

  // convert js argument to c++ type
  String::Utf8Value strLength(info[2]->ToString());
  string LengthCpp(strdup(*strLength));

  // convert js argument to c++ type
  ObjectHandler::property_t VolatilityCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[3]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[4]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  String::Utf8Value strFixedLegTenor(info[5]->ToString());
  string FixedLegTenorCpp(strdup(*strFixedLegTenor));

  // convert js argument to c++ type
  String::Utf8Value strFixedLegDayCounter(info[6]->ToString());
  string FixedLegDayCounterCpp(strdup(*strFixedLegDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strFloatingLegDayCounter(info[7]->ToString());
  string FloatingLegDayCounterCpp(strdup(*strFloatingLegDayCounter));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[8]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionHelperWorker(
    callback
    ,ObjectIDCpp
    ,OptionTenorCpp
    ,LengthCpp
    ,VolatilityCpp
    ,IborIndexCpp
    ,FixedLegTenorCpp
    ,FixedLegDayCounterCpp
    ,FloatingLegDayCounterCpp
    ,YieldCurveCpp
  ));

}

//SwaptionHelperWorker::~SwaptionHelperWorker(){
//
//}

//void SwaptionHelperWorker::Destroy(){
//
//}

void CalibrationHelperSetPricingEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PricingEngineLibObjPtr, mPricingEngine,
      QuantLibAddin::PricingEngine, QuantLib::PricingEngine)

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CalibrationHelper, QuantLib::CalibrationHelper)


  // invoke the member function
  ObjectIDLibObjPtr->setPricingEngine(
        PricingEngineLibObjPtr
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CalibrationHelperSetPricingEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CalibrationHelperSetPricingEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PricingEngine is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPricingEngine(info[1]->ToString());
  string PricingEngineCpp(strdup(*strPricingEngine));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CalibrationHelperSetPricingEngineWorker(
    callback
    ,ObjectIDCpp
    ,PricingEngineCpp
  ));

}

//CalibrationHelperSetPricingEngineWorker::~CalibrationHelperSetPricingEngineWorker(){
//
//}

//void CalibrationHelperSetPricingEngineWorker::Destroy(){
//
//}

void CalibrationHelperImpliedVolatilityWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size MaxEvaluationsLib;
  QuantLibAddin::cppToLibrary(mMaxEvaluations, MaxEvaluationsLib);

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CalibrationHelper, QuantLib::CalibrationHelper)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->impliedVolatility(
        mTargetValue
        ,
         mAccuracy
        ,
         MaxEvaluationsLib
        ,
         mMinVol
        ,
         mMaxVol
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CalibrationHelperImpliedVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CalibrationHelperImpliedVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TargetValue is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("MaxEvaluations is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("MinVol is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("MaxVol is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetValueCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  long MaxEvaluationsCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  double MinVolCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double MaxVolCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CalibrationHelperImpliedVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,TargetValueCpp
    ,AccuracyCpp
    ,MaxEvaluationsCpp
    ,MinVolCpp
    ,MaxVolCpp
  ));

}

//CalibrationHelperImpliedVolatilityWorker::~CalibrationHelperImpliedVolatilityWorker(){
//
//}

//void CalibrationHelperImpliedVolatilityWorker::Destroy(){
//
//}

void SwaptionHelperModelValueWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SwaptionHelper, QuantLib::SwaptionHelper)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->modelValue(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionHelperModelValueWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionHelperModelValue) {

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
  Nan::AsyncQueueWorker(new SwaptionHelperModelValueWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SwaptionHelperModelValueWorker::~SwaptionHelperModelValueWorker(){
//
//}

//void SwaptionHelperModelValueWorker::Destroy(){
//
//}

void OneFactorAffineModelCalibrateWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::CalibrationHelper> > CalibrationHelpersLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::CalibrationHelper, QuantLib::CalibrationHelper>(mCalibrationHelpers);


  // convert object IDs into library objects
  OH_GET_UNDERLYING_NONCONST(MethodLibObj, mMethod,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(EndCriteriaLibObj, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(ConstraintLibObj, mConstraint,
      QuantLibAddin::Constraint, QuantLib::Constraint)


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> WeightsLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mWeights);

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneFactorAffineModel, QuantLib::OneFactorAffineModel)


  // invoke the member function
  ObjectIDLibObjPtr->calibrate(
        CalibrationHelpersLibObjPtr
        ,
         MethodLibObj
        ,
         EndCriteriaLibObj
        ,
         ConstraintLibObj
        ,
         mWeights
        ,
         mFixedCoeff
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void OneFactorAffineModelCalibrateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::OneFactorAffineModelCalibrate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("CalibrationHelpers is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Method is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Constraint is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("Weights is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("FixedCoeff is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<string>CalibrationHelpersCpp;

  Local<Array> CalibrationHelpersArray = info[1].As<Array>();
  for (unsigned int i = 0; i < CalibrationHelpersArray->Length(); i++){
    String::Utf8Value strCalibrationHelpers(Nan::Get(CalibrationHelpersArray, i).ToLocalChecked()->ToString());
    CalibrationHelpersCpp.push_back(strdup(*strCalibrationHelpers));
  }

  // convert js argument to c++ type
  String::Utf8Value strMethod(info[2]->ToString());
  string MethodCpp(strdup(*strMethod));

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[3]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  String::Utf8Value strConstraint(info[4]->ToString());
  string ConstraintCpp(strdup(*strConstraint));

  // convert js argument to c++ type
  std::vector<double>WeightsCpp;

  Local<Array> WeightsArray = info[5].As<Array>();
  for (unsigned int i = 0; i < WeightsArray->Length(); i++){
    WeightsCpp.push_back(Nan::To<double>(Nan::Get(WeightsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<bool>FixedCoeffCpp;

  Local<Array> FixedCoeffArray = info[6].As<Array>();
  for (unsigned int i = 0; i < FixedCoeffArray->Length(); i++){
    FixedCoeffCpp.push_back(Nan::To<bool>(Nan::Get(FixedCoeffArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new OneFactorAffineModelCalibrateWorker(
    callback
    ,ObjectIDCpp
    ,CalibrationHelpersCpp
    ,MethodCpp
    ,EndCriteriaCpp
    ,ConstraintCpp
    ,WeightsCpp
    ,FixedCoeffCpp
  ));

}

//OneFactorAffineModelCalibrateWorker::~OneFactorAffineModelCalibrateWorker(){
//
//}

//void OneFactorAffineModelCalibrateWorker::Destroy(){
//
//}

void ModelG2CalibrateWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::CalibrationHelper> > CalibrationHelpersLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::CalibrationHelper, QuantLib::CalibrationHelper>(mCalibrationHelpers);


  // convert object IDs into library objects
  OH_GET_UNDERLYING_NONCONST(MethodLibObj, mMethod,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(EndCriteriaLibObj, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(ConstraintLibObj, mConstraint,
      QuantLibAddin::Constraint, QuantLib::Constraint)


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> WeightsLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mWeights);

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::G2, QuantLib::G2)


  // invoke the member function
  ObjectIDLibObjPtr->calibrate(
        CalibrationHelpersLibObjPtr
        ,
         MethodLibObj
        ,
         EndCriteriaLibObj
        ,
         ConstraintLibObj
        ,
         mWeights
        ,
         mFixedCoeff
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ModelG2CalibrateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ModelG2Calibrate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("CalibrationHelpers is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Method is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Constraint is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("Weights is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("FixedCoeff is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<string>CalibrationHelpersCpp;

  Local<Array> CalibrationHelpersArray = info[1].As<Array>();
  for (unsigned int i = 0; i < CalibrationHelpersArray->Length(); i++){
    String::Utf8Value strCalibrationHelpers(Nan::Get(CalibrationHelpersArray, i).ToLocalChecked()->ToString());
    CalibrationHelpersCpp.push_back(strdup(*strCalibrationHelpers));
  }

  // convert js argument to c++ type
  String::Utf8Value strMethod(info[2]->ToString());
  string MethodCpp(strdup(*strMethod));

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[3]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  String::Utf8Value strConstraint(info[4]->ToString());
  string ConstraintCpp(strdup(*strConstraint));

  // convert js argument to c++ type
  std::vector<double>WeightsCpp;

  Local<Array> WeightsArray = info[5].As<Array>();
  for (unsigned int i = 0; i < WeightsArray->Length(); i++){
    WeightsCpp.push_back(Nan::To<double>(Nan::Get(WeightsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<bool>FixedCoeffCpp;

  Local<Array> FixedCoeffArray = info[6].As<Array>();
  for (unsigned int i = 0; i < FixedCoeffArray->Length(); i++){
    FixedCoeffCpp.push_back(Nan::To<bool>(Nan::Get(FixedCoeffArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ModelG2CalibrateWorker(
    callback
    ,ObjectIDCpp
    ,CalibrationHelpersCpp
    ,MethodCpp
    ,EndCriteriaCpp
    ,ConstraintCpp
    ,WeightsCpp
    ,FixedCoeffCpp
  ));

}

//ModelG2CalibrateWorker::~ModelG2CalibrateWorker(){
//
//}

//void ModelG2CalibrateWorker::Destroy(){
//
//}
 