/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "randomsequencegenerator.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/randomsequencegenerator.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void MersenneTwisterRsgWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMersenneTwisterRsg(
          mObjectID,
          mDimension,
          mSeed,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::MersenneTwisterRsg(
          valueObject,
          mDimension,
          mSeed,
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

void MersenneTwisterRsgWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MersenneTwisterRsg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Dimension is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Seed is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long DimensionCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  long SeedCpp = Nan::To<int32_t>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MersenneTwisterRsgWorker(
    callback
    ,ObjectIDCpp
    ,DimensionCpp
    ,SeedCpp
  ));

}

//MersenneTwisterRsgWorker::~MersenneTwisterRsgWorker(){
//
//}

//void MersenneTwisterRsgWorker::Destroy(){
//
//}

void FaureRsgWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFaureRsg(
          mObjectID,
          mDimension,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FaureRsg(
          valueObject,
          mDimension,
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

void FaureRsgWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FaureRsg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Dimension is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long DimensionCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FaureRsgWorker(
    callback
    ,ObjectIDCpp
    ,DimensionCpp
  ));

}

//FaureRsgWorker::~FaureRsgWorker(){
//
//}

//void FaureRsgWorker::Destroy(){
//
//}

void HaltonRsgWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlHaltonRsg(
          mObjectID,
          mDimension,
          mSeed,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::HaltonRsg(
          valueObject,
          mDimension,
          mSeed,
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

void HaltonRsgWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HaltonRsg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Dimension is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Seed is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long DimensionCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  long SeedCpp = Nan::To<int32_t>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HaltonRsgWorker(
    callback
    ,ObjectIDCpp
    ,DimensionCpp
    ,SeedCpp
  ));

}

//HaltonRsgWorker::~HaltonRsgWorker(){
//
//}

//void HaltonRsgWorker::Destroy(){
//
//}

void SobolRsgWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSobolRsg(
          mObjectID,
          mDimension,
          mSeed,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SobolRsg(
          valueObject,
          mDimension,
          mSeed,
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

void SobolRsgWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SobolRsg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Dimension is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Seed is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long DimensionCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  long SeedCpp = Nan::To<int32_t>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SobolRsgWorker(
    callback
    ,ObjectIDCpp
    ,DimensionCpp
    ,SeedCpp
  ));

}

//SobolRsgWorker::~SobolRsgWorker(){
//
//}

//void SobolRsgWorker::Destroy(){
//
//}

void VariatesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::RandomSequenceGenerator)

  std::vector< std::vector<double> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->variates(
        mSamples
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VariatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpMatrix = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Local<Array> tmpArray = Nan::New<Array>(mReturnValue[i].size());
      for (unsigned int j = 0; j < mReturnValue[i].size(); j++) {
        Nan::Set(tmpArray,j,Nan::New<Number>(mReturnValue[i][j]));
      }
      Nan::Set(tmpMatrix,i,tmpArray);
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpMatrix
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Variates) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Samples is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long SamplesCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VariatesWorker(
    callback
    ,ObjectIDCpp
    ,SamplesCpp
  ));

}

//VariatesWorker::~VariatesWorker(){
//
//}

//void VariatesWorker::Destroy(){
//
//}

void RandWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLibAddin::rand(
    );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RandWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Rand) {

  // validate js arguments
 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[0].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RandWorker(
    callback
  ));

}

//RandWorker::~RandWorker(){
//
//}

//void RandWorker::Destroy(){
//
//}

void RandomizeWorker::Execute(){

  try{
       // invoke the utility function
  QuantLibAddin::randomize(
      mSeed
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RandomizeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Randomize) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Seed is required.");
  }
  // convert js argument to c++ type
  long SeedCpp = Nan::To<int32_t>(info[0]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RandomizeWorker(
    callback
    ,SeedCpp
  ));

}

//RandomizeWorker::~RandomizeWorker(){
//
//}

//void RandomizeWorker::Destroy(){
//
//}
 