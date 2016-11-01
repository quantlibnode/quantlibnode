// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "mathf.hpp"

#include <qlo/qladdindefines.hpp>
#include <ql/math/primenumbers.hpp>
#include <ql/math/matrixutilities/pseudosqrt.hpp>
#include <ql/math/matrixutilities/choleskydecomposition.hpp>
#include <qlo/symmetricschurdecomposition.hpp>
#include <qlo/getcovariance.hpp>
#include <qlo/mathf.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void SymmetricSchurDecompositionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix SymmetricMatrixLib = QuantLibAddin::vvToQlMatrix(mSymmetricMatrix);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSymmetricSchurDecomposition(
          mObjectID,
          mSymmetricMatrix,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SymmetricSchurDecomposition(
          valueObject,
          SymmetricMatrixLib,
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

void SymmetricSchurDecompositionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SymmetricSchurDecomposition) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("SymmetricMatrix is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >SymmetricMatrixCpp;

  Local<Array> SymmetricMatrixMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < SymmetricMatrixMatrix->Length(); i++){
	  Local<Array> SymmetricMatrixArray = SymmetricMatrixMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < SymmetricMatrixArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(SymmetricMatrixArray, j).ToLocalChecked()).FromJust());
	  }
	  SymmetricMatrixCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SymmetricSchurDecompositionWorker(
    callback
    ,ObjectIDCpp
    ,SymmetricMatrixCpp
  ));

}

//SymmetricSchurDecompositionWorker::~SymmetricSchurDecompositionWorker(){
//
//}

//SymmetricSchurDecompositionWorker::Destroy(){
//
//}

void CovarianceDecompositionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix SymmetricMatrixLib = QuantLibAddin::vvToQlMatrix(mSymmetricMatrix);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCovarianceDecomposition(
          mObjectID,
          mSymmetricMatrix,
          mTolerance,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CovarianceDecomposition(
          valueObject,
          SymmetricMatrixLib,
          mTolerance,
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

void CovarianceDecompositionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CovarianceDecomposition) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("SymmetricMatrix is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Tolerance is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >SymmetricMatrixCpp;

  Local<Array> SymmetricMatrixMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < SymmetricMatrixMatrix->Length(); i++){
	  Local<Array> SymmetricMatrixArray = SymmetricMatrixMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < SymmetricMatrixArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(SymmetricMatrixArray, j).ToLocalChecked()).FromJust());
	  }
	  SymmetricMatrixCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  double ToleranceCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CovarianceDecompositionWorker(
    callback
    ,ObjectIDCpp
    ,SymmetricMatrixCpp
    ,ToleranceCpp
  ));

}

//CovarianceDecompositionWorker::~CovarianceDecompositionWorker(){
//
//}

//CovarianceDecompositionWorker::Destroy(){
//
//}

void SymmetricSchurDecompositionEigenvaluesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SymmetricSchurDecomposition, QuantLib::SymmetricSchurDecomposition)


  // loop on the input parameter and populate the return vector
  QuantLib::Array returnValue = ObjectIDLibObjPtr->eigenvalues(
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

void SymmetricSchurDecompositionEigenvaluesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SymmetricSchurDecompositionEigenvalues) {

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
  Nan::AsyncQueueWorker(new SymmetricSchurDecompositionEigenvaluesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SymmetricSchurDecompositionEigenvaluesWorker::~SymmetricSchurDecompositionEigenvaluesWorker(){
//
//}

//SymmetricSchurDecompositionEigenvaluesWorker::Destroy(){
//
//}

void SymmetricSchurDecompositionEigenvectorsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SymmetricSchurDecomposition, QuantLib::SymmetricSchurDecomposition)

  QuantLib::Matrix returnValue;


  // invoke the member function
  returnValue = ObjectIDLibObjPtr->eigenvectors(
      );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SymmetricSchurDecompositionEigenvectorsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SymmetricSchurDecompositionEigenvectors) {

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
  Nan::AsyncQueueWorker(new SymmetricSchurDecompositionEigenvectorsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//SymmetricSchurDecompositionEigenvectorsWorker::~SymmetricSchurDecompositionEigenvectorsWorker(){
//
//}

//SymmetricSchurDecompositionEigenvectorsWorker::Destroy(){
//
//}

void CovarianceDecompositionVariancesWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CovarianceDecomposition, QuantLib::CovarianceDecomposition)


  // loop on the input parameter and populate the return vector
  QuantLib::Array returnValue = ObjectIDLibObjPtr->variances(
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

void CovarianceDecompositionVariancesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CovarianceDecompositionVariances) {

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
  Nan::AsyncQueueWorker(new CovarianceDecompositionVariancesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CovarianceDecompositionVariancesWorker::~CovarianceDecompositionVariancesWorker(){
//
//}

//CovarianceDecompositionVariancesWorker::Destroy(){
//
//}

void CovarianceDecompositionStandardDeviationsWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CovarianceDecomposition, QuantLib::CovarianceDecomposition)


  // loop on the input parameter and populate the return vector
  QuantLib::Array returnValue = ObjectIDLibObjPtr->standardDeviations(
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

void CovarianceDecompositionStandardDeviationsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CovarianceDecompositionStandardDeviations) {

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
  Nan::AsyncQueueWorker(new CovarianceDecompositionStandardDeviationsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CovarianceDecompositionStandardDeviationsWorker::~CovarianceDecompositionStandardDeviationsWorker(){
//
//}

//CovarianceDecompositionStandardDeviationsWorker::Destroy(){
//
//}

void CovarianceDecompositionCorrelationMatrixWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::CovarianceDecomposition, QuantLib::CovarianceDecomposition)

  QuantLib::Matrix returnValue;


  // invoke the member function
  returnValue = ObjectIDLibObjPtr->correlationMatrix(
      );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CovarianceDecompositionCorrelationMatrixWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CovarianceDecompositionCorrelationMatrix) {

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
  Nan::AsyncQueueWorker(new CovarianceDecompositionCorrelationMatrixWorker(
    callback
    ,ObjectIDCpp
  ));

}

//CovarianceDecompositionCorrelationMatrixWorker::~CovarianceDecompositionCorrelationMatrixWorker(){
//
//}

//CovarianceDecompositionCorrelationMatrixWorker::Destroy(){
//
//}

void PrimeNumberWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLib::PrimeNumbers::get(
      mN
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PrimeNumberWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::PrimeNumber) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("N is required.");
  }
  // convert js argument to c++ type
  long NCpp = Nan::To<int32_t>(info[0]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PrimeNumberWorker(
    callback
    ,NCpp
  ));

}

//PrimeNumberWorker::~PrimeNumberWorker(){
//
//}

//PrimeNumberWorker::Destroy(){
//
//}

void NormDistWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLibAddin::normDist(
      mX
      ,
       mMean
      ,
       mStandard_dev
      ,
       mCumulative
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void NormDistWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::NormDist) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("X is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Standard_dev is required.");
  }
  if (info.Length() == 3 || !info[3]->IsBoolean()) {
      return Nan::ThrowError("Cumulative is required.");
  }
  // convert js argument to c++ type
  double XCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double Standard_devCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  bool CumulativeCpp = Nan::To<bool>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new NormDistWorker(
    callback
    ,XCpp
    ,MeanCpp
    ,Standard_devCpp
    ,CumulativeCpp
  ));

}

//NormDistWorker::~NormDistWorker(){
//
//}

//NormDistWorker::Destroy(){
//
//}

void NormSDistWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLibAddin::normSDist(
      mZ
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void NormSDistWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::NormSDist) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Z is required.");
  }
  // convert js argument to c++ type
  double ZCpp = Nan::To<double>(info[0]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new NormSDistWorker(
    callback
    ,ZCpp
  ));

}

//NormSDistWorker::~NormSDistWorker(){
//
//}

//NormSDistWorker::Destroy(){
//
//}

void NormInvWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLibAddin::normInv(
      mProbability
      ,
       mMean
      ,
       mStandard_dev
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void NormInvWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::NormInv) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Probability is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Mean is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Standard_dev is required.");
  }
  // convert js argument to c++ type
  double ProbabilityCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double MeanCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double Standard_devCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new NormInvWorker(
    callback
    ,ProbabilityCpp
    ,MeanCpp
    ,Standard_devCpp
  ));

}

//NormInvWorker::~NormInvWorker(){
//
//}

//NormInvWorker::Destroy(){
//
//}

void NormSInvWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLibAddin::normSInv(
      mProbability
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void NormSInvWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::NormSInv) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Probability is required.");
  }
  // convert js argument to c++ type
  double ProbabilityCpp = Nan::To<double>(info[0]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new NormSInvWorker(
    callback
    ,ProbabilityCpp
  ));

}

//NormSInvWorker::~NormSInvWorker(){
//
//}

//NormSInvWorker::Destroy(){
//
//}

void CholeskyDecompositionWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix MatrixLib = QuantLibAddin::vvToQlMatrix(mMatrix);

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::CholeskyDecomposition(
        MatrixLib
       ,
         mFlexible
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CholeskyDecompositionWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CholeskyDecomposition) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Matrix is required.");
  }
  if (info.Length() == 1 || !info[1]->IsBoolean()) {
      return Nan::ThrowError("Flexible is required.");
  }
  // convert js argument to c++ type
  std::vector< std::vector<double> >MatrixCpp;

  Local<Array> MatrixMatrix = info[0].As<Array>();
  for (unsigned int i = 0; i < MatrixMatrix->Length(); i++){
	  Local<Array> MatrixArray = MatrixMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < MatrixArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(MatrixArray, j).ToLocalChecked()).FromJust());
	  }
	  MatrixCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  bool FlexibleCpp = Nan::To<bool>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CholeskyDecompositionWorker(
    callback
    ,MatrixCpp
    ,FlexibleCpp
  ));

}

