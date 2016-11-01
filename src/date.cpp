// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "date.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/date.hpp>
#include <ql/time/date.hpp>
#include <ql/time/imm.hpp>
#include <ql/time/ecb.hpp>
#include <ql/time/asx.hpp>
#include <qlo/loop/loop_date.hpp>
#include <oh/enumerations/typefactory.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void PeriodFromFrequencyWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);

       // invoke the utility function
  QuantLib::Period returnValue = QuantLibAddin::periodFromFrequency(
      FrequencyEnum
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PeriodFromFrequencyWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PeriodFromFrequency) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[0]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PeriodFromFrequencyWorker(
    callback
    ,FrequencyCpp
  ));

}

//PeriodFromFrequencyWorker::~PeriodFromFrequencyWorker(){
//
//}

//PeriodFromFrequencyWorker::Destroy(){
//
//}

void FrequencyFromPeriodWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> PeriodLib;

       std::vector<QuantLib::Frequency> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlFrequencyFromPeriodBind bindObject =
      boost::bind(
          &QuantLibAddin::frequencyFromPeriod
          ,_1
    );
  ObjectHandler::loop
      <QuantLibAddin::qlFrequencyFromPeriodBind, QuantLib::Period, QuantLib::Frequency>
          (bindObject,
            PeriodLib,
          returnValue
          );


  for(unsigned int i = 0; i< returnValue.size(); i++){
    std::ostringstream os;
    os << returnValue[i];
    mReturnValue.push_back(os.str());
  }

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void FrequencyFromPeriodWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<String>(mReturnValue[i]).ToLocalChecked());
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FrequencyFromPeriod) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Period is required.");
  }
  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>PeriodCpp;

  Local<Array> PeriodArray = info[0].As<Array>();
  for (unsigned int i = 0; i < PeriodArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(PeriodArray, i).ToLocalChecked()).FromJust()));
    PeriodCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FrequencyFromPeriodWorker(
    callback
    ,PeriodCpp
  ));

}

//FrequencyFromPeriodWorker::~FrequencyFromPeriodWorker(){
//
//}

//FrequencyFromPeriodWorker::Destroy(){
//
//}

void PeriodLessThanWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Period Period1Lib;
  QuantLibAddin::cppToLibrary(mPeriod1, Period1Lib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period Period2Lib;
  QuantLibAddin::cppToLibrary(mPeriod2, Period2Lib);

       // invoke the utility function
  mReturnValue = QuantLib::operator<(
      Period1Lib
      ,
       Period2Lib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PeriodLessThanWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PeriodLessThan) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Period1 is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Period2 is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strPeriod1(info[0]->ToString());
  string Period1Cpp(strdup(*strPeriod1));

  // convert js argument to c++ type
  String::Utf8Value strPeriod2(info[1]->ToString());
  string Period2Cpp(strdup(*strPeriod2));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PeriodLessThanWorker(
    callback
    ,Period1Cpp
    ,Period2Cpp
  ));

}

//PeriodLessThanWorker::~PeriodLessThanWorker(){
//
//}

//PeriodLessThanWorker::Destroy(){
//
//}

void PeriodEquivalentWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Period PeriodLib;
  QuantLibAddin::cppToLibrary(mPeriod, PeriodLib);

       // invoke the utility function
  QuantLib::Period returnValue = QuantLibAddin::periodEquivalent(
      PeriodLib
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PeriodEquivalentWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PeriodEquivalent) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Period is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strPeriod(info[0]->ToString());
  string PeriodCpp(strdup(*strPeriod));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PeriodEquivalentWorker(
    callback
    ,PeriodCpp
  ));

}

//PeriodEquivalentWorker::~PeriodEquivalentWorker(){
//
//}

//PeriodEquivalentWorker::Destroy(){
//
//}

void DateMinDateWorker::Execute(){

  try{
       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::Date::minDate(
    );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DateMinDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DateMinDate) {

  // validate js arguments
 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[0].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DateMinDateWorker(
    callback
  ));

}

//DateMinDateWorker::~DateMinDateWorker(){
//
//}

//DateMinDateWorker::Destroy(){
//
//}

void DateMaxDateWorker::Execute(){

  try{
       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::Date::maxDate(
    );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DateMaxDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DateMaxDate) {

  // validate js arguments
 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[0].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DateMaxDateWorker(
    callback
  ));

}

//DateMaxDateWorker::~DateMaxDateWorker(){
//
//}

