// This is a generated file, modify: generate/templates/class_header.h

#ifndef abcd_h
#define abcd_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class AbcdFunctionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mA;
    double mB;
    double mC;
    double mD;

    string mReturnValue;

    string mError;

    AbcdFunctionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double A
      ,double B
      ,double C
      ,double D
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mA(A)
      ,mB(B)
      ,mC(C)
      ,mD(D)
      {

      };

    //~AbcdFunctionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mTimes;
    std::vector<double> mBlackVols;
    double mA;
    double mB;
    double mC;
    double mD;
    bool mAIsFixed;
    bool mBIsFixed;
    bool mCIsFixed;
    bool mDIsFixed;
    bool mVegaWeighted;
    string mEndCriteria;
    string mMethod;

    string mReturnValue;

    string mError;

    AbcdCalibrationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> Times
      ,std::vector<double> BlackVols
      ,double A
      ,double B
      ,double C
      ,double D
      ,bool AIsFixed
      ,bool BIsFixed
      ,bool CIsFixed
      ,bool DIsFixed
      ,bool VegaWeighted
      ,string EndCriteria
      ,string Method
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimes(Times)
      ,mBlackVols(BlackVols)
      ,mA(A)
      ,mB(B)
      ,mC(C)
      ,mD(D)
      ,mAIsFixed(AIsFixed)
      ,mBIsFixed(BIsFixed)
      ,mCIsFixed(CIsFixed)
      ,mDIsFixed(DIsFixed)
      ,mVegaWeighted(VegaWeighted)
      ,mEndCriteria(EndCriteria)
      ,mMethod(Method)
      {

      };

    //~AbcdCalibrationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionInstantaneousValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mU;

    std::vector<double> mReturnValue;

    string mError;

    AbcdFunctionInstantaneousValueWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> U
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mU(U)
      {

      };

    //~AbcdFunctionInstantaneousValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionInstantaneousCovarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mU;
    double mT;
    double mS;

    std::vector<double> mReturnValue;

    string mError;

    AbcdFunctionInstantaneousCovarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> U
      ,double T
      ,double S
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mU(U)
      ,mT(T)
      ,mS(S)
      {

      };

    //~AbcdFunctionInstantaneousCovarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionInstantaneousVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mU;
    double mT;

    std::vector<double> mReturnValue;

    string mError;

    AbcdFunctionInstantaneousVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> U
      ,double T
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mU(U)
      ,mT(T)
      {

      };

    //~AbcdFunctionInstantaneousVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionInstantaneousVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mU;
    double mT;

    std::vector<double> mReturnValue;

    string mError;

    AbcdFunctionInstantaneousVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> U
      ,double T
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mU(U)
      ,mT(T)
      {

      };

    //~AbcdFunctionInstantaneousVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionCovarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTMin;
    std::vector<double> mTMax;
    double mT;
    double mS;

    std::vector<double> mReturnValue;

    string mError;

    AbcdFunctionCovarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double TMin
      ,std::vector<double> TMax
      ,double T
      ,double S
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTMin(TMin)
      ,mTMax(TMax)
      ,mT(T)
      ,mS(S)
      {

      };

    //~AbcdFunctionCovarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTMin;
    std::vector<double> mTMax;
    double mT;

    std::vector<double> mReturnValue;

    string mError;

    AbcdFunctionVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double TMin
      ,std::vector<double> TMax
      ,double T
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTMin(TMin)
      ,mTMax(TMax)
      ,mT(T)
      {

      };

    //~AbcdFunctionVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTMin;
    std::vector<double> mTMax;
    double mT;

    std::vector<double> mReturnValue;

    string mError;

    AbcdFunctionVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double TMin
      ,std::vector<double> TMax
      ,double T
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTMin(TMin)
      ,mTMax(TMax)
      ,mT(T)
      {

      };

    //~AbcdFunctionVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionShortTermVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdFunctionShortTermVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdFunctionShortTermVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionLongTermVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdFunctionLongTermVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdFunctionLongTermVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionMaximumLocationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdFunctionMaximumLocationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdFunctionMaximumLocationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionMaximumVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdFunctionMaximumVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdFunctionMaximumVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionAWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdFunctionAWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdFunctionAWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionBWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdFunctionBWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdFunctionBWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionCWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdFunctionCWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdFunctionCWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdFunctionDWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdFunctionDWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdFunctionDWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdDFunctionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdDFunctionWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdDFunctionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationComputeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mError;

    AbcdCalibrationComputeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdCalibrationComputeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationKWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mTimes;
    std::vector<double> mBlackVols;

    std::vector<double> mReturnValue;

    string mError;

    AbcdCalibrationKWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> Times
      ,std::vector<double> BlackVols
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimes(Times)
      ,mBlackVols(BlackVols)
      {

      };

    //~AbcdCalibrationKWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdCalibrationErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdCalibrationErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationMaxErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdCalibrationMaxErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdCalibrationMaxErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationEndCriteriaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    AbcdCalibrationEndCriteriaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdCalibrationEndCriteriaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationAWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdCalibrationAWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdCalibrationAWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationBWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdCalibrationBWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdCalibrationBWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationCWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdCalibrationCWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdCalibrationCWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdCalibrationDWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdCalibrationDWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdCalibrationDWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
