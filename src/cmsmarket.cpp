// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "cmsmarket.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/quote.hpp>
#include <qlo/cmsmarket.hpp>
#include <qlo/conundrumpricer.hpp>
#include <qlo/indexes/iborindex.hpp>
#include <qlo/indexes/swapindex.hpp>
#include <qlo/termstructures.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/indexes/swapindex.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void CmsMarketWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> SwapLengthsLib;


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::SwapIndex> > SwapIndexesLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::SwapIndex, QuantLib::SwapIndex>(mSwapIndexes);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert object IDs into library objects
  std::vector< std::vector< QuantLib::Handle<QuantLib::Quote> > > BidAskSpreadsLibObj =
      ObjectHandler::matrix::convert2< QuantLib::Handle<QuantLib::Quote> >(mBidAskSpreads, "BidAskSpreads");


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::CmsCouponPricer> > CmsCouponPricersLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::CmsCouponPricer, QuantLib::CmsCouponPricer>(mCmsCouponPricers);


  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCmsMarket(
          mObjectID,
          mSwapLengths,
          mSwapIndexes,
          mIborIndex,
          mBidAskSpreads,
          mCmsCouponPricers,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CmsMarket(
          valueObject,
          SwapLengthsLib,
          SwapIndexesLibObjPtr,
          IborIndexLibObjPtr,
          BidAskSpreadsLibObj,
          CmsCouponPricersLibObjPtr,
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

void CmsMarketWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CmsMarket) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("SwapLengths is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("SwapIndexes is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("BidAskSpreads is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("CmsCouponPricers is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>SwapLengthsCpp;

  Local<Array> SwapLengthsArray = info[1].As<Array>();
  for (unsigned int i = 0; i < SwapLengthsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(SwapLengthsArray, i).ToLocalChecked()).FromJust()));
    SwapLengthsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<string>SwapIndexesCpp;

  Local<Array> SwapIndexesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < SwapIndexesArray->Length(); i++){
    String::Utf8Value strSwapIndexes(Nan::Get(SwapIndexesArray, i).ToLocalChecked()->ToString());
    SwapIndexesCpp.push_back(strdup(*strSwapIndexes));
  }

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[3]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  std::vector< std::vector<ObjectHandler::property_t> >BidAskSpreadsCpp;

  Local<Array> BidAskSpreadsMatrix = info[4].As<Array>();
  for (unsigned int i = 0; i < BidAskSpreadsMatrix->Length(); i++){
	  Local<Array> BidAskSpreadsArray = BidAskSpreadsMatrix->Get(i).As<Array>();
	  std::vector<ObjectHandler::property_t> tmp;
	  for (unsigned int j = 0; j < BidAskSpreadsArray->Length(); j++){
      ObjectHandler::property_t temp =
          ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(BidAskSpreadsArray, j).ToLocalChecked()).FromJust()));
		  tmp.push_back(temp);
	  }
	  BidAskSpreadsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<string>CmsCouponPricersCpp;

  Local<Array> CmsCouponPricersArray = info[5].As<Array>();
  for (unsigned int i = 0; i < CmsCouponPricersArray->Length(); i++){
    String::Utf8Value strCmsCouponPricers(Nan::Get(CmsCouponPricersArray, i).ToLocalChecked()->ToString());
    CmsCouponPricersCpp.push_back(strdup(*strCmsCouponPricers));
  }

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[6]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CmsMarketWorker(
    callback
    ,ObjectIDCpp
    ,SwapLengthsCpp
    ,SwapIndexesCpp
    ,IborIndexCpp
    ,BidAskSpreadsCpp
    ,CmsCouponPricersCpp
    ,YieldCurveCpp
  ));

}

//CmsMarketWorker::~CmsMarketWorker(){
//
//}

//CmsMarketWorker::Destroy(){
//
//}

void BrowseCmsMarketWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CmsMarket)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->getCmsMarket(
      );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BrowseCmsMarketWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpMatrix = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Local<Array> tmpArray = Nan::New<Array>(mReturnValue[i].size());
      for (unsigned int j = 0; j < mReturnValue[i].size(); j++) {
        Nan::Set(tmpArray,j,Nan::New<String>(mReturnValue[i][j]).ToLocalChecked());
      }
      Nan::Set(tmpMatrix,i,tmpArray);
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpMatrix
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BrowseCmsMarket) {

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
  Nan::AsyncQueueWorker(new BrowseCmsMarketWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BrowseCmsMarketWorker::~BrowseCmsMarketWorker(){
//
//}

//BrowseCmsMarketWorker::Destroy(){
//
//}
 