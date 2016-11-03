/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "swaptionvolstructure.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/handleimpl.hpp>
#include <qlo/conversions/coercetermstructure.hpp>
#include <qlo/indexes/swapindex.hpp>
#include <qlo/optimization.hpp>
#include <ql/indexes/swapindex.hpp>
#include <ql/termstructures/volatility/swaption/swaptionvolcube.hpp>
#include <qlo/loop/loop_swaptionvolstructure.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void RelinkableHandleSwaptionVolatilityStructureWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlRelinkableHandleSwaptionVolatilityStructure(
          mObjectID,
          mCurrentLink,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RelinkableHandleImpl<QuantLibAddin::SwaptionVolatilityStructure, QuantLib::SwaptionVolatilityStructure>(
          valueObject,
          mCurrentLink,
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

void RelinkableHandleSwaptionVolatilityStructureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::RelinkableHandleSwaptionVolatilityStructure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurrentLink is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurrentLink(info[1]->ToString());
  string CurrentLinkCpp(strdup(*strCurrentLink));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RelinkableHandleSwaptionVolatilityStructureWorker(
    callback
    ,ObjectIDCpp
    ,CurrentLinkCpp
  ));

}

//RelinkableHandleSwaptionVolatilityStructureWorker::~RelinkableHandleSwaptionVolatilityStructureWorker(){
//
//}

//void RelinkableHandleSwaptionVolatilityStructureWorker::Destroy(){
//
//}

void ConstantSwaptionVolatilityWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NDaysLib;
  QuantLibAddin::cppToLibrary(mNDays, NDaysLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention BusinessDayConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mBusinessDayConvention);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> VolatilityLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mVolatility, "Volatility");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlConstantSwaptionVolatility(
          mObjectID,
          mNDays,
          mCalendar,
          mBusinessDayConvention,
          mVolatility,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ConstantSwaptionVolatility(
          valueObject,
          NDaysLib,
          CalendarEnum,
          BusinessDayConventionEnum,
          VolatilityLibObj,
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

void ConstantSwaptionVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ConstantSwaptionVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("NDays is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("BusinessDayConvention is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long NDaysCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[2]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  String::Utf8Value strBusinessDayConvention(info[3]->ToString());
  string BusinessDayConventionCpp(strdup(*strBusinessDayConvention));

  // convert js argument to c++ type
  ObjectHandler::property_t VolatilityCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[4]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[5]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ConstantSwaptionVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,NDaysCpp
    ,CalendarCpp
    ,BusinessDayConventionCpp
    ,VolatilityCpp
    ,DayCounterCpp
  ));

}

//ConstantSwaptionVolatilityWorker::~ConstantSwaptionVolatilityWorker(){
//
//}

//void ConstantSwaptionVolatilityWorker::Destroy(){
//
//}

void SpreadedSwaptionVolatilityWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(BaseVolStructureCoerce, mBaseVolStructure, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::SwaptionVolatilityStructure> BaseVolStructureLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              BaseVolStructureCoerce);


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> SpreadLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mSpread, "Spread");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSpreadedSwaptionVolatility(
          mObjectID,
          mBaseVolStructure,
          mSpread,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SpreadedSwaptionVolatility(
          valueObject,
          BaseVolStructureLibObj,
          SpreadLibObj,
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

void SpreadedSwaptionVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SpreadedSwaptionVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t BaseVolStructureCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t SpreadCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SpreadedSwaptionVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,BaseVolStructureCpp
    ,SpreadCpp
  ));

}

//SpreadedSwaptionVolatilityWorker::~SpreadedSwaptionVolatilityWorker(){
//
//}

//void SpreadedSwaptionVolatilityWorker::Destroy(){
//
//}

