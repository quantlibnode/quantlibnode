/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef driftcalculators_h
#define driftcalculators_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class LMMDriftCalculatorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mPseudo_square_root;
    std::vector<double> mDisplacements;
    std::vector<double> mTaus;
    long mNumeraire;
    long mAlive;

    string mReturnValue;

    string mError;

    LMMDriftCalculatorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Pseudo_square_root
      ,std::vector<double> Displacements
      ,std::vector<double> Taus
      ,long Numeraire
      ,long Alive
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPseudo_square_root(Pseudo_square_root)
      ,mDisplacements(Displacements)
      ,mTaus(Taus)
      ,mNumeraire(Numeraire)
      ,mAlive(Alive)
      {

      };

    //~LMMDriftCalculatorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMNormalDriftCalculatorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mPseudo_square_root;
    std::vector<double> mTaus;
    long mNumeraire;
    long mAlive;

    string mReturnValue;

    string mError;

    LMMNormalDriftCalculatorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Pseudo_square_root
      ,std::vector<double> Taus
      ,long Numeraire
      ,long Alive
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPseudo_square_root(Pseudo_square_root)
      ,mTaus(Taus)
      ,mNumeraire(Numeraire)
      ,mAlive(Alive)
      {

      };

    //~LMMNormalDriftCalculatorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CMSMMDriftCalculatorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mPseudo_square_root;
    std::vector<double> mDisplacements;
    std::vector<double> mTaus;
    long mNumeraire;
    long mAlive;
    long mSpanningFwds;

    string mReturnValue;

    string mError;

    CMSMMDriftCalculatorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Pseudo_square_root
      ,std::vector<double> Displacements
      ,std::vector<double> Taus
      ,long Numeraire
      ,long Alive
      ,long SpanningFwds
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPseudo_square_root(Pseudo_square_root)
      ,mDisplacements(Displacements)
      ,mTaus(Taus)
      ,mNumeraire(Numeraire)
      ,mAlive(Alive)
      ,mSpanningFwds(SpanningFwds)
      {

      };

    //~CMSMMDriftCalculatorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SMMDriftCalculatorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector< std::vector<double> > mPseudo_square_root;
    std::vector<double> mDisplacements;
    std::vector<double> mTaus;
    long mNumeraire;
    long mAlive;

    string mReturnValue;

    string mError;

    SMMDriftCalculatorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector< std::vector<double> > Pseudo_square_root
      ,std::vector<double> Displacements
      ,std::vector<double> Taus
      ,long Numeraire
      ,long Alive
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPseudo_square_root(Pseudo_square_root)
      ,mDisplacements(Displacements)
      ,mTaus(Taus)
      ,mNumeraire(Numeraire)
      ,mAlive(Alive)
      {

      };

    //~SMMDriftCalculatorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMDriftCalculatorComputePlainWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurveState;

    std::vector<double> mReturnValue;

    string mError;

    LMMDriftCalculatorComputePlainWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveState(CurveState)
      {

      };

    //~LMMDriftCalculatorComputePlainWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMDriftCalculatorComputeReducedWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurveState;

    std::vector<double> mReturnValue;

    string mError;

    LMMDriftCalculatorComputeReducedWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveState(CurveState)
      {

      };

    //~LMMDriftCalculatorComputeReducedWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMDriftCalculatorComputeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurveState;

    std::vector<double> mReturnValue;

    string mError;

    LMMDriftCalculatorComputeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveState(CurveState)
      {

      };

    //~LMMDriftCalculatorComputeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMNormalDriftCalculatorComputePlainWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurveState;

    std::vector<double> mReturnValue;

    string mError;

    LMMNormalDriftCalculatorComputePlainWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveState(CurveState)
      {

      };

    //~LMMNormalDriftCalculatorComputePlainWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMNormalDriftCalculatorComputeReducedWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurveState;

    std::vector<double> mReturnValue;

    string mError;

    LMMNormalDriftCalculatorComputeReducedWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveState(CurveState)
      {

      };

    //~LMMNormalDriftCalculatorComputeReducedWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMNormalDriftCalculatorComputeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurveState;

    std::vector<double> mReturnValue;

    string mError;

    LMMNormalDriftCalculatorComputeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveState(CurveState)
      {

      };

    //~LMMNormalDriftCalculatorComputeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CMSMMDriftCalculatorComputeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurveState;

    std::vector<double> mReturnValue;

    string mError;

    CMSMMDriftCalculatorComputeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveState(CurveState)
      {

      };

    //~CMSMMDriftCalculatorComputeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SMMDriftCalculatorComputeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurveState;

    std::vector<double> mReturnValue;

    string mError;

    SMMDriftCalculatorComputeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveState(CurveState)
      {

      };

    //~SMMDriftCalculatorComputeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
