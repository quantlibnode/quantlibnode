// This is a generated file, modify: generate/templates/class_header.h

#ifndef shortratemodels_h
#define shortratemodels_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class HullWhiteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;
    double mA;
    double mSigma;

    string mReturnValue;

    string mError;

    HullWhiteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
      ,double A
      ,double Sigma
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      ,mA(A)
      ,mSigma(Sigma)
      {

      };

    //~HullWhiteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VasicekWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mR0;
    double mA;
    double mB;
    double mSigma;
    double mLambda;

    string mReturnValue;

    string mError;

    VasicekWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double R0
      ,double A
      ,double B
      ,double Sigma
      ,double Lambda
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mR0(R0)
      ,mA(A)
      ,mB(B)
      ,mSigma(Sigma)
      ,mLambda(Lambda)
      {

      };

    //~VasicekWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ModelG2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;
    double mA;
    double mSigma;
    double mB;
    double mEta;
    double mCorrelation;

    string mReturnValue;

    string mError;

    ModelG2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
      ,double A
      ,double Sigma
      ,double B
      ,double Eta
      ,double Correlation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      ,mA(A)
      ,mSigma(Sigma)
      ,mB(B)
      ,mEta(Eta)
      ,mCorrelation(Correlation)
      {

      };

    //~ModelG2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VasicekAWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VasicekAWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VasicekAWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VasicekBWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VasicekBWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VasicekBWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VasicekLambdaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VasicekLambdaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VasicekLambdaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VasicekSigmaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VasicekSigmaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VasicekSigmaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ModelG2AWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ModelG2AWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ModelG2AWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ModelG2sigmaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ModelG2sigmaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ModelG2sigmaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ModelG2BWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ModelG2BWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ModelG2BWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ModelG2etaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ModelG2etaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ModelG2etaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ModelG2rhoWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ModelG2rhoWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ModelG2rhoWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesConvexityBiasWorker : public Nan::AsyncWorker {
  public:
    double mFuturesPrice;
    double mT1;
    double mT2;
    double mSigma;
    double mA;

    double mReturnValue;

    string mError;

    FuturesConvexityBiasWorker(
      Nan::Callback *callback
      ,double FuturesPrice
      ,double T1
      ,double T2
      ,double Sigma
      ,double A
    ):
      Nan::AsyncWorker(callback)
      ,mFuturesPrice(FuturesPrice)
      ,mT1(T1)
      ,mT2(T2)
      ,mSigma(Sigma)
      ,mA(A)
      {

      };

    //~FuturesConvexityBiasWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
