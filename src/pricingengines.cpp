/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "pricingengines.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/pricingengines.hpp>
#include <qlo/termstructures.hpp>
#include <qlo/shortratemodels.hpp>
#include <qlo/payoffs.hpp>
#include <qlo/marketmodels.hpp>
#include <qlo/processes.hpp>
#include <ql/pricingengines/blackformula.hpp>
#include <ql/pricingengines/blackscholescalculator.hpp>
#include <ql/termstructures/volatility/optionlet/optionletvolatilitystructure.hpp>
#include <ql/termstructures/volatility/swaption/swaptionvolstructure.hpp>
#include <ql/pricingengines/swaption/jamshidianswaptionengine.hpp>
#include <ql/pricingengines/swaption/g2swaptionengine.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void BlackCalculator2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffIDLibObjPtr, mPayoffID,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackCalculator2(
          mObjectID,
          mPayoffID,
          mAtmForwardValue,
          mStdDev,
          mDeflator,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackCalculator(
          valueObject,
          PayoffIDLibObjPtr,
          mAtmForwardValue,
          mStdDev,
          mDeflator,
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

void BlackCalculator2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculator2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PayoffID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPayoffID(info[1]->ToString());
  string PayoffIDCpp(strdup(*strPayoffID));

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculator2Worker(
    callback
    ,ObjectIDCpp
    ,PayoffIDCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DeflatorCpp
  ));

}

//BlackCalculator2Worker::~BlackCalculator2Worker(){
//
//}

//void BlackCalculator2Worker::Destroy(){
//
//}

void BlackCalculatorWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Option::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::Option::Type>()(mOptionType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackCalculator(
          mObjectID,
          mOptionType,
          mStrike,
          mAtmForwardValue,
          mStdDev,
          mDeflator,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackCalculator(
          valueObject,
          OptionTypeEnum,
          mStrike,
          mAtmForwardValue,
          mStdDev,
          mDeflator,
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

void BlackCalculatorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculator) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[1]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculatorWorker(
    callback
    ,ObjectIDCpp
    ,OptionTypeCpp
    ,StrikeCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DeflatorCpp
  ));

}

//BlackCalculatorWorker::~BlackCalculatorWorker(){
//
//}

//void BlackCalculatorWorker::Destroy(){
//
//}

void BlackScholesCalculator2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffIDLibObjPtr, mPayoffID,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackScholesCalculator2(
          mObjectID,
          mPayoffID,
          mSpot,
          mGrowth,
          mStdDev,
          mDeflator,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackScholesCalculator(
          valueObject,
          PayoffIDLibObjPtr,
          mSpot,
          mGrowth,
          mStdDev,
          mDeflator,
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

void BlackScholesCalculator2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackScholesCalculator2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PayoffID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Spot is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Growth is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPayoffID(info[1]->ToString());
  string PayoffIDCpp(strdup(*strPayoffID));

  // convert js argument to c++ type
  double SpotCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double GrowthCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackScholesCalculator2Worker(
    callback
    ,ObjectIDCpp
    ,PayoffIDCpp
    ,SpotCpp
    ,GrowthCpp
    ,StdDevCpp
    ,DeflatorCpp
  ));

}

//BlackScholesCalculator2Worker::~BlackScholesCalculator2Worker(){
//
//}

//void BlackScholesCalculator2Worker::Destroy(){
//
//}

void BlackScholesCalculatorWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Option::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::Option::Type>()(mOptionType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackScholesCalculator(
          mObjectID,
          mOptionType,
          mStrike,
          mSpot,
          mGrowth,
          mStdDev,
          mDeflator,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackScholesCalculator(
          valueObject,
          OptionTypeEnum,
          mStrike,
          mSpot,
          mGrowth,
          mStdDev,
          mDeflator,
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

void BlackScholesCalculatorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackScholesCalculator) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Spot is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Growth is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[1]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double SpotCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double GrowthCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackScholesCalculatorWorker(
    callback
    ,ObjectIDCpp
    ,OptionTypeCpp
    ,StrikeCpp
    ,SpotCpp
    ,GrowthCpp
    ,StdDevCpp
    ,DeflatorCpp
  ));

}

//BlackScholesCalculatorWorker::~BlackScholesCalculatorWorker(){
//
//}

//void BlackScholesCalculatorWorker::Destroy(){
//
//}

void PricingEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ProcessIDLibObjPtr, mProcessID,
      QuantLibAddin::GeneralizedBlackScholesProcess, QuantLib::GeneralizedBlackScholesProcess)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlPricingEngine(
          mObjectID,
          mEngineID,
          mProcessID,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::PricingEngine(
          valueObject,
          mEngineID,
          ProcessIDLibObjPtr,
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

void PricingEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PricingEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("EngineID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("ProcessID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strEngineID(info[1]->ToString());
  string EngineIDCpp(strdup(*strEngineID));

  // convert js argument to c++ type
  String::Utf8Value strProcessID(info[2]->ToString());
  string ProcessIDCpp(strdup(*strProcessID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PricingEngineWorker(
    callback
    ,ObjectIDCpp
    ,EngineIDCpp
    ,ProcessIDCpp
  ));

}

//PricingEngineWorker::~PricingEngineWorker(){
//
//}

//void PricingEngineWorker::Destroy(){
//
//}

void DiscountingSwapEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlDiscountingSwapEngine(
          mObjectID,
          mYieldCurve,
          mIncludeSettlDate,
          mSettlementDate,
          mNpvDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::DiscountingSwapEngine(
          valueObject,
          YieldCurveLibObj,
          mIncludeSettlDate,
          SettlementDateLib,
          NpvDateLib,
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

void DiscountingSwapEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DiscountingSwapEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[2]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DiscountingSwapEngineWorker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//DiscountingSwapEngineWorker::~DiscountingSwapEngineWorker(){
//
//}

//void DiscountingSwapEngineWorker::Destroy(){
//
//}

void BinomialPricingEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ProcessIDLibObjPtr, mProcessID,
      QuantLibAddin::GeneralizedBlackScholesProcess, QuantLib::GeneralizedBlackScholesProcess)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBinomialPricingEngine(
          mObjectID,
          mEngineID,
          mProcessID,
          mTimeSteps,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::PricingEngine(
          valueObject,
          mEngineID,
          ProcessIDLibObjPtr,
          mTimeSteps,
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

void BinomialPricingEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BinomialPricingEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("EngineID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("ProcessID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("TimeSteps is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strEngineID(info[1]->ToString());
  string EngineIDCpp(strdup(*strEngineID));

  // convert js argument to c++ type
  String::Utf8Value strProcessID(info[2]->ToString());
  string ProcessIDCpp(strdup(*strProcessID));

  // convert js argument to c++ type
  long TimeStepsCpp = Nan::To<int32_t>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BinomialPricingEngineWorker(
    callback
    ,ObjectIDCpp
    ,EngineIDCpp
    ,ProcessIDCpp
    ,TimeStepsCpp
  ));

}

//BinomialPricingEngineWorker::~BinomialPricingEngineWorker(){
//
//}

//void BinomialPricingEngineWorker::Destroy(){
//
//}

void BlackSwaptionEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);


  // convert object IDs into library objects
  OH_GET_OBJECT(VolTSCoerce, mVolTS, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::SwaptionVolatilityStructure> VolTSLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              VolTSCoerce);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackSwaptionEngine(
          mObjectID,
          mYieldCurve,
          mVolTS,
          mDisplacement,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackSwaptionEngine(
          valueObject,
          YieldCurveLibObj,
          VolTSLibObj,
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

void BlackSwaptionEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackSwaptionEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t VolTSCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackSwaptionEngineWorker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
    ,VolTSCpp
    ,DisplacementCpp
  ));

}

//BlackSwaptionEngineWorker::~BlackSwaptionEngineWorker(){
//
//}

//void BlackSwaptionEngineWorker::Destroy(){
//
//}

void BlackSwaptionEngine2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> VolLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mVol, "Vol");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackSwaptionEngine2(
          mObjectID,
          mYieldCurve,
          mVol,
          mDisplacement,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackSwaptionEngine(
          valueObject,
          YieldCurveLibObj,
          VolLibObj,
          mDisplacement,
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

void BlackSwaptionEngine2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackSwaptionEngine2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t VolCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[4]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackSwaptionEngine2Worker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
    ,VolCpp
    ,DisplacementCpp
    ,DayCounterCpp
  ));

}

//BlackSwaptionEngine2Worker::~BlackSwaptionEngine2Worker(){
//
//}

//void BlackSwaptionEngine2Worker::Destroy(){
//
//}

void BlackCapFloorEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);


  // convert object IDs into library objects
  OH_GET_OBJECT(VolTSCoerce, mVolTS, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::OptionletVolatilityStructure> VolTSLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::OptionletVolatilityStructure,
          QuantLib::OptionletVolatilityStructure>()(
              VolTSCoerce);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackCapFloorEngine(
          mObjectID,
          mYieldCurve,
          mVolTS,
          mDisplacement,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackCapFloorEngine(
          valueObject,
          YieldCurveLibObj,
          VolTSLibObj,
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

void BlackCapFloorEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCapFloorEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t VolTSCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCapFloorEngineWorker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
    ,VolTSCpp
    ,DisplacementCpp
  ));

}

//BlackCapFloorEngineWorker::~BlackCapFloorEngineWorker(){
//
//}

//void BlackCapFloorEngineWorker::Destroy(){
//
//}

void BlackCapFloorEngine2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> VolLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mVol, "Vol");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackCapFloorEngine2(
          mObjectID,
          mYieldCurve,
          mVol,
          mDisplacement,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackCapFloorEngine(
          valueObject,
          YieldCurveLibObj,
          VolLibObj,
          mDisplacement,
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

void BlackCapFloorEngine2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCapFloorEngine2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t VolCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[4]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCapFloorEngine2Worker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
    ,VolCpp
    ,DisplacementCpp
    ,DayCounterCpp
  ));

}

