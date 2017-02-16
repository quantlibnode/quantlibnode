/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef sequencestatistics_h
#define sequencestatistics_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class SequenceStatisticsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mDimension;

    string mReturnValue;

    string mError;

    SequenceStatisticsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Dimension
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDimension(Dimension)
      {

      };

    //~SequenceStatisticsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatistics2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mDimension;
    std::vector< std::vector<double> > mValues;
    std::vector<double> mWeights;

    string mReturnValue;

    string mError;

    SequenceStatistics2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Dimension
      ,std::vector< std::vector<double> > Values
      ,std::vector<double> Weights
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDimension(Dimension)
      ,mValues(Values)
      ,mWeights(Weights)
      {

      };

    //~SequenceStatistics2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsIncWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mDimension;

    string mReturnValue;

    string mError;

    SequenceStatisticsIncWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Dimension
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDimension(Dimension)
      {

      };

    //~SequenceStatisticsIncWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsInc2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mDimension;
    std::vector< std::vector<double> > mValues;
    std::vector<double> mWeights;

    string mReturnValue;

    string mError;

    SequenceStatisticsInc2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Dimension
      ,std::vector< std::vector<double> > Values
      ,std::vector<double> Weights
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDimension(Dimension)
      ,mValues(Values)
      ,mWeights(Weights)
      {

      };

    //~SequenceStatisticsInc2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsSamplesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    SequenceStatisticsSamplesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsSamplesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsWeightSumWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SequenceStatisticsWeightSumWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsWeightSumWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsMeanWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsMeanWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsMeanWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsStandardDeviationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsStandardDeviationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsStandardDeviationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsDownsideVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsDownsideVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsDownsideVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsDownsideDeviationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsDownsideDeviationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsDownsideDeviationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsSemiVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsSemiVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsSemiVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsSemiDeviationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsSemiDeviationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsSemiDeviationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsErrorEstimateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsErrorEstimateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsErrorEstimateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsSkewnessWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsSkewnessWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsSkewnessWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsKurtosisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsKurtosisWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsKurtosisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsMinWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsMinWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsMinWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsMaxWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsMaxWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsMaxWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsGaussianPercentileWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mX;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsGaussianPercentileWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double X
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mX(X)
      {

      };

    //~SequenceStatisticsGaussianPercentileWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsPercentileWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mX;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsPercentileWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double X
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mX(X)
      {

      };

    //~SequenceStatisticsPercentileWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsGaussianPotentialUpsideWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsGaussianPotentialUpsideWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~SequenceStatisticsGaussianPotentialUpsideWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsPotentialUpsideWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mCentile;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsPotentialUpsideWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Centile
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCentile(Centile)
      {

      };

    //~SequenceStatisticsPotentialUpsideWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsGaussianValueAtRiskWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsGaussianValueAtRiskWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~SequenceStatisticsGaussianValueAtRiskWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsValueAtRiskWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsValueAtRiskWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~SequenceStatisticsValueAtRiskWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsRegretWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsRegretWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~SequenceStatisticsRegretWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsGaussianShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsGaussianShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~SequenceStatisticsGaussianShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~SequenceStatisticsShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsGaussianAverageShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsGaussianAverageShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~SequenceStatisticsGaussianAverageShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsAverageShortfallWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTarget;

    std::vector<double> mReturnValue;

    string mError;

    SequenceStatisticsAverageShortfallWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Target
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTarget(Target)
      {

      };

    //~SequenceStatisticsAverageShortfallWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsSizeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    SequenceStatisticsSizeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsSizeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsCovarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    SequenceStatisticsCovarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsCovarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SequenceStatisticsCorrelationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    SequenceStatisticsCorrelationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SequenceStatisticsCorrelationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
