/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "credit.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/credit.hpp>
#include <qlo/creditdefaultswap.hpp>
#include <qlo/cdsoption.hpp>
#include <qlo/pricingengines.hpp>
#include <qlo/termstructures.hpp>
#include <qlo/handleimpl.hpp>
#include <qlo/conversions/coercetermstructure.hpp>
#include <qlo/ratehelpers.hpp>
#include <qlo/defaultbasket.hpp>
#include <qlo/exercise.hpp>
#include <ql/termstructures/credit/defaultprobabilityhelpers.hpp>
#include <ql/pricingengines/credit/midpointcdsengine.hpp>
#include <ql/experimental/credit/basket.hpp>
#include <ql/experimental/credit/cdsoption.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void CreditDefaultSwapWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Protection::Side BuyerSellerEnum =
      ObjectHandler::Create<QuantLib::Protection::Side>()(mBuyerSeller);


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(PremiumScheduleLibObjPtr, mPremiumSchedule,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentConvention);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ProtectionStartLib = ObjectHandler::convert2<QuantLib::Date>(
      mProtectionStart, "ProtectionStart");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date UpfrontDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mUpfrontDate, "UpfrontDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCreditDefaultSwap(
          mObjectID,
          mBuyerSeller,
          mNotional,
          mUpfront,
          mSpread,
          mPremiumSchedule,
          mPaymentConvention,
          mDayCounter,
          mSettlesAccrual,
          mPayAtDefault,
          mProtectionStart,
          mUpfrontDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CreditDefaultSwap(
          valueObject,
          BuyerSellerEnum,
          mNotional,
          mUpfront,
          mSpread,
          PremiumScheduleLibObjPtr,
          PaymentConventionEnum,
          DayCounterEnum,
          mSettlesAccrual,
          mPayAtDefault,
          ProtectionStartLib,
          UpfrontDateLib,
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

void CreditDefaultSwapWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CreditDefaultSwap) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("BuyerSeller is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Notional is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Upfront is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Spread is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("PremiumSchedule is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("PaymentConvention is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 8 || !info[8]->IsBoolean()) {
      return Nan::ThrowError("SettlesAccrual is required.");
  }
  if (info.Length() == 9 || !info[9]->IsBoolean()) {
      return Nan::ThrowError("PayAtDefault is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strBuyerSeller(info[1]->ToString());
  string BuyerSellerCpp(strdup(*strBuyerSeller));

  // convert js argument to c++ type
  double NotionalCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double UpfrontCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double SpreadCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strPremiumSchedule(info[5]->ToString());
  string PremiumScheduleCpp(strdup(*strPremiumSchedule));

  // convert js argument to c++ type
  String::Utf8Value strPaymentConvention(info[6]->ToString());
  string PaymentConventionCpp(strdup(*strPaymentConvention));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[7]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  bool SettlesAccrualCpp = Nan::To<bool>(info[8]).FromJust();

  // convert js argument to c++ type
  bool PayAtDefaultCpp = Nan::To<bool>(info[9]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t ProtectionStartCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[10]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t UpfrontDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[11]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[12].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CreditDefaultSwapWorker(
    callback
    ,ObjectIDCpp
    ,BuyerSellerCpp
    ,NotionalCpp
    ,UpfrontCpp
    ,SpreadCpp
    ,PremiumScheduleCpp
    ,PaymentConventionCpp
    ,DayCounterCpp
    ,SettlesAccrualCpp
    ,PayAtDefaultCpp
    ,ProtectionStartCpp
    ,UpfrontDateCpp
  ));

}

//CreditDefaultSwapWorker::~CreditDefaultSwapWorker(){
//
//}

//void CreditDefaultSwapWorker::Destroy(){
//
//}

void MidPointCdsEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(DefaultCurveCoerce, mDefaultCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::DefaultProbabilityTermStructure> DefaultCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::DefaultProbabilityTermStructure,
          QuantLib::DefaultProbabilityTermStructure>()(
              DefaultCurveCoerce);


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMidPointCdsEngine(
          mObjectID,
          mDefaultCurve,
          mRecoveryRate,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::MidPointCdsEngine(
          valueObject,
          DefaultCurveLibObj,
          mRecoveryRate,
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

void MidPointCdsEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MidPointCdsEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("RecoveryRate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t DefaultCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  double RecoveryRateCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[3]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MidPointCdsEngineWorker(
    callback
    ,ObjectIDCpp
    ,DefaultCurveCpp
    ,RecoveryRateCpp
    ,YieldCurveCpp
  ));

}

//MidPointCdsEngineWorker::~MidPointCdsEngineWorker(){
//
//}

//void MidPointCdsEngineWorker::Destroy(){
//
//}

void HazardRateCurveWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> CurveDatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mCurveDates, "CurveDates");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlHazardRateCurve(
          mObjectID,
          mCurveDates,
          mCurveRates,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::HazardRateCurve(
          valueObject,
          CurveDatesLib,
          mCurveRates,
          DayCounterEnum,
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

void HazardRateCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::HazardRateCurve) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("CurveDates is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("CurveRates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>CurveDatesCpp;

  Local<Array> CurveDatesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < CurveDatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(CurveDatesArray, i).ToLocalChecked()).FromJust()));
    CurveDatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>CurveRatesCpp;

  Local<Array> CurveRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < CurveRatesArray->Length(); i++){
    CurveRatesCpp.push_back(Nan::To<double>(Nan::Get(CurveRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[3]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new HazardRateCurveWorker(
    callback
    ,ObjectIDCpp
    ,CurveDatesCpp
    ,CurveRatesCpp
    ,DayCounterCpp
  ));

}

//HazardRateCurveWorker::~HazardRateCurveWorker(){
//
//}

//void HazardRateCurveWorker::Destroy(){
//
//}

void SpreadCdsHelperWorker::Execute(){

  try{

  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> RunningSpreadLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mRunningSpread, "RunningSpread");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period TenorLib;
  QuantLibAddin::cppToLibrary(mTenor, TenorLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural SettlementDaysLib = ObjectHandler::convert2<long>(
      mSettlementDays, "SettlementDays", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentConvention);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DateGeneration::Rule GenRuleEnum =
      ObjectHandler::Create<QuantLib::DateGeneration::Rule>()(mGenRule);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_OBJECT(DiscountingCurveCoerce, mDiscountingCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> DiscountingCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              DiscountingCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSpreadCdsHelper(
          mObjectID,
          mRunningSpread,
          mTenor,
          mSettlementDays,
          mCalendar,
          mFrequency,
          mPaymentConvention,
          mGenRule,
          mDayCounter,
          mRecoveryRate,
          mDiscountingCurve,
          mSettleAccrual,
          mPayAtDefault,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SpreadCdsHelper(
          valueObject,
          RunningSpreadLibObj,
          TenorLib,
          SettlementDaysLib,
          CalendarEnum,
          FrequencyEnum,
          PaymentConventionEnum,
          GenRuleEnum,
          DayCounterEnum,
          mRecoveryRate,
          DiscountingCurveLibObj,
          mSettleAccrual,
          mPayAtDefault,
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

void SpreadCdsHelperWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SpreadCdsHelper) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Tenor is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("PaymentConvention is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("GenRule is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("RecoveryRate is required.");
  }
  if (info.Length() == 11 || !info[11]->IsBoolean()) {
      return Nan::ThrowError("SettleAccrual is required.");
  }
  if (info.Length() == 12 || !info[12]->IsBoolean()) {
      return Nan::ThrowError("PayAtDefault is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t RunningSpreadCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strTenor(info[2]->ToString());
  string TenorCpp(strdup(*strTenor));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDaysCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[4]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[5]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  String::Utf8Value strPaymentConvention(info[6]->ToString());
  string PaymentConventionCpp(strdup(*strPaymentConvention));

  // convert js argument to c++ type
  String::Utf8Value strGenRule(info[7]->ToString());
  string GenRuleCpp(strdup(*strGenRule));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[8]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  double RecoveryRateCpp = Nan::To<double>(info[9]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t DiscountingCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[10]).FromJust()));

  // convert js argument to c++ type
  bool SettleAccrualCpp = Nan::To<bool>(info[11]).FromJust();

  // convert js argument to c++ type
  bool PayAtDefaultCpp = Nan::To<bool>(info[12]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[13].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SpreadCdsHelperWorker(
    callback
    ,ObjectIDCpp
    ,RunningSpreadCpp
    ,TenorCpp
    ,SettlementDaysCpp
    ,CalendarCpp
    ,FrequencyCpp
    ,PaymentConventionCpp
    ,GenRuleCpp
    ,DayCounterCpp
    ,RecoveryRateCpp
    ,DiscountingCurveCpp
    ,SettleAccrualCpp
    ,PayAtDefaultCpp
  ));

}

//SpreadCdsHelperWorker::~SpreadCdsHelperWorker(){
//
//}

//void SpreadCdsHelperWorker::Destroy(){
//
//}

void UpfrontCdsHelperWorker::Execute(){

  try{

  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> UpfrontSpreadLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mUpfrontSpread, "UpfrontSpread");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period TenorLib;
  QuantLibAddin::cppToLibrary(mTenor, TenorLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural SettlementDaysLib = ObjectHandler::convert2<long>(
      mSettlementDays, "SettlementDays", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentConvention);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DateGeneration::Rule GenRuleEnum =
      ObjectHandler::Create<QuantLib::DateGeneration::Rule>()(mGenRule);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_OBJECT(DiscCurveCoerce, mDiscCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> DiscCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              DiscCurveCoerce);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural UpfSettlDaysLib = ObjectHandler::convert2<long>(
      mUpfSettlDays, "UpfSettlDays", QuantLib::Null<QuantLib::Natural>());

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlUpfrontCdsHelper(
          mObjectID,
          mUpfrontSpread,
          mRunningSpread,
          mTenor,
          mSettlementDays,
          mCalendar,
          mFrequency,
          mPaymentConvention,
          mGenRule,
          mDayCounter,
          mRecRate,
          mDiscCurve,
          mUpfSettlDays,
          mSettlAccr,
          mPayAtDefault,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::UpfrontCdsHelper(
          valueObject,
          UpfrontSpreadLibObj,
          mRunningSpread,
          TenorLib,
          SettlementDaysLib,
          CalendarEnum,
          FrequencyEnum,
          PaymentConventionEnum,
          GenRuleEnum,
          DayCounterEnum,
          mRecRate,
          DiscCurveLibObj,
          UpfSettlDaysLib,
          mSettlAccr,
          mPayAtDefault,
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

void UpfrontCdsHelperWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::UpfrontCdsHelper) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("RunningSpread is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Tenor is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("PaymentConvention is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("GenRule is required.");
  }
  if (info.Length() == 9 || !info[9]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 10 || !info[10]->IsNumber()) {
      return Nan::ThrowError("RecRate is required.");
  }
  if (info.Length() == 13 || !info[13]->IsBoolean()) {
      return Nan::ThrowError("SettlAccr is required.");
  }
  if (info.Length() == 14 || !info[14]->IsBoolean()) {
      return Nan::ThrowError("PayAtDefault is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t UpfrontSpreadCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  double RunningSpreadCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strTenor(info[3]->ToString());
  string TenorCpp(strdup(*strTenor));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDaysCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[5]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[6]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  String::Utf8Value strPaymentConvention(info[7]->ToString());
  string PaymentConventionCpp(strdup(*strPaymentConvention));

  // convert js argument to c++ type
  String::Utf8Value strGenRule(info[8]->ToString());
  string GenRuleCpp(strdup(*strGenRule));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[9]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  double RecRateCpp = Nan::To<double>(info[10]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t DiscCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[11]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t UpfSettlDaysCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[12]).FromJust()));

  // convert js argument to c++ type
  bool SettlAccrCpp = Nan::To<bool>(info[13]).FromJust();

  // convert js argument to c++ type
  bool PayAtDefaultCpp = Nan::To<bool>(info[14]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[15].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new UpfrontCdsHelperWorker(
    callback
    ,ObjectIDCpp
    ,UpfrontSpreadCpp
    ,RunningSpreadCpp
    ,TenorCpp
    ,SettlementDaysCpp
    ,CalendarCpp
    ,FrequencyCpp
    ,PaymentConventionCpp
    ,GenRuleCpp
    ,DayCounterCpp
    ,RecRateCpp
    ,DiscCurveCpp
    ,UpfSettlDaysCpp
    ,SettlAccrCpp
    ,PayAtDefaultCpp
  ));

}

//UpfrontCdsHelperWorker::~UpfrontCdsHelperWorker(){
//
//}

//void UpfrontCdsHelperWorker::Destroy(){
//
//}

void PiecewiseHazardRateCurveWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::DefaultProbabilityHelper> > HelpersLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::DefaultProbabilityHelper, QuantLib::DefaultProbabilityHelper>(mHelpers);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlPiecewiseHazardRateCurve(
          mObjectID,
          mHelpers,
          mDayCounter,
          mCalendar,
          mInterpolation,
          mAccuracy,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::PiecewiseHazardRateCurve(
          valueObject,
          HelpersLibObjPtr,
          DayCounterEnum,
          CalendarEnum,
          mInterpolation,
          mAccuracy,
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

void PiecewiseHazardRateCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseHazardRateCurve) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Helpers is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Interpolation is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<string>HelpersCpp;

  Local<Array> HelpersArray = info[1].As<Array>();
  for (unsigned int i = 0; i < HelpersArray->Length(); i++){
    String::Utf8Value strHelpers(Nan::Get(HelpersArray, i).ToLocalChecked()->ToString());
    HelpersCpp.push_back(strdup(*strHelpers));
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[2]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[3]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  String::Utf8Value strInterpolation(info[4]->ToString());
  string InterpolationCpp(strdup(*strInterpolation));

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseHazardRateCurveWorker(
    callback
    ,ObjectIDCpp
    ,HelpersCpp
    ,DayCounterCpp
    ,CalendarCpp
    ,InterpolationCpp
    ,AccuracyCpp
  ));

}

//PiecewiseHazardRateCurveWorker::~PiecewiseHazardRateCurveWorker(){
//
//}

//void PiecewiseHazardRateCurveWorker::Destroy(){
//
//}

void PiecewiseFlatForwardCurveWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ReferenceDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mReferenceDate, "ReferenceDate");


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::RateHelper> > RateHelpersLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::RateHelper, QuantLib::RateHelper>(mRateHelpers);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlPiecewiseFlatForwardCurve(
          mObjectID,
          mReferenceDate,
          mRateHelpers,
          mDayCounter,
          mAccuracy,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::PiecewiseFlatForwardCurve(
          valueObject,
          ReferenceDateLib,
          RateHelpersLibObjPtr,
          DayCounterEnum,
          mAccuracy,
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

void PiecewiseFlatForwardCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PiecewiseFlatForwardCurve) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RateHelpers is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t ReferenceDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  std::vector<string>RateHelpersCpp;

  Local<Array> RateHelpersArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RateHelpersArray->Length(); i++){
    String::Utf8Value strRateHelpers(Nan::Get(RateHelpersArray, i).ToLocalChecked()->ToString());
    RateHelpersCpp.push_back(strdup(*strRateHelpers));
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[3]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PiecewiseFlatForwardCurveWorker(
    callback
    ,ObjectIDCpp
    ,ReferenceDateCpp
    ,RateHelpersCpp
    ,DayCounterCpp
    ,AccuracyCpp
  ));

}

//PiecewiseFlatForwardCurveWorker::~PiecewiseFlatForwardCurveWorker(){
//
//}

//void PiecewiseFlatForwardCurveWorker::Destroy(){
//
//}

void RiskyFixedBondWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Currency CurrencyEnum =
      ObjectHandler::Create<QuantLib::Currency>()(mCurrency);


  // convert object IDs into library objects
  OH_GET_OBJECT(DefaultCurveCoerce, mDefaultCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::DefaultProbabilityTermStructure> DefaultCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::DefaultProbabilityTermStructure,
          QuantLib::DefaultProbabilityTermStructure>()(
              DefaultCurveCoerce);


  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleLibObjPtr, mSchedule,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentConvention);


  // convert object IDs into library objects
  OH_GET_OBJECT(DiscountingCurveCoerce, mDiscountingCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> DiscountingCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              DiscountingCurveCoerce);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date PricingDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mPricingDate, "PricingDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRiskyFixedBond(
          mObjectID,
          mBondname,
          mCurrency,
          mRecovery,
          mDefaultCurve,
          mSchedule,
          mRate,
          mDayCounter,
          mPaymentConvention,
          mNotional,
          mDiscountingCurve,
          mPricingDate,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RiskyFixedBond(
          valueObject,
          mBondname,
          CurrencyEnum,
          mRecovery,
          DefaultCurveLibObj,
          ScheduleLibObjPtr,
          mRate,
          DayCounterEnum,
          PaymentConventionEnum,
          mNotional,
          DiscountingCurveLibObj,
          PricingDateLib,
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

void RiskyFixedBondWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RiskyFixedBond) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Bondname is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Currency is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Recovery is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Schedule is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Rate is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("PaymentConvention is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("Notional is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strBondname(info[1]->ToString());
  string BondnameCpp(strdup(*strBondname));

  // convert js argument to c++ type
  String::Utf8Value strCurrency(info[2]->ToString());
  string CurrencyCpp(strdup(*strCurrency));

  // convert js argument to c++ type
  double RecoveryCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t DefaultCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[4]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strSchedule(info[5]->ToString());
  string ScheduleCpp(strdup(*strSchedule));

  // convert js argument to c++ type
  double RateCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[7]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strPaymentConvention(info[8]->ToString());
  string PaymentConventionCpp(strdup(*strPaymentConvention));

  // convert js argument to c++ type
  double NotionalCpp = Nan::To<double>(info[9]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t DiscountingCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[10]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t PricingDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[11]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[12].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RiskyFixedBondWorker(
    callback
    ,ObjectIDCpp
    ,BondnameCpp
    ,CurrencyCpp
    ,RecoveryCpp
    ,DefaultCurveCpp
    ,ScheduleCpp
    ,RateCpp
    ,DayCounterCpp
    ,PaymentConventionCpp
    ,NotionalCpp
    ,DiscountingCurveCpp
    ,PricingDateCpp
  ));

}

//RiskyFixedBondWorker::~RiskyFixedBondWorker(){
//
//}

//void RiskyFixedBondWorker::Destroy(){
//
//}

void IssuerWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(DefaultCurvesLibObjPtr, mDefaultCurves,
      QuantLibAddin::DefaultProbabilityTermStructure, QuantLib::DefaultProbabilityTermStructure)


  // convert object IDs into library objects
  OH_GET_REFERENCE(DefaultEventsLibObjPtr, mDefaultEvents,
      QuantLibAddin::DefaultEventSet, QuantLib::DefaultEventSet)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlIssuer(
          mObjectID,
          mDefaultCurves,
          mDefaultEvents,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Issuer(
          valueObject,
          DefaultCurvesLibObjPtr,
          DefaultEventsLibObjPtr,
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

void IssuerWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Issuer) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("DefaultCurves is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("DefaultEvents is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDefaultCurves(info[1]->ToString());
  string DefaultCurvesCpp(strdup(*strDefaultCurves));

  // convert js argument to c++ type
  String::Utf8Value strDefaultEvents(info[2]->ToString());
  string DefaultEventsCpp(strdup(*strDefaultEvents));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IssuerWorker(
    callback
    ,ObjectIDCpp
    ,DefaultCurvesCpp
    ,DefaultEventsCpp
  ));

}

//IssuerWorker::~IssuerWorker(){
//
//}

//void IssuerWorker::Destroy(){
//
//}

void DefaultEventWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EventDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEventDate, "EventDate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Currency CurrencyEnum =
      ObjectHandler::Create<QuantLib::Currency>()(mCurrency);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Seniority SeniorityEnum =
      ObjectHandler::Create<QuantLib::Seniority>()(mSeniority);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlDefaultEvent(
          mObjectID,
          mEventType,
          mEventDate,
          mCurrency,
          mSeniority,
          mSettlementDate,
          mSettledRecovery,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::DefaultEventSet(
          valueObject,
          mEventType,
          EventDateLib,
          CurrencyEnum,
          SeniorityEnum,
          SettlementDateLib,
          mSettledRecovery,
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

void DefaultEventWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DefaultEvent) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("EventType is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Currency is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Seniority is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("SettledRecovery is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strEventType(info[1]->ToString());
  string EventTypeCpp(strdup(*strEventType));

  // convert js argument to c++ type
  ObjectHandler::property_t EventDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strCurrency(info[3]->ToString());
  string CurrencyCpp(strdup(*strCurrency));

  // convert js argument to c++ type
  String::Utf8Value strSeniority(info[4]->ToString());
  string SeniorityCpp(strdup(*strSeniority));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

  // convert js argument to c++ type
  double SettledRecoveryCpp = Nan::To<double>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DefaultEventWorker(
    callback
    ,ObjectIDCpp
    ,EventTypeCpp
    ,EventDateCpp
    ,CurrencyCpp
    ,SeniorityCpp
    ,SettlementDateCpp
    ,SettledRecoveryCpp
  ));

}

//DefaultEventWorker::~DefaultEventWorker(){
//
//}

//void DefaultEventWorker::Destroy(){
//
//}

void SyntheticCDOWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(BasketLibObjPtr, mBasket,
      QuantLibAddin::Basket, QuantLib::Basket)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Protection::Side BuyerSellerEnum =
      ObjectHandler::Create<QuantLib::Protection::Side>()(mBuyerSeller);


  // convert object IDs into library objects
  OH_GET_REFERENCE(PremiumScheduleLibObjPtr, mPremiumSchedule,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentConvention);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSyntheticCDO(
          mObjectID,
          mBasket,
          mBuyerSeller,
          mPremiumSchedule,
          mUpfront,
          mSpread,
          mDayCounter,
          mPaymentConvention,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SyntheticCDO(
          valueObject,
          BasketLibObjPtr,
          BuyerSellerEnum,
          PremiumScheduleLibObjPtr,
          mUpfront,
          mSpread,
          DayCounterEnum,
          PaymentConventionEnum,
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

void SyntheticCDOWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SyntheticCDO) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Basket is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("BuyerSeller is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("PremiumSchedule is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Upfront is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Spread is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("PaymentConvention is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strBasket(info[1]->ToString());
  string BasketCpp(strdup(*strBasket));

  // convert js argument to c++ type
  String::Utf8Value strBuyerSeller(info[2]->ToString());
  string BuyerSellerCpp(strdup(*strBuyerSeller));

  // convert js argument to c++ type
  String::Utf8Value strPremiumSchedule(info[3]->ToString());
  string PremiumScheduleCpp(strdup(*strPremiumSchedule));

  // convert js argument to c++ type
  double UpfrontCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double SpreadCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[6]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strPaymentConvention(info[7]->ToString());
  string PaymentConventionCpp(strdup(*strPaymentConvention));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SyntheticCDOWorker(
    callback
    ,ObjectIDCpp
    ,BasketCpp
    ,BuyerSellerCpp
    ,PremiumScheduleCpp
    ,UpfrontCpp
    ,SpreadCpp
    ,DayCounterCpp
    ,PaymentConventionCpp
  ));

}

//SyntheticCDOWorker::~SyntheticCDOWorker(){
//
//}

//void SyntheticCDOWorker::Destroy(){
//
//}

void MidPointCDOEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMidPointCDOEngine(
          mObjectID,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::MidPointCDOEngine(
          valueObject,
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

void MidPointCDOEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MidPointCDOEngine) {

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
  Nan::AsyncQueueWorker(new MidPointCDOEngineWorker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
  ));

}

//MidPointCDOEngineWorker::~MidPointCDOEngineWorker(){
//
//}

//void MidPointCDOEngineWorker::Destroy(){
//
//}

void NthToDefaultWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(BasketLibObjPtr, mBasket,
      QuantLibAddin::Basket, QuantLib::Basket)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size OrderLib;
  QuantLibAddin::cppToLibrary(mOrder, OrderLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Protection::Side BuyerSellerEnum =
      ObjectHandler::Create<QuantLib::Protection::Side>()(mBuyerSeller);


  // convert object IDs into library objects
  OH_GET_REFERENCE(PremiumScheduleLibObjPtr, mPremiumSchedule,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlNthToDefault(
          mObjectID,
          mBasket,
          mOrder,
          mBuyerSeller,
          mPremiumSchedule,
          mUpfront,
          mSpread,
          mDayCounter,
          mNotional,
          mSettlesAccrual,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::NthToDefault(
          valueObject,
          BasketLibObjPtr,
          OrderLib,
          BuyerSellerEnum,
          PremiumScheduleLibObjPtr,
          mUpfront,
          mSpread,
          DayCounterEnum,
          mNotional,
          mSettlesAccrual,
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

void NthToDefaultWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::NthToDefault) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Basket is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Order is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("BuyerSeller is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("PremiumSchedule is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Upfront is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Spread is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Notional is required.");
  }
  if (info.Length() == 9 || !info[9]->IsBoolean()) {
      return Nan::ThrowError("SettlesAccrual is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strBasket(info[1]->ToString());
  string BasketCpp(strdup(*strBasket));

  // convert js argument to c++ type
  long OrderCpp = Nan::To<int32_t>(info[2]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strBuyerSeller(info[3]->ToString());
  string BuyerSellerCpp(strdup(*strBuyerSeller));

  // convert js argument to c++ type
  String::Utf8Value strPremiumSchedule(info[4]->ToString());
  string PremiumScheduleCpp(strdup(*strPremiumSchedule));

  // convert js argument to c++ type
  double UpfrontCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double SpreadCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[7]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  double NotionalCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  bool SettlesAccrualCpp = Nan::To<bool>(info[9]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new NthToDefaultWorker(
    callback
    ,ObjectIDCpp
    ,BasketCpp
    ,OrderCpp
    ,BuyerSellerCpp
    ,PremiumScheduleCpp
    ,UpfrontCpp
    ,SpreadCpp
    ,DayCounterCpp
    ,NotionalCpp
    ,SettlesAccrualCpp
  ));

}

//NthToDefaultWorker::~NthToDefaultWorker(){
//
//}

//void NthToDefaultWorker::Destroy(){
//
//}

void IntegralNtdEngineWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Period IntegrationStepLib;
  QuantLibAddin::cppToLibrary(mIntegrationStep, IntegrationStepLib);


  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlIntegralNtdEngine(
          mObjectID,
          mIntegrationStep,
          mYieldCurve,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::IntegralNtdEngine(
          valueObject,
          IntegrationStepLib,
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

void IntegralNtdEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IntegralNtdEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("IntegrationStep is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strIntegrationStep(info[1]->ToString());
  string IntegrationStepCpp(strdup(*strIntegrationStep));

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IntegralNtdEngineWorker(
    callback
    ,ObjectIDCpp
    ,IntegrationStepCpp
    ,YieldCurveCpp
  ));

}

//IntegralNtdEngineWorker::~IntegralNtdEngineWorker(){
//
//}

//void IntegralNtdEngineWorker::Destroy(){
//
//}

void BlackCdsOptionEngineWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(DefaultCurveCoerce, mDefaultCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::DefaultProbabilityTermStructure> DefaultCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::DefaultProbabilityTermStructure,
          QuantLib::DefaultProbabilityTermStructure>()(
              DefaultCurveCoerce);


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> BlackVolLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mBlackVol, "BlackVol");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackCdsOptionEngine(
          mObjectID,
          mDefaultCurve,
          mRecoveryRate,
          mYieldCurve,
          mBlackVol,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackCdsOptionEngine(
          valueObject,
          DefaultCurveLibObj,
          mRecoveryRate,
          YieldCurveLibObj,
          BlackVolLibObj,
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

void BlackCdsOptionEngineWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackCdsOptionEngine) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("RecoveryRate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t DefaultCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  double RecoveryRateCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[3]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t BlackVolCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[4]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackCdsOptionEngineWorker(
    callback
    ,ObjectIDCpp
    ,DefaultCurveCpp
    ,RecoveryRateCpp
    ,YieldCurveCpp
    ,BlackVolCpp
  ));

}

//BlackCdsOptionEngineWorker::~BlackCdsOptionEngineWorker(){
//
//}

//void BlackCdsOptionEngineWorker::Destroy(){
//
//}

void CDSOptionWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(UnderlyingCDSLibObjPtr, mUnderlyingCDS,
      QuantLibAddin::CreditDefaultSwap, QuantLib::CreditDefaultSwap)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCDSOption(
          mObjectID,
          mUnderlyingCDS,
          mExercise,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CdsOption(
          valueObject,
          UnderlyingCDSLibObjPtr,
          ExerciseLibObjPtr,
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

void CDSOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CDSOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("UnderlyingCDS is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strUnderlyingCDS(info[1]->ToString());
  string UnderlyingCDSCpp(strdup(*strUnderlyingCDS));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[2]->ToString());
  string ExerciseCpp(strdup(*strExercise));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CDSOptionWorker(
    callback
    ,ObjectIDCpp
    ,UnderlyingCDSCpp
    ,ExerciseCpp
  ));

}

//CDSOptionWorker::~CDSOptionWorker(){
//
//}

//void CDSOptionWorker::Destroy(){
//
//}

void BaseCorrelationTermStructureWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SettlementDaysLib;
  QuantLibAddin::cppToLibrary(mSettlementDays, SettlementDaysLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention ConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mConvention);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> TenorsLib;


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> LossLevelLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mLossLevel);


  // convert object IDs into library objects
  std::vector< std::vector< QuantLib::Handle<QuantLib::Quote> > > CorrelationsLibObj =
      ObjectHandler::matrix::convert2< QuantLib::Handle<QuantLib::Quote> >(mCorrelations, "Correlations");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBaseCorrelationTermStructure(
          mObjectID,
          mInterpolatorType,
          mSettlementDays,
          mCalendar,
          mConvention,
          mTenors,
          mLossLevel,
          mCorrelations,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BaseCorrelationTermStructure(
          valueObject,
          mInterpolatorType,
          SettlementDaysLib,
          CalendarEnum,
          ConventionEnum,
          TenorsLib,
          mLossLevel,
          CorrelationsLibObj,
          DayCounterEnum,
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

void BaseCorrelationTermStructureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BaseCorrelationTermStructure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("InterpolatorType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("SettlementDays is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Convention is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("Tenors is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("LossLevel is required.");
  }
  if (info.Length() == 7 || !info[7]->IsArray()) {
      return Nan::ThrowError("Correlations is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strInterpolatorType(info[1]->ToString());
  string InterpolatorTypeCpp(strdup(*strInterpolatorType));

  // convert js argument to c++ type
  long SettlementDaysCpp = Nan::To<int32_t>(info[2]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[3]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  String::Utf8Value strConvention(info[4]->ToString());
  string ConventionCpp(strdup(*strConvention));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>TenorsCpp;

  Local<Array> TenorsArray = info[5].As<Array>();
  for (unsigned int i = 0; i < TenorsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(TenorsArray, i).ToLocalChecked()).FromJust()));
    TenorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>LossLevelCpp;

  Local<Array> LossLevelArray = info[6].As<Array>();
  for (unsigned int i = 0; i < LossLevelArray->Length(); i++){
    LossLevelCpp.push_back(Nan::To<double>(Nan::Get(LossLevelArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector< std::vector<ObjectHandler::property_t> >CorrelationsCpp;

  Local<Array> CorrelationsMatrix = info[7].As<Array>();
  for (unsigned int i = 0; i < CorrelationsMatrix->Length(); i++){
	  Local<Array> CorrelationsArray = CorrelationsMatrix->Get(i).As<Array>();
	  std::vector<ObjectHandler::property_t> tmp;
	  for (unsigned int j = 0; j < CorrelationsArray->Length(); j++){
      ObjectHandler::property_t temp =
          ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(CorrelationsArray, j).ToLocalChecked()).FromJust()));
		  tmp.push_back(temp);
	  }
	  CorrelationsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[8]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BaseCorrelationTermStructureWorker(
    callback
    ,ObjectIDCpp
    ,InterpolatorTypeCpp
    ,SettlementDaysCpp
    ,CalendarCpp
    ,ConventionCpp
    ,TenorsCpp
    ,LossLevelCpp
    ,CorrelationsCpp
    ,DayCounterCpp
  ));

}

//BaseCorrelationTermStructureWorker::~BaseCorrelationTermStructureWorker(){
//
//}

//void BaseCorrelationTermStructureWorker::Destroy(){
//
//}

void CdsCouponLegNPVWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CreditDefaultSwap, QuantLib::CreditDefaultSwap)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->couponLegNPV(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CdsCouponLegNPVWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CdsCouponLegNPV) {

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
  Nan::AsyncQueueWorker(new CdsCouponLegNPVWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CdsCouponLegNPVWorker::~CdsCouponLegNPVWorker(){
//
//}

//void CdsCouponLegNPVWorker::Destroy(){
//
//}

void CdsDefaultLegNPVWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CreditDefaultSwap, QuantLib::CreditDefaultSwap)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->defaultLegNPV(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CdsDefaultLegNPVWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CdsDefaultLegNPV) {

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
  Nan::AsyncQueueWorker(new CdsDefaultLegNPVWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CdsDefaultLegNPVWorker::~CdsDefaultLegNPVWorker(){
//
//}

//void CdsDefaultLegNPVWorker::Destroy(){
//
//}

void CdsFairSpreadWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CreditDefaultSwap, QuantLib::CreditDefaultSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->fairSpread(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CdsFairSpreadWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CdsFairSpread) {

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
  Nan::AsyncQueueWorker(new CdsFairSpreadWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CdsFairSpreadWorker::~CdsFairSpreadWorker(){
//
//}

//void CdsFairSpreadWorker::Destroy(){
//
//}

void CdsFairUpfrontWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CreditDefaultSwap, QuantLib::CreditDefaultSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->fairUpfront(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CdsFairUpfrontWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CdsFairUpfront) {

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
  Nan::AsyncQueueWorker(new CdsFairUpfrontWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CdsFairUpfrontWorker::~CdsFairUpfrontWorker(){
//
//}

//void CdsFairUpfrontWorker::Destroy(){
//
//}

void HRDatesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::PiecewiseHazardRateCurve)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Date> returnValue = ObjectIDObjPtr->dates(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HRDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::HRDates) {

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
  Nan::AsyncQueueWorker(new HRDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//HRDatesWorker::~HRDatesWorker(){
//
//}

//void HRDatesWorker::Destroy(){
//
//}

void HRatesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::PiecewiseHazardRateCurve)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDObjPtr->data(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void HRatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::HRates) {

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
  Nan::AsyncQueueWorker(new HRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//HRatesWorker::~HRatesWorker(){
//
//}

//void HRatesWorker::Destroy(){
//
//}

void CdsOptionImpliedVolWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);


  // convert object IDs into library objects
  OH_GET_OBJECT(DefaultCurveCoerce, mDefaultCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::DefaultProbabilityTermStructure> DefaultCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::DefaultProbabilityTermStructure,
          QuantLib::DefaultProbabilityTermStructure>()(
              DefaultCurveCoerce);


  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CdsOption, QuantLib::CdsOption)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->impliedVolatility(
        mPrice
        ,
         YieldCurveLibObj
        ,
         DefaultCurveLibObj
        ,
         mRecoveryRate
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CdsOptionImpliedVolWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CdsOptionImpliedVol) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Price is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("RecoveryRate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double PriceCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t YieldCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t DefaultCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[3]).FromJust()));

  // convert js argument to c++ type
  double RecoveryRateCpp = Nan::To<double>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CdsOptionImpliedVolWorker(
    callback
    ,ObjectIDCpp
    ,PriceCpp
    ,YieldCurveCpp
    ,DefaultCurveCpp
    ,RecoveryRateCpp
  ));

}

//CdsOptionImpliedVolWorker::~CdsOptionImpliedVolWorker(){
//
//}

//void CdsOptionImpliedVolWorker::Destroy(){
//
//}

void BaseCorrelationValueWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::BaseCorrelationTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DateLib = ObjectHandler::convert2<QuantLib::Date>(
      mDate, "Date");


  // convert input datatypes to QuantLib datatypes
     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->correlation(
        DateLib
        ,
         mLossLevel
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BaseCorrelationValueWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BaseCorrelationValue) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("LossLevel is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t DateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  double LossLevelCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BaseCorrelationValueWorker(
    callback
    ,ObjectIDCpp
    ,DateCpp
    ,LossLevelCpp
  ));

}

//BaseCorrelationValueWorker::~BaseCorrelationValueWorker(){
//
//}

//void BaseCorrelationValueWorker::Destroy(){
//
//}
 