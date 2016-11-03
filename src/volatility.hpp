/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef volatility_h
#define volatility_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class PiecewiseConstantAbcdVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mA;
    double mB;
    double mC;
    double mD;
    long mResetIndex;
    std::vector<double> mRateTimes;

    string mReturnValue;

    string mError;

    PiecewiseConstantAbcdVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double A
      ,double B
      ,double C
      ,double D
      ,long ResetIndex
      ,std::vector<double> RateTimes
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mA(A)
      ,mB(B)
      ,mC(C)
      ,mD(D)
      ,mResetIndex(ResetIndex)
      ,mRateTimes(RateTimes)
      {

      };

    //~PiecewiseConstantAbcdVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelLmExtLinearExponentialVolModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mFixingTimes;
    double mA;
    double mB;
    double mC;
    double mD;

    string mReturnValue;

    string mError;

    MarketModelLmExtLinearExponentialVolModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> FixingTimes
      ,double A
      ,double B
      ,double C
      ,double D
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFixingTimes(FixingTimes)
      ,mA(A)
      ,mB(B)
      ,mC(C)
      ,mD(D)
      {

      };

    //~MarketModelLmExtLinearExponentialVolModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantVarianceVariancesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    PiecewiseConstantVarianceVariancesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseConstantVarianceVariancesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantVarianceVolatilitiesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    PiecewiseConstantVarianceVolatilitiesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseConstantVarianceVolatilitiesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantVarianceRateTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    PiecewiseConstantVarianceRateTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseConstantVarianceRateTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantVarianceVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mTimeIndex;

    double mReturnValue;

    string mError;

    PiecewiseConstantVarianceVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long TimeIndex
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeIndex(TimeIndex)
      {

      };

    //~PiecewiseConstantVarianceVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantVarianceVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mTimeIndex;

    double mReturnValue;

    string mError;

    PiecewiseConstantVarianceVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long TimeIndex
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeIndex(TimeIndex)
      {

      };

    //~PiecewiseConstantVarianceVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantVarianceTotalVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mTimeIndex;

    double mReturnValue;

    string mError;

    PiecewiseConstantVarianceTotalVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long TimeIndex
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeIndex(TimeIndex)
      {

      };

    //~PiecewiseConstantVarianceTotalVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantVarianceTotalVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mTimeIndex;

    double mReturnValue;

    string mError;

    PiecewiseConstantVarianceTotalVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long TimeIndex
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeIndex(TimeIndex)
      {

      };

    //~PiecewiseConstantVarianceTotalVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
