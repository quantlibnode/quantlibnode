/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "smilesection.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/smilesection.hpp>
#include <qlo/optimization.hpp>
#include <qlo/volatilities.hpp>
#include <ql/termstructures/volatility/interpolatedsmilesection.hpp>
#include <ql/termstructures/volatility/sabrinterpolatedsmilesection.hpp>
#include <ql/experimental/volatility/sabrvolsurface.hpp>
#include <ql/quote.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void FlatSmileSectionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFlatSmileSection(
          mObjectID,
          mOptionDate,
          mVolatility,
          mDayCounter,
          mRefDate,
          mAtmValue,
          mVolatilityType,
          mDisplacement,
          false
      ));

    // Construct the Object
	std::map<std::string, QuantLib::VolatilityType> strEnum;
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FlatSmileSection(
          valueObject,
          OptionDateLib,
          mVolatility,
          DayCounterEnum,
          RefDateLib,
          mAtmValue,
		  strEnum[mVolatilityType],
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

void FlatSmileSectionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FlatSmileSection) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Volatility is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("AtmValue is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("VolatilityType is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  double VolatilityCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[3]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  double AtmValueCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strVolatilityType(info[6]->ToString());
  string VolatilityTypeCpp(strdup(*strVolatilityType));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[7]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FlatSmileSectionWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,VolatilityCpp
    ,DayCounterCpp
    ,RefDateCpp
    ,AtmValueCpp
    ,VolatilityTypeCpp
    ,DisplacementCpp
  ));

}

//FlatSmileSectionWorker::~FlatSmileSectionWorker(){
//
//}

//void FlatSmileSectionWorker::Destroy(){
//
//}

void SabrInterpolatedSmileSectionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert object IDs into library objects
  OH_GET_REFERENCE(EndCriteriaLibObjPtr, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_REFERENCE(MethodLibObjPtr, mMethod,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSabrInterpolatedSmileSection(
          mObjectID,
          mOptionDate,
          mForwardRate,
          mStrike,
          mFloatingStrike,
          mAtmVolatility,
          mVolatilitySpreads,
          mAlpha,
          mBeta,
          mNu,
          mRho,
          mAlphaIsFixed,
          mBetaIsFixed,
          mNuIsFixed,
          mRhoIsFixed,
          mVegaWeighted,
          mEndCriteria,
          mMethod,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SabrInterpolatedSmileSection(
          valueObject,
          OptionDateLib,
          mForwardRate,
          mStrike,
          mFloatingStrike,
          mAtmVolatility,
          mVolatilitySpreads,
          mAlpha,
          mBeta,
          mNu,
          mRho,
          mAlphaIsFixed,
          mBetaIsFixed,
          mNuIsFixed,
          mRhoIsFixed,
          mVegaWeighted,
          EndCriteriaLibObjPtr,
          MethodLibObjPtr,
          DayCounterEnum,
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

void SabrInterpolatedSmileSectionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrInterpolatedSmileSection) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("ForwardRate is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 4 || !info[4]->IsBoolean()) {
      return Nan::ThrowError("FloatingStrike is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("AtmVolatility is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("VolatilitySpreads is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Alpha is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("Nu is required.");
  }
  if (info.Length() == 10 || !info[10]->IsNumber()) {
      return Nan::ThrowError("Rho is required.");
  }
  if (info.Length() == 11 || !info[11]->IsBoolean()) {
      return Nan::ThrowError("AlphaIsFixed is required.");
  }
  if (info.Length() == 12 || !info[12]->IsBoolean()) {
      return Nan::ThrowError("BetaIsFixed is required.");
  }
  if (info.Length() == 13 || !info[13]->IsBoolean()) {
      return Nan::ThrowError("NuIsFixed is required.");
  }
  if (info.Length() == 14 || !info[14]->IsBoolean()) {
      return Nan::ThrowError("RhoIsFixed is required.");
  }
  if (info.Length() == 15 || !info[15]->IsBoolean()) {
      return Nan::ThrowError("VegaWeighted is required.");
  }
  if (info.Length() == 16 || !info[16]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 17 || !info[17]->IsString()) {
      return Nan::ThrowError("Method is required.");
  }
  if (info.Length() == 18 || !info[18]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  double ForwardRateCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  std::vector<double>StrikeCpp;

  Local<Array> StrikeArray = info[3].As<Array>();
  for (unsigned int i = 0; i < StrikeArray->Length(); i++){
    StrikeCpp.push_back(Nan::To<double>(Nan::Get(StrikeArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool FloatingStrikeCpp = Nan::To<bool>(info[4]).FromJust();

  // convert js argument to c++ type
  double AtmVolatilityCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  std::vector<double>VolatilitySpreadsCpp;

  Local<Array> VolatilitySpreadsArray = info[6].As<Array>();
  for (unsigned int i = 0; i < VolatilitySpreadsArray->Length(); i++){
    VolatilitySpreadsCpp.push_back(Nan::To<double>(Nan::Get(VolatilitySpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double AlphaCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  double NuCpp = Nan::To<double>(info[9]).FromJust();

  // convert js argument to c++ type
  double RhoCpp = Nan::To<double>(info[10]).FromJust();

  // convert js argument to c++ type
  bool AlphaIsFixedCpp = Nan::To<bool>(info[11]).FromJust();

  // convert js argument to c++ type
  bool BetaIsFixedCpp = Nan::To<bool>(info[12]).FromJust();

  // convert js argument to c++ type
  bool NuIsFixedCpp = Nan::To<bool>(info[13]).FromJust();

  // convert js argument to c++ type
  bool RhoIsFixedCpp = Nan::To<bool>(info[14]).FromJust();

  // convert js argument to c++ type
  bool VegaWeightedCpp = Nan::To<bool>(info[15]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[16]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  String::Utf8Value strMethod(info[17]->ToString());
  string MethodCpp(strdup(*strMethod));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[18]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[19].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SabrInterpolatedSmileSectionWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,ForwardRateCpp
    ,StrikeCpp
    ,FloatingStrikeCpp
    ,AtmVolatilityCpp
    ,VolatilitySpreadsCpp
    ,AlphaCpp
    ,BetaCpp
    ,NuCpp
    ,RhoCpp
    ,AlphaIsFixedCpp
    ,BetaIsFixedCpp
    ,NuIsFixedCpp
    ,RhoIsFixedCpp
    ,VegaWeightedCpp
    ,EndCriteriaCpp
    ,MethodCpp
    ,DayCounterCpp
  ));

}

//SabrInterpolatedSmileSectionWorker::~SabrInterpolatedSmileSectionWorker(){
//
//}

//void SabrInterpolatedSmileSectionWorker::Destroy(){
//
//}

void SabrInterpolatedSmileSection1Worker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> ForwardRateLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mForwardRate, "ForwardRate");


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> AtmVolatilityLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mAtmVolatility, "AtmVolatility");


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > VolatilitySpreadsLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mVolatilitySpreads, "VolatilitySpreads");


  // convert object IDs into library objects
  OH_GET_REFERENCE(EndCriteriaLibObjPtr, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_REFERENCE(MethodLibObjPtr, mMethod,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSabrInterpolatedSmileSection1(
          mObjectID,
          mOptionDate,
          mForwardRate,
          mStrike,
          mFloatingStrike,
          mAtmVolatility,
          mVolatilitySpreads,
          mAlpha,
          mBeta,
          mNu,
          mRho,
          mAlphaIsFixed,
          mBetaIsFixed,
          mNuIsFixed,
          mRhoIsFixed,
          mVegaWeighted,
          mEndCriteria,
          mMethod,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SabrInterpolatedSmileSection(
          valueObject,
          OptionDateLib,
          ForwardRateLibObj,
          mStrike,
          mFloatingStrike,
          AtmVolatilityLibObj,
          VolatilitySpreadsLibObj,
          mAlpha,
          mBeta,
          mNu,
          mRho,
          mAlphaIsFixed,
          mBetaIsFixed,
          mNuIsFixed,
          mRhoIsFixed,
          mVegaWeighted,
          EndCriteriaLibObjPtr,
          MethodLibObjPtr,
          DayCounterEnum,
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

void SabrInterpolatedSmileSection1Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrInterpolatedSmileSection1) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 4 || !info[4]->IsBoolean()) {
      return Nan::ThrowError("FloatingStrike is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("VolatilitySpreads is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Alpha is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("Nu is required.");
  }
  if (info.Length() == 10 || !info[10]->IsNumber()) {
      return Nan::ThrowError("Rho is required.");
  }
  if (info.Length() == 11 || !info[11]->IsBoolean()) {
      return Nan::ThrowError("AlphaIsFixed is required.");
  }
  if (info.Length() == 12 || !info[12]->IsBoolean()) {
      return Nan::ThrowError("BetaIsFixed is required.");
  }
  if (info.Length() == 13 || !info[13]->IsBoolean()) {
      return Nan::ThrowError("NuIsFixed is required.");
  }
  if (info.Length() == 14 || !info[14]->IsBoolean()) {
      return Nan::ThrowError("RhoIsFixed is required.");
  }
  if (info.Length() == 15 || !info[15]->IsBoolean()) {
      return Nan::ThrowError("VegaWeighted is required.");
  }
  if (info.Length() == 16 || !info[16]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 17 || !info[17]->IsString()) {
      return Nan::ThrowError("Method is required.");
  }
  if (info.Length() == 18 || !info[18]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t ForwardRateCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

  // convert js argument to c++ type
  std::vector<double>StrikeCpp;

  Local<Array> StrikeArray = info[3].As<Array>();
  for (unsigned int i = 0; i < StrikeArray->Length(); i++){
    StrikeCpp.push_back(Nan::To<double>(Nan::Get(StrikeArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool FloatingStrikeCpp = Nan::To<bool>(info[4]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t AtmVolatilityCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[5]).FromJust()));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>VolatilitySpreadsCpp;

  Local<Array> VolatilitySpreadsArray = info[6].As<Array>();
  for (unsigned int i = 0; i < VolatilitySpreadsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(VolatilitySpreadsArray, i).ToLocalChecked()).FromJust()));
    VolatilitySpreadsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  double AlphaCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  double NuCpp = Nan::To<double>(info[9]).FromJust();

  // convert js argument to c++ type
  double RhoCpp = Nan::To<double>(info[10]).FromJust();

  // convert js argument to c++ type
  bool AlphaIsFixedCpp = Nan::To<bool>(info[11]).FromJust();

  // convert js argument to c++ type
  bool BetaIsFixedCpp = Nan::To<bool>(info[12]).FromJust();

  // convert js argument to c++ type
  bool NuIsFixedCpp = Nan::To<bool>(info[13]).FromJust();

  // convert js argument to c++ type
  bool RhoIsFixedCpp = Nan::To<bool>(info[14]).FromJust();

  // convert js argument to c++ type
  bool VegaWeightedCpp = Nan::To<bool>(info[15]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[16]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  String::Utf8Value strMethod(info[17]->ToString());
  string MethodCpp(strdup(*strMethod));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[18]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[19].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SabrInterpolatedSmileSection1Worker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,ForwardRateCpp
    ,StrikeCpp
    ,FloatingStrikeCpp
    ,AtmVolatilityCpp
    ,VolatilitySpreadsCpp
    ,AlphaCpp
    ,BetaCpp
    ,NuCpp
    ,RhoCpp
    ,AlphaIsFixedCpp
    ,BetaIsFixedCpp
    ,NuIsFixedCpp
    ,RhoIsFixedCpp
    ,VegaWeightedCpp
    ,EndCriteriaCpp
    ,MethodCpp
    ,DayCounterCpp
  ));

}

//SabrInterpolatedSmileSection1Worker::~SabrInterpolatedSmileSection1Worker(){
//
//}

//void SabrInterpolatedSmileSection1Worker::Destroy(){
//
//}

void SabrSmileSectionWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > StdDevsLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mStdDevs, "StdDevs");


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> ForwardLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mForward, "Forward");


  // convert object IDs into library objects
  OH_GET_REFERENCE(EndCriteriaLibObjPtr, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_REFERENCE(MethodLibObjPtr, mMethod,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSabrSmileSection(
          mObjectID,
          mOptionTime,
          mStrikes,
          mStdDevs,
          mForward,
          mAlpha,
          mBeta,
          mNu,
          mRho,
          mAlphaIsFixed,
          mBetaIsFixed,
          mNuIsFixed,
          mRhoIsFixed,
          mVegaWeighted,
          mEndCriteria,
          mMethod,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SabrSmileSection(
          valueObject,
          mOptionTime,
          mStrikes,
          StdDevsLibObj,
          ForwardLibObj,
          mAlpha,
          mBeta,
          mNu,
          mRho,
          mAlphaIsFixed,
          mBetaIsFixed,
          mNuIsFixed,
          mRhoIsFixed,
          mVegaWeighted,
          EndCriteriaLibObjPtr,
          MethodLibObjPtr,
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

void SabrSmileSectionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrSmileSection) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("OptionTime is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Strikes is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("StdDevs is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Alpha is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Nu is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Rho is required.");
  }
  if (info.Length() == 9 || !info[9]->IsBoolean()) {
      return Nan::ThrowError("AlphaIsFixed is required.");
  }
  if (info.Length() == 10 || !info[10]->IsBoolean()) {
      return Nan::ThrowError("BetaIsFixed is required.");
  }
  if (info.Length() == 11 || !info[11]->IsBoolean()) {
      return Nan::ThrowError("NuIsFixed is required.");
  }
  if (info.Length() == 12 || !info[12]->IsBoolean()) {
      return Nan::ThrowError("RhoIsFixed is required.");
  }
  if (info.Length() == 13 || !info[13]->IsBoolean()) {
      return Nan::ThrowError("VegaWeighted is required.");
  }
  if (info.Length() == 14 || !info[14]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 15 || !info[15]->IsString()) {
      return Nan::ThrowError("Method is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double OptionTimeCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  std::vector<double>StrikesCpp;

  Local<Array> StrikesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < StrikesArray->Length(); i++){
    StrikesCpp.push_back(Nan::To<double>(Nan::Get(StrikesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>StdDevsCpp;

  Local<Array> StdDevsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < StdDevsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(StdDevsArray, i).ToLocalChecked()).FromJust()));
    StdDevsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  ObjectHandler::property_t ForwardCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[4]).FromJust()));

  // convert js argument to c++ type
  double AlphaCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double NuCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double RhoCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  bool AlphaIsFixedCpp = Nan::To<bool>(info[9]).FromJust();

  // convert js argument to c++ type
  bool BetaIsFixedCpp = Nan::To<bool>(info[10]).FromJust();

  // convert js argument to c++ type
  bool NuIsFixedCpp = Nan::To<bool>(info[11]).FromJust();

  // convert js argument to c++ type
  bool RhoIsFixedCpp = Nan::To<bool>(info[12]).FromJust();

  // convert js argument to c++ type
  bool VegaWeightedCpp = Nan::To<bool>(info[13]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[14]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  String::Utf8Value strMethod(info[15]->ToString());
  string MethodCpp(strdup(*strMethod));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[16].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SabrSmileSectionWorker(
    callback
    ,ObjectIDCpp
    ,OptionTimeCpp
    ,StrikesCpp
    ,StdDevsCpp
    ,ForwardCpp
    ,AlphaCpp
    ,BetaCpp
    ,NuCpp
    ,RhoCpp
    ,AlphaIsFixedCpp
    ,BetaIsFixedCpp
    ,NuIsFixedCpp
    ,RhoIsFixedCpp
    ,VegaWeightedCpp
    ,EndCriteriaCpp
    ,MethodCpp
  ));

}

//SabrSmileSectionWorker::~SabrSmileSectionWorker(){
//
//}

//void SabrSmileSectionWorker::Destroy(){
//
//}

void InterpolatedSmileSectionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > StdDevsLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mStdDevs, "StdDevs");


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> AtmLevelLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mAtmLevel, "AtmLevel");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlInterpolatedSmileSection(
          mObjectID,
          mOptionDate,
          mStrikes,
          mStdDevs,
          mAtmLevel,
          mDayCounter,
          mVolatilityType,
          mDisplacement,
          false
      ));

    // Construct the Object
	std::map<std::string, QuantLib::VolatilityType> strEnum;
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::InterpolatedSmileSection(
          valueObject,
          OptionDateLib,
          mStrikes,
          StdDevsLibObj,
          AtmLevelLibObj,
          DayCounterEnum,
		  strEnum[mVolatilityType],
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

void InterpolatedSmileSectionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterpolatedSmileSection) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Strikes is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("StdDevs is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("VolatilityType is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  std::vector<double>StrikesCpp;

  Local<Array> StrikesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < StrikesArray->Length(); i++){
    StrikesCpp.push_back(Nan::To<double>(Nan::Get(StrikesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>StdDevsCpp;

  Local<Array> StdDevsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < StdDevsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(StdDevsArray, i).ToLocalChecked()).FromJust()));
    StdDevsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  ObjectHandler::property_t AtmLevelCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[4]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[5]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strVolatilityType(info[6]->ToString());
  string VolatilityTypeCpp(strdup(*strVolatilityType));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[7]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterpolatedSmileSectionWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,StrikesCpp
    ,StdDevsCpp
    ,AtmLevelCpp
    ,DayCounterCpp
    ,VolatilityTypeCpp
    ,DisplacementCpp
  ));

}

//InterpolatedSmileSectionWorker::~InterpolatedSmileSectionWorker(){
//
//}

//void InterpolatedSmileSectionWorker::Destroy(){
//
//}

void SmileSectionFromSabrVolSurfaceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(SabrVolSurfaceCoerce, mSabrVolSurface, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::SabrVolSurface> SabrVolSurfaceLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::SabrVolSurface,
          QuantLib::SabrVolSurface>()(
              SabrVolSurfaceCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSmileSectionFromSabrVolSurface(
          mObjectID,
          mSabrVolSurface,
          mOptionTime,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SmileSectionFromSabrVolSurface(
          valueObject,
          SabrVolSurfaceLibObj,
          mOptionTime,
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

void SmileSectionFromSabrVolSurfaceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SmileSectionFromSabrVolSurface) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("OptionTime is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t SabrVolSurfaceCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  double OptionTimeCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SmileSectionFromSabrVolSurfaceWorker(
    callback
    ,ObjectIDCpp
    ,SabrVolSurfaceCpp
    ,OptionTimeCpp
  ));

}

//SmileSectionFromSabrVolSurfaceWorker::~SmileSectionFromSabrVolSurfaceWorker(){
//
//}

//void SmileSectionFromSabrVolSurfaceWorker::Destroy(){
//
//}

void SmileSectionVolatilityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SmileSection, QuantLib::SmileSection)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->volatility(
        mStrike
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SmileSectionVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SmileSectionVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SmileSectionVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,StrikeCpp
  ));

}

//SmileSectionVolatilityWorker::~SmileSectionVolatilityWorker(){
//
//}

//void SmileSectionVolatilityWorker::Destroy(){
//
//}

void SmileSectionVarianceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SmileSection, QuantLib::SmileSection)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->variance(
        mStrike
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SmileSectionVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SmileSectionVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SmileSectionVarianceWorker(
    callback
    ,ObjectIDCpp
    ,StrikeCpp
  ));

}

//SmileSectionVarianceWorker::~SmileSectionVarianceWorker(){
//
//}

//void SmileSectionVarianceWorker::Destroy(){
//
//}

void SmileSectionAtmLevelWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SmileSection, QuantLib::SmileSection)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->atmLevel(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SmileSectionAtmLevelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SmileSectionAtmLevel) {

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
  Nan::AsyncQueueWorker(new SmileSectionAtmLevelWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SmileSectionAtmLevelWorker::~SmileSectionAtmLevelWorker(){
//
//}

//void SmileSectionAtmLevelWorker::Destroy(){
//
//}

void SmileSectionExerciseDateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SmileSection, QuantLib::SmileSection)


  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->exerciseDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SmileSectionExerciseDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SmileSectionExerciseDate) {

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
  Nan::AsyncQueueWorker(new SmileSectionExerciseDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SmileSectionExerciseDateWorker::~SmileSectionExerciseDateWorker(){
//
//}

//void SmileSectionExerciseDateWorker::Destroy(){
//
//}

void SmileSectionDayCounterWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SmileSection, QuantLib::SmileSection)


  // invoke the member function
  QuantLib::DayCounter returnValue = ObjectIDLibObjPtr->dayCounter(
      );


  std::ostringstream os;
  os << returnValue;
  mReturnValue = os.str();

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SmileSectionDayCounterWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SmileSectionDayCounter) {

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
  Nan::AsyncQueueWorker(new SmileSectionDayCounterWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SmileSectionDayCounterWorker::~SmileSectionDayCounterWorker(){
//
//}

//void SmileSectionDayCounterWorker::Destroy(){
//
//}

void SabrInterpolatedSmileSectionAlphaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SabrInterpolatedSmileSection, QuantLib::SabrInterpolatedSmileSection)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->alpha(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SabrInterpolatedSmileSectionAlphaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrInterpolatedSmileSectionAlpha) {

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
  Nan::AsyncQueueWorker(new SabrInterpolatedSmileSectionAlphaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SabrInterpolatedSmileSectionAlphaWorker::~SabrInterpolatedSmileSectionAlphaWorker(){
//
//}

//void SabrInterpolatedSmileSectionAlphaWorker::Destroy(){
//
//}

void SabrInterpolatedSmileSectionBetaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SabrInterpolatedSmileSection, QuantLib::SabrInterpolatedSmileSection)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->beta(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SabrInterpolatedSmileSectionBetaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrInterpolatedSmileSectionBeta) {

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
  Nan::AsyncQueueWorker(new SabrInterpolatedSmileSectionBetaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SabrInterpolatedSmileSectionBetaWorker::~SabrInterpolatedSmileSectionBetaWorker(){
//
//}

//void SabrInterpolatedSmileSectionBetaWorker::Destroy(){
//
//}

void SabrInterpolatedSmileSectionNuWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SabrInterpolatedSmileSection, QuantLib::SabrInterpolatedSmileSection)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->nu(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SabrInterpolatedSmileSectionNuWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrInterpolatedSmileSectionNu) {

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
  Nan::AsyncQueueWorker(new SabrInterpolatedSmileSectionNuWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SabrInterpolatedSmileSectionNuWorker::~SabrInterpolatedSmileSectionNuWorker(){
//
//}

//void SabrInterpolatedSmileSectionNuWorker::Destroy(){
//
//}

void SabrInterpolatedSmileSectionRhoWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SabrInterpolatedSmileSection, QuantLib::SabrInterpolatedSmileSection)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->rho(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SabrInterpolatedSmileSectionRhoWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrInterpolatedSmileSectionRho) {

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
  Nan::AsyncQueueWorker(new SabrInterpolatedSmileSectionRhoWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SabrInterpolatedSmileSectionRhoWorker::~SabrInterpolatedSmileSectionRhoWorker(){
//
//}

//void SabrInterpolatedSmileSectionRhoWorker::Destroy(){
//
//}

void SabrInterpolatedSmileSectionErrorWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SabrInterpolatedSmileSection, QuantLib::SabrInterpolatedSmileSection)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->rmsError(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SabrInterpolatedSmileSectionErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrInterpolatedSmileSectionError) {

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
  Nan::AsyncQueueWorker(new SabrInterpolatedSmileSectionErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SabrInterpolatedSmileSectionErrorWorker::~SabrInterpolatedSmileSectionErrorWorker(){
//
//}

//void SabrInterpolatedSmileSectionErrorWorker::Destroy(){
//
//}

void SabrInterpolatedSmileSectionMaxErrorWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SabrInterpolatedSmileSection, QuantLib::SabrInterpolatedSmileSection)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->maxError(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SabrInterpolatedSmileSectionMaxErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrInterpolatedSmileSectionMaxError) {

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
  Nan::AsyncQueueWorker(new SabrInterpolatedSmileSectionMaxErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SabrInterpolatedSmileSectionMaxErrorWorker::~SabrInterpolatedSmileSectionMaxErrorWorker(){
//
//}

//void SabrInterpolatedSmileSectionMaxErrorWorker::Destroy(){
//
//}

void SabrInterpolatedSmileSectionEndCriteriaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SabrInterpolatedSmileSection, QuantLib::SabrInterpolatedSmileSection)


  // invoke the member function
  QuantLib::EndCriteria::Type returnValue = ObjectIDLibObjPtr->endCriteria(
      );


  std::ostringstream os;
  os << returnValue;
  mReturnValue = os.str();

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SabrInterpolatedSmileSectionEndCriteriaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrInterpolatedSmileSectionEndCriteria) {

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
  Nan::AsyncQueueWorker(new SabrInterpolatedSmileSectionEndCriteriaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SabrInterpolatedSmileSectionEndCriteriaWorker::~SabrInterpolatedSmileSectionEndCriteriaWorker(){
//
//}

//void SabrInterpolatedSmileSectionEndCriteriaWorker::Destroy(){
//
//}
 