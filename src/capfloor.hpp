// This is a generated file, modify: generate/templates/class_header.h

#ifndef capfloor_h
#define capfloor_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class CapFloorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionType;
    string mLegID;
    std::vector<double> mStrikes;

    string mReturnValue;

    string mError;

    CapFloorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionType
      ,string LegID
      ,std::vector<double> Strikes
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionType(OptionType)
      ,mLegID(LegID)
      ,mStrikes(Strikes)
      {

      };

    //~CapFloorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MakeCapFloorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionType;
    string mLength;
    string mIborIndex;
    double mStrike;
    string mForwardStart;
    string mPricingEngineID;

    string mReturnValue;

    string mError;

    MakeCapFloorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionType
      ,string Length
      ,string IborIndex
      ,double Strike
      ,string ForwardStart
      ,string PricingEngineID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionType(OptionType)
      ,mLength(Length)
      ,mIborIndex(IborIndex)
      ,mStrike(Strike)
      ,mForwardStart(ForwardStart)
      ,mPricingEngineID(PricingEngineID)
      {

      };

    //~MakeCapFloorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTypeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    CapFloorTypeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorTypeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorCapRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CapFloorCapRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorCapRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorFloorRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CapFloorFloorRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorFloorRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorAtmRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mYieldCurve;

    double mReturnValue;

    string mError;

    CapFloorAtmRateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~CapFloorAtmRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorStartDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    CapFloorStartDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorStartDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorMaturityDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    CapFloorMaturityDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorMaturityDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorImpliedVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mPrice;
    ObjectHandler::property_t mYieldCurve;
    double mGuess;
    double mAccuracy;
    ObjectHandler::property_t mMaxIter;
    double mMinVol;
    double mMaxVol;
    double mDisplacement;

    double mReturnValue;

    string mError;

    CapFloorImpliedVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Price
      ,ObjectHandler::property_t YieldCurve
      ,double Guess
      ,double Accuracy
      ,ObjectHandler::property_t MaxIter
      ,double MinVol
      ,double MaxVol
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPrice(Price)
      ,mYieldCurve(YieldCurve)
      ,mGuess(Guess)
      ,mAccuracy(Accuracy)
      ,mMaxIter(MaxIter)
      ,mMinVol(MinVol)
      ,mMaxVol(MaxVol)
      ,mDisplacement(Displacement)
      {

      };

    //~CapFloorImpliedVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorLegAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    CapFloorLegAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAfterDate(AfterDate)
      {

      };

    //~CapFloorLegAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
