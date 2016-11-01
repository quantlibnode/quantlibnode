// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "repository.hpp"

#include <qlo/qladdindefines.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void ObjectPropertyNamesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, ObjectHandler::Object)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->propertyNamesVector(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ObjectPropertyNamesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::ObjectPropertyNames) {

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
  Nan::AsyncQueueWorker(new ObjectPropertyNamesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//ObjectPropertyNamesWorker::~ObjectPropertyNamesWorker(){
//
//}

//ObjectPropertyNamesWorker::Destroy(){
//
//}

void DeleteObjectWorker::Execute(){

  try{
       // invoke the utility function
  ObjectHandler::Repository::instance().deleteObject(
      mObjectID
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DeleteObjectWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DeleteObject) {

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
  Nan::AsyncQueueWorker(new DeleteObjectWorker(
    callback
    ,ObjectIDCpp
  ));

}

//DeleteObjectWorker::~DeleteObjectWorker(){
//
//}

//DeleteObjectWorker::Destroy(){
//
//}

void DeleteObjectsWorker::Execute(){

  try{
       // invoke the utility function
  ObjectHandler::Repository::instance().deleteObject(
      mObjectID
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DeleteObjectsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DeleteObjects) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  std::vector<string>ObjectIDCpp;

  Local<Array> ObjectIDArray = info[0].As<Array>();
  for (unsigned int i = 0; i < ObjectIDArray->Length(); i++){
    String::Utf8Value strObjectID(Nan::Get(ObjectIDArray, i).ToLocalChecked()->ToString());
    ObjectIDCpp.push_back(strdup(*strObjectID));
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DeleteObjectsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//DeleteObjectsWorker::~DeleteObjectsWorker(){
//
//}

//DeleteObjectsWorker::Destroy(){
//
//}

void DeleteAllObjectsWorker::Execute(){

  try{
       // invoke the utility function
  ObjectHandler::Repository::instance().deleteAllObjects(
      mDeletePermanent
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DeleteAllObjectsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DeleteAllObjects) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsBoolean()) {
      return Nan::ThrowError("DeletePermanent is required.");
  }
  // convert js argument to c++ type
  bool DeletePermanentCpp = Nan::To<bool>(info[0]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DeleteAllObjectsWorker(
    callback
    ,DeletePermanentCpp
  ));

}

//DeleteAllObjectsWorker::~DeleteAllObjectsWorker(){
//
//}

//DeleteAllObjectsWorker::Destroy(){
//
//}

void ListObjectIDsWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = ObjectHandler::Repository::instance().listObjectIDs(
      mRegex
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ListObjectIDsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::ListObjectIDs) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("Regex is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strRegex(info[0]->ToString());
  string RegexCpp(strdup(*strRegex));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ListObjectIDsWorker(
    callback
    ,RegexCpp
  ));

}

//ListObjectIDsWorker::~ListObjectIDsWorker(){
//
//}

//ListObjectIDsWorker::Destroy(){
//
//}
 