//BlackCapFloorEngine2Worker::~BlackCapFloorEngine2Worker(){
//
//}

//void BlackCapFloorEngine2Worker::Destroy(){
//
//}

void AnalyticCapFloorEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(HandleModelLibObjPtr, mHandleModel,
      QuantLibAddin::AffineModel, QuantLib::AffineModel)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlAnalyticCapFloorEngine(
          mObjectID,
          mHandleModel,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::AnalyticCapFloorEngine(
          valueObject,
          HandleModelLibObjPtr,
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

void AnalyticCapFloorEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AnalyticCapFloorEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("HandleModel is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strHandleModel(info[1]->ToString());
  string HandleModelCpp(strdup(*strHandleModel));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AnalyticCapFloorEngineWorker(
    callback
    ,ObjectIDCpp
    ,HandleModelCpp
  ));

}

//AnalyticCapFloorEngineWorker::~AnalyticCapFloorEngineWorker(){
//
//}

//void AnalyticCapFloorEngineWorker::Destroy(){
//
//}

void BondEngineWorker::Execute(){

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
      new QuantLibAddin::ValueObjects::qlBondEngine(
          mObjectID,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BondEngine(
          valueObject,
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

void BondEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondEngineWorker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
  ));

}

//BondEngineWorker::~BondEngineWorker(){
//
//}

//void BondEngineWorker::Destroy(){
//
//}

void JamshidianSwaptionEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ModelLibObjPtr, mModel,
      QuantLibAddin::OneFactorAffineModel, QuantLib::OneFactorAffineModel)


  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlJamshidianSwaptionEngine(
          mObjectID,
          mModel,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::JamshidianSwaptionEngine(
          valueObject,
          ModelLibObjPtr,
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

void JamshidianSwaptionEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::JamshidianSwaptionEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Model is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strModel(info[1]->ToString());
  string ModelCpp(strdup(*strModel));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new JamshidianSwaptionEngineWorker(
    callback
    ,ObjectIDCpp
    ,ModelCpp
    ,YieldCurveCpp
  ));

}

//JamshidianSwaptionEngineWorker::~JamshidianSwaptionEngineWorker(){
//
//}

//void JamshidianSwaptionEngineWorker::Destroy(){
//
//}

void TreeSwaptionEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ModelLibObjPtr, mModel,
      QuantLibAddin::OneFactorAffineModel, QuantLib::OneFactorAffineModel)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NstepsLib;
  QuantLibAddin::cppToLibrary(mNsteps, NstepsLib);


  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlTreeSwaptionEngine(
          mObjectID,
          mModel,
          mNsteps,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::TreeSwaptionEngine(
          valueObject,
          ModelLibObjPtr,
          NstepsLib,
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

void TreeSwaptionEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TreeSwaptionEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Model is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Nsteps is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strModel(info[1]->ToString());
  string ModelCpp(strdup(*strModel));

  // convert js argument to c++ type
  long NstepsCpp = Nan::To<int32_t>(info[2]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[3]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TreeSwaptionEngineWorker(
    callback
    ,ObjectIDCpp
    ,ModelCpp
    ,NstepsCpp
    ,YieldCurveCpp
  ));

}

//TreeSwaptionEngineWorker::~TreeSwaptionEngineWorker(){
//
//}

//void TreeSwaptionEngineWorker::Destroy(){
//
//}

void ModelG2SwaptionEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ModelLibObjPtr, mModel,
      QuantLibAddin::G2, QuantLib::G2)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IntervalsLib;
  QuantLibAddin::cppToLibrary(mIntervals, IntervalsLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlModelG2SwaptionEngine(
          mObjectID,
          mModel,
          mRange,
          mIntervals,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::G2SwaptionEngine(
          valueObject,
          ModelLibObjPtr,
          mRange,
          IntervalsLib,
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

void ModelG2SwaptionEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ModelG2SwaptionEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Model is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Range is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Intervals is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strModel(info[1]->ToString());
  string ModelCpp(strdup(*strModel));

  // convert js argument to c++ type
  double RangeCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  long IntervalsCpp = Nan::To<int32_t>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ModelG2SwaptionEngineWorker(
    callback
    ,ObjectIDCpp
    ,ModelCpp
    ,RangeCpp
    ,IntervalsCpp
  ));

}

//ModelG2SwaptionEngineWorker::~ModelG2SwaptionEngineWorker(){
//
//}

//void ModelG2SwaptionEngineWorker::Destroy(){
//
//}

void BlackCalculatorValueWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->value(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorValueWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorValue) {

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
  Nan::AsyncQueueWorker(new BlackCalculatorValueWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackCalculatorValueWorker::~BlackCalculatorValueWorker(){
//
//}

//void BlackCalculatorValueWorker::Destroy(){
//
//}

void BlackCalculatorDeltaForwardWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->deltaForward(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorDeltaForwardWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorDeltaForward) {

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
  Nan::AsyncQueueWorker(new BlackCalculatorDeltaForwardWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackCalculatorDeltaForwardWorker::~BlackCalculatorDeltaForwardWorker(){
//
//}

//void BlackCalculatorDeltaForwardWorker::Destroy(){
//
//}

void BlackCalculatorDeltaWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->delta(
        mSpot
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorDeltaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorDelta) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Spot is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double SpotCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculatorDeltaWorker(
    callback
    ,ObjectIDCpp
    ,SpotCpp
  ));

}

//BlackCalculatorDeltaWorker::~BlackCalculatorDeltaWorker(){
//
//}

//void BlackCalculatorDeltaWorker::Destroy(){
//
//}

void BlackCalculatorElasticityForwardWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->elasticityForward(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorElasticityForwardWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorElasticityForward) {

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
  Nan::AsyncQueueWorker(new BlackCalculatorElasticityForwardWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackCalculatorElasticityForwardWorker::~BlackCalculatorElasticityForwardWorker(){
//
//}

//void BlackCalculatorElasticityForwardWorker::Destroy(){
//
//}

void BlackCalculatorElasticityWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->elasticity(
        mSpot
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorElasticityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorElasticity) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Spot is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double SpotCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculatorElasticityWorker(
    callback
    ,ObjectIDCpp
    ,SpotCpp
  ));

}

//BlackCalculatorElasticityWorker::~BlackCalculatorElasticityWorker(){
//
//}

//void BlackCalculatorElasticityWorker::Destroy(){
//
//}

void BlackCalculatorGammaForwardWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->gammaForward(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorGammaForwardWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorGammaForward) {

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
  Nan::AsyncQueueWorker(new BlackCalculatorGammaForwardWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackCalculatorGammaForwardWorker::~BlackCalculatorGammaForwardWorker(){
//
//}

//void BlackCalculatorGammaForwardWorker::Destroy(){
//
//}

void BlackCalculatorGammaWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->gamma(
        mSpot
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorGammaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorGamma) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Spot is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double SpotCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculatorGammaWorker(
    callback
    ,ObjectIDCpp
    ,SpotCpp
  ));

}

//BlackCalculatorGammaWorker::~BlackCalculatorGammaWorker(){
//
//}

//void BlackCalculatorGammaWorker::Destroy(){
//
//}

void BlackCalculatorThetaWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->theta(
        mSpot
        ,
         mTimeToMaturity
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorThetaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorTheta) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Spot is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("TimeToMaturity is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double SpotCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double TimeToMaturityCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculatorThetaWorker(
    callback
    ,ObjectIDCpp
    ,SpotCpp
    ,TimeToMaturityCpp
  ));

}

//BlackCalculatorThetaWorker::~BlackCalculatorThetaWorker(){
//
//}

//void BlackCalculatorThetaWorker::Destroy(){
//
//}

void BlackCalculatorThetaPerDayWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->thetaPerDay(
        mSpot
        ,
         mTimeToMaturity
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorThetaPerDayWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorThetaPerDay) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Spot is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("TimeToMaturity is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double SpotCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double TimeToMaturityCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculatorThetaPerDayWorker(
    callback
    ,ObjectIDCpp
    ,SpotCpp
    ,TimeToMaturityCpp
  ));

}

//BlackCalculatorThetaPerDayWorker::~BlackCalculatorThetaPerDayWorker(){
//
//}

//void BlackCalculatorThetaPerDayWorker::Destroy(){
//
//}

void BlackCalculatorVegaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->vega(
        mTimeToMaturity
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorVegaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorVega) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeToMaturity is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TimeToMaturityCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculatorVegaWorker(
    callback
    ,ObjectIDCpp
    ,TimeToMaturityCpp
  ));

}

//BlackCalculatorVegaWorker::~BlackCalculatorVegaWorker(){
//
//}

//void BlackCalculatorVegaWorker::Destroy(){
//
//}

void BlackCalculatorRhoWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->rho(
        mTimeToMaturity
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorRhoWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorRho) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeToMaturity is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TimeToMaturityCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculatorRhoWorker(
    callback
    ,ObjectIDCpp
    ,TimeToMaturityCpp
  ));

}