//DateMaxDateWorker::Destroy(){
//
//}

void DateIsLeapWorker::Execute(){

  try{
     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlDateIsLeapBind bindObject =
      boost::bind(
          &QuantLib::Date::isLeap
          ,_1
    );
  ObjectHandler::loop
      <QuantLibAddin::qlDateIsLeapBind, long, bool>
          (bindObject,
           mYear,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DateIsLeapWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DateIsLeap) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Year is required.");
  }
  // convert js argument to c++ type
  std::vector<long>YearCpp;

  Local<Array> YearArray = info[0].As<Array>();
  for (unsigned int i = 0; i < YearArray->Length(); i++){
    YearCpp.push_back(Nan::To<int32_t>(Nan::Get(YearArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DateIsLeapWorker(
    callback
    ,YearCpp
  ));

}

//DateIsLeapWorker::~DateIsLeapWorker(){
//
//}

//DateIsLeapWorker::Destroy(){
//
//}

void DateEndOfMonthWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDate, "Date");

       std::vector<QuantLib::Date> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlDateEndOfMonthBind bindObject =
      boost::bind(
          &QuantLib::Date::endOfMonth
          ,_1
    );
  ObjectHandler::loop
      <QuantLibAddin::qlDateEndOfMonthBind, QuantLib::Date, QuantLib::Date>
          (bindObject,
            DateLib,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DateEndOfMonthWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::DateEndOfMonth) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Date is required.");
  }
  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DateCpp;

  Local<Array> DateArray = info[0].As<Array>();
  for (unsigned int i = 0; i < DateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DateArray, i).ToLocalChecked()).FromJust()));
    DateCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DateEndOfMonthWorker(
    callback
    ,DateCpp
  ));

}

//DateEndOfMonthWorker::~DateEndOfMonthWorker(){
//
//}

//DateEndOfMonthWorker::Destroy(){
//
//}

void DateIsEndOfMonthWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDate, "Date");

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlDateIsEndOfMonthBind bindObject =
      boost::bind(
          &QuantLib::Date::isEndOfMonth
          ,_1
    );
  ObjectHandler::loop
      <QuantLibAddin::qlDateIsEndOfMonthBind, QuantLib::Date, bool>
          (bindObject,
            DateLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DateIsEndOfMonthWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DateIsEndOfMonth) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Date is required.");
  }
  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DateCpp;

  Local<Array> DateArray = info[0].As<Array>();
  for (unsigned int i = 0; i < DateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DateArray, i).ToLocalChecked()).FromJust()));
    DateCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DateIsEndOfMonthWorker(
    callback
    ,DateCpp
  ));

}

//DateIsEndOfMonthWorker::~DateIsEndOfMonthWorker(){
//
//}

//DateIsEndOfMonthWorker::Destroy(){
//
//}

void DateNextWeekdayWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDate, "Date");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Weekday WeekdayEnum =
      ObjectHandler::Create<QuantLib::Weekday>()(mWeekday);

       std::vector<QuantLib::Date> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlDateNextWeekdayBind bindObject =
      boost::bind(
          &QuantLib::Date::nextWeekday
          ,_1
          ,WeekdayEnum
    );
  ObjectHandler::loop
      <QuantLibAddin::qlDateNextWeekdayBind, QuantLib::Date, QuantLib::Date>
          (bindObject,
            DateLib,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DateNextWeekdayWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::DateNextWeekday) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Date is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Weekday is required.");
  }
  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DateCpp;

  Local<Array> DateArray = info[0].As<Array>();
  for (unsigned int i = 0; i < DateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DateArray, i).ToLocalChecked()).FromJust()));
    DateCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strWeekday(info[1]->ToString());
  string WeekdayCpp(strdup(*strWeekday));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DateNextWeekdayWorker(
    callback
    ,DateCpp
    ,WeekdayCpp
  ));

}

//DateNextWeekdayWorker::~DateNextWeekdayWorker(){
//
//}

//DateNextWeekdayWorker::Destroy(){
//
//}

void DateNthWeekdayWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Weekday WeekdayEnum =
      ObjectHandler::Create<QuantLib::Weekday>()(mWeekday);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Month MonthEnum =
      ObjectHandler::Create<QuantLib::Month>()(mMonth);

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::Date::nthWeekday(
      mNth
      ,
       WeekdayEnum
      ,
       MonthEnum
      ,
       mYear
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DateNthWeekdayWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DateNthWeekday) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Nth is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Weekday is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Month is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Year is required.");
  }
  // convert js argument to c++ type
  long NthCpp = Nan::To<int32_t>(info[0]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strWeekday(info[1]->ToString());
  string WeekdayCpp(strdup(*strWeekday));

  // convert js argument to c++ type
  String::Utf8Value strMonth(info[2]->ToString());
  string MonthCpp(strdup(*strMonth));

  // convert js argument to c++ type
  long YearCpp = Nan::To<int32_t>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DateNthWeekdayWorker(
    callback
    ,NthCpp
    ,WeekdayCpp
    ,MonthCpp
    ,YearCpp
  ));

}

//DateNthWeekdayWorker::~DateNthWeekdayWorker(){
//
//}

//DateNthWeekdayWorker::Destroy(){
//
//}

void IMMIsIMMdateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDate, "Date");

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlIMMIsIMMdateBind bindObject =
      boost::bind(
          &QuantLib::IMM::isIMMdate
          ,_1
          ,mMainCycle
    );
  ObjectHandler::loop
      <QuantLibAddin::qlIMMIsIMMdateBind, QuantLib::Date, bool>
          (bindObject,
            DateLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IMMIsIMMdateWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IMMIsIMMdate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Date is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DateCpp;

  Local<Array> DateArray = info[0].As<Array>();
  for (unsigned int i = 0; i < DateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DateArray, i).ToLocalChecked()).FromJust()));
    DateCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool MainCycleCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IMMIsIMMdateWorker(
    callback
    ,DateCpp
    ,MainCycleCpp
  ));

}

//IMMIsIMMdateWorker::~IMMIsIMMdateWorker(){
//
//}

//IMMIsIMMdateWorker::Destroy(){
//
//}

void IMMIsIMMcodeWorker::Execute(){

  try{
     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlIMMIsIMMcodeBind bindObject =
      boost::bind(
          &QuantLib::IMM::isIMMcode
          ,_1
          ,mMainCycle
    );
  ObjectHandler::loop
      <QuantLibAddin::qlIMMIsIMMcodeBind, string, bool>
          (bindObject,
           mCode,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IMMIsIMMcodeWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IMMIsIMMcode) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Code is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  std::vector<string>CodeCpp;

  Local<Array> CodeArray = info[0].As<Array>();
  for (unsigned int i = 0; i < CodeArray->Length(); i++){
    String::Utf8Value strCode(Nan::Get(CodeArray, i).ToLocalChecked()->ToString());
    CodeCpp.push_back(strdup(*strCode));
  }

  // convert js argument to c++ type
  bool MainCycleCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IMMIsIMMcodeWorker(
    callback
    ,CodeCpp
    ,MainCycleCpp
  ));

}

//IMMIsIMMcodeWorker::~IMMIsIMMcodeWorker(){
//
//}

//IMMIsIMMcodeWorker::Destroy(){
//
//}

void IMMcodeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> IMMdateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mIMMdate, "IMMdate");

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlIMMcodeBind bindObject =
      boost::bind(
          &QuantLib::IMM::code
          ,_1
    );
  ObjectHandler::loop
      <QuantLibAddin::qlIMMcodeBind, QuantLib::Date, string>
          (bindObject,
            IMMdateLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IMMcodeWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<String>(mReturnValue[i]).ToLocalChecked());
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IMMcode) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("IMMdate is required.");
  }
  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>IMMdateCpp;

  Local<Array> IMMdateArray = info[0].As<Array>();
  for (unsigned int i = 0; i < IMMdateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(IMMdateArray, i).ToLocalChecked()).FromJust()));
    IMMdateCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IMMcodeWorker(
    callback
    ,IMMdateCpp
  ));

}

//IMMcodeWorker::~IMMcodeWorker(){
//
//}

//IMMcodeWorker::Destroy(){
//
//}

void IMMNextCodeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  mReturnValue = QuantLib::IMM::nextCode(
      RefDateLib
      ,
       mMainCycle
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IMMNextCodeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IMMNextCode) {

  // validate js arguments
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

  // convert js argument to c++ type
  bool MainCycleCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IMMNextCodeWorker(
    callback
    ,RefDateCpp
    ,MainCycleCpp
  ));

}

//IMMNextCodeWorker::~IMMNextCodeWorker(){
//
//}

