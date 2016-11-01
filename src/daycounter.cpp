// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "daycounter.hpp"

#include <qlo/qladdindefines.hpp>
#include <ql/time/date.hpp>
#include <ql/time/daycounter.hpp>
#include <qlo/loop/loop_daycounter.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void DayCounterNameWorker::Execute(){

  try{
     
  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter daycounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

  // invoke the member function
  mReturnValue = daycounterEnum.name(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DayCounterNameWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DayCounterName) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[0]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DayCounterNameWorker(
    callback
    ,DayCounterCpp
  ));

}

//DayCounterNameWorker::~DayCounterNameWorker(){
//
//}

//DayCounterNameWorker::Destroy(){
//
//}

void DayCounterDayCountWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> EndDateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mEndDate, "EndDate");

       // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter daycounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

  // loop on the input parameter and populate the return vector

  QuantLibAddin::qlDayCounterDayCountBind bindObject =
      boost::bind((QuantLibAddin::qlDayCounterDayCountSignature)
              &QuantLib::DayCounter::dayCount,
              daycounterEnum
              ,StartDateLib
              ,_1
            );
      ObjectHandler::loop
          <QuantLibAddin::qlDayCounterDayCountBind,
                          QuantLib::Date,
                          long>
          (bindObject, EndDateLib,
            mReturnValue);
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DayCounterDayCountWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::DayCounterDayCount) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("EndDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[0]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>EndDateCpp;

  Local<Array> EndDateArray = info[2].As<Array>();
  for (unsigned int i = 0; i < EndDateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(EndDateArray, i).ToLocalChecked()).FromJust()));
    EndDateCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DayCounterDayCountWorker(
    callback
    ,DayCounterCpp
    ,StartDateCpp
    ,EndDateCpp
  ));

}

//DayCounterDayCountWorker::~DayCounterDayCountWorker(){
//
//}

//DayCounterDayCountWorker::Destroy(){
//
//}

void DayCounterYearFractionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> EndDateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mEndDate, "EndDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodStartLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodStart, "RefPeriodStart");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodEndLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodEnd, "RefPeriodEnd");

       // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter daycounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

  // loop on the input parameter and populate the return vector

  QuantLibAddin::qlDayCounterYearFractionBind bindObject =
      boost::bind((QuantLibAddin::qlDayCounterYearFractionSignature)
              &QuantLib::DayCounter::yearFraction,
              daycounterEnum
              ,StartDateLib
              ,_1
              ,RefPeriodStartLib
              ,RefPeriodEndLib
            );
      ObjectHandler::loop
          <QuantLibAddin::qlDayCounterYearFractionBind,
                          QuantLib::Date,
                          double>
          (bindObject, EndDateLib,
            mReturnValue);
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DayCounterYearFractionWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::DayCounterYearFraction) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("EndDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[0]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>EndDateCpp;

  Local<Array> EndDateArray = info[2].As<Array>();
  for (unsigned int i = 0; i < EndDateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(EndDateArray, i).ToLocalChecked()).FromJust()));
    EndDateCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodStartCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodEndCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DayCounterYearFractionWorker(
    callback
    ,DayCounterCpp
    ,StartDateCpp
    ,EndDateCpp
    ,RefPeriodStartCpp
    ,RefPeriodEndCpp
  ));

}

//DayCounterYearFractionWorker::~DayCounterYearFractionWorker(){
//
//}

//DayCounterYearFractionWorker::Destroy(){
//
//}
 