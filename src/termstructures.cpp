/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "termstructures.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/handleimpl.hpp>
#include <qlo/conversions/coercetermstructure.hpp>
#include <qlo/ratehelpers.hpp>
#include <qlo/loop/loop_termstructures.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void RelinkableHandleYieldTermStructureWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRelinkableHandleYieldTermStructure(
          mObjectID,
          mCurrentLink,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RelinkableHandleImpl<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>(
          valueObject,
          mCurrentLink,
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

void RelinkableHandleYieldTermStructureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RelinkableHandleYieldTermStructure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurrentLink is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurrentLink(info[1]->ToString());
  string CurrentLinkCpp(strdup(*strCurrentLink));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RelinkableHandleYieldTermStructureWorker(
    callback
    ,ObjectIDCpp
    ,CurrentLinkCpp
  ));

}

//RelinkableHandleYieldTermStructureWorker::~RelinkableHandleYieldTermStructureWorker(){
//
//}

//void RelinkableHandleYieldTermStructureWorker::Destroy(){
//
//}

void DiscountCurveWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> CurveDatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mCurveDates, "CurveDates");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlDiscountCurve(
          mObjectID,
          mCurveDates,
          mCurveDiscounts,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::DiscountCurve(
          valueObject,
          CurveDatesLib,
          mCurveDiscounts,
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

void DiscountCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DiscountCurve) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("CurveDates is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("CurveDiscounts is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>CurveDatesCpp;

  Local<Array> CurveDatesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < CurveDatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(CurveDatesArray, i).ToLocalChecked()).FromJust()));
    CurveDatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>CurveDiscountsCpp;

  Local<Array> CurveDiscountsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < CurveDiscountsArray->Length(); i++){
    CurveDiscountsCpp.push_back(Nan::To<double>(Nan::Get(CurveDiscountsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[3]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DiscountCurveWorker(
    callback
    ,ObjectIDCpp
    ,CurveDatesCpp
    ,CurveDiscountsCpp
    ,DayCounterCpp
  ));

}

//DiscountCurveWorker::~DiscountCurveWorker(){
//
//}

//void DiscountCurveWorker::Destroy(){
//
//}

void ZeroCurveWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> CurveDatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mCurveDates, "CurveDates");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlZeroCurve(
          mObjectID,
          mCurveDates,
          mCurveYields,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ZeroCurve(
          valueObject,
          CurveDatesLib,
          mCurveYields,
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

void ZeroCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ZeroCurve) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("CurveDates is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("CurveYields is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>CurveDatesCpp;

  Local<Array> CurveDatesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < CurveDatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(CurveDatesArray, i).ToLocalChecked()).FromJust()));
    CurveDatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>CurveYieldsCpp;

  Local<Array> CurveYieldsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < CurveYieldsArray->Length(); i++){
    CurveYieldsCpp.push_back(Nan::To<double>(Nan::Get(CurveYieldsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[3]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ZeroCurveWorker(
    callback
    ,ObjectIDCpp
    ,CurveDatesCpp
    ,CurveYieldsCpp
    ,DayCounterCpp
  ));

}

//ZeroCurveWorker::~ZeroCurveWorker(){
//
//}

//void ZeroCurveWorker::Destroy(){
//
//}

void ForwardCurveWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> CurveDatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mCurveDates, "CurveDates");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlForwardCurve(
          mObjectID,
          mCurveDates,
          mForwardYields,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ForwardCurve(
          valueObject,
          CurveDatesLib,
          mForwardYields,
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

void ForwardCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ForwardCurve) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("CurveDates is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("ForwardYields is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>CurveDatesCpp;

  Local<Array> CurveDatesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < CurveDatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(CurveDatesArray, i).ToLocalChecked()).FromJust()));
    CurveDatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>ForwardYieldsCpp;

  Local<Array> ForwardYieldsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < ForwardYieldsArray->Length(); i++){
    ForwardYieldsCpp.push_back(Nan::To<double>(Nan::Get(ForwardYieldsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[3]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ForwardCurveWorker(
    callback
    ,ObjectIDCpp
    ,CurveDatesCpp
    ,ForwardYieldsCpp
    ,DayCounterCpp
  ));

}

//ForwardCurveWorker::~ForwardCurveWorker(){
//
//}

//void ForwardCurveWorker::Destroy(){
//
//}

void FlatForwardWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NDaysLib;
  QuantLibAddin::cppToLibrary(mNDays, NDaysLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> RateLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mRate, "Rate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFlatForward(
          mObjectID,
          mNDays,
          mCalendar,
          mRate,
          mDayCounter,
          mCompounding,
          mFrequency,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FlatForward(
          valueObject,
          NDaysLib,
          CalendarEnum,
          RateLibObj,
          DayCounterEnum,
          CompoundingEnum,
          FrequencyEnum,
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

void FlatForwardWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FlatForward) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("NDays is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long NDaysCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[2]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  ObjectHandler::property_t RateCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[3]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[4]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[5]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[6]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FlatForwardWorker(
    callback
    ,ObjectIDCpp
    ,NDaysCpp
    ,CalendarCpp
    ,RateCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
  ));

}

//FlatForwardWorker::~FlatForwardWorker(){
//
//}

//void FlatForwardWorker::Destroy(){
//
//}

void ForwardSpreadedTermStructureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(BaseYieldCurveCoerce, mBaseYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> BaseYieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              BaseYieldCurveCoerce);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> SpreadLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mSpread, "Spread");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlForwardSpreadedTermStructure(
          mObjectID,
          mBaseYieldCurve,
          mSpread,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ForwardSpreadedTermStructure(
          valueObject,
          BaseYieldCurveLibObj,
          SpreadLibObj,
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

void ForwardSpreadedTermStructureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ForwardSpreadedTermStructure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t BaseYieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t SpreadCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ForwardSpreadedTermStructureWorker(
    callback
    ,ObjectIDCpp
    ,BaseYieldCurveCpp
    ,SpreadCpp
  ));

}

