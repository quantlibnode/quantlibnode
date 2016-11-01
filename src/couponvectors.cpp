// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "couponvectors.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/couponvectors.hpp>
#include <qlo/schedule.hpp>
#include <qlo/conundrumpricer.hpp>
#include <qlo/termstructures.hpp>
#include <qlo/indexes/iborindex.hpp>
#include <qlo/indexes/swapindex.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/indexes/swapindex.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void FixedRateLegWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFixedRateLeg(
          mObjectID,
          mPaymentBDC,
          mNominals,
          mScheduleID,
          mCoupons,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FixedRateLeg(
          valueObject,
          PaymentBDCEnum,
          mNominals,
          ScheduleIDLibObjPtr,
          mCoupons,
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

void FixedRateLegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FixedRateLeg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Nominals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("Coupons is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[1]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  std::vector<double>NominalsCpp;

  Local<Array> NominalsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < NominalsArray->Length(); i++){
    NominalsCpp.push_back(Nan::To<double>(Nan::Get(NominalsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[3]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<double>CouponsCpp;

  Local<Array> CouponsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < CouponsArray->Length(); i++){
    CouponsCpp.push_back(Nan::To<double>(Nan::Get(CouponsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[5]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FixedRateLegWorker(
    callback
    ,ObjectIDCpp
    ,PaymentBDCCpp
    ,NominalsCpp
    ,ScheduleIDCpp
    ,CouponsCpp
    ,DayCounterCpp
  ));

}

//FixedRateLegWorker::~FixedRateLegWorker(){
//
//}

//FixedRateLegWorker::Destroy(){
//
//}

void FixedRateLeg2Worker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLib::InterestRate> > CouponsLibObjPtr =
      ObjectHandler::getLibraryObjectVector<QuantLibAddin::InterestRate, QuantLib::InterestRate>(mCoupons);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlFixedRateLeg2(
          mObjectID,
          mPaymentBDC,
          mNominals,
          mScheduleID,
          mCoupons,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::FixedRateLeg(
          valueObject,
          PaymentBDCEnum,
          mNominals,
          ScheduleIDLibObjPtr,
          CouponsLibObjPtr,
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

void FixedRateLeg2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::FixedRateLeg2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Nominals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("Coupons is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[1]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  std::vector<double>NominalsCpp;

  Local<Array> NominalsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < NominalsArray->Length(); i++){
    NominalsCpp.push_back(Nan::To<double>(Nan::Get(NominalsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[3]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<string>CouponsCpp;

  Local<Array> CouponsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < CouponsArray->Length(); i++){
    String::Utf8Value strCoupons(Nan::Get(CouponsArray, i).ToLocalChecked()->ToString());
    CouponsCpp.push_back(strdup(*strCoupons));
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new FixedRateLeg2Worker(
    callback
    ,ObjectIDCpp
    ,PaymentBDCCpp
    ,NominalsCpp
    ,ScheduleIDCpp
    ,CouponsCpp
  ));

}

//FixedRateLeg2Worker::~FixedRateLeg2Worker(){
//
//}

//FixedRateLeg2Worker::Destroy(){
//
//}

void IborLegWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib datatypes
  std::vector<long> FixingDaysCpp;
  std::vector<QuantLib::Natural> FixingDaysLib =
      QuantLibAddin::convertVector<long, QuantLib::Natural>(FixingDaysCpp);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlIborLeg(
          mObjectID,
          mPaymentBDC,
          mNominals,
          mScheduleID,
          FixingDaysCpp,
          mIsInArrears,
          mDayCounter,
          mFloors,
          mGearings,
          mIborIndex,
          mSpreads,
          mCaps,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::IborLeg(
          valueObject,
          PaymentBDCEnum,
          mNominals,
          ScheduleIDLibObjPtr,
          FixingDaysLib,
          mIsInArrears,
          DayCounterEnum,
          mFloors,
          mGearings,
          IborIndexLibObjPtr,
          mSpreads,
          mCaps,
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

void IborLegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IborLeg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Nominals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("FixingDays is required.");
  }
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IsInArrears is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 7 || !info[7]->IsArray()) {
      return Nan::ThrowError("Floors is required.");
  }
  if (info.Length() == 8 || !info[8]->IsArray()) {
      return Nan::ThrowError("Gearings is required.");
  }
  if (info.Length() == 9 || !info[9]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("Spreads is required.");
  }
  if (info.Length() == 11 || !info[11]->IsArray()) {
      return Nan::ThrowError("Caps is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[1]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  std::vector<double>NominalsCpp;

  Local<Array> NominalsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < NominalsArray->Length(); i++){
    NominalsCpp.push_back(Nan::To<double>(Nan::Get(NominalsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[3]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>FixingDaysCpp;

  Local<Array> FixingDaysArray = info[4].As<Array>();
  for (unsigned int i = 0; i < FixingDaysArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(FixingDaysArray, i).ToLocalChecked()).FromJust()));
    FixingDaysCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool IsInArrearsCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[6]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  std::vector<double>FloorsCpp;

  Local<Array> FloorsArray = info[7].As<Array>();
  for (unsigned int i = 0; i < FloorsArray->Length(); i++){
    FloorsCpp.push_back(Nan::To<double>(Nan::Get(FloorsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>GearingsCpp;

  Local<Array> GearingsArray = info[8].As<Array>();
  for (unsigned int i = 0; i < GearingsArray->Length(); i++){
    GearingsCpp.push_back(Nan::To<double>(Nan::Get(GearingsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[9]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  std::vector<double>SpreadsCpp;

  Local<Array> SpreadsArray = info[10].As<Array>();
  for (unsigned int i = 0; i < SpreadsArray->Length(); i++){
    SpreadsCpp.push_back(Nan::To<double>(Nan::Get(SpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>CapsCpp;

  Local<Array> CapsArray = info[11].As<Array>();
  for (unsigned int i = 0; i < CapsArray->Length(); i++){
    CapsCpp.push_back(Nan::To<double>(Nan::Get(CapsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[12].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IborLegWorker(
    callback
    ,ObjectIDCpp
    ,PaymentBDCCpp
    ,NominalsCpp
    ,ScheduleIDCpp
    ,FixingDaysCpp
    ,IsInArrearsCpp
    ,DayCounterCpp
    ,FloorsCpp
    ,GearingsCpp
    ,IborIndexCpp
    ,SpreadsCpp
    ,CapsCpp
  ));

}

//IborLegWorker::~IborLegWorker(){
//
//}

//IborLegWorker::Destroy(){
//
//}

void DigitalIborLegWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib datatypes
  std::vector<long> FixingDaysCpp;
  std::vector<QuantLib::Natural> FixingDaysLib =
      QuantLibAddin::convertVector<long, QuantLib::Natural>(FixingDaysCpp);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ReplicationLibObjPtr, mReplication,
      QuantLibAddin::DigitalReplication, QuantLib::DigitalReplication)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlDigitalIborLeg(
          mObjectID,
          mPaymentBDC,
          mNominals,
          mScheduleID,
          FixingDaysCpp,
          mIsInArrears,
          mDayCounter,
          mGearings,
          mIborIndex,
          mSpreads,
          mCallStrikes,
          mCallSpecs,
          mCallPayoff,
          mPutStrikes,
          mPutSpecs,
          mPutPayoff,
          mReplication,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::DigitalIborLeg(
          valueObject,
          PaymentBDCEnum,
          mNominals,
          ScheduleIDLibObjPtr,
          FixingDaysLib,
          mIsInArrears,
          DayCounterEnum,
          mGearings,
          IborIndexLibObjPtr,
          mSpreads,
          mCallStrikes,
          mCallSpecs,
          mCallPayoff,
          mPutStrikes,
          mPutSpecs,
          mPutPayoff,
          ReplicationLibObjPtr,
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

void DigitalIborLegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DigitalIborLeg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Nominals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("FixingDays is required.");
  }
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IsInArrears is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 7 || !info[7]->IsArray()) {
      return Nan::ThrowError("Gearings is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 9 || !info[9]->IsArray()) {
      return Nan::ThrowError("Spreads is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("CallStrikes is required.");
  }
  if (info.Length() == 11 || !info[11]->IsString()) {
      return Nan::ThrowError("CallSpecs is required.");
  }
  if (info.Length() == 12 || !info[12]->IsArray()) {
      return Nan::ThrowError("CallPayoff is required.");
  }
  if (info.Length() == 13 || !info[13]->IsArray()) {
      return Nan::ThrowError("PutStrikes is required.");
  }
  if (info.Length() == 14 || !info[14]->IsString()) {
      return Nan::ThrowError("PutSpecs is required.");
  }
  if (info.Length() == 15 || !info[15]->IsArray()) {
      return Nan::ThrowError("PutPayoff is required.");
  }
  if (info.Length() == 16 || !info[16]->IsString()) {
      return Nan::ThrowError("Replication is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[1]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  std::vector<double>NominalsCpp;

  Local<Array> NominalsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < NominalsArray->Length(); i++){
    NominalsCpp.push_back(Nan::To<double>(Nan::Get(NominalsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[3]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>FixingDaysCpp;

  Local<Array> FixingDaysArray = info[4].As<Array>();
  for (unsigned int i = 0; i < FixingDaysArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(FixingDaysArray, i).ToLocalChecked()).FromJust()));
    FixingDaysCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool IsInArrearsCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[6]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  std::vector<double>GearingsCpp;

  Local<Array> GearingsArray = info[7].As<Array>();
  for (unsigned int i = 0; i < GearingsArray->Length(); i++){
    GearingsCpp.push_back(Nan::To<double>(Nan::Get(GearingsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[8]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  std::vector<double>SpreadsCpp;

  Local<Array> SpreadsArray = info[9].As<Array>();
  for (unsigned int i = 0; i < SpreadsArray->Length(); i++){
    SpreadsCpp.push_back(Nan::To<double>(Nan::Get(SpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>CallStrikesCpp;

  Local<Array> CallStrikesArray = info[10].As<Array>();
  for (unsigned int i = 0; i < CallStrikesArray->Length(); i++){
    CallStrikesCpp.push_back(Nan::To<double>(Nan::Get(CallStrikesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strCallSpecs(info[11]->ToString());
  string CallSpecsCpp(strdup(*strCallSpecs));

  // convert js argument to c++ type
  std::vector<double>CallPayoffCpp;

  Local<Array> CallPayoffArray = info[12].As<Array>();
  for (unsigned int i = 0; i < CallPayoffArray->Length(); i++){
    CallPayoffCpp.push_back(Nan::To<double>(Nan::Get(CallPayoffArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>PutStrikesCpp;

  Local<Array> PutStrikesArray = info[13].As<Array>();
  for (unsigned int i = 0; i < PutStrikesArray->Length(); i++){
    PutStrikesCpp.push_back(Nan::To<double>(Nan::Get(PutStrikesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strPutSpecs(info[14]->ToString());
  string PutSpecsCpp(strdup(*strPutSpecs));

  // convert js argument to c++ type
  std::vector<double>PutPayoffCpp;

  Local<Array> PutPayoffArray = info[15].As<Array>();
  for (unsigned int i = 0; i < PutPayoffArray->Length(); i++){
    PutPayoffCpp.push_back(Nan::To<double>(Nan::Get(PutPayoffArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strReplication(info[16]->ToString());
  string ReplicationCpp(strdup(*strReplication));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[17].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DigitalIborLegWorker(
    callback
    ,ObjectIDCpp
    ,PaymentBDCCpp
    ,NominalsCpp
    ,ScheduleIDCpp
    ,FixingDaysCpp
    ,IsInArrearsCpp
    ,DayCounterCpp
    ,GearingsCpp
    ,IborIndexCpp
    ,SpreadsCpp
    ,CallStrikesCpp
    ,CallSpecsCpp
    ,CallPayoffCpp
    ,PutStrikesCpp
    ,PutSpecsCpp
    ,PutPayoffCpp
    ,ReplicationCpp
  ));

}

//DigitalIborLegWorker::~DigitalIborLegWorker(){
//
//}

//DigitalIborLegWorker::Destroy(){
//
//}

void CmsLegWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib datatypes
  std::vector<long> FixingDaysCpp;
  std::vector<QuantLib::Natural> FixingDaysLib =
      QuantLibAddin::convertVector<long, QuantLib::Natural>(FixingDaysCpp);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapIndexLibObjPtr, mSwapIndex,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCmsLeg(
          mObjectID,
          mPaymentBDC,
          mNominals,
          mScheduleID,
          FixingDaysCpp,
          mIsInArrears,
          mDayCounter,
          mFloors,
          mGearings,
          mSwapIndex,
          mSpreads,
          mCaps,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CmsLeg(
          valueObject,
          PaymentBDCEnum,
          mNominals,
          ScheduleIDLibObjPtr,
          FixingDaysLib,
          mIsInArrears,
          DayCounterEnum,
          mFloors,
          mGearings,
          SwapIndexLibObjPtr,
          mSpreads,
          mCaps,
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

void CmsLegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CmsLeg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Nominals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("FixingDays is required.");
  }
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IsInArrears is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 7 || !info[7]->IsArray()) {
      return Nan::ThrowError("Floors is required.");
  }
  if (info.Length() == 8 || !info[8]->IsArray()) {
      return Nan::ThrowError("Gearings is required.");
  }
  if (info.Length() == 9 || !info[9]->IsString()) {
      return Nan::ThrowError("SwapIndex is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("Spreads is required.");
  }
  if (info.Length() == 11 || !info[11]->IsArray()) {
      return Nan::ThrowError("Caps is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[1]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  std::vector<double>NominalsCpp;

  Local<Array> NominalsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < NominalsArray->Length(); i++){
    NominalsCpp.push_back(Nan::To<double>(Nan::Get(NominalsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[3]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>FixingDaysCpp;

  Local<Array> FixingDaysArray = info[4].As<Array>();
  for (unsigned int i = 0; i < FixingDaysArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(FixingDaysArray, i).ToLocalChecked()).FromJust()));
    FixingDaysCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool IsInArrearsCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[6]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  std::vector<double>FloorsCpp;

  Local<Array> FloorsArray = info[7].As<Array>();
  for (unsigned int i = 0; i < FloorsArray->Length(); i++){
    FloorsCpp.push_back(Nan::To<double>(Nan::Get(FloorsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>GearingsCpp;

  Local<Array> GearingsArray = info[8].As<Array>();
  for (unsigned int i = 0; i < GearingsArray->Length(); i++){
    GearingsCpp.push_back(Nan::To<double>(Nan::Get(GearingsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapIndex(info[9]->ToString());
  string SwapIndexCpp(strdup(*strSwapIndex));

  // convert js argument to c++ type
  std::vector<double>SpreadsCpp;

  Local<Array> SpreadsArray = info[10].As<Array>();
  for (unsigned int i = 0; i < SpreadsArray->Length(); i++){
    SpreadsCpp.push_back(Nan::To<double>(Nan::Get(SpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>CapsCpp;

  Local<Array> CapsArray = info[11].As<Array>();
  for (unsigned int i = 0; i < CapsArray->Length(); i++){
    CapsCpp.push_back(Nan::To<double>(Nan::Get(CapsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[12].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CmsLegWorker(
    callback
    ,ObjectIDCpp
    ,PaymentBDCCpp
    ,NominalsCpp
    ,ScheduleIDCpp
    ,FixingDaysCpp
    ,IsInArrearsCpp
    ,DayCounterCpp
    ,FloorsCpp
    ,GearingsCpp
    ,SwapIndexCpp
    ,SpreadsCpp
    ,CapsCpp
  ));

}

//CmsLegWorker::~CmsLegWorker(){
//
//}

//CmsLegWorker::Destroy(){
//
//}

void DigitalCmsLegWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib datatypes
  std::vector<long> FixingDaysCpp;
  std::vector<QuantLib::Natural> FixingDaysLib =
      QuantLibAddin::convertVector<long, QuantLib::Natural>(FixingDaysCpp);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapIndexLibObjPtr, mSwapIndex,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ReplicationLibObjPtr, mReplication,
      QuantLibAddin::DigitalReplication, QuantLib::DigitalReplication)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlDigitalCmsLeg(
          mObjectID,
          mPaymentBDC,
          mNominals,
          mScheduleID,
          FixingDaysCpp,
          mIsInArrears,
          mDayCounter,
          mGearings,
          mSwapIndex,
          mSpreads,
          mCallStrikes,
          mCallSpecs,
          mCallPayoff,
          mPutStrikes,
          mPutSpecs,
          mPutPayoff,
          mReplication,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::DigitalCmsLeg(
          valueObject,
          PaymentBDCEnum,
          mNominals,
          ScheduleIDLibObjPtr,
          FixingDaysLib,
          mIsInArrears,
          DayCounterEnum,
          mGearings,
          SwapIndexLibObjPtr,
          mSpreads,
          mCallStrikes,
          mCallSpecs,
          mCallPayoff,
          mPutStrikes,
          mPutSpecs,
          mPutPayoff,
          ReplicationLibObjPtr,
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

void DigitalCmsLegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DigitalCmsLeg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Nominals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("FixingDays is required.");
  }
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IsInArrears is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 7 || !info[7]->IsArray()) {
      return Nan::ThrowError("Gearings is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("SwapIndex is required.");
  }
  if (info.Length() == 9 || !info[9]->IsArray()) {
      return Nan::ThrowError("Spreads is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("CallStrikes is required.");
  }
  if (info.Length() == 11 || !info[11]->IsString()) {
      return Nan::ThrowError("CallSpecs is required.");
  }
  if (info.Length() == 12 || !info[12]->IsArray()) {
      return Nan::ThrowError("CallPayoff is required.");
  }
  if (info.Length() == 13 || !info[13]->IsArray()) {
      return Nan::ThrowError("PutStrikes is required.");
  }
  if (info.Length() == 14 || !info[14]->IsString()) {
      return Nan::ThrowError("PutSpecs is required.");
  }
  if (info.Length() == 15 || !info[15]->IsArray()) {
      return Nan::ThrowError("PutPayoff is required.");
  }
  if (info.Length() == 16 || !info[16]->IsString()) {
      return Nan::ThrowError("Replication is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[1]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  std::vector<double>NominalsCpp;

  Local<Array> NominalsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < NominalsArray->Length(); i++){
    NominalsCpp.push_back(Nan::To<double>(Nan::Get(NominalsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[3]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>FixingDaysCpp;

  Local<Array> FixingDaysArray = info[4].As<Array>();
  for (unsigned int i = 0; i < FixingDaysArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(FixingDaysArray, i).ToLocalChecked()).FromJust()));
    FixingDaysCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool IsInArrearsCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[6]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  std::vector<double>GearingsCpp;

  Local<Array> GearingsArray = info[7].As<Array>();
  for (unsigned int i = 0; i < GearingsArray->Length(); i++){
    GearingsCpp.push_back(Nan::To<double>(Nan::Get(GearingsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapIndex(info[8]->ToString());
  string SwapIndexCpp(strdup(*strSwapIndex));

  // convert js argument to c++ type
  std::vector<double>SpreadsCpp;

  Local<Array> SpreadsArray = info[9].As<Array>();
  for (unsigned int i = 0; i < SpreadsArray->Length(); i++){
    SpreadsCpp.push_back(Nan::To<double>(Nan::Get(SpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>CallStrikesCpp;

  Local<Array> CallStrikesArray = info[10].As<Array>();
  for (unsigned int i = 0; i < CallStrikesArray->Length(); i++){
    CallStrikesCpp.push_back(Nan::To<double>(Nan::Get(CallStrikesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strCallSpecs(info[11]->ToString());
  string CallSpecsCpp(strdup(*strCallSpecs));

  // convert js argument to c++ type
  std::vector<double>CallPayoffCpp;

  Local<Array> CallPayoffArray = info[12].As<Array>();
  for (unsigned int i = 0; i < CallPayoffArray->Length(); i++){
    CallPayoffCpp.push_back(Nan::To<double>(Nan::Get(CallPayoffArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>PutStrikesCpp;

  Local<Array> PutStrikesArray = info[13].As<Array>();
  for (unsigned int i = 0; i < PutStrikesArray->Length(); i++){
    PutStrikesCpp.push_back(Nan::To<double>(Nan::Get(PutStrikesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strPutSpecs(info[14]->ToString());
  string PutSpecsCpp(strdup(*strPutSpecs));

  // convert js argument to c++ type
  std::vector<double>PutPayoffCpp;

  Local<Array> PutPayoffArray = info[15].As<Array>();
  for (unsigned int i = 0; i < PutPayoffArray->Length(); i++){
    PutPayoffCpp.push_back(Nan::To<double>(Nan::Get(PutPayoffArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strReplication(info[16]->ToString());
  string ReplicationCpp(strdup(*strReplication));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[17].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DigitalCmsLegWorker(
    callback
    ,ObjectIDCpp
    ,PaymentBDCCpp
    ,NominalsCpp
    ,ScheduleIDCpp
    ,FixingDaysCpp
    ,IsInArrearsCpp
    ,DayCounterCpp
    ,GearingsCpp
    ,SwapIndexCpp
    ,SpreadsCpp
    ,CallStrikesCpp
    ,CallSpecsCpp
    ,CallPayoffCpp
    ,PutStrikesCpp
    ,PutSpecsCpp
    ,PutPayoffCpp
    ,ReplicationCpp
  ));

}

//DigitalCmsLegWorker::~DigitalCmsLegWorker(){
//
//}

//DigitalCmsLegWorker::Destroy(){
//
//}

void RangeAccrualLegWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib datatypes
  std::vector<long> FixingDaysCpp;
  std::vector<QuantLib::Natural> FixingDaysLib =
      QuantLibAddin::convertVector<long, QuantLib::Natural>(FixingDaysCpp);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period ObservationsTenorLib;
  QuantLibAddin::cppToLibrary(mObservationsTenor, ObservationsTenorLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention ObservationsBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mObservationsBDC);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRangeAccrualLeg(
          mObjectID,
          mPaymentBDC,
          mNominals,
          mScheduleID,
          FixingDaysCpp,
          mDayCounter,
          mLowerStrikes,
          mGearings,
          mIborIndex,
          mSpreads,
          mUpperStrikes,
          mObservationsTenor,
          mObservationsBDC,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RangeAccrualLeg(
          valueObject,
          PaymentBDCEnum,
          mNominals,
          ScheduleIDLibObjPtr,
          FixingDaysLib,
          DayCounterEnum,
          mLowerStrikes,
          mGearings,
          IborIndexLibObjPtr,
          mSpreads,
          mUpperStrikes,
          ObservationsTenorLib,
          ObservationsBDCEnum,
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

void RangeAccrualLegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RangeAccrualLeg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Nominals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("FixingDays is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 6 || !info[6]->IsArray()) {
      return Nan::ThrowError("LowerStrikes is required.");
  }
  if (info.Length() == 7 || !info[7]->IsArray()) {
      return Nan::ThrowError("Gearings is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 9 || !info[9]->IsArray()) {
      return Nan::ThrowError("Spreads is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("UpperStrikes is required.");
  }
  if (info.Length() == 11 || !info[11]->IsString()) {
      return Nan::ThrowError("ObservationsTenor is required.");
  }
  if (info.Length() == 12 || !info[12]->IsString()) {
      return Nan::ThrowError("ObservationsBDC is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[1]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  std::vector<double>NominalsCpp;

  Local<Array> NominalsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < NominalsArray->Length(); i++){
    NominalsCpp.push_back(Nan::To<double>(Nan::Get(NominalsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[3]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>FixingDaysCpp;

  Local<Array> FixingDaysArray = info[4].As<Array>();
  for (unsigned int i = 0; i < FixingDaysArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(FixingDaysArray, i).ToLocalChecked()).FromJust()));
    FixingDaysCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[5]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  std::vector<double>LowerStrikesCpp;

  Local<Array> LowerStrikesArray = info[6].As<Array>();
  for (unsigned int i = 0; i < LowerStrikesArray->Length(); i++){
    LowerStrikesCpp.push_back(Nan::To<double>(Nan::Get(LowerStrikesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>GearingsCpp;

  Local<Array> GearingsArray = info[7].As<Array>();
  for (unsigned int i = 0; i < GearingsArray->Length(); i++){
    GearingsCpp.push_back(Nan::To<double>(Nan::Get(GearingsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[8]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  std::vector<double>SpreadsCpp;

  Local<Array> SpreadsArray = info[9].As<Array>();
  for (unsigned int i = 0; i < SpreadsArray->Length(); i++){
    SpreadsCpp.push_back(Nan::To<double>(Nan::Get(SpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>UpperStrikesCpp;

  Local<Array> UpperStrikesArray = info[10].As<Array>();
  for (unsigned int i = 0; i < UpperStrikesArray->Length(); i++){
    UpperStrikesCpp.push_back(Nan::To<double>(Nan::Get(UpperStrikesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strObservationsTenor(info[11]->ToString());
  string ObservationsTenorCpp(strdup(*strObservationsTenor));

  // convert js argument to c++ type
  String::Utf8Value strObservationsBDC(info[12]->ToString());
  string ObservationsBDCCpp(strdup(*strObservationsBDC));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[13].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RangeAccrualLegWorker(
    callback
    ,ObjectIDCpp
    ,PaymentBDCCpp
    ,NominalsCpp
    ,ScheduleIDCpp
    ,FixingDaysCpp
    ,DayCounterCpp
    ,LowerStrikesCpp
    ,GearingsCpp
    ,IborIndexCpp
    ,SpreadsCpp
    ,UpperStrikesCpp
    ,ObservationsTenorCpp
    ,ObservationsBDCCpp
  ));

}

//RangeAccrualLegWorker::~RangeAccrualLegWorker(){
//
//}

//RangeAccrualLegWorker::Destroy(){
//
//}

void CmsZeroLegWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention PaymentBDCEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mPaymentBDC);


  // convert object IDs into library objects
  OH_GET_REFERENCE(ScheduleIDLibObjPtr, mScheduleID,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib datatypes
  std::vector<long> FixingDaysCpp;
  std::vector<QuantLib::Natural> FixingDaysLib =
      QuantLibAddin::convertVector<long, QuantLib::Natural>(FixingDaysCpp);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapIndexLibObjPtr, mSwapIndex,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCmsZeroLeg(
          mObjectID,
          mPaymentBDC,
          mNominals,
          mScheduleID,
          FixingDaysCpp,
          mIsInArrears,
          mDayCounter,
          mFloors,
          mGearings,
          mSwapIndex,
          mSpreads,
          mCaps,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CmsZeroLeg(
          valueObject,
          PaymentBDCEnum,
          mNominals,
          ScheduleIDLibObjPtr,
          FixingDaysLib,
          mIsInArrears,
          DayCounterEnum,
          mFloors,
          mGearings,
          SwapIndexLibObjPtr,
          mSpreads,
          mCaps,
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

void CmsZeroLegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CmsZeroLeg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("PaymentBDC is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Nominals is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("ScheduleID is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("FixingDays is required.");
  }
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IsInArrears is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 7 || !info[7]->IsArray()) {
      return Nan::ThrowError("Floors is required.");
  }
  if (info.Length() == 8 || !info[8]->IsArray()) {
      return Nan::ThrowError("Gearings is required.");
  }
  if (info.Length() == 9 || !info[9]->IsString()) {
      return Nan::ThrowError("SwapIndex is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("Spreads is required.");
  }
  if (info.Length() == 11 || !info[11]->IsArray()) {
      return Nan::ThrowError("Caps is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPaymentBDC(info[1]->ToString());
  string PaymentBDCCpp(strdup(*strPaymentBDC));

  // convert js argument to c++ type
  std::vector<double>NominalsCpp;

  Local<Array> NominalsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < NominalsArray->Length(); i++){
    NominalsCpp.push_back(Nan::To<double>(Nan::Get(NominalsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strScheduleID(info[3]->ToString());
  string ScheduleIDCpp(strdup(*strScheduleID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>FixingDaysCpp;

  Local<Array> FixingDaysArray = info[4].As<Array>();
  for (unsigned int i = 0; i < FixingDaysArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(FixingDaysArray, i).ToLocalChecked()).FromJust()));
    FixingDaysCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool IsInArrearsCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[6]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  std::vector<double>FloorsCpp;

  Local<Array> FloorsArray = info[7].As<Array>();
  for (unsigned int i = 0; i < FloorsArray->Length(); i++){
    FloorsCpp.push_back(Nan::To<double>(Nan::Get(FloorsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>GearingsCpp;

  Local<Array> GearingsArray = info[8].As<Array>();
  for (unsigned int i = 0; i < GearingsArray->Length(); i++){
    GearingsCpp.push_back(Nan::To<double>(Nan::Get(GearingsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapIndex(info[9]->ToString());
  string SwapIndexCpp(strdup(*strSwapIndex));

  // convert js argument to c++ type
  std::vector<double>SpreadsCpp;

  Local<Array> SpreadsArray = info[10].As<Array>();
  for (unsigned int i = 0; i < SpreadsArray->Length(); i++){
    SpreadsCpp.push_back(Nan::To<double>(Nan::Get(SpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>CapsCpp;

  Local<Array> CapsArray = info[11].As<Array>();
  for (unsigned int i = 0; i < CapsArray->Length(); i++){
    CapsCpp.push_back(Nan::To<double>(Nan::Get(CapsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[12].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CmsZeroLegWorker(
    callback
    ,ObjectIDCpp
    ,PaymentBDCCpp
    ,NominalsCpp
    ,ScheduleIDCpp
    ,FixingDaysCpp
    ,IsInArrearsCpp
    ,DayCounterCpp
    ,FloorsCpp
    ,GearingsCpp
    ,SwapIndexCpp
    ,SpreadsCpp
    ,CapsCpp
  ));

}

//CmsZeroLegWorker::~CmsZeroLegWorker(){
//
//}

//CmsZeroLegWorker::Destroy(){
//
//}

void IborCouponPricerWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(VolatilityCoerce, mVolatility, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::OptionletVolatilityStructure> VolatilityLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::OptionletVolatilityStructure,
          QuantLib::OptionletVolatilityStructure>()(
              VolatilityCoerce);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlIborCouponPricer(
          mObjectID,
          mVolatility,
          mIborCouponPricerType,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::IborCouponPricer(
          valueObject,
          VolatilityLibObj,
          mIborCouponPricerType,
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

void IborCouponPricerWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IborCouponPricer) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("IborCouponPricerType is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t VolatilityCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strIborCouponPricerType(info[2]->ToString());
  string IborCouponPricerTypeCpp(strdup(*strIborCouponPricerType));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IborCouponPricerWorker(
    callback
    ,ObjectIDCpp
    ,VolatilityCpp
    ,IborCouponPricerTypeCpp
  ));

}

//IborCouponPricerWorker::~IborCouponPricerWorker(){
//
//}

//IborCouponPricerWorker::Destroy(){
//
//}

void CmsCouponPricerWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(VolatilityCoerce, mVolatility, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::SwaptionVolatilityStructure> VolatilityLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              VolatilityCoerce);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::GFunctionFactory::YieldCurveModel YieldCurveModelEnum =
      ObjectHandler::Create<QuantLib::GFunctionFactory::YieldCurveModel>()(mYieldCurveModel);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> MeanReversionLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mMeanReversion, "MeanReversion");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCmsCouponPricer(
          mObjectID,
          mVolatility,
          mCmsCouponPricerType,
          mYieldCurveModel,
          mMeanReversion,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CmsCouponPricer(
          valueObject,
          VolatilityLibObj,
          mCmsCouponPricerType,
          YieldCurveModelEnum,
          MeanReversionLibObj,
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

void CmsCouponPricerWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CmsCouponPricer) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("CmsCouponPricerType is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("YieldCurveModel is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t VolatilityCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strCmsCouponPricerType(info[2]->ToString());
  string CmsCouponPricerTypeCpp(strdup(*strCmsCouponPricerType));

  // convert js argument to c++ type
  String::Utf8Value strYieldCurveModel(info[3]->ToString());
  string YieldCurveModelCpp(strdup(*strYieldCurveModel));

  // convert js argument to c++ type
  ObjectHandler::property_t MeanReversionCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[4]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CmsCouponPricerWorker(
    callback
    ,ObjectIDCpp
    ,VolatilityCpp
    ,CmsCouponPricerTypeCpp
    ,YieldCurveModelCpp
    ,MeanReversionCpp
  ));

}

//CmsCouponPricerWorker::~CmsCouponPricerWorker(){
//
//}

//CmsCouponPricerWorker::Destroy(){
//
//}

void ConundrumPricerByNumericalIntegrationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(SwaptionVolCoerce, mSwaptionVol, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::SwaptionVolatilityStructure> SwaptionVolLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              SwaptionVolCoerce);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::GFunctionFactory::YieldCurveModel YieldCurveModelEnum =
      ObjectHandler::Create<QuantLib::GFunctionFactory::YieldCurveModel>()(mYieldCurveModel);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> MeanReversionLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mMeanReversion, "MeanReversion");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlConundrumPricerByNumericalIntegration(
          mObjectID,
          mSwaptionVol,
          mYieldCurveModel,
          mMeanReversion,
          mLowerLimit,
          mUpperLimit,
          mPrecision,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::NumericHaganPricer(
          valueObject,
          SwaptionVolLibObj,
          YieldCurveModelEnum,
          MeanReversionLibObj,
          mLowerLimit,
          mUpperLimit,
          mPrecision,
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

void ConundrumPricerByNumericalIntegrationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ConundrumPricerByNumericalIntegration) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("YieldCurveModel is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("LowerLimit is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("UpperLimit is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Precision is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t SwaptionVolCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strYieldCurveModel(info[2]->ToString());
  string YieldCurveModelCpp(strdup(*strYieldCurveModel));

  // convert js argument to c++ type
  ObjectHandler::property_t MeanReversionCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[3]).FromJust()));

  // convert js argument to c++ type
  double LowerLimitCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double UpperLimitCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double PrecisionCpp = Nan::To<double>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ConundrumPricerByNumericalIntegrationWorker(
    callback
    ,ObjectIDCpp
    ,SwaptionVolCpp
    ,YieldCurveModelCpp
    ,MeanReversionCpp
    ,LowerLimitCpp
    ,UpperLimitCpp
    ,PrecisionCpp
  ));

}

//ConundrumPricerByNumericalIntegrationWorker::~ConundrumPricerByNumericalIntegrationWorker(){
//
//}

//ConundrumPricerByNumericalIntegrationWorker::Destroy(){
//
//}

void DigitalReplicationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Replication::Type ReplicationEnum =
      ObjectHandler::Create<QuantLib::Replication::Type>()(mReplication);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlDigitalReplication(
          mObjectID,
          mReplication,
          mGap,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::DigitalReplication(
          valueObject,
          ReplicationEnum,
          mGap,
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

void DigitalReplicationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DigitalReplication) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Replication is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Gap is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strReplication(info[1]->ToString());
  string ReplicationCpp(strdup(*strReplication));

  // convert js argument to c++ type
  double GapCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DigitalReplicationWorker(
    callback
    ,ObjectIDCpp
    ,ReplicationCpp
    ,GapCpp
  ));

}

//DigitalReplicationWorker::~DigitalReplicationWorker(){
//
//}

//DigitalReplicationWorker::Destroy(){
//
//}

void ConundrumPricerByNumericalIntegrationUpperLimitWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::NumericHaganPricer, QuantLib::NumericHaganPricer)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->upperLimit(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ConundrumPricerByNumericalIntegrationUpperLimitWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ConundrumPricerByNumericalIntegrationUpperLimit) {

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
  Nan::AsyncQueueWorker(new ConundrumPricerByNumericalIntegrationUpperLimitWorker(
    callback
    ,ObjectIDCpp
  ));

}

//ConundrumPricerByNumericalIntegrationUpperLimitWorker::~ConundrumPricerByNumericalIntegrationUpperLimitWorker(){
//
//}

//ConundrumPricerByNumericalIntegrationUpperLimitWorker::Destroy(){
//
//}
 