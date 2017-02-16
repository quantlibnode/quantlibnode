/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef instruments_h
#define instruments_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class InstrumentNPVWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    InstrumentNPVWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InstrumentNPVWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InstrumentErrorEstimateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    InstrumentErrorEstimateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InstrumentErrorEstimateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InstrumentValuationDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    InstrumentValuationDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InstrumentValuationDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InstrumentResultsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mResultType;

    double mReturnValue;

    string mError;

    InstrumentResultsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string ResultType
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mResultType(ResultType)
      {

      };

    //~InstrumentResultsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InstrumentIsExpiredWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    InstrumentIsExpiredWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InstrumentIsExpiredWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InstrumentSetPricingEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPricingEngine;

    string mError;

    InstrumentSetPricingEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PricingEngine
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPricingEngine(PricingEngine)
      {

      };

    //~InstrumentSetPricingEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
