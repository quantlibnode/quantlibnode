/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef calibrationhelpers_h
#define calibrationhelpers_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class SwaptionHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionTenor;
    string mLength;
    ObjectHandler::property_t mVolatility;
    string mIborIndex;
    string mFixedLegTenor;
    string mFixedLegDayCounter;
    string mFloatingLegDayCounter;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    SwaptionHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionTenor
      ,string Length
      ,ObjectHandler::property_t Volatility
      ,string IborIndex
      ,string FixedLegTenor
      ,string FixedLegDayCounter
      ,string FloatingLegDayCounter
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      ,mLength(Length)
      ,mVolatility(Volatility)
      ,mIborIndex(IborIndex)
      ,mFixedLegTenor(FixedLegTenor)
      ,mFixedLegDayCounter(FixedLegDayCounter)
      ,mFloatingLegDayCounter(FloatingLegDayCounter)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~SwaptionHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalibrationHelperSetPricingEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPricingEngine;

    string mError;

    CalibrationHelperSetPricingEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PricingEngine
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPricingEngine(PricingEngine)
      {

      };

    //~CalibrationHelperSetPricingEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalibrationHelperImpliedVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTargetValue;
    double mAccuracy;
    long mMaxEvaluations;
    double mMinVol;
    double mMaxVol;

    double mReturnValue;

    string mError;

    CalibrationHelperImpliedVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double TargetValue
      ,double Accuracy
      ,long MaxEvaluations
      ,double MinVol
      ,double MaxVol
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTargetValue(TargetValue)
      ,mAccuracy(Accuracy)
      ,mMaxEvaluations(MaxEvaluations)
      ,mMinVol(MinVol)
      ,mMaxVol(MaxVol)
      {

      };

    //~CalibrationHelperImpliedVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionHelperModelValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SwaptionHelperModelValueWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwaptionHelperModelValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OneFactorAffineModelCalibrateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mCalibrationHelpers;
    string mMethod;
    string mEndCriteria;
    string mConstraint;
    std::vector<double> mWeights;
    std::vector<bool> mFixedCoeff;

    string mError;

    OneFactorAffineModelCalibrateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> CalibrationHelpers
      ,string Method
      ,string EndCriteria
      ,string Constraint
      ,std::vector<double> Weights
      ,std::vector<bool> FixedCoeff
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCalibrationHelpers(CalibrationHelpers)
      ,mMethod(Method)
      ,mEndCriteria(EndCriteria)
      ,mConstraint(Constraint)
      ,mWeights(Weights)
      ,mFixedCoeff(FixedCoeff)
      {

      };

    //~OneFactorAffineModelCalibrateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ModelG2CalibrateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mCalibrationHelpers;
    string mMethod;
    string mEndCriteria;
    string mConstraint;
    std::vector<double> mWeights;
    std::vector<bool> mFixedCoeff;

    string mError;

    ModelG2CalibrateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> CalibrationHelpers
      ,string Method
      ,string EndCriteria
      ,string Constraint
      ,std::vector<double> Weights
      ,std::vector<bool> FixedCoeff
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCalibrationHelpers(CalibrationHelpers)
      ,mMethod(Method)
      ,mEndCriteria(EndCriteria)
      ,mConstraint(Constraint)
      ,mWeights(Weights)
      ,mFixedCoeff(FixedCoeff)
      {

      };

    //~ModelG2CalibrateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
