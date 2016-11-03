/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "bonds.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/indexes/iborindex.hpp>
#include <qlo/indexes/swapindex.hpp>
#include <qlo/schedule.hpp>
#include <qlo/bonds.hpp>
#include <qlo/termstructures.hpp>
#include <qlo/couponvectors.hpp>
#include <ql/instruments/bond.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>
#include <ql/pricingengines/bond/bondfunctions.hpp>
#include <ql/currency.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/indexes/swapindex.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void FixedRateBondWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Currency CurrencyEnum =
      ObjectHandler::Create<QuantLib::Currency>()(mCurrency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SettlementDaysLib;
  QuantLibAddin::cppToLibrary(mSettlementDays, SettlementDaysLib);


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date IssueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mIssueDate, "IssueDate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar PaymentCalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mPaymentCalendar);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFixedRateBond(
          mObjectID,
          mDescription,
          mCurrency,
          mSettlementDays,
          mFaceAmount,
          mScheduleID,
          mCoupons,
          mDayCounter,
          mPaymentBDC,
          mRedemption,
          mIssueDate,
          mPaymentCalendar,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FixedRateBond(
          valueObject,
          mDescription,
          CurrencyEnum,
          SettlementDaysLib,
          mFaceAmount,
          ScheduleIDLibObjPtr,
          mCoupons,
          DayCounterEnum,
          PaymentBDCEnum,
          mRedemption,
          IssueDateLib,
          PaymentCalendarEnum,
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

void FixedRateBondWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FixedRateBond) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Description is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Currency is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("SettlementDays is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("FaceAmount is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("Coupons is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("Redemption is required.");
  }
  if (info.Length() == 11 || !info[11]->IsString()) {
      return Nan::ThrowError("PaymentCalendar is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDescription(info[1]->ToString());
  string DescriptionCpp(strdup(*strDescription));

  // convert js argument to c++ type
  String::Utf8Value strCurrency(info[2]->ToString());
  string CurrencyCpp(strdup(*strCurrency));

  // convert js argument to c++ type
  long SettlementDaysCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  double FaceAmountCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[5]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<double>CouponsCpp;

  Local<Array> CouponsArray = info[6].As<Array>();
  for (unsigned int i = 0; i < CouponsArray->Length(); i++){
    CouponsCpp.push_back(Nan::To<double>(Nan::Get(CouponsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[7]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[8]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  double RedemptionCpp = Nan::To<double>(info[9]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t IssueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[10]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strPaymentCalendar(info[11]->ToString());
  string PaymentCalendarCpp(strdup(*strPaymentCalendar));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[12].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FixedRateBondWorker(
    callback
    ,ObjectIDCpp
    ,DescriptionCpp
    ,CurrencyCpp
    ,SettlementDaysCpp
    ,FaceAmountCpp
    ,ScheduleIDCpp
    ,CouponsCpp
    ,DayCounterCpp
    ,PaymentBDCCpp
    ,RedemptionCpp
    ,IssueDateCpp
    ,PaymentCalendarCpp
  ));

}

//FixedRateBondWorker::~FixedRateBondWorker(){
//
//}

//void FixedRateBondWorker::Destroy(){
//
//}

void FixedRateBond2Worker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Currency CurrencyEnum =
      ObjectHandler::Create<QuantLib::Currency>()(mCurrency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SettlementDaysLib;
  QuantLibAddin::cppToLibrary(mSettlementDays, SettlementDaysLib);


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::InterestRate> > CouponsLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::InterestRate, QuantLib::InterestRate>(mCoupons);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date IssueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mIssueDate, "IssueDate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar PaymentCalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mPaymentCalendar);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFixedRateBond2(
          mObjectID,
          mDescription,
          mCurrency,
          mSettlementDays,
          mFaceAmount,
          mScheduleID,
          mCoupons,
          mPaymentBDC,
          mRedemption,
          mIssueDate,
          mPaymentCalendar,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FixedRateBond(
          valueObject,
          mDescription,
          CurrencyEnum,
          SettlementDaysLib,
          mFaceAmount,
          ScheduleIDLibObjPtr,
          CouponsLibObjPtr,
          PaymentBDCEnum,
          mRedemption,
          IssueDateLib,
          PaymentCalendarEnum,
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

void FixedRateBond2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FixedRateBond2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Description is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Currency is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("SettlementDays is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("FaceAmount is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("Coupons is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Redemption is required.");
  }
  if (info.Length() == 10 || !info[10]->IsString()) {
      return Nan::ThrowError("PaymentCalendar is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDescription(info[1]->ToString());
  string DescriptionCpp(strdup(*strDescription));

  // convert js argument to c++ type
  String::Utf8Value strCurrency(info[2]->ToString());
  string CurrencyCpp(strdup(*strCurrency));

  // convert js argument to c++ type
  long SettlementDaysCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  double FaceAmountCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[5]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<string>CouponsCpp;

  Local<Array> CouponsArray = info[6].As<Array>();
  for (unsigned int i = 0; i < CouponsArray->Length(); i++){
    String::Utf8Value strCoupons(Nan::Get(CouponsArray, i).ToLocalChecked()->ToString());
    CouponsCpp.push_back(strdup(*strCoupons));
  }

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[7]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  double RedemptionCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t IssueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[9]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strPaymentCalendar(info[10]->ToString());
  string PaymentCalendarCpp(strdup(*strPaymentCalendar));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[11].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FixedRateBond2Worker(
    callback
    ,ObjectIDCpp
    ,DescriptionCpp
    ,CurrencyCpp
    ,SettlementDaysCpp
    ,FaceAmountCpp
    ,ScheduleIDCpp
    ,CouponsCpp
    ,PaymentBDCCpp
    ,RedemptionCpp
    ,IssueDateCpp
    ,PaymentCalendarCpp
  ));

}

//FixedRateBond2Worker::~FixedRateBond2Worker(){
//
//}

//void FixedRateBond2Worker::Destroy(){
//
//}

void FloatingRateBondWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Currency CurrencyEnum =
      ObjectHandler::Create<QuantLib::Currency>()(mCurrency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SettlementDaysLib;
  QuantLibAddin::cppToLibrary(mSettlementDays, SettlementDaysLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural FixingDaysLib = ObjectHandler::convert2<long>(
      mFixingDays, "FixingDays", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date IssueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mIssueDate, "IssueDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFloatingRateBond(
          mObjectID,
          mDescription,
          mCurrency,
          mSettlementDays,
          mPaymentBDC,
          mFaceAmount,
          mScheduleID,
          mFixingDays,
          mIsInArrears,
          mDayCounter,
          mFloors,
          mGearings,
          mIborIndex,
          mSpreads,
          mCaps,
          mRedemption,
          mIssueDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FloatingRateBond(
          valueObject,
          mDescription,
          CurrencyEnum,
          SettlementDaysLib,
          PaymentBDCEnum,
          mFaceAmount,
          ScheduleIDLibObjPtr,
          FixingDaysLib,
          mIsInArrears,
          DayCounterEnum,
          mFloors,
          mGearings,
          IborIndexLibObjPtr,
          mSpreads,
          mCaps,
          mRedemption,
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

void FloatingRateBondWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FloatingRateBond) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Description is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Currency is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("SettlementDays is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("FaceAmount is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 8 || !info[8]->IsBoolean()) {
      return Nan::ThrowError("IsInArrears is required.");
  }
  if (info.Length() == 9 || !info[9]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("Floors is required.");
  }
  if (info.Length() == 11 || !info[11]->IsArray()) {
      return Nan::ThrowError("Gearings is required.");
  }
  if (info.Length() == 12 || !info[12]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 13 || !info[13]->IsArray()) {
      return Nan::ThrowError("Spreads is required.");
  }
  if (info.Length() == 14 || !info[14]->IsArray()) {
      return Nan::ThrowError("Caps is required.");
  }
  if (info.Length() == 15 || !info[15]->IsNumber()) {
      return Nan::ThrowError("Redemption is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDescription(info[1]->ToString());
  string DescriptionCpp(strdup(*strDescription));

  // convert js argument to c++ type
  String::Utf8Value strCurrency(info[2]->ToString());
  string CurrencyCpp(strdup(*strCurrency));

  // convert js argument to c++ type
  long SettlementDaysCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[4]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  double FaceAmountCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[6]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  ObjectHandler::property_t FixingDaysCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

  // convert js argument to c++ type
  bool IsInArrearsCpp = Nan::To<bool>(info[8]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[9]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  std::vector<double>FloorsCpp;

  Local<Array> FloorsArray = info[10].As<Array>();
  for (unsigned int i = 0; i < FloorsArray->Length(); i++){
    FloorsCpp.push_back(Nan::To<double>(Nan::Get(FloorsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>GearingsCpp;

  Local<Array> GearingsArray = info[11].As<Array>();
  for (unsigned int i = 0; i < GearingsArray->Length(); i++){
    GearingsCpp.push_back(Nan::To<double>(Nan::Get(GearingsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[12]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  std::vector<double>SpreadsCpp;

  Local<Array> SpreadsArray = info[13].As<Array>();
  for (unsigned int i = 0; i < SpreadsArray->Length(); i++){
    SpreadsCpp.push_back(Nan::To<double>(Nan::Get(SpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>CapsCpp;

  Local<Array> CapsArray = info[14].As<Array>();
  for (unsigned int i = 0; i < CapsArray->Length(); i++){
    CapsCpp.push_back(Nan::To<double>(Nan::Get(CapsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double RedemptionCpp = Nan::To<double>(info[15]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t IssueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[16]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[17].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FloatingRateBondWorker(
    callback
    ,ObjectIDCpp
    ,DescriptionCpp
    ,CurrencyCpp
    ,SettlementDaysCpp
    ,PaymentBDCCpp
    ,FaceAmountCpp
    ,ScheduleIDCpp
    ,FixingDaysCpp
    ,IsInArrearsCpp
    ,DayCounterCpp
    ,FloorsCpp
    ,GearingsCpp
    ,IborIndexCpp
    ,SpreadsCpp
    ,CapsCpp
    ,RedemptionCpp
    ,IssueDateCpp
  ));

}

//FloatingRateBondWorker::~FloatingRateBondWorker(){
//
//}

//void FloatingRateBondWorker::Destroy(){
//
//}

void CmsRateBondWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Currency CurrencyEnum =
      ObjectHandler::Create<QuantLib::Currency>()(mCurrency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SettlementDaysLib;
  QuantLibAddin::cppToLibrary(mSettlementDays, SettlementDaysLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural FixingDaysLib = ObjectHandler::convert2<long>(
      mFixingDays, "FixingDays", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapIndexLibObjPtr, mSwapIndex,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date IssueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mIssueDate, "IssueDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCmsRateBond(
          mObjectID,
          mDescription,
          mCurrency,
          mSettlementDays,
          mPaymentBDC,
          mFaceAmount,
          mScheduleID,
          mFixingDays,
          mIsInArrears,
          mDayCounter,
          mFloors,
          mGearings,
          mSwapIndex,
          mSpreads,
          mCaps,
          mRedemption,
          mIssueDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CmsRateBond(
          valueObject,
          mDescription,
          CurrencyEnum,
          SettlementDaysLib,
          PaymentBDCEnum,
          mFaceAmount,
          ScheduleIDLibObjPtr,
          FixingDaysLib,
          mIsInArrears,
          DayCounterEnum,
          mFloors,
          mGearings,
          SwapIndexLibObjPtr,
          mSpreads,
          mCaps,
          mRedemption,
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

void CmsRateBondWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CmsRateBond) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Description is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Currency is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("SettlementDays is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("FaceAmount is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 8 || !info[8]->IsBoolean()) {
      return Nan::ThrowError("IsInArrears is required.");
  }
  if (info.Length() == 9 || !info[9]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("Floors is required.");
  }
  if (info.Length() == 11 || !info[11]->IsArray()) {
      return Nan::ThrowError("Gearings is required.");
  }
  if (info.Length() == 12 || !info[12]->IsString()) {
      return Nan::ThrowError("SwapIndex is required.");
  }
  if (info.Length() == 13 || !info[13]->IsArray()) {
      return Nan::ThrowError("Spreads is required.");
  }
  if (info.Length() == 14 || !info[14]->IsArray()) {
      return Nan::ThrowError("Caps is required.");
  }
  if (info.Length() == 15 || !info[15]->IsNumber()) {
      return Nan::ThrowError("Redemption is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDescription(info[1]->ToString());
  string DescriptionCpp(strdup(*strDescription));

  // convert js argument to c++ type
  String::Utf8Value strCurrency(info[2]->ToString());
  string CurrencyCpp(strdup(*strCurrency));

  // convert js argument to c++ type
  long SettlementDaysCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[4]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  double FaceAmountCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[6]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  ObjectHandler::property_t FixingDaysCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

  // convert js argument to c++ type
  bool IsInArrearsCpp = Nan::To<bool>(info[8]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[9]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  std::vector<double>FloorsCpp;

  Local<Array> FloorsArray = info[10].As<Array>();
  for (unsigned int i = 0; i < FloorsArray->Length(); i++){
    FloorsCpp.push_back(Nan::To<double>(Nan::Get(FloorsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>GearingsCpp;

  Local<Array> GearingsArray = info[11].As<Array>();
  for (unsigned int i = 0; i < GearingsArray->Length(); i++){
    GearingsCpp.push_back(Nan::To<double>(Nan::Get(GearingsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapIndex(info[12]->ToString());
  string SwapIndexCpp(strdup(*strSwapIndex));

  // convert js argument to c++ type
  std::vector<double>SpreadsCpp;

  Local<Array> SpreadsArray = info[13].As<Array>();
  for (unsigned int i = 0; i < SpreadsArray->Length(); i++){
    SpreadsCpp.push_back(Nan::To<double>(Nan::Get(SpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>CapsCpp;

  Local<Array> CapsArray = info[14].As<Array>();
  for (unsigned int i = 0; i < CapsArray->Length(); i++){
    CapsCpp.push_back(Nan::To<double>(Nan::Get(CapsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double RedemptionCpp = Nan::To<double>(info[15]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t IssueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[16]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[17].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CmsRateBondWorker(
    callback
    ,ObjectIDCpp
    ,DescriptionCpp
    ,CurrencyCpp
    ,SettlementDaysCpp
    ,PaymentBDCCpp
    ,FaceAmountCpp
    ,ScheduleIDCpp
    ,FixingDaysCpp
    ,IsInArrearsCpp
    ,DayCounterCpp
    ,FloorsCpp
    ,GearingsCpp
    ,SwapIndexCpp
    ,SpreadsCpp
    ,CapsCpp
    ,RedemptionCpp
    ,IssueDateCpp
  ));

}

//CmsRateBondWorker::~CmsRateBondWorker(){
//
//}

//void CmsRateBondWorker::Destroy(){
//
//}

void ZeroCouponBondWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Currency CurrencyEnum =
      ObjectHandler::Create<QuantLib::Currency>()(mCurrency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SettlementDaysLib;
  QuantLibAddin::cppToLibrary(mSettlementDays, SettlementDaysLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date MaturityLib = ObjectHandler::convert2<QuantLib::Date>(
      mMaturity, "Maturity");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date IssueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mIssueDate, "IssueDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlZeroCouponBond(
          mObjectID,
          mDescription,
          mCurrency,
          mSettlementDays,
          mCalendar,
          mFaceAmount,
          mMaturity,
          mPaymentBDC,
          mRedemption,
          mIssueDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ZeroCouponBond(
          valueObject,
          mDescription,
          CurrencyEnum,
          SettlementDaysLib,
          CalendarEnum,
          mFaceAmount,
          MaturityLib,
          PaymentBDCEnum,
          mRedemption,
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

void ZeroCouponBondWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ZeroCouponBond) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Description is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Currency is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("SettlementDays is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("FaceAmount is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Redemption is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDescription(info[1]->ToString());
  string DescriptionCpp(strdup(*strDescription));

  // convert js argument to c++ type
  String::Utf8Value strCurrency(info[2]->ToString());
  string CurrencyCpp(strdup(*strCurrency));

  // convert js argument to c++ type
  long SettlementDaysCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[4]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  double FaceAmountCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t MaturityCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[7]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  double RedemptionCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t IssueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[9]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ZeroCouponBondWorker(
    callback
    ,ObjectIDCpp
    ,DescriptionCpp
    ,CurrencyCpp
    ,SettlementDaysCpp
    ,CalendarCpp
    ,FaceAmountCpp
    ,MaturityCpp
    ,PaymentBDCCpp
    ,RedemptionCpp
    ,IssueDateCpp
  ));

}

//ZeroCouponBondWorker::~ZeroCouponBondWorker(){
//
//}

//void ZeroCouponBondWorker::Destroy(){
//
//}

void BondWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Currency CurrencyEnum =
      ObjectHandler::Create<QuantLib::Currency>()(mCurrency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SettlementDaysLib;
  QuantLibAddin::cppToLibrary(mSettlementDays, SettlementDaysLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date MaturityDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mMaturityDate, "MaturityDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date IssueDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mIssueDate, "IssueDate");


  // convert object IDs into library objects
  OH_GET_UNDERLYING(LegIDLibObj, mLegID,
      QuantLibAddin::Leg, QuantLib::Leg)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBond(
          mObjectID,
          mDescription,
          mCurrency,
          mSettlementDays,
          mCalendar,
          mFaceAmount,
          mMaturityDate,
          mIssueDate,
          mLegID,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Bond(
          valueObject,
          mDescription,
          CurrencyEnum,
          SettlementDaysLib,
          CalendarEnum,
          mFaceAmount,
          MaturityDateLib,
          IssueDateLib,
          LegIDLibObj,
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

void BondWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Bond) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Description is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Currency is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("SettlementDays is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("FaceAmount is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("LegID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDescription(info[1]->ToString());
  string DescriptionCpp(strdup(*strDescription));

  // convert js argument to c++ type
  String::Utf8Value strCurrency(info[2]->ToString());
  string CurrencyCpp(strdup(*strCurrency));

  // convert js argument to c++ type
  long SettlementDaysCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[4]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  double FaceAmountCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t MaturityDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t IssueDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strLegID(info[8]->ToString());
  string LegIDCpp(strdup(*strLegID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondWorker(
    callback
    ,ObjectIDCpp
    ,DescriptionCpp
    ,CurrencyCpp
    ,SettlementDaysCpp
    ,CalendarCpp
    ,FaceAmountCpp
    ,MaturityDateCpp
    ,IssueDateCpp
    ,LegIDCpp
  ));

}

//BondWorker::~BondWorker(){
//
//}

//void BondWorker::Destroy(){
//
//}

void BondSettlementDaysWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Bond, QuantLib::Bond)


  // invoke the member function
  QuantLib::Natural returnValue = ObjectIDLibObjPtr->settlementDays(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondSettlementDaysWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondSettlementDays) {

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
  Nan::AsyncQueueWorker(new BondSettlementDaysWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondSettlementDaysWorker::~BondSettlementDaysWorker(){
//
//}

//void BondSettlementDaysWorker::Destroy(){
//
//}

void BondCalendarWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Bond, QuantLib::Bond)


  // invoke the member function
  QuantLib::Calendar returnValue = ObjectIDLibObjPtr->calendar(
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

void BondCalendarWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondCalendar) {

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
  Nan::AsyncQueueWorker(new BondCalendarWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondCalendarWorker::~BondCalendarWorker(){
//
//}

//void BondCalendarWorker::Destroy(){
//
//}

void BondNotionalsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Bond, QuantLib::Bond)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->notionals(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondNotionalsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::BondNotionals) {

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
  Nan::AsyncQueueWorker(new BondNotionalsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondNotionalsWorker::~BondNotionalsWorker(){
//
//}

//void BondNotionalsWorker::Destroy(){
//
//}

void BondNotionalWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Bond, QuantLib::Bond)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->notional(
        SettlementDateLib
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondNotionalWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondNotional) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondNotionalWorker(
    callback
    ,ObjectIDCpp
    ,SettlementDateCpp
  ));

}

//BondNotionalWorker::~BondNotionalWorker(){
//
//}

//void BondNotionalWorker::Destroy(){
//
//}

void BondMaturityDateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Bond, QuantLib::Bond)


  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->maturityDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondMaturityDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondMaturityDate) {

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
  Nan::AsyncQueueWorker(new BondMaturityDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondMaturityDateWorker::~BondMaturityDateWorker(){
//
//}

//void BondMaturityDateWorker::Destroy(){
//
//}

void BondIssueDateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Bond, QuantLib::Bond)


  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->issueDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondIssueDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondIssueDate) {

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
  Nan::AsyncQueueWorker(new BondIssueDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondIssueDateWorker::~BondIssueDateWorker(){
//
//}

//void BondIssueDateWorker::Destroy(){
//
//}

void BondIsTradableWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Bond, QuantLib::Bond)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->isTradable(
        SettlementDateLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondIsTradableWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondIsTradable) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondIsTradableWorker(
    callback
    ,ObjectIDCpp
    ,SettlementDateCpp
  ));

}

//BondIsTradableWorker::~BondIsTradableWorker(){
//
//}

//void BondIsTradableWorker::Destroy(){
//
//}

void BondSettlementDateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EvaluationDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEvaluationDate, "EvaluationDate");

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Bond, QuantLib::Bond)


  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->settlementDate(
        EvaluationDateLib
       );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondSettlementDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondSettlementDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t EvaluationDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondSettlementDateWorker(
    callback
    ,ObjectIDCpp
    ,EvaluationDateCpp
  ));

}

//BondSettlementDateWorker::~BondSettlementDateWorker(){
//
//}

//void BondSettlementDateWorker::Destroy(){
//
//}

void BondCleanPriceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Bond, QuantLib::Bond)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->cleanPrice(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondCleanPriceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondCleanPrice) {

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
  Nan::AsyncQueueWorker(new BondCleanPriceWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondCleanPriceWorker::~BondCleanPriceWorker(){
//
//}

//void BondCleanPriceWorker::Destroy(){
//
//}

void BondDescriptionWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Bond)


  // invoke the member function
  mReturnValue = ObjectIDObjPtr->description(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondDescriptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondDescription) {

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
  Nan::AsyncQueueWorker(new BondDescriptionWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondDescriptionWorker::~BondDescriptionWorker(){
//
//}

//void BondDescriptionWorker::Destroy(){
//
//}

void BondCurrencyWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Bond)


  // invoke the member function
  mReturnValue = ObjectIDObjPtr->currency(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondCurrencyWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondCurrency) {

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
  Nan::AsyncQueueWorker(new BondCurrencyWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondCurrencyWorker::~BondCurrencyWorker(){
//
//}

//void BondCurrencyWorker::Destroy(){
//
//}

void BondRedemptionAmountWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Bond)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->redemptionAmount(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondRedemptionAmountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondRedemptionAmount) {

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
  Nan::AsyncQueueWorker(new BondRedemptionAmountWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondRedemptionAmountWorker::~BondRedemptionAmountWorker(){
//
//}

//void BondRedemptionAmountWorker::Destroy(){
//
//}

void BondRedemptionDateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Bond)


  // invoke the member function
  QuantLib::Date returnValue = ObjectIDObjPtr->redemptionDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondRedemptionDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondRedemptionDate) {

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
  Nan::AsyncQueueWorker(new BondRedemptionDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//BondRedemptionDateWorker::~BondRedemptionDateWorker(){
//
//}

//void BondRedemptionDateWorker::Destroy(){
//
//}

void BondFlowAnalysisWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date AfterDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mAfterDate, "AfterDate");

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Bond)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->flowAnalysis(
        AfterDateLib
       );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondFlowAnalysisWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::BondFlowAnalysis) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t AfterDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondFlowAnalysisWorker(
    callback
    ,ObjectIDCpp
    ,AfterDateCpp
  ));

}

//BondFlowAnalysisWorker::~BondFlowAnalysisWorker(){
//
//}

//void BondFlowAnalysisWorker::Destroy(){
//
//}

void BondSetCouponPricerWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(FloatingRateCouponPricerLibObjPtr, mFloatingRateCouponPricer,
      QuantLibAddin::FloatingRateCouponPricer, QuantLib::FloatingRateCouponPricer)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Bond)


  // invoke the member function
  ObjectIDObjPtr->setCouponPricer(
        FloatingRateCouponPricerLibObjPtr
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondSetCouponPricerWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondSetCouponPricer) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("FloatingRateCouponPricer is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strFloatingRateCouponPricer(info[1]->ToString());
  string FloatingRateCouponPricerCpp(strdup(*strFloatingRateCouponPricer));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondSetCouponPricerWorker(
    callback
    ,ObjectIDCpp
    ,FloatingRateCouponPricerCpp
  ));

}

//BondSetCouponPricerWorker::~BondSetCouponPricerWorker(){
//
//}

//void BondSetCouponPricerWorker::Destroy(){
//
//}

void BondSetCouponPricersWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::FloatingRateCouponPricer> > FloatingRateCouponPricerLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::FloatingRateCouponPricer, QuantLib::FloatingRateCouponPricer>(mFloatingRateCouponPricer);

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Bond)


  // invoke the member function
  ObjectIDObjPtr->setCouponPricers(
        FloatingRateCouponPricerLibObjPtr
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondSetCouponPricersWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondSetCouponPricers) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("FloatingRateCouponPricer is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<string>FloatingRateCouponPricerCpp;

  Local<Array> FloatingRateCouponPricerArray = info[1].As<Array>();
  for (unsigned int i = 0; i < FloatingRateCouponPricerArray->Length(); i++){
    String::Utf8Value strFloatingRateCouponPricer(Nan::Get(FloatingRateCouponPricerArray, i).ToLocalChecked()->ToString());
    FloatingRateCouponPricerCpp.push_back(strdup(*strFloatingRateCouponPricer));
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondSetCouponPricersWorker(
    callback
    ,ObjectIDCpp
    ,FloatingRateCouponPricerCpp
  ));

}

//BondSetCouponPricersWorker::~BondSetCouponPricersWorker(){
//
//}

//void BondSetCouponPricersWorker::Destroy(){
//
//}

void BondStartDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::BondFunctions::startDate(
      ObjectIdLibObj
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondStartDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondStartDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondStartDateWorker(
    callback
    ,ObjectIdCpp
  ));

}

//BondStartDateWorker::~BondStartDateWorker(){
//
//}

//void BondStartDateWorker::Destroy(){
//
//}

void BondPreviousCashFlowDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::BondFunctions::previousCashFlowDate(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondPreviousCashFlowDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondPreviousCashFlowDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondPreviousCashFlowDateWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondPreviousCashFlowDateWorker::~BondPreviousCashFlowDateWorker(){
//
//}

//void BondPreviousCashFlowDateWorker::Destroy(){
//
//}

void BondNextCashFlowDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::BondFunctions::nextCashFlowDate(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondNextCashFlowDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondNextCashFlowDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondNextCashFlowDateWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondNextCashFlowDateWorker::~BondNextCashFlowDateWorker(){
//
//}

//void BondNextCashFlowDateWorker::Destroy(){
//
//}

void BondPreviousCashFlowAmountWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::previousCashFlowAmount(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondPreviousCashFlowAmountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondPreviousCashFlowAmount) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondPreviousCashFlowAmountWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondPreviousCashFlowAmountWorker::~BondPreviousCashFlowAmountWorker(){
//
//}

//void BondPreviousCashFlowAmountWorker::Destroy(){
//
//}

void BondNextCashFlowAmountWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::nextCashFlowAmount(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondNextCashFlowAmountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondNextCashFlowAmount) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondNextCashFlowAmountWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondNextCashFlowAmountWorker::~BondNextCashFlowAmountWorker(){
//
//}

//void BondNextCashFlowAmountWorker::Destroy(){
//
//}

void BondPreviousCouponRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::BondFunctions::previousCouponRate(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondPreviousCouponRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondPreviousCouponRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondPreviousCouponRateWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondPreviousCouponRateWorker::~BondPreviousCouponRateWorker(){
//
//}

//void BondPreviousCouponRateWorker::Destroy(){
//
//}

void BondNextCouponRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::BondFunctions::nextCouponRate(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondNextCouponRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondNextCouponRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondNextCouponRateWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondNextCouponRateWorker::~BondNextCouponRateWorker(){
//
//}

//void BondNextCouponRateWorker::Destroy(){
//
//}

void BondAccrualStartDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::BondFunctions::accrualStartDate(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondAccrualStartDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondAccrualStartDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondAccrualStartDateWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondAccrualStartDateWorker::~BondAccrualStartDateWorker(){
//
//}

//void BondAccrualStartDateWorker::Destroy(){
//
//}

void BondAccrualEndDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::BondFunctions::accrualEndDate(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondAccrualEndDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondAccrualEndDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondAccrualEndDateWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondAccrualEndDateWorker::~BondAccrualEndDateWorker(){
//
//}

//void BondAccrualEndDateWorker::Destroy(){
//
//}

void BondReferencePeriodStartWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::BondFunctions::referencePeriodStart(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondReferencePeriodStartWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondReferencePeriodStart) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondReferencePeriodStartWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondReferencePeriodStartWorker::~BondReferencePeriodStartWorker(){
//
//}

//void BondReferencePeriodStartWorker::Destroy(){
//
//}

void BondReferencePeriodEndWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::BondFunctions::referencePeriodEnd(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondReferencePeriodEndWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondReferencePeriodEnd) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondReferencePeriodEndWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondReferencePeriodEndWorker::~BondReferencePeriodEndWorker(){
//
//}

//void BondReferencePeriodEndWorker::Destroy(){
//
//}

void BondAccrualPeriodWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::BondFunctions::accrualPeriod(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondAccrualPeriodWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondAccrualPeriod) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondAccrualPeriodWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondAccrualPeriodWorker::~BondAccrualPeriodWorker(){
//
//}

//void BondAccrualPeriodWorker::Destroy(){
//
//}

void BondAccrualDaysWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::BondFunctions::accrualDays(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondAccrualDaysWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondAccrualDays) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondAccrualDaysWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondAccrualDaysWorker::~BondAccrualDaysWorker(){
//
//}

//void BondAccrualDaysWorker::Destroy(){
//
//}

void BondAccruedPeriodWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::BondFunctions::accruedPeriod(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondAccruedPeriodWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondAccruedPeriod) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondAccruedPeriodWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondAccruedPeriodWorker::~BondAccruedPeriodWorker(){
//
//}

//void BondAccruedPeriodWorker::Destroy(){
//
//}

void BondAccruedDaysWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::BondFunctions::accruedDays(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondAccruedDaysWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondAccruedDays) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondAccruedDaysWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondAccruedDaysWorker::~BondAccruedDaysWorker(){
//
//}

//void BondAccruedDaysWorker::Destroy(){
//
//}

void BondAccruedAmountWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::BondFunctions::accruedAmount(
      ObjectIdLibObj
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondAccruedAmountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondAccruedAmount) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondAccruedAmountWorker(
    callback
    ,ObjectIdCpp
    ,SettlementDateCpp
  ));

}

//BondAccruedAmountWorker::~BondAccruedAmountWorker(){
//
//}

//void BondAccruedAmountWorker::Destroy(){
//
//}

void BondCleanPriceFromYieldTermStructureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(YieldCurveLibObj, mYieldCurve,
      QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::cleanPrice(
      ObjectIdLibObj
      ,
       YieldCurveLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondCleanPriceFromYieldTermStructureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondCleanPriceFromYieldTermStructure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("YieldCurve is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  String::Utf8Value strYieldCurve(info[1]->ToString());
  string YieldCurveCpp(strdup(*strYieldCurve));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondCleanPriceFromYieldTermStructureWorker(
    callback
    ,ObjectIdCpp
    ,YieldCurveCpp
    ,SettlementDateCpp
  ));

}

//BondCleanPriceFromYieldTermStructureWorker::~BondCleanPriceFromYieldTermStructureWorker(){
//
//}

//void BondCleanPriceFromYieldTermStructureWorker::Destroy(){
//
//}

void BondBpsFromYieldTermStructureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(YieldCurveLibObj, mYieldCurve,
      QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::bps(
      ObjectIdLibObj
      ,
       YieldCurveLibObj
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondBpsFromYieldTermStructureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondBpsFromYieldTermStructure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("YieldCurve is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  String::Utf8Value strYieldCurve(info[1]->ToString());
  string YieldCurveCpp(strdup(*strYieldCurve));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondBpsFromYieldTermStructureWorker(
    callback
    ,ObjectIdCpp
    ,YieldCurveCpp
    ,SettlementDateCpp
  ));

}

//BondBpsFromYieldTermStructureWorker::~BondBpsFromYieldTermStructureWorker(){
//
//}

//void BondBpsFromYieldTermStructureWorker::Destroy(){
//
//}

void BondAtmRateFromYieldTermStructureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(YieldCurveLibObj, mYieldCurve,
      QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");


  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::atmRate(
      ObjectIdLibObj
      ,
       YieldCurveLibObj
      ,
       SettlementDateLib
      ,
       mCleanPrice
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondAtmRateFromYieldTermStructureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondAtmRateFromYieldTermStructure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("YieldCurve is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("CleanPrice is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  String::Utf8Value strYieldCurve(info[1]->ToString());
  string YieldCurveCpp(strdup(*strYieldCurve));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  double CleanPriceCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondAtmRateFromYieldTermStructureWorker(
    callback
    ,ObjectIdCpp
    ,YieldCurveCpp
    ,SettlementDateCpp
    ,CleanPriceCpp
  ));

}

//BondAtmRateFromYieldTermStructureWorker::~BondAtmRateFromYieldTermStructureWorker(){
//
//}

//void BondAtmRateFromYieldTermStructureWorker::Destroy(){
//
//}

void BondCleanPriceFromYieldWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::cleanPrice(
      ObjectIdLibObj
      ,
       mYield
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondCleanPriceFromYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondCleanPriceFromYield) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Yield is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  double YieldCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[2]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[3]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[4]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondCleanPriceFromYieldWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,SettlementDateCpp
  ));

}

//BondCleanPriceFromYieldWorker::~BondCleanPriceFromYieldWorker(){
//
//}

//void BondCleanPriceFromYieldWorker::Destroy(){
//
//}

void BondDirtyPriceFromYieldWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::dirtyPrice(
      ObjectIdLibObj
      ,
       mYield
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondDirtyPriceFromYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondDirtyPriceFromYield) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Yield is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  double YieldCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[2]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[3]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[4]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondDirtyPriceFromYieldWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,SettlementDateCpp
  ));

}

//BondDirtyPriceFromYieldWorker::~BondDirtyPriceFromYieldWorker(){
//
//}

//void BondDirtyPriceFromYieldWorker::Destroy(){
//
//}

void BondBpsFromYieldWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::bps(
      ObjectIdLibObj
      ,
       mYield
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondBpsFromYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondBpsFromYield) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Yield is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  double YieldCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[2]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[3]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[4]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondBpsFromYieldWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,SettlementDateCpp
  ));

}

//BondBpsFromYieldWorker::~BondBpsFromYieldWorker(){
//
//}

//void BondBpsFromYieldWorker::Destroy(){
//
//}

void BondYieldFromCleanPriceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size MaxIterationsLib;
  QuantLibAddin::cppToLibrary(mMaxIterations, MaxIterationsLib);

       // invoke the utility function
  mReturnValue = QuantLib::BondFunctions::yield(
      ObjectIdLibObj
      ,
       mCleanPrice
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       SettlementDateLib
      ,
       mAccuracy
      ,
       MaxIterationsLib
      ,
       mGuess
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondYieldFromCleanPriceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondYieldFromCleanPrice) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("CleanPrice is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("MaxIterations is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Guess is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  double CleanPriceCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[2]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[3]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[4]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  long MaxIterationsCpp = Nan::To<int32_t>(info[7]).FromJust();

  // convert js argument to c++ type
  double GuessCpp = Nan::To<double>(info[8]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondYieldFromCleanPriceWorker(
    callback
    ,ObjectIdCpp
    ,CleanPriceCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,SettlementDateCpp
    ,AccuracyCpp
    ,MaxIterationsCpp
    ,GuessCpp
  ));

}

//BondYieldFromCleanPriceWorker::~BondYieldFromCleanPriceWorker(){
//
//}

//void BondYieldFromCleanPriceWorker::Destroy(){
//
//}

void BondDurationFromYieldWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Duration::Type DurationTypeEnum =
      ObjectHandler::Create<QuantLib::Duration::Type>()(mDurationType);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::duration(
      ObjectIdLibObj
      ,
       mYield
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       DurationTypeEnum
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondDurationFromYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondDurationFromYield) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Yield is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("DurationType is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  double YieldCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[2]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[3]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[4]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  String::Utf8Value strDurationType(info[5]->ToString());
  string DurationTypeCpp(strdup(*strDurationType));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondDurationFromYieldWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,DurationTypeCpp
    ,SettlementDateCpp
  ));

}

//BondDurationFromYieldWorker::~BondDurationFromYieldWorker(){
//
//}

//void BondDurationFromYieldWorker::Destroy(){
//
//}

void BondConvexityFromYieldWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::convexity(
      ObjectIdLibObj
      ,
       mYield
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondConvexityFromYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondConvexityFromYield) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Yield is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  double YieldCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[2]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[3]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[4]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondConvexityFromYieldWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,SettlementDateCpp
  ));

}

//BondConvexityFromYieldWorker::~BondConvexityFromYieldWorker(){
//
//}

//void BondConvexityFromYieldWorker::Destroy(){
//
//}

void BondCleanPriceFromZSpreadWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert object IDs into library objects
  OH_GET_REFERENCE(YieldCurveLibObjPtr, mYieldCurve,
      QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::BondFunctions::cleanPrice(
      ObjectIdLibObj
      ,
       YieldCurveLibObjPtr
      ,
       mZSpread
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       SettlementDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondCleanPriceFromZSpreadWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondCleanPriceFromZSpread) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("YieldCurve is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("ZSpread is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  String::Utf8Value strYieldCurve(info[1]->ToString());
  string YieldCurveCpp(strdup(*strYieldCurve));

  // convert js argument to c++ type
  double ZSpreadCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[3]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[4]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[5]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondCleanPriceFromZSpreadWorker(
    callback
    ,ObjectIdCpp
    ,YieldCurveCpp
    ,ZSpreadCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,SettlementDateCpp
  ));

}

//BondCleanPriceFromZSpreadWorker::~BondCleanPriceFromZSpreadWorker(){
//
//}

//void BondCleanPriceFromZSpreadWorker::Destroy(){
//
//}

void BondZSpreadFromCleanPriceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(YieldCurveLibObjPtr, mYieldCurve,
      QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size MaxIterationsLib;
  QuantLibAddin::cppToLibrary(mMaxIterations, MaxIterationsLib);

       // invoke the utility function
  mReturnValue = QuantLib::BondFunctions::zSpread(
      ObjectIdLibObj
      ,
       mCleanPrice
      ,
       YieldCurveLibObjPtr
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       SettlementDateLib
      ,
       mAccuracy
      ,
       MaxIterationsLib
      ,
       mGuess
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondZSpreadFromCleanPriceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondZSpreadFromCleanPrice) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("CleanPrice is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("YieldCurve is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("MaxIterations is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("Guess is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  double CleanPriceCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strYieldCurve(info[2]->ToString());
  string YieldCurveCpp(strdup(*strYieldCurve));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[3]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[4]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[5]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  long MaxIterationsCpp = Nan::To<int32_t>(info[8]).FromJust();

  // convert js argument to c++ type
  double GuessCpp = Nan::To<double>(info[9]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondZSpreadFromCleanPriceWorker(
    callback
    ,ObjectIdCpp
    ,CleanPriceCpp
    ,YieldCurveCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,SettlementDateCpp
    ,AccuracyCpp
    ,MaxIterationsCpp
    ,GuessCpp
  ));

}

//BondZSpreadFromCleanPriceWorker::~BondZSpreadFromCleanPriceWorker(){
//
//}

//void BondZSpreadFromCleanPriceWorker::Destroy(){
//
//}

void BondAliveWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLibAddin::Bond> > BondsObjPtr =
      ObjectHandler::getObjectVector<QuantLibAddin::Bond>(mBonds);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefDate, "RefDate");

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlBondAlive(
      BondsObjPtr
      ,
       RefDateLib
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondAliveWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::BondAlive) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Bonds is required.");
  }
  // convert js argument to c++ type
  std::vector<string>BondsCpp;

  Local<Array> BondsArray = info[0].As<Array>();
  for (unsigned int i = 0; i < BondsArray->Length(); i++){
    String::Utf8Value strBonds(Nan::Get(BondsArray, i).ToLocalChecked()->ToString());
    BondsCpp.push_back(strdup(*strBonds));
  }

  // convert js argument to c++ type
  ObjectHandler::property_t RefDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondAliveWorker(
    callback
    ,BondsCpp
    ,RefDateCpp
  ));

}

//BondAliveWorker::~BondAliveWorker(){
//
//}

//void BondAliveWorker::Destroy(){
//
//}

void BondMaturityLookupWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLibAddin::Bond> > BondsObjPtr =
      ObjectHandler::getObjectVector<QuantLibAddin::Bond>(mBonds);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date MaturityLib = ObjectHandler::convert2<QuantLib::Date>(
      mMaturity, "Maturity");

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlBondMaturityLookup(
      BondsObjPtr
      ,
       MaturityLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondMaturityLookupWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BondMaturityLookup) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Bonds is required.");
  }
  // convert js argument to c++ type
  std::vector<string>BondsCpp;

  Local<Array> BondsArray = info[0].As<Array>();
  for (unsigned int i = 0; i < BondsArray->Length(); i++){
    String::Utf8Value strBonds(Nan::Get(BondsArray, i).ToLocalChecked()->ToString());
    BondsCpp.push_back(strdup(*strBonds));
  }

  // convert js argument to c++ type
  ObjectHandler::property_t MaturityCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondMaturityLookupWorker(
    callback
    ,BondsCpp
    ,MaturityCpp
  ));

}

//BondMaturityLookupWorker::~BondMaturityLookupWorker(){
//
//}

//void BondMaturityLookupWorker::Destroy(){
//
//}

void BondMaturitySortWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLibAddin::Bond> > BondsObjPtr =
      ObjectHandler::getObjectVector<QuantLibAddin::Bond>(mBonds);

       // invoke the utility function
  mReturnValue = QuantLibAddin::qlBondMaturitySort(
      BondsObjPtr
   );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BondMaturitySortWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::BondMaturitySort) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Bonds is required.");
  }
  // convert js argument to c++ type
  std::vector<string>BondsCpp;

  Local<Array> BondsArray = info[0].As<Array>();
  for (unsigned int i = 0; i < BondsArray->Length(); i++){
    String::Utf8Value strBonds(Nan::Get(BondsArray, i).ToLocalChecked()->ToString());
    BondsCpp.push_back(strdup(*strBonds));
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BondMaturitySortWorker(
    callback
    ,BondsCpp
  ));

}

//BondMaturitySortWorker::~BondMaturitySortWorker(){
//
//}

//void BondMaturitySortWorker::Destroy(){
//
//}
 