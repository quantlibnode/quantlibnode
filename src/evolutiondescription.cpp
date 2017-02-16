/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#include <nan.h>
#include <string.h>

#include "evolutiondescription.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/evolutiondescription.hpp>
#include <qlo/products.hpp>
#include <ql/models/marketmodels/multiproduct.hpp>
#include <ql/models/marketmodels/evolutiondescription.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void EvolutionDescriptionWorker::Execute(){

  try{
 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlEvolutionDescription(
          mObjectID,
          mRateTimes,
          mEvolutionTimes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::EvolutionDescription(
          valueObject,
          mRateTimes,
          mEvolutionTimes,
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

void EvolutionDescriptionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EvolutionDescription) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("RateTimes is required.");
  }
  if (info.Length() == 2 || !info[2]->IsArray()) {
      return Nan::ThrowError("EvolutionTimes is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  std::vector<double>RateTimesCpp;

  Local<Array> RateTimesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < RateTimesArray->Length(); i++){
    RateTimesCpp.push_back(Nan::To<double>(Nan::Get(RateTimesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector<double>EvolutionTimesCpp;

  Local<Array> EvolutionTimesArray = info[2].As<Array>();
  for (unsigned int i = 0; i < EvolutionTimesArray->Length(); i++){
    EvolutionTimesCpp.push_back(Nan::To<double>(Nan::Get(EvolutionTimesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new EvolutionDescriptionWorker(
    callback
    ,ObjectIDCpp
    ,RateTimesCpp
    ,EvolutionTimesCpp
  ));

}

//EvolutionDescriptionWorker::~EvolutionDescriptionWorker(){
//
//}

//void EvolutionDescriptionWorker::Destroy(){
//
//}

void EvolutionDescriptionFromProductWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(ProductLibObj, mProduct,
      QuantLibAddin::MarketModelMultiProduct, QuantLib::MarketModelMultiProduct)

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlEvolutionDescriptionFromProduct(
          mObjectID,
          mProduct,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::EvolutionDescription(
          valueObject,
          ProductLibObj,
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

void EvolutionDescriptionFromProductWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EvolutionDescriptionFromProduct) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Product is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strProduct(info[1]->ToString());
  string ProductCpp(strdup(*strProduct));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new EvolutionDescriptionFromProductWorker(
    callback
    ,ObjectIDCpp
    ,ProductCpp
  ));

}

//EvolutionDescriptionFromProductWorker::~EvolutionDescriptionFromProductWorker(){
//
//}

//void EvolutionDescriptionFromProductWorker::Destroy(){
//
//}

void EvolutionDescriptionRateTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->rateTimes(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EvolutionDescriptionRateTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::EvolutionDescriptionRateTimes) {

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
  Nan::AsyncQueueWorker(new EvolutionDescriptionRateTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EvolutionDescriptionRateTimesWorker::~EvolutionDescriptionRateTimesWorker(){
//
//}

//void EvolutionDescriptionRateTimesWorker::Destroy(){
//
//}

void EvolutionDescriptionRateTausWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->rateTaus(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EvolutionDescriptionRateTausWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::EvolutionDescriptionRateTaus) {

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
  Nan::AsyncQueueWorker(new EvolutionDescriptionRateTausWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EvolutionDescriptionRateTausWorker::~EvolutionDescriptionRateTausWorker(){
//
//}

//void EvolutionDescriptionRateTausWorker::Destroy(){
//
//}

void EvolutionDescriptionEvolutionTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->evolutionTimes(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EvolutionDescriptionEvolutionTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::EvolutionDescriptionEvolutionTimes) {

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
  Nan::AsyncQueueWorker(new EvolutionDescriptionEvolutionTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EvolutionDescriptionEvolutionTimesWorker::~EvolutionDescriptionEvolutionTimesWorker(){
//
//}

//void EvolutionDescriptionEvolutionTimesWorker::Destroy(){
//
//}

void EvolutionDescriptionFirstAliveRateWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Size> returnValue = ObjectIDLibObjPtr->firstAliveRate(
      );


  mReturnValue = QuantLibAddin::convertVector<QuantLib::Size, long>(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EvolutionDescriptionFirstAliveRateWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::EvolutionDescriptionFirstAliveRate) {

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
  Nan::AsyncQueueWorker(new EvolutionDescriptionFirstAliveRateWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EvolutionDescriptionFirstAliveRateWorker::~EvolutionDescriptionFirstAliveRateWorker(){
//
//}

//void EvolutionDescriptionFirstAliveRateWorker::Destroy(){
//
//}

void EvolutionDescriptionNumberOfRatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->numberOfRates(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EvolutionDescriptionNumberOfRatesWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EvolutionDescriptionNumberOfRates) {

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
  Nan::AsyncQueueWorker(new EvolutionDescriptionNumberOfRatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EvolutionDescriptionNumberOfRatesWorker::~EvolutionDescriptionNumberOfRatesWorker(){
//
//}

//void EvolutionDescriptionNumberOfRatesWorker::Destroy(){
//
//}

void EvolutionDescriptionNumberOfStepsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->numberOfSteps(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void EvolutionDescriptionNumberOfStepsWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::EvolutionDescriptionNumberOfSteps) {

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
  Nan::AsyncQueueWorker(new EvolutionDescriptionNumberOfStepsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//EvolutionDescriptionNumberOfStepsWorker::~EvolutionDescriptionNumberOfStepsWorker(){
//
//}

//void EvolutionDescriptionNumberOfStepsWorker::Destroy(){
//
//}

void TerminalMeasureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionDescriptionLibObj, mEvolutionDescription,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

       // invoke the utility function
  std::vector<QuantLib::Size> returnValue = QuantLib::terminalMeasure(
      EvolutionDescriptionLibObj
   );


  mReturnValue = QuantLibAddin::convertVector<QuantLib::Size, long>(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void TerminalMeasureWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::TerminalMeasure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("EvolutionDescription is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strEvolutionDescription(info[0]->ToString());
  string EvolutionDescriptionCpp(strdup(*strEvolutionDescription));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new TerminalMeasureWorker(
    callback
    ,EvolutionDescriptionCpp
  ));

}

//TerminalMeasureWorker::~TerminalMeasureWorker(){
//
//}

//void TerminalMeasureWorker::Destroy(){
//
//}

void MoneyMarketMeasureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionDescriptionLibObj, mEvolutionDescription,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)

       // invoke the utility function
  std::vector<QuantLib::Size> returnValue = QuantLib::moneyMarketMeasure(
      EvolutionDescriptionLibObj
   );


  mReturnValue = QuantLibAddin::convertVector<QuantLib::Size, long>(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MoneyMarketMeasureWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MoneyMarketMeasure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("EvolutionDescription is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strEvolutionDescription(info[0]->ToString());
  string EvolutionDescriptionCpp(strdup(*strEvolutionDescription));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MoneyMarketMeasureWorker(
    callback
    ,EvolutionDescriptionCpp
  ));

}

//MoneyMarketMeasureWorker::~MoneyMarketMeasureWorker(){
//
//}

//void MoneyMarketMeasureWorker::Destroy(){
//
//}

void MoneyMarketPlusMeasureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionDescriptionLibObj, mEvolutionDescription,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Size OffsetLib;
  QuantLibAddin::cppToLibrary(mOffset, OffsetLib);

       // invoke the utility function
  std::vector<QuantLib::Size> returnValue = QuantLib::moneyMarketPlusMeasure(
      EvolutionDescriptionLibObj
      ,
       OffsetLib
   );


  mReturnValue = QuantLibAddin::convertVector<QuantLib::Size, long>(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void MoneyMarketPlusMeasureWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::MoneyMarketPlusMeasure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("EvolutionDescription is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Offset is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strEvolutionDescription(info[0]->ToString());
  string EvolutionDescriptionCpp(strdup(*strEvolutionDescription));

  // convert js argument to c++ type
  long OffsetCpp = Nan::To<int32_t>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new MoneyMarketPlusMeasureWorker(
    callback
    ,EvolutionDescriptionCpp
    ,OffsetCpp
  ));

}

//MoneyMarketPlusMeasureWorker::~MoneyMarketPlusMeasureWorker(){
//
//}

//void MoneyMarketPlusMeasureWorker::Destroy(){
//
//}

void IsInTerminalMeasureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionDescriptionLibObj, mEvolutionDescription,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)


  // convert input datatypes to QuantLib datatypes
  std::vector<long> NumerairesCpp;
  std::vector<QuantLib::Size> NumerairesLib =
      QuantLibAddin::convertVector<long, QuantLib::Size>(NumerairesCpp);

       // invoke the utility function
  mReturnValue = QuantLib::isInTerminalMeasure(
      EvolutionDescriptionLibObj
      ,
       NumerairesLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IsInTerminalMeasureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IsInTerminalMeasure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("EvolutionDescription is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Numeraires is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strEvolutionDescription(info[0]->ToString());
  string EvolutionDescriptionCpp(strdup(*strEvolutionDescription));

  // convert js argument to c++ type
  std::vector<long>NumerairesCpp;

  Local<Array> NumerairesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < NumerairesArray->Length(); i++){
    NumerairesCpp.push_back(Nan::To<int32_t>(Nan::Get(NumerairesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IsInTerminalMeasureWorker(
    callback
    ,EvolutionDescriptionCpp
    ,NumerairesCpp
  ));

}

//IsInTerminalMeasureWorker::~IsInTerminalMeasureWorker(){
//
//}

//void IsInTerminalMeasureWorker::Destroy(){
//
//}

void IsInMoneyMarketMeasureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionDescriptionLibObj, mEvolutionDescription,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)


  // convert input datatypes to QuantLib datatypes
  std::vector<long> NumerairesCpp;
  std::vector<QuantLib::Size> NumerairesLib =
      QuantLibAddin::convertVector<long, QuantLib::Size>(NumerairesCpp);

       // invoke the utility function
  mReturnValue = QuantLib::isInMoneyMarketMeasure(
      EvolutionDescriptionLibObj
      ,
       NumerairesLib
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IsInMoneyMarketMeasureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IsInMoneyMarketMeasure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("EvolutionDescription is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Numeraires is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strEvolutionDescription(info[0]->ToString());
  string EvolutionDescriptionCpp(strdup(*strEvolutionDescription));

  // convert js argument to c++ type
  std::vector<long>NumerairesCpp;

  Local<Array> NumerairesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < NumerairesArray->Length(); i++){
    NumerairesCpp.push_back(Nan::To<int32_t>(Nan::Get(NumerairesArray, i).ToLocalChecked()).FromJust());
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IsInMoneyMarketMeasureWorker(
    callback
    ,EvolutionDescriptionCpp
    ,NumerairesCpp
  ));

}

//IsInMoneyMarketMeasureWorker::~IsInMoneyMarketMeasureWorker(){
//
//}

//void IsInMoneyMarketMeasureWorker::Destroy(){
//
//}

void IsInMoneyMarketPlusMeasureWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_UNDERLYING(EvolutionDescriptionLibObj, mEvolutionDescription,
      QuantLibAddin::EvolutionDescription, QuantLib::EvolutionDescription)


  // convert input datatypes to QuantLib datatypes
  std::vector<long> NumerairesCpp;
  std::vector<QuantLib::Size> NumerairesLib =
      QuantLibAddin::convertVector<long, QuantLib::Size>(NumerairesCpp);

       // invoke the utility function
  mReturnValue = QuantLib::isInMoneyMarketPlusMeasure(
      EvolutionDescriptionLibObj
      ,
       NumerairesLib
      ,
       mOffset
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void IsInMoneyMarketPlusMeasureWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Boolean>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::IsInMoneyMarketPlusMeasure) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("EvolutionDescription is required.");
  }
  if (info.Length() == 1 || !info[1]->IsArray()) {
      return Nan::ThrowError("Numeraires is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Offset is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strEvolutionDescription(info[0]->ToString());
  string EvolutionDescriptionCpp(strdup(*strEvolutionDescription));

  // convert js argument to c++ type
  std::vector<long>NumerairesCpp;

  Local<Array> NumerairesArray = info[1].As<Array>();
  for (unsigned int i = 0; i < NumerairesArray->Length(); i++){
    NumerairesCpp.push_back(Nan::To<int32_t>(Nan::Get(NumerairesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  long OffsetCpp = Nan::To<int32_t>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new IsInMoneyMarketPlusMeasureWorker(
    callback
    ,EvolutionDescriptionCpp
    ,NumerairesCpp
    ,OffsetCpp
  ));

}

//IsInMoneyMarketPlusMeasureWorker::~IsInMoneyMarketPlusMeasureWorker(){
//
//}

//void IsInMoneyMarketPlusMeasureWorker::Destroy(){
//
//}
 