// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "piecewiseyieldcurve.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/piecewiseyieldcurve.hpp>
#include <qlo/ratehelpers.hpp>
#include <qlo/handleimpl.hpp>
#include <ql/interestrate.hpp>
#include <qlo/conversions/coercetermstructure.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void PiecewiseYieldCurveWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural NDaysLib = ObjectHandler::convert2<long>(
      mNDays, "NDays", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::RateHelper> > RateHelpersLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::RateHelper, QuantLib::RateHelper>(mRateHelpers);


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
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlPiecewiseYieldCurve(
          mObjectID,
          mNDays,
          mCalendar,
          mRateHelpers,
          mDayCounter,
          mJumps,
          mJumpDates,
          mAccuracy,
          mTraitsID,
          mInterpolatorID,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::PiecewiseYieldCurve(
          valueObject,
          NDaysLib,
          CalendarEnum,
          RateHelpersLibObjPtr,
          DayCounterEnum,
          JumpsLibObj,
          JumpDatesLib,
          mAccuracy,
          mTraitsID,
          mInterpolatorID,
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

void PiecewiseYieldCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseYieldCurve) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("RateHelpers is required.");
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
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("TraitsID is required.");
  }
  if (info.Length() == 9 || !info[9]->IsString()) {
      return Nan::ThrowError("InterpolatorID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t NDaysCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[2]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  std::vector<string>RateHelpersCpp;

  Local<Array> RateHelpersArray = info[3].As<Array>();
  for (unsigned int i = 0; i < RateHelpersArray->Length(); i++){
    String::Utf8Value strRateHelpers(Nan::Get(RateHelpersArray, i).ToLocalChecked()->ToString());
    RateHelpersCpp.push_back(strdup(*strRateHelpers));
  }

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
  double AccuracyCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strTraitsID(info[8]->ToString());
  string TraitsIDCpp(strdup(*strTraitsID));

  // convert js argument to c++ type
  String::Utf8Value strInterpolatorID(info[9]->ToString());
  string InterpolatorIDCpp(strdup(*strInterpolatorID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseYieldCurveWorker(
    callback
    ,ObjectIDCpp
    ,NDaysCpp
    ,CalendarCpp
    ,RateHelpersCpp
    ,DayCounterCpp
    ,JumpsCpp
    ,JumpDatesCpp
    ,AccuracyCpp
    ,TraitsIDCpp
    ,InterpolatorIDCpp
  ));

}

//PiecewiseYieldCurveWorker::~PiecewiseYieldCurveWorker(){
//
//}

//PiecewiseYieldCurveWorker::Destroy(){
//
//}

void PiecewiseYieldCurveTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::PiecewiseYieldCurve)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->times(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseYieldCurveTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::PiecewiseYieldCurveTimes) {

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
  Nan::AsyncQueueWorker(new PiecewiseYieldCurveTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseYieldCurveTimesWorker::~PiecewiseYieldCurveTimesWorker(){
//
//}

//PiecewiseYieldCurveTimesWorker::Destroy(){
//
//}

void PiecewiseYieldCurveDatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::PiecewiseYieldCurve)

     
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

void PiecewiseYieldCurveDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::PiecewiseYieldCurveDates) {

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
  Nan::AsyncQueueWorker(new PiecewiseYieldCurveDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseYieldCurveDatesWorker::~PiecewiseYieldCurveDatesWorker(){
//
//}

//PiecewiseYieldCurveDatesWorker::Destroy(){
//
//}

void PiecewiseYieldCurveDataWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::PiecewiseYieldCurve)

     
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

void PiecewiseYieldCurveDataWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::PiecewiseYieldCurveData) {

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
  Nan::AsyncQueueWorker(new PiecewiseYieldCurveDataWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseYieldCurveDataWorker::~PiecewiseYieldCurveDataWorker(){
//
//}

//PiecewiseYieldCurveDataWorker::Destroy(){
//
//}

void PiecewiseYieldCurveJumpTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::PiecewiseYieldCurve)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->jumpTimes(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseYieldCurveJumpTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::PiecewiseYieldCurveJumpTimes) {

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
  Nan::AsyncQueueWorker(new PiecewiseYieldCurveJumpTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseYieldCurveJumpTimesWorker::~PiecewiseYieldCurveJumpTimesWorker(){
//
//}

//PiecewiseYieldCurveJumpTimesWorker::Destroy(){
//
//}

void PiecewiseYieldCurveJumpDatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::PiecewiseYieldCurve)

     
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

void PiecewiseYieldCurveJumpDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::PiecewiseYieldCurveJumpDates) {

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
  Nan::AsyncQueueWorker(new PiecewiseYieldCurveJumpDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseYieldCurveJumpDatesWorker::~PiecewiseYieldCurveJumpDatesWorker(){
//
//}

//PiecewiseYieldCurveJumpDatesWorker::Destroy(){
//
//}
 