//IMMNextCodeWorker::Destroy(){
//
//}

void IMMNextCodesWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlIMMNextCodes(
      RefDateLib
      ,
       mMainCycle
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IMMNextCodesWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<String>(mReturnValue[i]).ToLocalChecked());
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IMMNextCodes) {

  // validate js arguments
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

  // convert js argument to c++ type
  std::vector<bool>MainCycleCpp;

  Local<Array> MainCycleArray = info[1].As<Array>();
  for (unsigned int i = 0; i < MainCycleArray->Length(); i++){
    MainCycleCpp.push_back(Nan::To<bool>(Nan::Get(MainCycleArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IMMNextCodesWorker(
    callback
    ,RefDateCpp
    ,MainCycleCpp
  ));

}

//IMMNextCodesWorker::~IMMNextCodesWorker(){
//
//}

//IMMNextCodesWorker::Destroy(){
//
//}

void IMMdateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       std::vector<QuantLib::Date> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlIMMdateBind bindObject =
      boost::bind(
          &QuantLib::IMM::date
          ,_1
          ,RefDateLib
    );
  ObjectHandler::loop
      <QuantLibAddin::qlIMMdateBind, string, QuantLib::Date>
          (bindObject,
           mIMMcode,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IMMdateWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::IMMdate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("IMMcode is required.");
  }
  // convert js argument to c++ type
  std::vector<string>IMMcodeCpp;

  Local<Array> IMMcodeArray = info[0].As<Array>();
  for (unsigned int i = 0; i < IMMcodeArray->Length(); i++){
    String::Utf8Value strIMMcode(Nan::Get(IMMcodeArray, i).ToLocalChecked()->ToString());
    IMMcodeCpp.push_back(strdup(*strIMMcode));
  }

  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IMMdateWorker(
    callback
    ,IMMcodeCpp
    ,RefDateCpp
  ));

}

//IMMdateWorker::~IMMdateWorker(){
//
//}

//IMMdateWorker::Destroy(){
//
//}

void IMMNextDateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::IMM::nextDate(
      RefDateLib
      ,
       mMainCycle
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IMMNextDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IMMNextDate) {

  // validate js arguments
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

  // convert js argument to c++ type
  bool MainCycleCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IMMNextDateWorker(
    callback
    ,RefDateCpp
    ,MainCycleCpp
  ));

}

//IMMNextDateWorker::~IMMNextDateWorker(){
//
//}

//IMMNextDateWorker::Destroy(){
//
//}

void IMMNextDatesWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  std::vector<QuantLib::Date> returnValue = QuantLibAddin::qlIMMNextDates(
      RefDateLib
      ,
       mMainCycle
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IMMNextDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::IMMNextDates) {

  // validate js arguments
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

  // convert js argument to c++ type
  std::vector<bool>MainCycleCpp;

  Local<Array> MainCycleArray = info[1].As<Array>();
  for (unsigned int i = 0; i < MainCycleArray->Length(); i++){
    MainCycleCpp.push_back(Nan::To<bool>(Nan::Get(MainCycleArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IMMNextDatesWorker(
    callback
    ,RefDateCpp
    ,MainCycleCpp
  ));

}

//IMMNextDatesWorker::~IMMNextDatesWorker(){
//
//}

//IMMNextDatesWorker::Destroy(){
//
//}

void ASXIsASXdateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDate, "Date");

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlASXIsASXdateBind bindObject =
      boost::bind(
          &QuantLib::ASX::isASXdate
          ,_1
          ,mMainCycle
    );
  ObjectHandler::loop
      <QuantLibAddin::qlASXIsASXdateBind, QuantLib::Date, bool>
          (bindObject,
            DateLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ASXIsASXdateWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ASXIsASXdate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Date is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DateCpp;

  Local<Array> DateArray = info[0].As<Array>();
  for (unsigned int i = 0; i < DateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DateArray, i).ToLocalChecked()).FromJust()));
    DateCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool MainCycleCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ASXIsASXdateWorker(
    callback
    ,DateCpp
    ,MainCycleCpp
  ));

}

//ASXIsASXdateWorker::~ASXIsASXdateWorker(){
//
//}

//ASXIsASXdateWorker::Destroy(){
//
//}

