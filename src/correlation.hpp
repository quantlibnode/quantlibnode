/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef correlation_h
#define correlation_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class MarketModelLmLinearExponentialCorrelationModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mSize;
    double mRho;
    double mBeta;
    long mFactors;

    string mReturnValue;

    string mError;

    MarketModelLmLinearExponentialCorrelationModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Size
      ,double Rho
      ,double Beta
      ,long Factors
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSize(Size)
      ,mRho(Rho)
      ,mBeta(Beta)
      ,mFactors(Factors)
      {

      };

    //~MarketModelLmLinearExponentialCorrelationModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HistoricalForwardRatesAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSequenceStats;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mEndDate;
    string mStep;
    string mIborIndex;
    string mInitialGap;
    string mHorizon;
    std::vector<string> mIborIndexes;
    std::vector<string> mSwapIndexes;
    string mDayCounter;
    string mTraitsID;
    string mInterpolatorID;
    double mBootstrapAccuracy;

    string mReturnValue;

    string mError;

    HistoricalForwardRatesAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string SequenceStats
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t EndDate
      ,string Step
      ,string IborIndex
      ,string InitialGap
      ,string Horizon
      ,std::vector<string> IborIndexes
      ,std::vector<string> SwapIndexes
      ,string DayCounter
      ,string TraitsID
      ,string InterpolatorID
      ,double BootstrapAccuracy
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSequenceStats(SequenceStats)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mStep(Step)
      ,mIborIndex(IborIndex)
      ,mInitialGap(InitialGap)
      ,mHorizon(Horizon)
      ,mIborIndexes(IborIndexes)
      ,mSwapIndexes(SwapIndexes)
      ,mDayCounter(DayCounter)
      ,mTraitsID(TraitsID)
      ,mInterpolatorID(InterpolatorID)
      ,mBootstrapAccuracy(BootstrapAccuracy)
      {

      };

    //~HistoricalForwardRatesAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HistoricalRatesAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSequenceStats;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mEndDate;
    string mStep;
    std::vector<string> mInterestRateIndexes;

    string mReturnValue;

    string mError;

    HistoricalRatesAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string SequenceStats
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t EndDate
      ,string Step
      ,std::vector<string> InterestRateIndexes
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSequenceStats(SequenceStats)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mStep(Step)
      ,mInterestRateIndexes(InterestRateIndexes)
      {

      };

    //~HistoricalRatesAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TimeHomogeneousForwardCorrelationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFwdCorrMatrix;
    std::vector<double> mRateTimes;

    string mReturnValue;

    string mError;

    TimeHomogeneousForwardCorrelationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > FwdCorrMatrix
      ,std::vector<double> RateTimes
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFwdCorrMatrix(FwdCorrMatrix)
      ,mRateTimes(RateTimes)
      {

      };

    //~TimeHomogeneousForwardCorrelationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ExponentialForwardCorrelationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;
    double mLongTermCorr;
    double mBeta;
    double mGamma;
    std::vector<double> mTimes;

    string mReturnValue;

    string mError;

    ExponentialForwardCorrelationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
      ,double LongTermCorr
      ,double Beta
      ,double Gamma
      ,std::vector<double> Times
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      ,mLongTermCorr(LongTermCorr)
      ,mBeta(Beta)
      ,mGamma(Gamma)
      ,mTimes(Times)
      {

      };

    //~ExponentialForwardCorrelationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CotSwapFromFwdCorrelationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mFwdCorr;
    string mCurveState;
    double mDisplacement;

    string mReturnValue;

    string mError;

    CotSwapFromFwdCorrelationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string FwdCorr
      ,string CurveState
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFwdCorr(FwdCorr)
      ,mCurveState(CurveState)
      ,mDisplacement(Displacement)
      {

      };

    //~CotSwapFromFwdCorrelationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HistoricalForwardRatesAnalysisSkippedDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    HistoricalForwardRatesAnalysisSkippedDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HistoricalForwardRatesAnalysisSkippedDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HistoricalForwardRatesAnalysisSkippedDatesErrorMessageWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    HistoricalForwardRatesAnalysisSkippedDatesErrorMessageWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HistoricalForwardRatesAnalysisSkippedDatesErrorMessageWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HistoricalForwardRatesAnalysisFailedDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    HistoricalForwardRatesAnalysisFailedDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HistoricalForwardRatesAnalysisFailedDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HistoricalForwardRatesAnalysisFailedDatesErrorMessageWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    HistoricalForwardRatesAnalysisFailedDatesErrorMessageWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HistoricalForwardRatesAnalysisFailedDatesErrorMessageWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HistoricalForwardRatesAnalysisFixingPeriodsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    HistoricalForwardRatesAnalysisFixingPeriodsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HistoricalForwardRatesAnalysisFixingPeriodsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HistoricalRatesAnalysisSkippedDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    HistoricalRatesAnalysisSkippedDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HistoricalRatesAnalysisSkippedDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HistoricalRatesAnalysisSkippedDatesErrorMessageWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    HistoricalRatesAnalysisSkippedDatesErrorMessageWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HistoricalRatesAnalysisSkippedDatesErrorMessageWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantCorrelationCorrelationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mTimeIndex;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    PiecewiseConstantCorrelationCorrelationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long TimeIndex
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeIndex(TimeIndex)
      {

      };

    //~PiecewiseConstantCorrelationCorrelationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantCorrelationTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    PiecewiseConstantCorrelationTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseConstantCorrelationTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseConstantCorrelationNumberOfRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    PiecewiseConstantCorrelationNumberOfRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseConstantCorrelationNumberOfRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ExponentialCorrelationsWorker : public Nan::AsyncWorker {
  public:
    std::vector<double> mRateTimes;
    double mLongTermCorr;
    double mBeta;
    double mGamma;
    double mTime;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    ExponentialCorrelationsWorker(
      Nan::Callback *callback
      ,std::vector<double> RateTimes
      ,double LongTermCorr
      ,double Beta
      ,double Gamma
      ,double Time
    ):
      Nan::AsyncWorker(callback)
      ,mRateTimes(RateTimes)
      ,mLongTermCorr(LongTermCorr)
      ,mBeta(Beta)
      ,mGamma(Gamma)
      ,mTime(Time)
      {

      };

    //~ExponentialCorrelationsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