//CholeskyDecompositionWorker::~CholeskyDecompositionWorker(){
//
//}

//CholeskyDecompositionWorker::Destroy(){
//
//}

void PseudoSqrtWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix MatrixLib = QuantLibAddin::vvToQlMatrix(mMatrix);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::SalvagingAlgorithm::Type SalvagingAlgorithmEnum =
      ObjectHandler::Create<QuantLib::SalvagingAlgorithm::Type>()(mSalvagingAlgorithm);

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::pseudoSqrt(
        MatrixLib
       ,
         SalvagingAlgorithmEnum
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void PseudoSqrtWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::PseudoSqrt) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Matrix is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("SalvagingAlgorithm is required.");
  }
  // convert js argument to c++ type
  std::vector< std::vector<double> >MatrixCpp;

  Local<Array> MatrixMatrix = info[0].As<Array>();
  for (unsigned int i = 0; i < MatrixMatrix->Length(); i++){
	  Local<Array> MatrixArray = MatrixMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < MatrixArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(MatrixArray, j).ToLocalChecked()).FromJust());
	  }
	  MatrixCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strSalvagingAlgorithm(info[1]->ToString());
  string SalvagingAlgorithmCpp(strdup(*strSalvagingAlgorithm));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new PseudoSqrtWorker(
    callback
    ,MatrixCpp
    ,SalvagingAlgorithmCpp
  ));

}

//PseudoSqrtWorker::~PseudoSqrtWorker(){
//
//}

//PseudoSqrtWorker::Destroy(){
//
//}

void RankReducedSqrtWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix MatrixLib = QuantLibAddin::vvToQlMatrix(mMatrix);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::SalvagingAlgorithm::Type SalvagingAlgorithmEnum =
      ObjectHandler::Create<QuantLib::SalvagingAlgorithm::Type>()(mSalvagingAlgorithm);

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = QuantLib::rankReducedSqrt(
        MatrixLib
       ,
         mMaxRank
       ,
         mComponentPercentage
       ,
         SalvagingAlgorithmEnum
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void RankReducedSqrtWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::RankReducedSqrt) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Matrix is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("MaxRank is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("ComponentPercentage is required.");
  }
  if (info.Length() == 3 || !info[3]->IsString()) {
      return Nan::ThrowError("SalvagingAlgorithm is required.");
  }
  // convert js argument to c++ type
  std::vector< std::vector<double> >MatrixCpp;

  Local<Array> MatrixMatrix = info[0].As<Array>();
  for (unsigned int i = 0; i < MatrixMatrix->Length(); i++){
	  Local<Array> MatrixArray = MatrixMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < MatrixArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(MatrixArray, j).ToLocalChecked()).FromJust());
	  }
	  MatrixCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  long MaxRankCpp = Nan::To<int32_t>(info[1]).FromJust();

  // convert js argument to c++ type
  double ComponentPercentageCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strSalvagingAlgorithm(info[3]->ToString());
  string SalvagingAlgorithmCpp(strdup(*strSalvagingAlgorithm));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new RankReducedSqrtWorker(
    callback
    ,MatrixCpp
    ,MaxRankCpp
    ,ComponentPercentageCpp
    ,SalvagingAlgorithmCpp
  ));

}

//RankReducedSqrtWorker::~RankReducedSqrtWorker(){
//
//}

//RankReducedSqrtWorker::Destroy(){
//
//}

void GetCovarianceWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix MatrixLib = QuantLibAddin::vvToQlMatrix(mMatrix);

       QuantLib::Matrix returnValue;


  // invoke the utility function
  returnValue = getCovariance(
        mVols.begin(),
        mVols.end()
       ,
         MatrixLib
       ,
         mTolerance
       );


  mReturnValue = QuantLibAddin::qlMatrixToVv(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void GetCovarianceWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::GetCovariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsArray()) {
      return Nan::ThrowError("Vols is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Matrix is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Tolerance is required.");
  }
  // convert js argument to c++ type
  std::vector<double>VolsCpp;

  Local<Array> VolsArray = info[0].As<Array>();
  for (unsigned int i = 0; i < VolsArray->Length(); i++){
    VolsCpp.push_back(Nan::To<double>(Nan::Get(VolsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector< std::vector<double> >MatrixCpp;

  Local<Array> MatrixMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < MatrixMatrix->Length(); i++){
	  Local<Array> MatrixArray = MatrixMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < MatrixArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(MatrixArray, j).ToLocalChecked()).FromJust());
	  }
	  MatrixCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  double ToleranceCpp = Nan::To<double>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new GetCovarianceWorker(
    callback
    ,VolsCpp
    ,MatrixCpp
    ,ToleranceCpp
  ));

}

//GetCovarianceWorker::~GetCovarianceWorker(){
//
//}

//GetCovarianceWorker::Destroy(){
//
//}
 