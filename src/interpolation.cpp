// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "interpolation.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/interpolation.hpp>
#include <qlo/interpolation2D.hpp>
#include <qlo/optimization.hpp>
#include <ql/math/interpolations/sabrinterpolation.hpp>
#include <ql/math/interpolations/abcdinterpolation.hpp>
#include <ql/math/interpolations/interpolation2d.hpp>
#include <qlo/loop/loop_interpolation.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void InterpolationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XArrayLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXArray);


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > YArrayLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mYArray, "YArray");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlInterpolation(
          mObjectID,
          mInterpolationType,
          mXArray,
          mYArray,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::GenericInterp(
          valueObject,
          mInterpolationType,
          mXArray,
          YArrayLibObj,
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

void InterpolationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Interpolation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("InterpolationType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("XArray is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("YArray is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strInterpolationType(info[1]->ToString());
  string InterpolationTypeCpp(strdup(*strInterpolationType));

  // convert js argument to c++ type
  std::vector<double>XArrayCpp;

  Local<Array> XArrayArray = info[2].As<Array>();
  for (unsigned int i = 0; i < XArrayArray->Length(); i++){
    XArrayCpp.push_back(Nan::To<double>(Nan::Get(XArrayArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>YArrayCpp;

  Local<Array> YArrayArray = info[3].As<Array>();
  for (unsigned int i = 0; i < YArrayArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(YArrayArray, i).ToLocalChecked()).FromJust()));
    YArrayCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterpolationWorker(
    callback
    ,ObjectIDCpp
    ,InterpolationTypeCpp
    ,XArrayCpp
    ,YArrayCpp
  ));

}

//InterpolationWorker::~InterpolationWorker(){
//
//}

//InterpolationWorker::Destroy(){
//
//}

void MixedLinearCubicInterpolationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XArrayLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXArray);


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > YArrayLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mYArray, "YArray");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SwitchIndexLib;
  QuantLibAddin::cppToLibrary(mSwitchIndex, SwitchIndexLib);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::CubicInterpolation::DerivativeApprox DerApproxEnum =
      ObjectHandler::Create<QuantLib::CubicInterpolation::DerivativeApprox>()(mDerApprox);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::CubicInterpolation::BoundaryCondition LeftConditionTypeEnum =
      ObjectHandler::Create<QuantLib::CubicInterpolation::BoundaryCondition>()(mLeftConditionType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::CubicInterpolation::BoundaryCondition RightConditionTypeEnum =
      ObjectHandler::Create<QuantLib::CubicInterpolation::BoundaryCondition>()(mRightConditionType);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlMixedLinearCubicInterpolation(
          mObjectID,
          mXArray,
          mYArray,
          mSwitchIndex,
          mDerApprox,
          mMonotonic,
          mLeftConditionType,
          mLeftConditionValue,
          mRightConditionType,
          mRightConditionValue,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::MixedLinearCubicInterpolation(
          valueObject,
          mXArray,
          YArrayLibObj,
          SwitchIndexLib,
          DerApproxEnum,
          mMonotonic,
          LeftConditionTypeEnum,
          mLeftConditionValue,
          RightConditionTypeEnum,
          mRightConditionValue,
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

void MixedLinearCubicInterpolationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::MixedLinearCubicInterpolation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XArray is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("YArray is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("SwitchIndex is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("DerApprox is required.");
  }
  if (info.Length() == 5 || !info[5]->IsBoolean()) {
      return Nan::ThrowError("Monotonic is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("LeftConditionType is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("LeftConditionValue is required.");
  }
  if (info.Length() == 8 || !info[8]->IsString()) {
      return Nan::ThrowError("RightConditionType is required.");
  }
  if (info.Length() == 9 || !info[9]->IsNumber()) {
      return Nan::ThrowError("RightConditionValue is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XArrayCpp;

  Local<Array> XArrayArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XArrayArray->Length(); i++){
    XArrayCpp.push_back(Nan::To<double>(Nan::Get(XArrayArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>YArrayCpp;

  Local<Array> YArrayArray = info[2].As<Array>();
  for (unsigned int i = 0; i < YArrayArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(YArrayArray, i).ToLocalChecked()).FromJust()));
    YArrayCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  long SwitchIndexCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDerApprox(info[4]->ToString());
  string DerApproxCpp(strdup(*strDerApprox));

  // convert js argument to c++ type
  bool MonotonicCpp = Nan::To<bool>(info[5]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strLeftConditionType(info[6]->ToString());
  string LeftConditionTypeCpp(strdup(*strLeftConditionType));

  // convert js argument to c++ type
  double LeftConditionValueCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strRightConditionType(info[8]->ToString());
  string RightConditionTypeCpp(strdup(*strRightConditionType));

  // convert js argument to c++ type
  double RightConditionValueCpp = Nan::To<double>(info[9]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[10].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MixedLinearCubicInterpolationWorker(
    callback
    ,ObjectIDCpp
    ,XArrayCpp
    ,YArrayCpp
    ,SwitchIndexCpp
    ,DerApproxCpp
    ,MonotonicCpp
    ,LeftConditionTypeCpp
    ,LeftConditionValueCpp
    ,RightConditionTypeCpp
    ,RightConditionValueCpp
  ));

}

//MixedLinearCubicInterpolationWorker::~MixedLinearCubicInterpolationWorker(){
//
//}

//MixedLinearCubicInterpolationWorker::Destroy(){
//
//}

void CubicInterpolationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XArrayLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXArray);


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > YArrayLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mYArray, "YArray");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::CubicInterpolation::DerivativeApprox DerApproxEnum =
      ObjectHandler::Create<QuantLib::CubicInterpolation::DerivativeApprox>()(mDerApprox);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::CubicInterpolation::BoundaryCondition LeftConditionTypeEnum =
      ObjectHandler::Create<QuantLib::CubicInterpolation::BoundaryCondition>()(mLeftConditionType);


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::CubicInterpolation::BoundaryCondition RightConditionTypeEnum =
      ObjectHandler::Create<QuantLib::CubicInterpolation::BoundaryCondition>()(mRightConditionType);


  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCubicInterpolation(
          mObjectID,
          mXArray,
          mYArray,
          mDerApprox,
          mMonotonic,
          mLeftConditionType,
          mLeftConditionValue,
          mRightConditionType,
          mRightConditionValue,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CubicInterpolation(
          valueObject,
          mXArray,
          YArrayLibObj,
          DerApproxEnum,
          mMonotonic,
          LeftConditionTypeEnum,
          mLeftConditionValue,
          RightConditionTypeEnum,
          mRightConditionValue,
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

void CubicInterpolationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CubicInterpolation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XArray is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("YArray is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("DerApprox is required.");
  }
  if (info.Length() == 4 || !info[4]->IsBoolean()) {
      return Nan::ThrowError("Monotonic is required.");
  }
  if (info.Length() == 5 || !info[5]->IsString()) {
      return Nan::ThrowError("LeftConditionType is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("LeftConditionValue is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("RightConditionType is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("RightConditionValue is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XArrayCpp;

  Local<Array> XArrayArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XArrayArray->Length(); i++){
    XArrayCpp.push_back(Nan::To<double>(Nan::Get(XArrayArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>YArrayCpp;

  Local<Array> YArrayArray = info[2].As<Array>();
  for (unsigned int i = 0; i < YArrayArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(YArrayArray, i).ToLocalChecked()).FromJust()));
    YArrayCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strDerApprox(info[3]->ToString());
  string DerApproxCpp(strdup(*strDerApprox));

  // convert js argument to c++ type
  bool MonotonicCpp = Nan::To<bool>(info[4]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strLeftConditionType(info[5]->ToString());
  string LeftConditionTypeCpp(strdup(*strLeftConditionType));

  // convert js argument to c++ type
  double LeftConditionValueCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strRightConditionType(info[7]->ToString());
  string RightConditionTypeCpp(strdup(*strRightConditionType));

  // convert js argument to c++ type
  double RightConditionValueCpp = Nan::To<double>(info[8]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[9].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CubicInterpolationWorker(
    callback
    ,ObjectIDCpp
    ,XArrayCpp
    ,YArrayCpp
    ,DerApproxCpp
    ,MonotonicCpp
    ,LeftConditionTypeCpp
    ,LeftConditionValueCpp
    ,RightConditionTypeCpp
    ,RightConditionValueCpp
  ));

}

//CubicInterpolationWorker::~CubicInterpolationWorker(){
//
//}

//CubicInterpolationWorker::Destroy(){
//
//}

void AbcdInterpolationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XArrayLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXArray);


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > YArrayLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mYArray, "YArray");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(EndCriteriaLibObjPtr, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_REFERENCE(OptimizationMethLibObjPtr, mOptimizationMeth,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlAbcdInterpolation(
          mObjectID,
          mXArray,
          mYArray,
          mA,
          mB,
          mC,
          mD,
          mAIsFixed,
          mBIsFixed,
          mCIsFixed,
          mDIsFixed,
          mVegaWeighted,
          mEndCriteria,
          mOptimizationMeth,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::AbcdInterpolation(
          valueObject,
          mXArray,
          YArrayLibObj,
          mA,
          mB,
          mC,
          mD,
          mAIsFixed,
          mBIsFixed,
          mCIsFixed,
          mDIsFixed,
          mVegaWeighted,
          EndCriteriaLibObjPtr,
          OptimizationMethLibObjPtr,
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

void AbcdInterpolationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdInterpolation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XArray is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("YArray is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("A is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("B is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("C is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("D is required.");
  }
  if (info.Length() == 7 || !info[7]->IsBoolean()) {
      return Nan::ThrowError("AIsFixed is required.");
  }
  if (info.Length() == 8 || !info[8]->IsBoolean()) {
      return Nan::ThrowError("BIsFixed is required.");
  }
  if (info.Length() == 9 || !info[9]->IsBoolean()) {
      return Nan::ThrowError("CIsFixed is required.");
  }
  if (info.Length() == 10 || !info[10]->IsBoolean()) {
      return Nan::ThrowError("DIsFixed is required.");
  }
  if (info.Length() == 11 || !info[11]->IsBoolean()) {
      return Nan::ThrowError("VegaWeighted is required.");
  }
  if (info.Length() == 12 || !info[12]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 13 || !info[13]->IsString()) {
      return Nan::ThrowError("OptimizationMeth is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XArrayCpp;

  Local<Array> XArrayArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XArrayArray->Length(); i++){
    XArrayCpp.push_back(Nan::To<double>(Nan::Get(XArrayArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>YArrayCpp;

  Local<Array> YArrayArray = info[2].As<Array>();
  for (unsigned int i = 0; i < YArrayArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(YArrayArray, i).ToLocalChecked()).FromJust()));
    YArrayCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  double ACpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double BCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double CCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double DCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  bool AIsFixedCpp = Nan::To<bool>(info[7]).FromJust();

  // convert js argument to c++ type
  bool BIsFixedCpp = Nan::To<bool>(info[8]).FromJust();

  // convert js argument to c++ type
  bool CIsFixedCpp = Nan::To<bool>(info[9]).FromJust();

  // convert js argument to c++ type
  bool DIsFixedCpp = Nan::To<bool>(info[10]).FromJust();

  // convert js argument to c++ type
  bool VegaWeightedCpp = Nan::To<bool>(info[11]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[12]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  String::Utf8Value strOptimizationMeth(info[13]->ToString());
  string OptimizationMethCpp(strdup(*strOptimizationMeth));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[14].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdInterpolationWorker(
    callback
    ,ObjectIDCpp
    ,XArrayCpp
    ,YArrayCpp
    ,ACpp
    ,BCpp
    ,CCpp
    ,DCpp
    ,AIsFixedCpp
    ,BIsFixedCpp
    ,CIsFixedCpp
    ,DIsFixedCpp
    ,VegaWeightedCpp
    ,EndCriteriaCpp
    ,OptimizationMethCpp
  ));

}

//AbcdInterpolationWorker::~AbcdInterpolationWorker(){
//
//}

//AbcdInterpolationWorker::Destroy(){
//
//}

void SABRInterpolationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XArrayLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXArray);


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > YArrayLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mYArray, "YArray");


  // convert object IDs into library objects
  QuantLib::Handle<QuantLib::Quote> ForwardLibObj =
      ObjectHandler::convert2< QuantLib::Handle<QuantLib::Quote> >(mForward, "Forward");


  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert object IDs into library objects
  OH_GET_REFERENCE(EndCriteriaLibObjPtr, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_REFERENCE(OptimizationMethLibObjPtr, mOptimizationMeth,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSABRInterpolation(
          mObjectID,
          mXArray,
          mYArray,
          mExpiry,
          mForward,
          mAlpha,
          mBeta,
          mNu,
          mRho,
          mAlphaIsFixed,
          mBetaIsFixed,
          mNuIsFixed,
          mRhoIsFixed,
          mVegaWeighted,
          mEndCriteria,
          mOptimizationMeth,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SABRInterpolation(
          valueObject,
          mXArray,
          YArrayLibObj,
          mExpiry,
          ForwardLibObj,
          mAlpha,
          mBeta,
          mNu,
          mRho,
          mAlphaIsFixed,
          mBetaIsFixed,
          mNuIsFixed,
          mRhoIsFixed,
          mVegaWeighted,
          EndCriteriaLibObjPtr,
          OptimizationMethLibObjPtr,
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

void SABRInterpolationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XArray is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("YArray is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Expiry is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Alpha is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Nu is required.");
  }
  if (info.Length() == 8 || !info[8]->IsNumber()) {
      return Nan::ThrowError("Rho is required.");
  }
  if (info.Length() == 9 || !info[9]->IsBoolean()) {
      return Nan::ThrowError("AlphaIsFixed is required.");
  }
  if (info.Length() == 10 || !info[10]->IsBoolean()) {
      return Nan::ThrowError("BetaIsFixed is required.");
  }
  if (info.Length() == 11 || !info[11]->IsBoolean()) {
      return Nan::ThrowError("NuIsFixed is required.");
  }
  if (info.Length() == 12 || !info[12]->IsBoolean()) {
      return Nan::ThrowError("RhoIsFixed is required.");
  }
  if (info.Length() == 13 || !info[13]->IsBoolean()) {
      return Nan::ThrowError("VegaWeighted is required.");
  }
  if (info.Length() == 14 || !info[14]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 15 || !info[15]->IsString()) {
      return Nan::ThrowError("OptimizationMeth is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XArrayCpp;

  Local<Array> XArrayArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XArrayArray->Length(); i++){
    XArrayCpp.push_back(Nan::To<double>(Nan::Get(XArrayArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>YArrayCpp;

  Local<Array> YArrayArray = info[2].As<Array>();
  for (unsigned int i = 0; i < YArrayArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(YArrayArray, i).ToLocalChecked()).FromJust()));
    YArrayCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  double ExpiryCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t ForwardCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[4]).FromJust()));

  // convert js argument to c++ type
  double AlphaCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[6]).FromJust();

  // convert js argument to c++ type
  double NuCpp = Nan::To<double>(info[7]).FromJust();

  // convert js argument to c++ type
  double RhoCpp = Nan::To<double>(info[8]).FromJust();

  // convert js argument to c++ type
  bool AlphaIsFixedCpp = Nan::To<bool>(info[9]).FromJust();

  // convert js argument to c++ type
  bool BetaIsFixedCpp = Nan::To<bool>(info[10]).FromJust();

  // convert js argument to c++ type
  bool NuIsFixedCpp = Nan::To<bool>(info[11]).FromJust();

  // convert js argument to c++ type
  bool RhoIsFixedCpp = Nan::To<bool>(info[12]).FromJust();

  // convert js argument to c++ type
  bool VegaWeightedCpp = Nan::To<bool>(info[13]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[14]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  String::Utf8Value strOptimizationMeth(info[15]->ToString());
  string OptimizationMethCpp(strdup(*strOptimizationMeth));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[16].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SABRInterpolationWorker(
    callback
    ,ObjectIDCpp
    ,XArrayCpp
    ,YArrayCpp
    ,ExpiryCpp
    ,ForwardCpp
    ,AlphaCpp
    ,BetaCpp
    ,NuCpp
    ,RhoCpp
    ,AlphaIsFixedCpp
    ,BetaIsFixedCpp
    ,NuIsFixedCpp
    ,RhoIsFixedCpp
    ,VegaWeightedCpp
    ,EndCriteriaCpp
    ,OptimizationMethCpp
  ));

}

//SABRInterpolationWorker::~SABRInterpolationWorker(){
//
//}

//SABRInterpolationWorker::Destroy(){
//
//}

void Interpolation2DWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XArrayLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXArray);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> YArrayLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mYArray);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix ZMatrixLib = QuantLibAddin::vvToQlMatrix(mZMatrix);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlInterpolation2D(
          mObjectID,
          mInterpolationType,
          mXArray,
          mYArray,
          mZMatrix,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Interpolation2D(
          valueObject,
          mInterpolationType,
          mXArray,
          mYArray,
          ZMatrixLib,
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

void Interpolation2DWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Interpolation2D) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("InterpolationType is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("XArray is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("YArray is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("ZMatrix is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strInterpolationType(info[1]->ToString());
  string InterpolationTypeCpp(strdup(*strInterpolationType));

  // convert js argument to c++ type
  std::vector<double>XArrayCpp;

  Local<Array> XArrayArray = info[2].As<Array>();
  for (unsigned int i = 0; i < XArrayArray->Length(); i++){
    XArrayCpp.push_back(Nan::To<double>(Nan::Get(XArrayArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>YArrayCpp;

  Local<Array> YArrayArray = info[3].As<Array>();
  for (unsigned int i = 0; i < YArrayArray->Length(); i++){
    YArrayCpp.push_back(Nan::To<double>(Nan::Get(YArrayArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector< std::vector<double> >ZMatrixCpp;

  Local<Array> ZMatrixMatrix = info[4].As<Array>();
  for (unsigned int i = 0; i < ZMatrixMatrix->Length(); i++){
	  Local<Array> ZMatrixArray = ZMatrixMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < ZMatrixArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(ZMatrixArray, j).ToLocalChecked()).FromJust());
	  }
	  ZMatrixCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new Interpolation2DWorker(
    callback
    ,ObjectIDCpp
    ,InterpolationTypeCpp
    ,XArrayCpp
    ,YArrayCpp
    ,ZMatrixCpp
  ));

}

//Interpolation2DWorker::~Interpolation2DWorker(){
//
//}

//Interpolation2DWorker::Destroy(){
//
//}

void ExtrapolatorEnableExtrapolationWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Extrapolator)


  // invoke the member function
  ObjectIDObjPtr->enableExtrapolation(
        mExtrapolationFlag
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void ExtrapolatorEnableExtrapolationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::Null()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ExtrapolatorEnableExtrapolation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("ExtrapolationFlag is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  bool ExtrapolationFlagCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ExtrapolatorEnableExtrapolationWorker(
    callback
    ,ObjectIDCpp
    ,ExtrapolationFlagCpp
  ));

}

//ExtrapolatorEnableExtrapolationWorker::~ExtrapolatorEnableExtrapolationWorker(){
//
//}

//ExtrapolatorEnableExtrapolationWorker::Destroy(){
//
//}

void InterpolationInterpolateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XValuesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXValues);

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Interpolation)

  std::vector<QuantLib::Real> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlInterpolationInterpolateBind bindObject =
      boost::bind((QuantLibAddin::qlInterpolationInterpolateSignature)
              &QuantLibAddin::Interpolation::operator(),
              ObjectIDObjPtr
          ,_1
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlInterpolationInterpolateBind,
                      QuantLib::Real,
                      QuantLib::Real>
          (bindObject,
            mXValues,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolationInterpolateWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::InterpolationInterpolate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XValues is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XValuesCpp;

  Local<Array> XValuesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XValuesArray->Length(); i++){
    XValuesCpp.push_back(Nan::To<double>(Nan::Get(XValuesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterpolationInterpolateWorker(
    callback
    ,ObjectIDCpp
    ,XValuesCpp
    ,AllowExtrapolationCpp
  ));

}

//InterpolationInterpolateWorker::~InterpolationInterpolateWorker(){
//
//}

//InterpolationInterpolateWorker::Destroy(){
//
//}

void InterpolationDerivativeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XValuesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXValues);

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Interpolation)

  std::vector<QuantLib::Real> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlInterpolationDerivativeBind bindObject =
      boost::bind((QuantLibAddin::qlInterpolationDerivativeSignature)
              &QuantLibAddin::Interpolation::derivative,
              ObjectIDObjPtr
          ,_1
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlInterpolationDerivativeBind,
                      QuantLib::Real,
                      QuantLib::Real>
          (bindObject,
            mXValues,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolationDerivativeWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::InterpolationDerivative) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XValues is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XValuesCpp;

  Local<Array> XValuesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XValuesArray->Length(); i++){
    XValuesCpp.push_back(Nan::To<double>(Nan::Get(XValuesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterpolationDerivativeWorker(
    callback
    ,ObjectIDCpp
    ,XValuesCpp
    ,AllowExtrapolationCpp
  ));

}

//InterpolationDerivativeWorker::~InterpolationDerivativeWorker(){
//
//}

//InterpolationDerivativeWorker::Destroy(){
//
//}

void InterpolationSecondDerivativeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XValuesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXValues);

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Interpolation)

  std::vector<QuantLib::Real> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlInterpolationSecondDerivativeBind bindObject =
      boost::bind((QuantLibAddin::qlInterpolationSecondDerivativeSignature)
              &QuantLibAddin::Interpolation::secondDerivative,
              ObjectIDObjPtr
          ,_1
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlInterpolationSecondDerivativeBind,
                      QuantLib::Real,
                      QuantLib::Real>
          (bindObject,
            mXValues,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolationSecondDerivativeWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::InterpolationSecondDerivative) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XValues is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XValuesCpp;

  Local<Array> XValuesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XValuesArray->Length(); i++){
    XValuesCpp.push_back(Nan::To<double>(Nan::Get(XValuesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterpolationSecondDerivativeWorker(
    callback
    ,ObjectIDCpp
    ,XValuesCpp
    ,AllowExtrapolationCpp
  ));

}

//InterpolationSecondDerivativeWorker::~InterpolationSecondDerivativeWorker(){
//
//}

//InterpolationSecondDerivativeWorker::Destroy(){
//
//}

void InterpolationPrimitiveWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XValuesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXValues);

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::Interpolation)

  std::vector<QuantLib::Real> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlInterpolationPrimitiveBind bindObject =
      boost::bind((QuantLibAddin::qlInterpolationPrimitiveSignature)
              &QuantLibAddin::Interpolation::primitive,
              ObjectIDObjPtr
          ,_1
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlInterpolationPrimitiveBind,
                      QuantLib::Real,
                      QuantLib::Real>
          (bindObject,
            mXValues,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolationPrimitiveWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::InterpolationPrimitive) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XValues is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XValuesCpp;

  Local<Array> XValuesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XValuesArray->Length(); i++){
    XValuesCpp.push_back(Nan::To<double>(Nan::Get(XValuesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterpolationPrimitiveWorker(
    callback
    ,ObjectIDCpp
    ,XValuesCpp
    ,AllowExtrapolationCpp
  ));

}

//InterpolationPrimitiveWorker::~InterpolationPrimitiveWorker(){
//
//}

//InterpolationPrimitiveWorker::Destroy(){
//
//}

void InterpolationIsInRangeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XValuesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXValues);

       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation, QuantLib::Interpolation)


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlInterpolationIsInRangeBind bindObject =
      boost::bind((QuantLibAddin::qlInterpolationIsInRangeSignature)
              &QuantLib::Interpolation::isInRange,
              ObjectIDLibObjPtr
          ,_1
          );

  ObjectHandler::loop
      <QuantLibAddin::qlInterpolationIsInRangeBind,
                      QuantLib::Real,
                      bool>
          (bindObject,
            mXValues,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolationIsInRangeWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterpolationIsInRange) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XValues is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XValuesCpp;

  Local<Array> XValuesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XValuesArray->Length(); i++){
    XValuesCpp.push_back(Nan::To<double>(Nan::Get(XValuesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new InterpolationIsInRangeWorker(
    callback
    ,ObjectIDCpp
    ,XValuesCpp
  ));

}

//InterpolationIsInRangeWorker::~InterpolationIsInRangeWorker(){
//
//}

//InterpolationIsInRangeWorker::Destroy(){
//
//}

void InterpolationXminWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation, QuantLib::Interpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->xMin(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolationXminWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterpolationXmin) {

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
  Nan::AsyncQueueWorker(new InterpolationXminWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterpolationXminWorker::~InterpolationXminWorker(){
//
//}

//InterpolationXminWorker::Destroy(){
//
//}

void InterpolationXmaxWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation, QuantLib::Interpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->xMax(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void InterpolationXmaxWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::InterpolationXmax) {

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
  Nan::AsyncQueueWorker(new InterpolationXmaxWorker(
    callback
    ,ObjectIDCpp
  ));

}

//InterpolationXmaxWorker::~InterpolationXmaxWorker(){
//
//}

//InterpolationXmaxWorker::Destroy(){
//
//}

void CubicInterpolationPrimitiveConstantsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CubicInterpolation)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDObjPtr->primitiveConstants(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CubicInterpolationPrimitiveConstantsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CubicInterpolationPrimitiveConstants) {

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
  Nan::AsyncQueueWorker(new CubicInterpolationPrimitiveConstantsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CubicInterpolationPrimitiveConstantsWorker::~CubicInterpolationPrimitiveConstantsWorker(){
//
//}

//CubicInterpolationPrimitiveConstantsWorker::Destroy(){
//
//}

void CubicInterpolationACoefficientsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CubicInterpolation)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDObjPtr->aCoefficients(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CubicInterpolationACoefficientsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CubicInterpolationACoefficients) {

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
  Nan::AsyncQueueWorker(new CubicInterpolationACoefficientsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CubicInterpolationACoefficientsWorker::~CubicInterpolationACoefficientsWorker(){
//
//}

//CubicInterpolationACoefficientsWorker::Destroy(){
//
//}

void CubicInterpolationBCoefficientsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CubicInterpolation)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDObjPtr->bCoefficients(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CubicInterpolationBCoefficientsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CubicInterpolationBCoefficients) {

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
  Nan::AsyncQueueWorker(new CubicInterpolationBCoefficientsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CubicInterpolationBCoefficientsWorker::~CubicInterpolationBCoefficientsWorker(){
//
//}

//CubicInterpolationBCoefficientsWorker::Destroy(){
//
//}

void CubicInterpolationCCoefficientsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CubicInterpolation)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDObjPtr->cCoefficients(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CubicInterpolationCCoefficientsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CubicInterpolationCCoefficients) {

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
  Nan::AsyncQueueWorker(new CubicInterpolationCCoefficientsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CubicInterpolationCCoefficientsWorker::~CubicInterpolationCCoefficientsWorker(){
//
//}

//CubicInterpolationCCoefficientsWorker::Destroy(){
//
//}

void CubicInterpolationMonotonicityAdjustmentsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CubicInterpolation)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->monotonicityAdjustments(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CubicInterpolationMonotonicityAdjustmentsWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CubicInterpolationMonotonicityAdjustments) {

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
  Nan::AsyncQueueWorker(new CubicInterpolationMonotonicityAdjustmentsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CubicInterpolationMonotonicityAdjustmentsWorker::~CubicInterpolationMonotonicityAdjustmentsWorker(){
//
//}

//CubicInterpolationMonotonicityAdjustmentsWorker::Destroy(){
//
//}

void AbcdInterpolationAWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::AbcdInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->a(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdInterpolationAWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdInterpolationA) {

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
  Nan::AsyncQueueWorker(new AbcdInterpolationAWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdInterpolationAWorker::~AbcdInterpolationAWorker(){
//
//}

//AbcdInterpolationAWorker::Destroy(){
//
//}

void AbcdInterpolationBWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::AbcdInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->b(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdInterpolationBWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdInterpolationB) {

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
  Nan::AsyncQueueWorker(new AbcdInterpolationBWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdInterpolationBWorker::~AbcdInterpolationBWorker(){
//
//}

//AbcdInterpolationBWorker::Destroy(){
//
//}

void AbcdInterpolationCWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::AbcdInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->c(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdInterpolationCWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdInterpolationC) {

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
  Nan::AsyncQueueWorker(new AbcdInterpolationCWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdInterpolationCWorker::~AbcdInterpolationCWorker(){
//
//}

//AbcdInterpolationCWorker::Destroy(){
//
//}

void AbcdInterpolationDWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::AbcdInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->d(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdInterpolationDWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdInterpolationD) {

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
  Nan::AsyncQueueWorker(new AbcdInterpolationDWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdInterpolationDWorker::~AbcdInterpolationDWorker(){
//
//}

//AbcdInterpolationDWorker::Destroy(){
//
//}

void AbcdInterpolationRmsErrorWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::AbcdInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->rmsError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdInterpolationRmsErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdInterpolationRmsError) {

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
  Nan::AsyncQueueWorker(new AbcdInterpolationRmsErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdInterpolationRmsErrorWorker::~AbcdInterpolationRmsErrorWorker(){
//
//}

//AbcdInterpolationRmsErrorWorker::Destroy(){
//
//}

void AbcdInterpolationMaxErrorWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::AbcdInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->maxError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdInterpolationMaxErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdInterpolationMaxError) {

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
  Nan::AsyncQueueWorker(new AbcdInterpolationMaxErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdInterpolationMaxErrorWorker::~AbcdInterpolationMaxErrorWorker(){
//
//}

//AbcdInterpolationMaxErrorWorker::Destroy(){
//
//}

void AbcdInterpolationEndCriteriaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::AbcdInterpolation)


  // invoke the member function
  QuantLib::EndCriteria::Type returnValue = ObjectIDObjPtr->endCriteria(
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

void AbcdInterpolationEndCriteriaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdInterpolationEndCriteria) {

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
  Nan::AsyncQueueWorker(new AbcdInterpolationEndCriteriaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdInterpolationEndCriteriaWorker::~AbcdInterpolationEndCriteriaWorker(){
//
//}

//AbcdInterpolationEndCriteriaWorker::Destroy(){
//
//}

void SABRInterpolationExpiryWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SABRInterpolation, QuantLib::SABRInterpolation)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->expiry(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SABRInterpolationExpiryWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolationExpiry) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationExpiryWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationExpiryWorker::~SABRInterpolationExpiryWorker(){
//
//}

//SABRInterpolationExpiryWorker::Destroy(){
//
//}

void SABRInterpolationForwardWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SABRInterpolation, QuantLib::SABRInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->forward(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SABRInterpolationForwardWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolationForward) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationForwardWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationForwardWorker::~SABRInterpolationForwardWorker(){
//
//}

//SABRInterpolationForwardWorker::Destroy(){
//
//}

void SABRInterpolationAlphaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SABRInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->alpha(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SABRInterpolationAlphaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolationAlpha) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationAlphaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationAlphaWorker::~SABRInterpolationAlphaWorker(){
//
//}

//SABRInterpolationAlphaWorker::Destroy(){
//
//}

void SABRInterpolationBetaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SABRInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->beta(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SABRInterpolationBetaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolationBeta) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationBetaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationBetaWorker::~SABRInterpolationBetaWorker(){
//
//}

//SABRInterpolationBetaWorker::Destroy(){
//
//}

void SABRInterpolationNuWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SABRInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->nu(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SABRInterpolationNuWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolationNu) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationNuWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationNuWorker::~SABRInterpolationNuWorker(){
//
//}

//SABRInterpolationNuWorker::Destroy(){
//
//}

void SABRInterpolationRhoWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SABRInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->rho(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SABRInterpolationRhoWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolationRho) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationRhoWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationRhoWorker::~SABRInterpolationRhoWorker(){
//
//}

//SABRInterpolationRhoWorker::Destroy(){
//
//}

void SABRInterpolationRmsErrorWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SABRInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->rmsError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SABRInterpolationRmsErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolationRmsError) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationRmsErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationRmsErrorWorker::~SABRInterpolationRmsErrorWorker(){
//
//}

//SABRInterpolationRmsErrorWorker::Destroy(){
//
//}

void SABRInterpolationMaxErrorWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SABRInterpolation)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDObjPtr->maxError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SABRInterpolationMaxErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolationMaxError) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationMaxErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationMaxErrorWorker::~SABRInterpolationMaxErrorWorker(){
//
//}

//SABRInterpolationMaxErrorWorker::Destroy(){
//
//}

void SABRInterpolationEndCriteriaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SABRInterpolation)


  // invoke the member function
  QuantLib::EndCriteria::Type returnValue = ObjectIDObjPtr->endCriteria(
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

void SABRInterpolationEndCriteriaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SABRInterpolationEndCriteria) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationEndCriteriaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationEndCriteriaWorker::~SABRInterpolationEndCriteriaWorker(){
//
//}

//SABRInterpolationEndCriteriaWorker::Destroy(){
//
//}

void SABRInterpolationWeightsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SABRInterpolation)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDObjPtr->interpolationWeights(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SABRInterpolationWeightsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SABRInterpolationWeights) {

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
  Nan::AsyncQueueWorker(new SABRInterpolationWeightsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SABRInterpolationWeightsWorker::~SABRInterpolationWeightsWorker(){
//
//}

//SABRInterpolationWeightsWorker::Destroy(){
//
//}

void Interpolation2DXminWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation2D, QuantLib::Interpolation2D)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->xMin(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void Interpolation2DXminWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Interpolation2DXmin) {

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
  Nan::AsyncQueueWorker(new Interpolation2DXminWorker(
    callback
    ,ObjectIDCpp
  ));

}

//Interpolation2DXminWorker::~Interpolation2DXminWorker(){
//
//}

//Interpolation2DXminWorker::Destroy(){
//
//}

void Interpolation2DXmaxWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation2D, QuantLib::Interpolation2D)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->xMax(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void Interpolation2DXmaxWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Interpolation2DXmax) {

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
  Nan::AsyncQueueWorker(new Interpolation2DXmaxWorker(
    callback
    ,ObjectIDCpp
  ));

}

//Interpolation2DXmaxWorker::~Interpolation2DXmaxWorker(){
//
//}

//Interpolation2DXmaxWorker::Destroy(){
//
//}

void Interpolation2DXvaluesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation2D, QuantLib::Interpolation2D)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->xValues(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void Interpolation2DXvaluesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::Interpolation2DXvalues) {

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
  Nan::AsyncQueueWorker(new Interpolation2DXvaluesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//Interpolation2DXvaluesWorker::~Interpolation2DXvaluesWorker(){
//
//}

//Interpolation2DXvaluesWorker::Destroy(){
//
//}

void Interpolation2DYminWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation2D, QuantLib::Interpolation2D)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->yMin(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void Interpolation2DYminWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Interpolation2DYmin) {

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
  Nan::AsyncQueueWorker(new Interpolation2DYminWorker(
    callback
    ,ObjectIDCpp
  ));

}

//Interpolation2DYminWorker::~Interpolation2DYminWorker(){
//
//}

//Interpolation2DYminWorker::Destroy(){
//
//}

void Interpolation2DYmaxWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation2D, QuantLib::Interpolation2D)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->yMax(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void Interpolation2DYmaxWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Interpolation2DYmax) {

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
  Nan::AsyncQueueWorker(new Interpolation2DYmaxWorker(
    callback
    ,ObjectIDCpp
  ));

}

//Interpolation2DYmaxWorker::~Interpolation2DYmaxWorker(){
//
//}

//Interpolation2DYmaxWorker::Destroy(){
//
//}

void Interpolation2DYvaluesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation2D, QuantLib::Interpolation2D)


  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->yValues(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void Interpolation2DYvaluesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::Interpolation2DYvalues) {

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
  Nan::AsyncQueueWorker(new Interpolation2DYvaluesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//Interpolation2DYvaluesWorker::~Interpolation2DYvaluesWorker(){
//
//}

//Interpolation2DYvaluesWorker::Destroy(){
//
//}

void Interpolation2DzDataWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation2D, QuantLib::Interpolation2D)

  QuantLib::Matrix returnValue;


  // invoke the member function
  returnValue = ObjectIDLibObjPtr->zData(
      );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void Interpolation2DzDataWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpMatrix = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Local<Array> tmpArray = Nan::New<Array>(mReturnValue[i].size());
      for (unsigned int j = 0; j < mReturnValue[i].size(); j++) {
        Nan::Set(tmpArray,j,Nan::New<Number>(mReturnValue[i][j]));
      }
      Nan::Set(tmpMatrix,i,tmpArray);
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpMatrix
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Interpolation2DzData) {

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
  Nan::AsyncQueueWorker(new Interpolation2DzDataWorker(
    callback
    ,ObjectIDCpp
  ));

}

//Interpolation2DzDataWorker::~Interpolation2DzDataWorker(){
//
//}

//Interpolation2DzDataWorker::Destroy(){
//
//}

void Interpolation2DIsInRangeWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XValuesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXValues);


  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation2D, QuantLib::Interpolation2D)


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlInterpolation2DIsInRangeBind bindObject =
      boost::bind((QuantLibAddin::qlInterpolation2DIsInRangeSignature)
              &QuantLib::Interpolation2D::isInRange,
              ObjectIDLibObjPtr
          ,_1
          ,mYValue
          );

  ObjectHandler::loop
      <QuantLibAddin::qlInterpolation2DIsInRangeBind,
                      QuantLib::Real,
                      bool>
          (bindObject,
            mXValues,
          mReturnValue
          );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void Interpolation2DIsInRangeWorker::HandleOKCallback(){
  Nan::HandleScope scope;

    Local<Array> tmpArray = Nan::New<Array>(mReturnValue.size());
    for (unsigned int i = 0; i < mReturnValue.size(); i++) {
      Nan::Set(tmpArray,i,Nan::New<Boolean>(mReturnValue[i]));
    }

  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      tmpArray
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Interpolation2DIsInRange) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XValues is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("YValue is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XValuesCpp;

  Local<Array> XValuesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XValuesArray->Length(); i++){
    XValuesCpp.push_back(Nan::To<double>(Nan::Get(XValuesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double YValueCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new Interpolation2DIsInRangeWorker(
    callback
    ,ObjectIDCpp
    ,XValuesCpp
    ,YValueCpp
  ));

}

//Interpolation2DIsInRangeWorker::~Interpolation2DIsInRangeWorker(){
//
//}

//Interpolation2DIsInRangeWorker::Destroy(){
//
//}

void Interpolation2DInterpolateWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> XValueLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mXValue);


  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Interpolation2D, QuantLib::Interpolation2D)

  std::vector<QuantLib::Real> returnValue;


  // loop on the input parameter and populate the return vector
  QuantLibAddin::qlInterpolation2DInterpolateBind bindObject =
      boost::bind((QuantLibAddin::qlInterpolation2DInterpolateSignature)
              &QuantLib::Interpolation2D::operator(),
              ObjectIDLibObjPtr
          ,_1
          ,mYValue
          ,mAllowExtrapolation
          );

  ObjectHandler::loop
      <QuantLibAddin::qlInterpolation2DInterpolateBind,
                      QuantLib::Real,
                      QuantLib::Real>
          (bindObject,
            mXValue,
          returnValue
          );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void Interpolation2DInterpolateWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::Interpolation2DInterpolate) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("XValue is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("YValue is required.");
  }
  if (info.Length() == 3 || !info[3]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>XValueCpp;

  Local<Array> XValueArray = info[1].As<Array>();
  for (unsigned int i = 0; i < XValueArray->Length(); i++){
    XValueCpp.push_back(Nan::To<double>(Nan::Get(XValueArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double YValueCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new Interpolation2DInterpolateWorker(
    callback
    ,ObjectIDCpp
    ,XValueCpp
    ,YValueCpp
    ,AllowExtrapolationCpp
  ));

}

//Interpolation2DInterpolateWorker::~Interpolation2DInterpolateWorker(){
//
//}

//Interpolation2DInterpolateWorker::Destroy(){
//
//}
 