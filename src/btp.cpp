// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "btp.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/btp.hpp>
#include <qlo/indexes/ibor/euribor.hpp>
#include <qlo/termstructures.hpp>
#include <ql/instruments/bonds/btp.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void CCTEUWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date MaturityDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mMaturityDate, "MaturityDate");


  // convert object IDs into library objects
  OH_GET_OBJECT(FwdCurveCoerce, mFwdCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> FwdCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              FwdCurveCoerce);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date IssueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mIssueDate, "IssueDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCCTEU(
          mObjectID,
          mDescription,
          mMaturityDate,
          mSpread,
          mFwdCurve,
          mStartDate,
          mIssueDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CCTEU(
          valueObject,
          mDescription,
          MaturityDateLib,
          mSpread,
          FwdCurveLibObj,
          StartDateLib,
          IssueDateLib,
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

void CCTEUWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CCTEU) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Description is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Spread is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDescription(info[1]->ToString());
  string DescriptionCpp(strdup(*strDescription));

  // convert js argument to c++ type
  ObjectHandler::property_t MaturityDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  double SpreadCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t FwdCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[4]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t IssueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CCTEUWorker(
    callback
    ,ObjectIDCpp
    ,DescriptionCpp
    ,MaturityDateCpp
    ,SpreadCpp
    ,FwdCurveCpp
    ,StartDateCpp
    ,IssueDateCpp
  ));

}

//CCTEUWorker::~CCTEUWorker(){
//
//}

//CCTEUWorker::Destroy(){
//
//}

void BTPWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date MaturityDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mMaturityDate, "MaturityDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date IssueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mIssueDate, "IssueDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBTP(
          mObjectID,
          mDescription,
          mMaturityDate,
          mCoupon,
          mStartDate,
          mIssueDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BTP(
          valueObject,
          mDescription,
          MaturityDateLib,
          mCoupon,
          StartDateLib,
          IssueDateLib,
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

void BTPWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BTP) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Description is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Coupon is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDescription(info[1]->ToString());
  string DescriptionCpp(strdup(*strDescription));

  // convert js argument to c++ type
  ObjectHandler::property_t MaturityDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  double CouponCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t IssueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BTPWorker(
    callback
    ,ObjectIDCpp
    ,DescriptionCpp
    ,MaturityDateCpp
    ,CouponCpp
    ,StartDateCpp
    ,IssueDateCpp
  ));

}

//BTPWorker::~BTPWorker(){
//
//}

//BTPWorker::Destroy(){
//
//}

void BTP2Worker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date MaturityDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mMaturityDate, "MaturityDate");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date IssueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mIssueDate, "IssueDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBTP2(
          mObjectID,
          mDescription,
          mMaturityDate,
          mCoupon,
          mRedemption,
          mStartDate,
          mIssueDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BTP(
          valueObject,
          mDescription,
          MaturityDateLib,
          mCoupon,
          mRedemption,
          StartDateLib,
          IssueDateLib,
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

void BTP2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BTP2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Description is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Coupon is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Redemption is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDescription(info[1]->ToString());
  string DescriptionCpp(strdup(*strDescription));

  // convert js argument to c++ type
  ObjectHandler::property_t MaturityDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  double CouponCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double RedemptionCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t IssueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BTP2Worker(
    callback
    ,ObjectIDCpp
    ,DescriptionCpp
    ,MaturityDateCpp
    ,CouponCpp
    ,RedemptionCpp
    ,StartDateCpp
    ,IssueDateCpp
  ));

}

//BTP2Worker::~BTP2Worker(){
//
//}

//BTP2Worker::Destroy(){
//
//}

void RendistatoBasketWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::BTP> > BTPsLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::BTP, QuantLib::BTP>(mBTPs);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> OutstandingsLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mOutstandings);


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > PricesLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mPrices, "Prices");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRendistatoBasket(
          mObjectID,
          mBTPs,
          mOutstandings,
          mPrices,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RendistatoBasket(
          valueObject,
          BTPsLibObjPtr,
          mOutstandings,
          PricesLibObj,
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

void RendistatoBasketWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoBasket) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("BTPs is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Outstandings is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Prices is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<string>BTPsCpp;

  Local<Array> BTPsArray = info[1].As<Array>();
  for (unsigned int i = 0; i < BTPsArray->Length(); i++){
    String::Utf8Value strBTPs(Nan::Get(BTPsArray, i).ToLocalChecked()->ToString());
    BTPsCpp.push_back(strdup(*strBTPs));
  }

  // convert js argument to c++ type
  std::vector<double>OutstandingsCpp;

  Local<Array> OutstandingsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < OutstandingsArray->Length(); i++){
    OutstandingsCpp.push_back(Nan::To<double>(Nan::Get(OutstandingsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>PricesCpp;

  Local<Array> PricesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < PricesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(PricesArray, i).ToLocalChecked()).FromJust()));
    PricesCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RendistatoBasketWorker(
    callback
    ,ObjectIDCpp
    ,BTPsCpp
    ,OutstandingsCpp
    ,PricesCpp
  ));

}

