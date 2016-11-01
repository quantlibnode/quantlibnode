// This is a generated file, modify: generate/templates/class_content.cc

#include <nan.h>
#include <string.h>

#include "volatilities.hpp"

#include <qlo/qladdindefines.hpp>
#include <qlo/indexes/interestrateindex.hpp>
#include <qlo/volatilities.hpp>
#include <ql/math/interpolations/sabrinterpolation.hpp>
#include <ql/termstructures/volatility/equityfx/blackconstantvol.hpp>
#include <ql/termstructures/volatility/equityfx/blackvariancesurface.hpp>
#include <ql/experimental/volatility/abcdatmvolcurve.hpp>
#include <ql/experimental/volatility/sabrvolsurface.hpp>
 #include <oh/objecthandler.hpp>
#include <oh/conversions/getobjectvector.hpp>
#include <qlo/valueobjects/vo_all.hpp>
#include <qlo/conversions/all.hpp>
#include "../loop.hpp"


void BlackConstantVolWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackConstantVol(
          mObjectID,
          mSettlementDate,
          mCalendar,
          mVolatility,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackConstantVol(
          valueObject,
          SettlementDateLib,
          CalendarEnum,
          mVolatility,
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

void BlackConstantVolWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackConstantVol) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Volatility is required.");
  }
  if (info.Length() == 4 || !info[4]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[2]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  double VolatilityCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[4]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackConstantVolWorker(
    callback
    ,ObjectIDCpp
    ,SettlementDateCpp
    ,CalendarCpp
    ,VolatilityCpp
    ,DayCounterCpp
  ));

}

//BlackConstantVolWorker::~BlackConstantVolWorker(){
//
//}

//BlackConstantVolWorker::Destroy(){
//
//}

void BlackVarianceSurfaceWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Date SettlementDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mSettlementDate, "SettlementDate");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Date> DatesLib = ObjectHandler::vector::convert2<QuantLib::Date>(
      mDates, "Dates");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Matrix VolatilitiesLib = QuantLibAddin::vvToQlMatrix(mVolatilities);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlBlackVarianceSurface(
          mObjectID,
          mSettlementDate,
          mCalendar,
          mDates,
          mStrikes,
          mVolatilities,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::BlackVarianceSurface(
          valueObject,
          SettlementDateLib,
          CalendarEnum,
          DatesLib,
          mStrikes,
          VolatilitiesLib,
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

void BlackVarianceSurfaceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackVarianceSurface) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("Dates is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("Strikes is required.");
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
  ObjectHandler::property_t SettlementDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[2]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>DatesCpp;

  Local<Array> DatesArray = info[3].As<Array>();
  for (unsigned int i = 0; i < DatesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(Nan::Get(DatesArray, i).ToLocalChecked()).FromJust()));
    DatesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>StrikesCpp;

  Local<Array> StrikesArray = info[4].As<Array>();
  for (unsigned int i = 0; i < StrikesArray->Length(); i++){
    StrikesCpp.push_back(Nan::To<double>(Nan::Get(StrikesArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector< std::vector<double> >VolatilitiesCpp;

  Local<Array> VolatilitiesMatrix = info[5].As<Array>();
  for (unsigned int i = 0; i < VolatilitiesMatrix->Length(); i++){
	  Local<Array> VolatilitiesArray = VolatilitiesMatrix->Get(i).As<Array>();
	  std::vector<double> tmp;
	  for (unsigned int j = 0; j < VolatilitiesArray->Length(); j++){
		  tmp.push_back(Nan::To<double>(Nan::Get(VolatilitiesArray, j).ToLocalChecked()).FromJust());
	  }
	  VolatilitiesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[6]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackVarianceSurfaceWorker(
    callback
    ,ObjectIDCpp
    ,SettlementDateCpp
    ,CalendarCpp
    ,DatesCpp
    ,StrikesCpp
    ,VolatilitiesCpp
    ,DayCounterCpp
  ));

}

//BlackVarianceSurfaceWorker::~BlackVarianceSurfaceWorker(){
//
//}

//BlackVarianceSurfaceWorker::Destroy(){
//
//}

void AbcdAtmVolCurveWorker::Execute(){

  try{

  // convert input datatypes to QuantLib datatypes
  QuantLib::Natural SettlementDaysLib = ObjectHandler::convert2<long>(
      mSettlementDays, "SettlementDays", QuantLib::Null<QuantLib::Natural>());


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::Calendar CalendarEnum =
      ObjectHandler::Create<QuantLib::Calendar>()(mCalendar);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> OptionTenorsLib;


  // convert object IDs into library objects
  std::vector< QuantLib::Handle<QuantLib::Quote> > VolatilitiesQuotesLibObj =
      ObjectHandler::vector::convert2< QuantLib::Handle<QuantLib::Quote> >(mVolatilitiesQuotes, "VolatilitiesQuotes");


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::BusinessDayConvention ConventionEnum =
      ObjectHandler::Create<QuantLib::BusinessDayConvention>()(mConvention);


  // convert input datatypes to QuantLib enumerated datatypes
  QuantLib::DayCounter DayCounterEnum =
      ObjectHandler::Create<QuantLib::DayCounter>()(mDayCounter);

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlAbcdAtmVolCurve(
          mObjectID,
          mSettlementDays,
          mCalendar,
          mOptionTenors,
          mVolatilitiesQuotes,
          mInclusionInInterpolation,
          mConvention,
          mDayCounter,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::AbcdAtmVolCurve(
          valueObject,
          SettlementDaysLib,
          CalendarEnum,
          OptionTenorsLib,
          VolatilitiesQuotesLibObj,
          mInclusionInInterpolation,
          ConventionEnum,
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

void AbcdAtmVolCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdAtmVolCurve) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsString()) {
      return Nan::ThrowError("Calendar is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("OptionTenors is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("VolatilitiesQuotes is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("InclusionInInterpolation is required.");
  }
  if (info.Length() == 6 || !info[6]->IsString()) {
      return Nan::ThrowError("Convention is required.");
  }
  if (info.Length() == 7 || !info[7]->IsString()) {
      return Nan::ThrowError("DayCounter is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t SettlementDaysCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  String::Utf8Value strCalendar(info[2]->ToString());
  string CalendarCpp(strdup(*strCalendar));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionTenorsCpp;

  Local<Array> OptionTenorsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < OptionTenorsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(OptionTenorsArray, i).ToLocalChecked()).FromJust()));
    OptionTenorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>VolatilitiesQuotesCpp;

  Local<Array> VolatilitiesQuotesArray = info[4].As<Array>();
  for (unsigned int i = 0; i < VolatilitiesQuotesArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(VolatilitiesQuotesArray, i).ToLocalChecked()).FromJust()));
    VolatilitiesQuotesCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<bool>InclusionInInterpolationCpp;

  Local<Array> InclusionInInterpolationArray = info[5].As<Array>();
  for (unsigned int i = 0; i < InclusionInInterpolationArray->Length(); i++){
    InclusionInInterpolationCpp.push_back(Nan::To<bool>(Nan::Get(InclusionInInterpolationArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  String::Utf8Value strConvention(info[6]->ToString());
  string ConventionCpp(strdup(*strConvention));

  // convert js argument to c++ type
  String::Utf8Value strDayCounter(info[7]->ToString());
  string DayCounterCpp(strdup(*strDayCounter));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[8].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveWorker(
    callback
    ,ObjectIDCpp
    ,SettlementDaysCpp
    ,CalendarCpp
    ,OptionTenorsCpp
    ,VolatilitiesQuotesCpp
    ,InclusionInInterpolationCpp
    ,ConventionCpp
    ,DayCounterCpp
  ));

}

//AbcdAtmVolCurveWorker::~AbcdAtmVolCurveWorker(){
//
//}

//AbcdAtmVolCurveWorker::Destroy(){
//
//}

void SabrVolSurfaceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(InterestRateIndexLibObjPtr, mInterestRateIndex,
      QuantLibAddin::InterestRateIndex, QuantLib::InterestRateIndex)


  // convert object IDs into library objects
  OH_GET_OBJECT(BlackAtmVolCurveCoerce, mBlackAtmVolCurve, ObjectHandler::Object)
  QuantLib::Handle<QuantLib::BlackAtmVolCurve> BlackAtmVolCurveLibObj =
      QuantLibAddin::CoerceHandle<
          QuantLibAddin::BlackAtmVolCurve,
          QuantLib::BlackAtmVolCurve>()(
              BlackAtmVolCurveCoerce);


  // convert input datatypes to QuantLib datatypes
  std::vector<QuantLib::Period> OptionTenorsLib;


  // convert object IDs into library objects
  std::vector< std::vector< QuantLib::Handle<QuantLib::Quote> > > VolatilitiesQuotesLibObj =
      ObjectHandler::matrix::convert2< QuantLib::Handle<QuantLib::Quote> >(mVolatilitiesQuotes, "VolatilitiesQuotes");

 
    // Construct the Value Object
    boost::shared_ptr<ObjectHandler::ValueObject> valueObject(
      new QuantLibAddin::ValueObjects::qlSabrVolSurface(
          mObjectID,
          mInterestRateIndex,
          mBlackAtmVolCurve,
          mOptionTenors,
          mAtmRateSpreads,
          mVolatilitiesQuotes,
          false
      ));

    // Construct the Object
    boost::shared_ptr<ObjectHandler::Object> object(
      new QuantLibAddin::SabrVolSurface(
          valueObject,
          InterestRateIndexLibObjPtr,
          BlackAtmVolCurveLibObj,
          OptionTenorsLib,
          mAtmRateSpreads,
          VolatilitiesQuotesLibObj,
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

void SabrVolSurfaceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrVolSurface) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("InterestRateIndex is required.");
  }
  if (info.Length() == 3 || !info[3]->IsArray()) {
      return Nan::ThrowError("OptionTenors is required.");
  }
  if (info.Length() == 4 || !info[4]->IsArray()) {
      return Nan::ThrowError("AtmRateSpreads is required.");
  }
  if (info.Length() == 5 || !info[5]->IsArray()) {
      return Nan::ThrowError("VolatilitiesQuotes is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strInterestRateIndex(info[1]->ToString());
  string InterestRateIndexCpp(strdup(*strInterestRateIndex));

  // convert js argument to c++ type
  ObjectHandler::property_t BlackAtmVolCurveCpp =
      ObjectHandler::property_t(static_cast<double>(Nan::To<double>(info[2]).FromJust()));

  // convert js argument to c++ type
  std::vector<ObjectHandler::property_t>OptionTenorsCpp;

  Local<Array> OptionTenorsArray = info[3].As<Array>();
  for (unsigned int i = 0; i < OptionTenorsArray->Length(); i++){
    ObjectHandler::property_t tmp =
        ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(OptionTenorsArray, i).ToLocalChecked()).FromJust()));
    OptionTenorsCpp.push_back(tmp);
  }

  // convert js argument to c++ type
  std::vector<double>AtmRateSpreadsCpp;

  Local<Array> AtmRateSpreadsArray = info[4].As<Array>();
  for (unsigned int i = 0; i < AtmRateSpreadsArray->Length(); i++){
    AtmRateSpreadsCpp.push_back(Nan::To<double>(Nan::Get(AtmRateSpreadsArray, i).ToLocalChecked()).FromJust());
  }

  // convert js argument to c++ type
  std::vector< std::vector<ObjectHandler::property_t> >VolatilitiesQuotesCpp;

  Local<Array> VolatilitiesQuotesMatrix = info[5].As<Array>();
  for (unsigned int i = 0; i < VolatilitiesQuotesMatrix->Length(); i++){
	  Local<Array> VolatilitiesQuotesArray = VolatilitiesQuotesMatrix->Get(i).As<Array>();
	  std::vector<ObjectHandler::property_t> tmp;
	  for (unsigned int j = 0; j < VolatilitiesQuotesArray->Length(); j++){
      ObjectHandler::property_t temp =
          ObjectHandler::property_t(static_cast<double>(Nan::To<double>(Nan::Get(VolatilitiesQuotesArray, j).ToLocalChecked()).FromJust()));
		  tmp.push_back(temp);
	  }
	  VolatilitiesQuotesCpp.push_back(tmp);
  }

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[6].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SabrVolSurfaceWorker(
    callback
    ,ObjectIDCpp
    ,InterestRateIndexCpp
    ,BlackAtmVolCurveCpp
    ,OptionTenorsCpp
    ,AtmRateSpreadsCpp
    ,VolatilitiesQuotesCpp
  ));

}

//SabrVolSurfaceWorker::~SabrVolSurfaceWorker(){
//
//}

//SabrVolSurfaceWorker::Destroy(){
//
//}

void VolatilityTermStructureBusinessDayConventionWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VolatilityTermStructure, QuantLib::VolatilityTermStructure)

     
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

void VolatilityTermStructureBusinessDayConventionWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VolatilityTermStructureBusinessDayConvention) {

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
  Nan::AsyncQueueWorker(new VolatilityTermStructureBusinessDayConventionWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VolatilityTermStructureBusinessDayConventionWorker::~VolatilityTermStructureBusinessDayConventionWorker(){
//
//}

//VolatilityTermStructureBusinessDayConventionWorker::Destroy(){
//
//}

void VolatilityTermStructureOptionDateFromTenorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VolatilityTermStructure, QuantLib::VolatilityTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period TenorLib;
  QuantLibAddin::cppToLibrary(mTenor, TenorLib);

     
  // invoke the member function
  QuantLib::Date returnValue = ObjectIDLibObjPtr->optionDateFromTenor(
        TenorLib
       );


  mReturnValue = QuantLibAddin::libraryToScalar(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VolatilityTermStructureOptionDateFromTenorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VolatilityTermStructureOptionDateFromTenor) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("Tenor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strTenor(info[1]->ToString());
  string TenorCpp(strdup(*strTenor));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VolatilityTermStructureOptionDateFromTenorWorker(
    callback
    ,ObjectIDCpp
    ,TenorCpp
  ));

}

//VolatilityTermStructureOptionDateFromTenorWorker::~VolatilityTermStructureOptionDateFromTenorWorker(){
//
//}

//VolatilityTermStructureOptionDateFromTenorWorker::Destroy(){
//
//}

void VolatilityTermStructureMinStrikeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VolatilityTermStructure, QuantLib::VolatilityTermStructure)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->minStrike(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VolatilityTermStructureMinStrikeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VolatilityTermStructureMinStrike) {

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
  Nan::AsyncQueueWorker(new VolatilityTermStructureMinStrikeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VolatilityTermStructureMinStrikeWorker::~VolatilityTermStructureMinStrikeWorker(){
//
//}

//VolatilityTermStructureMinStrikeWorker::Destroy(){
//
//}

void VolatilityTermStructureMaxStrikeWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::VolatilityTermStructure, QuantLib::VolatilityTermStructure)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->maxStrike(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VolatilityTermStructureMaxStrikeWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::VolatilityTermStructureMaxStrike) {

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
  Nan::AsyncQueueWorker(new VolatilityTermStructureMaxStrikeWorker(
    callback
    ,ObjectIDCpp
  ));

}

//VolatilityTermStructureMaxStrikeWorker::~VolatilityTermStructureMaxStrikeWorker(){
//
//}

//VolatilityTermStructureMaxStrikeWorker::Destroy(){
//
//}

void BlackAtmVolCurveAtmVolWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackAtmVolCurve, QuantLib::BlackAtmVolCurve)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->atmVol(
        OptionDateLib
        ,
         mAllowExtrapolation
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackAtmVolCurveAtmVolWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackAtmVolCurveAtmVol) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackAtmVolCurveAtmVolWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackAtmVolCurveAtmVolWorker::~BlackAtmVolCurveAtmVolWorker(){
//
//}

//BlackAtmVolCurveAtmVolWorker::Destroy(){
//
//}

void BlackAtmVolCurveAtmVol2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackAtmVolCurve, QuantLib::BlackAtmVolCurve)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period OptionTenorLib;
  QuantLibAddin::cppToLibrary(mOptionTenor, OptionTenorLib);

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->atmVol(
        OptionTenorLib
        ,
         mAllowExtrapolation
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackAtmVolCurveAtmVol2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackAtmVolCurveAtmVol2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strOptionTenor(info[1]->ToString());
  string OptionTenorCpp(strdup(*strOptionTenor));

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackAtmVolCurveAtmVol2Worker(
    callback
    ,ObjectIDCpp
    ,OptionTenorCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackAtmVolCurveAtmVol2Worker::~BlackAtmVolCurveAtmVol2Worker(){
//
//}

//BlackAtmVolCurveAtmVol2Worker::Destroy(){
//
//}

void BlackAtmVolCurveAtmVol3Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackAtmVolCurve, QuantLib::BlackAtmVolCurve)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->atmVol(
        mOptionTime
        ,
         mAllowExtrapolation
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackAtmVolCurveAtmVol3Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackAtmVolCurveAtmVol3) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("OptionTime is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double OptionTimeCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackAtmVolCurveAtmVol3Worker(
    callback
    ,ObjectIDCpp
    ,OptionTimeCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackAtmVolCurveAtmVol3Worker::~BlackAtmVolCurveAtmVol3Worker(){
//
//}

//BlackAtmVolCurveAtmVol3Worker::Destroy(){
//
//}

void BlackAtmVolCurveAtmVarianceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackAtmVolCurve, QuantLib::BlackAtmVolCurve)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->atmVariance(
        OptionDateLib
        ,
         mAllowExtrapolation
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackAtmVolCurveAtmVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackAtmVolCurveAtmVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackAtmVolCurveAtmVarianceWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackAtmVolCurveAtmVarianceWorker::~BlackAtmVolCurveAtmVarianceWorker(){
//
//}

//BlackAtmVolCurveAtmVarianceWorker::Destroy(){
//
//}

void BlackAtmVolCurveAtmVariance2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackAtmVolCurve, QuantLib::BlackAtmVolCurve)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period OptionTenorLib;
  QuantLibAddin::cppToLibrary(mOptionTenor, OptionTenorLib);

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->atmVariance(
        OptionTenorLib
        ,
         mAllowExtrapolation
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackAtmVolCurveAtmVariance2Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackAtmVolCurveAtmVariance2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strOptionTenor(info[1]->ToString());
  string OptionTenorCpp(strdup(*strOptionTenor));

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackAtmVolCurveAtmVariance2Worker(
    callback
    ,ObjectIDCpp
    ,OptionTenorCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackAtmVolCurveAtmVariance2Worker::~BlackAtmVolCurveAtmVariance2Worker(){
//
//}

//BlackAtmVolCurveAtmVariance2Worker::Destroy(){
//
//}

void BlackAtmVolCurveAtmVariance3Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackAtmVolCurve, QuantLib::BlackAtmVolCurve)

     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->atmVariance(
        mOptionTime
        ,
         mAllowExtrapolation
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackAtmVolCurveAtmVariance3Worker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackAtmVolCurveAtmVariance3) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("OptionTime is required.");
  }
  if (info.Length() == 2 || !info[2]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double OptionTimeCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[2]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[3].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackAtmVolCurveAtmVariance3Worker(
    callback
    ,ObjectIDCpp
    ,OptionTimeCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackAtmVolCurveAtmVariance3Worker::~BlackAtmVolCurveAtmVariance3Worker(){
//
//}

//BlackAtmVolCurveAtmVariance3Worker::Destroy(){
//
//}

void BlackVolTermStructureBlackVolWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackVolTermStructure, QuantLib::BlackVolTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib datatypes
     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->blackVol(
        OptionDateLib
        ,
         mStrike
        ,
         mAllowExtrapolation
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackVolTermStructureBlackVolWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackVolTermStructureBlackVol) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 3 || !info[3]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackVolTermStructureBlackVolWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,StrikeCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackVolTermStructureBlackVolWorker::~BlackVolTermStructureBlackVolWorker(){
//
//}

//BlackVolTermStructureBlackVolWorker::Destroy(){
//
//}

void BlackVolTermStructureBlackVarianceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackVolTermStructure, QuantLib::BlackVolTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib datatypes
     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->blackVariance(
        OptionDateLib
        ,
         mStrike
        ,
         mAllowExtrapolation
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackVolTermStructureBlackVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackVolTermStructureBlackVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 3 || !info[3]->IsBoolean()) {
      return Nan::ThrowError("AllowExtrapolation is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[3]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[4].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackVolTermStructureBlackVarianceWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
    ,StrikeCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackVolTermStructureBlackVarianceWorker::~BlackVolTermStructureBlackVarianceWorker(){
//
//}

//BlackVolTermStructureBlackVarianceWorker::Destroy(){
//
//}

void BlackVolTermStructureBlackForwardVolWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackVolTermStructure, QuantLib::BlackVolTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ForwardDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mForwardDate, "ForwardDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib datatypes
     
  // invoke the member function
  mReturnValue = ObjectIDLibObjPtr->blackForwardVol(
        ForwardDateLib
        ,
         OptionDateLib
        ,
         mStrike
        ,
         mAllowExtrapolation
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackVolTermStructureBlackForwardVolWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackVolTermStructureBlackForwardVol) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
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
  ObjectHandler::property_t ForwardDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackVolTermStructureBlackForwardVolWorker(
    callback
    ,ObjectIDCpp
    ,ForwardDateCpp
    ,OptionDateCpp
    ,StrikeCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackVolTermStructureBlackForwardVolWorker::~BlackVolTermStructureBlackForwardVolWorker(){
//
//}

//BlackVolTermStructureBlackForwardVolWorker::Destroy(){
//
//}

void BlackVolTermStructureBlackForwardVarianceWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::BlackVolTermStructure, QuantLib::BlackVolTermStructure)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date ForwardDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mForwardDate, "ForwardDate");


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");


  // convert input datatypes to QuantLib datatypes
     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->blackForwardVariance(
        ForwardDateLib
        ,
         OptionDateLib
        ,
         mStrike
        ,
         mAllowExtrapolation
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void BlackVolTermStructureBlackForwardVarianceWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::BlackVolTermStructureBlackForwardVariance) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
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
  ObjectHandler::property_t ForwardDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[2]).FromJust()));

  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  bool AllowExtrapolationCpp = Nan::To<bool>(info[4]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[5].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new BlackVolTermStructureBlackForwardVarianceWorker(
    callback
    ,ObjectIDCpp
    ,ForwardDateCpp
    ,OptionDateCpp
    ,StrikeCpp
    ,AllowExtrapolationCpp
  ));

}

//BlackVolTermStructureBlackForwardVarianceWorker::~BlackVolTermStructureBlackForwardVarianceWorker(){
//
//}

//BlackVolTermStructureBlackForwardVarianceWorker::Destroy(){
//
//}

void AbcdAtmVolCurveOptionTenorsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
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

void AbcdAtmVolCurveOptionTenorsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveOptionTenors) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveOptionTenorsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveOptionTenorsWorker::~AbcdAtmVolCurveOptionTenorsWorker(){
//
//}

//AbcdAtmVolCurveOptionTenorsWorker::Destroy(){
//
//}

void AbcdAtmVolCurveOptionTenorsInInterpolationWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Period> returnValue = ObjectIDLibObjPtr->optionTenorsInInterpolation(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveOptionTenorsInInterpolationWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveOptionTenorsInInterpolation) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveOptionTenorsInInterpolationWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveOptionTenorsInInterpolationWorker::~AbcdAtmVolCurveOptionTenorsInInterpolationWorker(){
//
//}

//AbcdAtmVolCurveOptionTenorsInInterpolationWorker::Destroy(){
//
//}

void AbcdAtmVolCurveOptionDatesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
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

void AbcdAtmVolCurveOptionDatesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveOptionDates) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveOptionDatesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveOptionDatesWorker::~AbcdAtmVolCurveOptionDatesWorker(){
//
//}

//AbcdAtmVolCurveOptionDatesWorker::Destroy(){
//
//}

void AbcdAtmVolCurveOptionTimesWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->optionTimes(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveOptionTimesWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveOptionTimes) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveOptionTimesWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveOptionTimesWorker::~AbcdAtmVolCurveOptionTimesWorker(){
//
//}

//AbcdAtmVolCurveOptionTimesWorker::Destroy(){
//
//}

void AbcdAtmVolCurveRmsErrorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->rmsError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveRmsErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveRmsError) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveRmsErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveRmsErrorWorker::~AbcdAtmVolCurveRmsErrorWorker(){
//
//}

//AbcdAtmVolCurveRmsErrorWorker::Destroy(){
//
//}

void AbcdAtmVolCurveMaxErrorWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->maxError(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveMaxErrorWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveMaxError) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveMaxErrorWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveMaxErrorWorker::~AbcdAtmVolCurveMaxErrorWorker(){
//
//}

//AbcdAtmVolCurveMaxErrorWorker::Destroy(){
//
//}

void AbcdAtmVolCurveAWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->a(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveAWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveA) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveAWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveAWorker::~AbcdAtmVolCurveAWorker(){
//
//}

//AbcdAtmVolCurveAWorker::Destroy(){
//
//}

void AbcdAtmVolCurveBWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->b(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveBWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveB) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveBWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveBWorker::~AbcdAtmVolCurveBWorker(){
//
//}

//AbcdAtmVolCurveBWorker::Destroy(){
//
//}

void AbcdAtmVolCurveCWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->c(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveCWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveC) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveCWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveCWorker::~AbcdAtmVolCurveCWorker(){
//
//}

//AbcdAtmVolCurveCWorker::Destroy(){
//
//}

void AbcdAtmVolCurveDWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->d(
      );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveDWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveD) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveDWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveDWorker::~AbcdAtmVolCurveDWorker(){
//
//}

//AbcdAtmVolCurveDWorker::Destroy(){
//
//}

void AbcdAtmVolCurveKatOptionTenorsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // loop on the input parameter and populate the return vector
  std::vector<QuantLib::Real> returnValue = ObjectIDLibObjPtr->k(
      );


  mReturnValue = QuantLibAddin::libraryToVector(returnValue);

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveKatOptionTenorsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveKatOptionTenors) {

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
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveKatOptionTenorsWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AbcdAtmVolCurveKatOptionTenorsWorker::~AbcdAtmVolCurveKatOptionTenorsWorker(){
//
//}

//AbcdAtmVolCurveKatOptionTenorsWorker::Destroy(){
//
//}

void AbcdAtmVolCurveKWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::AbcdAtmVolCurve, QuantLib::AbcdAtmVolCurve)

     
  // invoke the member function
  QuantLib::Real returnValue = ObjectIDLibObjPtr->k(
        mTime
       );


  mReturnValue = returnValue;

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AbcdAtmVolCurveKWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AbcdAtmVolCurveK) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Time is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  double TimeCpp = Nan::To<double>(info[1]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new AbcdAtmVolCurveKWorker(
    callback
    ,ObjectIDCpp
    ,TimeCpp
  ));

}

//AbcdAtmVolCurveKWorker::~AbcdAtmVolCurveKWorker(){
//
//}

//AbcdAtmVolCurveKWorker::Destroy(){
//
//}

void VolatilitySpreadsWorker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SabrVolSurface, QuantLib::SabrVolSurface)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Date OptionDateLib = ObjectHandler::convert2<QuantLib::Date>(
      mOptionDate, "OptionDate");

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->volatilitySpreads(
        OptionDateLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VolatilitySpreadsWorker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::VolatilitySpreads) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  ObjectHandler::property_t OptionDateCpp =
      ObjectHandler::property_t(static_cast<long>(Nan::To<int32_t>(info[1]).FromJust()));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VolatilitySpreadsWorker(
    callback
    ,ObjectIDCpp
    ,OptionDateCpp
  ));

}

//VolatilitySpreadsWorker::~VolatilitySpreadsWorker(){
//
//}

//VolatilitySpreadsWorker::Destroy(){
//
//}

void VolatilitySpreads2Worker::Execute(){

  try{

  // convert object IDs into library objects
  OH_GET_REFERENCE(ObjectIDLibObjPtr, mObjectID,
      QuantLibAddin::SabrVolSurface, QuantLib::SabrVolSurface)


  // convert input datatypes to QuantLib datatypes
  QuantLib::Period OptionTenorLib;
  QuantLibAddin::cppToLibrary(mOptionTenor, OptionTenorLib);

     
  // loop on the input parameter and populate the return vector
  mReturnValue = ObjectIDLibObjPtr->volatilitySpreads(
        OptionTenorLib
       );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void VolatilitySpreads2Worker::HandleOKCallback(){
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

NAN_METHOD(QuantLibNode::VolatilitySpreads2) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsString()) {
      return Nan::ThrowError("ObjectID is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
      return Nan::ThrowError("OptionTenor is required.");
  }
  // convert js argument to c++ type
  String::Utf8Value strObjectID(info[0]->ToString());
  string ObjectIDCpp(strdup(*strObjectID));

  // convert js argument to c++ type
  String::Utf8Value strOptionTenor(info[1]->ToString());
  string OptionTenorCpp(strdup(*strOptionTenor));

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[2].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new VolatilitySpreads2Worker(
    callback
    ,ObjectIDCpp
    ,OptionTenorCpp
  ));

}

//VolatilitySpreads2Worker::~VolatilitySpreads2Worker(){
//
//}

//VolatilitySpreads2Worker::Destroy(){
//
//}

void AtmCurveWorker::Execute(){

  try{
       // convert object IDs into library objects
  OH_GET_OBJECT(ObjectIDObjPtr, mObjectID, QuantLibAddin::SabrVolSurface)


  // invoke the member function
  mReturnValue = ObjectIDObjPtr->atmCurve(
      );

   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void AtmCurveWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<String>(mReturnValue).ToLocalChecked()
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::AtmCurve) {

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
  Nan::AsyncQueueWorker(new AtmCurveWorker(
    callback
    ,ObjectIDCpp
  ));

}

//AtmCurveWorker::~AtmCurveWorker(){
//
//}

//AtmCurveWorker::Destroy(){
//
//}

void SabrVolatilityWorker::Execute(){

  try{
       // invoke the utility function
  mReturnValue = QuantLib::sabrVolatility(
      mStrike
      ,
       mForward
      ,
       mExpTime
      ,
       mAlpha
      ,
       mBeta
      ,
       mNu
      ,
       mRho
     );
   }catch(const std::exception &e){
    mError = e.what();
  }catch (...){
    mError = "unkown error";
  }

}

void SabrVolatilityWorker::HandleOKCallback(){
  Nan::HandleScope scope;


  Local<v8::Value> argv[2] = {
		  Nan::New<String>(mError).ToLocalChecked(),
      Nan::New<Number>(mReturnValue)
	};

	callback->Call(2, argv);
}

NAN_METHOD(QuantLibNode::SabrVolatility) {

  // validate js arguments
  if (info.Length() == 0 || !info[0]->IsNumber()) {
      return Nan::ThrowError("Strike is required.");
  }
  if (info.Length() == 1 || !info[1]->IsNumber()) {
      return Nan::ThrowError("Forward is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
      return Nan::ThrowError("ExpTime is required.");
  }
  if (info.Length() == 3 || !info[3]->IsNumber()) {
      return Nan::ThrowError("Alpha is required.");
  }
  if (info.Length() == 4 || !info[4]->IsNumber()) {
      return Nan::ThrowError("Beta is required.");
  }
  if (info.Length() == 5 || !info[5]->IsNumber()) {
      return Nan::ThrowError("Nu is required.");
  }
  if (info.Length() == 6 || !info[6]->IsNumber()) {
      return Nan::ThrowError("Rho is required.");
  }
  // convert js argument to c++ type
  double StrikeCpp = Nan::To<double>(info[0]).FromJust();

  // convert js argument to c++ type
  double ForwardCpp = Nan::To<double>(info[1]).FromJust();

  // convert js argument to c++ type
  double ExpTimeCpp = Nan::To<double>(info[2]).FromJust();

  // convert js argument to c++ type
  double AlphaCpp = Nan::To<double>(info[3]).FromJust();

  // convert js argument to c++ type
  double BetaCpp = Nan::To<double>(info[4]).FromJust();

  // convert js argument to c++ type
  double NuCpp = Nan::To<double>(info[5]).FromJust();

  // convert js argument to c++ type
  double RhoCpp = Nan::To<double>(info[6]).FromJust();

 
  // declare callback
  Nan::Callback *callback = new Nan::Callback(info[7].As<Function>());
  // launch Async worker
  Nan::AsyncQueueWorker(new SabrVolatilityWorker(
    callback
    ,StrikeCpp
    ,ForwardCpp
    ,ExpTimeCpp
    ,AlphaCpp
    ,BetaCpp
    ,NuCpp
    ,RhoCpp
  ));

}

//SabrVolatilityWorker::~SabrVolatilityWorker(){
//
//}

//SabrVolatilityWorker::Destroy(){
//
//}
 