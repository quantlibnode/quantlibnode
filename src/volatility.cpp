/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "volatility.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/volatility.hpp>
#include <ql/models/marketmodels/models/piecewiseconstantabcdvariance.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void PiecewiseConstantAbcdVarianceWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlPiecewiseConstantAbcdVariance(
          mObjectID,
          mA,
          mB,
          mC,
          mD,
          mResetIndex,
          mRateTimes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::PiecewiseConstantAbcdVariance(
          valueObject,
          mA,
          mB,
          mC,
          mD,
          mResetIndex,
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

void PiecewiseConstantAbcdVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseConstantAbcdVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("A is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("B is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("C is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("D is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("ResetIndex is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double ACpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double BCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double CCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double DCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  long ResetIndexCpp = Nan::To<int32_t>(info[5]).FromJust();

  // convert js argument to c++ type
  std::vector<double>RateTimesCpp;

  Local<Array> RateTimesArray = info[6].As<Array>();
  for (unsigned int i = 0; i < RateTimesArray->Length(); i++){
    RateTimesCpp.push_back(Nan::To<double>(Nan::Get(RateTimesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseConstantAbcdVarianceWorker(
    callback
    ,ObjectIDCpp
    ,ACpp
    ,BCpp
    ,CCpp
    ,DCpp
    ,ResetIndexCpp
    ,RateTimesCpp
  ));

}

//PiecewiseConstantAbcdVarianceWorker::~PiecewiseConstantAbcdVarianceWorker(){
//
//}

//void PiecewiseConstantAbcdVarianceWorker::Destroy(){
//
//}

void MarketModelLmExtLinearExponentialVolModelWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMarketModelLmExtLinearExponentialVolModel(
          mObjectID,
          mFixingTimes,
          mA,
          mB,
          mC,
          mD,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::LmExtLinearExponentialVolModel(
          valueObject,
          mFixingTimes,
          mA,
          mB,
          mC,
          mD,
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

void MarketModelLmExtLinearExponentialVolModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelLmExtLinearExponentialVolModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("FixingTimes is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("A is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("B is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("C is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("D is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>FixingTimesCpp;

  Local<Array> FixingTimesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < FixingTimesArray->Length(); i++){
    FixingTimesCpp.push_back(Nan::To<double>(Nan::Get(FixingTimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double ACpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double BCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double CCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double DCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelLmExtLinearExponentialVolModelWorker(
    callback
    ,ObjectIDCpp
    ,FixingTimesCpp
    ,ACpp
    ,BCpp
    ,CCpp
    ,DCpp
  ));

}

//MarketModelLmExtLinearExponentialVolModelWorker::~MarketModelLmExtLinearExponentialVolModelWorker(){
//
//}

//void MarketModelLmExtLinearExponentialVolModelWorker::Destroy(){
//
//}

void PiecewiseConstantVarianceVariancesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->variances(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantVarianceVariancesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::PiecewiseConstantVarianceVariances) {

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
  Nan::AsyncQueueWorker(new PiecewiseConstantVarianceVariancesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseConstantVarianceVariancesWorker::~PiecewiseConstantVarianceVariancesWorker(){
//
//}

//void PiecewiseConstantVarianceVariancesWorker::Destroy(){
//
//}

void PiecewiseConstantVarianceVolatilitiesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->volatilities(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantVarianceVolatilitiesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::PiecewiseConstantVarianceVolatilities) {

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
  Nan::AsyncQueueWorker(new PiecewiseConstantVarianceVolatilitiesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseConstantVarianceVolatilitiesWorker::~PiecewiseConstantVarianceVolatilitiesWorker(){
//
//}

//void PiecewiseConstantVarianceVolatilitiesWorker::Destroy(){
//
//}

void PiecewiseConstantVarianceRateTimesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->rateTimes(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantVarianceRateTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::PiecewiseConstantVarianceRateTimes) {

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
  Nan::AsyncQueueWorker(new PiecewiseConstantVarianceRateTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//PiecewiseConstantVarianceRateTimesWorker::~PiecewiseConstantVarianceRateTimesWorker(){
//
//}

//void PiecewiseConstantVarianceRateTimesWorker::Destroy(){
//
//}

void PiecewiseConstantVarianceVarianceWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size TimeIndexLib;
  QuantLibAddin::cppToLibrary(mTimeIndex, TimeIndexLib);

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->variance(
        TimeIndexLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantVarianceVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseConstantVarianceVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeIndex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long TimeIndexCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseConstantVarianceVarianceWorker(
    callback
    ,ObjectIDCpp
    ,TimeIndexCpp
  ));

}

//PiecewiseConstantVarianceVarianceWorker::~PiecewiseConstantVarianceVarianceWorker(){
//
//}

//void PiecewiseConstantVarianceVarianceWorker::Destroy(){
//
//}

void PiecewiseConstantVarianceVolatilityWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size TimeIndexLib;
  QuantLibAddin::cppToLibrary(mTimeIndex, TimeIndexLib);

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->volatility(
        TimeIndexLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantVarianceVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseConstantVarianceVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeIndex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long TimeIndexCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseConstantVarianceVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,TimeIndexCpp
  ));

}

//PiecewiseConstantVarianceVolatilityWorker::~PiecewiseConstantVarianceVolatilityWorker(){
//
//}

//void PiecewiseConstantVarianceVolatilityWorker::Destroy(){
//
//}

void PiecewiseConstantVarianceTotalVarianceWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size TimeIndexLib;
  QuantLibAddin::cppToLibrary(mTimeIndex, TimeIndexLib);

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->totalVariance(
        TimeIndexLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantVarianceTotalVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseConstantVarianceTotalVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeIndex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long TimeIndexCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseConstantVarianceTotalVarianceWorker(
    callback
    ,ObjectIDCpp
    ,TimeIndexCpp
  ));

}

//PiecewiseConstantVarianceTotalVarianceWorker::~PiecewiseConstantVarianceTotalVarianceWorker(){
//
//}

//void PiecewiseConstantVarianceTotalVarianceWorker::Destroy(){
//
//}

void PiecewiseConstantVarianceTotalVolatilityWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size TimeIndexLib;
  QuantLibAddin::cppToLibrary(mTimeIndex, TimeIndexLib);

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::PiecewiseConstantVariance, QuantLib::PiecewiseConstantVariance)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->totalVolatility(
        TimeIndexLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PiecewiseConstantVarianceTotalVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseConstantVarianceTotalVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TimeIndex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long TimeIndexCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseConstantVarianceTotalVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,TimeIndexCpp
  ));

}

//PiecewiseConstantVarianceTotalVolatilityWorker::~PiecewiseConstantVarianceTotalVolatilityWorker(){
//
//}

//void PiecewiseConstantVarianceTotalVolatilityWorker::Destroy(){
//
//}
 