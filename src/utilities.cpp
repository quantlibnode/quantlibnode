/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "utilities.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/utilities.hpp>
#include <ql/models/marketmodels/utilities.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void xlVersionWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLibAddin::qlxlVersion(
      mVerbose
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void xlVersionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::xlVersion) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsBoolean()) {
      return Nan::ThrowError("Verbose is required.");
  }
  // convert js argument to c++ type
  bool VerboseCpp = Nan::To<bool>(info[0]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new xlVersionWorker(
    callback
    ,VerboseCpp
  ));

}

//xlVersionWorker::~xlVersionWorker(){
//
//}

//void xlVersionWorker::Destroy(){
//
//}

void AddinVersionWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLibAddin::qlAddinVersion(
    );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AddinVersionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AddinVersion) {

  // validate js arguments
 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[0].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AddinVersionWorker(
    callback
  ));

}

//AddinVersionWorker::~AddinVersionWorker(){
//
//}

//void AddinVersionWorker::Destroy(){
//
//}

void VersionWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLibAddin::qlVersion(
    );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VersionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Version) {

  // validate js arguments
 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[0].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VersionWorker(
    callback
  ));

}

//VersionWorker::~VersionWorker(){
//
//}

//void VersionWorker::Destroy(){
//
//}

void FunctionCountWorker::Execute(){

  try{
       mReturnValue =  1046;
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void FunctionCountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FunctionCount) {

  // validate js arguments
 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[0].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FunctionCountWorker(
    callback
  ));

}

//FunctionCountWorker::~FunctionCountWorker(){
//
//}

//void FunctionCountWorker::Destroy(){
//
//}
 