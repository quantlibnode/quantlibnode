// This is a generated file, modify: generate/templates/class_header.h

#ifndef forwardrateagreement_h
#define forwardrateagreement_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class FRAWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mValueDate;
    ObjectHandler::property_t mMaturityDate;
    string mPosition;
    double mStrike;
    double mNotional;
    string mIborIndex;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    FRAWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t ValueDate
      ,ObjectHandler::property_t MaturityDate
      ,string Position
      ,double Strike
      ,double Notional
      ,string IborIndex
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mValueDate(ValueDate)
      ,mMaturityDate(MaturityDate)
      ,mPosition(Position)
      ,mStrike(Strike)
      ,mNotional(Notional)
      ,mIborIndex(IborIndex)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~FRAWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FRAforwardRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    FRAforwardRateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FRAforwardRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FRAforwardValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    FRAforwardValueWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FRAforwardValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FRAspotValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    FRAspotValueWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FRAspotValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