//ForwardSpreadedTermStructureWorker::~ForwardSpreadedTermStructureWorker(){
//
//}

//void ForwardSpreadedTermStructureWorker::Destroy(){
//
//}

void ImpliedTermStructureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(BaseYieldCurveCoerce, mBaseYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> BaseYieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              BaseYieldCurveCoerce);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ReferenceDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mReferenceDate, "ReferenceDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlImpliedTermStructure(
          mObjectID,
          mBaseYieldCurve,
          mReferenceDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ImpliedTermStructure(
          valueObject,
          BaseYieldCurveLibObj,
          ReferenceDateLib,
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

void ImpliedTermStructureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ImpliedTermStructure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t BaseYieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t ReferenceDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ImpliedTermStructureWorker(
    callback
    ,ObjectIDCpp
    ,BaseYieldCurveCpp
    ,ReferenceDateCpp
  ));

}

//ImpliedTermStructureWorker::~ImpliedTermStructureWorker(){
//
//}

//void ImpliedTermStructureWorker::Destroy(){
//
//}

void InterpolatedYieldCurveWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDates, "Dates");


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> DataLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mData);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > JumpsLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mJumps, "Jumps");


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> JumpDatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mJumpDates, "JumpDates");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NRateHelperLib;
  QuantLibAddin::cppToLibrary(mNRateHelper, NRateHelperLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlInterpolatedYieldCurve(
          mObjectID,
          mDates,
          mData,
          mCalendar,
          mDayCounter,
          mJumps,
          mJumpDates,
          mTraitsID,
          mInterpolatorID,
          mMixedInterpolationBehavior,
          mNRateHelper,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::InterpolatedYieldCurve(
          valueObject,
          DatesLib,
          mData,
          CalendarEnum,
          DayCounterEnum,
          JumpsLibObj,
          JumpDatesLib,
          mTraitsID,
          mInterpolatorID,
          mMixedInterpolationBehavior,
          NRateHelperLib,
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

void InterpolatedYieldCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterpolatedYieldCurve) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Dates is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Data is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("Jumps is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("JumpDates is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("TraitsID is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("InterpolatorID is required.");
  }
  if (info.Length() == 9 || !info[9]->IsString()) {
      return Nan::ThrowError("MixedInterpolationBehavior is required.");
  }
  if (info.Length() == 10 || !info[10]->IsNumber()) {
      return Nan::ThrowError("NRateHelper is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DatesCpp;

  Local<Array> DatesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < DatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DatesArray, i).ToLocalChecked()).FromJust()));
    DatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>DataCpp;

  Local<Array> DataArray = info[2].As<Array>();
  for (unsigned int i = 0; i < DataArray->Length(); i++){
    DataCpp.push_back(Nan::To<double>(Nan::Get(DataArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[3]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[4]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>JumpsCpp;

  Local<Array> JumpsArray = info[5].As<Array>();
  for (unsigned int i = 0; i < JumpsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(JumpsArray, i).ToLocalChecked()).FromJust()));
    JumpsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>JumpDatesCpp;

  Local<Array> JumpDatesArray = info[6].As<Array>();
  for (unsigned int i = 0; i < JumpDatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(JumpDatesArray, i).ToLocalChecked()).FromJust()));
    JumpDatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strTraitsID(info[7]->ToString());
  string TraitsIDCpp(strdup(*strTraitsID));

  // convert js argument to c++ type
  String::Utf8Value strInterpolatorID(info[8]->ToString());
  string InterpolatorIDCpp(strdup(*strInterpolatorID));

  // convert js argument to c++ type
  String::Utf8Value strMixedInterpolationBehavior(info[9]->ToString());
  string MixedInterpolationBehaviorCpp(strdup(*strMixedInterpolationBehavior));

  // convert js argument to c++ type
  long NRateHelperCpp = Nan::To<int32_t>(info[10]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[11].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterpolatedYieldCurveWorker(
    callback
    ,ObjectIDCpp
    ,DatesCpp
    ,DataCpp
    ,CalendarCpp
    ,DayCounterCpp
    ,JumpsCpp
    ,JumpDatesCpp
    ,TraitsIDCpp
    ,InterpolatorIDCpp
    ,MixedInterpolationBehaviorCpp
    ,NRateHelperCpp
  ));

}

