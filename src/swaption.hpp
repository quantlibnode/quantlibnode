/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef swaption_h
#define swaption_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class SwaptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mVanillaSwap;
    string mExercise;
    string mSettlementType;

    string mReturnValue;

    string mError;

    SwaptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string VanillaSwap
      ,string Exercise
      ,string SettlementType
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mVanillaSwap(VanillaSwap)
      ,mExercise(Exercise)
      ,mSettlementType(SettlementType)
      {

      };

    //~SwaptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MakeSwaptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSwapIndex;
    string mOptionTenor;
    double mStrike;
    string mPricingEngineID;

    string mReturnValue;

    string mError;

    MakeSwaptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string SwapIndex
      ,string OptionTenor
      ,double Strike
      ,string PricingEngineID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwapIndex(SwapIndex)
      ,mOptionTenor(OptionTenor)
      ,mStrike(Strike)
      ,mPricingEngineID(PricingEngineID)
      {

      };

    //~MakeSwaptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionTypeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SwaptionTypeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwaptionTypeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionSettlementTypeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SwaptionSettlementTypeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwaptionSettlementTypeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionImpliedVolatilityWorker : public Nan::AsyncWorker {
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

    SwaptionImpliedVolatilityWorker(
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

    //~SwaptionImpliedVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
