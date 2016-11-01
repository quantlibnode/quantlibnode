// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "assetswap.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/indexes/iborindex.hpp>
#include <qlo/schedule.hpp>
#include <qlo/assetswap.hpp>
#include <qlo/termstructures.hpp>
#include <qlo/bonds.hpp>
#include <ql/instruments/assetswap.hpp>
#include <ql/indexes/iborindex.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void AssetSwapWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(BondLibObjPtr, mBond,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert object IDs into library objects
  OH_GET_REFERENCE(FloatingLegScheduleLibObjPtr, mFloatingLegSchedule,
      QuantLibAddin::Schedule, QuantLib::Schedule)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter FloatingLegDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mFloatingLegDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlAssetSwap(
          mObjectID,
          mPayBondCoupon,
          mBond,
          mCleanPrice,
          mIborIndex,
          mSpread,
          mFloatingLegSchedule,
          mFloatingLegDayCounter,
          mParAssetSwap,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::AssetSwap(
          valueObject,
          mPayBondCoupon,
          BondLibObjPtr,
          mCleanPrice,
          IborIndexLibObjPtr,
          mSpread,
          FloatingLegScheduleLibObjPtr,
          FloatingLegDayCounterEnum,
          mParAssetSwap,
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

void AssetSwapWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AssetSwap) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("PayBondCoupon is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Bond is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("CleanPrice is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Spread is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("FloatingLegSchedule is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("FloatingLegDayCounter is required.");
  }
  if (info.Length() == 8 || !info[8]->IsBoolean()) {
      return Nan::ThrowError("ParAssetSwap is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  bool PayBondCouponCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strBond(info[2]->ToString());
  string BondCpp(strdup(*strBond));

  // convert js argument to c++ type
  double CleanPriceCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[4]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  double SpreadCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strFloatingLegSchedule(info[6]->ToString());
  string FloatingLegScheduleCpp(strdup(*strFloatingLegSchedule));

  // convert js argument to c++ type
  String::Utf8Value strFloatingLegDayCounter(info[7]->ToString());
  string FloatingLegDayCounterCpp(strdup(*strFloatingLegDayCounter));

  // convert js argument to c++ type
  bool ParAssetSwapCpp = Nan::To<bool>(info[8]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AssetSwapWorker(
    callback
    ,ObjectIDCpp
    ,PayBondCouponCpp
    ,BondCpp
    ,CleanPriceCpp
    ,IborIndexCpp
    ,SpreadCpp
    ,FloatingLegScheduleCpp
    ,FloatingLegDayCounterCpp
    ,ParAssetSwapCpp
  ));

}

//AssetSwapWorker::~AssetSwapWorker(){
//
//}

//AssetSwapWorker::Destroy(){
//
//}

void AssetSwap2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(BondLibObjPtr, mBond,
      QuantLibAddin::Bond, QuantLib::Bond)


  // convert object IDs into library objects
  OH_GET_REFERENCE(IborIndexLibObjPtr, mIborIndex,
      QuantLibAddin::IborIndex, QuantLib::IborIndex)


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter FloatingLegDayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mFloatingLegDayCounter);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date DealMaturityLib = ObjectHandler::convert2<QuantLib::Date>(
      mDealMaturity, "DealMaturity");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlAssetSwap2(
          mObjectID,
          mParAssetSwap,
          mBond,
          mCleanPrice,
          mNonParRepayment,
          mGearing,
          mIborIndex,
          mSpread,
          mFloatingLegDayCounter,
          mDealMaturity,
          mPayBondCoupon,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::AssetSwap(
          valueObject,
          mParAssetSwap,
          BondLibObjPtr,
          mCleanPrice,
          mNonParRepayment,
          mGearing,
          IborIndexLibObjPtr,
          mSpread,
          FloatingLegDayCounterEnum,
          DealMaturityLib,
          mPayBondCoupon,
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

void AssetSwap2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AssetSwap2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("ParAssetSwap is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Bond is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("CleanPrice is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("NonParRepayment is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Gearing is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("IborIndex is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Spread is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("FloatingLegDayCounter is required.");
  }
  if (info.Length() == 10 || !info[10]->IsBoolean()) {
      return Nan::ThrowError("PayBondCoupon is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  bool ParAssetSwapCpp = Nan::To<bool>(info[1]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strBond(info[2]->ToString());
  string BondCpp(strdup(*strBond));

  // convert js argument to c++ type
  double CleanPriceCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double NonParRepaymentCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double GearingCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strIborIndex(info[6]->ToString());
  string IborIndexCpp(strdup(*strIborIndex));

  // convert js argument to c++ type
  double SpreadCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strFloatingLegDayCounter(info[8]->ToString());
  string FloatingLegDayCounterCpp(strdup(*strFloatingLegDayCounter));

  // convert js argument to c++ type
  ObjectHandler::property_t DealMaturityCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[9]).FromJust()));

  // convert js argument to c++ type
  bool PayBondCouponCpp = Nan::To<bool>(info[10]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[11].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AssetSwap2Worker(
    callback
    ,ObjectIDCpp
    ,ParAssetSwapCpp
    ,BondCpp
    ,CleanPriceCpp
    ,NonParRepaymentCpp
    ,GearingCpp
    ,IborIndexCpp
    ,SpreadCpp
    ,FloatingLegDayCounterCpp
    ,DealMaturityCpp
    ,PayBondCouponCpp
  ));

}

//AssetSwap2Worker::~AssetSwap2Worker(){
//
//}

//AssetSwap2Worker::Destroy(){
//
//}

void AssetSwapBondLegAnalysisWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date AfterDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mAfterDate, "AfterDate");

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::AssetSwap)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->bondLeg(
        AfterDateLib
       );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AssetSwapBondLegAnalysisWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AssetSwapBondLegAnalysis) {

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
  Nan::AsyncQueueWorker(new AssetSwapBondLegAnalysisWorker(
    callback
    ,ObjectIDCpp
    ,AfterDateCpp
  ));

}

