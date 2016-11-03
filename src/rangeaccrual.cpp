/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "rangeaccrual.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/rangeaccrual.hpp>
#include <qlo/indexes/iborindex.hpp>
#include <qlo/schedule.hpp>
#include <qlo/smilesection.hpp>
#include <qlo/termstructures.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>
#include <ql/cashflows/rangeaccrual.hpp>
#include <ql/indexes/iborindex.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void RangeAccrualFloatersCouponWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date PaymentDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mPaymentDate, "PaymentDate");


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EndDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEndDate, "EndDate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCountIDEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCountID);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodStartLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodStart, "RefPeriodStart");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodEndLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodEnd, "RefPeriodEnd");


  // convert object IDs into library objects
  OH_GET_REFERENCE(ObserSchedIDLibObjPtr, mObserSchedID,
      QuantLibAddin::Schedule, QuantLib::Schedule)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRangeAccrualFloatersCoupon(
          mObjectID,
          mNominal,
          mPaymentDate,
          mIborIndex,
          mStartDate,
          mEndDate,
          mFixingDays,
          mDayCountID,
          mGearings,
          mSpreads,
          mRefPeriodStart,
          mRefPeriodEnd,
          mObserSchedID,
          mLowerTrigger,
          mUpperTrigger,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RangeAccrualFloatersCoupon(
          valueObject,
          mNominal,
          PaymentDateLib,
          IborIndexLibObjPtr,
          StartDateLib,
          EndDateLib,
          mFixingDays,
          DayCountIDEnum,
          mGearings,
          mSpreads,
          RefPeriodStartLib,
          RefPeriodEndLib,
          ObserSchedIDLibObjPtr,
          mLowerTrigger,
          mUpperTrigger,
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

void RangeAccrualFloatersCouponWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RangeAccrualFloatersCoupon) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Nominal is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("FixingDays is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("DayCountID is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Gearings is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("Spreads is required.");
  }
  if (info.Length() == 12 || !info[12]->IsString()) {
      return Nan::ThrowError("ObserSchedID is required.");
  }
  if (info.Length() == 13 || !info[13]->IsNumber()) {
      return Nan::ThrowError("LowerTrigger is required.");
  }
  if (info.Length() == 14 || !info[14]->IsNumber()) {
      return Nan::ThrowError("UpperTrigger is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double NominalCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t PaymentDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[3]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t EndDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

  // convert js argument to c++ type
  long FixingDaysCpp = Nan::To<int32_t>(info[6]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCountID(info[7]->ToString());
  string DayCountIDCpp(strdup(*strDayCountID));

  // convert js argument to c++ type
  double GearingsCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  double SpreadsCpp = Nan::To<double>(info[9]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodStartCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[10]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodEndCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[11]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strObserSchedID(info[12]->ToString());
  string ObserSchedIDCpp(strdup(*strObserSchedID));

  // convert js argument to c++ type
  double LowerTriggerCpp = Nan::To<double>(info[13]).FromJust();

  // convert js argument to c++ type
  double UpperTriggerCpp = Nan::To<double>(info[14]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[15].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RangeAccrualFloatersCouponWorker(
    callback
    ,ObjectIDCpp
    ,NominalCpp
    ,PaymentDateCpp
    ,IborIndexCpp
    ,StartDateCpp
    ,EndDateCpp
    ,FixingDaysCpp
    ,DayCountIDCpp
    ,GearingsCpp
    ,SpreadsCpp
    ,RefPeriodStartCpp
    ,RefPeriodEndCpp
    ,ObserSchedIDCpp
    ,LowerTriggerCpp
    ,UpperTriggerCpp
  ));

}

//RangeAccrualFloatersCouponWorker::~RangeAccrualFloatersCouponWorker(){
//
//}

//void RangeAccrualFloatersCouponWorker::Destroy(){
//
//}

void RangeAccrualFloatersCouponFromLegWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(RangeAccrualLegLibObj, mRangeAccrualLeg,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size PositionLib;
  QuantLibAddin::cppToLibrary(mPosition, PositionLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRangeAccrualFloatersCouponFromLeg(
          mObjectID,
          mRangeAccrualLeg,
          mPosition,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RangeAccrualFloatersCoupon(
          valueObject,
          RangeAccrualLegLibObj,
          PositionLib,
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

void RangeAccrualFloatersCouponFromLegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RangeAccrualFloatersCouponFromLeg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("RangeAccrualLeg is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Position is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strRangeAccrualLeg(info[1]->ToString());
  string RangeAccrualLegCpp(strdup(*strRangeAccrualLeg));

  // convert js argument to c++ type
  long PositionCpp = Nan::To<int32_t>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RangeAccrualFloatersCouponFromLegWorker(
    callback
    ,ObjectIDCpp
    ,RangeAccrualLegCpp
    ,PositionCpp
  ));

}

//RangeAccrualFloatersCouponFromLegWorker::~RangeAccrualFloatersCouponFromLegWorker(){
//
//}

//void RangeAccrualFloatersCouponFromLegWorker::Destroy(){
//
//}

void RangeAccrualPricerByBgmWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(SmileOnStartDateIDLibObjPtr, mSmileOnStartDateID,
      QuantLibAddin::SmileSection, QuantLib::SmileSection)


  // convert object IDs into library objects
  OH_GET_REFERENCE(SmileOnEndDateIDLibObjPtr, mSmileOnEndDateID,
      QuantLibAddin::SmileSection, QuantLib::SmileSection)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRangeAccrualPricerByBgm(
          mObjectID,
          mCorrelation,
          mSmileOnStartDateID,
          mSmileOnEndDateID,
          mWithSmile,
          mByCallSpread,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RangeAccrualPricerByBgm(
          valueObject,
          mCorrelation,
          SmileOnStartDateIDLibObjPtr,
          SmileOnEndDateIDLibObjPtr,
          mWithSmile,
          mByCallSpread,
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

void RangeAccrualPricerByBgmWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RangeAccrualPricerByBgm) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Correlation is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("SmileOnStartDateID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("SmileOnEndDateID is required.");
  }
  if (info.Length() == 4 || !info[4]->IsBoolean()) {
      return Nan::ThrowError("WithSmile is required.");
  }
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("ByCallSpread is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double CorrelationCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strSmileOnStartDateID(info[2]->ToString());
  string SmileOnStartDateIDCpp(strdup(*strSmileOnStartDateID));

  // convert js argument to c++ type
  String::Utf8Value strSmileOnEndDateID(info[3]->ToString());
  string SmileOnEndDateIDCpp(strdup(*strSmileOnEndDateID));

  // convert js argument to c++ type
  bool WithSmileCpp = Nan::To<bool>(info[4]).FromJust();

  // convert js argument to c++ type
  bool ByCallSpreadCpp = Nan::To<bool>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RangeAccrualPricerByBgmWorker(
    callback
    ,ObjectIDCpp
    ,CorrelationCpp
    ,SmileOnStartDateIDCpp
    ,SmileOnEndDateIDCpp
    ,WithSmileCpp
    ,ByCallSpreadCpp
  ));

}

//RangeAccrualPricerByBgmWorker::~RangeAccrualPricerByBgmWorker(){
//
//}

//void RangeAccrualPricerByBgmWorker::Destroy(){
//
//}

void RangeAccrualFloatersCouponSetPricerWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RangeAccrualFloatersCoupon, QuantLib::RangeAccrualFloatersCoupon)


  // convert object IDs into library objects
  OH_GET_REFERENCE(RangeAccrualPricerLibObjPtr, mRangeAccrualPricer,
      QuantLibAddin::RangeAccrualPricer, QuantLib::RangeAccrualPricer)

     
  // invoke the member function
  ObjectIDLibObjPtr->setPricer(
        RangeAccrualPricerLibObjPtr
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RangeAccrualFloatersCouponSetPricerWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RangeAccrualFloatersCouponSetPricer) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("RangeAccrualPricer is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strRangeAccrualPricer(info[1]->ToString());
  string RangeAccrualPricerCpp(strdup(*strRangeAccrualPricer));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RangeAccrualFloatersCouponSetPricerWorker(
    callback
    ,ObjectIDCpp
    ,RangeAccrualPricerCpp
  ));

}

//RangeAccrualFloatersCouponSetPricerWorker::~RangeAccrualFloatersCouponSetPricerWorker(){
//
//}

//void RangeAccrualFloatersCouponSetPricerWorker::Destroy(){
//
//}

void RangeAccrualFloatersCouponObservationDatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RangeAccrualFloatersCoupon, QuantLib::RangeAccrualFloatersCoupon)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Date> returnValue = ObjectIDLibObjPtr->observationDates(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RangeAccrualFloatersCouponObservationDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RangeAccrualFloatersCouponObservationDates) {

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
  Nan::AsyncQueueWorker(new RangeAccrualFloatersCouponObservationDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RangeAccrualFloatersCouponObservationDatesWorker::~RangeAccrualFloatersCouponObservationDatesWorker(){
//
//}

//void RangeAccrualFloatersCouponObservationDatesWorker::Destroy(){
//
//}

void RangeAccrualFloatersCouponStarDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RangeAccrualFloatersCoupon, QuantLib::RangeAccrualFloatersCoupon)

     
  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->accrualStartDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RangeAccrualFloatersCouponStarDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RangeAccrualFloatersCouponStarDate) {

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
  Nan::AsyncQueueWorker(new RangeAccrualFloatersCouponStarDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RangeAccrualFloatersCouponStarDateWorker::~RangeAccrualFloatersCouponStarDateWorker(){
//
//}

//void RangeAccrualFloatersCouponStarDateWorker::Destroy(){
//
//}

void RangeAccrualFloatersCouponEndDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RangeAccrualFloatersCoupon, QuantLib::RangeAccrualFloatersCoupon)

     
  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->accrualEndDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RangeAccrualFloatersCouponEndDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RangeAccrualFloatersCouponEndDate) {

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
  Nan::AsyncQueueWorker(new RangeAccrualFloatersCouponEndDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RangeAccrualFloatersCouponEndDateWorker::~RangeAccrualFloatersCouponEndDateWorker(){
//
//}

//void RangeAccrualFloatersCouponEndDateWorker::Destroy(){
//
//}

void RangeAccrualFloatersCouponObservationsNoWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RangeAccrualFloatersCoupon, QuantLib::RangeAccrualFloatersCoupon)

     
  // invoke the member function
  QuantLib::Size returnValue = ObjectIDLibObjPtr->observationsNo(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RangeAccrualFloatersCouponObservationsNoWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RangeAccrualFloatersCouponObservationsNo) {

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
  Nan::AsyncQueueWorker(new RangeAccrualFloatersCouponObservationsNoWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RangeAccrualFloatersCouponObservationsNoWorker::~RangeAccrualFloatersCouponObservationsNoWorker(){
//
//}

//void RangeAccrualFloatersCouponObservationsNoWorker::Destroy(){
//
//}

void RangeAccrualFloatersPriceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RangeAccrualFloatersCoupon, QuantLib::RangeAccrualFloatersCoupon)


  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->price(
        YieldCurveLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RangeAccrualFloatersPriceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RangeAccrualFloatersPrice) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RangeAccrualFloatersPriceWorker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
  ));

}

//RangeAccrualFloatersPriceWorker::~RangeAccrualFloatersPriceWorker(){
//
//}

//void RangeAccrualFloatersPriceWorker::Destroy(){
//
//}

void SimpleFloaterPriceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::RangeAccrualFloatersCoupon, QuantLib::RangeAccrualFloatersCoupon)


  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->priceWithoutOptionality(
        YieldCurveLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SimpleFloaterPriceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SimpleFloaterPrice) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SimpleFloaterPriceWorker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
  ));

}

//SimpleFloaterPriceWorker::~SimpleFloaterPriceWorker(){
//
//}

//void SimpleFloaterPriceWorker::Destroy(){
//
//}
 