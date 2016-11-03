/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef marketmodels_h
#define marketmodels_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class FlatVolWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mVolatilities;
    string mCorrelations;
    string mEvolutionDescription;
    long mFactors;
    std::vector<double> mInitialRates;
    std::vector<double> mDisplacements;

    string mReturnValue;

    string mError;

    FlatVolWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> Volatilities
      ,string Correlations
      ,string EvolutionDescription
      ,long Factors
      ,std::vector<double> InitialRates
      ,std::vector<double> Displacements
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mVolatilities(Volatilities)
      ,mCorrelations(Correlations)
      ,mEvolutionDescription(EvolutionDescription)
      ,mFactors(Factors)
      ,mInitialRates(InitialRates)
      ,mDisplacements(Displacements)
      {

      };

    //~FlatVolWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdVolWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mA;
    double mB;
    double mC;
    double mD;
    std::vector<double> mKs;
    string mCorrelations;
    string mEvolutionDescription;
    long mFactors;
    std::vector<double> mInitialRates;
    std::vector<double> mDisplacements;

    string mReturnValue;

    string mError;

    AbcdVolWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double A
      ,double B
      ,double C
      ,double D
      ,std::vector<double> Ks
      ,string Correlations
      ,string EvolutionDescription
      ,long Factors
      ,std::vector<double> InitialRates
      ,std::vector<double> Displacements
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mA(A)
      ,mB(B)
      ,mC(C)
      ,mD(D)
      ,mKs(Ks)
      ,mCorrelations(Correlations)
      ,mEvolutionDescription(EvolutionDescription)
      ,mFactors(Factors)
      ,mInitialRates(InitialRates)
      ,mDisplacements(Displacements)
      {

      };

    //~AbcdVolWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PseudoRootFacadeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCalibrator;

    string mReturnValue;

    string mError;

    PseudoRootFacadeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Calibrator
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCalibrator(Calibrator)
      {

      };

    //~PseudoRootFacadeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CotSwapToFwdAdapterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCoterminalModel;

    string mReturnValue;

    string mError;

    CotSwapToFwdAdapterWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CoterminalModel
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCoterminalModel(CoterminalModel)
      {

      };

    //~CotSwapToFwdAdapterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FwdPeriodAdapterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mLargeModel;
    long mPeriod;
    long mOffset;
    std::vector<double> mDisplacements;

    string mReturnValue;

    string mError;

    FwdPeriodAdapterWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string LargeModel
      ,long Period
      ,long Offset
      ,std::vector<double> Displacements
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLargeModel(LargeModel)
      ,mPeriod(Period)
      ,mOffset(Offset)
      ,mDisplacements(Displacements)
      {

      };

    //~FwdPeriodAdapterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FwdToCotSwapAdapterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mForwardModel;

    string mReturnValue;

    string mError;

    FwdToCotSwapAdapterWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string ForwardModel
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mForwardModel(ForwardModel)
      {

      };

    //~FwdToCotSwapAdapterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FlatVolFactoryWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mLongTermCorr;
    double mBeta;
    std::vector<double> mTimes;
    std::vector<double> mVolatilities;
    ObjectHandler::property_t mYieldCurve;
    double mDisplacement;

    string mReturnValue;

    string mError;

    FlatVolFactoryWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double LongTermCorr
      ,double Beta
      ,std::vector<double> Times
      ,std::vector<double> Volatilities
      ,ObjectHandler::property_t YieldCurve
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLongTermCorr(LongTermCorr)
      ,mBeta(Beta)
      ,mTimes(Times)
      ,mVolatilities(Volatilities)
      ,mYieldCurve(YieldCurve)
      ,mDisplacement(Displacement)
      {

      };

    //~FlatVolFactoryWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelInitialRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    MarketModelInitialRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelInitialRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelDisplacementsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    MarketModelDisplacementsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelDisplacementsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelNumberOfRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    MarketModelNumberOfRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelNumberOfRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelNumberOfFactorsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    MarketModelNumberOfFactorsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelNumberOfFactorsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelNumberOfStepsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    MarketModelNumberOfStepsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelNumberOfStepsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelPseudoRootWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    MarketModelPseudoRootWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~MarketModelPseudoRootWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelCovarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    MarketModelCovarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~MarketModelCovarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelTotalCovarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    MarketModelTotalCovarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~MarketModelTotalCovarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelTimeDependentVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    std::vector<double> mReturnValue;

    string mError;

    MarketModelTimeDependentVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~MarketModelTimeDependentVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CoterminalSwapForwardJacobianWorker : public Nan::AsyncWorker {
  public:
    string mCurveState;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    CoterminalSwapForwardJacobianWorker(
      Nan::Callback *callback
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mCurveState(CurveState)
      {

      };

    //~CoterminalSwapForwardJacobianWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CoterminalSwapZedMatrixWorker : public Nan::AsyncWorker {
  public:
    string mCurveState;
    double mDisplacement;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    CoterminalSwapZedMatrixWorker(
      Nan::Callback *callback
      ,string CurveState
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mCurveState(CurveState)
      ,mDisplacement(Displacement)
      {

      };

    //~CoterminalSwapZedMatrixWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CoinitialSwapForwardJacobianWorker : public Nan::AsyncWorker {
  public:
    string mCurveState;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    CoinitialSwapForwardJacobianWorker(
      Nan::Callback *callback
      ,string CurveState
    ):
      Nan::AsyncWorker(callback)
      ,mCurveState(CurveState)
      {

      };

    //~CoinitialSwapForwardJacobianWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CoinitialSwapZedMatrixWorker : public Nan::AsyncWorker {
  public:
    string mCurveState;
    double mDisplacement;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    CoinitialSwapZedMatrixWorker(
      Nan::Callback *callback
      ,string CurveState
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mCurveState(CurveState)
      ,mDisplacement(Displacement)
      {

      };

    //~CoinitialSwapZedMatrixWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmSwapForwardJacobianWorker : public Nan::AsyncWorker {
  public:
    string mCurveState;
    long mSpanningForwards;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    CmSwapForwardJacobianWorker(
      Nan::Callback *callback
      ,string CurveState
      ,long SpanningForwards
    ):
      Nan::AsyncWorker(callback)
      ,mCurveState(CurveState)
      ,mSpanningForwards(SpanningForwards)
      {

      };

    //~CmSwapForwardJacobianWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmSwapZedMatrixWorker : public Nan::AsyncWorker {
  public:
    string mCurveState;
    long mSpanningForwards;
    double mDisplacement;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    CmSwapZedMatrixWorker(
      Nan::Callback *callback
      ,string CurveState
      ,long SpanningForwards
      ,double Displacement
    ):
      Nan::AsyncWorker(callback)
      ,mCurveState(CurveState)
      ,mSpanningForwards(SpanningForwards)
      ,mDisplacement(Displacement)
      {

      };

    //~CmSwapZedMatrixWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AnnuityWorker : public Nan::AsyncWorker {
  public:
    string mCurveState;
    long mStartIndex;
    long mEndIndex;
    long mNumeraireIndex;

    double mReturnValue;

    string mError;

    AnnuityWorker(
      Nan::Callback *callback
      ,string CurveState
      ,long StartIndex
      ,long EndIndex
      ,long NumeraireIndex
    ):
      Nan::AsyncWorker(callback)
      ,mCurveState(CurveState)
      ,mStartIndex(StartIndex)
      ,mEndIndex(EndIndex)
      ,mNumeraireIndex(NumeraireIndex)
      {

      };

    //~AnnuityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapDerivativeWorker : public Nan::AsyncWorker {
  public:
    string mCurveState;
    long mStartIndex;
    long mEndIndex;
    long mFwdRateIndex;

    double mReturnValue;

    string mError;

    SwapDerivativeWorker(
      Nan::Callback *callback
      ,string CurveState
      ,long StartIndex
      ,long EndIndex
      ,long FwdRateIndex
    ):
      Nan::AsyncWorker(callback)
      ,mCurveState(CurveState)
      ,mStartIndex(StartIndex)
      ,mEndIndex(EndIndex)
      ,mFwdRateIndex(FwdRateIndex)
      {

      };

    //~SwapDerivativeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateVolDifferencesWorker : public Nan::AsyncWorker {
  public:
    string mMarketModel1;
    string mMarketModel2;

    std::vector<double> mReturnValue;

    string mError;

    RateVolDifferencesWorker(
      Nan::Callback *callback
      ,string MarketModel1
      ,string MarketModel2
    ):
      Nan::AsyncWorker(callback)
      ,mMarketModel1(MarketModel1)
      ,mMarketModel2(MarketModel2)
      {

      };

    //~RateVolDifferencesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateInstVolDifferencesWorker : public Nan::AsyncWorker {
  public:
    string mMarketModel1;
    string mMarketModel2;
    long mIndex;

    std::vector<double> mReturnValue;

    string mError;

    RateInstVolDifferencesWorker(
      Nan::Callback *callback
      ,string MarketModel1
      ,string MarketModel2
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mMarketModel1(MarketModel1)
      ,mMarketModel2(MarketModel2)
      ,mIndex(Index)
      {

      };

    //~RateInstVolDifferencesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