void ASXIsASXcodeWorker::Execute(){

  try{
     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlASXIsASXcodeBind bindObject =
      boost::bind(
          &QuantLib::ASX::isASXcode
          ,_1
          ,mMainCycle
    );
  ObjectHandler::loop
      <QuantLibAddin::qlASXIsASXcodeBind, string, bool>
          (bindObject,
           mCode,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ASXIsASXcodeWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ASXIsASXcode) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Code is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  std::vector<string>CodeCpp;

  Local<Array> CodeArray = info[0].As<Array>();
  for (unsigned int i = 0; i < CodeArray->Length(); i++){
    String::Utf8Value strCode(Nan::Get(CodeArray, i).ToLocalChecked()->ToString());
    CodeCpp.push_back(strdup(*strCode));
  }

  // convert js argument to c++ type
  bool MainCycleCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ASXIsASXcodeWorker(
    callback
    ,CodeCpp
    ,MainCycleCpp
  ));

}

//ASXIsASXcodeWorker::~ASXIsASXcodeWorker(){
//
//}

//ASXIsASXcodeWorker::Destroy(){
//
//}

void ASXcodeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> ASXdateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mASXdate, "ASXdate");

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlASXcodeBind bindObject =
      boost::bind(
          &QuantLib::ASX::code
          ,_1
    );
  ObjectHandler::loop
      <QuantLibAddin::qlASXcodeBind, QuantLib::Date, string>
          (bindObject,
            ASXdateLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ASXcodeWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<String>(mReturnValue[i]).ToLocalChecked());
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ASXcode) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("ASXdate is required.");
  }
  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>ASXdateCpp;

  Local<Array> ASXdateArray = info[0].As<Array>();
  for (unsigned int i = 0; i < ASXdateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(ASXdateArray, i).ToLocalChecked()).FromJust()));
    ASXdateCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ASXcodeWorker(
    callback
    ,ASXdateCpp
  ));

}

//ASXcodeWorker::~ASXcodeWorker(){
//
//}

//ASXcodeWorker::Destroy(){
//
//}

void ASXNextCodeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  mReturnValue = QuantLib::ASX::nextCode(
      RefDateLib
      ,
       mMainCycle
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ASXNextCodeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ASXNextCode) {

  // validate js arguments
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

  // convert js argument to c++ type
  bool MainCycleCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ASXNextCodeWorker(
    callback
    ,RefDateCpp
    ,MainCycleCpp
  ));

}

//ASXNextCodeWorker::~ASXNextCodeWorker(){
//
//}

//ASXNextCodeWorker::Destroy(){
//
//}

void ASXNextCodesWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlASXNextCodes(
      RefDateLib
      ,
       mMainCycle
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ASXNextCodesWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<String>(mReturnValue[i]).ToLocalChecked());
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ASXNextCodes) {

  // validate js arguments
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

  // convert js argument to c++ type
  std::vector<bool>MainCycleCpp;

  Local<Array> MainCycleArray = info[1].As<Array>();
  for (unsigned int i = 0; i < MainCycleArray->Length(); i++){
    MainCycleCpp.push_back(Nan::To<bool>(Nan::Get(MainCycleArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ASXNextCodesWorker(
    callback
    ,RefDateCpp
    ,MainCycleCpp
  ));

}

//ASXNextCodesWorker::~ASXNextCodesWorker(){
//
//}

//ASXNextCodesWorker::Destroy(){
//
//}

void ASXdateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       std::vector<QuantLib::Date> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlASXdateBind bindObject =
      boost::bind(
          &QuantLib::ASX::date
          ,_1
          ,RefDateLib
    );
  ObjectHandler::loop
      <QuantLibAddin::qlASXdateBind, string, QuantLib::Date>
          (bindObject,
           mASXcode,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ASXdateWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::ASXdate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("ASXcode is required.");
  }
  // convert js argument to c++ type
  std::vector<string>ASXcodeCpp;

  Local<Array> ASXcodeArray = info[0].As<Array>();
  for (unsigned int i = 0; i < ASXcodeArray->Length(); i++){
    String::Utf8Value strASXcode(Nan::Get(ASXcodeArray, i).ToLocalChecked()->ToString());
    ASXcodeCpp.push_back(strdup(*strASXcode));
  }

  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ASXdateWorker(
    callback
    ,ASXcodeCpp
    ,RefDateCpp
  ));

}

//ASXdateWorker::~ASXdateWorker(){
//
//}

//ASXdateWorker::Destroy(){
//
//}

void ASXNextDateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::ASX::nextDate(
      RefDateLib
      ,
       mMainCycle
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ASXNextDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ASXNextDate) {

  // validate js arguments
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

  // convert js argument to c++ type
  bool MainCycleCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ASXNextDateWorker(
    callback
    ,RefDateCpp
    ,MainCycleCpp
  ));

}

