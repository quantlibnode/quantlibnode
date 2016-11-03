/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef interpolation_h
#define interpolation_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class InterpolationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mInterpolationType;
    std::vector<double> mXArray;
    std::vector<ObjectHandler::property_t> mYArray;

    string mReturnValue;

    string mError;

    InterpolationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string InterpolationType
      ,std::vector<double> XArray
      ,std::vector<ObjectHandler::property_t> YArray
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mInterpolationType(InterpolationType)
      ,mXArray(XArray)
      ,mYArray(YArray)
      {

      };

    //~InterpolationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MixedLinearCubicInterpolationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXArray;
    std::vector<ObjectHandler::property_t> mYArray;
    long mSwitchIndex;
    string mDerApprox;
    bool mMonotonic;
    string mLeftConditionType;
    double mLeftConditionValue;
    string mRightConditionType;
    double mRightConditionValue;

    string mReturnValue;

    string mError;

    MixedLinearCubicInterpolationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XArray
      ,std::vector<ObjectHandler::property_t> YArray
      ,long SwitchIndex
      ,string DerApprox
      ,bool Monotonic
      ,string LeftConditionType
      ,double LeftConditionValue
      ,string RightConditionType
      ,double RightConditionValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXArray(XArray)
      ,mYArray(YArray)
      ,mSwitchIndex(SwitchIndex)
      ,mDerApprox(DerApprox)
      ,mMonotonic(Monotonic)
      ,mLeftConditionType(LeftConditionType)
      ,mLeftConditionValue(LeftConditionValue)
      ,mRightConditionType(RightConditionType)
      ,mRightConditionValue(RightConditionValue)
      {

      };

    //~MixedLinearCubicInterpolationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CubicInterpolationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXArray;
    std::vector<ObjectHandler::property_t> mYArray;
    string mDerApprox;
    bool mMonotonic;
    string mLeftConditionType;
    double mLeftConditionValue;
    string mRightConditionType;
    double mRightConditionValue;

    string mReturnValue;

    string mError;

    CubicInterpolationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XArray
      ,std::vector<ObjectHandler::property_t> YArray
      ,string DerApprox
      ,bool Monotonic
      ,string LeftConditionType
      ,double LeftConditionValue
      ,string RightConditionType
      ,double RightConditionValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXArray(XArray)
      ,mYArray(YArray)
      ,mDerApprox(DerApprox)
      ,mMonotonic(Monotonic)
      ,mLeftConditionType(LeftConditionType)
      ,mLeftConditionValue(LeftConditionValue)
      ,mRightConditionType(RightConditionType)
      ,mRightConditionValue(RightConditionValue)
      {

      };

    //~CubicInterpolationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdInterpolationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXArray;
    std::vector<ObjectHandler::property_t> mYArray;
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
    string mOptimizationMeth;

    string mReturnValue;

    string mError;

    AbcdInterpolationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XArray
      ,std::vector<ObjectHandler::property_t> YArray
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
      ,string OptimizationMeth
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXArray(XArray)
      ,mYArray(YArray)
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
      ,mOptimizationMeth(OptimizationMeth)
      {

      };

    //~AbcdInterpolationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXArray;
    std::vector<ObjectHandler::property_t> mYArray;
    double mExpiry;
    ObjectHandler::property_t mForward;
    double mAlpha;
    double mBeta;
    double mNu;
    double mRho;
    bool mAlphaIsFixed;
    bool mBetaIsFixed;
    bool mNuIsFixed;
    bool mRhoIsFixed;
    bool mVegaWeighted;
    string mEndCriteria;
    string mOptimizationMeth;

    string mReturnValue;

    string mError;

    SABRInterpolationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XArray
      ,std::vector<ObjectHandler::property_t> YArray
      ,double Expiry
      ,ObjectHandler::property_t Forward
      ,double Alpha
      ,double Beta
      ,double Nu
      ,double Rho
      ,bool AlphaIsFixed
      ,bool BetaIsFixed
      ,bool NuIsFixed
      ,bool RhoIsFixed
      ,bool VegaWeighted
      ,string EndCriteria
      ,string OptimizationMeth
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXArray(XArray)
      ,mYArray(YArray)
      ,mExpiry(Expiry)
      ,mForward(Forward)
      ,mAlpha(Alpha)
      ,mBeta(Beta)
      ,mNu(Nu)
      ,mRho(Rho)
      ,mAlphaIsFixed(AlphaIsFixed)
      ,mBetaIsFixed(BetaIsFixed)
      ,mNuIsFixed(NuIsFixed)
      ,mRhoIsFixed(RhoIsFixed)
      ,mVegaWeighted(VegaWeighted)
      ,mEndCriteria(EndCriteria)
      ,mOptimizationMeth(OptimizationMeth)
      {

      };

    //~SABRInterpolationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mInterpolationType;
    std::vector<double> mXArray;
    std::vector<double> mYArray;
    std::vector< std::vector<double> > mZMatrix;

    string mReturnValue;

    string mError;

    Interpolation2DWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string InterpolationType
      ,std::vector<double> XArray
      ,std::vector<double> YArray
      ,std::vector< std::vector<double> > ZMatrix
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mInterpolationType(InterpolationType)
      ,mXArray(XArray)
      ,mYArray(YArray)
      ,mZMatrix(ZMatrix)
      {

      };

    //~Interpolation2DWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ExtrapolatorEnableExtrapolationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    bool mExtrapolationFlag;

    string mError;

    ExtrapolatorEnableExtrapolationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,bool ExtrapolationFlag
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mExtrapolationFlag(ExtrapolationFlag)
      {

      };

    //~ExtrapolatorEnableExtrapolationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolationInterpolateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXValues;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    InterpolationInterpolateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XValues
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXValues(XValues)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~InterpolationInterpolateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolationDerivativeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXValues;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    InterpolationDerivativeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XValues
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXValues(XValues)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~InterpolationDerivativeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolationSecondDerivativeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXValues;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    InterpolationSecondDerivativeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XValues
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXValues(XValues)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~InterpolationSecondDerivativeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolationPrimitiveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXValues;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    InterpolationPrimitiveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XValues
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXValues(XValues)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~InterpolationPrimitiveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolationIsInRangeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXValues;

    std::vector<bool> mReturnValue;

    string mError;

    InterpolationIsInRangeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XValues
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXValues(XValues)
      {

      };

    //~InterpolationIsInRangeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolationXminWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    InterpolationXminWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterpolationXminWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolationXmaxWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    InterpolationXmaxWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterpolationXmaxWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CubicInterpolationPrimitiveConstantsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CubicInterpolationPrimitiveConstantsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CubicInterpolationPrimitiveConstantsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CubicInterpolationACoefficientsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CubicInterpolationACoefficientsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CubicInterpolationACoefficientsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CubicInterpolationBCoefficientsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CubicInterpolationBCoefficientsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CubicInterpolationBCoefficientsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CubicInterpolationCCoefficientsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CubicInterpolationCCoefficientsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CubicInterpolationCCoefficientsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CubicInterpolationMonotonicityAdjustmentsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<bool> mReturnValue;

    string mError;

    CubicInterpolationMonotonicityAdjustmentsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CubicInterpolationMonotonicityAdjustmentsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdInterpolationAWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdInterpolationAWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdInterpolationAWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdInterpolationBWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdInterpolationBWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdInterpolationBWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdInterpolationCWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdInterpolationCWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdInterpolationCWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdInterpolationDWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdInterpolationDWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdInterpolationDWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdInterpolationRmsErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdInterpolationRmsErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdInterpolationRmsErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdInterpolationMaxErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdInterpolationMaxErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdInterpolationMaxErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdInterpolationEndCriteriaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    AbcdInterpolationEndCriteriaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdInterpolationEndCriteriaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationExpiryWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SABRInterpolationExpiryWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationExpiryWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationForwardWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SABRInterpolationForwardWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationForwardWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationAlphaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SABRInterpolationAlphaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationAlphaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationBetaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SABRInterpolationBetaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationBetaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationNuWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SABRInterpolationNuWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationNuWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationRhoWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SABRInterpolationRhoWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationRhoWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationRmsErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SABRInterpolationRmsErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationRmsErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationMaxErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SABRInterpolationMaxErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationMaxErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationEndCriteriaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SABRInterpolationEndCriteriaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationEndCriteriaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SABRInterpolationWeightsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    SABRInterpolationWeightsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SABRInterpolationWeightsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DXminWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    Interpolation2DXminWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~Interpolation2DXminWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DXmaxWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    Interpolation2DXmaxWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~Interpolation2DXmaxWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DXvaluesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    Interpolation2DXvaluesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~Interpolation2DXvaluesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DYminWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    Interpolation2DYminWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~Interpolation2DYminWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DYmaxWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    Interpolation2DYmaxWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~Interpolation2DYmaxWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DYvaluesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    Interpolation2DYvaluesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~Interpolation2DYvaluesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DzDataWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    Interpolation2DzDataWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~Interpolation2DzDataWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DIsInRangeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXValues;
    double mYValue;

    std::vector<bool> mReturnValue;

    string mError;

    Interpolation2DIsInRangeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XValues
      ,double YValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXValues(XValues)
      ,mYValue(YValue)
      {

      };

    //~Interpolation2DIsInRangeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Interpolation2DInterpolateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mXValue;
    double mYValue;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    Interpolation2DInterpolateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> XValue
      ,double YValue
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mXValue(XValue)
      ,mYValue(YValue)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~Interpolation2DInterpolateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
