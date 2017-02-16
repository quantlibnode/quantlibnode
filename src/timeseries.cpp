/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "timeseries.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/timeseries.hpp>
#include <qlo/index.hpp>
#include <qlo/loop/loop_timeseries.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void TimeSeriesWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDates, "Dates");


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> ValuesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mValues);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlTimeSeries(
          mObjectID,
          mDates,
          mValues,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::TimeSeriesDef(
          valueObject,
          DatesLib,
          mValues,
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

void TimeSeriesWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TimeSeries) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Dates is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Values is required.");
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
  std::vector<double>ValuesCpp;

  Local<Array> ValuesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < ValuesArray->Length(); i++){
    ValuesCpp.push_back(Nan::To<double>(Nan::Get(ValuesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TimeSeriesWorker(
    callback
    ,ObjectIDCpp
    ,DatesCpp
    ,ValuesCpp
  ));

}

//TimeSeriesWorker::~TimeSeriesWorker(){
//
//}

//void TimeSeriesWorker::Destroy(){
//
//}

void TimeSeriesFromIndexWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(IndexLibObjPtr, mIndex,
      QuantLibAddin::Index, QuantLib::Index)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlTimeSeriesFromIndex(
          mObjectID,
          mIndex,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::TimeSeriesDef(
          valueObject,
          IndexLibObjPtr,
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

void TimeSeriesFromIndexWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TimeSeriesFromIndex) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Index is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strIndex(info[1]->ToString());
  string IndexCpp(strdup(*strIndex));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TimeSeriesFromIndexWorker(
    callback
    ,ObjectIDCpp
    ,IndexCpp
  ));

}

//TimeSeriesFromIndexWorker::~TimeSeriesFromIndexWorker(){
//
//}

//void TimeSeriesFromIndexWorker::Destroy(){
//
//}

void TimeSeriesFirstDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::TimeSeriesDef, QuantLib::TimeSeriesDef)

     
  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->firstDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TimeSeriesFirstDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TimeSeriesFirstDate) {

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
  Nan::AsyncQueueWorker(new TimeSeriesFirstDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TimeSeriesFirstDateWorker::~TimeSeriesFirstDateWorker(){
//
//}

//void TimeSeriesFirstDateWorker::Destroy(){
//
//}

void TimeSeriesLastDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::TimeSeriesDef, QuantLib::TimeSeriesDef)

     
  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->lastDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TimeSeriesLastDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TimeSeriesLastDate) {

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
  Nan::AsyncQueueWorker(new TimeSeriesLastDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TimeSeriesLastDateWorker::~TimeSeriesLastDateWorker(){
//
//}

//void TimeSeriesLastDateWorker::Destroy(){
//
//}

void TimeSeriesSizeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::TimeSeriesDef, QuantLib::TimeSeriesDef)

     
  // invoke the member function
  QuantLib::Size returnValue = ObjectIDLibObjPtr->size(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TimeSeriesSizeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TimeSeriesSize) {

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
  Nan::AsyncQueueWorker(new TimeSeriesSizeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TimeSeriesSizeWorker::~TimeSeriesSizeWorker(){
//
//}

//void TimeSeriesSizeWorker::Destroy(){
//
//}

void TimeSeriesEmptyWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::TimeSeriesDef, QuantLib::TimeSeriesDef)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->empty(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TimeSeriesEmptyWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TimeSeriesEmpty) {

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
  Nan::AsyncQueueWorker(new TimeSeriesEmptyWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TimeSeriesEmptyWorker::~TimeSeriesEmptyWorker(){
//
//}

//void TimeSeriesEmptyWorker::Destroy(){
//
//}

void TimeSeriesDatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::TimeSeriesDef, QuantLib::TimeSeriesDef)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Date> returnValue = ObjectIDLibObjPtr->dates(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TimeSeriesDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::TimeSeriesDates) {

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
  Nan::AsyncQueueWorker(new TimeSeriesDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TimeSeriesDatesWorker::~TimeSeriesDatesWorker(){
//
//}

//void TimeSeriesDatesWorker::Destroy(){
//
//}

void TimeSeriesValuesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::TimeSeriesDef, QuantLib::TimeSeriesDef)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->values(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TimeSeriesValuesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::TimeSeriesValues) {

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
  Nan::AsyncQueueWorker(new TimeSeriesValuesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//TimeSeriesValuesWorker::~TimeSeriesValuesWorker(){
//
//}

//void TimeSeriesValuesWorker::Destroy(){
//
//}

void TimeSeriesValueWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::TimeSeriesDef)


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDates, "Dates");

       std::vector<QuantLib::Real> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlTimeSeriesValueBind bindObject =
      boost::bind((QuantLibAddin::qlTimeSeriesValueSignature)
              &QuantLibAddin::TimeSeriesDef::subscriptWrapper,
              ObjectIDObjPtr
          ,_1
          );

  ObjectHandler::loop
      <QuantLibAddin::qlTimeSeriesValueBind,
                      QuantLib::Date,
                      QuantLib::Real>
          (bindObject,
            DatesLib,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TimeSeriesValueWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::TimeSeriesValue) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Dates is required.");
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

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TimeSeriesValueWorker(
    callback
    ,ObjectIDCpp
    ,DatesCpp
  ));

}

//TimeSeriesValueWorker::~TimeSeriesValueWorker(){
//
//}

//void TimeSeriesValueWorker::Destroy(){
//
//}
 