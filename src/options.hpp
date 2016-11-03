/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef options_h
#define options_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class BarrierOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mBarrierType;
    double mBarrier;
    double mRebate;
    string mPayoff;
    string mExercise;

    string mReturnValue;

    string mError;

    BarrierOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string BarrierType
      ,double Barrier
      ,double Rebate
      ,string Payoff
      ,string Exercise
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBarrierType(BarrierType)
      ,mBarrier(Barrier)
      ,mRebate(Rebate)
      ,mPayoff(Payoff)
      ,mExercise(Exercise)
      {

      };

    //~BarrierOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CaAsianOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mAverageType;
    string mPayoff;
    string mExercise;

    string mReturnValue;

    string mError;

    CaAsianOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string AverageType
      ,string Payoff
      ,string Exercise
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAverageType(AverageType)
      ,mPayoff(Payoff)
      ,mExercise(Exercise)
      {

      };

    //~CaAsianOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DaAsianOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mAverageType;
    double mRunningAccumulator;
    long mPastFixings;
    std::vector<ObjectHandler::property_t> mFixingDates;
    string mPayoff;
    string mExercise;

    string mReturnValue;

    string mError;

    DaAsianOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string AverageType
      ,double RunningAccumulator
      ,long PastFixings
      ,std::vector<ObjectHandler::property_t> FixingDates
      ,string Payoff
      ,string Exercise
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAverageType(AverageType)
      ,mRunningAccumulator(RunningAccumulator)
      ,mPastFixings(PastFixings)
      ,mFixingDates(FixingDates)
      ,mPayoff(Payoff)
      ,mExercise(Exercise)
      {

      };

    //~DaAsianOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DividendVanillaOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPayoff;
    string mExercise;
    std::vector<ObjectHandler::property_t> mDividendDates;
    std::vector<double> mDividends;

    string mReturnValue;

    string mError;

    DividendVanillaOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Payoff
      ,string Exercise
      ,std::vector<ObjectHandler::property_t> DividendDates
      ,std::vector<double> Dividends
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayoff(Payoff)
      ,mExercise(Exercise)
      ,mDividendDates(DividendDates)
      ,mDividends(Dividends)
      {

      };

    //~DividendVanillaOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ForwardVanillaOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mMoneyness;
    ObjectHandler::property_t mResetDate;
    string mPayoff;
    string mExercise;

    string mReturnValue;

    string mError;

    ForwardVanillaOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Moneyness
      ,ObjectHandler::property_t ResetDate
      ,string Payoff
      ,string Exercise
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mMoneyness(Moneyness)
      ,mResetDate(ResetDate)
      ,mPayoff(Payoff)
      ,mExercise(Exercise)
      {

      };

    //~ForwardVanillaOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPayoff;
    string mExercise;

    string mReturnValue;

    string mError;

    VanillaOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Payoff
      ,string Exercise
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayoff(Payoff)
      ,mExercise(Exercise)
      {

      };

    //~VanillaOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EuropeanOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPayoff;
    string mExercise;

    string mReturnValue;

    string mError;

    EuropeanOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Payoff
      ,string Exercise
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayoff(Payoff)
      ,mExercise(Exercise)
      {

      };

    //~EuropeanOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class QuantoVanillaOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPayoff;
    string mExercise;

    string mReturnValue;

    string mError;

    QuantoVanillaOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Payoff
      ,string Exercise
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayoff(Payoff)
      ,mExercise(Exercise)
      {

      };

    //~QuantoVanillaOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class QuantoForwardVanillaOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mMoneyness;
    ObjectHandler::property_t mResetDate;
    string mPayoff;
    string mExercise;

    string mReturnValue;

    string mError;

    QuantoForwardVanillaOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Moneyness
      ,ObjectHandler::property_t ResetDate
      ,string Payoff
      ,string Exercise
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mMoneyness(Moneyness)
      ,mResetDate(ResetDate)
      ,mPayoff(Payoff)
      ,mExercise(Exercise)
      {

      };

    //~QuantoForwardVanillaOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DeltaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    DeltaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~DeltaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DeltaForwardWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    DeltaForwardWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~DeltaForwardWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ElasticityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ElasticityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ElasticityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GammaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    GammaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~GammaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ThetaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ThetaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ThetaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ThetaPerDayWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ThetaPerDayWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ThetaPerDayWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VegaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VegaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VegaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RhoWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RhoWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RhoWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DividendRhoWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    DividendRhoWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~DividendRhoWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ItmCashProbabilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ItmCashProbabilityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ItmCashProbabilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
