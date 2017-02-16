/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "leg.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/couponvectors.hpp>
#include <qlo/conundrumpricer.hpp>
#include <qlo/termstructures.hpp>
#include <qlo/capfloor.hpp>
#include <qlo/swap.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>
#include <ql/instruments/swap.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void LegWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDates, "Dates");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlLeg(
          mObjectID,
          mAmounts,
          mDates,
          mToBeSorted,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Leg(
          valueObject,
          mAmounts,
          DatesLib,
          mToBeSorted,
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

void LegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Leg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Amounts is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Dates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsBoolean()) {
      return Nan::ThrowError("ToBeSorted is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>AmountsCpp;

  Local<Array> AmountsArray = info[1].As<Array>();
  for (unsigned int i = 0; i < AmountsArray->Length(); i++){
    AmountsCpp.push_back(Nan::To<double>(Nan::Get(AmountsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DatesCpp;

  Local<Array> DatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < DatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DatesArray, i).ToLocalChecked()).FromJust()));
    DatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool ToBeSortedCpp = Nan::To<bool>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegWorker(
    callback
    ,ObjectIDCpp
    ,AmountsCpp
    ,DatesCpp
    ,ToBeSortedCpp
  ));

}

//LegWorker::~LegWorker(){
//
//}

//void LegWorker::Destroy(){
//
//}

void LegFromCapFloorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(CapFloorLibObjPtr, mCapFloor,
      QuantLibAddin::CapFloor, QuantLib::CapFloor)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlLegFromCapFloor(
          mObjectID,
          mCapFloor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Leg(
          valueObject,
          CapFloorLibObjPtr,
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

void LegFromCapFloorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegFromCapFloor) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CapFloor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCapFloor(info[1]->ToString());
  string CapFloorCpp(strdup(*strCapFloor));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegFromCapFloorWorker(
    callback
    ,ObjectIDCpp
    ,CapFloorCpp
  ));

}

//LegFromCapFloorWorker::~LegFromCapFloorWorker(){
//
//}

//void LegFromCapFloorWorker::Destroy(){
//
//}

void LegFromSwapWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapLibObjPtr, mSwap,
      QuantLibAddin::Swap, QuantLib::Swap)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlLegFromSwap(
          mObjectID,
          mSwap,
          mLegNumber,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Leg(
          valueObject,
          SwapLibObjPtr,
          mLegNumber,
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

void LegFromSwapWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegFromSwap) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Swap is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("LegNumber is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strSwap(info[1]->ToString());
  string SwapCpp(strdup(*strSwap));

  // convert js argument to c++ type
  long LegNumberCpp = Nan::To<int32_t>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegFromSwapWorker(
    callback
    ,ObjectIDCpp
    ,SwapCpp
    ,LegNumberCpp
  ));

}

//LegFromSwapWorker::~LegFromSwapWorker(){
//
//}

//void LegFromSwapWorker::Destroy(){
//
//}

void MultiPhaseLegWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLibAddin::Leg> > LegIDsObjPtr =
      ObjectHandler::getObjectVector<QuantLibAddin::Leg>(mLegIDs);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMultiPhaseLeg(
          mObjectID,
          mLegIDs,
          mToBeSorted,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::MultiPhaseLeg(
          valueObject,
          LegIDsObjPtr,
          mToBeSorted,
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

void MultiPhaseLegWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MultiPhaseLeg) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("LegIDs is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("ToBeSorted is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<string>LegIDsCpp;

  Local<Array> LegIDsArray = info[1].As<Array>();
  for (unsigned int i = 0; i < LegIDsArray->Length(); i++){
    String::Utf8Value strLegIDs(Nan::Get(LegIDsArray, i).ToLocalChecked()->ToString());
    LegIDsCpp.push_back(strdup(*strLegIDs));
  }

  // convert js argument to c++ type
  bool ToBeSortedCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MultiPhaseLegWorker(
    callback
    ,ObjectIDCpp
    ,LegIDsCpp
    ,ToBeSortedCpp
  ));

}

