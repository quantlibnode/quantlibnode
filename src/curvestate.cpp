/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "curvestate.hpp"

#include <qlo/qladdindefines.hpp>
#include <ql/models/marketmodels/swapforwardmappings.hpp>
#include <ql/models/marketmodels/curvestates/cmswapcurvestate.hpp>
#include <ql/models/marketmodels/curvestates/coterminalswapcurvestate.hpp>
#include <ql/models/marketmodels/curvestates/lmmcurvestate.hpp>
#include <qlo/curvestate.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void CMSwapCurveStateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SpanningForwardsLib;
  QuantLibAddin::cppToLibrary(mSpanningForwards, SpanningForwardsLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCMSwapCurveState(
          mObjectID,
          mRateTimes,
          mSpanningForwards,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CMSwapCurveState(
          valueObject,
          mRateTimes,
          SpanningForwardsLib,
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

void CMSwapCurveStateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CMSwapCurveState) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("SpanningForwards is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>RateTimesCpp;

  Local<Array> RateTimesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < RateTimesArray->Length(); i++){
    RateTimesCpp.push_back(Nan::To<double>(Nan::Get(RateTimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long SpanningForwardsCpp = Nan::To<int32_t>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CMSwapCurveStateWorker(
    callback
    ,ObjectIDCpp
    ,RateTimesCpp
    ,SpanningForwardsCpp
  ));

}

//CMSwapCurveStateWorker::~CMSwapCurveStateWorker(){
//
//}

//void CMSwapCurveStateWorker::Destroy(){
//
//}

void CoterminalSwapCurveStateWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCoterminalSwapCurveState(
          mObjectID,
          mRateTimes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CoterminalSwapCurveState(
          valueObject,
          mRateTimes,
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

void CoterminalSwapCurveStateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CoterminalSwapCurveState) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>RateTimesCpp;

  Local<Array> RateTimesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < RateTimesArray->Length(); i++){
    RateTimesCpp.push_back(Nan::To<double>(Nan::Get(RateTimesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CoterminalSwapCurveStateWorker(
    callback
    ,ObjectIDCpp
    ,RateTimesCpp
  ));

}

//CoterminalSwapCurveStateWorker::~CoterminalSwapCurveStateWorker(){
//
//}

//void CoterminalSwapCurveStateWorker::Destroy(){
//
//}

void LMMCurveStateWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlLMMCurveState(
          mObjectID,
          mRateTimes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::LMMCurveState(
          valueObject,
          mRateTimes,
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

void LMMCurveStateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LMMCurveState) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>RateTimesCpp;

  Local<Array> RateTimesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < RateTimesArray->Length(); i++){
    RateTimesCpp.push_back(Nan::To<double>(Nan::Get(RateTimesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMCurveStateWorker(
    callback
    ,ObjectIDCpp
    ,RateTimesCpp
  ));

}

//LMMCurveStateWorker::~LMMCurveStateWorker(){
//
//}

//void LMMCurveStateWorker::Destroy(){
//
//}

void CurveStateRateTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CurveState, QuantLib::CurveState)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->rateTimes(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CurveStateRateTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CurveStateRateTimes) {

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
  Nan::AsyncQueueWorker(new CurveStateRateTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CurveStateRateTimesWorker::~CurveStateRateTimesWorker(){
//
//}

//void CurveStateRateTimesWorker::Destroy(){
//
//}

void CurveStateRateTausWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CurveState, QuantLib::CurveState)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->rateTaus(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CurveStateRateTausWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CurveStateRateTaus) {

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
  Nan::AsyncQueueWorker(new CurveStateRateTausWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CurveStateRateTausWorker::~CurveStateRateTausWorker(){
//
//}

//void CurveStateRateTausWorker::Destroy(){
//
//}

void CurveStateForwardRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CurveState, QuantLib::CurveState)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->forwardRates(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CurveStateForwardRatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CurveStateForwardRates) {

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
  Nan::AsyncQueueWorker(new CurveStateForwardRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CurveStateForwardRatesWorker::~CurveStateForwardRatesWorker(){
//
//}

//void CurveStateForwardRatesWorker::Destroy(){
//
//}

void CurveStateCoterminalSwapRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CurveState, QuantLib::CurveState)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->coterminalSwapRates(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CurveStateCoterminalSwapRatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CurveStateCoterminalSwapRates) {

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
  Nan::AsyncQueueWorker(new CurveStateCoterminalSwapRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CurveStateCoterminalSwapRatesWorker::~CurveStateCoterminalSwapRatesWorker(){
//
//}

//void CurveStateCoterminalSwapRatesWorker::Destroy(){
//
//}

void CurveStateCMSwapRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CurveState, QuantLib::CurveState)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SpanningForwardsLib;
  QuantLibAddin::cppToLibrary(mSpanningForwards, SpanningForwardsLib);

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->cmSwapRates(
        SpanningForwardsLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CurveStateCMSwapRatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CurveStateCMSwapRates) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("SpanningForwards is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long SpanningForwardsCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CurveStateCMSwapRatesWorker(
    callback
    ,ObjectIDCpp
    ,SpanningForwardsCpp
  ));

}

//CurveStateCMSwapRatesWorker::~CurveStateCMSwapRatesWorker(){
//
//}

//void CurveStateCMSwapRatesWorker::Destroy(){
//
//}

void CMSwapCurveStateSetOnCMSwapRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CMSwapCurveState, QuantLib::CMSwapCurveState)

     
  // invoke the member function
  ObjectIDLibObjPtr->setOnCMSwapRates(
        mCMSwapRates
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CMSwapCurveStateSetOnCMSwapRatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CMSwapCurveStateSetOnCMSwapRates) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("CMSwapRates is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>CMSwapRatesCpp;

  Local<Array> CMSwapRatesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < CMSwapRatesArray->Length(); i++){
    CMSwapRatesCpp.push_back(Nan::To<double>(Nan::Get(CMSwapRatesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CMSwapCurveStateSetOnCMSwapRatesWorker(
    callback
    ,ObjectIDCpp
    ,CMSwapRatesCpp
  ));

}

//CMSwapCurveStateSetOnCMSwapRatesWorker::~CMSwapCurveStateSetOnCMSwapRatesWorker(){
//
//}

//void CMSwapCurveStateSetOnCMSwapRatesWorker::Destroy(){
//
//}

void CoterminalSwapCurveStateSetOnCoterminalSwapRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CoterminalSwapCurveState, QuantLib::CoterminalSwapCurveState)

     
  // invoke the member function
  ObjectIDLibObjPtr->setOnCoterminalSwapRates(
        mCoterminalSwaps
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CoterminalSwapCurveStateSetOnCoterminalSwapRatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CoterminalSwapCurveStateSetOnCoterminalSwapRates) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("CoterminalSwaps is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>CoterminalSwapsCpp;

  Local<Array> CoterminalSwapsArray = info[1].As<Array>();
  for (unsigned int i = 0; i < CoterminalSwapsArray->Length(); i++){
    CoterminalSwapsCpp.push_back(Nan::To<double>(Nan::Get(CoterminalSwapsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CoterminalSwapCurveStateSetOnCoterminalSwapRatesWorker(
    callback
    ,ObjectIDCpp
    ,CoterminalSwapsCpp
  ));

}

//CoterminalSwapCurveStateSetOnCoterminalSwapRatesWorker::~CoterminalSwapCurveStateSetOnCoterminalSwapRatesWorker(){
//
//}

//void CoterminalSwapCurveStateSetOnCoterminalSwapRatesWorker::Destroy(){
//
//}

void LMMCurveStateSetOnForwardRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::LMMCurveState, QuantLib::LMMCurveState)

     
  // invoke the member function
  ObjectIDLibObjPtr->setOnForwardRates(
        mRates
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LMMCurveStateSetOnForwardRatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LMMCurveStateSetOnForwardRates) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Rates is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>RatesCpp;

  Local<Array> RatesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < RatesArray->Length(); i++){
    RatesCpp.push_back(Nan::To<double>(Nan::Get(RatesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMCurveStateSetOnForwardRatesWorker(
    callback
    ,ObjectIDCpp
    ,RatesCpp
  ));

}

//LMMCurveStateSetOnForwardRatesWorker::~LMMCurveStateSetOnForwardRatesWorker(){
//
//}

//void LMMCurveStateSetOnForwardRatesWorker::Destroy(){
//
//}

void LMMCurveStateSetOnDiscountRatiosWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::LMMCurveState, QuantLib::LMMCurveState)

     
  // invoke the member function
  ObjectIDLibObjPtr->setOnDiscountRatios(
        mDiscountRatios
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LMMCurveStateSetOnDiscountRatiosWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LMMCurveStateSetOnDiscountRatios) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("DiscountRatios is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>DiscountRatiosCpp;

  Local<Array> DiscountRatiosArray = info[1].As<Array>();
  for (unsigned int i = 0; i < DiscountRatiosArray->Length(); i++){
    DiscountRatiosCpp.push_back(Nan::To<double>(Nan::Get(DiscountRatiosArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMCurveStateSetOnDiscountRatiosWorker(
    callback
    ,ObjectIDCpp
    ,DiscountRatiosCpp
  ));

}

//LMMCurveStateSetOnDiscountRatiosWorker::~LMMCurveStateSetOnDiscountRatiosWorker(){
//
//}

//void LMMCurveStateSetOnDiscountRatiosWorker::Destroy(){
//
//}

void ForwardsFromDiscountRatiosWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size FirstValidIndexLib;
  QuantLibAddin::cppToLibrary(mFirstValidIndex, FirstValidIndexLib);

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlForwardsFromDiscountRatios(
      FirstValidIndexLib
      ,
       mDiscountRatios
      ,
       mTaus
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ForwardsFromDiscountRatiosWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::ForwardsFromDiscountRatios) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("FirstValidIndex is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("DiscountRatios is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Taus is required.");
  }
  // convert js argument to c++ type
  long FirstValidIndexCpp = Nan::To<int32_t>(info[0]).FromJust();

  // convert js argument to c++ type
  std::vector<double>DiscountRatiosCpp;

  Local<Array> DiscountRatiosArray = info[1].As<Array>();
  for (unsigned int i = 0; i < DiscountRatiosArray->Length(); i++){
    DiscountRatiosCpp.push_back(Nan::To<double>(Nan::Get(DiscountRatiosArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TausCpp;

  Local<Array> TausArray = info[2].As<Array>();
  for (unsigned int i = 0; i < TausArray->Length(); i++){
    TausCpp.push_back(Nan::To<double>(Nan::Get(TausArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ForwardsFromDiscountRatiosWorker(
    callback
    ,FirstValidIndexCpp
    ,DiscountRatiosCpp
    ,TausCpp
  ));

}

//ForwardsFromDiscountRatiosWorker::~ForwardsFromDiscountRatiosWorker(){
//
//}

//void ForwardsFromDiscountRatiosWorker::Destroy(){
//
//}

void CoterminalSwapRatesFromDiscountRatiosWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size FirstValidIndexLib;
  QuantLibAddin::cppToLibrary(mFirstValidIndex, FirstValidIndexLib);

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlCoterminalSwapRatesFromDiscountRatios(
      FirstValidIndexLib
      ,
       mDiscountRatios
      ,
       mTaus
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CoterminalSwapRatesFromDiscountRatiosWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CoterminalSwapRatesFromDiscountRatios) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("FirstValidIndex is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("DiscountRatios is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Taus is required.");
  }
  // convert js argument to c++ type
  long FirstValidIndexCpp = Nan::To<int32_t>(info[0]).FromJust();

  // convert js argument to c++ type
  std::vector<double>DiscountRatiosCpp;

  Local<Array> DiscountRatiosArray = info[1].As<Array>();
  for (unsigned int i = 0; i < DiscountRatiosArray->Length(); i++){
    DiscountRatiosCpp.push_back(Nan::To<double>(Nan::Get(DiscountRatiosArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TausCpp;

  Local<Array> TausArray = info[2].As<Array>();
  for (unsigned int i = 0; i < TausArray->Length(); i++){
    TausCpp.push_back(Nan::To<double>(Nan::Get(TausArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CoterminalSwapRatesFromDiscountRatiosWorker(
    callback
    ,FirstValidIndexCpp
    ,DiscountRatiosCpp
    ,TausCpp
  ));

}

//CoterminalSwapRatesFromDiscountRatiosWorker::~CoterminalSwapRatesFromDiscountRatiosWorker(){
//
//}

//void CoterminalSwapRatesFromDiscountRatiosWorker::Destroy(){
//
//}

void CoterminalSwapAnnuitiesFromDiscountRatiosWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size FirstValidIndexLib;
  QuantLibAddin::cppToLibrary(mFirstValidIndex, FirstValidIndexLib);

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlCoterminalSwapAnnuitiesFromDiscountRatios(
      FirstValidIndexLib
      ,
       mDiscountRatios
      ,
       mTaus
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CoterminalSwapAnnuitiesFromDiscountRatiosWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CoterminalSwapAnnuitiesFromDiscountRatios) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("FirstValidIndex is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("DiscountRatios is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Taus is required.");
  }
  // convert js argument to c++ type
  long FirstValidIndexCpp = Nan::To<int32_t>(info[0]).FromJust();

  // convert js argument to c++ type
  std::vector<double>DiscountRatiosCpp;

  Local<Array> DiscountRatiosArray = info[1].As<Array>();
  for (unsigned int i = 0; i < DiscountRatiosArray->Length(); i++){
    DiscountRatiosCpp.push_back(Nan::To<double>(Nan::Get(DiscountRatiosArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TausCpp;

  Local<Array> TausArray = info[2].As<Array>();
  for (unsigned int i = 0; i < TausArray->Length(); i++){
    TausCpp.push_back(Nan::To<double>(Nan::Get(TausArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CoterminalSwapAnnuitiesFromDiscountRatiosWorker(
    callback
    ,FirstValidIndexCpp
    ,DiscountRatiosCpp
    ,TausCpp
  ));

}

//CoterminalSwapAnnuitiesFromDiscountRatiosWorker::~CoterminalSwapAnnuitiesFromDiscountRatiosWorker(){
//
//}

//void CoterminalSwapAnnuitiesFromDiscountRatiosWorker::Destroy(){
//
//}

void ConstantMaturitySwapRatesFromDiscountRatiosWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SpanningForwardsLib;
  QuantLibAddin::cppToLibrary(mSpanningForwards, SpanningForwardsLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size FirstValidIndexLib;
  QuantLibAddin::cppToLibrary(mFirstValidIndex, FirstValidIndexLib);

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlConstantMaturitySwapRatesFromDiscountRatios(
      SpanningForwardsLib
      ,
       FirstValidIndexLib
      ,
       mDiscountRatios
      ,
       mTaus
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ConstantMaturitySwapRatesFromDiscountRatiosWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::ConstantMaturitySwapRatesFromDiscountRatios) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("SpanningForwards is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("FirstValidIndex is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("DiscountRatios is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Taus is required.");
  }
  // convert js argument to c++ type
  long SpanningForwardsCpp = Nan::To<int32_t>(info[0]).FromJust();

  // convert js argument to c++ type
  long FirstValidIndexCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  std::vector<double>DiscountRatiosCpp;

  Local<Array> DiscountRatiosArray = info[2].As<Array>();
  for (unsigned int i = 0; i < DiscountRatiosArray->Length(); i++){
    DiscountRatiosCpp.push_back(Nan::To<double>(Nan::Get(DiscountRatiosArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TausCpp;

  Local<Array> TausArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TausArray->Length(); i++){
    TausCpp.push_back(Nan::To<double>(Nan::Get(TausArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ConstantMaturitySwapRatesFromDiscountRatiosWorker(
    callback
    ,SpanningForwardsCpp
    ,FirstValidIndexCpp
    ,DiscountRatiosCpp
    ,TausCpp
  ));

}

//ConstantMaturitySwapRatesFromDiscountRatiosWorker::~ConstantMaturitySwapRatesFromDiscountRatiosWorker(){
//
//}

//void ConstantMaturitySwapRatesFromDiscountRatiosWorker::Destroy(){
//
//}

void ConstantMaturitySwapAnnuitiesFromDiscountRatiosWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SpanningForwardsLib;
  QuantLibAddin::cppToLibrary(mSpanningForwards, SpanningForwardsLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size FirstValidIndexLib;
  QuantLibAddin::cppToLibrary(mFirstValidIndex, FirstValidIndexLib);

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlConstantMaturitySwapAnnuitiesFromDiscountRatios(
      SpanningForwardsLib
      ,
       FirstValidIndexLib
      ,
       mDiscountRatios
      ,
       mTaus
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ConstantMaturitySwapAnnuitiesFromDiscountRatiosWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::ConstantMaturitySwapAnnuitiesFromDiscountRatios) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("SpanningForwards is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("FirstValidIndex is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("DiscountRatios is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Taus is required.");
  }
  // convert js argument to c++ type
  long SpanningForwardsCpp = Nan::To<int32_t>(info[0]).FromJust();

  // convert js argument to c++ type
  long FirstValidIndexCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  std::vector<double>DiscountRatiosCpp;

  Local<Array> DiscountRatiosArray = info[2].As<Array>();
  for (unsigned int i = 0; i < DiscountRatiosArray->Length(); i++){
    DiscountRatiosCpp.push_back(Nan::To<double>(Nan::Get(DiscountRatiosArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TausCpp;

  Local<Array> TausArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TausArray->Length(); i++){
    TausCpp.push_back(Nan::To<double>(Nan::Get(TausArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ConstantMaturitySwapAnnuitiesFromDiscountRatiosWorker(
    callback
    ,SpanningForwardsCpp
    ,FirstValidIndexCpp
    ,DiscountRatiosCpp
    ,TausCpp
  ));

}

//ConstantMaturitySwapAnnuitiesFromDiscountRatiosWorker::~ConstantMaturitySwapAnnuitiesFromDiscountRatiosWorker(){
//
//}

//void ConstantMaturitySwapAnnuitiesFromDiscountRatiosWorker::Destroy(){
//
//}
 