void SwaptionVTSMatrixWorker::Execute(){

  try{

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention BusinessDayConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mBusinessDayConvention);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> OptionTenorsLib;


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> SwapTenorsLib;


  // convert object IDs into library objects
  std::vector< std::vector< QuantLib::Handle<QuantLib::Quote> > > VolatilitiesLibObj =
      ObjectHandler::matrix::convert2< QuantLib::Handle<QuantLib::Quote> >(mVolatilities, "Volatilities");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSwaptionVTSMatrix(
          mObjectID,
          mCalendar,
          mBusinessDayConvention,
          mOptionTenors,
          mSwapTenors,
          mVolatilities,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SwaptionVolatilityMatrix(
          valueObject,
          CalendarEnum,
          BusinessDayConventionEnum,
          OptionTenorsLib,
          SwapTenorsLib,
          VolatilitiesLibObj,
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

void SwaptionVTSMatrixWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionVTSMatrix) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("BusinessDayConvention is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("OptionTenors is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("SwapTenors is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("Volatilities is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[1]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  String::Utf8Value strBusinessDayConvention(info[2]->ToString());
  string BusinessDayConventionCpp(strdup(*strBusinessDayConvention));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionTenorsCpp;

  Local<Array> OptionTenorsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < OptionTenorsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(OptionTenorsArray, i).ToLocalChecked()).FromJust()));
    OptionTenorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>SwapTenorsCpp;

  Local<Array> SwapTenorsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < SwapTenorsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(SwapTenorsArray, i).ToLocalChecked()).FromJust()));
    SwapTenorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector< std::vector<ObjectHandler::property_t> >VolatilitiesCpp;

  Local<Array> VolatilitiesMatrix = info[5].As<Array>();
  for (unsigned int i = 0; i < VolatilitiesMatrix->Length(); i++){
	  Local<Array> VolatilitiesArray = VolatilitiesMatrix->Get(i).As<Array>();
	  std::vector<ObjectHandler::property_t> tmp;
	  for (unsigned int j = 0; j < VolatilitiesArray->Length(); j++){
      ObjectHandler::property_t temp =
          ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(VolatilitiesArray, j).ToLocalChecked()).FromJust()));
		  tmp.push_back(temp);
	  }
	  VolatilitiesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[6]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSMatrixWorker(
    callback
    ,ObjectIDCpp
    ,CalendarCpp
    ,BusinessDayConventionCpp
    ,OptionTenorsCpp
    ,SwapTenorsCpp
    ,VolatilitiesCpp
    ,DayCounterCpp
  ));

}

//SwaptionVTSMatrixWorker::~SwaptionVTSMatrixWorker(){
//
//}

//void SwaptionVTSMatrixWorker::Destroy(){
//
//}

