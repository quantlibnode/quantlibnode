/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "processes.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/processes.hpp>
#include <qlo/volatilities.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void GeneralizedBlackScholesProcessWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(BlackVolIDLibObjPtr, mBlackVolID,
      QuantLibAddin::BlackVolTermStructure, QuantLib::BlackVolTermStructure)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlGeneralizedBlackScholesProcess(
          mObjectID,
          mBlackVolID,
          mUnderlying,
          mDayCounter,
          mSettlementDate,
          mRiskFreeRate,
          mDividendYield,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::GeneralizedBlackScholesProcess(
          valueObject,
          BlackVolIDLibObjPtr,
          mUnderlying,
          DayCounterEnum,
          SettlementDateLib,
          mRiskFreeRate,
          mDividendYield,
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

void GeneralizedBlackScholesProcessWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GeneralizedBlackScholesProcess) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("BlackVolID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Underlying is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("RiskFreeRate is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("DividendYield is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strBlackVolID(info[1]->ToString());
  string BlackVolIDCpp(strdup(*strBlackVolID));

  // convert js argument to c++ type
  double UnderlyingCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[3]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  double RiskFreeRateCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double DividendYieldCpp = Nan::To<double>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GeneralizedBlackScholesProcessWorker(
    callback
    ,ObjectIDCpp
    ,BlackVolIDCpp
    ,UnderlyingCpp
    ,DayCounterCpp
    ,SettlementDateCpp
    ,RiskFreeRateCpp
    ,DividendYieldCpp
  ));

}

//GeneralizedBlackScholesProcessWorker::~GeneralizedBlackScholesProcessWorker(){
//
//}

//void GeneralizedBlackScholesProcessWorker::Destroy(){
//
//}
 