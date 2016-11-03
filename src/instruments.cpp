/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "instruments.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/baseinstruments.hpp>
#include <qlo/pricingengines.hpp>
#include <ql/instrument.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void InstrumentNPVWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Instrument, QuantLib::Instrument)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->NPV(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InstrumentNPVWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InstrumentNPV) {

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
  Nan::AsyncQueueWorker(new InstrumentNPVWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InstrumentNPVWorker::~InstrumentNPVWorker(){
//
//}

//void InstrumentNPVWorker::Destroy(){
//
//}

void InstrumentErrorEstimateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Instrument, QuantLib::Instrument)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->errorEstimate(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InstrumentErrorEstimateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InstrumentErrorEstimate) {

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
  Nan::AsyncQueueWorker(new InstrumentErrorEstimateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InstrumentErrorEstimateWorker::~InstrumentErrorEstimateWorker(){
//
//}

//void InstrumentErrorEstimateWorker::Destroy(){
//
//}

void InstrumentValuationDateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Instrument, QuantLib::Instrument)


  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->valuationDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InstrumentValuationDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InstrumentValuationDate) {

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
  Nan::AsyncQueueWorker(new InstrumentValuationDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InstrumentValuationDateWorker::~InstrumentValuationDateWorker(){
//
//}

//void InstrumentValuationDateWorker::Destroy(){
//
//}

void InstrumentResultsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Instrument, QuantLib::Instrument)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->result<QuantLib::Real>(
        mResultType
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InstrumentResultsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InstrumentResults) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("ResultType is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strResultType(info[1]->ToString());
  string ResultTypeCpp(strdup(*strResultType));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InstrumentResultsWorker(
    callback
    ,ObjectIDCpp
    ,ResultTypeCpp
  ));

}

//InstrumentResultsWorker::~InstrumentResultsWorker(){
//
//}

//void InstrumentResultsWorker::Destroy(){
//
//}

void InstrumentIsExpiredWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Instrument, QuantLib::Instrument)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->isExpired(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InstrumentIsExpiredWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InstrumentIsExpired) {

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
  Nan::AsyncQueueWorker(new InstrumentIsExpiredWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InstrumentIsExpiredWorker::~InstrumentIsExpiredWorker(){
//
//}

//void InstrumentIsExpiredWorker::Destroy(){
//
//}

void InstrumentSetPricingEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(PricingEngineObjPtr, mPricingEngine, QuantLibAddin::PricingEngine)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Instrument)


  // invoke the member function
  ObjectIDObjPtr->setPricingEngine(
        PricingEngineObjPtr
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InstrumentSetPricingEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InstrumentSetPricingEngine) {

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
  Nan::AsyncQueueWorker(new InstrumentSetPricingEngineWorker(
    callback
    ,ObjectIDCpp
    ,PricingEngineCpp
  ));

}

//InstrumentSetPricingEngineWorker::~InstrumentSetPricingEngineWorker(){
//
//}

//void InstrumentSetPricingEngineWorker::Destroy(){
//
//}
 