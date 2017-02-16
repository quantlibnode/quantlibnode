/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "accountingengines.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/accountingengines.hpp>
#include <qlo/marketmodelevolvers.hpp>
#include <qlo/products.hpp>
#include <qlo/sequencestatistics.hpp>
#include <ql/models/marketmodels/accountingengine.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void AccountingEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(MarketModelEvolverLibObjPtr, mMarketModelEvolver,
      QuantLibAddin::MarketModelEvolver, QuantLib::MarketModelEvolver)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(ProductLibObj, mProduct,
      QuantLibAddin::MarketModelMultiProduct, QuantLib::MarketModelMultiProduct)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlAccountingEngine(
          mObjectID,
          mMarketModelEvolver,
          mProduct,
          mInitialNumeraireValue,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::AccountingEngine(
          valueObject,
          MarketModelEvolverLibObjPtr,
          ProductLibObj,
          mInitialNumeraireValue,
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

void AccountingEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AccountingEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("MarketModelEvolver is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Product is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("InitialNumeraireValue is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strMarketModelEvolver(info[1]->ToString());
  string MarketModelEvolverCpp(strdup(*strMarketModelEvolver));

  // convert js argument to c++ type
  String::Utf8Value strProduct(info[2]->ToString());
  string ProductCpp(strdup(*strProduct));

  // convert js argument to c++ type
  double InitialNumeraireValueCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AccountingEngineWorker(
    callback
    ,ObjectIDCpp
    ,MarketModelEvolverCpp
    ,ProductCpp
    ,InitialNumeraireValueCpp
  ));

}

//AccountingEngineWorker::~AccountingEngineWorker(){
//
//}

//void AccountingEngineWorker::Destroy(){
//
//}

void AccountingEngineMultiplePathValuesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING_NONCONST(SequenceStatsLibObj, mSequenceStats,
      QuantLibAddin::SequenceStatisticsInc, QuantLib::SequenceStatisticsInc)

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AccountingEngine, QuantLib::AccountingEngine)


  // invoke the member function
  ObjectIDLibObjPtr->multiplePathValues(
        SequenceStatsLibObj
        ,
         mPaths
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AccountingEngineMultiplePathValuesWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AccountingEngineMultiplePathValues) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("SequenceStats is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Paths is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strSequenceStats(info[1]->ToString());
  string SequenceStatsCpp(strdup(*strSequenceStats));

  // convert js argument to c++ type
  long PathsCpp = Nan::To<int32_t>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AccountingEngineMultiplePathValuesWorker(
    callback
    ,ObjectIDCpp
    ,SequenceStatsCpp
    ,PathsCpp
  ));

}

//AccountingEngineMultiplePathValuesWorker::~AccountingEngineMultiplePathValuesWorker(){
//
//}

//void AccountingEngineMultiplePathValuesWorker::Destroy(){
//
//}
 