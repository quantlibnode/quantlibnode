// This is a generated file, modify: generate/templates/class_header.h

#ifndef latentmodels_h
#define latentmodels_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class GaussianDefaultProbLMWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mBasket;
    std::vector< std::vector<double> > mFactors;

    string mReturnValue;

    string mError;

    GaussianDefaultProbLMWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Basket
      ,std::vector< std::vector<double> > Factors
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBasket(Basket)
      ,mFactors(Factors)
      {

      };

    //~GaussianDefaultProbLMWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TDefaultProbLMWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<long> mTorders;
    string mBasket;
    std::vector< std::vector<double> > mFactors;

    string mReturnValue;

    string mError;

    TDefaultProbLMWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<long> Torders
      ,string Basket
      ,std::vector< std::vector<double> > Factors
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTorders(Torders)
      ,mBasket(Basket)
      ,mFactors(Factors)
      {

      };

    //~TDefaultProbLMWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianLMDefaultCorrelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mCorrelationDate;
    long mNameindexA;
    long mNameindexB;

    double mReturnValue;

    string mError;

    GaussianLMDefaultCorrelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t CorrelationDate
      ,long NameindexA
      ,long NameindexB
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCorrelationDate(CorrelationDate)
      ,mNameindexA(NameindexA)
      ,mNameindexB(NameindexB)
      {

      };

    //~GaussianLMDefaultCorrelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianLMAssetCorrelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mNameindexA;
    long mNameindexB;

    double mReturnValue;

    string mError;

    GaussianLMAssetCorrelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long NameindexA
      ,long NameindexB
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNameindexA(NameindexA)
      ,mNameindexB(NameindexB)
      {

      };

    //~GaussianLMAssetCorrelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class GaussianLMProbNHitsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mNumDefaults;
    ObjectHandler::property_t mProbabilityDate;

    double mReturnValue;

    string mError;

    GaussianLMProbNHitsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long NumDefaults
      ,ObjectHandler::property_t ProbabilityDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNumDefaults(NumDefaults)
      ,mProbabilityDate(ProbabilityDate)
      {

      };

    //~GaussianLMProbNHitsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TLMDefaultCorrelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mCorrelationDate;
    long mNameindexA;
    long mNameindexB;

    double mReturnValue;

    string mError;

    TLMDefaultCorrelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t CorrelationDate
      ,long NameindexA
      ,long NameindexB
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCorrelationDate(CorrelationDate)
      ,mNameindexA(NameindexA)
      ,mNameindexB(NameindexB)
      {

      };

    //~TLMDefaultCorrelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TLMAssetCorrelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mNameindexA;
    long mNameindexB;

    double mReturnValue;

    string mError;

    TLMAssetCorrelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long NameindexA
      ,long NameindexB
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNameindexA(NameindexA)
      ,mNameindexB(NameindexB)
      {

      };

    //~TLMAssetCorrelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TLMProbNHitsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mNumDefaults;
    ObjectHandler::property_t mProbabilityDate;

    double mReturnValue;

    string mError;

    TLMProbNHitsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long NumDefaults
      ,ObjectHandler::property_t ProbabilityDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNumDefaults(NumDefaults)
      ,mProbabilityDate(ProbabilityDate)
      {

      };

    //~TLMProbNHitsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