//InterpolatedYieldCurveWorker::~InterpolatedYieldCurveWorker(){
//
//}

//void InterpolatedYieldCurveWorker::Destroy(){
//
//}

void TermStructureDayCounterWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::TermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::TermStructure,
          QuantLib::TermStructure>()(
              ObjectIDTemp);

     
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

void TermStructureDayCounterWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TermStructureDayCounter) {

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
  Nan::AsyncQueueWorker(new TermStructureDayCounterWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TermStructureDayCounterWorker::~TermStructureDayCounterWorker(){
//
//}

//void TermStructureDayCounterWorker::Destroy(){
//
//}

void TermStructureMaxDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::TermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::TermStructure,
          QuantLib::TermStructure>()(
              ObjectIDTemp);

     
  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->maxDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TermStructureMaxDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TermStructureMaxDate) {

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
  Nan::AsyncQueueWorker(new TermStructureMaxDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TermStructureMaxDateWorker::~TermStructureMaxDateWorker(){
//
//}

//void TermStructureMaxDateWorker::Destroy(){
//
//}

void TermStructureReferenceDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::TermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::TermStructure,
          QuantLib::TermStructure>()(
              ObjectIDTemp);

     
  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->referenceDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TermStructureReferenceDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TermStructureReferenceDate) {

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
  Nan::AsyncQueueWorker(new TermStructureReferenceDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TermStructureReferenceDateWorker::~TermStructureReferenceDateWorker(){
//
//}

//void TermStructureReferenceDateWorker::Destroy(){
//
//}

void TermStructureTimeFromReferenceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::TermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::TermStructure,
          QuantLib::TermStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDate, "Date");

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlTermStructureTimeFromReferenceBind bindObject =
      boost::bind((QuantLibAddin::qlTermStructureTimeFromReferenceSignature)
              &QuantLib::TermStructure::timeFromReference,
              ObjectIDLibObjPtr
          ,_1
          );

  ObjectHandler::loop
      <QuantLibAddin::qlTermStructureTimeFromReferenceBind,
                      QuantLib::Date,
                      QuantLib::Time>
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

void TermStructureTimeFromReferenceWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::TermStructureTimeFromReference) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Date is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DateCpp;

  Local<Array> DateArray = info[1].As<Array>();
  for (unsigned int i = 0; i < DateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DateArray, i).ToLocalChecked()).FromJust()));
    DateCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TermStructureTimeFromReferenceWorker(
    callback
    ,ObjectIDCpp
    ,DateCpp
  ));

}

//TermStructureTimeFromReferenceWorker::~TermStructureTimeFromReferenceWorker(){
//
//}

//void TermStructureTimeFromReferenceWorker::Destroy(){
//
//}

void TermStructureCalendarWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::TermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::TermStructure,
          QuantLib::TermStructure>()(
              ObjectIDTemp);

     
  // invoke the member function
  QuantLib::Calendar returnValue = ObjectIDLibObjPtr->calendar(
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

void TermStructureCalendarWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TermStructureCalendar) {

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
  Nan::AsyncQueueWorker(new TermStructureCalendarWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TermStructureCalendarWorker::~TermStructureCalendarWorker(){
//
//}

//void TermStructureCalendarWorker::Destroy(){
//
//}

void TermStructureSettlementDaysWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::TermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::TermStructure,
          QuantLib::TermStructure>()(
              ObjectIDTemp);

     
  // invoke the member function
  QuantLib::Natural returnValue = ObjectIDLibObjPtr->settlementDays(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TermStructureSettlementDaysWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TermStructureSettlementDays) {

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
  Nan::AsyncQueueWorker(new TermStructureSettlementDaysWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TermStructureSettlementDaysWorker::~TermStructureSettlementDaysWorker(){
//
//}

//void TermStructureSettlementDaysWorker::Destroy(){
//
//}

void YieldTSDiscountWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::YieldTermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DfDatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDfDates, "DfDates");

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlYieldTSDiscountBind bindObject =
      boost::bind((QuantLibAddin::qlYieldTSDiscountSignature)
              &QuantLib::YieldTermStructure::discount,
              ObjectIDLibObjPtr
          ,_1
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlYieldTSDiscountBind,
                      QuantLib::Date,
                      QuantLib::DiscountFactor>
          (bindObject,
            DfDatesLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void YieldTSDiscountWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::YieldTSDiscount) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("DfDates is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DfDatesCpp;

  Local<Array> DfDatesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < DfDatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DfDatesArray, i).ToLocalChecked()).FromJust()));
    DfDatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new YieldTSDiscountWorker(
    callback
    ,ObjectIDCpp
    ,DfDatesCpp
    ,AllowExtrapolationCpp
  ));

}

//YieldTSDiscountWorker::~YieldTSDiscountWorker(){
//
//}

//void YieldTSDiscountWorker::Destroy(){
//
//}

void YieldTSForwardRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::YieldTermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date D1Lib = ObjectHandler::convert2<QuantLib::Date>(
      mD1, "D1");


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> D2Lib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mD2, "D2");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter ResultDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mResultDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);

       std::vector<QuantLib::InterestRate> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlYieldTSForwardRateBind bindObject =
      boost::bind((QuantLibAddin::qlYieldTSForwardRateSignature)
              &QuantLib::YieldTermStructure::forwardRate,
              ObjectIDLibObjPtr
          ,D1Lib
          ,_1
          ,ResultDayCounterEnum
          ,CompoundingEnum
          ,FrequencyEnum
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlYieldTSForwardRateBind,
                      QuantLib::Date,
                      QuantLib::InterestRate>
          (bindObject,
            D2Lib,
          returnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void YieldTSForwardRateWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::YieldTSForwardRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("D2 is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ResultDayCounter is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  if (info.Length() == 6 || !info[6]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t D1Cpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>D2Cpp;

  Local<Array> D2Array = info[2].As<Array>();
  for (unsigned int i = 0; i < D2Array->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(D2Array, i).ToLocalChecked()).FromJust()));
    D2Cpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strResultDayCounter(info[3]->ToString());
  string ResultDayCounterCpp(strdup(*strResultDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[4]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[5]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new YieldTSForwardRateWorker(
    callback
    ,ObjectIDCpp
    ,D1Cpp
    ,D2Cpp
    ,ResultDayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,AllowExtrapolationCpp
  ));

}

//YieldTSForwardRateWorker::~YieldTSForwardRateWorker(){
//
//}

//void YieldTSForwardRateWorker::Destroy(){
//
//}

void YieldTSForwardRate2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::YieldTermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDate, "Date");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period PeriodLib;
  QuantLibAddin::cppToLibrary(mPeriod, PeriodLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter ResultDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mResultDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);

       std::vector<QuantLib::InterestRate> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlYieldTSForwardRate2Bind bindObject =
      boost::bind((QuantLibAddin::qlYieldTSForwardRate2Signature)
              &QuantLib::YieldTermStructure::forwardRate,
              ObjectIDLibObjPtr
          ,_1
          ,PeriodLib
          ,ResultDayCounterEnum
          ,CompoundingEnum
          ,FrequencyEnum
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlYieldTSForwardRate2Bind,
                      QuantLib::Date,
                      QuantLib::InterestRate>
          (bindObject,
            DateLib,
          returnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void YieldTSForwardRate2Worker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::YieldTSForwardRate2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Date is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Period is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ResultDayCounter is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  if (info.Length() == 6 || !info[6]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DateCpp;

  Local<Array> DateArray = info[1].As<Array>();
  for (unsigned int i = 0; i < DateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DateArray, i).ToLocalChecked()).FromJust()));
    DateCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strPeriod(info[2]->ToString());
  string PeriodCpp(strdup(*strPeriod));

  // convert js argument to c++ type
  String::Utf8Value strResultDayCounter(info[3]->ToString());
  string ResultDayCounterCpp(strdup(*strResultDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[4]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[5]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new YieldTSForwardRate2Worker(
    callback
    ,ObjectIDCpp
    ,DateCpp
    ,PeriodCpp
    ,ResultDayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,AllowExtrapolationCpp
  ));

}

