/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef basketlossmodels_h
#define basketlossmodels_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class GaussianLHPLossmodelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mCorrelation;
    std::vector<double> mRecoveyRates;

    string mReturnValue;

    string mError;

    GaussianLHPLossmodelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Correlation
      ,std::vector<double> RecoveyRates
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCorrelation(Correlation)
      ,mRecoveyRates(RecoveyRates)
      {

      };

    //~GaussianLHPLossmodelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IHGaussPoolLossModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mCorrelation;
    std::vector<double> mRecoveyRates;
    long mNumBuckets;

    string mReturnValue;

    string mError;

    IHGaussPoolLossModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Correlation
      ,std::vector<double> RecoveyRates
      ,long NumBuckets
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCorrelation(Correlation)
      ,mRecoveyRates(RecoveyRates)
      ,mNumBuckets(NumBuckets)
      {

      };

    //~IHGaussPoolLossModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IHStudentPoolLossModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mCorrelation;
    std::vector<double> mRecoveyRates;
    std::vector<double> mTtraits;
    long mNumBuckets;

    string mReturnValue;

    string mError;

    IHStudentPoolLossModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Correlation
      ,std::vector<double> RecoveyRates
      ,std::vector<double> Ttraits
      ,long NumBuckets
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCorrelation(Correlation)
      ,mRecoveyRates(RecoveyRates)
      ,mTtraits(Ttraits)
      ,mNumBuckets(NumBuckets)
      {

      };

    //~IHStudentPoolLossModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GBinomialLossmodelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFactors;
    std::vector<double> mRecoveyRates;

    string mReturnValue;

    string mError;

    GBinomialLossmodelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Factors
      ,std::vector<double> RecoveyRates
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFactors(Factors)
      ,mRecoveyRates(RecoveyRates)
      {

      };

    //~GBinomialLossmodelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TBinomialLossmodelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFactors;
    std::vector<double> mRecoveyRates;
    std::vector<double> mTtraits;

    string mReturnValue;

    string mError;

    TBinomialLossmodelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Factors
      ,std::vector<double> RecoveyRates
      ,std::vector<double> Ttraits
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFactors(Factors)
      ,mRecoveyRates(RecoveyRates)
      ,mTtraits(Ttraits)
      {

      };

    //~TBinomialLossmodelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BaseCorrelationLossModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mBaseModel;
    string mBaseCorrelationSurface;
    std::vector<double> mRecoveries;
    std::vector<double> mInitiTraits;

    string mReturnValue;

    string mError;

    BaseCorrelationLossModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string BaseModel
      ,string BaseCorrelationSurface
      ,std::vector<double> Recoveries
      ,std::vector<double> InitiTraits
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBaseModel(BaseModel)
      ,mBaseCorrelationSurface(BaseCorrelationSurface)
      ,mRecoveries(Recoveries)
      ,mInitiTraits(InitiTraits)
      {

      };

    //~BaseCorrelationLossModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GMCLossModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFactors;
    std::vector<double> mRecoveyRates;
    long mNumSimulations;

    string mReturnValue;

    string mError;

    GMCLossModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Factors
      ,std::vector<double> RecoveyRates
      ,long NumSimulations
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFactors(Factors)
      ,mRecoveyRates(RecoveyRates)
      ,mNumSimulations(NumSimulations)
      {

      };

    //~GMCLossModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GRandomRRMCLossModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFactors;
    std::vector<double> mRecoveyRates;
    double mModelA;
    long mNumSimulations;

    string mReturnValue;

    string mError;

    GRandomRRMCLossModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Factors
      ,std::vector<double> RecoveyRates
      ,double ModelA
      ,long NumSimulations
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFactors(Factors)
      ,mRecoveyRates(RecoveyRates)
      ,mModelA(ModelA)
      ,mNumSimulations(NumSimulations)
      {

      };

    //~GRandomRRMCLossModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TMCLossModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFactors;
    std::vector<double> mRecoveyRates;
    std::vector<double> mTtraits;
    long mNumSimulations;

    string mReturnValue;

    string mError;

    TMCLossModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Factors
      ,std::vector<double> RecoveyRates
      ,std::vector<double> Ttraits
      ,long NumSimulations
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFactors(Factors)
      ,mRecoveyRates(RecoveyRates)
      ,mTtraits(Ttraits)
      ,mNumSimulations(NumSimulations)
      {

      };

    //~TMCLossModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TRandomRRMCLossModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFactors;
    std::vector<double> mRecoveyRates;
    std::vector<double> mTtraits;
    double mModelA;
    long mNumSimulations;

    string mReturnValue;

    string mError;

    TRandomRRMCLossModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Factors
      ,std::vector<double> RecoveyRates
      ,std::vector<double> Ttraits
      ,double ModelA
      ,long NumSimulations
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFactors(Factors)
      ,mRecoveyRates(RecoveyRates)
      ,mTtraits(Ttraits)
      ,mModelA(ModelA)
      ,mNumSimulations(NumSimulations)
      {

      };

    //~TRandomRRMCLossModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GSaddlePointLossmodelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFactors;
    std::vector<double> mRecoveyRates;

    string mReturnValue;

    string mError;

    GSaddlePointLossmodelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Factors
      ,std::vector<double> RecoveyRates
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFactors(Factors)
      ,mRecoveyRates(RecoveyRates)
      {

      };

    //~GSaddlePointLossmodelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TSaddlePointLossmodelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFactors;
    std::vector<double> mRecoveyRates;
    std::vector<double> mTtraits;

    string mReturnValue;

    string mError;

    TSaddlePointLossmodelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Factors
      ,std::vector<double> RecoveyRates
      ,std::vector<double> Ttraits
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFactors(Factors)
      ,mRecoveyRates(RecoveyRates)
      ,mTtraits(Ttraits)
      {

      };

    //~TSaddlePointLossmodelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GRecursiveLossmodelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mFactors;
    std::vector<double> mRecoveyRates;

    string mReturnValue;

    string mError;

    GRecursiveLossmodelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Factors
      ,std::vector<double> RecoveyRates
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFactors(Factors)
      ,mRecoveyRates(RecoveyRates)
      {

      };

    //~GRecursiveLossmodelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
