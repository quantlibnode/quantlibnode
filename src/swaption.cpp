/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "swaption.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/swaption.hpp>
#include <qlo/shortratemodels.hpp>
#include <qlo/indexes/swapindex.hpp>
#include <qlo/vanillaswap.hpp>
#include <qlo/termstructures.hpp>
#include <qlo/pricingengines.hpp>
#include <qlo/exercise.hpp>
#include <qlo/indexes/ibor/euribor.hpp>
#include <ql/indexes/swapindex.hpp>
#include <ql/exercise.hpp>
#include <ql/indexes/ibor/euribor.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void SwaptionWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(VanillaSwapLibObjPtr, mVanillaSwap,
      QuantLibAddin::VanillaSwap, QuantLib::VanillaSwap)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ExerciseLibObjPtr, mExercise,
      QuantLibAddin::Exercise, QuantLib::Exercise)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Settlement::Type SettlementTypeEnum =
      ObjectHandler::Create<QuantLib::Settlement::Type>()(mSettlementType);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSwaption(
          mObjectID,
          mVanillaSwap,
          mExercise,
          mSettlementType,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Swaption(
          valueObject,
          VanillaSwapLibObjPtr,
          ExerciseLibObjPtr,
          SettlementTypeEnum,
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

void SwaptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Swaption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("VanillaSwap is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Exercise is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("SettlementType is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strVanillaSwap(info[1]->ToString());
  string VanillaSwapCpp(strdup(*strVanillaSwap));

  // convert js argument to c++ type
  String::Utf8Value strExercise(info[2]->ToString());
  string ExerciseCpp(strdup(*strExercise));

  // convert js argument to c++ type
  String::Utf8Value strSettlementType(info[3]->ToString());
  string SettlementTypeCpp(strdup(*strSettlementType));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionWorker(
    callback
    ,ObjectIDCpp
    ,VanillaSwapCpp
    ,ExerciseCpp
    ,SettlementTypeCpp
  ));

}

//SwaptionWorker::~SwaptionWorker(){
//
//}

//void SwaptionWorker::Destroy(){
//
//}

void MakeSwaptionWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapIndexLibObjPtr, mSwapIndex,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period OptionTenorLib;
  QuantLibAddin::cppToLibrary(mOptionTenor, OptionTenorLib);


  // convert object IDs into library objects
  OH_GET_REFERENCE(PricingEngineIDLibObjPtr, mPricingEngineID,
      QuantLibAddin::PricingEngine, QuantLib::PricingEngine)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMakeSwaption(
          mObjectID,
          mSwapIndex,
          mOptionTenor,
          mStrike,
          mPricingEngineID,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Swaption(
          valueObject,
          SwapIndexLibObjPtr,
          OptionTenorLib,
          mStrike,
          PricingEngineIDLibObjPtr,
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

void MakeSwaptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MakeSwaption) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("SwapIndex is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("PricingEngineID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strSwapIndex(info[1]->ToString());
  string SwapIndexCpp(strdup(*strSwapIndex));

  // convert js argument to c++ type
  String::Utf8Value strOptionTenor(info[2]->ToString());
  string OptionTenorCpp(strdup(*strOptionTenor));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strPricingEngineID(info[4]->ToString());
  string PricingEngineIDCpp(strdup(*strPricingEngineID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MakeSwaptionWorker(
    callback
    ,ObjectIDCpp
    ,SwapIndexCpp
    ,OptionTenorCpp
    ,StrikeCpp
    ,PricingEngineIDCpp
  ));

}

//MakeSwaptionWorker::~MakeSwaptionWorker(){
//
//}

//void MakeSwaptionWorker::Destroy(){
//
//}

void SwaptionTypeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Swaption, QuantLib::Swaption)


  // invoke the member function
  QuantLib::VanillaSwap::Type returnValue = ObjectIDLibObjPtr->type(
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

void SwaptionTypeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionType) {

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
  Nan::AsyncQueueWorker(new SwaptionTypeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SwaptionTypeWorker::~SwaptionTypeWorker(){
//
//}

//void SwaptionTypeWorker::Destroy(){
//
//}

void SwaptionSettlementTypeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Swaption, QuantLib::Swaption)


  // invoke the member function
  QuantLib::Settlement::Type returnValue = ObjectIDLibObjPtr->settlementType(
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

void SwaptionSettlementTypeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionSettlementType) {

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
  Nan::AsyncQueueWorker(new SwaptionSettlementTypeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SwaptionSettlementTypeWorker::~SwaptionSettlementTypeWorker(){
//
//}

//void SwaptionSettlementTypeWorker::Destroy(){
//
//}

void SwaptionImpliedVolatilityWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_OBJECT(YieldCurveCoerce, mYieldCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::YieldTermStructure,
          QuantLib::YieldTermStructure>()(
              YieldCurveCoerce);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural MaxIterLib = ObjectHandler::convert2<long>(
      mMaxIter, "MaxIter", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Swaption, QuantLib::Swaption)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->impliedVolatility(
        mPrice
        ,
         YieldCurveLibObj
        ,
         mGuess
        ,
         mAccuracy
        ,
         MaxIterLib
        ,
         mMinVol
        ,
         mMaxVol
        ,
         mDisplacement
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionImpliedVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionImpliedVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Price is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Guess is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Accuracy is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("MinVol is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("MaxVol is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Displacement is required.");
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
  double GuessCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double AccuracyCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t MaxIterCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[5]).FromJust()));

  // convert js argument to c++ type
  double MinVolCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double MaxVolCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double DisplacementCpp = Nan::To<double>(info[8]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionImpliedVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,PriceCpp
    ,YieldCurveCpp
    ,GuessCpp
    ,AccuracyCpp
    ,MaxIterCpp
    ,MinVolCpp
    ,MaxVolCpp
    ,DisplacementCpp
  ));

}

//SwaptionImpliedVolatilityWorker::~SwaptionImpliedVolatilityWorker(){
//
//}

//void SwaptionImpliedVolatilityWorker::Destroy(){
//
//}
 