//MultiPhaseLegWorker::~MultiPhaseLegWorker(){
//
//}

//void MultiPhaseLegWorker::Destroy(){
//
//}

void InterestRateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Compounding CompoundingEnum =
      ObjectHandler::Create<QuantLib::Compounding>()(mCompounding);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Frequency FrequencyEnum =
      ObjectHandler::Create<QuantLib::Frequency>()(mFrequency);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlInterestRate(
          mObjectID,
          mRate,
          mDayCounter,
          mCompounding,
          mFrequency,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::InterestRate(
          valueObject,
          mRate,
          DayCounterEnum,
          CompoundingEnum,
          FrequencyEnum,
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

void InterestRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterestRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Rate is required.");
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
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double RateCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[2]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[3]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[4]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterestRateWorker(
    callback
    ,ObjectIDCpp
    ,RateCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
  ));

}

//InterestRateWorker::~InterestRateWorker(){
//
//}

//void InterestRateWorker::Destroy(){
//
//}

void LegFlowAnalysisWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date AfterDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mAfterDate, "AfterDate");

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Leg)

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

void LegFlowAnalysisWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::LegFlowAnalysis) {

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
  Nan::AsyncQueueWorker(new LegFlowAnalysisWorker(
    callback
    ,ObjectIDCpp
    ,AfterDateCpp
  ));

}

//LegFlowAnalysisWorker::~LegFlowAnalysisWorker(){
//
//}

//void LegFlowAnalysisWorker::Destroy(){
//
//}

