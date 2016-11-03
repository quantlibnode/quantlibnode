/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "products.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/products.hpp>
#include <qlo/payoffs.hpp>
#include <ql/models/marketmodels/products/onestep/onestepforwards.hpp>
#include <ql/models/marketmodels/products/onestep/onestepoptionlets.hpp>
#include <ql/models/marketmodels/products/multistep/multistepratchet.hpp>
#include <ql/models/marketmodels/products/multiproductcomposite.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void MarketModelMultiProductCompositeWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMarketModelMultiProductComposite(
          mObjectID,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::MultiProductComposite(
          valueObject,
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

void MarketModelMultiProductCompositeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelMultiProductComposite) {

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
  Nan::AsyncQueueWorker(new MarketModelMultiProductCompositeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelMultiProductCompositeWorker::~MarketModelMultiProductCompositeWorker(){
//
//}

//void MarketModelMultiProductCompositeWorker::Destroy(){
//
//}

void MarketModelOneStepForwardsWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMarketModelOneStepForwards(
          mObjectID,
          mRateTimes,
          mAccruals,
          mPaymentTimes,
          mStrikes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::OneStepForwards(
          valueObject,
          mRateTimes,
          mAccruals,
          mPaymentTimes,
          mStrikes,
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

void MarketModelOneStepForwardsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelOneStepForwards) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Accruals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("PaymentTimes is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("Strikes is required.");
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
  std::vector<double>AccrualsCpp;

  Local<Array> AccrualsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < AccrualsArray->Length(); i++){
    AccrualsCpp.push_back(Nan::To<double>(Nan::Get(AccrualsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>PaymentTimesCpp;

  Local<Array> PaymentTimesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < PaymentTimesArray->Length(); i++){
    PaymentTimesCpp.push_back(Nan::To<double>(Nan::Get(PaymentTimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>StrikesCpp;

  Local<Array> StrikesArray = info[4].As<Array>();
  for (unsigned int i = 0; i < StrikesArray->Length(); i++){
    StrikesCpp.push_back(Nan::To<double>(Nan::Get(StrikesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelOneStepForwardsWorker(
    callback
    ,ObjectIDCpp
    ,RateTimesCpp
    ,AccrualsCpp
    ,PaymentTimesCpp
    ,StrikesCpp
  ));

}

//MarketModelOneStepForwardsWorker::~MarketModelOneStepForwardsWorker(){
//
//}

//void MarketModelOneStepForwardsWorker::Destroy(){
//
//}

void MarketModelMultiStepRatchetWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMarketModelMultiStepRatchet(
          mObjectID,
          mRateTimes,
          mAccruals,
          mPaymentTimes,
          mGearingOfFloor,
          mGearingOfFixing,
          mSpreadOfFloor,
          mSpreadOfFixing,
          mInitialFloor,
          mPayer,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::MultiStepRatchet(
          valueObject,
          mRateTimes,
          mAccruals,
          mPaymentTimes,
          mGearingOfFloor,
          mGearingOfFixing,
          mSpreadOfFloor,
          mSpreadOfFixing,
          mInitialFloor,
          mPayer,
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

void MarketModelMultiStepRatchetWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelMultiStepRatchet) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Accruals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("PaymentTimes is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("GearingOfFloor is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("GearingOfFixing is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("SpreadOfFloor is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("SpreadOfFixing is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("InitialFloor is required.");
  }
  if (info.Length() == 9 || !info[9]->IsBoolean()) {
      return Nan::ThrowError("Payer is required.");
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
  std::vector<double>AccrualsCpp;

  Local<Array> AccrualsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < AccrualsArray->Length(); i++){
    AccrualsCpp.push_back(Nan::To<double>(Nan::Get(AccrualsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>PaymentTimesCpp;

  Local<Array> PaymentTimesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < PaymentTimesArray->Length(); i++){
    PaymentTimesCpp.push_back(Nan::To<double>(Nan::Get(PaymentTimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double GearingOfFloorCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double GearingOfFixingCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double SpreadOfFloorCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double SpreadOfFixingCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double InitialFloorCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  bool PayerCpp = Nan::To<bool>(info[9]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelMultiStepRatchetWorker(
    callback
    ,ObjectIDCpp
    ,RateTimesCpp
    ,AccrualsCpp
    ,PaymentTimesCpp
    ,GearingOfFloorCpp
    ,GearingOfFixingCpp
    ,SpreadOfFloorCpp
    ,SpreadOfFixingCpp
    ,InitialFloorCpp
    ,PayerCpp
  ));

}

//MarketModelMultiStepRatchetWorker::~MarketModelMultiStepRatchetWorker(){
//
//}

//void MarketModelMultiStepRatchetWorker::Destroy(){
//
//}

void MarketModelOneStepOptionletsWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::Payoff> > PayoffsLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::Payoff, QuantLib::Payoff>(mPayoffs);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMarketModelOneStepOptionlets(
          mObjectID,
          mRateTimes,
          mAccruals,
          mPaymentTimes,
          mPayoffs,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::OneStepOptionlets(
          valueObject,
          mRateTimes,
          mAccruals,
          mPaymentTimes,
          PayoffsLibObjPtr,
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

void MarketModelOneStepOptionletsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelOneStepOptionlets) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Accruals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("PaymentTimes is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("Payoffs is required.");
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
  std::vector<double>AccrualsCpp;

  Local<Array> AccrualsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < AccrualsArray->Length(); i++){
    AccrualsCpp.push_back(Nan::To<double>(Nan::Get(AccrualsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>PaymentTimesCpp;

  Local<Array> PaymentTimesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < PaymentTimesArray->Length(); i++){
    PaymentTimesCpp.push_back(Nan::To<double>(Nan::Get(PaymentTimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<string>PayoffsCpp;

  Local<Array> PayoffsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < PayoffsArray->Length(); i++){
    String::Utf8Value strPayoffs(Nan::Get(PayoffsArray, i).ToLocalChecked()->ToString());
    PayoffsCpp.push_back(strdup(*strPayoffs));
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelOneStepOptionletsWorker(
    callback
    ,ObjectIDCpp
    ,RateTimesCpp
    ,AccrualsCpp
    ,PaymentTimesCpp
    ,PayoffsCpp
  ));

}

//MarketModelOneStepOptionletsWorker::~MarketModelOneStepOptionletsWorker(){
//
//}

//void MarketModelOneStepOptionletsWorker::Destroy(){
//
//}

void MarketModelMultiProductCompositeAddWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MultiProductComposite, QuantLib::MultiProductComposite)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(ProductLibObj, mProduct,
      QuantLibAddin::MarketModelMultiProduct, QuantLib::MarketModelMultiProduct)

     
  // invoke the member function
  ObjectIDLibObjPtr->MarketModelComposite::add(
        ProductLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelMultiProductCompositeAddWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelMultiProductCompositeAdd) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Product is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strProduct(info[1]->ToString());
  string ProductCpp(strdup(*strProduct));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MarketModelMultiProductCompositeAddWorker(
    callback
    ,ObjectIDCpp
    ,ProductCpp
  ));

}

//MarketModelMultiProductCompositeAddWorker::~MarketModelMultiProductCompositeAddWorker(){
//
//}

//void MarketModelMultiProductCompositeAddWorker::Destroy(){
//
//}

void MarketModelMultiProductCompositeFinalizeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MultiProductComposite, QuantLib::MultiProductComposite)

     
  // invoke the member function
  ObjectIDLibObjPtr->finalize(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelMultiProductCompositeFinalizeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelMultiProductCompositeFinalize) {

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
  Nan::AsyncQueueWorker(new MarketModelMultiProductCompositeFinalizeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelMultiProductCompositeFinalizeWorker::~MarketModelMultiProductCompositeFinalizeWorker(){
//
//}

//void MarketModelMultiProductCompositeFinalizeWorker::Destroy(){
//
//}

void MarketModelMultiProductSuggestedNumerairesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModelMultiProduct, QuantLib::MarketModelMultiProduct)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Size> returnValue = ObjectIDLibObjPtr->suggestedNumeraires(
      );


  mReturnValue = QuantLibAddin::convertVector<QuantLib::Size, long>(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelMultiProductSuggestedNumerairesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MarketModelMultiProductSuggestedNumeraires) {

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
  Nan::AsyncQueueWorker(new MarketModelMultiProductSuggestedNumerairesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelMultiProductSuggestedNumerairesWorker::~MarketModelMultiProductSuggestedNumerairesWorker(){
//
//}

//void MarketModelMultiProductSuggestedNumerairesWorker::Destroy(){
//
//}

void MarketModelMultiProductPossibleCashFlowTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModelMultiProduct, QuantLib::MarketModelMultiProduct)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->possibleCashFlowTimes(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelMultiProductPossibleCashFlowTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MarketModelMultiProductPossibleCashFlowTimes) {

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
  Nan::AsyncQueueWorker(new MarketModelMultiProductPossibleCashFlowTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelMultiProductPossibleCashFlowTimesWorker::~MarketModelMultiProductPossibleCashFlowTimesWorker(){
//
//}

//void MarketModelMultiProductPossibleCashFlowTimesWorker::Destroy(){
//
//}

void MarketModelMultiProductNumberOfProductsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModelMultiProduct, QuantLib::MarketModelMultiProduct)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->numberOfProducts(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelMultiProductNumberOfProductsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelMultiProductNumberOfProducts) {

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
  Nan::AsyncQueueWorker(new MarketModelMultiProductNumberOfProductsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelMultiProductNumberOfProductsWorker::~MarketModelMultiProductNumberOfProductsWorker(){
//
//}

//void MarketModelMultiProductNumberOfProductsWorker::Destroy(){
//
//}

void MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStepWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::MarketModelMultiProduct, QuantLib::MarketModelMultiProduct)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->maxNumberOfCashFlowsPerProductPerStep(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStepWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStep) {

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
  Nan::AsyncQueueWorker(new MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStepWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStepWorker::~MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStepWorker(){
//
//}

//void MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStepWorker::Destroy(){
//
//}
 