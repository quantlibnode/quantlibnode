/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "basketlossmodels.hpp"

#include <qlo/qladdindefines.hpp>
#include <ql/experimental/credit/gaussianlhplossmodel.hpp>
#include <ql/experimental/credit/binomiallossmodel.hpp>
#include <ql/experimental/credit/inhomogeneouspooldef.hpp>
#include <ql/experimental/credit/correlationstructure.hpp>
#include <qlo/basketlossmodels.hpp>
#include <qlo/defaulttermstructures.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void GaussianLHPLossmodelWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlGaussianLHPLossmodel(
          mObjectID,
          mCorrelation,
          mRecoveyRates,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::GaussianLHPLossModel(
          valueObject,
          mCorrelation,
          mRecoveyRates,
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

void GaussianLHPLossmodelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianLHPLossmodel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Correlation is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double CorrelationCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianLHPLossmodelWorker(
    callback
    ,ObjectIDCpp
    ,CorrelationCpp
    ,RecoveyRatesCpp
  ));

}

//GaussianLHPLossmodelWorker::~GaussianLHPLossmodelWorker(){
//
//}

//void GaussianLHPLossmodelWorker::Destroy(){
//
//}

void IHGaussPoolLossModelWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumBucketsLib;
  QuantLibAddin::cppToLibrary(mNumBuckets, NumBucketsLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlIHGaussPoolLossModel(
          mObjectID,
          mCorrelation,
          mRecoveyRates,
          mNumBuckets,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::IHGaussPoolLossModel(
          valueObject,
          mCorrelation,
          mRecoveyRates,
          NumBucketsLib,
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

void IHGaussPoolLossModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IHGaussPoolLossModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Correlation is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("NumBuckets is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double CorrelationCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long NumBucketsCpp = Nan::To<int32_t>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IHGaussPoolLossModelWorker(
    callback
    ,ObjectIDCpp
    ,CorrelationCpp
    ,RecoveyRatesCpp
    ,NumBucketsCpp
  ));

}

//IHGaussPoolLossModelWorker::~IHGaussPoolLossModelWorker(){
//
//}

//void IHGaussPoolLossModelWorker::Destroy(){
//
//}

void IHStudentPoolLossModelWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumBucketsLib;
  QuantLibAddin::cppToLibrary(mNumBuckets, NumBucketsLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlIHStudentPoolLossModel(
          mObjectID,
          mCorrelation,
          mRecoveyRates,
          mTtraits,
          mNumBuckets,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::IHStudentPoolLossModel(
          valueObject,
          mCorrelation,
          mRecoveyRates,
          mTtraits,
          NumBucketsLib,
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

void IHStudentPoolLossModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IHStudentPoolLossModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Correlation is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Ttraits is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("NumBuckets is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double CorrelationCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TtraitsCpp;

  Local<Array> TtraitsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TtraitsArray->Length(); i++){
    TtraitsCpp.push_back(Nan::To<double>(Nan::Get(TtraitsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long NumBucketsCpp = Nan::To<int32_t>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IHStudentPoolLossModelWorker(
    callback
    ,ObjectIDCpp
    ,CorrelationCpp
    ,RecoveyRatesCpp
    ,TtraitsCpp
    ,NumBucketsCpp
  ));

}

//IHStudentPoolLossModelWorker::~IHStudentPoolLossModelWorker(){
//
//}

//void IHStudentPoolLossModelWorker::Destroy(){
//
//}

void GBinomialLossmodelWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlGBinomialLossmodel(
          mObjectID,
          mFactors,
          mRecoveyRates,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::GaussianBinomialLossModel(
          valueObject,
          mFactors,
          mRecoveyRates,
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

void GBinomialLossmodelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GBinomialLossmodel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FactorsCpp;

  Local<Array> FactorsMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FactorsMatrix->Length(); i++){
	  Local<Array> FactorsArray = FactorsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FactorsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FactorsArray, j).ToLocalChecked()).FromJust());
	  }
	  FactorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GBinomialLossmodelWorker(
    callback
    ,ObjectIDCpp
    ,FactorsCpp
    ,RecoveyRatesCpp
  ));

}

//GBinomialLossmodelWorker::~GBinomialLossmodelWorker(){
//
//}

//void GBinomialLossmodelWorker::Destroy(){
//
//}

void TBinomialLossmodelWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlTBinomialLossmodel(
          mObjectID,
          mFactors,
          mRecoveyRates,
          mTtraits,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::TBinomialLossModel(
          valueObject,
          mFactors,
          mRecoveyRates,
          mTtraits,
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

void TBinomialLossmodelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TBinomialLossmodel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Ttraits is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FactorsCpp;

  Local<Array> FactorsMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FactorsMatrix->Length(); i++){
	  Local<Array> FactorsArray = FactorsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FactorsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FactorsArray, j).ToLocalChecked()).FromJust());
	  }
	  FactorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TtraitsCpp;

  Local<Array> TtraitsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TtraitsArray->Length(); i++){
    TtraitsCpp.push_back(Nan::To<double>(Nan::Get(TtraitsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TBinomialLossmodelWorker(
    callback
    ,ObjectIDCpp
    ,FactorsCpp
    ,RecoveyRatesCpp
    ,TtraitsCpp
  ));

}

//TBinomialLossmodelWorker::~TBinomialLossmodelWorker(){
//
//}

//void TBinomialLossmodelWorker::Destroy(){
//
//}

void BaseCorrelationLossModelWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(BaseCorrelationSurfaceLibObjPtr, mBaseCorrelationSurface,
      QuantLibAddin::CorrelationTermStructure, QuantLib::CorrelationTermStructure)


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> RecoveriesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mRecoveries);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> InitiTraitsLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mInitiTraits);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBaseCorrelationLossModel(
          mObjectID,
          mBaseModel,
          mBaseCorrelationSurface,
          mRecoveries,
          mInitiTraits,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BaseCorrelationLossModel(
          valueObject,
          mBaseModel,
          BaseCorrelationSurfaceLibObjPtr,
          mRecoveries,
          mInitiTraits,
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

void BaseCorrelationLossModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BaseCorrelationLossModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("BaseModel is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("BaseCorrelationSurface is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Recoveries is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("InitiTraits is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strBaseModel(info[1]->ToString());
  string BaseModelCpp(strdup(*strBaseModel));

  // convert js argument to c++ type
  String::Utf8Value strBaseCorrelationSurface(info[2]->ToString());
  string BaseCorrelationSurfaceCpp(strdup(*strBaseCorrelationSurface));

  // convert js argument to c++ type
  std::vector<double>RecoveriesCpp;

  Local<Array> RecoveriesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < RecoveriesArray->Length(); i++){
    RecoveriesCpp.push_back(Nan::To<double>(Nan::Get(RecoveriesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>InitiTraitsCpp;

  Local<Array> InitiTraitsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < InitiTraitsArray->Length(); i++){
    InitiTraitsCpp.push_back(Nan::To<double>(Nan::Get(InitiTraitsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BaseCorrelationLossModelWorker(
    callback
    ,ObjectIDCpp
    ,BaseModelCpp
    ,BaseCorrelationSurfaceCpp
    ,RecoveriesCpp
    ,InitiTraitsCpp
  ));

}

//BaseCorrelationLossModelWorker::~BaseCorrelationLossModelWorker(){
//
//}

//void BaseCorrelationLossModelWorker::Destroy(){
//
//}

void GMCLossModelWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumSimulationsLib;
  QuantLibAddin::cppToLibrary(mNumSimulations, NumSimulationsLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlGMCLossModel(
          mObjectID,
          mFactors,
          mRecoveyRates,
          mNumSimulations,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::GaussianRandomDefaultLM(
          valueObject,
          mFactors,
          mRecoveyRates,
          NumSimulationsLib,
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

void GMCLossModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GMCLossModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("NumSimulations is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FactorsCpp;

  Local<Array> FactorsMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FactorsMatrix->Length(); i++){
	  Local<Array> FactorsArray = FactorsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FactorsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FactorsArray, j).ToLocalChecked()).FromJust());
	  }
	  FactorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long NumSimulationsCpp = Nan::To<int32_t>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GMCLossModelWorker(
    callback
    ,ObjectIDCpp
    ,FactorsCpp
    ,RecoveyRatesCpp
    ,NumSimulationsCpp
  ));

}

//GMCLossModelWorker::~GMCLossModelWorker(){
//
//}

//void GMCLossModelWorker::Destroy(){
//
//}

void GRandomRRMCLossModelWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumSimulationsLib;
  QuantLibAddin::cppToLibrary(mNumSimulations, NumSimulationsLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlGRandomRRMCLossModel(
          mObjectID,
          mFactors,
          mRecoveyRates,
          mModelA,
          mNumSimulations,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::GaussianRandomLossLM(
          valueObject,
          mFactors,
          mRecoveyRates,
          mModelA,
          NumSimulationsLib,
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

void GRandomRRMCLossModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GRandomRRMCLossModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("ModelA is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("NumSimulations is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FactorsCpp;

  Local<Array> FactorsMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FactorsMatrix->Length(); i++){
	  Local<Array> FactorsArray = FactorsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FactorsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FactorsArray, j).ToLocalChecked()).FromJust());
	  }
	  FactorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double ModelACpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  long NumSimulationsCpp = Nan::To<int32_t>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GRandomRRMCLossModelWorker(
    callback
    ,ObjectIDCpp
    ,FactorsCpp
    ,RecoveyRatesCpp
    ,ModelACpp
    ,NumSimulationsCpp
  ));

}

//GRandomRRMCLossModelWorker::~GRandomRRMCLossModelWorker(){
//
//}

//void GRandomRRMCLossModelWorker::Destroy(){
//
//}

void TMCLossModelWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumSimulationsLib;
  QuantLibAddin::cppToLibrary(mNumSimulations, NumSimulationsLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlTMCLossModel(
          mObjectID,
          mFactors,
          mRecoveyRates,
          mTtraits,
          mNumSimulations,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::TRandomDefaultLM(
          valueObject,
          mFactors,
          mRecoveyRates,
          mTtraits,
          NumSimulationsLib,
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

void TMCLossModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TMCLossModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Ttraits is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("NumSimulations is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FactorsCpp;

  Local<Array> FactorsMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FactorsMatrix->Length(); i++){
	  Local<Array> FactorsArray = FactorsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FactorsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FactorsArray, j).ToLocalChecked()).FromJust());
	  }
	  FactorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TtraitsCpp;

  Local<Array> TtraitsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TtraitsArray->Length(); i++){
    TtraitsCpp.push_back(Nan::To<double>(Nan::Get(TtraitsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long NumSimulationsCpp = Nan::To<int32_t>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TMCLossModelWorker(
    callback
    ,ObjectIDCpp
    ,FactorsCpp
    ,RecoveyRatesCpp
    ,TtraitsCpp
    ,NumSimulationsCpp
  ));

}

//TMCLossModelWorker::~TMCLossModelWorker(){
//
//}

//void TMCLossModelWorker::Destroy(){
//
//}

void TRandomRRMCLossModelWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumSimulationsLib;
  QuantLibAddin::cppToLibrary(mNumSimulations, NumSimulationsLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlTRandomRRMCLossModel(
          mObjectID,
          mFactors,
          mRecoveyRates,
          mTtraits,
          mModelA,
          mNumSimulations,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::TRandomLossLM(
          valueObject,
          mFactors,
          mRecoveyRates,
          mTtraits,
          mModelA,
          NumSimulationsLib,
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

void TRandomRRMCLossModelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TRandomRRMCLossModel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Ttraits is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("ModelA is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("NumSimulations is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FactorsCpp;

  Local<Array> FactorsMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FactorsMatrix->Length(); i++){
	  Local<Array> FactorsArray = FactorsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FactorsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FactorsArray, j).ToLocalChecked()).FromJust());
	  }
	  FactorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TtraitsCpp;

  Local<Array> TtraitsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TtraitsArray->Length(); i++){
    TtraitsCpp.push_back(Nan::To<double>(Nan::Get(TtraitsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  double ModelACpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  long NumSimulationsCpp = Nan::To<int32_t>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TRandomRRMCLossModelWorker(
    callback
    ,ObjectIDCpp
    ,FactorsCpp
    ,RecoveyRatesCpp
    ,TtraitsCpp
    ,ModelACpp
    ,NumSimulationsCpp
  ));

}

//TRandomRRMCLossModelWorker::~TRandomRRMCLossModelWorker(){
//
//}

//void TRandomRRMCLossModelWorker::Destroy(){
//
//}

void GSaddlePointLossmodelWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlGSaddlePointLossmodel(
          mObjectID,
          mFactors,
          mRecoveyRates,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SaddlePointLossModel(
          valueObject,
          mFactors,
          mRecoveyRates,
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

void GSaddlePointLossmodelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GSaddlePointLossmodel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FactorsCpp;

  Local<Array> FactorsMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FactorsMatrix->Length(); i++){
	  Local<Array> FactorsArray = FactorsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FactorsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FactorsArray, j).ToLocalChecked()).FromJust());
	  }
	  FactorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GSaddlePointLossmodelWorker(
    callback
    ,ObjectIDCpp
    ,FactorsCpp
    ,RecoveyRatesCpp
  ));

}

//GSaddlePointLossmodelWorker::~GSaddlePointLossmodelWorker(){
//
//}

//void GSaddlePointLossmodelWorker::Destroy(){
//
//}

void TSaddlePointLossmodelWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlTSaddlePointLossmodel(
          mObjectID,
          mFactors,
          mRecoveyRates,
          mTtraits,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::TSaddlePointLossModel(
          valueObject,
          mFactors,
          mRecoveyRates,
          mTtraits,
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

void TSaddlePointLossmodelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::TSaddlePointLossmodel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Ttraits is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FactorsCpp;

  Local<Array> FactorsMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FactorsMatrix->Length(); i++){
	  Local<Array> FactorsArray = FactorsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FactorsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FactorsArray, j).ToLocalChecked()).FromJust());
	  }
	  FactorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TtraitsCpp;

  Local<Array> TtraitsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TtraitsArray->Length(); i++){
    TtraitsCpp.push_back(Nan::To<double>(Nan::Get(TtraitsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TSaddlePointLossmodelWorker(
    callback
    ,ObjectIDCpp
    ,FactorsCpp
    ,RecoveyRatesCpp
    ,TtraitsCpp
  ));

}

//TSaddlePointLossmodelWorker::~TSaddlePointLossmodelWorker(){
//
//}

//void TSaddlePointLossmodelWorker::Destroy(){
//
//}

void GRecursiveLossmodelWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlGRecursiveLossmodel(
          mObjectID,
          mFactors,
          mRecoveyRates,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::RecursiveGaussLossModel(
          valueObject,
          mFactors,
          mRecoveyRates,
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

void GRecursiveLossmodelWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GRecursiveLossmodel) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Factors is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("RecoveyRates is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >FactorsCpp;

  Local<Array> FactorsMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < FactorsMatrix->Length(); i++){
	  Local<Array> FactorsArray = FactorsMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < FactorsArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(FactorsArray, j).ToLocalChecked()).FromJust());
	  }
	  FactorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>RecoveyRatesCpp;

  Local<Array> RecoveyRatesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < RecoveyRatesArray->Length(); i++){
    RecoveyRatesCpp.push_back(Nan::To<double>(Nan::Get(RecoveyRatesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GRecursiveLossmodelWorker(
    callback
    ,ObjectIDCpp
    ,FactorsCpp
    ,RecoveyRatesCpp
  ));

}

//GRecursiveLossmodelWorker::~GRecursiveLossmodelWorker(){
//
//}

//void GRecursiveLossmodelWorker::Destroy(){
//
//}
 