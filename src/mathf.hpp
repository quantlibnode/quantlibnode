/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef mathf_h
#define mathf_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class SymmetricSchurDecompositionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mSymmetricMatrix;

    string mReturnValue;

    string mError;

    SymmetricSchurDecompositionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > SymmetricMatrix
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSymmetricMatrix(SymmetricMatrix)
      {

      };

    //~SymmetricSchurDecompositionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CovarianceDecompositionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mSymmetricMatrix;
    double mTolerance;

    string mReturnValue;

    string mError;

    CovarianceDecompositionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > SymmetricMatrix
      ,double Tolerance
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSymmetricMatrix(SymmetricMatrix)
      ,mTolerance(Tolerance)
      {

      };

    //~CovarianceDecompositionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SymmetricSchurDecompositionEigenvaluesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SymmetricSchurDecompositionEigenvaluesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SymmetricSchurDecompositionEigenvaluesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SymmetricSchurDecompositionEigenvectorsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    SymmetricSchurDecompositionEigenvectorsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SymmetricSchurDecompositionEigenvectorsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CovarianceDecompositionVariancesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CovarianceDecompositionVariancesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CovarianceDecompositionVariancesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CovarianceDecompositionStandardDeviationsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CovarianceDecompositionStandardDeviationsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CovarianceDecompositionStandardDeviationsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CovarianceDecompositionCorrelationMatrixWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    CovarianceDecompositionCorrelationMatrixWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CovarianceDecompositionCorrelationMatrixWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PrimeNumberWorker : public Nan::AsyncWorker {
  public:
    long mN;

    long mReturnValue;

    string mError;

    PrimeNumberWorker(
      Nan::Callback *callback
      ,long N
    ):
      Nan::AsyncWorker(callback)
      ,mN(N)
      {

      };

    //~PrimeNumberWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class NormDistWorker : public Nan::AsyncWorker {
  public:
    double mX;
    double mMean;
    double mStandard_dev;
    bool mCumulative;

    double mReturnValue;

    string mError;

    NormDistWorker(
      Nan::Callback *callback
      ,double X
      ,double Mean
      ,double Standard_dev
      ,bool Cumulative
    ):
      Nan::AsyncWorker(callback)
      ,mX(X)
      ,mMean(Mean)
      ,mStandard_dev(Standard_dev)
      ,mCumulative(Cumulative)
      {

      };

    //~NormDistWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class NormSDistWorker : public Nan::AsyncWorker {
  public:
    double mZ;

    double mReturnValue;

    string mError;

    NormSDistWorker(
      Nan::Callback *callback
      ,double Z
    ):
      Nan::AsyncWorker(callback)
      ,mZ(Z)
      {

      };

    //~NormSDistWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class NormInvWorker : public Nan::AsyncWorker {
  public:
    double mProbability;
    double mMean;
    double mStandard_dev;

    double mReturnValue;

    string mError;

    NormInvWorker(
      Nan::Callback *callback
      ,double Probability
      ,double Mean
      ,double Standard_dev
    ):
      Nan::AsyncWorker(callback)
      ,mProbability(Probability)
      ,mMean(Mean)
      ,mStandard_dev(Standard_dev)
      {

      };

    //~NormInvWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class NormSInvWorker : public Nan::AsyncWorker {
  public:
    double mProbability;

    double mReturnValue;

    string mError;

    NormSInvWorker(
      Nan::Callback *callback
      ,double Probability
    ):
      Nan::AsyncWorker(callback)
      ,mProbability(Probability)
      {

      };

    //~NormSInvWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CholeskyDecompositionWorker : public Nan::AsyncWorker {
  public:
    std::vector< std::vector<double> > mMatrix;
    bool mFlexible;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    CholeskyDecompositionWorker(
      Nan::Callback *callback
      ,std::vector< std::vector<double> > Matrix
      ,bool Flexible
    ):
      Nan::AsyncWorker(callback)
      ,mMatrix(Matrix)
      ,mFlexible(Flexible)
      {

      };

    //~CholeskyDecompositionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PseudoSqrtWorker : public Nan::AsyncWorker {
  public:
    std::vector< std::vector<double> > mMatrix;
    string mSalvagingAlgorithm;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    PseudoSqrtWorker(
      Nan::Callback *callback
      ,std::vector< std::vector<double> > Matrix
      ,string SalvagingAlgorithm
    ):
      Nan::AsyncWorker(callback)
      ,mMatrix(Matrix)
      ,mSalvagingAlgorithm(SalvagingAlgorithm)
      {

      };

    //~PseudoSqrtWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RankReducedSqrtWorker : public Nan::AsyncWorker {
  public:
    std::vector< std::vector<double> > mMatrix;
    long mMaxRank;
    double mComponentPercentage;
    string mSalvagingAlgorithm;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    RankReducedSqrtWorker(
      Nan::Callback *callback
      ,std::vector< std::vector<double> > Matrix
      ,long MaxRank
      ,double ComponentPercentage
      ,string SalvagingAlgorithm
    ):
      Nan::AsyncWorker(callback)
      ,mMatrix(Matrix)
      ,mMaxRank(MaxRank)
      ,mComponentPercentage(ComponentPercentage)
      ,mSalvagingAlgorithm(SalvagingAlgorithm)
      {

      };

    //~RankReducedSqrtWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GetCovarianceWorker : public Nan::AsyncWorker {
  public:
    std::vector<double> mVols;
    std::vector< std::vector<double> > mMatrix;
    double mTolerance;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    GetCovarianceWorker(
      Nan::Callback *callback
      ,std::vector<double> Vols
      ,std::vector< std::vector<double> > Matrix
      ,double Tolerance
    ):
      Nan::AsyncWorker(callback)
      ,mVols(Vols)
      ,mMatrix(Matrix)
      ,mTolerance(Tolerance)
      {

      };

    //~GetCovarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
