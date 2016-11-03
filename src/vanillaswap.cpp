/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "vanillaswap.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/vanillaswap.hpp>
#include <qlo/indexes/iborindex.hpp>
#include <qlo/indexes/swapindex.hpp>
#include <qlo/ratehelpers.hpp>
#include <qlo/schedule.hpp>
#include <qlo/pricingengines.hpp>
#include <qlo/termstructures.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/indexes/swapindex.hpp>
#include <ql/termstructures/yield/ratehelpers.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void VanillaSwapWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::VanillaSwap::Type PayerReceiverEnum =
      ObjectHandler::Create<QuantLib::VanillaSwap::Type>()(mPayerReceiver);


  // convert object IDs into library objects
  OH_GET_REFERENCE(FixScheduleLibObjPtr, mFixSchedule,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter FixDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mFixDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(FloatingLegScheduleLibObjPtr, mFloatingLegSchedule,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter FloatingLegDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mFloatingLegDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentConvention);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlVanillaSwap(
          mObjectID,
          mPayerReceiver,
          mNominal,
          mFixSchedule,
          mFixedRate,
          mFixDayCounter,
          mFloatingLegSchedule,
          mIborIndex,
          mSpread,
          mFloatingLegDayCounter,
          mPaymentConvention,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::VanillaSwap(
          valueObject,
          PayerReceiverEnum,
          mNominal,
          FixScheduleLibObjPtr,
          mFixedRate,
          FixDayCounterEnum,
          FloatingLegScheduleLibObjPtr,
          IborIndexLibObjPtr,
          mSpread,
          FloatingLegDayCounterEnum,
          PaymentConventionEnum,
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

void VanillaSwapWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwap) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PayerReceiver is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Nominal is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("FixSchedule is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("FixedRate is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("FixDayCounter is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("FloatingLegSchedule is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Spread is required.");
  }
  if (info.Length() == 9 || !info[9]->IsString()) {
      return Nan::ThrowError("FloatingLegDayCounter is required.");
  }
  if (info.Length() == 10 || !info[10]->IsString()) {
      return Nan::ThrowError("PaymentConvention is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPayerReceiver(info[1]->ToString());
  string PayerReceiverCpp(strdup(*strPayerReceiver));

  // convert js argument to c++ type
  double NominalCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strFixSchedule(info[3]->ToString());
  string FixScheduleCpp(strdup(*strFixSchedule));

  // convert js argument to c++ type
  double FixedRateCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strFixDayCounter(info[5]->ToString());
  string FixDayCounterCpp(strdup(*strFixDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strFloatingLegSchedule(info[6]->ToString());
  string FloatingLegScheduleCpp(strdup(*strFloatingLegSchedule));

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[7]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  double SpreadCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strFloatingLegDayCounter(info[9]->ToString());
  string FloatingLegDayCounterCpp(strdup(*strFloatingLegDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strPaymentConvention(info[10]->ToString());
  string PaymentConventionCpp(strdup(*strPaymentConvention));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[11].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VanillaSwapWorker(
    callback
    ,ObjectIDCpp
    ,PayerReceiverCpp
    ,NominalCpp
    ,FixScheduleCpp
    ,FixedRateCpp
    ,FixDayCounterCpp
    ,FloatingLegScheduleCpp
    ,IborIndexCpp
    ,SpreadCpp
    ,FloatingLegDayCounterCpp
    ,PaymentConventionCpp
  ));

}

//VanillaSwapWorker::~VanillaSwapWorker(){
//
//}

//void VanillaSwapWorker::Destroy(){
//
//}

void MakeVanillaSwapWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural SettlDaysLib = ObjectHandler::convert2<long>(
      mSettlDays, "SettlDays", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period ForwardStartLib;
  QuantLibAddin::cppToLibrary(mForwardStart, ForwardStartLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter FixDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mFixDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(PricingEngineIDLibObjPtr, mPricingEngineID,
      QuantLibAddin::PricingEngine, QuantLib::PricingEngine)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMakeVanillaSwap(
          mObjectID,
          mSettlDays,
          mSwapTenor,
          mIborIndex,
          mFixedRate,
          mForwardStart,
          mFixDayCounter,
          mSpread,
          mPricingEngineID,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::VanillaSwap(
          valueObject,
          SettlDaysLib,
          SwapTenorLib,
          IborIndexLibObjPtr,
          mFixedRate,
          ForwardStartLib,
          FixDayCounterEnum,
          mSpread,
          PricingEngineIDLibObjPtr,
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

void MakeVanillaSwapWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MakeVanillaSwap) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("FixedRate is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("ForwardStart is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("FixDayCounter is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Spread is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("PricingEngineID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlDaysCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[2]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[3]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  double FixedRateCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strForwardStart(info[5]->ToString());
  string ForwardStartCpp(strdup(*strForwardStart));

  // convert js argument to c++ type
  String::Utf8Value strFixDayCounter(info[6]->ToString());
  string FixDayCounterCpp(strdup(*strFixDayCounter));

  // convert js argument to c++ type
  double SpreadCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strPricingEngineID(info[8]->ToString());
  string PricingEngineIDCpp(strdup(*strPricingEngineID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MakeVanillaSwapWorker(
    callback
    ,ObjectIDCpp
    ,SettlDaysCpp
    ,SwapTenorCpp
    ,IborIndexCpp
    ,FixedRateCpp
    ,ForwardStartCpp
    ,FixDayCounterCpp
    ,SpreadCpp
    ,PricingEngineIDCpp
  ));

}

//MakeVanillaSwapWorker::~MakeVanillaSwapWorker(){
//
//}

//void MakeVanillaSwapWorker::Destroy(){
//
//}

void MakeIMMSwapWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date FirstImmDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mFirstImmDate, "FirstImmDate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter FixDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mFixDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(PricingEngineIDLibObjPtr, mPricingEngineID,
      QuantLibAddin::PricingEngine, QuantLib::PricingEngine)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMakeIMMSwap(
          mObjectID,
          mSwapTenor,
          mIborIndex,
          mFixedRate,
          mFirstImmDate,
          mFixDayCounter,
          mSpread,
          mPricingEngineID,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::VanillaSwap(
          valueObject,
          SwapTenorLib,
          IborIndexLibObjPtr,
          mFixedRate,
          FirstImmDateLib,
          FixDayCounterEnum,
          mSpread,
          PricingEngineIDLibObjPtr,
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

void MakeIMMSwapWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MakeIMMSwap) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("FixedRate is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("FixDayCounter is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Spread is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("PricingEngineID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[1]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[2]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  double FixedRateCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t FirstImmDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strFixDayCounter(info[5]->ToString());
  string FixDayCounterCpp(strdup(*strFixDayCounter));

  // convert js argument to c++ type
  double SpreadCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strPricingEngineID(info[7]->ToString());
  string PricingEngineIDCpp(strdup(*strPricingEngineID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MakeIMMSwapWorker(
    callback
    ,ObjectIDCpp
    ,SwapTenorCpp
    ,IborIndexCpp
    ,FixedRateCpp
    ,FirstImmDateCpp
    ,FixDayCounterCpp
    ,SpreadCpp
    ,PricingEngineIDCpp
  ));

}

//MakeIMMSwapWorker::~MakeIMMSwapWorker(){
//
//}

//void MakeIMMSwapWorker::Destroy(){
//
//}

void VanillaSwapFromSwapIndexWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapIndexLibObjPtr, mSwapIndex,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date FixingDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mFixingDate, "FixingDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlVanillaSwapFromSwapIndex(
          mObjectID,
          mSwapIndex,
          mFixingDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::VanillaSwap(
          valueObject,
          SwapIndexLibObjPtr,
          FixingDateLib,
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

void VanillaSwapFromSwapIndexWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFromSwapIndex) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("SwapIndex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strSwapIndex(info[1]->ToString());
  string SwapIndexCpp(strdup(*strSwapIndex));

  // convert js argument to c++ type
  ObjectHandler::property_t FixingDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VanillaSwapFromSwapIndexWorker(
    callback
    ,ObjectIDCpp
    ,SwapIndexCpp
    ,FixingDateCpp
  ));

}

//VanillaSwapFromSwapIndexWorker::~VanillaSwapFromSwapIndexWorker(){
//
//}

//void VanillaSwapFromSwapIndexWorker::Destroy(){
//
//}

void VanillaSwapFromSwapRateHelperWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapRateHelperLibObjPtr, mSwapRateHelper,
      QuantLibAddin::SwapRateHelper, QuantLib::SwapRateHelper)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlVanillaSwapFromSwapRateHelper(
          mObjectID,
          mSwapRateHelper,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::VanillaSwap(
          valueObject,
          SwapRateHelperLibObjPtr,
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

void VanillaSwapFromSwapRateHelperWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFromSwapRateHelper) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("SwapRateHelper is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strSwapRateHelper(info[1]->ToString());
  string SwapRateHelperCpp(strdup(*strSwapRateHelper));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VanillaSwapFromSwapRateHelperWorker(
    callback
    ,ObjectIDCpp
    ,SwapRateHelperCpp
  ));

}

//VanillaSwapFromSwapRateHelperWorker::~VanillaSwapFromSwapRateHelperWorker(){
//
//}

//void VanillaSwapFromSwapRateHelperWorker::Destroy(){
//
//}

void VanillaSwapFixedLegBPSWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->fixedLegBPS(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapFixedLegBPSWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFixedLegBPS) {

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
  Nan::AsyncQueueWorker(new VanillaSwapFixedLegBPSWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapFixedLegBPSWorker::~VanillaSwapFixedLegBPSWorker(){
//
//}

//void VanillaSwapFixedLegBPSWorker::Destroy(){
//
//}

void VanillaSwapFixedLegNPVWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->fixedLegNPV(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapFixedLegNPVWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFixedLegNPV) {

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
  Nan::AsyncQueueWorker(new VanillaSwapFixedLegNPVWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapFixedLegNPVWorker::~VanillaSwapFixedLegNPVWorker(){
//
//}

//void VanillaSwapFixedLegNPVWorker::Destroy(){
//
//}

void VanillaSwapFairRateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->fairRate(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapFairRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFairRate) {

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
  Nan::AsyncQueueWorker(new VanillaSwapFairRateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapFairRateWorker::~VanillaSwapFairRateWorker(){
//
//}

//void VanillaSwapFairRateWorker::Destroy(){
//
//}

void VanillaSwapFloatingLegBPSWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->floatingLegBPS(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapFloatingLegBPSWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFloatingLegBPS) {

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
  Nan::AsyncQueueWorker(new VanillaSwapFloatingLegBPSWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapFloatingLegBPSWorker::~VanillaSwapFloatingLegBPSWorker(){
//
//}

//void VanillaSwapFloatingLegBPSWorker::Destroy(){
//
//}

void VanillaSwapFloatingLegNPVWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->floatingLegNPV(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapFloatingLegNPVWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFloatingLegNPV) {

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
  Nan::AsyncQueueWorker(new VanillaSwapFloatingLegNPVWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapFloatingLegNPVWorker::~VanillaSwapFloatingLegNPVWorker(){
//
//}

//void VanillaSwapFloatingLegNPVWorker::Destroy(){
//
//}

void VanillaSwapFairSpreadWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->fairSpread(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapFairSpreadWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFairSpread) {

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
  Nan::AsyncQueueWorker(new VanillaSwapFairSpreadWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapFairSpreadWorker::~VanillaSwapFairSpreadWorker(){
//
//}

//void VanillaSwapFairSpreadWorker::Destroy(){
//
//}

void VanillaSwapTypeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  QuantLib::VanillaSwap::Type returnValue = ObjectIDLibObjPtr->type(
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

void VanillaSwapTypeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapType) {

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
  Nan::AsyncQueueWorker(new VanillaSwapTypeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapTypeWorker::~VanillaSwapTypeWorker(){
//
//}

//void VanillaSwapTypeWorker::Destroy(){
//
//}

void VanillaSwapNominalWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->nominal(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapNominalWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapNominal) {

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
  Nan::AsyncQueueWorker(new VanillaSwapNominalWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapNominalWorker::~VanillaSwapNominalWorker(){
//
//}

//void VanillaSwapNominalWorker::Destroy(){
//
//}

void VanillaSwapFixedRateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->fixedRate(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapFixedRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFixedRate) {

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
  Nan::AsyncQueueWorker(new VanillaSwapFixedRateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapFixedRateWorker::~VanillaSwapFixedRateWorker(){
//
//}

//void VanillaSwapFixedRateWorker::Destroy(){
//
//}

void VanillaSwapFixedDayCountWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  QuantLib::DayCounter returnValue = ObjectIDLibObjPtr->fixedDayCount(
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

void VanillaSwapFixedDayCountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFixedDayCount) {

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
  Nan::AsyncQueueWorker(new VanillaSwapFixedDayCountWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapFixedDayCountWorker::~VanillaSwapFixedDayCountWorker(){
//
//}

//void VanillaSwapFixedDayCountWorker::Destroy(){
//
//}

void VanillaSwapSpreadWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->spread(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapSpreadWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapSpread) {

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
  Nan::AsyncQueueWorker(new VanillaSwapSpreadWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapSpreadWorker::~VanillaSwapSpreadWorker(){
//
//}

//void VanillaSwapSpreadWorker::Destroy(){
//
//}

void VanillaSwapFloatingDayCountWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  QuantLib::DayCounter returnValue = ObjectIDLibObjPtr->floatingDayCount(
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

void VanillaSwapFloatingDayCountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFloatingDayCount) {

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
  Nan::AsyncQueueWorker(new VanillaSwapFloatingDayCountWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapFloatingDayCountWorker::~VanillaSwapFloatingDayCountWorker(){
//
//}

//void VanillaSwapFloatingDayCountWorker::Destroy(){
//
//}

void VanillaSwapPaymentConventionWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // invoke the member function
  QuantLib::BusinessDayConvention returnValue = ObjectIDLibObjPtr->paymentConvention(
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

void VanillaSwapPaymentConventionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapPaymentConvention) {

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
  Nan::AsyncQueueWorker(new VanillaSwapPaymentConventionWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VanillaSwapPaymentConventionWorker::~VanillaSwapPaymentConventionWorker(){
//
//}

//void VanillaSwapPaymentConventionWorker::Destroy(){
//
//}

void VanillaSwapFixedLegAnalysisWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date AfterDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mAfterDate, "AfterDate");

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::VanillaSwap)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->fixedLegAnalysis(
        AfterDateLib
       );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapFixedLegAnalysisWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpMatrix = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Local<Array> tmpArray = Nan::New<Array>(mReturnValue[i].size());
      for (unsigned int j = 0; j < mReturnValue[i].size(); j++) {
        Nan::Set(tmpArray,j,Nan::New<String>(mReturnValue[i][j]).ToLocalChecked());
      }
      Nan::Set(tmpMatrix,i,tmpArray);
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpMatrix
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFixedLegAnalysis) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t AfterDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VanillaSwapFixedLegAnalysisWorker(
    callback
    ,ObjectIDCpp
    ,AfterDateCpp
  ));

}

//VanillaSwapFixedLegAnalysisWorker::~VanillaSwapFixedLegAnalysisWorker(){
//
//}

//void VanillaSwapFixedLegAnalysisWorker::Destroy(){
//
//}

void VanillaSwapFloatingLegAnalysisWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date AfterDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mAfterDate, "AfterDate");

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::VanillaSwap)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->floatingLegAnalysis(
        AfterDateLib
       );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VanillaSwapFloatingLegAnalysisWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpMatrix = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Local<Array> tmpArray = Nan::New<Array>(mReturnValue[i].size());
      for (unsigned int j = 0; j < mReturnValue[i].size(); j++) {
        Nan::Set(tmpArray,j,Nan::New<String>(mReturnValue[i][j]).ToLocalChecked());
      }
      Nan::Set(tmpMatrix,i,tmpArray);
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpMatrix
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaSwapFloatingLegAnalysis) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t AfterDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VanillaSwapFloatingLegAnalysisWorker(
    callback
    ,ObjectIDCpp
    ,AfterDateCpp
  ));

}

//VanillaSwapFloatingLegAnalysisWorker::~VanillaSwapFloatingLegAnalysisWorker(){
//
//}

//void VanillaSwapFloatingLegAnalysisWorker::Destroy(){
//
//}
 