void SwaptionVolCube2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(AtmVolStructureCoerce, mAtmVolStructure, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::SwaptionVolatilityStructure> AtmVolStructureLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              AtmVolStructureCoerce);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> OptionTenorLib;


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> SwapTenorLib;


  // convert object IDs into library objects
  std::vector< std::vector< QuantLib::Handle<QuantLib::Quote> > > SpreadVolsLibObj =
      ObjectHandler::matrix::convert2< QuantLib::Handle<QuantLib::Quote> >(mSpreadVols, "SpreadVols");


  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapIndexBaseLibObjPtr, mSwapIndexBase,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ShortSwapIndexBaseLibObjPtr, mShortSwapIndexBase,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSwaptionVolCube2(
          mObjectID,
          mAtmVolStructure,
          mOptionTenor,
          mSwapTenor,
          mStrikeSpreads,
          mSpreadVols,
          mSwapIndexBase,
          mShortSwapIndexBase,
          mVegaWeightedSmileFit,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SwaptionVolCube2(
          valueObject,
          AtmVolStructureLibObj,
          OptionTenorLib,
          SwapTenorLib,
          mStrikeSpreads,
          SpreadVolsLibObj,
          SwapIndexBaseLibObjPtr,
          ShortSwapIndexBaseLibObjPtr,
          mVegaWeightedSmileFit,
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

void SwaptionVolCube2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionVolCube2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("StrikeSpreads is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("SpreadVols is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("SwapIndexBase is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("ShortSwapIndexBase is required.");
  }
  if (info.Length() == 8 || !info[8]->IsBoolean()) {
      return Nan::ThrowError("VegaWeightedSmileFit is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t AtmVolStructureCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionTenorCpp;

  Local<Array> OptionTenorArray = info[2].As<Array>();
  for (unsigned int i = 0; i < OptionTenorArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(OptionTenorArray, i).ToLocalChecked()).FromJust()));
    OptionTenorCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>SwapTenorCpp;

  Local<Array> SwapTenorArray = info[3].As<Array>();
  for (unsigned int i = 0; i < SwapTenorArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(SwapTenorArray, i).ToLocalChecked()).FromJust()));
    SwapTenorCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>StrikeSpreadsCpp;

  Local<Array> StrikeSpreadsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < StrikeSpreadsArray->Length(); i++){
    StrikeSpreadsCpp.push_back(Nan::To<double>(Nan::Get(StrikeSpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector< std::vector<ObjectHandler::property_t> >SpreadVolsCpp;

  Local<Array> SpreadVolsMatrix = info[5].As<Array>();
  for (unsigned int i = 0; i < SpreadVolsMatrix->Length(); i++){
	  Local<Array> SpreadVolsArray = SpreadVolsMatrix->Get(i).As<Array>();
	  std::vector<ObjectHandler::property_t> tmp;
	  for (unsigned int j = 0; j < SpreadVolsArray->Length(); j++){
      ObjectHandler::property_t temp =
          ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(SpreadVolsArray, j).ToLocalChecked()).FromJust()));
		  tmp.push_back(temp);
	  }
	  SpreadVolsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapIndexBase(info[6]->ToString());
  string SwapIndexBaseCpp(strdup(*strSwapIndexBase));

  // convert js argument to c++ type
  String::Utf8Value strShortSwapIndexBase(info[7]->ToString());
  string ShortSwapIndexBaseCpp(strdup(*strShortSwapIndexBase));

  // convert js argument to c++ type
  bool VegaWeightedSmileFitCpp = Nan::To<bool>(info[8]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVolCube2Worker(
    callback
    ,ObjectIDCpp
    ,AtmVolStructureCpp
    ,OptionTenorCpp
    ,SwapTenorCpp
    ,StrikeSpreadsCpp
    ,SpreadVolsCpp
    ,SwapIndexBaseCpp
    ,ShortSwapIndexBaseCpp
    ,VegaWeightedSmileFitCpp
  ));

}

//SwaptionVolCube2Worker::~SwaptionVolCube2Worker(){
//
//}

//void SwaptionVolCube2Worker::Destroy(){
//
//}

void SwaptionVolCube1Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(AtmVolStructureCoerce, mAtmVolStructure, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::SwaptionVolatilityStructure> AtmVolStructureLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              AtmVolStructureCoerce);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> OptionTenorsLib;


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> SwapTenorsLib;


  // convert object IDs into library objects
  std::vector< std::vector< QuantLib::Handle<QuantLib::Quote> > > SpreadVolsLibObj =
      ObjectHandler::matrix::convert2< QuantLib::Handle<QuantLib::Quote> >(mSpreadVols, "SpreadVols");


  // convert object IDs into library objects
  OH_GET_REFERENCE(SwapIndexBaseLibObjPtr, mSwapIndexBase,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)


  // convert object IDs into library objects
  OH_GET_REFERENCE(ShortSwapIndexBaseLibObjPtr, mShortSwapIndexBase,
      QuantLibAddin::SwapIndex, QuantLib::SwapIndex)


  // convert object IDs into library objects
  std::vector< std::vector< QuantLib::Handle<QuantLib::Quote> > > GuessLibObj =
      ObjectHandler::matrix::convert2< QuantLib::Handle<QuantLib::Quote> >(mGuess, "Guess");


  // convert object IDs into library objects
  OH_GET_REFERENCE(EndCriteriaLibObjPtr, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_REFERENCE(OptMethodLibObjPtr, mOptMethod,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSwaptionVolCube1(
          mObjectID,
          mAtmVolStructure,
          mOptionTenors,
          mSwapTenors,
          mStrikeSpreads,
          mSpreadVols,
          mSwapIndexBase,
          mShortSwapIndexBase,
          mVegaWeightedSmileFit,
          mGuess,
          mIsFixed,
          mIsAtmCalibrated,
          mEndCriteria,
          mMaxErrorTol,
          mOptMethod,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SwaptionVolCube1(
          valueObject,
          AtmVolStructureLibObj,
          OptionTenorsLib,
          SwapTenorsLib,
          mStrikeSpreads,
          SpreadVolsLibObj,
          SwapIndexBaseLibObjPtr,
          ShortSwapIndexBaseLibObjPtr,
          mVegaWeightedSmileFit,
          GuessLibObj,
          mIsFixed,
          mIsAtmCalibrated,
          EndCriteriaLibObjPtr,
          mMaxErrorTol,
          OptMethodLibObjPtr,
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

void SwaptionVolCube1Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionVolCube1) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("OptionTenors is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("SwapTenors is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("StrikeSpreads is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("SpreadVols is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("SwapIndexBase is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("ShortSwapIndexBase is required.");
  }
  if (info.Length() == 8 || !info[8]->IsBoolean()) {
      return Nan::ThrowError("VegaWeightedSmileFit is required.");
  }
  if (info.Length() == 9 || !info[9]->IsArray()) {
      return Nan::ThrowError("Guess is required.");
  }
  if (info.Length() == 10 || !info[10]->IsArray()) {
      return Nan::ThrowError("IsFixed is required.");
  }
  if (info.Length() == 11 || !info[11]->IsBoolean()) {
      return Nan::ThrowError("IsAtmCalibrated is required.");
  }
  if (info.Length() == 12 || !info[12]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 13 || !info[13]->IsNumber()) {
      return Nan::ThrowError("MaxErrorTol is required.");
  }
  if (info.Length() == 14 || !info[14]->IsString()) {
      return Nan::ThrowError("OptMethod is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t AtmVolStructureCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionTenorsCpp;

  Local<Array> OptionTenorsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < OptionTenorsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(OptionTenorsArray, i).ToLocalChecked()).FromJust()));
    OptionTenorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>SwapTenorsCpp;

  Local<Array> SwapTenorsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < SwapTenorsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(SwapTenorsArray, i).ToLocalChecked()).FromJust()));
    SwapTenorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>StrikeSpreadsCpp;

  Local<Array> StrikeSpreadsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < StrikeSpreadsArray->Length(); i++){
    StrikeSpreadsCpp.push_back(Nan::To<double>(Nan::Get(StrikeSpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector< std::vector<ObjectHandler::property_t> >SpreadVolsCpp;

  Local<Array> SpreadVolsMatrix = info[5].As<Array>();
  for (unsigned int i = 0; i < SpreadVolsMatrix->Length(); i++){
	  Local<Array> SpreadVolsArray = SpreadVolsMatrix->Get(i).As<Array>();
	  std::vector<ObjectHandler::property_t> tmp;
	  for (unsigned int j = 0; j < SpreadVolsArray->Length(); j++){
      ObjectHandler::property_t temp =
          ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(SpreadVolsArray, j).ToLocalChecked()).FromJust()));
		  tmp.push_back(temp);
	  }
	  SpreadVolsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapIndexBase(info[6]->ToString());
  string SwapIndexBaseCpp(strdup(*strSwapIndexBase));

  // convert js argument to c++ type
  String::Utf8Value strShortSwapIndexBase(info[7]->ToString());
  string ShortSwapIndexBaseCpp(strdup(*strShortSwapIndexBase));

  // convert js argument to c++ type
  bool VegaWeightedSmileFitCpp = Nan::To<bool>(info[8]).FromJust();

  // convert js argument to c++ type
  std::vector< std::vector<ObjectHandler::property_t> >GuessCpp;

  Local<Array> GuessMatrix = info[9].As<Array>();
  for (unsigned int i = 0; i < GuessMatrix->Length(); i++){
	  Local<Array> GuessArray = GuessMatrix->Get(i).As<Array>();
	  std::vector<ObjectHandler::property_t> tmp;
	  for (unsigned int j = 0; j < GuessArray->Length(); j++){
      ObjectHandler::property_t temp =
          ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(GuessArray, j).ToLocalChecked()).FromJust()));
		  tmp.push_back(temp);
	  }
	  GuessCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<bool>IsFixedCpp;

  Local<Array> IsFixedArray = info[10].As<Array>();
  for (unsigned int i = 0; i < IsFixedArray->Length(); i++){
    IsFixedCpp.push_back(Nan::To<bool>(Nan::Get(IsFixedArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool IsAtmCalibratedCpp = Nan::To<bool>(info[11]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[12]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  double MaxErrorTolCpp = Nan::To<double>(info[13]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strOptMethod(info[14]->ToString());
  string OptMethodCpp(strdup(*strOptMethod));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[15].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVolCube1Worker(
    callback
    ,ObjectIDCpp
    ,AtmVolStructureCpp
    ,OptionTenorsCpp
    ,SwapTenorsCpp
    ,StrikeSpreadsCpp
    ,SpreadVolsCpp
    ,SwapIndexBaseCpp
    ,ShortSwapIndexBaseCpp
    ,VegaWeightedSmileFitCpp
    ,GuessCpp
    ,IsFixedCpp
    ,IsAtmCalibratedCpp
    ,EndCriteriaCpp
    ,MaxErrorTolCpp
    ,OptMethodCpp
  ));

}

//SwaptionVolCube1Worker::~SwaptionVolCube1Worker(){
//
//}

//void SwaptionVolCube1Worker::Destroy(){
//
//}

void SmileSectionByCubeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(VolCubeTemp, mVolCube, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityCube> VolCubeLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityCube,
          QuantLib::SwaptionVolatilityCube>()(
              VolCubeTemp);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSmileSectionByCube(
          mObjectID,
          mVolCube,
          mOptionDate,
          mSwapTenor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SmileSectionByCube(
          valueObject,
          VolCubeLibObjPtr,
          OptionDateLib,
          SwapTenorLib,
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

void SmileSectionByCubeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SmileSectionByCube) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("VolCube is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strVolCube(info[1]->ToString());
  string VolCubeCpp(strdup(*strVolCube));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[3]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SmileSectionByCubeWorker(
    callback
    ,ObjectIDCpp
    ,VolCubeCpp
    ,OptionDateCpp
    ,SwapTenorCpp
  ));

}

//SmileSectionByCubeWorker::~SmileSectionByCubeWorker(){
//
//}

//void SmileSectionByCubeWorker::Destroy(){
//
//}

void SmileSectionByCube2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(VolCubeTemp, mVolCube, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityCube> VolCubeLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityCube,
          QuantLib::SwaptionVolatilityCube>()(
              VolCubeTemp);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period OptionDateLib;
  QuantLibAddin::cppToLibrary(mOptionDate, OptionDateLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSmileSectionByCube2(
          mObjectID,
          mVolCube,
          mOptionDate,
          mSwapTenor,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SmileSectionByCube(
          valueObject,
          VolCubeLibObjPtr,
          OptionDateLib,
          SwapTenorLib,
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

void SmileSectionByCube2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SmileSectionByCube2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("VolCube is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("OptionDate is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strVolCube(info[1]->ToString());
  string VolCubeCpp(strdup(*strVolCube));

  // convert js argument to c++ type
  String::Utf8Value strOptionDate(info[2]->ToString());
  string OptionDateCpp(strdup(*strOptionDate));

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[3]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SmileSectionByCube2Worker(
    callback
    ,ObjectIDCpp
    ,VolCubeCpp
    ,OptionDateCpp
    ,SwapTenorCpp
  ));

}

//SmileSectionByCube2Worker::~SmileSectionByCube2Worker(){
//
//}

//void SmileSectionByCube2Worker::Destroy(){
//
//}

void SwaptionVTSVolatilityWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlSwaptionVTSVolatilityBind bindObject =
      boost::bind((QuantLibAddin::qlSwaptionVTSVolatilitySignature)
              &QuantLib::SwaptionVolatilityStructure::volatility,
              ObjectIDLibObjPtr
          ,OptionDateLib
          ,SwapTenorLib
          ,_1
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlSwaptionVTSVolatilityBind,
                      QuantLib::Rate,
                      QuantLib::Volatility>
          (bindObject,
           mStrike,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSVolatilityWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 4 || !info[4]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[2]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

  // convert js argument to c++ type
  std::vector<double>StrikeCpp;

  Local<Array> StrikeArray = info[3].As<Array>();
  for (unsigned int i = 0; i < StrikeArray->Length(); i++){
    StrikeCpp.push_back(Nan::To<double>(Nan::Get(StrikeArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSVolatilityWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,SwapTenorCpp
    ,StrikeCpp
    ,AllowExtrapolationCpp
  ));

}

//SwaptionVTSVolatilityWorker::~SwaptionVTSVolatilityWorker(){
//
//}

//void SwaptionVTSVolatilityWorker::Destroy(){
//
//}

void SwaptionVTSVolatility2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period OptionTenorLib;
  QuantLibAddin::cppToLibrary(mOptionTenor, OptionTenorLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlSwaptionVTSVolatility2Bind bindObject =
      boost::bind((QuantLibAddin::qlSwaptionVTSVolatility2Signature)
              &QuantLib::SwaptionVolatilityStructure::volatility,
              ObjectIDLibObjPtr
          ,OptionTenorLib
          ,SwapTenorLib
          ,_1
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlSwaptionVTSVolatility2Bind,
                      QuantLib::Rate,
                      QuantLib::Volatility>
          (bindObject,
           mStrike,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSVolatility2Worker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSVolatility2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 4 || !info[4]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strOptionTenor(info[1]->ToString());
  string OptionTenorCpp(strdup(*strOptionTenor));

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[2]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

  // convert js argument to c++ type
  std::vector<double>StrikeCpp;

  Local<Array> StrikeArray = info[3].As<Array>();
  for (unsigned int i = 0; i < StrikeArray->Length(); i++){
    StrikeCpp.push_back(Nan::To<double>(Nan::Get(StrikeArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSVolatility2Worker(
    callback
    ,ObjectIDCpp
    ,OptionTenorCpp
    ,SwapTenorCpp
    ,StrikeCpp
    ,AllowExtrapolationCpp
  ));

}

//SwaptionVTSVolatility2Worker::~SwaptionVTSVolatility2Worker(){
//
//}

//void SwaptionVTSVolatility2Worker::Destroy(){
//
//}

void SwaptionVTSBlackVarianceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> OptionDateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlSwaptionVTSBlackVarianceBind bindObject =
      boost::bind((QuantLibAddin::qlSwaptionVTSBlackVarianceSignature)
              &QuantLib::SwaptionVolatilityStructure::blackVariance,
              ObjectIDLibObjPtr
          ,_1
          ,SwapTenorLib
          ,mStrike
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlSwaptionVTSBlackVarianceBind,
                      QuantLib::Date,
                      double>
          (bindObject,
            OptionDateLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSBlackVarianceWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSBlackVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("OptionDate is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 4 || !info[4]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionDateCpp;

  Local<Array> OptionDateArray = info[1].As<Array>();
  for (unsigned int i = 0; i < OptionDateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(OptionDateArray, i).ToLocalChecked()).FromJust()));
    OptionDateCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[2]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSBlackVarianceWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,SwapTenorCpp
    ,StrikeCpp
    ,AllowExtrapolationCpp
  ));

}

//SwaptionVTSBlackVarianceWorker::~SwaptionVTSBlackVarianceWorker(){
//
//}

//void SwaptionVTSBlackVarianceWorker::Destroy(){
//
//}

void SwaptionVTSBlackVariance2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> OptionTenorLib;


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlSwaptionVTSBlackVariance2Bind bindObject =
      boost::bind((QuantLibAddin::qlSwaptionVTSBlackVariance2Signature)
              &QuantLib::SwaptionVolatilityStructure::blackVariance,
              ObjectIDLibObjPtr
          ,_1
          ,SwapTenorLib
          ,mStrike
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlSwaptionVTSBlackVariance2Bind,
                      QuantLib::Period,
                      double>
          (bindObject,
            OptionTenorLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSBlackVariance2Worker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSBlackVariance2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 4 || !info[4]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionTenorCpp;

  Local<Array> OptionTenorArray = info[1].As<Array>();
  for (unsigned int i = 0; i < OptionTenorArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(OptionTenorArray, i).ToLocalChecked()).FromJust()));
    OptionTenorCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[2]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSBlackVariance2Worker(
    callback
    ,ObjectIDCpp
    ,OptionTenorCpp
    ,SwapTenorCpp
    ,StrikeCpp
    ,AllowExtrapolationCpp
  ));

}

//SwaptionVTSBlackVariance2Worker::~SwaptionVTSBlackVariance2Worker(){
//
//}

//void SwaptionVTSBlackVariance2Worker::Destroy(){
//
//}

void SwaptionVTSMaxSwapTenorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              ObjectIDTemp);

     
  // invoke the member function
  QuantLib::Period returnValue = ObjectIDLibObjPtr->maxSwapTenor(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSMaxSwapTenorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionVTSMaxSwapTenor) {

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
  Nan::AsyncQueueWorker(new SwaptionVTSMaxSwapTenorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SwaptionVTSMaxSwapTenorWorker::~SwaptionVTSMaxSwapTenorWorker(){
//
//}

//void SwaptionVTSMaxSwapTenorWorker::Destroy(){
//
//}

void SwaptionVTSBusinessDayConventionWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              ObjectIDTemp);

     
  // invoke the member function
  QuantLib::BusinessDayConvention returnValue = ObjectIDLibObjPtr->businessDayConvention(
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

void SwaptionVTSBusinessDayConventionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionVTSBusinessDayConvention) {

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
  Nan::AsyncQueueWorker(new SwaptionVTSBusinessDayConventionWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SwaptionVTSBusinessDayConventionWorker::~SwaptionVTSBusinessDayConventionWorker(){
//
//}

//void SwaptionVTSBusinessDayConventionWorker::Destroy(){
//
//}

void SwaptionVTSOptionDateFromTenorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> OptionTenorLib;

       std::vector<QuantLib::Date> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlSwaptionVTSOptionDateFromTenorBind bindObject =
      boost::bind((QuantLibAddin::qlSwaptionVTSOptionDateFromTenorSignature)
              &QuantLib::SwaptionVolatilityStructure::optionDateFromTenor,
              ObjectIDLibObjPtr
          ,_1
          );

  ObjectHandler::loop
      <QuantLibAddin::qlSwaptionVTSOptionDateFromTenorBind,
                      QuantLib::Period,
                      QuantLib::Date>
          (bindObject,
            OptionTenorLib,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSOptionDateFromTenorWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSOptionDateFromTenor) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionTenorCpp;

  Local<Array> OptionTenorArray = info[1].As<Array>();
  for (unsigned int i = 0; i < OptionTenorArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(OptionTenorArray, i).ToLocalChecked()).FromJust()));
    OptionTenorCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSOptionDateFromTenorWorker(
    callback
    ,ObjectIDCpp
    ,OptionTenorCpp
  ));

}

//SwaptionVTSOptionDateFromTenorWorker::~SwaptionVTSOptionDateFromTenorWorker(){
//
//}

//void SwaptionVTSOptionDateFromTenorWorker::Destroy(){
//
//}

void SwaptionVTSSwapLengthWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> SwapTenorLib;

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlSwaptionVTSSwapLengthBind bindObject =
      boost::bind((QuantLibAddin::qlSwaptionVTSSwapLengthSignature)
              &QuantLib::SwaptionVolatilityStructure::swapLength,
              ObjectIDLibObjPtr
          ,_1
          );

  ObjectHandler::loop
      <QuantLibAddin::qlSwaptionVTSSwapLengthBind,
                      QuantLib::Period,
                      QuantLib::Time>
          (bindObject,
            SwapTenorLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSSwapLengthWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSSwapLength) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>SwapTenorCpp;

  Local<Array> SwapTenorArray = info[1].As<Array>();
  for (unsigned int i = 0; i < SwapTenorArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(SwapTenorArray, i).ToLocalChecked()).FromJust()));
    SwapTenorCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSSwapLengthWorker(
    callback
    ,ObjectIDCpp
    ,SwapTenorCpp
  ));

}

//SwaptionVTSSwapLengthWorker::~SwaptionVTSSwapLengthWorker(){
//
//}

//void SwaptionVTSSwapLengthWorker::Destroy(){
//
//}

void SwaptionVTSSwapLength2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityStructure> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SwapStartLib = ObjectHandler::convert2<QuantLib::Date>(
      mSwapStart, "SwapStart");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SwapEndLib = ObjectHandler::convert2<QuantLib::Date>(
      mSwapEnd, "SwapEnd");

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->swapLength(
        SwapStartLib
        ,
         SwapEndLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSSwapLength2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SwaptionVTSSwapLength2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t SwapStartCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t SwapEndCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSSwapLength2Worker(
    callback
    ,ObjectIDCpp
    ,SwapStartCpp
    ,SwapEndCpp
  ));

}

//SwaptionVTSSwapLength2Worker::~SwaptionVTSSwapLength2Worker(){
//
//}

//void SwaptionVTSSwapLength2Worker::Destroy(){
//
//}

void SwaptionVTSMatrixOptionDatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityDiscrete> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityDiscrete,
          QuantLib::SwaptionVolatilityDiscrete>()(
              ObjectIDTemp);

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Date> returnValue = ObjectIDLibObjPtr->optionDates(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSMatrixOptionDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSMatrixOptionDates) {

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
  Nan::AsyncQueueWorker(new SwaptionVTSMatrixOptionDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SwaptionVTSMatrixOptionDatesWorker::~SwaptionVTSMatrixOptionDatesWorker(){
//
//}

//void SwaptionVTSMatrixOptionDatesWorker::Destroy(){
//
//}

void SwaptionVTSMatrixOptionTenorsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityDiscrete> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityDiscrete,
          QuantLib::SwaptionVolatilityDiscrete>()(
              ObjectIDTemp);

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Period> returnValue = ObjectIDLibObjPtr->optionTenors(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSMatrixOptionTenorsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSMatrixOptionTenors) {

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
  Nan::AsyncQueueWorker(new SwaptionVTSMatrixOptionTenorsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SwaptionVTSMatrixOptionTenorsWorker::~SwaptionVTSMatrixOptionTenorsWorker(){
//
//}

//void SwaptionVTSMatrixOptionTenorsWorker::Destroy(){
//
//}

void SwaptionVTSMatrixSwapTenorsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityDiscrete> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityDiscrete,
          QuantLib::SwaptionVolatilityDiscrete>()(
              ObjectIDTemp);

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Period> returnValue = ObjectIDLibObjPtr->swapTenors(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSMatrixSwapTenorsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSMatrixSwapTenors) {

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
  Nan::AsyncQueueWorker(new SwaptionVTSMatrixSwapTenorsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SwaptionVTSMatrixSwapTenorsWorker::~SwaptionVTSMatrixSwapTenorsWorker(){
//
//}

//void SwaptionVTSMatrixSwapTenorsWorker::Destroy(){
//
//}

void SwaptionVTSMatrixLocateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SwaptionVolatilityMatrix)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->locate(
        OptionDateLib
        ,
         SwapTenorLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSMatrixLocateWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSMatrixLocate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[2]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSMatrixLocateWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,SwapTenorCpp
  ));

}

//SwaptionVTSMatrixLocateWorker::~SwaptionVTSMatrixLocateWorker(){
//
//}

//void SwaptionVTSMatrixLocateWorker::Destroy(){
//
//}

void SwaptionVTSatmStrikeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityCube> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityCube,
          QuantLib::SwaptionVolatilityCube>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> OptionDateLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlSwaptionVTSatmStrikeBind bindObject =
      boost::bind((QuantLibAddin::qlSwaptionVTSatmStrikeSignature)
              &QuantLib::SwaptionVolatilityCube::atmStrike,
              ObjectIDLibObjPtr
          ,_1
          ,SwapTenorLib
          );

  ObjectHandler::loop
      <QuantLibAddin::qlSwaptionVTSatmStrikeBind,
                      QuantLib::Date,
                      QuantLib::Rate>
          (bindObject,
            OptionDateLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSatmStrikeWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSatmStrike) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("OptionDate is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionDateCpp;

  Local<Array> OptionDateArray = info[1].As<Array>();
  for (unsigned int i = 0; i < OptionDateArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(OptionDateArray, i).ToLocalChecked()).FromJust()));
    OptionDateCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[2]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSatmStrikeWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,SwapTenorCpp
  ));

}

//SwaptionVTSatmStrikeWorker::~SwaptionVTSatmStrikeWorker(){
//
//}

//void SwaptionVTSatmStrikeWorker::Destroy(){
//
//}

void SwaptionVTSatmStrike2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDTemp, mObjectID, ObjectHandler::Object)
  boost::shared_ptr<QuantLib::SwaptionVolatilityCube> ObjectIDLibObjPtr =
      QuantLibAddin::CoerceTermStructure<
          QuantLibAddin::SwaptionVolatilityCube,
          QuantLib::SwaptionVolatilityCube>()(
              ObjectIDTemp);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> OptionTenorLib;


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period SwapTenorLib;
  QuantLibAddin::cppToLibrary(mSwapTenor, SwapTenorLib);

     
  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlSwaptionVTSatmStrike2Bind bindObject =
      boost::bind((QuantLibAddin::qlSwaptionVTSatmStrike2Signature)
              &QuantLib::SwaptionVolatilityCube::atmStrike,
              ObjectIDLibObjPtr
          ,_1
          ,SwapTenorLib
          );

  ObjectHandler::loop
      <QuantLibAddin::qlSwaptionVTSatmStrike2Bind,
                      QuantLib::Period,
                      QuantLib::Rate>
          (bindObject,
            OptionTenorLib,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SwaptionVTSatmStrike2Worker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SwaptionVTSatmStrike2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("SwapTenor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionTenorCpp;

  Local<Array> OptionTenorArray = info[1].As<Array>();
  for (unsigned int i = 0; i < OptionTenorArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(OptionTenorArray, i).ToLocalChecked()).FromJust()));
    OptionTenorCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strSwapTenor(info[2]->ToString());
  string SwapTenorCpp(strdup(*strSwapTenor));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SwaptionVTSatmStrike2Worker(
    callback
    ,ObjectIDCpp
    ,OptionTenorCpp
    ,SwapTenorCpp
  ));

}

//SwaptionVTSatmStrike2Worker::~SwaptionVTSatmStrike2Worker(){
//
//}

//void SwaptionVTSatmStrike2Worker::Destroy(){
//
//}

void SparseSabrParametersWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SwaptionVolCube1)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->getSparseSabrParameters(
      );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SparseSabrParametersWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SparseSabrParameters) {

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
  Nan::AsyncQueueWorker(new SparseSabrParametersWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SparseSabrParametersWorker::~SparseSabrParametersWorker(){
//
//}

//void SparseSabrParametersWorker::Destroy(){
//
//}

void DenseSabrParametersWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SwaptionVolCube1)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->getDenseSabrParameters(
      );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void DenseSabrParametersWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::DenseSabrParameters) {

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
  Nan::AsyncQueueWorker(new DenseSabrParametersWorker(
    callback
    ,ObjectIDCpp
  ));

}

//DenseSabrParametersWorker::~DenseSabrParametersWorker(){
//
//}

//void DenseSabrParametersWorker::Destroy(){
//
//}

void MarketVolCubeWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SwaptionVolCube1)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->getMarketVolCube(
      );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MarketVolCubeWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MarketVolCube) {

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
  Nan::AsyncQueueWorker(new MarketVolCubeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//MarketVolCubeWorker::~MarketVolCubeWorker(){
//
//}

//void MarketVolCubeWorker::Destroy(){
//
//}

void VolCubeAtmCalibratedWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SwaptionVolCube1)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->getVolCubeAtmCalibrated(
      );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VolCubeAtmCalibratedWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::VolCubeAtmCalibrated) {

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
  Nan::AsyncQueueWorker(new VolCubeAtmCalibratedWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VolCubeAtmCalibratedWorker::~VolCubeAtmCalibratedWorker(){
//
//}

//void VolCubeAtmCalibratedWorker::Destroy(){
//
//}
 