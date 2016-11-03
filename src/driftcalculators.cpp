/* 
  Copyright (C) 2016 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "driftcalculators.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/driftcalculators.hpp>
#include <qlo/curvestate.hpp>
#include <ql/models/marketmodels/curvestates/cmswapcurvestate.hpp>
#include <ql/models/marketmodels/curvestates/coterminalswapcurvestate.hpp>
#include <ql/models/marketmodels/curvestates/lmmcurvestate.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void LMMDriftCalculatorWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix Pseudo_square_rootLib = QuantLibAddin::vvToQlMatrix(mPseudo_square_root);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumeraireLib;
  QuantLibAddin::cppToLibrary(mNumeraire, NumeraireLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size AliveLib;
  QuantLibAddin::cppToLibrary(mAlive, AliveLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlLMMDriftCalculator(
          mObjectID,
          mPseudo_square_root,
          mDisplacements,
          mTaus,
          mNumeraire,
          mAlive,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::LMMDriftCalculator(
          valueObject,
          Pseudo_square_rootLib,
          mDisplacements,
          mTaus,
          NumeraireLib,
          AliveLib,
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

void LMMDriftCalculatorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LMMDriftCalculator) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Pseudo_square_root is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Displacements is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Taus is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Numeraire is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Alive is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >Pseudo_square_rootCpp;

  Local<Array> Pseudo_square_rootMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < Pseudo_square_rootMatrix->Length(); i++){
	  Local<Array> Pseudo_square_rootArray = Pseudo_square_rootMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < Pseudo_square_rootArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(Pseudo_square_rootArray, j).ToLocalChecked()).FromJust());
	  }
	  Pseudo_square_rootCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>DisplacementsCpp;

  Local<Array> DisplacementsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < DisplacementsArray->Length(); i++){
    DisplacementsCpp.push_back(Nan::To<double>(Nan::Get(DisplacementsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TausCpp;

  Local<Array> TausArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TausArray->Length(); i++){
    TausCpp.push_back(Nan::To<double>(Nan::Get(TausArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long NumeraireCpp = Nan::To<int32_t>(info[4]).FromJust();

  // convert js argument to c++ type
  long AliveCpp = Nan::To<int32_t>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMDriftCalculatorWorker(
    callback
    ,ObjectIDCpp
    ,Pseudo_square_rootCpp
    ,DisplacementsCpp
    ,TausCpp
    ,NumeraireCpp
    ,AliveCpp
  ));

}

//LMMDriftCalculatorWorker::~LMMDriftCalculatorWorker(){
//
//}

//void LMMDriftCalculatorWorker::Destroy(){
//
//}

void LMMNormalDriftCalculatorWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix Pseudo_square_rootLib = QuantLibAddin::vvToQlMatrix(mPseudo_square_root);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumeraireLib;
  QuantLibAddin::cppToLibrary(mNumeraire, NumeraireLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size AliveLib;
  QuantLibAddin::cppToLibrary(mAlive, AliveLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlLMMNormalDriftCalculator(
          mObjectID,
          mPseudo_square_root,
          mTaus,
          mNumeraire,
          mAlive,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::LMMNormalDriftCalculator(
          valueObject,
          Pseudo_square_rootLib,
          mTaus,
          NumeraireLib,
          AliveLib,
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

void LMMNormalDriftCalculatorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::LMMNormalDriftCalculator) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Pseudo_square_root is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Taus is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Numeraire is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Alive is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >Pseudo_square_rootCpp;

  Local<Array> Pseudo_square_rootMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < Pseudo_square_rootMatrix->Length(); i++){
	  Local<Array> Pseudo_square_rootArray = Pseudo_square_rootMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < Pseudo_square_rootArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(Pseudo_square_rootArray, j).ToLocalChecked()).FromJust());
	  }
	  Pseudo_square_rootCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>TausCpp;

  Local<Array> TausArray = info[2].As<Array>();
  for (unsigned int i = 0; i < TausArray->Length(); i++){
    TausCpp.push_back(Nan::To<double>(Nan::Get(TausArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long NumeraireCpp = Nan::To<int32_t>(info[3]).FromJust();

  // convert js argument to c++ type
  long AliveCpp = Nan::To<int32_t>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMNormalDriftCalculatorWorker(
    callback
    ,ObjectIDCpp
    ,Pseudo_square_rootCpp
    ,TausCpp
    ,NumeraireCpp
    ,AliveCpp
  ));

}

//LMMNormalDriftCalculatorWorker::~LMMNormalDriftCalculatorWorker(){
//
//}

//void LMMNormalDriftCalculatorWorker::Destroy(){
//
//}

void CMSMMDriftCalculatorWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix Pseudo_square_rootLib = QuantLibAddin::vvToQlMatrix(mPseudo_square_root);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumeraireLib;
  QuantLibAddin::cppToLibrary(mNumeraire, NumeraireLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size AliveLib;
  QuantLibAddin::cppToLibrary(mAlive, AliveLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size SpanningFwdsLib;
  QuantLibAddin::cppToLibrary(mSpanningFwds, SpanningFwdsLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlCMSMMDriftCalculator(
          mObjectID,
          mPseudo_square_root,
          mDisplacements,
          mTaus,
          mNumeraire,
          mAlive,
          mSpanningFwds,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::CMSMMDriftCalculator(
          valueObject,
          Pseudo_square_rootLib,
          mDisplacements,
          mTaus,
          NumeraireLib,
          AliveLib,
          SpanningFwdsLib,
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

void CMSMMDriftCalculatorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::CMSMMDriftCalculator) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Pseudo_square_root is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Displacements is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Taus is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Numeraire is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Alive is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("SpanningFwds is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >Pseudo_square_rootCpp;

  Local<Array> Pseudo_square_rootMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < Pseudo_square_rootMatrix->Length(); i++){
	  Local<Array> Pseudo_square_rootArray = Pseudo_square_rootMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < Pseudo_square_rootArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(Pseudo_square_rootArray, j).ToLocalChecked()).FromJust());
	  }
	  Pseudo_square_rootCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>DisplacementsCpp;

  Local<Array> DisplacementsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < DisplacementsArray->Length(); i++){
    DisplacementsCpp.push_back(Nan::To<double>(Nan::Get(DisplacementsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TausCpp;

  Local<Array> TausArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TausArray->Length(); i++){
    TausCpp.push_back(Nan::To<double>(Nan::Get(TausArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long NumeraireCpp = Nan::To<int32_t>(info[4]).FromJust();

  // convert js argument to c++ type
  long AliveCpp = Nan::To<int32_t>(info[5]).FromJust();

  // convert js argument to c++ type
  long SpanningFwdsCpp = Nan::To<int32_t>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CMSMMDriftCalculatorWorker(
    callback
    ,ObjectIDCpp
    ,Pseudo_square_rootCpp
    ,DisplacementsCpp
    ,TausCpp
    ,NumeraireCpp
    ,AliveCpp
    ,SpanningFwdsCpp
  ));

}

//CMSMMDriftCalculatorWorker::~CMSMMDriftCalculatorWorker(){
//
//}

//void CMSMMDriftCalculatorWorker::Destroy(){
//
//}

void SMMDriftCalculatorWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix Pseudo_square_rootLib = QuantLibAddin::vvToQlMatrix(mPseudo_square_root);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size NumeraireLib;
  QuantLibAddin::cppToLibrary(mNumeraire, NumeraireLib);


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size AliveLib;
  QuantLibAddin::cppToLibrary(mAlive, AliveLib);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSMMDriftCalculator(
          mObjectID,
          mPseudo_square_root,
          mDisplacements,
          mTaus,
          mNumeraire,
          mAlive,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SMMDriftCalculator(
          valueObject,
          Pseudo_square_rootLib,
          mDisplacements,
          mTaus,
          NumeraireLib,
          AliveLib,
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

void SMMDriftCalculatorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SMMDriftCalculator) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Pseudo_square_root is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("Displacements is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Taus is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Numeraire is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Alive is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector< std::vector<double> >Pseudo_square_rootCpp;

  Local<Array> Pseudo_square_rootMatrix = info[1].As<Array>();
  for (unsigned int i = 0; i < Pseudo_square_rootMatrix->Length(); i++){
	  Local<Array> Pseudo_square_rootArray = Pseudo_square_rootMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < Pseudo_square_rootArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(Pseudo_square_rootArray, j).ToLocalChecked()).FromJust());
	  }
	  Pseudo_square_rootCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>DisplacementsCpp;

  Local<Array> DisplacementsArray = info[2].As<Array>();
  for (unsigned int i = 0; i < DisplacementsArray->Length(); i++){
    DisplacementsCpp.push_back(Nan::To<double>(Nan::Get(DisplacementsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>TausCpp;

  Local<Array> TausArray = info[3].As<Array>();
  for (unsigned int i = 0; i < TausArray->Length(); i++){
    TausCpp.push_back(Nan::To<double>(Nan::Get(TausArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long NumeraireCpp = Nan::To<int32_t>(info[4]).FromJust();

  // convert js argument to c++ type
  long AliveCpp = Nan::To<int32_t>(info[5]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SMMDriftCalculatorWorker(
    callback
    ,ObjectIDCpp
    ,Pseudo_square_rootCpp
    ,DisplacementsCpp
    ,TausCpp
    ,NumeraireCpp
    ,AliveCpp
  ));

}

//SMMDriftCalculatorWorker::~SMMDriftCalculatorWorker(){
//
//}

//void SMMDriftCalculatorWorker::Destroy(){
//
//}

void LMMDriftCalculatorComputePlainWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::LMMCurveState, QuantLib::LMMCurveState)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::LMMDriftCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->computePlain(
        CurveStateLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LMMDriftCalculatorComputePlainWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::LMMDriftCalculatorComputePlain) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[1]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMDriftCalculatorComputePlainWorker(
    callback
    ,ObjectIDCpp
    ,CurveStateCpp
  ));

}

//LMMDriftCalculatorComputePlainWorker::~LMMDriftCalculatorComputePlainWorker(){
//
//}

//void LMMDriftCalculatorComputePlainWorker::Destroy(){
//
//}

void LMMDriftCalculatorComputeReducedWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::LMMCurveState, QuantLib::LMMCurveState)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::LMMDriftCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->computeReduced(
        CurveStateLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LMMDriftCalculatorComputeReducedWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::LMMDriftCalculatorComputeReduced) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[1]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMDriftCalculatorComputeReducedWorker(
    callback
    ,ObjectIDCpp
    ,CurveStateCpp
  ));

}

//LMMDriftCalculatorComputeReducedWorker::~LMMDriftCalculatorComputeReducedWorker(){
//
//}

//void LMMDriftCalculatorComputeReducedWorker::Destroy(){
//
//}

void LMMDriftCalculatorComputeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::LMMCurveState, QuantLib::LMMCurveState)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::LMMDriftCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->compute(
        CurveStateLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LMMDriftCalculatorComputeWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::LMMDriftCalculatorCompute) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[1]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMDriftCalculatorComputeWorker(
    callback
    ,ObjectIDCpp
    ,CurveStateCpp
  ));

}

//LMMDriftCalculatorComputeWorker::~LMMDriftCalculatorComputeWorker(){
//
//}

//void LMMDriftCalculatorComputeWorker::Destroy(){
//
//}

void LMMNormalDriftCalculatorComputePlainWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::LMMCurveState, QuantLib::LMMCurveState)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::LMMNormalDriftCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->computePlain(
        CurveStateLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LMMNormalDriftCalculatorComputePlainWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::LMMNormalDriftCalculatorComputePlain) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[1]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMNormalDriftCalculatorComputePlainWorker(
    callback
    ,ObjectIDCpp
    ,CurveStateCpp
  ));

}

//LMMNormalDriftCalculatorComputePlainWorker::~LMMNormalDriftCalculatorComputePlainWorker(){
//
//}

//void LMMNormalDriftCalculatorComputePlainWorker::Destroy(){
//
//}

void LMMNormalDriftCalculatorComputeReducedWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::LMMCurveState, QuantLib::LMMCurveState)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::LMMNormalDriftCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->computeReduced(
        CurveStateLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LMMNormalDriftCalculatorComputeReducedWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::LMMNormalDriftCalculatorComputeReduced) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[1]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMNormalDriftCalculatorComputeReducedWorker(
    callback
    ,ObjectIDCpp
    ,CurveStateCpp
  ));

}

//LMMNormalDriftCalculatorComputeReducedWorker::~LMMNormalDriftCalculatorComputeReducedWorker(){
//
//}

//void LMMNormalDriftCalculatorComputeReducedWorker::Destroy(){
//
//}

void LMMNormalDriftCalculatorComputeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::LMMCurveState, QuantLib::LMMCurveState)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::LMMNormalDriftCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->compute(
        CurveStateLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void LMMNormalDriftCalculatorComputeWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::LMMNormalDriftCalculatorCompute) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[1]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new LMMNormalDriftCalculatorComputeWorker(
    callback
    ,ObjectIDCpp
    ,CurveStateCpp
  ));

}

//LMMNormalDriftCalculatorComputeWorker::~LMMNormalDriftCalculatorComputeWorker(){
//
//}

//void LMMNormalDriftCalculatorComputeWorker::Destroy(){
//
//}

void CMSMMDriftCalculatorComputeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CMSwapCurveState, QuantLib::CMSwapCurveState)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::CMSMMDriftCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->compute(
        CurveStateLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void CMSMMDriftCalculatorComputeWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::CMSMMDriftCalculatorCompute) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[1]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new CMSMMDriftCalculatorComputeWorker(
    callback
    ,ObjectIDCpp
    ,CurveStateCpp
  ));

}

//CMSMMDriftCalculatorComputeWorker::~CMSMMDriftCalculatorComputeWorker(){
//
//}

//void CMSMMDriftCalculatorComputeWorker::Destroy(){
//
//}

void SMMDriftCalculatorComputeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(CurveStateLibObj, mCurveState,
      QuantLibAddin::CoterminalSwapCurveState, QuantLib::CoterminalSwapCurveState)

       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SMMDriftCalculator)


  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDObjPtr->compute(
        CurveStateLibObj
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SMMDriftCalculatorComputeWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::SMMDriftCalculatorCompute) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("CurveState is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strCurveState(info[1]->ToString());
  string CurveStateCpp(strdup(*strCurveState));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SMMDriftCalculatorComputeWorker(
    callback
    ,ObjectIDCpp
    ,CurveStateCpp
  ));

}

//SMMDriftCalculatorComputeWorker::~SMMDriftCalculatorComputeWorker(){
//
//}

//void SMMDriftCalculatorComputeWorker::Destroy(){
//
//}
 