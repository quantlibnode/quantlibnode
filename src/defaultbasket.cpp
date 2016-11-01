// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "defaultbasket.hpp"

#include <qlo/qladdindefines.hpp>
#include <ql/experimental/credit/basket.hpp>
#include <qlo/credit.hpp>
#include <qlo/defaultbasket.hpp>
#include <qlo/basketlossmodels.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void CreditBasketWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::Issuer> > IssuersLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::Issuer, QuantLib::Issuer>(mIssuers);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ReferenceDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mReferenceDate, "ReferenceDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCreditBasket(
          mObjectID,
          mIssuerNames,
          mIssuers,
          mNotionals,
          mReferenceDate,
          mAttachmentRatio,
          mDettachmentRatio,
          mAmortizing,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Basket(
          valueObject,
          mIssuerNames,
          IssuersLibObjPtr,
          mNotionals,
          ReferenceDateLib,
          mAttachmentRatio,
          mDettachmentRatio,
          mAmortizing,
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

void CreditBasketWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditBasket) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("IssuerNames is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Issuers is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Notionals is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("AttachmentRatio is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("DettachmentRatio is required.");
  }
  if (info.Length() == 7 || !info[7]->IsBoolean()) {
      return Nan::ThrowError("Amortizing is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<string>IssuerNamesCpp;

  Local<Array> IssuerNamesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < IssuerNamesArray->Length(); i++){
    String::Utf8Value strIssuerNames(Nan::Get(IssuerNamesArray, i).ToLocalChecked()->ToString());
    IssuerNamesCpp.push_back(strdup(*strIssuerNames));
  }

  // convert js argument to c++ type
  std::vector<string>IssuersCpp;

  Local<Array> IssuersArray = info[2].As<Array>();
  for (unsigned int i = 0; i < IssuersArray->Length(); i++){
    String::Utf8Value strIssuers(Nan::Get(IssuersArray, i).ToLocalChecked()->ToString());
    IssuersCpp.push_back(strdup(*strIssuers));
  }

  // convert js argument to c++ type
  std::vector<double>NotionalsCpp;

  Local<Array> NotionalsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < NotionalsArray->Length(); i++){
    NotionalsCpp.push_back(Nan::To<double>(Nan::Get(NotionalsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  ObjectHandler::property_t ReferenceDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  double AttachmentRatioCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double DettachmentRatioCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  bool AmortizingCpp = Nan::To<bool>(info[7]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CreditBasketWorker(
    callback
    ,ObjectIDCpp
    ,IssuerNamesCpp
    ,IssuersCpp
    ,NotionalsCpp
    ,ReferenceDateCpp
    ,AttachmentRatioCpp
    ,DettachmentRatioCpp
    ,AmortizingCpp
  ));

}

//CreditBasketWorker::~CreditBasketWorker(){
//
//}

//CreditBasketWorker::Destroy(){
//
//}

void CreditBasketSetLossModelWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(DefaultLossModelLibObjPtr, mDefaultLossModel,
      QuantLibAddin::DefaultLossModel, QuantLib::DefaultLossModel)

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  ObjectIDLibObjPtr->setLossModel(
        DefaultLossModelLibObjPtr
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CreditBasketSetLossModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditBasketSetLossModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("DefaultLossModel is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDefaultLossModel(info[1]->ToString());
  string DefaultLossModelCpp(strdup(*strDefaultLossModel));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CreditBasketSetLossModelWorker(
    callback
    ,ObjectIDCpp
    ,DefaultLossModelCpp
  ));

}

//CreditBasketSetLossModelWorker::~CreditBasketSetLossModelWorker(){
//
//}

//CreditBasketSetLossModelWorker::Destroy(){
//
//}

void CreditBasketSizeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


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

void CreditBasketSizeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditBasketSize) {

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
  Nan::AsyncQueueWorker(new CreditBasketSizeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CreditBasketSizeWorker::~CreditBasketSizeWorker(){
//
//}

//CreditBasketSizeWorker::Destroy(){
//
//}

void CreditBasketLiveNotionalWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->remainingNotional(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CreditBasketLiveNotionalWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditBasketLiveNotional) {

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
  Nan::AsyncQueueWorker(new CreditBasketLiveNotionalWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CreditBasketLiveNotionalWorker::~CreditBasketLiveNotionalWorker(){
//
//}

//CreditBasketLiveNotionalWorker::Destroy(){
//
//}

void CreditBasketLossWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->cumulatedLoss(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CreditBasketLossWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditBasketLoss) {

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
  Nan::AsyncQueueWorker(new CreditBasketLossWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CreditBasketLossWorker::~CreditBasketLossWorker(){
//
//}

//CreditBasketLossWorker::Destroy(){
//
//}

void CrediBasketAttachLiveWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->remainingAttachmentAmount(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CrediBasketAttachLiveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CrediBasketAttachLive) {

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
  Nan::AsyncQueueWorker(new CrediBasketAttachLiveWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CrediBasketAttachLiveWorker::~CrediBasketAttachLiveWorker(){
//
//}

//CrediBasketAttachLiveWorker::Destroy(){
//
//}

void CrediBasketDetachLiveWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->remainingDetachmentAmount(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CrediBasketDetachLiveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CrediBasketDetachLive) {

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
  Nan::AsyncQueueWorker(new CrediBasketDetachLiveWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CrediBasketDetachLiveWorker::~CrediBasketDetachLiveWorker(){
//
//}

//CrediBasketDetachLiveWorker::Destroy(){
//
//}

void ExpectedTrancheLossWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateForLossLib = ObjectHandler::convert2<QuantLib::Date>(
      mDateForLoss, "DateForLoss");

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->expectedTrancheLoss(
        DateForLossLib
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ExpectedTrancheLossWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ExpectedTrancheLoss) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t DateForLossCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ExpectedTrancheLossWorker(
    callback
    ,ObjectIDCpp
    ,DateForLossCpp
  ));

}

//ExpectedTrancheLossWorker::~ExpectedTrancheLossWorker(){
//
//}

//ExpectedTrancheLossWorker::Destroy(){
//
//}

void CreditBasketPercentileWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateForLossLib = ObjectHandler::convert2<QuantLib::Date>(
      mDateForLoss, "DateForLoss");


  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->percentile(
        DateForLossLib
        ,
         mPercentileValue
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CreditBasketPercentileWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditBasketPercentile) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("PercentileValue is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t DateForLossCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  double PercentileValueCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CreditBasketPercentileWorker(
    callback
    ,ObjectIDCpp
    ,DateForLossCpp
    ,PercentileValueCpp
  ));

}

//CreditBasketPercentileWorker::~CreditBasketPercentileWorker(){
//
//}

//CreditBasketPercentileWorker::Destroy(){
//
//}

void CreditBasketESFWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateForLossLib = ObjectHandler::convert2<QuantLib::Date>(
      mDateForLoss, "DateForLoss");


  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->expectedShortfall(
        DateForLossLib
        ,
         mPercentileValue
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CreditBasketESFWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditBasketESF) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("PercentileValue is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t DateForLossCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  double PercentileValueCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CreditBasketESFWorker(
    callback
    ,ObjectIDCpp
    ,DateForLossCpp
    ,PercentileValueCpp
  ));

}

//CreditBasketESFWorker::~CreditBasketESFWorker(){
//
//}

//CreditBasketESFWorker::Destroy(){
//
//}

void CreditBasketNthEventPWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size EventOrderLib;
  QuantLibAddin::cppToLibrary(mEventOrder, EventOrderLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateForLossLib = ObjectHandler::convert2<QuantLib::Date>(
      mDateForLoss, "DateForLoss");

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->probsBeingNthEvent(
        EventOrderLib
        ,
         DateForLossLib
       );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CreditBasketNthEventPWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CreditBasketNthEventP) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("EventOrder is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long EventOrderCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t DateForLossCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CreditBasketNthEventPWorker(
    callback
    ,ObjectIDCpp
    ,EventOrderCpp
    ,DateForLossCpp
  ));

}

//CreditBasketNthEventPWorker::~CreditBasketNthEventPWorker(){
//
//}

//CreditBasketNthEventPWorker::Destroy(){
//
//}

void CreditBasketProbLossWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateForLossLib = ObjectHandler::convert2<QuantLib::Date>(
      mDateForLoss, "DateForLoss");


  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->probOverLoss(
        DateForLossLib
        ,
         mLossFractionValue
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CreditBasketProbLossWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditBasketProbLoss) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("LossFractionValue is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t DateForLossCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  double LossFractionValueCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CreditBasketProbLossWorker(
    callback
    ,ObjectIDCpp
    ,DateForLossCpp
    ,LossFractionValueCpp
  ));

}

//CreditBasketProbLossWorker::~CreditBasketProbLossWorker(){
//
//}

//CreditBasketProbLossWorker::Destroy(){
//
//}

void CreditBasketSplitLossWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateForLossLib = ObjectHandler::convert2<QuantLib::Date>(
      mDateForLoss, "DateForLoss");


  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->splitVaRLevel(
        DateForLossLib
        ,
         mLossValue
       );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CreditBasketSplitLossWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CreditBasketSplitLoss) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("LossValue is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t DateForLossCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  double LossValueCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CreditBasketSplitLossWorker(
    callback
    ,ObjectIDCpp
    ,DateForLossCpp
    ,LossValueCpp
  ));

}

//CreditBasketSplitLossWorker::~CreditBasketSplitLossWorker(){
//
//}

//CreditBasketSplitLossWorker::Destroy(){
//
//}

void CreditBasketDefaulCorrelWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateCorrelLib = ObjectHandler::convert2<QuantLib::Date>(
      mDateCorrel, "DateCorrel");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexIssuer1Lib;
  QuantLibAddin::cppToLibrary(mIndexIssuer1, IndexIssuer1Lib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size IndexIssuer2Lib;
  QuantLibAddin::cppToLibrary(mIndexIssuer2, IndexIssuer2Lib);

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Basket, QuantLib::Basket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->defaultCorrelation(
        DateCorrelLib
        ,
         IndexIssuer1Lib
        ,
         IndexIssuer2Lib
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CreditBasketDefaulCorrelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditBasketDefaulCorrel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("IndexIssuer1 is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("IndexIssuer2 is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t DateCorrelCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  long IndexIssuer1Cpp = Nan::To<int32_t>(info[2]).FromJust();

  // convert js argument to c++ type
  long IndexIssuer2Cpp = Nan::To<int32_t>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CreditBasketDefaulCorrelWorker(
    callback
    ,ObjectIDCpp
    ,DateCorrelCpp
    ,IndexIssuer1Cpp
    ,IndexIssuer2Cpp
  ));

}

//CreditBasketDefaulCorrelWorker::~CreditBasketDefaulCorrelWorker(){
//
//}

//CreditBasketDefaulCorrelWorker::Destroy(){
//
//}
 