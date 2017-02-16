/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "abcd.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/abcd.hpp>
#include <qlo/optimization.hpp>
#include <ql/termstructures/volatility/abcd.hpp>
#include <ql/termstructures/volatility/abcdcalibration.hpp>
#include <qlo/loop/loop_abcd.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void AbcdFunctionWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlAbcdFunction(
          mObjectID,
          mA,
          mB,
          mC,
          mD,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::AbcdFunction(
          valueObject,
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

void AbcdFunctionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdFunction) {

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

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdFunctionWorker(
    callback
    ,ObjectIDCpp
    ,ACpp
    ,BCpp
    ,CCpp
    ,DCpp
  ));

}

//AbcdFunctionWorker::~AbcdFunctionWorker(){
//
//}

//void AbcdFunctionWorker::Destroy(){
//
//}

void AbcdCalibrationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(EndCriteriaLibObjPtr, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_REFERENCE(MethodLibObjPtr, mMethod,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlAbcdCalibration(
          mObjectID,
          mTimes,
          mBlackVols,
          mA,
          mB,
          mC,
          mD,
          mAIsFixed,
          mBIsFixed,
          mCIsFixed,
          mDIsFixed,
          mVegaWeighted,
          mEndCriteria,
          mMethod,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::AbcdCalibration(
          valueObject,
          mTimes,
          mBlackVols,
          mA,
          mB,
          mC,
          mD,
          mAIsFixed,
          mBIsFixed,
          mCIsFixed,
          mDIsFixed,
          mVegaWeighted,
          EndCriteriaLibObjPtr,
          MethodLibObjPtr,
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

void AbcdCalibrationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdCalibration) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Times is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("BlackVols is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("A is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("B is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("C is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("D is required.");
  }
  if (info.Length() == 7 || !info[7]->IsBoolean()) {
      return Nan::ThrowError("AIsFixed is required.");
  }
  if (info.Length() == 8 || !info[8]->IsBoolean()) {
      return Nan::ThrowError("BIsFixed is required.");
  }
  if (info.Length() == 9 || !info[9]->IsBoolean()) {
      return Nan::ThrowError("CIsFixed is required.");
  }
  if (info.Length() == 10 || !info[10]->IsBoolean()) {
      return Nan::ThrowError("DIsFixed is required.");
  }
  if (info.Length() == 11 || !info[11]->IsBoolean()) {
      return Nan::ThrowError("VegaWeighted is required.");
  }
  if (info.Length() == 12 || !info[12]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 13 || !info[13]->IsString()) {
      return Nan::ThrowError("Method is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>TimesCpp;

  Local<Array> TimesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < TimesArray->Length(); i++){
    TimesCpp.push_back(Nan::To<double>(Nan::Get(TimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>BlackVolsCpp;

  Local<Array> BlackVolsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < BlackVolsArray->Length(); i++){
    BlackVolsCpp.push_back(Nan::To<double>(Nan::Get(BlackVolsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double ACpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double BCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double CCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double DCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  bool AIsFixedCpp = Nan::To<bool>(info[7]).FromJust();

  // convert js argument to c++ type
  bool BIsFixedCpp = Nan::To<bool>(info[8]).FromJust();

  // convert js argument to c++ type
  bool CIsFixedCpp = Nan::To<bool>(info[9]).FromJust();

  // convert js argument to c++ type
  bool DIsFixedCpp = Nan::To<bool>(info[10]).FromJust();

  // convert js argument to c++ type
  bool VegaWeightedCpp = Nan::To<bool>(info[11]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[12]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  String::Utf8Value strMethod(info[13]->ToString());
  string MethodCpp(strdup(*strMethod));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[14].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdCalibrationWorker(
    callback
    ,ObjectIDCpp
    ,TimesCpp
    ,BlackVolsCpp
    ,ACpp
    ,BCpp
    ,CCpp
    ,DCpp
    ,AIsFixedCpp
    ,BIsFixedCpp
    ,CIsFixedCpp
    ,DIsFixedCpp
    ,VegaWeightedCpp
    ,EndCriteriaCpp
    ,MethodCpp
  ));

}

//AbcdCalibrationWorker::~AbcdCalibrationWorker(){
//
//}

//void AbcdCalibrationWorker::Destroy(){
//
//}

void AbcdFunctionInstantaneousValueWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlAbcdFunctionInstantaneousValueBind bindObject =
      boost::bind((QuantLibAddin::qlAbcdFunctionInstantaneousValueSignature)
              &QuantLib::AbcdFunction::operator(),
              ObjectIDLibObjPtr
          ,_1
          );

  ObjectHandler::loop
      <QuantLibAddin::qlAbcdFunctionInstantaneousValueBind,
                      double,
                      double>
          (bindObject,
           mU,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionInstantaneousValueWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdFunctionInstantaneousValue) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("U is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>UCpp;

  Local<Array> UArray = info[1].As<Array>();
  for (unsigned int i = 0; i < UArray->Length(); i++){
    UCpp.push_back(Nan::To<double>(Nan::Get(UArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdFunctionInstantaneousValueWorker(
    callback
    ,ObjectIDCpp
    ,UCpp
  ));

}

//AbcdFunctionInstantaneousValueWorker::~AbcdFunctionInstantaneousValueWorker(){
//
//}

//void AbcdFunctionInstantaneousValueWorker::Destroy(){
//
//}

void AbcdFunctionInstantaneousCovarianceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlAbcdFunctionInstantaneousCovarianceBind bindObject =
      boost::bind((QuantLibAddin::qlAbcdFunctionInstantaneousCovarianceSignature)
              &QuantLib::AbcdFunction::instantaneousCovariance,
              ObjectIDLibObjPtr
          ,_1
          ,mT
          ,mS
          );

  ObjectHandler::loop
      <QuantLibAddin::qlAbcdFunctionInstantaneousCovarianceBind,
                      double,
                      double>
          (bindObject,
           mU,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionInstantaneousCovarianceWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdFunctionInstantaneousCovariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("U is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("T is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("S is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>UCpp;

  Local<Array> UArray = info[1].As<Array>();
  for (unsigned int i = 0; i < UArray->Length(); i++){
    UCpp.push_back(Nan::To<double>(Nan::Get(UArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double TCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double SCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdFunctionInstantaneousCovarianceWorker(
    callback
    ,ObjectIDCpp
    ,UCpp
    ,TCpp
    ,SCpp
  ));

}

//AbcdFunctionInstantaneousCovarianceWorker::~AbcdFunctionInstantaneousCovarianceWorker(){
//
//}

//void AbcdFunctionInstantaneousCovarianceWorker::Destroy(){
//
//}

void AbcdFunctionInstantaneousVarianceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlAbcdFunctionInstantaneousVarianceBind bindObject =
      boost::bind((QuantLibAddin::qlAbcdFunctionInstantaneousVarianceSignature)
              &QuantLib::AbcdFunction::instantaneousVariance,
              ObjectIDLibObjPtr
          ,_1
          ,mT
          );

  ObjectHandler::loop
      <QuantLibAddin::qlAbcdFunctionInstantaneousVarianceBind,
                      double,
                      double>
          (bindObject,
           mU,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionInstantaneousVarianceWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdFunctionInstantaneousVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("U is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("T is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>UCpp;

  Local<Array> UArray = info[1].As<Array>();
  for (unsigned int i = 0; i < UArray->Length(); i++){
    UCpp.push_back(Nan::To<double>(Nan::Get(UArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double TCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdFunctionInstantaneousVarianceWorker(
    callback
    ,ObjectIDCpp
    ,UCpp
    ,TCpp
  ));

}

//AbcdFunctionInstantaneousVarianceWorker::~AbcdFunctionInstantaneousVarianceWorker(){
//
//}

//void AbcdFunctionInstantaneousVarianceWorker::Destroy(){
//
//}

void AbcdFunctionInstantaneousVolatilityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlAbcdFunctionInstantaneousVolatilityBind bindObject =
      boost::bind((QuantLibAddin::qlAbcdFunctionInstantaneousVolatilitySignature)
              &QuantLib::AbcdFunction::instantaneousVolatility,
              ObjectIDLibObjPtr
          ,_1
          ,mT
          );

  ObjectHandler::loop
      <QuantLibAddin::qlAbcdFunctionInstantaneousVolatilityBind,
                      double,
                      QuantLib::Volatility>
          (bindObject,
           mU,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionInstantaneousVolatilityWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdFunctionInstantaneousVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("U is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("T is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>UCpp;

  Local<Array> UArray = info[1].As<Array>();
  for (unsigned int i = 0; i < UArray->Length(); i++){
    UCpp.push_back(Nan::To<double>(Nan::Get(UArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double TCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdFunctionInstantaneousVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,UCpp
    ,TCpp
  ));

}

//AbcdFunctionInstantaneousVolatilityWorker::~AbcdFunctionInstantaneousVolatilityWorker(){
//
//}

//void AbcdFunctionInstantaneousVolatilityWorker::Destroy(){
//
//}

void AbcdFunctionCovarianceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlAbcdFunctionCovarianceBind bindObject =
      boost::bind((QuantLibAddin::qlAbcdFunctionCovarianceSignature)
              &QuantLib::AbcdFunction::covariance,
              ObjectIDLibObjPtr
          ,mTMin
          ,_1
          ,mT
          ,mS
          );

  ObjectHandler::loop
      <QuantLibAddin::qlAbcdFunctionCovarianceBind,
                      double,
                      double>
          (bindObject,
           mTMax,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionCovarianceWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdFunctionCovariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TMin is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("TMax is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("T is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("S is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TMinCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  std::vector<double>TMaxCpp;

  Local<Array> TMaxArray = info[2].As<Array>();
  for (unsigned int i = 0; i < TMaxArray->Length(); i++){
    TMaxCpp.push_back(Nan::To<double>(Nan::Get(TMaxArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double TCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double SCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdFunctionCovarianceWorker(
    callback
    ,ObjectIDCpp
    ,TMinCpp
    ,TMaxCpp
    ,TCpp
    ,SCpp
  ));

}

//AbcdFunctionCovarianceWorker::~AbcdFunctionCovarianceWorker(){
//
//}

//void AbcdFunctionCovarianceWorker::Destroy(){
//
//}

void AbcdFunctionVarianceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlAbcdFunctionVarianceBind bindObject =
      boost::bind((QuantLibAddin::qlAbcdFunctionVarianceSignature)
              &QuantLib::AbcdFunction::variance,
              ObjectIDLibObjPtr
          ,mTMin
          ,_1
          ,mT
          );

  ObjectHandler::loop
      <QuantLibAddin::qlAbcdFunctionVarianceBind,
                      double,
                      double>
          (bindObject,
           mTMax,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionVarianceWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdFunctionVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TMin is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("TMax is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("T is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TMinCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  std::vector<double>TMaxCpp;

  Local<Array> TMaxArray = info[2].As<Array>();
  for (unsigned int i = 0; i < TMaxArray->Length(); i++){
    TMaxCpp.push_back(Nan::To<double>(Nan::Get(TMaxArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double TCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdFunctionVarianceWorker(
    callback
    ,ObjectIDCpp
    ,TMinCpp
    ,TMaxCpp
    ,TCpp
  ));

}

//AbcdFunctionVarianceWorker::~AbcdFunctionVarianceWorker(){
//
//}

//void AbcdFunctionVarianceWorker::Destroy(){
//
//}

void AbcdFunctionVolatilityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlAbcdFunctionVolatilityBind bindObject =
      boost::bind((QuantLibAddin::qlAbcdFunctionVolatilitySignature)
              &QuantLib::AbcdFunction::volatility,
              ObjectIDLibObjPtr
          ,mTMin
          ,_1
          ,mT
          );

  ObjectHandler::loop
      <QuantLibAddin::qlAbcdFunctionVolatilityBind,
                      double,
                      QuantLib::Volatility>
          (bindObject,
           mTMax,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionVolatilityWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdFunctionVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("TMin is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("TMax is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("T is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TMinCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  std::vector<double>TMaxCpp;

  Local<Array> TMaxArray = info[2].As<Array>();
  for (unsigned int i = 0; i < TMaxArray->Length(); i++){
    TMaxCpp.push_back(Nan::To<double>(Nan::Get(TMaxArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double TCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdFunctionVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,TMinCpp
    ,TMaxCpp
    ,TCpp
  ));

}

//AbcdFunctionVolatilityWorker::~AbcdFunctionVolatilityWorker(){
//
//}

//void AbcdFunctionVolatilityWorker::Destroy(){
//
//}

void AbcdFunctionShortTermVolatilityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->shortTermVolatility(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionShortTermVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdFunctionShortTermVolatility) {

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
  Nan::AsyncQueueWorker(new AbcdFunctionShortTermVolatilityWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdFunctionShortTermVolatilityWorker::~AbcdFunctionShortTermVolatilityWorker(){
//
//}

//void AbcdFunctionShortTermVolatilityWorker::Destroy(){
//
//}

void AbcdFunctionLongTermVolatilityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->longTermVolatility(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionLongTermVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdFunctionLongTermVolatility) {

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
  Nan::AsyncQueueWorker(new AbcdFunctionLongTermVolatilityWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdFunctionLongTermVolatilityWorker::~AbcdFunctionLongTermVolatilityWorker(){
//
//}

//void AbcdFunctionLongTermVolatilityWorker::Destroy(){
//
//}

void AbcdFunctionMaximumLocationWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->maximumLocation(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionMaximumLocationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdFunctionMaximumLocation) {

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
  Nan::AsyncQueueWorker(new AbcdFunctionMaximumLocationWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdFunctionMaximumLocationWorker::~AbcdFunctionMaximumLocationWorker(){
//
//}

//void AbcdFunctionMaximumLocationWorker::Destroy(){
//
//}

void AbcdFunctionMaximumVolatilityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->maximumVolatility(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionMaximumVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdFunctionMaximumVolatility) {

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
  Nan::AsyncQueueWorker(new AbcdFunctionMaximumVolatilityWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdFunctionMaximumVolatilityWorker::~AbcdFunctionMaximumVolatilityWorker(){
//
//}

//void AbcdFunctionMaximumVolatilityWorker::Destroy(){
//
//}

void AbcdFunctionAWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->a(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionAWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdFunctionA) {

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
  Nan::AsyncQueueWorker(new AbcdFunctionAWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdFunctionAWorker::~AbcdFunctionAWorker(){
//
//}

//void AbcdFunctionAWorker::Destroy(){
//
//}

void AbcdFunctionBWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->b(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionBWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdFunctionB) {

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
  Nan::AsyncQueueWorker(new AbcdFunctionBWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdFunctionBWorker::~AbcdFunctionBWorker(){
//
//}

//void AbcdFunctionBWorker::Destroy(){
//
//}

void AbcdFunctionCWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->c(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionCWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdFunctionC) {

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
  Nan::AsyncQueueWorker(new AbcdFunctionCWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdFunctionCWorker::~AbcdFunctionCWorker(){
//
//}

//void AbcdFunctionCWorker::Destroy(){
//
//}

void AbcdFunctionDWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->d(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdFunctionDWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdFunctionD) {

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
  Nan::AsyncQueueWorker(new AbcdFunctionDWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdFunctionDWorker::~AbcdFunctionDWorker(){
//
//}

//void AbcdFunctionDWorker::Destroy(){
//
//}

void AbcdDFunctionWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdFunction, QuantLib::AbcdFunction)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->d(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdDFunctionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdDFunction) {

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
  Nan::AsyncQueueWorker(new AbcdDFunctionWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdDFunctionWorker::~AbcdDFunctionWorker(){
//
//}

//void AbcdDFunctionWorker::Destroy(){
//
//}

void AbcdCalibrationComputeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdCalibration, QuantLib::AbcdCalibration)


  // invoke the member function
  ObjectIDLibObjPtr->compute(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdCalibrationComputeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdCalibrationCompute) {

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
  Nan::AsyncQueueWorker(new AbcdCalibrationComputeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdCalibrationComputeWorker::~AbcdCalibrationComputeWorker(){
//
//}

//void AbcdCalibrationComputeWorker::Destroy(){
//
//}

void AbcdCalibrationKWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdCalibration, QuantLib::AbcdCalibration)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->k(
        mTimes
        ,
         mBlackVols
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdCalibrationKWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdCalibrationK) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Times is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("BlackVols is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>TimesCpp;

  Local<Array> TimesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < TimesArray->Length(); i++){
    TimesCpp.push_back(Nan::To<double>(Nan::Get(TimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>BlackVolsCpp;

  Local<Array> BlackVolsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < BlackVolsArray->Length(); i++){
    BlackVolsCpp.push_back(Nan::To<double>(Nan::Get(BlackVolsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdCalibrationKWorker(
    callback
    ,ObjectIDCpp
    ,TimesCpp
    ,BlackVolsCpp
  ));

}

//AbcdCalibrationKWorker::~AbcdCalibrationKWorker(){
//
//}

//void AbcdCalibrationKWorker::Destroy(){
//
//}

void AbcdCalibrationErrorWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdCalibration, QuantLib::AbcdCalibration)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->error(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdCalibrationErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdCalibrationError) {

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
  Nan::AsyncQueueWorker(new AbcdCalibrationErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdCalibrationErrorWorker::~AbcdCalibrationErrorWorker(){
//
//}

//void AbcdCalibrationErrorWorker::Destroy(){
//
//}

void AbcdCalibrationMaxErrorWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdCalibration, QuantLib::AbcdCalibration)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->maxError(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdCalibrationMaxErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdCalibrationMaxError) {

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
  Nan::AsyncQueueWorker(new AbcdCalibrationMaxErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdCalibrationMaxErrorWorker::~AbcdCalibrationMaxErrorWorker(){
//
//}

//void AbcdCalibrationMaxErrorWorker::Destroy(){
//
//}

void AbcdCalibrationEndCriteriaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdCalibration, QuantLib::AbcdCalibration)


  // invoke the member function
  QuantLib::EndCriteria::Type returnValue = ObjectIDLibObjPtr->endCriteria(
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

void AbcdCalibrationEndCriteriaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdCalibrationEndCriteria) {

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
  Nan::AsyncQueueWorker(new AbcdCalibrationEndCriteriaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdCalibrationEndCriteriaWorker::~AbcdCalibrationEndCriteriaWorker(){
//
//}

//void AbcdCalibrationEndCriteriaWorker::Destroy(){
//
//}

void AbcdCalibrationAWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdCalibration, QuantLib::AbcdCalibration)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->a(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdCalibrationAWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdCalibrationA) {

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
  Nan::AsyncQueueWorker(new AbcdCalibrationAWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdCalibrationAWorker::~AbcdCalibrationAWorker(){
//
//}

//void AbcdCalibrationAWorker::Destroy(){
//
//}

void AbcdCalibrationBWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdCalibration, QuantLib::AbcdCalibration)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->b(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdCalibrationBWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdCalibrationB) {

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
  Nan::AsyncQueueWorker(new AbcdCalibrationBWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdCalibrationBWorker::~AbcdCalibrationBWorker(){
//
//}

//void AbcdCalibrationBWorker::Destroy(){
//
//}

void AbcdCalibrationCWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdCalibration, QuantLib::AbcdCalibration)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->c(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdCalibrationCWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdCalibrationC) {

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
  Nan::AsyncQueueWorker(new AbcdCalibrationCWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdCalibrationCWorker::~AbcdCalibrationCWorker(){
//
//}

//void AbcdCalibrationCWorker::Destroy(){
//
//}

void AbcdCalibrationDWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdCalibration, QuantLib::AbcdCalibration)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->d(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdCalibrationDWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdCalibrationD) {

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
  Nan::AsyncQueueWorker(new AbcdCalibrationDWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdCalibrationDWorker::~AbcdCalibrationDWorker(){
//
//}

//void AbcdCalibrationDWorker::Destroy(){
//
//}
 