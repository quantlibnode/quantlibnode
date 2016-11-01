// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "options.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/options.hpp>
#include <qlo/payoffs.hpp>
#include <qlo/exercise.hpp>
#include <ql/instruments/oneassetoption.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void BarrierOptionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Barrier::Type BarrierTypeEnum =
      ObjectHandler::Create<QuantLib::Barrier::Type>()(mBarrierType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBarrierOption(
          mObjectID,
          mBarrierType,
          mBarrier,
          mRebate,
          mPayoff,
          mExercise,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BarrierOption(
          valueObject,
          BarrierTypeEnum,
          mBarrier,
          mRebate,
          PayoffLibObjPtr,
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

void BarrierOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BarrierOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("BarrierType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Barrier is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Rebate is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strBarrierType(info[1]->ToString());
  string BarrierTypeCpp(strdup(*strBarrierType));

  // convert js argument to c++ type
  double BarrierCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double RebateCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[4]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[5]->ToString());
  string ExerciseCpp(strdup(*strExercise));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BarrierOptionWorker(
    callback
    ,ObjectIDCpp
    ,BarrierTypeCpp
    ,BarrierCpp
    ,RebateCpp
    ,PayoffCpp
    ,ExerciseCpp
  ));

}

//BarrierOptionWorker::~BarrierOptionWorker(){
//
//}

//BarrierOptionWorker::Destroy(){
//
//}

void CaAsianOptionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Average::Type AverageTypeEnum =
      ObjectHandler::Create<QuantLib::Average::Type>()(mAverageType);


  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCaAsianOption(
          mObjectID,
          mAverageType,
          mPayoff,
          mExercise,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ContinuousAveragingAsianOption(
          valueObject,
          AverageTypeEnum,
          PayoffLibObjPtr,
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

void CaAsianOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CaAsianOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("AverageType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strAverageType(info[1]->ToString());
  string AverageTypeCpp(strdup(*strAverageType));

  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[2]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[3]->ToString());
  string ExerciseCpp(strdup(*strExercise));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CaAsianOptionWorker(
    callback
    ,ObjectIDCpp
    ,AverageTypeCpp
    ,PayoffCpp
    ,ExerciseCpp
  ));

}

//CaAsianOptionWorker::~CaAsianOptionWorker(){
//
//}

//CaAsianOptionWorker::Destroy(){
//
//}

void DaAsianOptionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Average::Type AverageTypeEnum =
      ObjectHandler::Create<QuantLib::Average::Type>()(mAverageType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size PastFixingsLib;
  QuantLibAddin::cppToLibrary(mPastFixings, PastFixingsLib);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> FixingDatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mFixingDates, "FixingDates");


  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlDaAsianOption(
          mObjectID,
          mAverageType,
          mRunningAccumulator,
          mPastFixings,
          mFixingDates,
          mPayoff,
          mExercise,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::DiscreteAveragingAsianOption(
          valueObject,
          AverageTypeEnum,
          mRunningAccumulator,
          PastFixingsLib,
          FixingDatesLib,
          PayoffLibObjPtr,
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

void DaAsianOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DaAsianOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("AverageType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("RunningAccumulator is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("PastFixings is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("FixingDates is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strAverageType(info[1]->ToString());
  string AverageTypeCpp(strdup(*strAverageType));

  // convert js argument to c++ type
  double RunningAccumulatorCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  long PastFixingsCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>FixingDatesCpp;

  Local<Array> FixingDatesArray = info[4].As<Array>();
  for (unsigned int i = 0; i < FixingDatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(FixingDatesArray, i).ToLocalChecked()).FromJust()));
    FixingDatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[5]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[6]->ToString());
  string ExerciseCpp(strdup(*strExercise));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DaAsianOptionWorker(
    callback
    ,ObjectIDCpp
    ,AverageTypeCpp
    ,RunningAccumulatorCpp
    ,PastFixingsCpp
    ,FixingDatesCpp
    ,PayoffCpp
    ,ExerciseCpp
  ));

}

//DaAsianOptionWorker::~DaAsianOptionWorker(){
//
//}

//DaAsianOptionWorker::Destroy(){
//
//}

void DividendVanillaOptionWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DividendDatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDividendDates, "DividendDates");


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> DividendsLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mDividends);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlDividendVanillaOption(
          mObjectID,
          mPayoff,
          mExercise,
          mDividendDates,
          mDividends,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::DividendVanillaOption(
          valueObject,
          PayoffLibObjPtr,
          ExerciseLibObjPtr,
          DividendDatesLib,
          mDividends,
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

void DividendVanillaOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DividendVanillaOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("DividendDates is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("Dividends is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[1]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[2]->ToString());
  string ExerciseCpp(strdup(*strExercise));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DividendDatesCpp;

  Local<Array> DividendDatesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < DividendDatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DividendDatesArray, i).ToLocalChecked()).FromJust()));
    DividendDatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>DividendsCpp;

  Local<Array> DividendsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < DividendsArray->Length(); i++){
    DividendsCpp.push_back(Nan::To<double>(Nan::Get(DividendsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new DividendVanillaOptionWorker(
    callback
    ,ObjectIDCpp
    ,PayoffCpp
    ,ExerciseCpp
    ,DividendDatesCpp
    ,DividendsCpp
  ));

}

//DividendVanillaOptionWorker::~DividendVanillaOptionWorker(){
//
//}

//DividendVanillaOptionWorker::Destroy(){
//
//}

void ForwardVanillaOptionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ResetDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mResetDate, "ResetDate");


  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlForwardVanillaOption(
          mObjectID,
          mMoneyness,
          mResetDate,
          mPayoff,
          mExercise,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ForwardVanillaOption(
          valueObject,
          mMoneyness,
          ResetDateLib,
          PayoffLibObjPtr,
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

void ForwardVanillaOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ForwardVanillaOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Moneyness is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double MoneynessCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t ResetDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[3]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[4]->ToString());
  string ExerciseCpp(strdup(*strExercise));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ForwardVanillaOptionWorker(
    callback
    ,ObjectIDCpp
    ,MoneynessCpp
    ,ResetDateCpp
    ,PayoffCpp
    ,ExerciseCpp
  ));

}

//ForwardVanillaOptionWorker::~ForwardVanillaOptionWorker(){
//
//}

//ForwardVanillaOptionWorker::Destroy(){
//
//}

void VanillaOptionWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlVanillaOption(
          mObjectID,
          mPayoff,
          mExercise,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::VanillaOption(
          valueObject,
          PayoffLibObjPtr,
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

void VanillaOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VanillaOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[1]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[2]->ToString());
  string ExerciseCpp(strdup(*strExercise));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VanillaOptionWorker(
    callback
    ,ObjectIDCpp
    ,PayoffCpp
    ,ExerciseCpp
  ));

}

//VanillaOptionWorker::~VanillaOptionWorker(){
//
//}

//VanillaOptionWorker::Destroy(){
//
//}

void EuropeanOptionWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlEuropeanOption(
          mObjectID,
          mPayoff,
          mExercise,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::EuropeanOption(
          valueObject,
          PayoffLibObjPtr,
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

void EuropeanOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EuropeanOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[1]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[2]->ToString());
  string ExerciseCpp(strdup(*strExercise));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new EuropeanOptionWorker(
    callback
    ,ObjectIDCpp
    ,PayoffCpp
    ,ExerciseCpp
  ));

}

//EuropeanOptionWorker::~EuropeanOptionWorker(){
//
//}

//EuropeanOptionWorker::Destroy(){
//
//}

void QuantoVanillaOptionWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlQuantoVanillaOption(
          mObjectID,
          mPayoff,
          mExercise,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::QuantoVanillaOption(
          valueObject,
          PayoffLibObjPtr,
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

void QuantoVanillaOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::QuantoVanillaOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[1]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[2]->ToString());
  string ExerciseCpp(strdup(*strExercise));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new QuantoVanillaOptionWorker(
    callback
    ,ObjectIDCpp
    ,PayoffCpp
    ,ExerciseCpp
  ));

}

//QuantoVanillaOptionWorker::~QuantoVanillaOptionWorker(){
//
//}

//QuantoVanillaOptionWorker::Destroy(){
//
//}

void QuantoForwardVanillaOptionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ResetDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mResetDate, "ResetDate");


  // convert object IDs into library objects
  OH_GET_REFERENCE(PayoffLibObjPtr, mPayoff,
      QuantLibAddin::StrikedTypePayoff, QuantLib::StrikedTypePayoff)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlQuantoForwardVanillaOption(
          mObjectID,
          mMoneyness,
          mResetDate,
          mPayoff,
          mExercise,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::QuantoForwardVanillaOption(
          valueObject,
          mMoneyness,
          ResetDateLib,
          PayoffLibObjPtr,
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

void QuantoForwardVanillaOptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::QuantoForwardVanillaOption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Moneyness is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("Payoff is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double MoneynessCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t ResetDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strPayoff(info[3]->ToString());
  string PayoffCpp(strdup(*strPayoff));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[4]->ToString());
  string ExerciseCpp(strdup(*strExercise));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new QuantoForwardVanillaOptionWorker(
    callback
    ,ObjectIDCpp
    ,MoneynessCpp
    ,ResetDateCpp
    ,PayoffCpp
    ,ExerciseCpp
  ));

}

//QuantoForwardVanillaOptionWorker::~QuantoForwardVanillaOptionWorker(){
//
//}

//QuantoForwardVanillaOptionWorker::Destroy(){
//
//}

void DeltaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->delta(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DeltaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Delta) {

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
  Nan::AsyncQueueWorker(new DeltaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//DeltaWorker::~DeltaWorker(){
//
//}

//DeltaWorker::Destroy(){
//
//}

void DeltaForwardWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->deltaForward(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DeltaForwardWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DeltaForward) {

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
  Nan::AsyncQueueWorker(new DeltaForwardWorker(
    callback
    ,ObjectIDCpp
  ));

}

//DeltaForwardWorker::~DeltaForwardWorker(){
//
//}

//DeltaForwardWorker::Destroy(){
//
//}

void ElasticityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->elasticity(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ElasticityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Elasticity) {

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
  Nan::AsyncQueueWorker(new ElasticityWorker(
    callback
    ,ObjectIDCpp
  ));

}

//ElasticityWorker::~ElasticityWorker(){
//
//}

//ElasticityWorker::Destroy(){
//
//}

void GammaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gamma(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GammaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Gamma) {

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
  Nan::AsyncQueueWorker(new GammaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//GammaWorker::~GammaWorker(){
//
//}

//GammaWorker::Destroy(){
//
//}

void ThetaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->theta(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ThetaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Theta) {

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
  Nan::AsyncQueueWorker(new ThetaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//ThetaWorker::~ThetaWorker(){
//
//}

//ThetaWorker::Destroy(){
//
//}

void ThetaPerDayWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->thetaPerDay(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ThetaPerDayWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ThetaPerDay) {

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
  Nan::AsyncQueueWorker(new ThetaPerDayWorker(
    callback
    ,ObjectIDCpp
  ));

}

//ThetaPerDayWorker::~ThetaPerDayWorker(){
//
//}

//ThetaPerDayWorker::Destroy(){
//
//}

void VegaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->vega(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VegaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Vega) {

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
  Nan::AsyncQueueWorker(new VegaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VegaWorker::~VegaWorker(){
//
//}

//VegaWorker::Destroy(){
//
//}

void RhoWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->rho(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RhoWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Rho) {

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
  Nan::AsyncQueueWorker(new RhoWorker(
    callback
    ,ObjectIDCpp
  ));

}

//RhoWorker::~RhoWorker(){
//
//}

//RhoWorker::Destroy(){
//
//}

void DividendRhoWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->dividendRho(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DividendRhoWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::DividendRho) {

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
  Nan::AsyncQueueWorker(new DividendRhoWorker(
    callback
    ,ObjectIDCpp
  ));

}

//DividendRhoWorker::~DividendRhoWorker(){
//
//}

//DividendRhoWorker::Destroy(){
//
//}

void ItmCashProbabilityWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::OneAssetOption, QuantLib::OneAssetOption)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->itmCashProbability(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ItmCashProbabilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ItmCashProbability) {

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
  Nan::AsyncQueueWorker(new ItmCashProbabilityWorker(
    callback
    ,ObjectIDCpp
  ));

}

//ItmCashProbabilityWorker::~ItmCashProbabilityWorker(){
//
//}

//ItmCashProbabilityWorker::Destroy(){
//
//}
 