//RendistatoBasketWorker::~RendistatoBasketWorker(){
//
//}

//RendistatoBasketWorker::Destroy(){
//
//}

void RendistatoCalculatorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(RendistatoBasketLibObjPtr, mRendistatoBasket,
      QuantLibAddin::RendistatoBasket, QuantLib::RendistatoBasket)


  // convert object IDs into library objects
  OH_GET_REFERENCE(EuriborLibObjPtr, mEuribor,
      QuantLibAddin::Euribor, QuantLib::Euribor)


  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRendistatoCalculator(
          mObjectID,
          mRendistatoBasket,
          mEuribor,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RendistatoCalculator(
          valueObject,
          RendistatoBasketLibObjPtr,
          EuriborLibObjPtr,
          YieldCurveLibObj,
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

void RendistatoCalculatorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoCalculator) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("RendistatoBasket is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Euribor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strRendistatoBasket(info[1]->ToString());
  string RendistatoBasketCpp(strdup(*strRendistatoBasket));

  // convert js argument to c++ type
  String::Utf8Value strEuribor(info[2]->ToString());
  string EuriborCpp(strdup(*strEuribor));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[3]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RendistatoCalculatorWorker(
    callback
    ,ObjectIDCpp
    ,RendistatoBasketCpp
    ,EuriborCpp
    ,YieldCurveCpp
  ));

}

//RendistatoCalculatorWorker::~RendistatoCalculatorWorker(){
//
//}

//RendistatoCalculatorWorker::Destroy(){
//
//}

void RendistatoEquivalentSwapLengthQuoteWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(RendistatoCalculatorLibObjPtr, mRendistatoCalculator,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRendistatoEquivalentSwapLengthQuote(
          mObjectID,
          mRendistatoCalculator,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RendistatoEquivalentSwapLengthQuote(
          valueObject,
          RendistatoCalculatorLibObjPtr,
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

void RendistatoEquivalentSwapLengthQuoteWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoEquivalentSwapLengthQuote) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("RendistatoCalculator is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strRendistatoCalculator(info[1]->ToString());
  string RendistatoCalculatorCpp(strdup(*strRendistatoCalculator));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RendistatoEquivalentSwapLengthQuoteWorker(
    callback
    ,ObjectIDCpp
    ,RendistatoCalculatorCpp
  ));

}

//RendistatoEquivalentSwapLengthQuoteWorker::~RendistatoEquivalentSwapLengthQuoteWorker(){
//
//}

//RendistatoEquivalentSwapLengthQuoteWorker::Destroy(){
//
//}

void RendistatoEquivalentSwapSpreadQuoteWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(RendistatoCalculatorLibObjPtr, mRendistatoCalculator,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRendistatoEquivalentSwapSpreadQuote(
          mObjectID,
          mRendistatoCalculator,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RendistatoEquivalentSwapSpreadQuote(
          valueObject,
          RendistatoCalculatorLibObjPtr,
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

void RendistatoEquivalentSwapSpreadQuoteWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoEquivalentSwapSpreadQuote) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("RendistatoCalculator is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strRendistatoCalculator(info[1]->ToString());
  string RendistatoCalculatorCpp(strdup(*strRendistatoCalculator));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RendistatoEquivalentSwapSpreadQuoteWorker(
    callback
    ,ObjectIDCpp
    ,RendistatoCalculatorCpp
  ));

}

//RendistatoEquivalentSwapSpreadQuoteWorker::~RendistatoEquivalentSwapSpreadQuoteWorker(){
//
//}

//RendistatoEquivalentSwapSpreadQuoteWorker::Destroy(){
//
//}

void RendistatoBasketSizeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoBasket, QuantLib::RendistatoBasket)


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

void RendistatoBasketSizeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoBasketSize) {

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
  Nan::AsyncQueueWorker(new RendistatoBasketSizeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoBasketSizeWorker::~RendistatoBasketSizeWorker(){
//
//}

//RendistatoBasketSizeWorker::Destroy(){
//
//}

void RendistatoBasketOutstandingWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoBasket, QuantLib::RendistatoBasket)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->outstanding(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoBasketOutstandingWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoBasketOutstanding) {

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
  Nan::AsyncQueueWorker(new RendistatoBasketOutstandingWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoBasketOutstandingWorker::~RendistatoBasketOutstandingWorker(){
//
//}

//RendistatoBasketOutstandingWorker::Destroy(){
//
//}

void RendistatoBasketOutstandingsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoBasket, QuantLib::RendistatoBasket)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->outstandings(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoBasketOutstandingsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RendistatoBasketOutstandings) {

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
  Nan::AsyncQueueWorker(new RendistatoBasketOutstandingsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoBasketOutstandingsWorker::~RendistatoBasketOutstandingsWorker(){
//
//}

//RendistatoBasketOutstandingsWorker::Destroy(){
//
//}

void RendistatoBasketWeightsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoBasket, QuantLib::RendistatoBasket)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->weights(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoBasketWeightsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RendistatoBasketWeights) {

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
  Nan::AsyncQueueWorker(new RendistatoBasketWeightsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoBasketWeightsWorker::~RendistatoBasketWeightsWorker(){
//
//}

//RendistatoBasketWeightsWorker::Destroy(){
//
//}

void RendistatoCalculatorYieldWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->yield(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoCalculatorYield) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorYieldWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorYieldWorker::~RendistatoCalculatorYieldWorker(){
//
//}

//RendistatoCalculatorYieldWorker::Destroy(){
//
//}

void RendistatoCalculatorDurationWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->duration(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorDurationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoCalculatorDuration) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorDurationWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorDurationWorker::~RendistatoCalculatorDurationWorker(){
//
//}

//RendistatoCalculatorDurationWorker::Destroy(){
//
//}

void RendistatoCalculatorYieldsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->yields(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorYieldsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RendistatoCalculatorYields) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorYieldsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorYieldsWorker::~RendistatoCalculatorYieldsWorker(){
//
//}

//RendistatoCalculatorYieldsWorker::Destroy(){
//
//}

void RendistatoCalculatorDurationsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->durations(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorDurationsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RendistatoCalculatorDurations) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorDurationsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorDurationsWorker::~RendistatoCalculatorDurationsWorker(){
//
//}

//RendistatoCalculatorDurationsWorker::Destroy(){
//
//}

void RendistatoCalculatorSwapLengthsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->swapLengths(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorSwapLengthsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RendistatoCalculatorSwapLengths) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorSwapLengthsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorSwapLengthsWorker::~RendistatoCalculatorSwapLengthsWorker(){
//
//}

//RendistatoCalculatorSwapLengthsWorker::Destroy(){
//
//}

void RendistatoCalculatorSwapRatesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->swapRates(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorSwapRatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RendistatoCalculatorSwapRates) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorSwapRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorSwapRatesWorker::~RendistatoCalculatorSwapRatesWorker(){
//
//}

//RendistatoCalculatorSwapRatesWorker::Destroy(){
//
//}

void RendistatoCalculatorSwapYieldsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->swapYields(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorSwapYieldsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RendistatoCalculatorSwapYields) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorSwapYieldsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorSwapYieldsWorker::~RendistatoCalculatorSwapYieldsWorker(){
//
//}

//RendistatoCalculatorSwapYieldsWorker::Destroy(){
//
//}

void RendistatoCalculatorSwapDurationsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->swapDurations(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorSwapDurationsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RendistatoCalculatorSwapDurations) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorSwapDurationsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorSwapDurationsWorker::~RendistatoCalculatorSwapDurationsWorker(){
//
//}

//RendistatoCalculatorSwapDurationsWorker::Destroy(){
//
//}

void RendistatoCalculatorEquivalentSwapRateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->equivalentSwapRate(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorEquivalentSwapRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoCalculatorEquivalentSwapRate) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorEquivalentSwapRateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorEquivalentSwapRateWorker::~RendistatoCalculatorEquivalentSwapRateWorker(){
//
//}

//RendistatoCalculatorEquivalentSwapRateWorker::Destroy(){
//
//}

void RendistatoCalculatorEquivalentSwapYieldWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->equivalentSwapYield(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorEquivalentSwapYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoCalculatorEquivalentSwapYield) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorEquivalentSwapYieldWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorEquivalentSwapYieldWorker::~RendistatoCalculatorEquivalentSwapYieldWorker(){
//
//}

//RendistatoCalculatorEquivalentSwapYieldWorker::Destroy(){
//
//}

void RendistatoCalculatorEquivalentSwapDurationWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->equivalentSwapDuration(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorEquivalentSwapDurationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoCalculatorEquivalentSwapDuration) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorEquivalentSwapDurationWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorEquivalentSwapDurationWorker::~RendistatoCalculatorEquivalentSwapDurationWorker(){
//
//}

//RendistatoCalculatorEquivalentSwapDurationWorker::Destroy(){
//
//}

void RendistatoCalculatorEquivalentSwapSpreadWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->equivalentSwapSpread(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorEquivalentSwapSpreadWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoCalculatorEquivalentSwapSpread) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorEquivalentSwapSpreadWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorEquivalentSwapSpreadWorker::~RendistatoCalculatorEquivalentSwapSpreadWorker(){
//
//}

//RendistatoCalculatorEquivalentSwapSpreadWorker::Destroy(){
//
//}

void RendistatoCalculatorEquivalentSwapLengthWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RendistatoCalculator, QuantLib::RendistatoCalculator)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->equivalentSwapLength(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RendistatoCalculatorEquivalentSwapLengthWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RendistatoCalculatorEquivalentSwapLength) {

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
  Nan::AsyncQueueWorker(new RendistatoCalculatorEquivalentSwapLengthWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RendistatoCalculatorEquivalentSwapLengthWorker::~RendistatoCalculatorEquivalentSwapLengthWorker(){
//
//}

//RendistatoCalculatorEquivalentSwapLengthWorker::Destroy(){
//
//}
 