//ASXNextDateWorker::~ASXNextDateWorker(){
//
//}

//ASXNextDateWorker::Destroy(){
//
//}

void ASXNextDatesWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  std::vector<QuantLib::Date> returnValue = QuantLibAddin::qlASXNextDates(
      RefDateLib
      ,
       mMainCycle
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ASXNextDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::ASXNextDates) {

  // validate js arguments
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("MainCycle is required.");
  }
  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

  // convert js argument to c++ type
  std::vector<bool>MainCycleCpp;

  Local<Array> MainCycleArray = info[1].As<Array>();
  for (unsigned int i = 0; i < MainCycleArray->Length(); i++){
    MainCycleCpp.push_back(Nan::To<bool>(Nan::Get(MainCycleArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ASXNextDatesWorker(
    callback
    ,RefDateCpp
    ,MainCycleCpp
  ));

}

//ASXNextDatesWorker::~ASXNextDatesWorker(){
//
//}

//ASXNextDatesWorker::Destroy(){
//
//}

void ECBKnownDatesWorker::Execute(){

  try{
       // invoke the utility function
  std::vector<QuantLib::Date> returnValue = QuantLibAddin::qlECBKnownDates(
  );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBKnownDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::ECBKnownDates) {

  // validate js arguments
 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[0].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBKnownDatesWorker(
    callback
  ));

}

//ECBKnownDatesWorker::~ECBKnownDatesWorker(){
//
//}

//ECBKnownDatesWorker::Destroy(){
//
//}

void ECBAddDateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateLib = ObjectHandler::convert2<QuantLib::Date>(
      mDate, "Date");

       // invoke the utility function
  QuantLib::ECB::addDate(
      DateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBAddDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBAddDate) {

  // validate js arguments
  // convert js argument to c++ type
  ObjectHandler::property_t DateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBAddDateWorker(
    callback
    ,DateCpp
  ));

}

//ECBAddDateWorker::~ECBAddDateWorker(){
//
//}

//ECBAddDateWorker::Destroy(){
//
//}

void ECBRemoveDateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateLib = ObjectHandler::convert2<QuantLib::Date>(
      mDate, "Date");

       // invoke the utility function
  QuantLib::ECB::removeDate(
      DateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBRemoveDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBRemoveDate) {

  // validate js arguments
  // convert js argument to c++ type
  ObjectHandler::property_t DateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBRemoveDateWorker(
    callback
    ,DateCpp
  ));

}

//ECBRemoveDateWorker::~ECBRemoveDateWorker(){
//
//}

//ECBRemoveDateWorker::Destroy(){
//
//}

void ECBdate2Worker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Month MonthEnum =
      ObjectHandler::Create<QuantLib::Month>()(mMonth);

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::ECB::date(
      MonthEnum
      ,
       mYear
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBdate2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBdate2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Month is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Year is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strMonth(info[0]->ToString());
  string MonthCpp(strdup(*strMonth));

  // convert js argument to c++ type
  long YearCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBdate2Worker(
    callback
    ,MonthCpp
    ,YearCpp
  ));

}

//ECBdate2Worker::~ECBdate2Worker(){
//
//}

//ECBdate2Worker::Destroy(){
//
//}

void ECBdateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::ECB::date(
      mECBcode
      ,
       RefDateLib
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBdateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBdate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ECBcode is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strECBcode(info[0]->ToString());
  string ECBcodeCpp(strdup(*strECBcode));

  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBdateWorker(
    callback
    ,ECBcodeCpp
    ,RefDateCpp
  ));

}

//ECBdateWorker::~ECBdateWorker(){
//
//}

//ECBdateWorker::Destroy(){
//
//}

void ECBcodeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ECBdateLib = ObjectHandler::convert2<QuantLib::Date>(
      mECBdate, "ECBdate");

       // invoke the utility function
  mReturnValue = QuantLib::ECB::code(
      ECBdateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBcodeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBcode) {

  // validate js arguments
  // convert js argument to c++ type
  ObjectHandler::property_t ECBdateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBcodeWorker(
    callback
    ,ECBdateCpp
  ));

}