void LegSetCouponPricersWorker::Execute(){

  try{

  // convert object IDs into library objects
  std::vector< boost::shared_ptr<QuantLibAddin::FloatingRateCouponPricer> > FloatingRateCouponPricerObjPtr =
      ObjectHandler::getObjectVector<QuantLibAddin::FloatingRateCouponPricer>(mFloatingRateCouponPricer);

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Leg)


  // invoke the member function
  ObjectIDObjPtr->setCouponPricers(
        FloatingRateCouponPricerObjPtr
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegSetCouponPricersWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegSetCouponPricers) {

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
  Nan::AsyncQueueWorker(new LegSetCouponPricersWorker(
    callback
    ,ObjectIDCpp
    ,FloatingRateCouponPricerCpp
  ));

}

//LegSetCouponPricersWorker::~LegSetCouponPricersWorker(){
//
//}

//void LegSetCouponPricersWorker::Destroy(){
//
//}

void InterestRateRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::InterestRate, QuantLib::InterestRate)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->rate(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterestRateRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterestRateRate) {

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
  Nan::AsyncQueueWorker(new InterestRateRateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterestRateRateWorker::~InterestRateRateWorker(){
//
//}

//void InterestRateRateWorker::Destroy(){
//
//}

void InterestRateDayCounterWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::InterestRate, QuantLib::InterestRate)

     
  // invoke the member function
  QuantLib::DayCounter returnValue = ObjectIDLibObjPtr->dayCounter(
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

void InterestRateDayCounterWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterestRateDayCounter) {

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
  Nan::AsyncQueueWorker(new InterestRateDayCounterWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterestRateDayCounterWorker::~InterestRateDayCounterWorker(){
//
//}

//void InterestRateDayCounterWorker::Destroy(){
//
//}

void InterestRateCompoundingWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::InterestRate, QuantLib::InterestRate)

     
  // invoke the member function
  QuantLib::Compounding returnValue = ObjectIDLibObjPtr->compounding(
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

void InterestRateCompoundingWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterestRateCompounding) {

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
  Nan::AsyncQueueWorker(new InterestRateCompoundingWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterestRateCompoundingWorker::~InterestRateCompoundingWorker(){
//
//}

//void InterestRateCompoundingWorker::Destroy(){
//
//}

void InterestRateFrequencyWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::InterestRate, QuantLib::InterestRate)

     
  // invoke the member function
  QuantLib::Frequency returnValue = ObjectIDLibObjPtr->frequency(
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

void InterestRateFrequencyWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterestRateFrequency) {

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
  Nan::AsyncQueueWorker(new InterestRateFrequencyWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterestRateFrequencyWorker::~InterestRateFrequencyWorker(){
//
//}

//void InterestRateFrequencyWorker::Destroy(){
//
//}

void InterestRateDiscountFactorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::InterestRate, QuantLib::InterestRate)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EndDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEndDate, "EndDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodStartLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodStart, "RefPeriodStart");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodEndLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodEnd, "RefPeriodEnd");

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->discountFactor(
        StartDateLib
        ,
         EndDateLib
        ,
         RefPeriodStartLib
        ,
         RefPeriodEndLib
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterestRateDiscountFactorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterestRateDiscountFactor) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t EndDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodStartCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodEndCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterestRateDiscountFactorWorker(
    callback
    ,ObjectIDCpp
    ,StartDateCpp
    ,EndDateCpp
    ,RefPeriodStartCpp
    ,RefPeriodEndCpp
  ));

}

//InterestRateDiscountFactorWorker::~InterestRateDiscountFactorWorker(){
//
//}

//void InterestRateDiscountFactorWorker::Destroy(){
//
//}

void InterestRateCompoundFactorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::InterestRate, QuantLib::InterestRate)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EndDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEndDate, "EndDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodStartLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodStart, "RefPeriodStart");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodEndLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodEnd, "RefPeriodEnd");

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->compoundFactor(
        StartDateLib
        ,
         EndDateLib
        ,
         RefPeriodStartLib
        ,
         RefPeriodEndLib
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterestRateCompoundFactorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterestRateCompoundFactor) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t EndDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodStartCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodEndCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterestRateCompoundFactorWorker(
    callback
    ,ObjectIDCpp
    ,StartDateCpp
    ,EndDateCpp
    ,RefPeriodStartCpp
    ,RefPeriodEndCpp
  ));

}

//InterestRateCompoundFactorWorker::~InterestRateCompoundFactorWorker(){
//
//}

//void InterestRateCompoundFactorWorker::Destroy(){
//
//}

void InterestRateEquivalentRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::InterestRate, QuantLib::InterestRate)


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
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EndDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEndDate, "EndDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodStartLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodStart, "RefPeriodStart");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodEndLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodEnd, "RefPeriodEnd");

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->equivalentRate(
        DayCounterEnum
        ,
         CompoundingEnum
        ,
         FrequencyEnum
        ,
         StartDateLib
        ,
         EndDateLib
        ,
         RefPeriodStartLib
        ,
         RefPeriodEndLib
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterestRateEquivalentRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterestRateEquivalentRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[1]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[2]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[3]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t EndDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodStartCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodEndCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterestRateEquivalentRateWorker(
    callback
    ,ObjectIDCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,StartDateCpp
    ,EndDateCpp
    ,RefPeriodStartCpp
    ,RefPeriodEndCpp
  ));

}

//InterestRateEquivalentRateWorker::~InterestRateEquivalentRateWorker(){
//
//}

//void InterestRateEquivalentRateWorker::Destroy(){
//
//}

void LegStartDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::CashFlows::startDate(
      ObjectIdLibObj
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegStartDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegStartDate) {

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
  Nan::AsyncQueueWorker(new LegStartDateWorker(
    callback
    ,ObjectIdCpp
  ));

}

//LegStartDateWorker::~LegStartDateWorker(){
//
//}

//void LegStartDateWorker::Destroy(){
//
//}

void LegMaturityDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::CashFlows::maturityDate(
      ObjectIdLibObj
     );

  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegMaturityDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegMaturityDate) {

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
  Nan::AsyncQueueWorker(new LegMaturityDateWorker(
    callback
    ,ObjectIdCpp
  ));

}

//LegMaturityDateWorker::~LegMaturityDateWorker(){
//
//}

//void LegMaturityDateWorker::Destroy(){
//
//}

void LegIsExpiredWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::isExpired(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegIsExpiredWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegIsExpired) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegIsExpiredWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegIsExpiredWorker::~LegIsExpiredWorker(){
//
//}

//void LegIsExpiredWorker::Destroy(){
//
//}

void LegPreviousCashFlowDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::CashFlows::previousCashFlowDate(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegPreviousCashFlowDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegPreviousCashFlowDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegPreviousCashFlowDateWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegPreviousCashFlowDateWorker::~LegPreviousCashFlowDateWorker(){
//
//}

//void LegPreviousCashFlowDateWorker::Destroy(){
//
//}

void LegNextCashFlowDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::CashFlows::nextCashFlowDate(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegNextCashFlowDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegNextCashFlowDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegNextCashFlowDateWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegNextCashFlowDateWorker::~LegNextCashFlowDateWorker(){
//
//}

//void LegNextCashFlowDateWorker::Destroy(){
//
//}

void LegPreviousCashFlowAmountWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::CashFlows::previousCashFlowAmount(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegPreviousCashFlowAmountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegPreviousCashFlowAmount) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegPreviousCashFlowAmountWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegPreviousCashFlowAmountWorker::~LegPreviousCashFlowAmountWorker(){
//
//}

//void LegPreviousCashFlowAmountWorker::Destroy(){
//
//}

void LegNextCashFlowAmountWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::CashFlows::nextCashFlowAmount(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegNextCashFlowAmountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegNextCashFlowAmount) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegNextCashFlowAmountWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegNextCashFlowAmountWorker::~LegNextCashFlowAmountWorker(){
//
//}

//void LegNextCashFlowAmountWorker::Destroy(){
//
//}

void LegPreviousCouponRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::previousCouponRate(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegPreviousCouponRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegPreviousCouponRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegPreviousCouponRateWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegPreviousCouponRateWorker::~LegPreviousCouponRateWorker(){
//
//}

//void LegPreviousCouponRateWorker::Destroy(){
//
//}

void LegNextCouponRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::nextCouponRate(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegNextCouponRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegNextCouponRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegNextCouponRateWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegNextCouponRateWorker::~LegNextCouponRateWorker(){
//
//}

//void LegNextCouponRateWorker::Destroy(){
//
//}

void LegNominalWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::CashFlows::nominal(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegNominalWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegNominal) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegNominalWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegNominalWorker::~LegNominalWorker(){
//
//}

//void LegNominalWorker::Destroy(){
//
//}

void LegAccrualStartDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::CashFlows::accrualStartDate(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegAccrualStartDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegAccrualStartDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegAccrualStartDateWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegAccrualStartDateWorker::~LegAccrualStartDateWorker(){
//
//}

//void LegAccrualStartDateWorker::Destroy(){
//
//}

void LegAccrualEndDateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::CashFlows::accrualEndDate(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegAccrualEndDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegAccrualEndDate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegAccrualEndDateWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegAccrualEndDateWorker::~LegAccrualEndDateWorker(){
//
//}

//void LegAccrualEndDateWorker::Destroy(){
//
//}

void LegReferencePeriodStartWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::CashFlows::referencePeriodStart(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegReferencePeriodStartWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegReferencePeriodStart) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegReferencePeriodStartWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegReferencePeriodStartWorker::~LegReferencePeriodStartWorker(){
//
//}

//void LegReferencePeriodStartWorker::Destroy(){
//
//}

void LegReferencePeriodEndWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Date returnValue = QuantLib::CashFlows::referencePeriodEnd(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegReferencePeriodEndWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegReferencePeriodEnd) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegReferencePeriodEndWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegReferencePeriodEndWorker::~LegReferencePeriodEndWorker(){
//
//}

//void LegReferencePeriodEndWorker::Destroy(){
//
//}

void LegAccrualPeriodWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::accrualPeriod(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegAccrualPeriodWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegAccrualPeriod) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegAccrualPeriodWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegAccrualPeriodWorker::~LegAccrualPeriodWorker(){
//
//}

//void LegAccrualPeriodWorker::Destroy(){
//
//}

void LegAccrualDaysWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::accrualDays(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegAccrualDaysWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegAccrualDays) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegAccrualDaysWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegAccrualDaysWorker::~LegAccrualDaysWorker(){
//
//}

//void LegAccrualDaysWorker::Destroy(){
//
//}

void LegAccruedPeriodWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::accrualPeriod(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegAccruedPeriodWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegAccruedPeriod) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegAccruedPeriodWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegAccruedPeriodWorker::~LegAccruedPeriodWorker(){
//
//}

//void LegAccruedPeriodWorker::Destroy(){
//
//}

void LegAccruedDaysWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::accrualDays(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegAccruedDaysWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegAccruedDays) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegAccruedDaysWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegAccruedDaysWorker::~LegAccruedDaysWorker(){
//
//}

//void LegAccruedDaysWorker::Destroy(){
//
//}

void LegAccruedAmountWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::CashFlows::accruedAmount(
      ObjectIdLibObj
      ,
       mIncludeSettlDate
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

void LegAccruedAmountWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegAccruedAmount) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegAccruedAmountWorker(
    callback
    ,ObjectIdCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
  ));

}

//LegAccruedAmountWorker::~LegAccruedAmountWorker(){
//
//}

//void LegAccruedAmountWorker::Destroy(){
//
//}

void LegNPVWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(DiscountCurveLibObj, mDiscountCurve,
      QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::npv(
      ObjectIdLibObj
      ,
       DiscountCurveLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegNPVWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegNPV) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("DiscountCurve is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  String::Utf8Value strDiscountCurve(info[1]->ToString());
  string DiscountCurveCpp(strdup(*strDiscountCurve));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[2]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegNPVWorker(
    callback
    ,ObjectIdCpp
    ,DiscountCurveCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//LegNPVWorker::~LegNPVWorker(){
//
//}

//void LegNPVWorker::Destroy(){
//
//}

void LegBPSWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(DiscountCurveLibObj, mDiscountCurve,
      QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::bps(
      ObjectIdLibObj
      ,
       DiscountCurveLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegBPSWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegBPS) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("DiscountCurve is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  String::Utf8Value strDiscountCurve(info[1]->ToString());
  string DiscountCurveCpp(strdup(*strDiscountCurve));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[2]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegBPSWorker(
    callback
    ,ObjectIdCpp
    ,DiscountCurveCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//LegBPSWorker::~LegBPSWorker(){
//
//}

//void LegBPSWorker::Destroy(){
//
//}

void LegAtmRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert object IDs into library objects
  OH_GET_UNDERLYING(DiscountCurveLibObj, mDiscountCurve,
      QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");


  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::atmRate(
      ObjectIdLibObj
      ,
       DiscountCurveLibObj
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
      ,
       mNPV
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegAtmRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegAtmRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("DiscountCurve is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("NPV is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  String::Utf8Value strDiscountCurve(info[1]->ToString());
  string DiscountCurveCpp(strdup(*strDiscountCurve));

  // convert js argument to c++ type
  bool IncludeSettlDateCpp = Nan::To<bool>(info[2]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[3]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  double NPVCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegAtmRateWorker(
    callback
    ,ObjectIdCpp
    ,DiscountCurveCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
    ,NPVCpp
  ));

}

//LegAtmRateWorker::~LegAtmRateWorker(){
//
//}

//void LegAtmRateWorker::Destroy(){
//
//}

void LegNPVFromYieldWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


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
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::CashFlows::npv(
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
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegNPVFromYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegNPVFromYield) {

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
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
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
  bool IncludeSettlDateCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegNPVFromYieldWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//LegNPVFromYieldWorker::~LegNPVFromYieldWorker(){
//
//}

//void LegNPVFromYieldWorker::Destroy(){
//
//}

void LegBPSFromYieldWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


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
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::bps(
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
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegBPSFromYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegBPSFromYield) {

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
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
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
  bool IncludeSettlDateCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegBPSFromYieldWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//LegBPSFromYieldWorker::~LegBPSFromYieldWorker(){
//
//}

//void LegBPSFromYieldWorker::Destroy(){
//
//}

void LegYieldWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


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
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size MaxIterationsLib;
  QuantLibAddin::cppToLibrary(mMaxIterations, MaxIterationsLib);

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::yield(
      ObjectIdLibObj
      ,
       mNPV
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
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

void LegYieldWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegYield) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("NPV is required.");
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
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("MaxIterations is required.");
  }
  if (info.Length() == 10 || !info[10]->IsNumber()) {
      return Nan::ThrowError("Guess is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  double NPVCpp = Nan::To<double>(info[1]).FromJust();

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
  bool IncludeSettlDateCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  long MaxIterationsCpp = Nan::To<int32_t>(info[9]).FromJust();

  // convert js argument to c++ type
  double GuessCpp = Nan::To<double>(info[10]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[11].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegYieldWorker(
    callback
    ,ObjectIdCpp
    ,NPVCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
    ,AccuracyCpp
    ,MaxIterationsCpp
    ,GuessCpp
  ));

}

//LegYieldWorker::~LegYieldWorker(){
//
//}

//void LegYieldWorker::Destroy(){
//
//}

void LegDurationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


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


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::duration(
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
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegDurationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegDuration) {

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
  if (info.Length() == 6 || !info[6]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
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
  bool IncludeSettlDateCpp = Nan::To<bool>(info[6]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[8]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegDurationWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,DurationTypeCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//LegDurationWorker::~LegDurationWorker(){
//
//}

//void LegDurationWorker::Destroy(){
//
//}

void LegConvexityWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


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
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::CashFlows::convexity(
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
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegConvexityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegConvexity) {

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
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
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
  bool IncludeSettlDateCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegConvexityWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//LegConvexityWorker::~LegConvexityWorker(){
//
//}

//void LegConvexityWorker::Destroy(){
//
//}

void LegBasisPointValueWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


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
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::CashFlows::basisPointValue(
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
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegBasisPointValueWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegBasisPointValue) {

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
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
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
  bool IncludeSettlDateCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegBasisPointValueWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//LegBasisPointValueWorker::~LegBasisPointValueWorker(){
//
//}

//void LegBasisPointValueWorker::Destroy(){
//
//}

void LegYieldValueBasisPointWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


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
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::CashFlows::yieldValueBasisPoint(
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
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegYieldValueBasisPointWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegYieldValueBasisPoint) {

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
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
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
  bool IncludeSettlDateCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegYieldValueBasisPointWorker(
    callback
    ,ObjectIdCpp
    ,YieldCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//LegYieldValueBasisPointWorker::~LegYieldValueBasisPointWorker(){
//
//}

//void LegYieldValueBasisPointWorker::Destroy(){
//
//}

void LegNPVFromZSpreadWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert object IDs into library objects
  OH_GET_REFERENCE(DiscountCurveLibObjPtr, mDiscountCurve,
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
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::CashFlows::npv(
      ObjectIdLibObj
      ,
       DiscountCurveLibObjPtr
      ,
       mZSpread
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LegNPVFromZSpreadWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegNPVFromZSpread) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("DiscountCurve is required.");
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
  if (info.Length() == 6 || !info[6]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  String::Utf8Value strDiscountCurve(info[1]->ToString());
  string DiscountCurveCpp(strdup(*strDiscountCurve));

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
  bool IncludeSettlDateCpp = Nan::To<bool>(info[6]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[8]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegNPVFromZSpreadWorker(
    callback
    ,ObjectIdCpp
    ,DiscountCurveCpp
    ,ZSpreadCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
  ));

}

//LegNPVFromZSpreadWorker::~LegNPVFromZSpreadWorker(){
//
//}

//void LegNPVFromZSpreadWorker::Destroy(){
//
//}

void LegZSpreadWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ObjectIdLibObj, mObjectId,
      QuantLibAddin::Leg, QuantLib::Leg)


  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(DiscountCurveLibObjPtr, mDiscountCurve,
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
  QuantLib::Date NpvDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mNpvDate, "NpvDate");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size MaxIterationsLib;
  QuantLibAddin::cppToLibrary(mMaxIterations, MaxIterationsLib);

       // invoke the utility function
  mReturnValue = QuantLib::CashFlows::zSpread(
      ObjectIdLibObj
      ,
       mNPV
      ,
       DiscountCurveLibObjPtr
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       mIncludeSettlDate
      ,
       SettlementDateLib
      ,
       NpvDateLib
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

void LegZSpreadWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LegZSpread) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectId is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("NPV is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("DiscountCurve is required.");
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
  if (info.Length() == 6 || !info[6]->IsBoolean()) {
      return Nan::ThrowError("IncludeSettlDate is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  if (info.Length() == 10 || !info[10]->IsNumber()) {
      return Nan::ThrowError("MaxIterations is required.");
  }
  if (info.Length() == 11 || !info[11]->IsNumber()) {
      return Nan::ThrowError("Guess is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectId(info[0]->ToString());
  string ObjectIdCpp(strdup(*strObjectId));

  // convert js argument to c++ type
  double NPVCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDiscountCurve(info[2]->ToString());
  string DiscountCurveCpp(strdup(*strDiscountCurve));

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
  bool IncludeSettlDateCpp = Nan::To<bool>(info[6]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t NpvDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[8]).FromJust()));

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[9]).FromJust();

  // convert js argument to c++ type
  long MaxIterationsCpp = Nan::To<int32_t>(info[10]).FromJust();

  // convert js argument to c++ type
  double GuessCpp = Nan::To<double>(info[11]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[12].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LegZSpreadWorker(
    callback
    ,ObjectIdCpp
    ,NPVCpp
    ,DiscountCurveCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,IncludeSettlDateCpp
    ,SettlementDateCpp
    ,NpvDateCpp
    ,AccuracyCpp
    ,MaxIterationsCpp
    ,GuessCpp
  ));

}

//LegZSpreadWorker::~LegZSpreadWorker(){
//
//}

//void LegZSpreadWorker::Destroy(){
//
//}

void InterestRateImpliedRateWorker::Execute(){

  try{

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
  QuantLib::Date StartDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mStartDate, "StartDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date EndDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mEndDate, "EndDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodStartLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodStart, "RefPeriodStart");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date RefPeriodEndLib = ObjectHandler::convert2<QuantLib::Date>(
      mRefPeriodEnd, "RefPeriodEnd");

       // invoke the utility function
  QuantLib::Real returnValue = QuantLib::InterestRate::impliedRate(
      mCompound
      ,
       DayCounterEnum
      ,
       CompoundingEnum
      ,
       FrequencyEnum
      ,
       StartDateLib
      ,
       EndDateLib
      ,
       RefPeriodStartLib
      ,
       RefPeriodEndLib
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterestRateImpliedRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterestRateImpliedRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Compound is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Compounding is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Frequency is required.");
  }
  // convert js argument to c++ type
  double CompoundCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[1]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

  // convert js argument to c++ type
  String::Utf8Value strCompounding(info[2]->ToString());
  string CompoundingCpp(strdup(*strCompounding));

  // convert js argument to c++ type
  String::Utf8Value strFrequency(info[3]->ToString());
  string FrequencyCpp(strdup(*strFrequency));

  // convert js argument to c++ type
  ObjectHandler::property_t StartDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[4]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t EndDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodStartCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t RefPeriodEndCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[7]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterestRateImpliedRateWorker(
    callback
    ,CompoundCpp
    ,DayCounterCpp
    ,CompoundingCpp
    ,FrequencyCpp
    ,StartDateCpp
    ,EndDateCpp
    ,RefPeriodStartCpp
    ,RefPeriodEndCpp
  ));

}

//InterestRateImpliedRateWorker::~InterestRateImpliedRateWorker(){
//
//}

//void InterestRateImpliedRateWorker::Destroy(){
//
//}
 