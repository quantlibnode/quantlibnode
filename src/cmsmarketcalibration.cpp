/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "cmsmarketcalibration.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/cmsmarketcalibration.hpp>
#include <qlo/cmsmarket.hpp>
#include <qlo/termstructures.hpp>
#include <qlo/optimization.hpp>
#include <ql/termstructures/volatility/swaption/swaptionvolcube1.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void CmsMarketCalibrationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_OBJECT(VolCubeCoerce, mVolCube, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::SwaptionVolatilityStructure> VolCubeLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::SwaptionVolatilityStructure,
          QuantLib::SwaptionVolatilityStructure>()(
              VolCubeCoerce);


  // convert object IDs into library objects
  OH_GET_REFERENCE(CmsMarketLibObjPtr, mCmsMarket,
      QuantLibAddin::CmsMarket, QuantLib::CmsMarket)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix WeightsLib = QuantLibAddin::vvToQlMatrix(mWeights);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::CmsMarketCalibration::CalibrationType CalibrationTypeEnum =
      ObjectHandler::Create<QuantLib::CmsMarketCalibration::CalibrationType>()(mCalibrationType);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCmsMarketCalibration(
          mObjectID,
          mVolCube,
          mCmsMarket,
          mWeights,
          mCalibrationType,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CmsMarketCalibration(
          valueObject,
          VolCubeLibObj,
          CmsMarketLibObjPtr,
          WeightsLib,
          CalibrationTypeEnum,
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

void CmsMarketCalibrationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CmsMarketCalibration) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("CmsMarket is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Weights is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("CalibrationType is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t VolCubeCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strCmsMarket(info[2]->ToString());
  string CmsMarketCpp(strdup(*strCmsMarket));

  // convert js argument to c++ type
  std::vector< std::vector<double> >WeightsCpp;

  Local<Array> WeightsMatrix = info[3].As<Array>();
  for (unsigned int i = 0; i < WeightsMatrix->Length(); i++){
	  Local<Array> WeightsArray = WeightsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < WeightsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(WeightsArray, j).ToLocalChecked()).FromJust());
	  }
	  WeightsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strCalibrationType(info[4]->ToString());
  string CalibrationTypeCpp(strdup(*strCalibrationType));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CmsMarketCalibrationWorker(
    callback
    ,ObjectIDCpp
    ,VolCubeCpp
    ,CmsMarketCpp
    ,WeightsCpp
    ,CalibrationTypeCpp
  ));

}

//CmsMarketCalibrationWorker::~CmsMarketCalibrationWorker(){
//
//}

//void CmsMarketCalibrationWorker::Destroy(){
//
//}

void CmsMarketCalibrationComputeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(EndCriteriaLibObjPtr, mEndCriteria,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // convert object IDs into library objects
  OH_GET_REFERENCE(OptimizationMethodLibObjPtr, mOptimizationMethod,
      QuantLibAddin::OptimizationMethod, QuantLib::OptimizationMethod)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Array GuessLib;

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CmsMarketCalibration)


  // loop on the input parameter and populate the return vector
  QuantLib::Array returnValue = ObjectIDObjPtr->compute(
        EndCriteriaLibObjPtr
        ,
         OptimizationMethodLibObjPtr
        ,
         GuessLib
        ,
         mIsMeanRevFixed
       );


  for(unsigned int i = 0; i < returnValue.size(); i++){
    mReturnValue.push_back(returnValue[i]);
  }

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CmsMarketCalibrationComputeWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CmsMarketCalibrationCompute) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("EndCriteria is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("OptimizationMethod is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Guess is required.");
  }
  if (info.Length() == 4 || !info[4]->IsBoolean()) {
      return Nan::ThrowError("IsMeanRevFixed is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strEndCriteria(info[1]->ToString());
  string EndCriteriaCpp(strdup(*strEndCriteria));

  // convert js argument to c++ type
  String::Utf8Value strOptimizationMethod(info[2]->ToString());
  string OptimizationMethodCpp(strdup(*strOptimizationMethod));

  // convert js argument to c++ type
  std::vector<double>GuessCpp;

  Local<Array> GuessArray = info[3].As<Array>();
  for (unsigned int i = 0; i < GuessArray->Length(); i++){
    GuessCpp.push_back(Nan::To<double>(Nan::Get(GuessArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  bool IsMeanRevFixedCpp = Nan::To<bool>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CmsMarketCalibrationComputeWorker(
    callback
    ,ObjectIDCpp
    ,EndCriteriaCpp
    ,OptimizationMethodCpp
    ,GuessCpp
    ,IsMeanRevFixedCpp
  ));

}

//CmsMarketCalibrationComputeWorker::~CmsMarketCalibrationComputeWorker(){
//
//}

//void CmsMarketCalibrationComputeWorker::Destroy(){
//
//}

void CmsMarketCalibrationErrorWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CmsMarketCalibration, QuantLib::CmsMarketCalibration)


  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->error(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CmsMarketCalibrationErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CmsMarketCalibrationError) {

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
  Nan::AsyncQueueWorker(new CmsMarketCalibrationErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CmsMarketCalibrationErrorWorker::~CmsMarketCalibrationErrorWorker(){
//
//}

//void CmsMarketCalibrationErrorWorker::Destroy(){
//
//}

void CmsMarketCalibrationEndCriteriaWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CmsMarketCalibration, QuantLib::CmsMarketCalibration)


  // invoke the member function
  QuantLib::EndCriteria::Type returnValue = ObjectIDLibObjPtr->endCriteria(
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

void CmsMarketCalibrationEndCriteriaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CmsMarketCalibrationEndCriteria) {

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
  Nan::AsyncQueueWorker(new CmsMarketCalibrationEndCriteriaWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CmsMarketCalibrationEndCriteriaWorker::~CmsMarketCalibrationEndCriteriaWorker(){
//
//}

//void CmsMarketCalibrationEndCriteriaWorker::Destroy(){
//
//}

void CmsMarketCalibrationElapsedWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CmsMarketCalibration)


  // invoke the member function
  mReturnValue = ObjectIDObjPtr->elapsed(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CmsMarketCalibrationElapsedWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CmsMarketCalibrationElapsed) {

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
  Nan::AsyncQueueWorker(new CmsMarketCalibrationElapsedWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CmsMarketCalibrationElapsedWorker::~CmsMarketCalibrationElapsedWorker(){
//
//}

//void CmsMarketCalibrationElapsedWorker::Destroy(){
//
//}

void CmsMarketCalibrationSparseSabrParametersWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CmsMarketCalibration)

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

void CmsMarketCalibrationSparseSabrParametersWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CmsMarketCalibrationSparseSabrParameters) {

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
  Nan::AsyncQueueWorker(new CmsMarketCalibrationSparseSabrParametersWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CmsMarketCalibrationSparseSabrParametersWorker::~CmsMarketCalibrationSparseSabrParametersWorker(){
//
//}

//void CmsMarketCalibrationSparseSabrParametersWorker::Destroy(){
//
//}

void CmsMarketCalibrationDenseSabrParametersWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CmsMarketCalibration)

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

void CmsMarketCalibrationDenseSabrParametersWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CmsMarketCalibrationDenseSabrParameters) {

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
  Nan::AsyncQueueWorker(new CmsMarketCalibrationDenseSabrParametersWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CmsMarketCalibrationDenseSabrParametersWorker::~CmsMarketCalibrationDenseSabrParametersWorker(){
//
//}

//void CmsMarketCalibrationDenseSabrParametersWorker::Destroy(){
//
//}

void SimultaneousCalibrationBrowseCmsMarketWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CmsMarketCalibration)

  std::vector< std::vector<ObjectHandler::property_t> > returnValue;


  // invoke the member function
  returnValue = ObjectIDObjPtr->getCmsMarket(
      );


  mReturnValue = ObjectHandler::matrix::convert2<string>(returnValue,"returnValue");

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SimultaneousCalibrationBrowseCmsMarketWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SimultaneousCalibrationBrowseCmsMarket) {

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
  Nan::AsyncQueueWorker(new SimultaneousCalibrationBrowseCmsMarketWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SimultaneousCalibrationBrowseCmsMarketWorker::~SimultaneousCalibrationBrowseCmsMarketWorker(){
//
//}

//void SimultaneousCalibrationBrowseCmsMarketWorker::Destroy(){
//
//}
 