//ECBcodeWorker::~ECBcodeWorker(){
//
//}

//ECBcodeWorker::Destroy(){
//
//}

void ECBNextDateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateLib = ObjectHandler::convert2<QuantLib::Date>(
      mDate, "Date");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::ECB::nextDate(
      DateLib
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBNextDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBNextDate) {

  // validate js arguments
  // convert js argument to c++ type
  ObjectHandler::property_t DateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBNextDateWorker(
    callback
    ,DateCpp
  ));

}

//ECBNextDateWorker::~ECBNextDateWorker(){
//
//}

//ECBNextDateWorker::Destroy(){
//
//}

void ECBNextDate2Worker::Execute(){

  try{
       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::ECB::nextDate(
      mCode
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBNextDate2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBNextDate2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Code is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCode(info[0]->ToString());
  string CodeCpp(strdup(*strCode));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBNextDate2Worker(
    callback
    ,CodeCpp
  ));

}

//ECBNextDate2Worker::~ECBNextDate2Worker(){
//
//}

//ECBNextDate2Worker::Destroy(){
//
//}

void ECBNextDatesWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateLib = ObjectHandler::convert2<QuantLib::Date>(
      mDate, "Date");

       // invoke the utility function
  std::vector<QuantLib::Date> returnValue = QuantLib::ECB::nextDates(
      DateLib
   );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBNextDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::ECBNextDates) {

  // validate js arguments
  // convert js argument to c++ type
  ObjectHandler::property_t DateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBNextDatesWorker(
    callback
    ,DateCpp
  ));

}

//ECBNextDatesWorker::~ECBNextDatesWorker(){
//
//}

//ECBNextDatesWorker::Destroy(){
//
//}

void ECBIsECBdateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDate, "Date");

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlECBIsECBdateBind bindObject =
      boost::bind(
          &QuantLib::ECB::isECBdate
          ,_1
    );
  ObjectHandler::loop
      <QuantLibAddin::qlECBIsECBdateBind, QuantLib::Date, bool>
          (bindObject,
            DateLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBIsECBdateWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBIsECBdate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Date is required.");
  }
  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DateCpp;

  Local<Array> DateArray = info[0].As<Array>();
  for (unsigned int i = 0; i < DateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DateArray, i).ToLocalChecked()).FromJust()));
    DateCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBIsECBdateWorker(
    callback
    ,DateCpp
  ));

}

//ECBIsECBdateWorker::~ECBIsECBdateWorker(){
//
//}

//ECBIsECBdateWorker::Destroy(){
//
//}

void ECBIsECBcodeWorker::Execute(){

  try{
     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlECBIsECBcodeBind bindObject =
      boost::bind(
          &QuantLib::ECB::isECBcode
          ,_1
    );
  ObjectHandler::loop
      <QuantLibAddin::qlECBIsECBcodeBind, string, bool>
          (bindObject,
           mCode,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBIsECBcodeWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBIsECBcode) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Code is required.");
  }
  // convert js argument to c++ type
  std::vector<string>CodeCpp;

  Local<Array> CodeArray = info[0].As<Array>();
  for (unsigned int i = 0; i < CodeArray->Length(); i++){
    String::Utf8Value strCode(Nan::Get(CodeArray, i).ToLocalChecked()->ToString());
    CodeCpp.push_back(strdup(*strCode));
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBIsECBcodeWorker(
    callback
    ,CodeCpp
  ));

}

//ECBIsECBcodeWorker::~ECBIsECBcodeWorker(){
//
//}

//ECBIsECBcodeWorker::Destroy(){
//
//}

void ECBNextCodeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  mReturnValue = QuantLib::ECB::nextCode(
      RefDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBNextCodeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBNextCode) {

  // validate js arguments
  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[0]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBNextCodeWorker(
    callback
    ,RefDateCpp
  ));

}

//ECBNextCodeWorker::~ECBNextCodeWorker(){
//
//}

//ECBNextCodeWorker::Destroy(){
//
//}

void ECBNextCode2Worker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLib::ECB::nextCode(
      mCode
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ECBNextCode2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ECBNextCode2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Code is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strCode(info[0]->ToString());
  string CodeCpp(strdup(*strCode));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ECBNextCode2Worker(
    callback
    ,CodeCpp
  ));

}

//ECBNextCode2Worker::~ECBNextCode2Worker(){
//
//}

//ECBNextCode2Worker::Destroy(){
//
//}
 