//BlackCalculatorRhoWorker::~BlackCalculatorRhoWorker(){
//
//}

//void BlackCalculatorRhoWorker::Destroy(){
//
//}

void BlackCalculatorDividendRhoWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->dividendRho(
        mTimeToMaturity
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorDividendRhoWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorDividendRho) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeToMaturity is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TimeToMaturityCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCalculatorDividendRhoWorker(
    callback
    ,ObjectIDCpp
    ,TimeToMaturityCpp
  ));

}

//BlackCalculatorDividendRhoWorker::~BlackCalculatorDividendRhoWorker(){
//
//}

//void BlackCalculatorDividendRhoWorker::Destroy(){
//
//}

void BlackCalculatorItmCashProbabilityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->itmCashProbability(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorItmCashProbabilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorItmCashProbability) {

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
  Nan::AsyncQueueWorker(new BlackCalculatorItmCashProbabilityWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackCalculatorItmCashProbabilityWorker::~BlackCalculatorItmCashProbabilityWorker(){
//
//}

//void BlackCalculatorItmCashProbabilityWorker::Destroy(){
//
//}

void BlackCalculatorItmAssetProbabilityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->itmAssetProbability(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorItmAssetProbabilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorItmAssetProbability) {

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
  Nan::AsyncQueueWorker(new BlackCalculatorItmAssetProbabilityWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackCalculatorItmAssetProbabilityWorker::~BlackCalculatorItmAssetProbabilityWorker(){
//
//}

//void BlackCalculatorItmAssetProbabilityWorker::Destroy(){
//
//}

void BlackCalculatorStrikeSensitivityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->strikeSensitivity(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorStrikeSensitivityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorStrikeSensitivity) {

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
  Nan::AsyncQueueWorker(new BlackCalculatorStrikeSensitivityWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackCalculatorStrikeSensitivityWorker::~BlackCalculatorStrikeSensitivityWorker(){
//
//}

//void BlackCalculatorStrikeSensitivityWorker::Destroy(){
//
//}

void BlackCalculatorAlphaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->alpha(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorAlphaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorAlpha) {

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
  Nan::AsyncQueueWorker(new BlackCalculatorAlphaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackCalculatorAlphaWorker::~BlackCalculatorAlphaWorker(){
//
//}

//void BlackCalculatorAlphaWorker::Destroy(){
//
//}

void BlackCalculatorBetaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackCalculator, QuantLib::BlackCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->beta(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackCalculatorBetaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCalculatorBeta) {

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
  Nan::AsyncQueueWorker(new BlackCalculatorBetaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackCalculatorBetaWorker::~BlackCalculatorBetaWorker(){
//
//}

//void BlackCalculatorBetaWorker::Destroy(){
//
//}

void BlackScholesCalculatorDeltaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackScholesCalculator, QuantLib::BlackScholesCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->delta(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackScholesCalculatorDeltaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackScholesCalculatorDelta) {

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
  Nan::AsyncQueueWorker(new BlackScholesCalculatorDeltaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackScholesCalculatorDeltaWorker::~BlackScholesCalculatorDeltaWorker(){
//
//}

//void BlackScholesCalculatorDeltaWorker::Destroy(){
//
//}

void BlackScholesCalculatorElasticityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackScholesCalculator, QuantLib::BlackScholesCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->elasticity(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackScholesCalculatorElasticityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackScholesCalculatorElasticity) {

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
  Nan::AsyncQueueWorker(new BlackScholesCalculatorElasticityWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackScholesCalculatorElasticityWorker::~BlackScholesCalculatorElasticityWorker(){
//
//}

//void BlackScholesCalculatorElasticityWorker::Destroy(){
//
//}

void BlackScholesCalculatorGammaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackScholesCalculator, QuantLib::BlackScholesCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->gamma(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackScholesCalculatorGammaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackScholesCalculatorGamma) {

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
  Nan::AsyncQueueWorker(new BlackScholesCalculatorGammaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BlackScholesCalculatorGammaWorker::~BlackScholesCalculatorGammaWorker(){
//
//}

//void BlackScholesCalculatorGammaWorker::Destroy(){
//
//}

void BlackScholesCalculatorThetaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackScholesCalculator, QuantLib::BlackScholesCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->theta(
        mTimeToMaturity
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackScholesCalculatorThetaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackScholesCalculatorTheta) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeToMaturity is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TimeToMaturityCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackScholesCalculatorThetaWorker(
    callback
    ,ObjectIDCpp
    ,TimeToMaturityCpp
  ));

}

//BlackScholesCalculatorThetaWorker::~BlackScholesCalculatorThetaWorker(){
//
//}

//void BlackScholesCalculatorThetaWorker::Destroy(){
//
//}

void BlackScholesCalculatorThetaPerDayWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackScholesCalculator, QuantLib::BlackScholesCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->thetaPerDay(
        mTimeToMaturity
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackScholesCalculatorThetaPerDayWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackScholesCalculatorThetaPerDay) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeToMaturity is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TimeToMaturityCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackScholesCalculatorThetaPerDayWorker(
    callback
    ,ObjectIDCpp
    ,TimeToMaturityCpp
  ));

}

//BlackScholesCalculatorThetaPerDayWorker::~BlackScholesCalculatorThetaPerDayWorker(){
//
//}

//void BlackScholesCalculatorThetaPerDayWorker::Destroy(){
//
//}

void BlackFormulaWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Option::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::Option::Type>()(mOptionType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormula(
      OptionTypeEnum
      ,
       mStrike
      ,
       mAtmForwardValue
      ,
       mStdDev
      ,
       mDeflator
      ,
       mDisplacement
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormulaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormula) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[0]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormulaWorker(
    callback
    ,OptionTypeCpp
    ,StrikeCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DeflatorCpp
    ,DisplacementCpp
  ));

}

//BlackFormulaWorker::~BlackFormulaWorker(){
//
//}

//void BlackFormulaWorker::Destroy(){
//
//}

void BlackFormulaCashItmProbabilityWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Option::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::Option::Type>()(mOptionType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormulaCashItmProbability(
      OptionTypeEnum
      ,
       mStrike
      ,
       mAtmForwardValue
      ,
       mStdDev
      ,
       mDisplacement
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormulaCashItmProbabilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormulaCashItmProbability) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[0]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormulaCashItmProbabilityWorker(
    callback
    ,OptionTypeCpp
    ,StrikeCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DisplacementCpp
  ));

}

//BlackFormulaCashItmProbabilityWorker::~BlackFormulaCashItmProbabilityWorker(){
//
//}

//void BlackFormulaCashItmProbabilityWorker::Destroy(){
//
//}

void BlackFormulaImpliedStdDevApproximationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Option::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::Option::Type>()(mOptionType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormulaImpliedStdDevApproximation(
      OptionTypeEnum
      ,
       mStrike
      ,
       mAtmForwardValue
      ,
       mOptionPrice
      ,
       mDeflator
      ,
       mDisplacement
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormulaImpliedStdDevApproximationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormulaImpliedStdDevApproximation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("OptionPrice is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[0]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double OptionPriceCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormulaImpliedStdDevApproximationWorker(
    callback
    ,OptionTypeCpp
    ,StrikeCpp
    ,AtmForwardValueCpp
    ,OptionPriceCpp
    ,DeflatorCpp
    ,DisplacementCpp
  ));

}

//BlackFormulaImpliedStdDevApproximationWorker::~BlackFormulaImpliedStdDevApproximationWorker(){
//
//}

//void BlackFormulaImpliedStdDevApproximationWorker::Destroy(){
//
//}

void BlackFormulaImpliedStdDevWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Option::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::Option::Type>()(mOptionType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural MaxIterLib = ObjectHandler::convert2<long>(
      mMaxIter, "MaxIter", QuantLib::Null<QuantLib::Natural>());

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormulaImpliedStdDev(
      OptionTypeEnum
      ,
       mStrike
      ,
       mAtmForwardValue
      ,
       mOptionPrice
      ,
       mDeflator
      ,
       mDisplacement
      ,
       mGuess
      ,
       mAccuracy
      ,
       MaxIterLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormulaImpliedStdDevWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormulaImpliedStdDev) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("OptionPrice is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Guess is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[0]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double OptionPriceCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double GuessCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t MaxIterCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[8]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormulaImpliedStdDevWorker(
    callback
    ,OptionTypeCpp
    ,StrikeCpp
    ,AtmForwardValueCpp
    ,OptionPriceCpp
    ,DeflatorCpp
    ,DisplacementCpp
    ,GuessCpp
    ,AccuracyCpp
    ,MaxIterCpp
  ));

}

//BlackFormulaImpliedStdDevWorker::~BlackFormulaImpliedStdDevWorker(){
//
//}

//void BlackFormulaImpliedStdDevWorker::Destroy(){
//
//}

void BlackFormulaStdDevDerivativeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormulaStdDevDerivative(
      mStrike
      ,
       mAtmForwardValue
      ,
       mStdDev
      ,
       mDeflator
      ,
       mDisplacement
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormulaStdDevDerivativeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormulaStdDevDerivative) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormulaStdDevDerivativeWorker(
    callback
    ,StrikeCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DeflatorCpp
    ,DisplacementCpp
  ));

}

//BlackFormulaStdDevDerivativeWorker::~BlackFormulaStdDevDerivativeWorker(){
//
//}

//void BlackFormulaStdDevDerivativeWorker::Destroy(){
//
//}

void BachelierBlackFormulaWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Option::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::Option::Type>()(mOptionType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::bachelierBlackFormula(
      OptionTypeEnum
      ,
       mStrike
      ,
       mAtmForwardValue
      ,
       mStdDev
      ,
       mDeflator
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BachelierBlackFormulaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BachelierBlackFormula) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[0]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BachelierBlackFormulaWorker(
    callback
    ,OptionTypeCpp
    ,StrikeCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DeflatorCpp
  ));

}

//BachelierBlackFormulaWorker::~BachelierBlackFormulaWorker(){
//
//}

//void BachelierBlackFormulaWorker::Destroy(){
//
//}

void BlackFormula2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::PlainVanillaPayoff, QuantLib::PlainVanillaPayoff)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormula(
      PayoffLibObjPtr
      ,
       mAtmForwardValue
      ,
       mStdDev
      ,
       mDeflator
      ,
       mDisplacement
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormula2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormula2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[0]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormula2Worker(
    callback
    ,PayoffCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DeflatorCpp
    ,DisplacementCpp
  ));

}

//BlackFormula2Worker::~BlackFormula2Worker(){
//
//}

//void BlackFormula2Worker::Destroy(){
//
//}

void BlackFormulaCashItmProbability2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::PlainVanillaPayoff, QuantLib::PlainVanillaPayoff)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormulaCashItmProbability(
      PayoffLibObjPtr
      ,
       mAtmForwardValue
      ,
       mStdDev
      ,
       mDisplacement
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormulaCashItmProbability2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormulaCashItmProbability2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[0]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormulaCashItmProbability2Worker(
    callback
    ,PayoffCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DisplacementCpp
  ));

}

//BlackFormulaCashItmProbability2Worker::~BlackFormulaCashItmProbability2Worker(){
//
//}

//void BlackFormulaCashItmProbability2Worker::Destroy(){
//
//}

void BlackFormulaImpliedStdDevApproximation2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::PlainVanillaPayoff, QuantLib::PlainVanillaPayoff)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormulaImpliedStdDevApproximation(
      PayoffLibObjPtr
      ,
       mAtmForwardValue
      ,
       mOptionPrice
      ,
       mDeflator
      ,
       mDisplacement
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormulaImpliedStdDevApproximation2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormulaImpliedStdDevApproximation2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("OptionPrice is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[0]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double OptionPriceCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormulaImpliedStdDevApproximation2Worker(
    callback
    ,PayoffCpp
    ,AtmForwardValueCpp
    ,OptionPriceCpp
    ,DeflatorCpp
    ,DisplacementCpp
  ));

}

//BlackFormulaImpliedStdDevApproximation2Worker::~BlackFormulaImpliedStdDevApproximation2Worker(){
//
//}

//void BlackFormulaImpliedStdDevApproximation2Worker::Destroy(){
//
//}

void BlackFormulaImpliedStdDev2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffIDLibObjPtr, mPayoffID,
      QuantLibAddin::PlainVanillaPayoff, QuantLib::PlainVanillaPayoff)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural MaxIterLib = ObjectHandler::convert2<long>(
      mMaxIter, "MaxIter", QuantLib::Null<QuantLib::Natural>());

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormulaImpliedStdDev(
      PayoffIDLibObjPtr
      ,
       mAtmForwardValue
      ,
       mOptionPrice
      ,
       mDeflator
      ,
       mDisplacement
      ,
       mGuess
      ,
       mAccuracy
      ,
       MaxIterLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormulaImpliedStdDev2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormulaImpliedStdDev2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("PayoffID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("OptionPrice is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Guess is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strPayoffID(info[0]->ToString());
  string PayoffIDCpp(strdup(*strPayoffID));

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double OptionPriceCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double GuessCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t MaxIterCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormulaImpliedStdDev2Worker(
    callback
    ,PayoffIDCpp
    ,AtmForwardValueCpp
    ,OptionPriceCpp
    ,DeflatorCpp
    ,DisplacementCpp
    ,GuessCpp
    ,AccuracyCpp
    ,MaxIterCpp
  ));

}

//BlackFormulaImpliedStdDev2Worker::~BlackFormulaImpliedStdDev2Worker(){
//
//}

//void BlackFormulaImpliedStdDev2Worker::Destroy(){
//
//}

void BlackFormulaStdDevDerivative2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffIDLibObjPtr, mPayoffID,
      QuantLibAddin::PlainVanillaPayoff, QuantLib::PlainVanillaPayoff)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::blackFormulaStdDevDerivative(
      PayoffIDLibObjPtr
      ,
       mAtmForwardValue
      ,
       mStdDev
      ,
       mDeflator
      ,
       mDisplacement
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackFormulaStdDevDerivative2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackFormulaStdDevDerivative2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("PayoffID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strPayoffID(info[0]->ToString());
  string PayoffIDCpp(strdup(*strPayoffID));

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackFormulaStdDevDerivative2Worker(
    callback
    ,PayoffIDCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DeflatorCpp
    ,DisplacementCpp
  ));

}

//BlackFormulaStdDevDerivative2Worker::~BlackFormulaStdDevDerivative2Worker(){
//
//}

//void BlackFormulaStdDevDerivative2Worker::Destroy(){
//
//}

void BachelierBlackFormula2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::PlainVanillaPayoff, QuantLib::PlainVanillaPayoff)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::bachelierBlackFormula(
      PayoffLibObjPtr
      ,
       mAtmForwardValue
      ,
       mStdDev
      ,
       mDeflator
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BachelierBlackFormula2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BachelierBlackFormula2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("AtmForwardValue is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Deflator is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[0]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  double AtmForwardValueCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double DeflatorCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BachelierBlackFormula2Worker(
    callback
    ,PayoffCpp
    ,AtmForwardValueCpp
    ,StdDevCpp
    ,DeflatorCpp
  ));

}

//BachelierBlackFormula2Worker::~BachelierBlackFormula2Worker(){
//
//}

//void BachelierBlackFormula2Worker::Destroy(){
//
//}
 