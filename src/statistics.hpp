/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef statistics_h
#define statistics_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class StatisticsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mValues;
    std::vector<double> mWeights;

    string mReturnValue;

    string mError;

    StatisticsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> Values
      ,std::vector<double> Weights
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mValues(Values)
      ,mWeights(Weights)
      {

      };

    //~StatisticsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IncrementalStatisticsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mValues;
    std::vector<double> mWeights;

    string mReturnValue;

    string mError;

    IncrementalStatisticsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> Values
      ,std::vector<double> Weights
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mValues(Values)
      ,mWeights(Weights)
      {

      };

    //~IncrementalStatisticsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsSamplesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    StatisticsSamplesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsSamplesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsWeightSumWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsWeightSumWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsWeightSumWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsMeanWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsMeanWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsMeanWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsStandardDeviationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsStandardDeviationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsStandardDeviationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsErrorEstimateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsErrorEstimateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsErrorEstimateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsSkewnessWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsSkewnessWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsSkewnessWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsKurtosisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsKurtosisWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsKurtosisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsMinWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsMinWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsMinWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsMaxWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsMaxWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsMaxWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsPercentileWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mX;

    double mReturnValue;

    string mError;

    StatisticsPercentileWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double X
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mX(X)
      {

      };

    //~StatisticsPercentileWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsTopPercentileWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mX;

    double mReturnValue;

    string mError;

    StatisticsTopPercentileWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double X
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mX(X)
      {

      };

    //~StatisticsTopPercentileWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianDownsideVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsGaussianDownsideVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsGaussianDownsideVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianDownsideDeviationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsGaussianDownsideDeviationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsGaussianDownsideDeviationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianRegretWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsGaussianRegretWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsGaussianRegretWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianPercentileWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mX;

    double mReturnValue;

    string mError;

    StatisticsGaussianPercentileWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double X
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mX(X)
      {

      };

    //~StatisticsGaussianPercentileWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianTopPercentileWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mX;

    double mReturnValue;

    string mError;

    StatisticsGaussianTopPercentileWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double X
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mX(X)
      {

      };

    //~StatisticsGaussianTopPercentileWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianPotentialUpsideWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsGaussianPotentialUpsideWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsGaussianPotentialUpsideWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianValueAtRiskWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsGaussianValueAtRiskWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsGaussianValueAtRiskWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianExpectedShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsGaussianExpectedShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsGaussianExpectedShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsGaussianShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsGaussianShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsGaussianAverageShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsGaussianAverageShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsGaussianAverageShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsSemiVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsSemiVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsSemiVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsSemiDeviationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsSemiDeviationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsSemiDeviationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsDownsideVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsDownsideVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsDownsideVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsDownsideDeviationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    StatisticsDownsideDeviationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StatisticsDownsideDeviationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsRegretWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsRegretWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsRegretWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsPotentialUpsideWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mCentile;

    double mReturnValue;

    string mError;

    StatisticsPotentialUpsideWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Centile
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCentile(Centile)
      {

      };

    //~StatisticsPotentialUpsideWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsValueAtRiskWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsValueAtRiskWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsValueAtRiskWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsExpectedShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mCentile;

    double mReturnValue;

    string mError;

    StatisticsExpectedShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Centile
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCentile(Centile)
      {

      };

    //~StatisticsExpectedShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StatisticsAverageShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    double mReturnValue;

    string mError;

    StatisticsAverageShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~StatisticsAverageShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianDownsideVarianceWorker : public Nan::AsyncWorker {
  public:
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianDownsideVarianceWorker(
      Nan::Callback *callback
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianDownsideVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianDownsideDeviationWorker : public Nan::AsyncWorker {
  public:
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianDownsideDeviationWorker(
      Nan::Callback *callback
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianDownsideDeviationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianRegretWorker : public Nan::AsyncWorker {
  public:
    double mTarget;
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianRegretWorker(
      Nan::Callback *callback
      ,double Target
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mTarget(Target)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianRegretWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianPercentileWorker : public Nan::AsyncWorker {
  public:
    double mX;
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianPercentileWorker(
      Nan::Callback *callback
      ,double X
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mX(X)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianPercentileWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianTopPercentileWorker : public Nan::AsyncWorker {
  public:
    double mX;
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianTopPercentileWorker(
      Nan::Callback *callback
      ,double X
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mX(X)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianTopPercentileWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianPotentialUpsideWorker : public Nan::AsyncWorker {
  public:
    double mTarget;
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianPotentialUpsideWorker(
      Nan::Callback *callback
      ,double Target
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mTarget(Target)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianPotentialUpsideWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianValueAtRiskWorker : public Nan::AsyncWorker {
  public:
    double mTarget;
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianValueAtRiskWorker(
      Nan::Callback *callback
      ,double Target
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mTarget(Target)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianValueAtRiskWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianExpectedShortfallWorker : public Nan::AsyncWorker {
  public:
    double mTarget;
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianExpectedShortfallWorker(
      Nan::Callback *callback
      ,double Target
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mTarget(Target)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianExpectedShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianShortfallWorker : public Nan::AsyncWorker {
  public:
    double mTarget;
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianShortfallWorker(
      Nan::Callback *callback
      ,double Target
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mTarget(Target)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianAverageShortfallWorker : public Nan::AsyncWorker {
  public:
    double mTarget;
    double mMean;
    double mStdDev;

    double mReturnValue;

    string mError;

    GaussianAverageShortfallWorker(
      Nan::Callback *callback
      ,double Target
      ,double Mean
      ,double StdDev
    ):
      Nan::AsyncWorker(callback)
      ,mTarget(Target)
      ,mMean(Mean)
      ,mStdDev(StdDev)
      {

      };

    //~GaussianAverageShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
