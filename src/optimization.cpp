/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "optimization.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/optimization.hpp>
#include <ql/math/optimization/spherecylinder.hpp>
#include <ql/math/optimization/endcriteria.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void EndCriteriaWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlEndCriteria(
          mObjectID,
          mMaxIterations,
          mMaxStationaryStateIterations,
          mRootEpsilon,
          mFunctionEpsilon,
          mGradientNormEpsilon,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::EndCriteria(
          valueObject,
          mMaxIterations,
          mMaxStationaryStateIterations,
          mRootEpsilon,
          mFunctionEpsilon,
          mGradientNormEpsilon,
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

void EndCriteriaWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EndCriteria) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("MaxIterations is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("MaxStationaryStateIterations is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("RootEpsilon is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("FunctionEpsilon is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("GradientNormEpsilon is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  long MaxIterationsCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  long MaxStationaryStateIterationsCpp = Nan::To<int32_t>(info[2]).FromJust();

  // convert js argument to c++ type
  double RootEpsilonCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double FunctionEpsilonCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double GradientNormEpsilonCpp = Nan::To<double>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new EndCriteriaWorker(
    callback
    ,ObjectIDCpp
    ,MaxIterationsCpp
    ,MaxStationaryStateIterationsCpp
    ,RootEpsilonCpp
    ,FunctionEpsilonCpp
    ,GradientNormEpsilonCpp
  ));

}

//EndCriteriaWorker::~EndCriteriaWorker(){
//
//}

//void EndCriteriaWorker::Destroy(){
//
//}

void NoConstraintWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlNoConstraint(
          mObjectID,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::NoConstraint(
          valueObject,
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

void NoConstraintWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::NoConstraint) {

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
  Nan::AsyncQueueWorker(new NoConstraintWorker(
    callback
    ,ObjectIDCpp
  ));

}

//NoConstraintWorker::~NoConstraintWorker(){
//
//}

//void NoConstraintWorker::Destroy(){
//
//}

void SimplexWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSimplex(
          mObjectID,
          mLambda,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::Simplex(
          valueObject,
          mLambda,
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

void SimplexWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::Simplex) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Lambda is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double LambdaCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SimplexWorker(
    callback
    ,ObjectIDCpp
    ,LambdaCpp
  ));

}

//SimplexWorker::~SimplexWorker(){
//
//}

//void SimplexWorker::Destroy(){
//
//}

void LevenbergMarquardtWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlLevenbergMarquardt(
          mObjectID,
          mEpsfcn,
          mXtol,
          mGtol,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::LevenbergMarquardt(
          valueObject,
          mEpsfcn,
          mXtol,
          mGtol,
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

void LevenbergMarquardtWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LevenbergMarquardt) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Epsfcn is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Xtol is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Gtol is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double EpsfcnCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double XtolCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double GtolCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LevenbergMarquardtWorker(
    callback
    ,ObjectIDCpp
    ,EpsfcnCpp
    ,XtolCpp
    ,GtolCpp
  ));

}

//LevenbergMarquardtWorker::~LevenbergMarquardtWorker(){
//
//}

//void LevenbergMarquardtWorker::Destroy(){
//
//}

void ConjugateGradientWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(LineSearchLibObjPtr, mLineSearch,
      QuantLibAddin::LineSearch, QuantLib::LineSearch)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlConjugateGradient(
          mObjectID,
          mLineSearch,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ConjugateGradient(
          valueObject,
          LineSearchLibObjPtr,
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

void ConjugateGradientWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ConjugateGradient) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("LineSearch is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strLineSearch(info[1]->ToString());
  string LineSearchCpp(strdup(*strLineSearch));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ConjugateGradientWorker(
    callback
    ,ObjectIDCpp
    ,LineSearchCpp
  ));

}

//ConjugateGradientWorker::~ConjugateGradientWorker(){
//
//}

//void ConjugateGradientWorker::Destroy(){
//
//}

void SteepestDescentWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(LineSearchLibObjPtr, mLineSearch,
      QuantLibAddin::LineSearch, QuantLib::LineSearch)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSteepestDescent(
          mObjectID,
          mLineSearch,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SteepestDescent(
          valueObject,
          LineSearchLibObjPtr,
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

void SteepestDescentWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SteepestDescent) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("LineSearch is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strLineSearch(info[1]->ToString());
  string LineSearchCpp(strdup(*strLineSearch));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SteepestDescentWorker(
    callback
    ,ObjectIDCpp
    ,LineSearchCpp
  ));

}

//SteepestDescentWorker::~SteepestDescentWorker(){
//
//}

//void SteepestDescentWorker::Destroy(){
//
//}

void ArmijoLineSearchWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlArmijoLineSearch(
          mObjectID,
          mEpsilon,
          mAlpha,
          mBeta,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::ArmijoLineSearch(
          valueObject,
          mEpsilon,
          mAlpha,
          mBeta,
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

void ArmijoLineSearchWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::ArmijoLineSearch) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Epsilon is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Alpha is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double EpsilonCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double AlphaCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new ArmijoLineSearchWorker(
    callback
    ,ObjectIDCpp
    ,EpsilonCpp
    ,AlphaCpp
    ,BetaCpp
  ));

}

//ArmijoLineSearchWorker::~ArmijoLineSearchWorker(){
//
//}

//void ArmijoLineSearchWorker::Destroy(){
//
//}

void EndCriteriaMaxIterationsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // invoke the member function
  QuantLib::Size returnValue = ObjectIDLibObjPtr->maxIterations(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EndCriteriaMaxIterationsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EndCriteriaMaxIterations) {

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
  Nan::AsyncQueueWorker(new EndCriteriaMaxIterationsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EndCriteriaMaxIterationsWorker::~EndCriteriaMaxIterationsWorker(){
//
//}

//void EndCriteriaMaxIterationsWorker::Destroy(){
//
//}

void EndCriteriaMaxStationaryStateIterationsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // invoke the member function
  QuantLib::Size returnValue = ObjectIDLibObjPtr->maxStationaryStateIterations(
      );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EndCriteriaMaxStationaryStateIterationsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EndCriteriaMaxStationaryStateIterations) {

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
  Nan::AsyncQueueWorker(new EndCriteriaMaxStationaryStateIterationsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EndCriteriaMaxStationaryStateIterationsWorker::~EndCriteriaMaxStationaryStateIterationsWorker(){
//
//}

//void EndCriteriaMaxStationaryStateIterationsWorker::Destroy(){
//
//}

void EndCriteriaFunctionEpsilonWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->functionEpsilon(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EndCriteriaFunctionEpsilonWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EndCriteriaFunctionEpsilon) {

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
  Nan::AsyncQueueWorker(new EndCriteriaFunctionEpsilonWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EndCriteriaFunctionEpsilonWorker::~EndCriteriaFunctionEpsilonWorker(){
//
//}

//void EndCriteriaFunctionEpsilonWorker::Destroy(){
//
//}

void EndCriteriaGradientNormEpsilonWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EndCriteria, QuantLib::EndCriteria)


  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->gradientNormEpsilon(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EndCriteriaGradientNormEpsilonWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EndCriteriaGradientNormEpsilon) {

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
  Nan::AsyncQueueWorker(new EndCriteriaGradientNormEpsilonWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EndCriteriaGradientNormEpsilonWorker::~EndCriteriaGradientNormEpsilonWorker(){
//
//}

//void EndCriteriaGradientNormEpsilonWorker::Destroy(){
//
//}

void SphereCylinderOptimizerClosestWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes

  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural MaxIterLib = ObjectHandler::convert2<long>(
      mMaxIter, "MaxIter", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib datatypes
       // invoke the utility function
  std::vector<QuantLib::Real> returnValue = QuantLib::sphereCylinderOptimizerClosest(
      mR
      ,
       mS
      ,
       mAlpha
      ,
       mZ1
      ,
       mZ2
      ,
       mZ3
      ,
       MaxIterLib
      ,
       mTol
   );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SphereCylinderOptimizerClosestWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SphereCylinderOptimizerClosest) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("R is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("S is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Alpha is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Z1 is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Z2 is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Z3 is required.");
  }
  if (info.Length() == 7 || !info[7]->IsNumber()) {
      return Nan::ThrowError("Tol is required.");
  }
  // convert js argument to c++ type
  double RCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double SCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double AlphaCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double Z1Cpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double Z2Cpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double Z3Cpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  ObjectHandler::property_t MaxIterCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[6]).FromJust()));

  // convert js argument to c++ type
  double TolCpp = Nan::To<double>(info[7]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SphereCylinderOptimizerClosestWorker(
    callback
    ,RCpp
    ,SCpp
    ,AlphaCpp
    ,Z1Cpp
    ,Z2Cpp
    ,Z3Cpp
    ,MaxIterCpp
    ,TolCpp
  ));

}

//SphereCylinderOptimizerClosestWorker::~SphereCylinderOptimizerClosestWorker(){
//
//}

//void SphereCylinderOptimizerClosestWorker::Destroy(){
//
//}

void SecondsToStringWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLibAddin::qlSecondsToString(
      mSeconds
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SecondsToStringWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SecondsToString) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Seconds is required.");
  }
  // convert js argument to c++ type
  double SecondsCpp = Nan::To<double>(info[0]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SecondsToStringWorker(
    callback
    ,SecondsCpp
  ));

}

//SecondsToStringWorker::~SecondsToStringWorker(){
//
//}

//void SecondsToStringWorker::Destroy(){
//
//}
 