//YieldTSForwardRate2Worker::~YieldTSForwardRate2Worker(){
//
//}

//void YieldTSForwardRate2Worker::Destroy(){
//
//}

void YieldTSZeroRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::YieldTermStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDates, "Dates");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter ResultDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mResultDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);

       std::vector<QuantLib::InterestRate> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlYieldTSZeroRateBind bindObject =
      boost::bind((QuantLibAddin::qlYieldTSZeroRateSignature)
              &QuantLib::YieldTermStructure::zeroRate,
              ObjectIDLibObjPtr
          ,_1
          ,ResultDayCounterEnum
          ,CompoundingEnum
          ,FrequencyEnum
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlYieldTSZeroRateBind,
                      QuantLib::Date,
                      QuantLib::InterestRate>
          (bindObject,
            DatesLib,
          returnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void YieldTSZeroRateWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::YieldTSZeroRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Dates is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("ResultDayCounter is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DatesCpp;

  Local<Array> DatesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < DatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DatesArray, i).ToLocalChecked()).FromJust()));
    DatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strResultDayCounter(info[2]->ToString());
  string ResultDayCounterCpp(strdup(*strResultDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[3]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[4]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new YieldTSZeroRateWorker(
    callback
    ,ObjectIDCpp
    ,DatesCpp
    ,ResultDayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,AllowExtrapolationCpp
  ));

}

//YieldTSZeroRateWorker::~YieldTSZeroRateWorker(){
//
//}

//void YieldTSZeroRateWorker::Destroy(){
//
//}

void InterpolatedYieldCurveTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::InterpolatedYieldCurve)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->times(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolatedYieldCurveTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::InterpolatedYieldCurveTimes) {

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
  Nan::AsyncQueueWorker(new InterpolatedYieldCurveTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterpolatedYieldCurveTimesWorker::~InterpolatedYieldCurveTimesWorker(){
//
//}

//void InterpolatedYieldCurveTimesWorker::Destroy(){
//
//}

void InterpolatedYieldCurveDatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::InterpolatedYieldCurve)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Date> returnValue = ObjectIDObjPtr->dates(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolatedYieldCurveDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::InterpolatedYieldCurveDates) {

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
  Nan::AsyncQueueWorker(new InterpolatedYieldCurveDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterpolatedYieldCurveDatesWorker::~InterpolatedYieldCurveDatesWorker(){
//
//}

//void InterpolatedYieldCurveDatesWorker::Destroy(){
//
//}

void InterpolatedYieldCurveDataWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::InterpolatedYieldCurve)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDObjPtr->data(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolatedYieldCurveDataWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::InterpolatedYieldCurveData) {

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
  Nan::AsyncQueueWorker(new InterpolatedYieldCurveDataWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterpolatedYieldCurveDataWorker::~InterpolatedYieldCurveDataWorker(){
//
//}

//void InterpolatedYieldCurveDataWorker::Destroy(){
//
//}

void InterpolatedYieldCurveJumpTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::InterpolatedYieldCurve)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->jumpTimes(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolatedYieldCurveJumpTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::InterpolatedYieldCurveJumpTimes) {

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
  Nan::AsyncQueueWorker(new InterpolatedYieldCurveJumpTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterpolatedYieldCurveJumpTimesWorker::~InterpolatedYieldCurveJumpTimesWorker(){
//
//}

//void InterpolatedYieldCurveJumpTimesWorker::Destroy(){
//
//}

void InterpolatedYieldCurveJumpDatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::InterpolatedYieldCurve)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Date> returnValue = ObjectIDObjPtr->jumpDates(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolatedYieldCurveJumpDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::InterpolatedYieldCurveJumpDates) {

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
  Nan::AsyncQueueWorker(new InterpolatedYieldCurveJumpDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterpolatedYieldCurveJumpDatesWorker::~InterpolatedYieldCurveJumpDatesWorker(){
//
//}

//void InterpolatedYieldCurveJumpDatesWorker::Destroy(){
//
//}
 