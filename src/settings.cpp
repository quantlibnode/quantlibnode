/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "settings.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/settings.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void SettingsEvaluationDateWorker::Execute(){

  try{
       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::Settings::instance().evaluationDate(
    );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SettingsEvaluationDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SettingsEvaluationDate) {

  // validate js arguments
 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[0].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SettingsEvaluationDateWorker(
    callback
  ));

}

//SettingsEvaluationDateWorker::~SettingsEvaluationDateWorker(){
//
//}

//void SettingsEvaluationDateWorker::Destroy(){
//
//}

void SettingsSetEvaluationDateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EvalDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEvalDate, "EvalDate");

       // invoke the utility function
  QuantLibAddin::qlSettingsSetEvaluationDate(
      EvalDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SettingsSetEvaluationDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SettingsSetEvaluationDate) {

  // validate js arguments
  // convert js argument to c++ type
  ObjectHandler::property_t EvalDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SettingsSetEvaluationDateWorker(
    callback
    ,EvalDateCpp
  ));

}

//SettingsSetEvaluationDateWorker::~SettingsSetEvaluationDateWorker(){
//
//}

//void SettingsSetEvaluationDateWorker::Destroy(){
//
//}

void SettingsEnforceTodaysHistoricFixingsWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLib::Settings::instance().enforcesTodaysHistoricFixings(
    );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SettingsEnforceTodaysHistoricFixingsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SettingsEnforceTodaysHistoricFixings) {

  // validate js arguments
 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[0].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SettingsEnforceTodaysHistoricFixingsWorker(
    callback
  ));

}

//SettingsEnforceTodaysHistoricFixingsWorker::~SettingsEnforceTodaysHistoricFixingsWorker(){
//
//}

//void SettingsEnforceTodaysHistoricFixingsWorker::Destroy(){
//
//}

void SettingsSetEnforceTodaysHistoricFixingsWorker::Execute(){

  try{
       // invoke the utility function
  QuantLibAddin::qlSettingsSetEnforceTodaysHistoricFixings(
      mBoolean
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SettingsSetEnforceTodaysHistoricFixingsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SettingsSetEnforceTodaysHistoricFixings) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsBoolean()) {
      return Nan::ThrowError("Boolean is required.");
  }
  // convert js argument to c++ type
  bool BooleanCpp = Nan::To<bool>(info[0]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SettingsSetEnforceTodaysHistoricFixingsWorker(
    callback
    ,BooleanCpp
  ));

}

//SettingsSetEnforceTodaysHistoricFixingsWorker::~SettingsSetEnforceTodaysHistoricFixingsWorker(){
//
//}

//void SettingsSetEnforceTodaysHistoricFixingsWorker::Destroy(){
//
//}
 