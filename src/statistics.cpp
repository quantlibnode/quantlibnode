/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "statistics.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/statistics.hpp>
#include <ql/math/statistics/statistics.hpp>
#include <ql/math/statistics/incrementalstatistics.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void StatisticsWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> ValuesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mValues);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> WeightsLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mWeights);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlStatistics(
          mObjectID,
          mValues,
          mWeights,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Statistics(
          valueObject,
          mValues,
          mWeights,
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

void StatisticsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Statistics) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Values is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Weights is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>ValuesCpp;

  Local<Array> ValuesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < ValuesArray->Length(); i++){
    ValuesCpp.push_back(Nan::To<double>(Nan::Get(ValuesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>WeightsCpp;

  Local<Array> WeightsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < WeightsArray->Length(); i++){
    WeightsCpp.push_back(Nan::To<double>(Nan::Get(WeightsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsWorker(
    callback
    ,ObjectIDCpp
    ,ValuesCpp
    ,WeightsCpp
  ));

}

//StatisticsWorker::~StatisticsWorker(){
//
//}

//void StatisticsWorker::Destroy(){
//
//}

void IncrementalStatisticsWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> ValuesLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mValues);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Real> WeightsLib =
      QuantLibAddin::convertVector<double, QuantLib::Real>(mWeights);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlIncrementalStatistics(
          mObjectID,
          mValues,
          mWeights,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::IncrementalStatistics(
          valueObject,
          mValues,
          mWeights,
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

void IncrementalStatisticsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IncrementalStatistics) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Values is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Weights is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>ValuesCpp;

  Local<Array> ValuesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < ValuesArray->Length(); i++){
    ValuesCpp.push_back(Nan::To<double>(Nan::Get(ValuesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>WeightsCpp;

  Local<Array> WeightsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < WeightsArray->Length(); i++){
    WeightsCpp.push_back(Nan::To<double>(Nan::Get(WeightsArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IncrementalStatisticsWorker(
    callback
    ,ObjectIDCpp
    ,ValuesCpp
    ,WeightsCpp
  ));

}

//IncrementalStatisticsWorker::~IncrementalStatisticsWorker(){
//
//}

//void IncrementalStatisticsWorker::Destroy(){
//
//}

void StatisticsSamplesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Size returnValue = ObjectIDLibObjPtr->samples(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsSamplesWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsSamples) {

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
  Nan::AsyncQueueWorker(new StatisticsSamplesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsSamplesWorker::~StatisticsSamplesWorker(){
//
//}

//void StatisticsSamplesWorker::Destroy(){
//
//}

void StatisticsWeightSumWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->weightSum(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsWeightSumWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsWeightSum) {

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
  Nan::AsyncQueueWorker(new StatisticsWeightSumWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsWeightSumWorker::~StatisticsWeightSumWorker(){
//
//}

//void StatisticsWeightSumWorker::Destroy(){
//
//}

void StatisticsMeanWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->mean(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsMeanWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsMean) {

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
  Nan::AsyncQueueWorker(new StatisticsMeanWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsMeanWorker::~StatisticsMeanWorker(){
//
//}

//void StatisticsMeanWorker::Destroy(){
//
//}

void StatisticsVarianceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->variance(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsVariance) {

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
  Nan::AsyncQueueWorker(new StatisticsVarianceWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsVarianceWorker::~StatisticsVarianceWorker(){
//
//}

//void StatisticsVarianceWorker::Destroy(){
//
//}

void StatisticsStandardDeviationWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->standardDeviation(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsStandardDeviationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsStandardDeviation) {

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
  Nan::AsyncQueueWorker(new StatisticsStandardDeviationWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsStandardDeviationWorker::~StatisticsStandardDeviationWorker(){
//
//}

//void StatisticsStandardDeviationWorker::Destroy(){
//
//}

void StatisticsErrorEstimateWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->errorEstimate(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsErrorEstimateWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsErrorEstimate) {

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
  Nan::AsyncQueueWorker(new StatisticsErrorEstimateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsErrorEstimateWorker::~StatisticsErrorEstimateWorker(){
//
//}

//void StatisticsErrorEstimateWorker::Destroy(){
//
//}

void StatisticsSkewnessWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->skewness(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsSkewnessWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsSkewness) {

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
  Nan::AsyncQueueWorker(new StatisticsSkewnessWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsSkewnessWorker::~StatisticsSkewnessWorker(){
//
//}

//void StatisticsSkewnessWorker::Destroy(){
//
//}

void StatisticsKurtosisWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->kurtosis(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsKurtosisWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsKurtosis) {

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
  Nan::AsyncQueueWorker(new StatisticsKurtosisWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsKurtosisWorker::~StatisticsKurtosisWorker(){
//
//}

//void StatisticsKurtosisWorker::Destroy(){
//
//}

void StatisticsMinWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->min(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsMinWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsMin) {

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
  Nan::AsyncQueueWorker(new StatisticsMinWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsMinWorker::~StatisticsMinWorker(){
//
//}

//void StatisticsMinWorker::Destroy(){
//
//}

void StatisticsMaxWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->max(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsMaxWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsMax) {

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
  Nan::AsyncQueueWorker(new StatisticsMaxWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsMaxWorker::~StatisticsMaxWorker(){
//
//}

//void StatisticsMaxWorker::Destroy(){
//
//}

void StatisticsPercentileWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->percentile(
        mX
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsPercentileWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsPercentile) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("X is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double XCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsPercentileWorker(
    callback
    ,ObjectIDCpp
    ,XCpp
  ));

}

//StatisticsPercentileWorker::~StatisticsPercentileWorker(){
//
//}

//void StatisticsPercentileWorker::Destroy(){
//
//}

void StatisticsTopPercentileWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->topPercentile(
        mX
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsTopPercentileWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsTopPercentile) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("X is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double XCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsTopPercentileWorker(
    callback
    ,ObjectIDCpp
    ,XCpp
  ));

}

//StatisticsTopPercentileWorker::~StatisticsTopPercentileWorker(){
//
//}

//void StatisticsTopPercentileWorker::Destroy(){
//
//}

void StatisticsGaussianDownsideVarianceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianDownsideVariance(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianDownsideVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianDownsideVariance) {

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
  Nan::AsyncQueueWorker(new StatisticsGaussianDownsideVarianceWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsGaussianDownsideVarianceWorker::~StatisticsGaussianDownsideVarianceWorker(){
//
//}

//void StatisticsGaussianDownsideVarianceWorker::Destroy(){
//
//}

void StatisticsGaussianDownsideDeviationWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianDownsideDeviation(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianDownsideDeviationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianDownsideDeviation) {

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
  Nan::AsyncQueueWorker(new StatisticsGaussianDownsideDeviationWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsGaussianDownsideDeviationWorker::~StatisticsGaussianDownsideDeviationWorker(){
//
//}

//void StatisticsGaussianDownsideDeviationWorker::Destroy(){
//
//}

void StatisticsGaussianRegretWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianRegret(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianRegretWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianRegret) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsGaussianRegretWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsGaussianRegretWorker::~StatisticsGaussianRegretWorker(){
//
//}

//void StatisticsGaussianRegretWorker::Destroy(){
//
//}

void StatisticsGaussianPercentileWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianPercentile(
        mX
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianPercentileWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianPercentile) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("X is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double XCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsGaussianPercentileWorker(
    callback
    ,ObjectIDCpp
    ,XCpp
  ));

}

//StatisticsGaussianPercentileWorker::~StatisticsGaussianPercentileWorker(){
//
//}

//void StatisticsGaussianPercentileWorker::Destroy(){
//
//}

void StatisticsGaussianTopPercentileWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianTopPercentile(
        mX
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianTopPercentileWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianTopPercentile) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("X is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double XCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsGaussianTopPercentileWorker(
    callback
    ,ObjectIDCpp
    ,XCpp
  ));

}

//StatisticsGaussianTopPercentileWorker::~StatisticsGaussianTopPercentileWorker(){
//
//}

//void StatisticsGaussianTopPercentileWorker::Destroy(){
//
//}

void StatisticsGaussianPotentialUpsideWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianPotentialUpside(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianPotentialUpsideWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianPotentialUpside) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsGaussianPotentialUpsideWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsGaussianPotentialUpsideWorker::~StatisticsGaussianPotentialUpsideWorker(){
//
//}

//void StatisticsGaussianPotentialUpsideWorker::Destroy(){
//
//}

void StatisticsGaussianValueAtRiskWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianValueAtRisk(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianValueAtRiskWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianValueAtRisk) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsGaussianValueAtRiskWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsGaussianValueAtRiskWorker::~StatisticsGaussianValueAtRiskWorker(){
//
//}

//void StatisticsGaussianValueAtRiskWorker::Destroy(){
//
//}

void StatisticsGaussianExpectedShortfallWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianExpectedShortfall(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianExpectedShortfallWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianExpectedShortfall) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsGaussianExpectedShortfallWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsGaussianExpectedShortfallWorker::~StatisticsGaussianExpectedShortfallWorker(){
//
//}

//void StatisticsGaussianExpectedShortfallWorker::Destroy(){
//
//}

void StatisticsGaussianShortfallWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianShortfall(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianShortfallWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianShortfall) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsGaussianShortfallWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsGaussianShortfallWorker::~StatisticsGaussianShortfallWorker(){
//
//}

//void StatisticsGaussianShortfallWorker::Destroy(){
//
//}

void StatisticsGaussianAverageShortfallWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gaussianAverageShortfall(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsGaussianAverageShortfallWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsGaussianAverageShortfall) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsGaussianAverageShortfallWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsGaussianAverageShortfallWorker::~StatisticsGaussianAverageShortfallWorker(){
//
//}

//void StatisticsGaussianAverageShortfallWorker::Destroy(){
//
//}

void StatisticsSemiVarianceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->semiVariance(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsSemiVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsSemiVariance) {

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
  Nan::AsyncQueueWorker(new StatisticsSemiVarianceWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsSemiVarianceWorker::~StatisticsSemiVarianceWorker(){
//
//}

//void StatisticsSemiVarianceWorker::Destroy(){
//
//}

void StatisticsSemiDeviationWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->semiDeviation(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsSemiDeviationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsSemiDeviation) {

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
  Nan::AsyncQueueWorker(new StatisticsSemiDeviationWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsSemiDeviationWorker::~StatisticsSemiDeviationWorker(){
//
//}

//void StatisticsSemiDeviationWorker::Destroy(){
//
//}

void StatisticsDownsideVarianceWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->downsideVariance(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsDownsideVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsDownsideVariance) {

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
  Nan::AsyncQueueWorker(new StatisticsDownsideVarianceWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsDownsideVarianceWorker::~StatisticsDownsideVarianceWorker(){
//
//}

//void StatisticsDownsideVarianceWorker::Destroy(){
//
//}

void StatisticsDownsideDeviationWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->downsideDeviation(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsDownsideDeviationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsDownsideDeviation) {

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
  Nan::AsyncQueueWorker(new StatisticsDownsideDeviationWorker(
    callback
    ,ObjectIDCpp
  ));

}

//StatisticsDownsideDeviationWorker::~StatisticsDownsideDeviationWorker(){
//
//}

//void StatisticsDownsideDeviationWorker::Destroy(){
//
//}

void StatisticsRegretWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->regret(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsRegretWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsRegret) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsRegretWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsRegretWorker::~StatisticsRegretWorker(){
//
//}

//void StatisticsRegretWorker::Destroy(){
//
//}

void StatisticsPotentialUpsideWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->potentialUpside(
        mCentile
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsPotentialUpsideWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsPotentialUpside) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Centile is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double CentileCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsPotentialUpsideWorker(
    callback
    ,ObjectIDCpp
    ,CentileCpp
  ));

}

//StatisticsPotentialUpsideWorker::~StatisticsPotentialUpsideWorker(){
//
//}

//void StatisticsPotentialUpsideWorker::Destroy(){
//
//}

void StatisticsValueAtRiskWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->valueAtRisk(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsValueAtRiskWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsValueAtRisk) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsValueAtRiskWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsValueAtRiskWorker::~StatisticsValueAtRiskWorker(){
//
//}

//void StatisticsValueAtRiskWorker::Destroy(){
//
//}

void StatisticsExpectedShortfallWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->expectedShortfall(
        mCentile
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsExpectedShortfallWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsExpectedShortfall) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Centile is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double CentileCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsExpectedShortfallWorker(
    callback
    ,ObjectIDCpp
    ,CentileCpp
  ));

}

//StatisticsExpectedShortfallWorker::~StatisticsExpectedShortfallWorker(){
//
//}

//void StatisticsExpectedShortfallWorker::Destroy(){
//
//}

void StatisticsShortfallWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->shortfall(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsShortfallWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsShortfall) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsShortfallWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsShortfallWorker::~StatisticsShortfallWorker(){
//
//}

//void StatisticsShortfallWorker::Destroy(){
//
//}

void StatisticsAverageShortfallWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::Statistics, QuantLib::Statistics)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->averageShortfall(
        mTarget
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void StatisticsAverageShortfallWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::StatisticsAverageShortfall) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new StatisticsAverageShortfallWorker(
    callback
    ,ObjectIDCpp
    ,TargetCpp
  ));

}

//StatisticsAverageShortfallWorker::~StatisticsAverageShortfallWorker(){
//
//}

//void StatisticsAverageShortfallWorker::Destroy(){
//
//}

void GaussianDownsideVarianceWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianDownsideVariance(
      mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianDownsideVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianDownsideVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianDownsideVarianceWorker(
    callback
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianDownsideVarianceWorker::~GaussianDownsideVarianceWorker(){
//
//}

//void GaussianDownsideVarianceWorker::Destroy(){
//
//}

void GaussianDownsideDeviationWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianDownsideDeviation(
      mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianDownsideDeviationWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianDownsideDeviation) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianDownsideDeviationWorker(
    callback
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianDownsideDeviationWorker::~GaussianDownsideDeviationWorker(){
//
//}

//void GaussianDownsideDeviationWorker::Destroy(){
//
//}

void GaussianRegretWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianRegret(
      mTarget
      ,
       mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianRegretWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianRegret) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianRegretWorker(
    callback
    ,TargetCpp
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianRegretWorker::~GaussianRegretWorker(){
//
//}

//void GaussianRegretWorker::Destroy(){
//
//}

void GaussianPercentileWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianPercentile(
      mX
      ,
       mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianPercentileWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianPercentile) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("X is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double XCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianPercentileWorker(
    callback
    ,XCpp
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianPercentileWorker::~GaussianPercentileWorker(){
//
//}

//void GaussianPercentileWorker::Destroy(){
//
//}

void GaussianTopPercentileWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianTopPercentile(
      mX
      ,
       mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianTopPercentileWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianTopPercentile) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("X is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double XCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianTopPercentileWorker(
    callback
    ,XCpp
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianTopPercentileWorker::~GaussianTopPercentileWorker(){
//
//}

//void GaussianTopPercentileWorker::Destroy(){
//
//}

void GaussianPotentialUpsideWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianPotentialUpside(
      mTarget
      ,
       mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianPotentialUpsideWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianPotentialUpside) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianPotentialUpsideWorker(
    callback
    ,TargetCpp
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianPotentialUpsideWorker::~GaussianPotentialUpsideWorker(){
//
//}

//void GaussianPotentialUpsideWorker::Destroy(){
//
//}

void GaussianValueAtRiskWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianValueAtRisk(
      mTarget
      ,
       mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianValueAtRiskWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianValueAtRisk) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianValueAtRiskWorker(
    callback
    ,TargetCpp
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianValueAtRiskWorker::~GaussianValueAtRiskWorker(){
//
//}

//void GaussianValueAtRiskWorker::Destroy(){
//
//}

void GaussianExpectedShortfallWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianExpectedShortfall(
      mTarget
      ,
       mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianExpectedShortfallWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianExpectedShortfall) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianExpectedShortfallWorker(
    callback
    ,TargetCpp
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianExpectedShortfallWorker::~GaussianExpectedShortfallWorker(){
//
//}

//void GaussianExpectedShortfallWorker::Destroy(){
//
//}

void GaussianShortfallWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianShortfall(
      mTarget
      ,
       mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianShortfallWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianShortfall) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianShortfallWorker(
    callback
    ,TargetCpp
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianShortfallWorker::~GaussianShortfallWorker(){
//
//}

//void GaussianShortfallWorker::Destroy(){
//
//}

void GaussianAverageShortfallWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  QuantLib::Real returnValue = QuantLibAddin::gaussianAverageShortfall(
      mTarget
      ,
       mMean
      ,
       mStdDev
     );

  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GaussianAverageShortfallWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::GaussianAverageShortfall) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Target is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("StdDev is required.");
  }
  // convert js argument to c++ type
  double TargetCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double StdDevCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GaussianAverageShortfallWorker(
    callback
    ,TargetCpp
    ,MeanCpp
    ,StdDevCpp
  ));

}

//GaussianAverageShortfallWorker::~GaussianAverageShortfallWorker(){
//
//}

//void GaussianAverageShortfallWorker::Destroy(){
//
//}
 