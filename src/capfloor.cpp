/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "capfloor.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/capfloor.hpp>
#include <qlo/indexes/iborindex.hpp>
#include <qlo/couponvectors.hpp>
#include <qlo/pricingengines.hpp>
#include <qlo/termstructures.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>
#include <ql/indexes/iborindex.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void CapFloorWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::CapFloor::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::CapFloor::Type>()(mOptionType);


  // convert object IDs into library objects
  OH_GET_UNDERLYING(LegIDLibObj, mLegID,
      QuantLibAddin::Leg, QuantLib::Leg)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCapFloor(
          mObjectID,
          mOptionType,
          mLegID,
          mStrikes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CapFloor(
          valueObject,
          OptionTypeEnum,
          LegIDLibObj,
          mStrikes,
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

void CapFloorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CapFloor) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("LegID is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Strikes is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[1]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  String::Utf8Value strLegID(info[2]->ToString());
  string LegIDCpp(strdup(*strLegID));

  // convert js argument to c++ type
  std::vector<double>StrikesCpp;

  Local<Array> StrikesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < StrikesArray->Length(); i++){
    StrikesCpp.push_back(Nan::To<double>(Nan::Get(StrikesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CapFloorWorker(
    callback
    ,ObjectIDCpp
    ,OptionTypeCpp
    ,LegIDCpp
    ,StrikesCpp
  ));

}

//CapFloorWorker::~CapFloorWorker(){
//
//}

//void CapFloorWorker::Destroy(){
//
//}

void MakeCapFloorWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::CapFloor::Type OptionTypeEnum =
      ObjectHandler::Create<QuantLib::CapFloor::Type>()(mOptionType);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period LengthLib;
  QuantLibAddin::cppToLibrary(mLength, LengthLib);


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period ForwardStartLib;
  QuantLibAddin::cppToLibrary(mForwardStart, ForwardStartLib);


  // convert object IDs into library objects
  OH_GET_REFERENCE(PricingEngineIDLibObjPtr, mPricingEngineID,
      QuantLibAddin::PricingEngine, QuantLib::PricingEngine)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMakeCapFloor(
          mObjectID,
          mOptionType,
          mLength,
          mIborIndex,
          mStrike,
          mForwardStart,
          mPricingEngineID,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CapFloor(
          valueObject,
          OptionTypeEnum,
          LengthLib,
          IborIndexLibObjPtr,
          mStrike,
          ForwardStartLib,
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

void MakeCapFloorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MakeCapFloor) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("OptionType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Length is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("ForwardStart is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("PricingEngineID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strOptionType(info[1]->ToString());
  string OptionTypeCpp(strdup(*strOptionType));

  // convert js argument to c++ type
  String::Utf8Value strLength(info[2]->ToString());
  string LengthCpp(strdup(*strLength));

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[3]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strForwardStart(info[5]->ToString());
  string ForwardStartCpp(strdup(*strForwardStart));

  // convert js argument to c++ type
  String::Utf8Value strPricingEngineID(info[6]->ToString());
  string PricingEngineIDCpp(strdup(*strPricingEngineID));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MakeCapFloorWorker(
    callback
    ,ObjectIDCpp
    ,OptionTypeCpp
    ,LengthCpp
    ,IborIndexCpp
    ,StrikeCpp
    ,ForwardStartCpp
    ,PricingEngineIDCpp
  ));

}

//MakeCapFloorWorker::~MakeCapFloorWorker(){
//
//}

//void MakeCapFloorWorker::Destroy(){
//
//}

void CapFloorTypeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CapFloor, QuantLib::CapFloor)


  // invoke the member function
  QuantLib::CapFloor::Type returnValue = ObjectIDLibObjPtr->type(
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

void CapFloorTypeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CapFloorType) {

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
  Nan::AsyncQueueWorker(new CapFloorTypeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CapFloorTypeWorker::~CapFloorTypeWorker(){
//
//}

//void CapFloorTypeWorker::Destroy(){
//
//}

void CapFloorCapRatesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CapFloor, QuantLib::CapFloor)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->capRates(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CapFloorCapRatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CapFloorCapRates) {

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
  Nan::AsyncQueueWorker(new CapFloorCapRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CapFloorCapRatesWorker::~CapFloorCapRatesWorker(){
//
//}

//void CapFloorCapRatesWorker::Destroy(){
//
//}

void CapFloorFloorRatesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CapFloor, QuantLib::CapFloor)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->floorRates(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CapFloorFloorRatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CapFloorFloorRates) {

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
  Nan::AsyncQueueWorker(new CapFloorFloorRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CapFloorFloorRatesWorker::~CapFloorFloorRatesWorker(){
//
//}

//void CapFloorFloorRatesWorker::Destroy(){
//
//}

void CapFloorAtmRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(YieldCurveLibObj, mYieldCurve,
      QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure)

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CapFloor, QuantLib::CapFloor)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->atmRate(
        YieldCurveLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CapFloorAtmRateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CapFloorAtmRate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("YieldCurve is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strYieldCurve(info[1]->ToString());
  string YieldCurveCpp(strdup(*strYieldCurve));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CapFloorAtmRateWorker(
    callback
    ,ObjectIDCpp
    ,YieldCurveCpp
  ));

}

//CapFloorAtmRateWorker::~CapFloorAtmRateWorker(){
//
//}

//void CapFloorAtmRateWorker::Destroy(){
//
//}

void CapFloorStartDateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CapFloor, QuantLib::CapFloor)


  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->startDate(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CapFloorStartDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CapFloorStartDate) {

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
  Nan::AsyncQueueWorker(new CapFloorStartDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CapFloorStartDateWorker::~CapFloorStartDateWorker(){
//
//}

//void CapFloorStartDateWorker::Destroy(){
//
//}

void CapFloorMaturityDateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CapFloor, QuantLib::CapFloor)


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

void CapFloorMaturityDateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CapFloorMaturityDate) {

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
  Nan::AsyncQueueWorker(new CapFloorMaturityDateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CapFloorMaturityDateWorker::~CapFloorMaturityDateWorker(){
//
//}

//void CapFloorMaturityDateWorker::Destroy(){
//
//}

void CapFloorImpliedVolatilityWorker::Execute(){

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
      QuantLibAddin::CapFloor, QuantLib::CapFloor)


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

void CapFloorImpliedVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CapFloorImpliedVolatility) {

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
  Nan::AsyncQueueWorker(new CapFloorImpliedVolatilityWorker(
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

//CapFloorImpliedVolatilityWorker::~CapFloorImpliedVolatilityWorker(){
//
//}

//void CapFloorImpliedVolatilityWorker::Destroy(){
//
//}

void CapFloorLegAnalysisWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date AfterDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mAfterDate, "AfterDate");

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CapFloor)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->legAnalysis(
        AfterDateLib
       );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CapFloorLegAnalysisWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CapFloorLegAnalysis) {

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
  Nan::AsyncQueueWorker(new CapFloorLegAnalysisWorker(
    callback
    ,ObjectIDCpp
    ,AfterDateCpp
  ));

}

//CapFloorLegAnalysisWorker::~CapFloorLegAnalysisWorker(){
//
//}

//void CapFloorLegAnalysisWorker::Destroy(){
//
//}
 