//AssetSwapBondLegAnalysisWorker::~AssetSwapBondLegAnalysisWorker(){
//
//}

//AssetSwapBondLegAnalysisWorker::Destroy(){
//
//}

void AssetSwapFloatingLegAnalysisWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date AfterDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mAfterDate, "AfterDate");

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::AssetSwap)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->floatingLeg(
        AfterDateLib
       );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AssetSwapFloatingLegAnalysisWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AssetSwapFloatingLegAnalysis) {

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
  Nan::AsyncQueueWorker(new AssetSwapFloatingLegAnalysisWorker(
    callback
    ,ObjectIDCpp
    ,AfterDateCpp
  ));

}

//AssetSwapFloatingLegAnalysisWorker::~AssetSwapFloatingLegAnalysisWorker(){
//
//}

//AssetSwapFloatingLegAnalysisWorker::Destroy(){
//
//}

void AssetSwapFairSpreadWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AssetSwap, QuantLib::AssetSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->fairSpread(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AssetSwapFairSpreadWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AssetSwapFairSpread) {

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
  Nan::AsyncQueueWorker(new AssetSwapFairSpreadWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AssetSwapFairSpreadWorker::~AssetSwapFairSpreadWorker(){
//
//}

//AssetSwapFairSpreadWorker::Destroy(){
//
//}

void AssetSwapFloatingLegBPSWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AssetSwap, QuantLib::AssetSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->floatingLegBPS(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AssetSwapFloatingLegBPSWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AssetSwapFloatingLegBPS) {

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
  Nan::AsyncQueueWorker(new AssetSwapFloatingLegBPSWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AssetSwapFloatingLegBPSWorker::~AssetSwapFloatingLegBPSWorker(){
//
//}

//AssetSwapFloatingLegBPSWorker::Destroy(){
//
//}

void AssetSwapFairCleanPriceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AssetSwap, QuantLib::AssetSwap)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->fairCleanPrice(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AssetSwapFairCleanPriceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AssetSwapFairCleanPrice) {

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
  Nan::AsyncQueueWorker(new AssetSwapFairCleanPriceWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AssetSwapFairCleanPriceWorker::~AssetSwapFairCleanPriceWorker(){
//
//}

//AssetSwapFairCleanPriceWorker::Destroy(){
//
//}

void AssetSwapFairNonParRepaymentWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AssetSwap, QuantLib::AssetSwap)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->fairNonParRepayment(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AssetSwapFairNonParRepaymentWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AssetSwapFairNonParRepayment) {

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
  Nan::AsyncQueueWorker(new AssetSwapFairNonParRepaymentWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AssetSwapFairNonParRepaymentWorker::~AssetSwapFairNonParRepaymentWorker(){
//
//}

//AssetSwapFairNonParRepaymentWorker::Destroy(){
//
//}

void AssetSwapParSwapWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AssetSwap, QuantLib::AssetSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->parSwap(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AssetSwapParSwapWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AssetSwapParSwap) {

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
  Nan::AsyncQueueWorker(new AssetSwapParSwapWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AssetSwapParSwapWorker::~AssetSwapParSwapWorker(){
//
//}

//AssetSwapParSwapWorker::Destroy(){
//
//}

void AssetSwapPayBondCouponWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AssetSwap, QuantLib::AssetSwap)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->payBondCoupon(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AssetSwapPayBondCouponWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AssetSwapPayBondCoupon) {

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
  Nan::AsyncQueueWorker(new AssetSwapPayBondCouponWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AssetSwapPayBondCouponWorker::~AssetSwapPayBondCouponWorker(){
//
//}

//AssetSwapPayBondCouponWorker::Destroy(){
//
//}
 