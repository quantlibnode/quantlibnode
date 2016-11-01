// This is a generated file, modify: generate/templates/class_header.h

#ifndef pricingengines_h
#define pricingengines_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class BlackCalculator2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPayoffID;
    double mAtmForwardValue;
    double mStdDev;
    double mDeflator;

    string mReturnValue;

    string mError;

    BlackCalculator2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PayoffID
      ,double AtmForwardValue
      ,double StdDev
      ,double Deflator
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayoffID(PayoffID)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      {

      };

    //~BlackCalculator2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionType;
    double mStrike;
    double mAtmForwardValue;
    double mStdDev;
    double mDeflator;

    string mReturnValue;

    string mError;

    BlackCalculatorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionType
      ,double Strike
      ,double AtmForwardValue
      ,double StdDev
      ,double Deflator
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionType(OptionType)
      ,mStrike(Strike)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      {

      };

    //~BlackCalculatorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackScholesCalculator2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPayoffID;
    double mSpot;
    double mGrowth;
    double mStdDev;
    double mDeflator;

    string mReturnValue;

    string mError;

    BlackScholesCalculator2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PayoffID
      ,double Spot
      ,double Growth
      ,double StdDev
      ,double Deflator
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayoffID(PayoffID)
      ,mSpot(Spot)
      ,mGrowth(Growth)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      {

      };

    //~BlackScholesCalculator2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackScholesCalculatorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionType;
    double mStrike;
    double mSpot;
    double mGrowth;
    double mStdDev;
    double mDeflator;

    string mReturnValue;

    string mError;

    BlackScholesCalculatorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionType
      ,double Strike
      ,double Spot
      ,double Growth
      ,double StdDev
      ,double Deflator
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionType(OptionType)
      ,mStrike(Strike)
      ,mSpot(Spot)
      ,mGrowth(Growth)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      {

      };

    //~BlackScholesCalculatorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PricingEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mEngineID;
    string mProcessID;

    string mReturnValue;

    string mError;

    PricingEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string EngineID
      ,string ProcessID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEngineID(EngineID)
      ,mProcessID(ProcessID)
      {

      };

    //~PricingEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DiscountingSwapEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    string mReturnValue;

    string mError;

    DiscountingSwapEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~DiscountingSwapEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BinomialPricingEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mEngineID;
    string mProcessID;
    long mTimeSteps;

    string mReturnValue;

    string mError;

    BinomialPricingEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string EngineID
      ,string ProcessID
      ,long TimeSteps
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEngineID(EngineID)
      ,mProcessID(ProcessID)
      ,mTimeSteps(TimeSteps)
      {

      };

    //~BinomialPricingEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackSwaptionEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;
    ObjectHandler::property_t mVolTS;
    double mDisplacement;

    string mReturnValue;

    string mError;

    BlackSwaptionEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
      ,ObjectHandler::property_t VolTS
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      ,mVolTS(VolTS)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackSwaptionEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackSwaptionEngine2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;
    ObjectHandler::property_t mVol;
    double mDisplacement;
    string mDayCounter;

    string mReturnValue;

    string mError;

    BlackSwaptionEngine2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
      ,ObjectHandler::property_t Vol
      ,double Displacement
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      ,mVol(Vol)
      ,mDisplacement(Displacement)
      ,mDayCounter(DayCounter)
      {

      };

    //~BlackSwaptionEngine2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCapFloorEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;
    ObjectHandler::property_t mVolTS;
    double mDisplacement;

    string mReturnValue;

    string mError;

    BlackCapFloorEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
      ,ObjectHandler::property_t VolTS
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      ,mVolTS(VolTS)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackCapFloorEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCapFloorEngine2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;
    ObjectHandler::property_t mVol;
    double mDisplacement;
    string mDayCounter;

    string mReturnValue;

    string mError;

    BlackCapFloorEngine2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
      ,ObjectHandler::property_t Vol
      ,double Displacement
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      ,mVol(Vol)
      ,mDisplacement(Displacement)
      ,mDayCounter(DayCounter)
      {

      };

    //~BlackCapFloorEngine2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AnalyticCapFloorEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mHandleModel;

    string mReturnValue;

    string mError;

    AnalyticCapFloorEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string HandleModel
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mHandleModel(HandleModel)
      {

      };

    //~AnalyticCapFloorEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    BondEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~BondEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class JamshidianSwaptionEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mModel;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    JamshidianSwaptionEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Model
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mModel(Model)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~JamshidianSwaptionEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TreeSwaptionEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mModel;
    long mNsteps;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    TreeSwaptionEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Model
      ,long Nsteps
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mModel(Model)
      ,mNsteps(Nsteps)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~TreeSwaptionEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ModelG2SwaptionEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mModel;
    double mRange;
    long mIntervals;

    string mReturnValue;

    string mError;

    ModelG2SwaptionEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Model
      ,double Range
      ,long Intervals
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mModel(Model)
      ,mRange(Range)
      ,mIntervals(Intervals)
      {

      };

    //~ModelG2SwaptionEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackCalculatorValueWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackCalculatorValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorDeltaForwardWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackCalculatorDeltaForwardWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackCalculatorDeltaForwardWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorDeltaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mSpot;

    double mReturnValue;

    string mError;

    BlackCalculatorDeltaWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Spot
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSpot(Spot)
      {

      };

    //~BlackCalculatorDeltaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorElasticityForwardWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackCalculatorElasticityForwardWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackCalculatorElasticityForwardWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorElasticityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mSpot;

    double mReturnValue;

    string mError;

    BlackCalculatorElasticityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Spot
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSpot(Spot)
      {

      };

    //~BlackCalculatorElasticityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorGammaForwardWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackCalculatorGammaForwardWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackCalculatorGammaForwardWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorGammaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mSpot;

    double mReturnValue;

    string mError;

    BlackCalculatorGammaWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Spot
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSpot(Spot)
      {

      };

    //~BlackCalculatorGammaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorThetaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mSpot;
    double mTimeToMaturity;

    double mReturnValue;

    string mError;

    BlackCalculatorThetaWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Spot
      ,double TimeToMaturity
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSpot(Spot)
      ,mTimeToMaturity(TimeToMaturity)
      {

      };

    //~BlackCalculatorThetaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorThetaPerDayWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mSpot;
    double mTimeToMaturity;

    double mReturnValue;

    string mError;

    BlackCalculatorThetaPerDayWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Spot
      ,double TimeToMaturity
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSpot(Spot)
      ,mTimeToMaturity(TimeToMaturity)
      {

      };

    //~BlackCalculatorThetaPerDayWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorVegaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTimeToMaturity;

    double mReturnValue;

    string mError;

    BlackCalculatorVegaWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double TimeToMaturity
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeToMaturity(TimeToMaturity)
      {

      };

    //~BlackCalculatorVegaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorRhoWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTimeToMaturity;

    double mReturnValue;

    string mError;

    BlackCalculatorRhoWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double TimeToMaturity
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeToMaturity(TimeToMaturity)
      {

      };

    //~BlackCalculatorRhoWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorDividendRhoWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTimeToMaturity;

    double mReturnValue;

    string mError;

    BlackCalculatorDividendRhoWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double TimeToMaturity
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeToMaturity(TimeToMaturity)
      {

      };

    //~BlackCalculatorDividendRhoWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorItmCashProbabilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackCalculatorItmCashProbabilityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackCalculatorItmCashProbabilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorItmAssetProbabilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackCalculatorItmAssetProbabilityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackCalculatorItmAssetProbabilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorStrikeSensitivityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackCalculatorStrikeSensitivityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackCalculatorStrikeSensitivityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorAlphaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackCalculatorAlphaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackCalculatorAlphaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCalculatorBetaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackCalculatorBetaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackCalculatorBetaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackScholesCalculatorDeltaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackScholesCalculatorDeltaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackScholesCalculatorDeltaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackScholesCalculatorElasticityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackScholesCalculatorElasticityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackScholesCalculatorElasticityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackScholesCalculatorGammaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BlackScholesCalculatorGammaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BlackScholesCalculatorGammaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackScholesCalculatorThetaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTimeToMaturity;

    double mReturnValue;

    string mError;

    BlackScholesCalculatorThetaWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double TimeToMaturity
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeToMaturity(TimeToMaturity)
      {

      };

    //~BlackScholesCalculatorThetaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackScholesCalculatorThetaPerDayWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTimeToMaturity;

    double mReturnValue;

    string mError;

    BlackScholesCalculatorThetaPerDayWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double TimeToMaturity
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeToMaturity(TimeToMaturity)
      {

      };

    //~BlackScholesCalculatorThetaPerDayWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormulaWorker : public Nan::AsyncWorker {
  public:
    string mOptionType;
    double mStrike;
    double mAtmForwardValue;
    double mStdDev;
    double mDeflator;
    double mDisplacement;

    double mReturnValue;

    string mError;

    BlackFormulaWorker(
      Nan::Callback *callback
      ,string OptionType
      ,double Strike
      ,double AtmForwardValue
      ,double StdDev
      ,double Deflator
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mOptionType(OptionType)
      ,mStrike(Strike)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackFormulaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormulaCashItmProbabilityWorker : public Nan::AsyncWorker {
  public:
    string mOptionType;
    double mStrike;
    double mAtmForwardValue;
    double mStdDev;
    double mDisplacement;

    double mReturnValue;

    string mError;

    BlackFormulaCashItmProbabilityWorker(
      Nan::Callback *callback
      ,string OptionType
      ,double Strike
      ,double AtmForwardValue
      ,double StdDev
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mOptionType(OptionType)
      ,mStrike(Strike)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackFormulaCashItmProbabilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormulaImpliedStdDevApproximationWorker : public Nan::AsyncWorker {
  public:
    string mOptionType;
    double mStrike;
    double mAtmForwardValue;
    double mOptionPrice;
    double mDeflator;
    double mDisplacement;

    double mReturnValue;

    string mError;

    BlackFormulaImpliedStdDevApproximationWorker(
      Nan::Callback *callback
      ,string OptionType
      ,double Strike
      ,double AtmForwardValue
      ,double OptionPrice
      ,double Deflator
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mOptionType(OptionType)
      ,mStrike(Strike)
      ,mAtmForwardValue(AtmForwardValue)
      ,mOptionPrice(OptionPrice)
      ,mDeflator(Deflator)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackFormulaImpliedStdDevApproximationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormulaImpliedStdDevWorker : public Nan::AsyncWorker {
  public:
    string mOptionType;
    double mStrike;
    double mAtmForwardValue;
    double mOptionPrice;
    double mDeflator;
    double mDisplacement;
    double mGuess;
    double mAccuracy;
    ObjectHandler::property_t mMaxIter;

    double mReturnValue;

    string mError;

    BlackFormulaImpliedStdDevWorker(
      Nan::Callback *callback
      ,string OptionType
      ,double Strike
      ,double AtmForwardValue
      ,double OptionPrice
      ,double Deflator
      ,double Displacement
      ,double Guess
      ,double Accuracy
      ,ObjectHandler::property_t MaxIter
    ):
      Nan::AsyncWorker(callback)
      ,mOptionType(OptionType)
      ,mStrike(Strike)
      ,mAtmForwardValue(AtmForwardValue)
      ,mOptionPrice(OptionPrice)
      ,mDeflator(Deflator)
      ,mDisplacement(Displacement)
      ,mGuess(Guess)
      ,mAccuracy(Accuracy)
      ,mMaxIter(MaxIter)
      {

      };

    //~BlackFormulaImpliedStdDevWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormulaStdDevDerivativeWorker : public Nan::AsyncWorker {
  public:
    double mStrike;
    double mAtmForwardValue;
    double mStdDev;
    double mDeflator;
    double mDisplacement;

    double mReturnValue;

    string mError;

    BlackFormulaStdDevDerivativeWorker(
      Nan::Callback *callback
      ,double Strike
      ,double AtmForwardValue
      ,double StdDev
      ,double Deflator
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mStrike(Strike)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackFormulaStdDevDerivativeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BachelierBlackFormulaWorker : public Nan::AsyncWorker {
  public:
    string mOptionType;
    double mStrike;
    double mAtmForwardValue;
    double mStdDev;
    double mDeflator;

    double mReturnValue;

    string mError;

    BachelierBlackFormulaWorker(
      Nan::Callback *callback
      ,string OptionType
      ,double Strike
      ,double AtmForwardValue
      ,double StdDev
      ,double Deflator
    ):
      Nan::AsyncWorker(callback)
      ,mOptionType(OptionType)
      ,mStrike(Strike)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      {

      };

    //~BachelierBlackFormulaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormula2Worker : public Nan::AsyncWorker {
  public:
    string mPayoff;
    double mAtmForwardValue;
    double mStdDev;
    double mDeflator;
    double mDisplacement;

    double mReturnValue;

    string mError;

    BlackFormula2Worker(
      Nan::Callback *callback
      ,string Payoff
      ,double AtmForwardValue
      ,double StdDev
      ,double Deflator
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mPayoff(Payoff)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackFormula2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormulaCashItmProbability2Worker : public Nan::AsyncWorker {
  public:
    string mPayoff;
    double mAtmForwardValue;
    double mStdDev;
    double mDisplacement;

    double mReturnValue;

    string mError;

    BlackFormulaCashItmProbability2Worker(
      Nan::Callback *callback
      ,string Payoff
      ,double AtmForwardValue
      ,double StdDev
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mPayoff(Payoff)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackFormulaCashItmProbability2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormulaImpliedStdDevApproximation2Worker : public Nan::AsyncWorker {
  public:
    string mPayoff;
    double mAtmForwardValue;
    double mOptionPrice;
    double mDeflator;
    double mDisplacement;

    double mReturnValue;

    string mError;

    BlackFormulaImpliedStdDevApproximation2Worker(
      Nan::Callback *callback
      ,string Payoff
      ,double AtmForwardValue
      ,double OptionPrice
      ,double Deflator
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mPayoff(Payoff)
      ,mAtmForwardValue(AtmForwardValue)
      ,mOptionPrice(OptionPrice)
      ,mDeflator(Deflator)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackFormulaImpliedStdDevApproximation2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormulaImpliedStdDev2Worker : public Nan::AsyncWorker {
  public:
    string mPayoffID;
    double mAtmForwardValue;
    double mOptionPrice;
    double mDeflator;
    double mDisplacement;
    double mGuess;
    double mAccuracy;
    ObjectHandler::property_t mMaxIter;

    double mReturnValue;

    string mError;

    BlackFormulaImpliedStdDev2Worker(
      Nan::Callback *callback
      ,string PayoffID
      ,double AtmForwardValue
      ,double OptionPrice
      ,double Deflator
      ,double Displacement
      ,double Guess
      ,double Accuracy
      ,ObjectHandler::property_t MaxIter
    ):
      Nan::AsyncWorker(callback)
      ,mPayoffID(PayoffID)
      ,mAtmForwardValue(AtmForwardValue)
      ,mOptionPrice(OptionPrice)
      ,mDeflator(Deflator)
      ,mDisplacement(Displacement)
      ,mGuess(Guess)
      ,mAccuracy(Accuracy)
      ,mMaxIter(MaxIter)
      {

      };

    //~BlackFormulaImpliedStdDev2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackFormulaStdDevDerivative2Worker : public Nan::AsyncWorker {
  public:
    string mPayoffID;
    double mAtmForwardValue;
    double mStdDev;
    double mDeflator;
    double mDisplacement;

    double mReturnValue;

    string mError;

    BlackFormulaStdDevDerivative2Worker(
      Nan::Callback *callback
      ,string PayoffID
      ,double AtmForwardValue
      ,double StdDev
      ,double Deflator
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mPayoffID(PayoffID)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      ,mDisplacement(Displacement)
      {

      };

    //~BlackFormulaStdDevDerivative2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BachelierBlackFormula2Worker : public Nan::AsyncWorker {
  public:
    string mPayoff;
    double mAtmForwardValue;
    double mStdDev;
    double mDeflator;

    double mReturnValue;

    string mError;

    BachelierBlackFormula2Worker(
      Nan::Callback *callback
      ,string Payoff
      ,double AtmForwardValue
      ,double StdDev
      ,double Deflator
    ):
      Nan::AsyncWorker(callback)
      ,mPayoff(Payoff)
      ,mAtmForwardValue(AtmForwardValue)
      ,mStdDev(StdDev)
      ,mDeflator(Deflator)
      {

      };

    //~BachelierBlackFormula2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
