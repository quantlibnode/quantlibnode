// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "payoffs.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/stickyratchet.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void StrikedTypePayoffWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Option::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::Option::Type>()(mOptionType);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlStrikedTypePayoff(
          mObjectID,
          mPayoffID,
          mOptionType,
          mStrike,
          mThirdParameter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::StrikedTypePayoff(
          valueObject,
          mPayoffID,
          OptionTypeEnum,
          mStrike,
          mThirdParameter,
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

void StrikedTypePayoffWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StrikedTypePayoff) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PayoffID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("ThirdParameter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPayoffID(info[1]->ToString());
  string PayoffIDCpp(strdup(*strPayoffID));

  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[2]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double ThirdParameterCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StrikedTypePayoffWorker(
    callback
    ,ObjectIDCpp
    ,PayoffIDCpp
    ,OptionTypeCpp
    ,StrikeCpp
    ,ThirdParameterCpp
  ));

}

//StrikedTypePayoffWorker::~StrikedTypePayoffWorker(){
//
//}

//StrikedTypePayoffWorker::Destroy(){
//
//}

void DoubleStickyRatchetPayoffWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlDoubleStickyRatchetPayoff(
          mObjectID,
          mType1,
          mType2,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::DoubleStickyRatchetPayoff(
          valueObject,
          mType1,
          mType2,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
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

void DoubleStickyRatchetPayoffWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DoubleStickyRatchetPayoff) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Type1 is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Type2 is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Gearing1 is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Gearing2 is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Gearing3 is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Spread1 is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Spread2 is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Spread3 is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("InitialValue1 is required.");
  }
  if (info.Length() == 10 || !info[10]->IsNumber()) {
      return Nan::ThrowError("InitialValue2 is required.");
  }
  if (info.Length() == 11 || !info[11]->IsNumber()) {
      return Nan::ThrowError("AccrualFactor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double Type1Cpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double Type2Cpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double Gearing1Cpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double Gearing2Cpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double Gearing3Cpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double Spread1Cpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double Spread2Cpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double Spread3Cpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  double InitialValue1Cpp = Nan::To<double>(info[9]).FromJust();

  // convert js argument to c++ type
  double InitialValue2Cpp = Nan::To<double>(info[10]).FromJust();

  // convert js argument to c++ type
  double AccrualFactorCpp = Nan::To<double>(info[11]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[12].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DoubleStickyRatchetPayoffWorker(
    callback
    ,ObjectIDCpp
    ,Type1Cpp
    ,Type2Cpp
    ,Gearing1Cpp
    ,Gearing2Cpp
    ,Gearing3Cpp
    ,Spread1Cpp
    ,Spread2Cpp
    ,Spread3Cpp
    ,InitialValue1Cpp
    ,InitialValue2Cpp
    ,AccrualFactorCpp
  ));

}

//DoubleStickyRatchetPayoffWorker::~DoubleStickyRatchetPayoffWorker(){
//
//}

//DoubleStickyRatchetPayoffWorker::Destroy(){
//
//}

void RatchetPayoffWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRatchetPayoff(
          mObjectID,
          mGearing1,
          mGearing2,
          mSpread1,
          mSpread2,
          mInitialValue,
          mAccrualFactor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RatchetPayoff(
          valueObject,
          mGearing1,
          mGearing2,
          mSpread1,
          mSpread2,
          mInitialValue,
          mAccrualFactor,
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

void RatchetPayoffWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RatchetPayoff) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Gearing1 is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Gearing2 is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Spread1 is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Spread2 is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("InitialValue is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("AccrualFactor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double Gearing1Cpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double Gearing2Cpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double Spread1Cpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double Spread2Cpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double InitialValueCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double AccrualFactorCpp = Nan::To<double>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RatchetPayoffWorker(
    callback
    ,ObjectIDCpp
    ,Gearing1Cpp
    ,Gearing2Cpp
    ,Spread1Cpp
    ,Spread2Cpp
    ,InitialValueCpp
    ,AccrualFactorCpp
  ));

}

//RatchetPayoffWorker::~RatchetPayoffWorker(){
//
//}

//RatchetPayoffWorker::Destroy(){
//
//}

void StickyPayoffWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlStickyPayoff(
          mObjectID,
          mGearing1,
          mGearing2,
          mSpread1,
          mSpread2,
          mInitialValue,
          mAccrualFactor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::StickyPayoff(
          valueObject,
          mGearing1,
          mGearing2,
          mSpread1,
          mSpread2,
          mInitialValue,
          mAccrualFactor,
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

void StickyPayoffWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StickyPayoff) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Gearing1 is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Gearing2 is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Spread1 is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Spread2 is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("InitialValue is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("AccrualFactor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double Gearing1Cpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double Gearing2Cpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double Spread1Cpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double Spread2Cpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double InitialValueCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double AccrualFactorCpp = Nan::To<double>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StickyPayoffWorker(
    callback
    ,ObjectIDCpp
    ,Gearing1Cpp
    ,Gearing2Cpp
    ,Spread1Cpp
    ,Spread2Cpp
    ,InitialValueCpp
    ,AccrualFactorCpp
  ));

}

//StickyPayoffWorker::~StickyPayoffWorker(){
//
//}

//StickyPayoffWorker::Destroy(){
//
//}

void RatchetMaxPayoffWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRatchetMaxPayoff(
          mObjectID,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RatchetMaxPayoff(
          valueObject,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
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

void RatchetMaxPayoffWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RatchetMaxPayoff) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Gearing1 is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Gearing2 is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Gearing3 is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Spread1 is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Spread2 is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Spread3 is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("InitialValue1 is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("InitialValue2 is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("AccrualFactor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double Gearing1Cpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double Gearing2Cpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double Gearing3Cpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double Spread1Cpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double Spread2Cpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double Spread3Cpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double InitialValue1Cpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double InitialValue2Cpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  double AccrualFactorCpp = Nan::To<double>(info[9]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RatchetMaxPayoffWorker(
    callback
    ,ObjectIDCpp
    ,Gearing1Cpp
    ,Gearing2Cpp
    ,Gearing3Cpp
    ,Spread1Cpp
    ,Spread2Cpp
    ,Spread3Cpp
    ,InitialValue1Cpp
    ,InitialValue2Cpp
    ,AccrualFactorCpp
  ));

}

//RatchetMaxPayoffWorker::~RatchetMaxPayoffWorker(){
//
//}

//RatchetMaxPayoffWorker::Destroy(){
//
//}

void RatchetMinPayoffWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRatchetMinPayoff(
          mObjectID,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RatchetMinPayoff(
          valueObject,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
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

void RatchetMinPayoffWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RatchetMinPayoff) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Gearing1 is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Gearing2 is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Gearing3 is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Spread1 is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Spread2 is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Spread3 is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("InitialValue1 is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("InitialValue2 is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("AccrualFactor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double Gearing1Cpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double Gearing2Cpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double Gearing3Cpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double Spread1Cpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double Spread2Cpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double Spread3Cpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double InitialValue1Cpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double InitialValue2Cpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  double AccrualFactorCpp = Nan::To<double>(info[9]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RatchetMinPayoffWorker(
    callback
    ,ObjectIDCpp
    ,Gearing1Cpp
    ,Gearing2Cpp
    ,Gearing3Cpp
    ,Spread1Cpp
    ,Spread2Cpp
    ,Spread3Cpp
    ,InitialValue1Cpp
    ,InitialValue2Cpp
    ,AccrualFactorCpp
  ));

}

//RatchetMinPayoffWorker::~RatchetMinPayoffWorker(){
//
//}

//RatchetMinPayoffWorker::Destroy(){
//
//}

void StickyMaxPayoffWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlStickyMaxPayoff(
          mObjectID,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::StickyMaxPayoff(
          valueObject,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
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

void StickyMaxPayoffWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StickyMaxPayoff) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Gearing1 is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Gearing2 is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Gearing3 is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Spread1 is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Spread2 is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Spread3 is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("InitialValue1 is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("InitialValue2 is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("AccrualFactor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double Gearing1Cpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double Gearing2Cpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double Gearing3Cpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double Spread1Cpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double Spread2Cpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double Spread3Cpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double InitialValue1Cpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double InitialValue2Cpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  double AccrualFactorCpp = Nan::To<double>(info[9]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StickyMaxPayoffWorker(
    callback
    ,ObjectIDCpp
    ,Gearing1Cpp
    ,Gearing2Cpp
    ,Gearing3Cpp
    ,Spread1Cpp
    ,Spread2Cpp
    ,Spread3Cpp
    ,InitialValue1Cpp
    ,InitialValue2Cpp
    ,AccrualFactorCpp
  ));

}

//StickyMaxPayoffWorker::~StickyMaxPayoffWorker(){
//
//}

//StickyMaxPayoffWorker::Destroy(){
//
//}

void StickyMinPayoffWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlStickyMinPayoff(
          mObjectID,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::StickyMinPayoff(
          valueObject,
          mGearing1,
          mGearing2,
          mGearing3,
          mSpread1,
          mSpread2,
          mSpread3,
          mInitialValue1,
          mInitialValue2,
          mAccrualFactor,
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

void StickyMinPayoffWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StickyMinPayoff) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Gearing1 is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Gearing2 is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Gearing3 is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Spread1 is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Spread2 is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Spread3 is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("InitialValue1 is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("InitialValue2 is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("AccrualFactor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double Gearing1Cpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double Gearing2Cpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double Gearing3Cpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double Spread1Cpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double Spread2Cpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double Spread3Cpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double InitialValue1Cpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double InitialValue2Cpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  double AccrualFactorCpp = Nan::To<double>(info[9]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StickyMinPayoffWorker(
    callback
    ,ObjectIDCpp
    ,Gearing1Cpp
    ,Gearing2Cpp
    ,Gearing3Cpp
    ,Spread1Cpp
    ,Spread2Cpp
    ,Spread3Cpp
    ,InitialValue1Cpp
    ,InitialValue2Cpp
    ,AccrualFactorCpp
  ));

}

//StickyMinPayoffWorker::~StickyMinPayoffWorker(){
//
//}

//StickyMinPayoffWorker::Destroy(){
//
//}

void PayoffNameWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Payoff, QuantLib::Payoff)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->name(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PayoffNameWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PayoffName) {

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
  Nan::AsyncQueueWorker(new PayoffNameWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PayoffNameWorker::~PayoffNameWorker(){
//
//}

//PayoffNameWorker::Destroy(){
//
//}

void PayoffDescriptionWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Payoff, QuantLib::Payoff)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->description(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PayoffDescriptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PayoffDescription) {

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
  Nan::AsyncQueueWorker(new PayoffDescriptionWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PayoffDescriptionWorker::~PayoffDescriptionWorker(){
//
//}

//PayoffDescriptionWorker::Destroy(){
//
//}

void PayoffValueWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Payoff, QuantLib::Payoff)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->operator()(
        mUnderlying
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PayoffValueWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PayoffValue) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Underlying is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double UnderlyingCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PayoffValueWorker(
    callback
    ,ObjectIDCpp
    ,UnderlyingCpp
  ));

}

//PayoffValueWorker::~PayoffValueWorker(){
//
//}

//PayoffValueWorker::Destroy(){
//
//}

void PayoffOptionTypeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::TypePayoff, QuantLib::TypePayoff)


  // invoke the member function
  QuantLib::Option::Type returnValue = ObjectIDLibObjPtr->optionType(
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

void PayoffOptionTypeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PayoffOptionType) {

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
  Nan::AsyncQueueWorker(new PayoffOptionTypeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PayoffOptionTypeWorker::~PayoffOptionTypeWorker(){
//
//}

//PayoffOptionTypeWorker::Destroy(){
//
//}

void PayoffStrikeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->strike(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PayoffStrikeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PayoffStrike) {

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
  Nan::AsyncQueueWorker(new PayoffStrikeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PayoffStrikeWorker::~PayoffStrikeWorker(){
//
//}

//PayoffStrikeWorker::Destroy(){
//
//}

void PayoffThirdParameterWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::StrikedTypePayoff)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->thirdParameter(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PayoffThirdParameterWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PayoffThirdParameter) {

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
  Nan::AsyncQueueWorker(new PayoffThirdParameterWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PayoffThirdParameterWorker::~PayoffThirdParameterWorker(){
//
//}

//PayoffThirdParameterWorker::Destroy(){
//
//}
 