// This is a generated file, modify: generate/templates/class_header.h

#ifndef optimization_h
#define optimization_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class EndCriteriaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mMaxIterations;
    long mMaxStationaryStateIterations;
    double mRootEpsilon;
    double mFunctionEpsilon;
    double mGradientNormEpsilon;

    string mReturnValue;

    string mError;

    EndCriteriaWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long MaxIterations
      ,long MaxStationaryStateIterations
      ,double RootEpsilon
      ,double FunctionEpsilon
      ,double GradientNormEpsilon
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mMaxIterations(MaxIterations)
      ,mMaxStationaryStateIterations(MaxStationaryStateIterations)
      ,mRootEpsilon(RootEpsilon)
      ,mFunctionEpsilon(FunctionEpsilon)
      ,mGradientNormEpsilon(GradientNormEpsilon)
      {

      };

    //~EndCriteriaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class NoConstraintWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    NoConstraintWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~NoConstraintWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SimplexWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mLambda;

    string mReturnValue;

    string mError;

    SimplexWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Lambda
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLambda(Lambda)
      {

      };

    //~SimplexWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LevenbergMarquardtWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mEpsfcn;
    double mXtol;
    double mGtol;

    string mReturnValue;

    string mError;

    LevenbergMarquardtWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Epsfcn
      ,double Xtol
      ,double Gtol
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEpsfcn(Epsfcn)
      ,mXtol(Xtol)
      ,mGtol(Gtol)
      {

      };

    //~LevenbergMarquardtWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ConjugateGradientWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mLineSearch;

    string mReturnValue;

    string mError;

    ConjugateGradientWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string LineSearch
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLineSearch(LineSearch)
      {

      };

    //~ConjugateGradientWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SteepestDescentWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mLineSearch;

    string mReturnValue;

    string mError;

    SteepestDescentWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string LineSearch
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLineSearch(LineSearch)
      {

      };

    //~SteepestDescentWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ArmijoLineSearchWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mEpsilon;
    double mAlpha;
    double mBeta;

    string mReturnValue;

    string mError;

    ArmijoLineSearchWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Epsilon
      ,double Alpha
      ,double Beta
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEpsilon(Epsilon)
      ,mAlpha(Alpha)
      ,mBeta(Beta)
      {

      };

    //~ArmijoLineSearchWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EndCriteriaMaxIterationsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    EndCriteriaMaxIterationsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EndCriteriaMaxIterationsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EndCriteriaMaxStationaryStateIterationsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    EndCriteriaMaxStationaryStateIterationsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EndCriteriaMaxStationaryStateIterationsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EndCriteriaFunctionEpsilonWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    EndCriteriaFunctionEpsilonWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EndCriteriaFunctionEpsilonWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EndCriteriaGradientNormEpsilonWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    EndCriteriaGradientNormEpsilonWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EndCriteriaGradientNormEpsilonWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SphereCylinderOptimizerClosestWorker : public Nan::AsyncWorker {
  public:
    double mR;
    double mS;
    double mAlpha;
    double mZ1;
    double mZ2;
    double mZ3;
    ObjectHandler::property_t mMaxIter;
    double mTol;

    std::vector<double> mReturnValue;

    string mError;

    SphereCylinderOptimizerClosestWorker(
      Nan::Callback *callback
      ,double R
      ,double S
      ,double Alpha
      ,double Z1
      ,double Z2
      ,double Z3
      ,ObjectHandler::property_t MaxIter
      ,double Tol
    ):
      Nan::AsyncWorker(callback)
      ,mR(R)
      ,mS(S)
      ,mAlpha(Alpha)
      ,mZ1(Z1)
      ,mZ2(Z2)
      ,mZ3(Z3)
      ,mMaxIter(MaxIter)
      ,mTol(Tol)
      {

      };

    //~SphereCylinderOptimizerClosestWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SecondsToStringWorker : public Nan::AsyncWorker {
  public:
    double mSeconds;

    string mReturnValue;

    string mError;

    SecondsToStringWorker(
      Nan::Callback *callback
      ,double Seconds
    ):
      Nan::AsyncWorker(callback)
      ,mSeconds(Seconds)
      {

      };

    //~SecondsToStringWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
