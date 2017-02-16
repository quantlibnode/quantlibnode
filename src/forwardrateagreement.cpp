/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "forwardrateagreement.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/forwardrateagreement.hpp>
#include <qlo/indexes/iborindex.hpp>
#include <qlo/yieldtermstructures.hpp>
#include <ql/indexes/iborindex.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void FRAWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ValueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mValueDate, "ValueDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date MaturityDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mMaturityDate, "MaturityDate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Position::Type PositionEnum =
      ObjectHandler::Create<QuantLib::Position::Type>()(mPosition);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFRA(
          mObjectID,
          mValueDate,
          mMaturityDate,
          mPosition,
          mStrike,
          mNotional,
          mIborIndex,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ForwardRateAgreement(
          valueObject,
          ValueDateLib,
          MaturityDateLib,
          PositionEnum,
          mStrike,
          mNotional,
          IborIndexLibObjPtr,
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

void FRAWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FRA) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Position is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Notional is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t ValueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t MaturityDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strPosition(info[3]->ToString());
  string PositionCpp(strdup(*strPosition));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double NotionalCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[6]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[7]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FRAWorker(
    callback
    ,ObjectIDCpp
    ,ValueDateCpp
    ,MaturityDateCpp
    ,PositionCpp
    ,StrikeCpp
    ,NotionalCpp
    ,IborIndexCpp
    ,YieldCurveCpp
  ));

}

//FRAWorker::~FRAWorker(){
//
//}

//void FRAWorker::Destroy(){
//
//}

void FRAforwardRateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::ForwardRateAgreement, QuantLib::ForwardRateAgreement)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->forwardRate(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void FRAforwardRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FRAforwardRate) {

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
  Nan::AsyncQueueWorker(new FRAforwardRateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//FRAforwardRateWorker::~FRAforwardRateWorker(){
//
//}

//void FRAforwardRateWorker::Destroy(){
//
//}

void FRAforwardValueWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::ForwardRateAgreement, QuantLib::ForwardRateAgreement)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->forwardValue(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void FRAforwardValueWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FRAforwardValue) {

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
  Nan::AsyncQueueWorker(new FRAforwardValueWorker(
    callback
    ,ObjectIDCpp
  ));

}

//FRAforwardValueWorker::~FRAforwardValueWorker(){
//
//}

//void FRAforwardValueWorker::Destroy(){
//
//}

void FRAspotValueWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::ForwardRateAgreement, QuantLib::ForwardRateAgreement)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->spotValue(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void FRAspotValueWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FRAspotValue) {

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
  Nan::AsyncQueueWorker(new FRAspotValueWorker(
    callback
    ,ObjectIDCpp
  ));

}

//FRAspotValueWorker::~FRAspotValueWorker(){
//
//}

//void FRAspotValueWorker::Destroy(){
//
//}
 