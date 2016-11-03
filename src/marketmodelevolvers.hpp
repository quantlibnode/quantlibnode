/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef marketmodelevolvers_h
#define marketmodelevolvers_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class ForwardRatePcWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mMarketModel;
    string mBrownianGeneratorFactory;
    std::vector<long> mNumeraires;

    string mReturnValue;

    string mError;

    ForwardRatePcWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string MarketModel
      ,string BrownianGeneratorFactory
      ,std::vector<long> Numeraires
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mMarketModel(MarketModel)
      ,mBrownianGeneratorFactory(BrownianGeneratorFactory)
      ,mNumeraires(Numeraires)
      {

      };

    //~ForwardRatePcWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ForwardRateIpcWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mMarketModel;
    string mBrownianGeneratorFactory;
    std::vector<long> mNumeraires;

    string mReturnValue;

    string mError;

    ForwardRateIpcWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string MarketModel
      ,string BrownianGeneratorFactory
      ,std::vector<long> Numeraires
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mMarketModel(MarketModel)
      ,mBrownianGeneratorFactory(BrownianGeneratorFactory)
      ,mNumeraires(Numeraires)
      {

      };

    //~ForwardRateIpcWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ForwardRateNormalPcWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mMarketModel;
    string mBrownianGeneratorFactory;
    std::vector<long> mNumeraires;

    string mReturnValue;

    string mError;

    ForwardRateNormalPcWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string MarketModel
      ,string BrownianGeneratorFactory
      ,std::vector<long> Numeraires
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mMarketModel(MarketModel)
      ,mBrownianGeneratorFactory(BrownianGeneratorFactory)
      ,mNumeraires(Numeraires)
      {

      };

    //~ForwardRateNormalPcWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelEvolverStartNewPathWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    MarketModelEvolverStartNewPathWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelEvolverStartNewPathWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelEvolverAdvanceStepWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    MarketModelEvolverAdvanceStepWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelEvolverAdvanceStepWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelEvolverCurrentStepWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    MarketModelEvolverCurrentStepWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelEvolverCurrentStepWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelEvolverNumerairesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    MarketModelEvolverNumerairesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelEvolverNumerairesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
