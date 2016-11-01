// This is a generated file, modify: generate/templates/class_header.h

#ifndef credit_h
#define credit_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class CreditDefaultSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mBuyerSeller;
    double mNotional;
    double mUpfront;
    double mSpread;
    string mPremiumSchedule;
    string mPaymentConvention;
    string mDayCounter;
    bool mSettlesAccrual;
    bool mPayAtDefault;
    ObjectHandler::property_t mProtectionStart;
    ObjectHandler::property_t mUpfrontDate;

    string mReturnValue;

    string mError;

    CreditDefaultSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string BuyerSeller
      ,double Notional
      ,double Upfront
      ,double Spread
      ,string PremiumSchedule
      ,string PaymentConvention
      ,string DayCounter
      ,bool SettlesAccrual
      ,bool PayAtDefault
      ,ObjectHandler::property_t ProtectionStart
      ,ObjectHandler::property_t UpfrontDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBuyerSeller(BuyerSeller)
      ,mNotional(Notional)
      ,mUpfront(Upfront)
      ,mSpread(Spread)
      ,mPremiumSchedule(PremiumSchedule)
      ,mPaymentConvention(PaymentConvention)
      ,mDayCounter(DayCounter)
      ,mSettlesAccrual(SettlesAccrual)
      ,mPayAtDefault(PayAtDefault)
      ,mProtectionStart(ProtectionStart)
      ,mUpfrontDate(UpfrontDate)
      {

      };

    //~CreditDefaultSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MidPointCdsEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mDefaultCurve;
    double mRecoveryRate;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    MidPointCdsEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t DefaultCurve
      ,double RecoveryRate
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDefaultCurve(DefaultCurve)
      ,mRecoveryRate(RecoveryRate)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~MidPointCdsEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HazardRateCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mCurveDates;
    std::vector<double> mCurveRates;
    string mDayCounter;

    string mReturnValue;

    string mError;

    HazardRateCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> CurveDates
      ,std::vector<double> CurveRates
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveDates(CurveDates)
      ,mCurveRates(CurveRates)
      ,mDayCounter(DayCounter)
      {

      };

    //~HazardRateCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SpreadCdsHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mRunningSpread;
    string mTenor;
    ObjectHandler::property_t mSettlementDays;
    string mCalendar;
    string mFrequency;
    string mPaymentConvention;
    string mGenRule;
    string mDayCounter;
    double mRecoveryRate;
    ObjectHandler::property_t mDiscountingCurve;
    bool mSettleAccrual;
    bool mPayAtDefault;

    string mReturnValue;

    string mError;

    SpreadCdsHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t RunningSpread
      ,string Tenor
      ,ObjectHandler::property_t SettlementDays
      ,string Calendar
      ,string Frequency
      ,string PaymentConvention
      ,string GenRule
      ,string DayCounter
      ,double RecoveryRate
      ,ObjectHandler::property_t DiscountingCurve
      ,bool SettleAccrual
      ,bool PayAtDefault
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRunningSpread(RunningSpread)
      ,mTenor(Tenor)
      ,mSettlementDays(SettlementDays)
      ,mCalendar(Calendar)
      ,mFrequency(Frequency)
      ,mPaymentConvention(PaymentConvention)
      ,mGenRule(GenRule)
      ,mDayCounter(DayCounter)
      ,mRecoveryRate(RecoveryRate)
      ,mDiscountingCurve(DiscountingCurve)
      ,mSettleAccrual(SettleAccrual)
      ,mPayAtDefault(PayAtDefault)
      {

      };

    //~SpreadCdsHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class UpfrontCdsHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mUpfrontSpread;
    double mRunningSpread;
    string mTenor;
    ObjectHandler::property_t mSettlementDays;
    string mCalendar;
    string mFrequency;
    string mPaymentConvention;
    string mGenRule;
    string mDayCounter;
    double mRecRate;
    ObjectHandler::property_t mDiscCurve;
    ObjectHandler::property_t mUpfSettlDays;
    bool mSettlAccr;
    bool mPayAtDefault;

    string mReturnValue;

    string mError;

    UpfrontCdsHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t UpfrontSpread
      ,double RunningSpread
      ,string Tenor
      ,ObjectHandler::property_t SettlementDays
      ,string Calendar
      ,string Frequency
      ,string PaymentConvention
      ,string GenRule
      ,string DayCounter
      ,double RecRate
      ,ObjectHandler::property_t DiscCurve
      ,ObjectHandler::property_t UpfSettlDays
      ,bool SettlAccr
      ,bool PayAtDefault
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mUpfrontSpread(UpfrontSpread)
      ,mRunningSpread(RunningSpread)
      ,mTenor(Tenor)
      ,mSettlementDays(SettlementDays)
      ,mCalendar(Calendar)
      ,mFrequency(Frequency)
      ,mPaymentConvention(PaymentConvention)
      ,mGenRule(GenRule)
      ,mDayCounter(DayCounter)
      ,mRecRate(RecRate)
      ,mDiscCurve(DiscCurve)
      ,mUpfSettlDays(UpfSettlDays)
      ,mSettlAccr(SettlAccr)
      ,mPayAtDefault(PayAtDefault)
      {

      };

    //~UpfrontCdsHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseHazardRateCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mHelpers;
    string mDayCounter;
    string mCalendar;
    string mInterpolation;
    double mAccuracy;

    string mReturnValue;

    string mError;

    PiecewiseHazardRateCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> Helpers
      ,string DayCounter
      ,string Calendar
      ,string Interpolation
      ,double Accuracy
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mHelpers(Helpers)
      ,mDayCounter(DayCounter)
      ,mCalendar(Calendar)
      ,mInterpolation(Interpolation)
      ,mAccuracy(Accuracy)
      {

      };

    //~PiecewiseHazardRateCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseFlatForwardCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mReferenceDate;
    std::vector<string> mRateHelpers;
    string mDayCounter;
    double mAccuracy;

    string mReturnValue;

    string mError;

    PiecewiseFlatForwardCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t ReferenceDate
      ,std::vector<string> RateHelpers
      ,string DayCounter
      ,double Accuracy
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mReferenceDate(ReferenceDate)
      ,mRateHelpers(RateHelpers)
      ,mDayCounter(DayCounter)
      ,mAccuracy(Accuracy)
      {

      };

    //~PiecewiseFlatForwardCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RiskyFixedBondWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mBondname;
    string mCurrency;
    double mRecovery;
    ObjectHandler::property_t mDefaultCurve;
    string mSchedule;
    double mRate;
    string mDayCounter;
    string mPaymentConvention;
    double mNotional;
    ObjectHandler::property_t mDiscountingCurve;
    ObjectHandler::property_t mPricingDate;

    string mReturnValue;

    string mError;

    RiskyFixedBondWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Bondname
      ,string Currency
      ,double Recovery
      ,ObjectHandler::property_t DefaultCurve
      ,string Schedule
      ,double Rate
      ,string DayCounter
      ,string PaymentConvention
      ,double Notional
      ,ObjectHandler::property_t DiscountingCurve
      ,ObjectHandler::property_t PricingDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBondname(Bondname)
      ,mCurrency(Currency)
      ,mRecovery(Recovery)
      ,mDefaultCurve(DefaultCurve)
      ,mSchedule(Schedule)
      ,mRate(Rate)
      ,mDayCounter(DayCounter)
      ,mPaymentConvention(PaymentConvention)
      ,mNotional(Notional)
      ,mDiscountingCurve(DiscountingCurve)
      ,mPricingDate(PricingDate)
      {

      };

    //~RiskyFixedBondWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IssuerWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDefaultCurves;
    string mDefaultEvents;

    string mReturnValue;

    string mError;

    IssuerWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string DefaultCurves
      ,string DefaultEvents
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDefaultCurves(DefaultCurves)
      ,mDefaultEvents(DefaultEvents)
      {

      };

    //~IssuerWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DefaultEventWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mEventType;
    ObjectHandler::property_t mEventDate;
    string mCurrency;
    string mSeniority;
    ObjectHandler::property_t mSettlementDate;
    double mSettledRecovery;

    string mReturnValue;

    string mError;

    DefaultEventWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string EventType
      ,ObjectHandler::property_t EventDate
      ,string Currency
      ,string Seniority
      ,ObjectHandler::property_t SettlementDate
      ,double SettledRecovery
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEventType(EventType)
      ,mEventDate(EventDate)
      ,mCurrency(Currency)
      ,mSeniority(Seniority)
      ,mSettlementDate(SettlementDate)
      ,mSettledRecovery(SettledRecovery)
      {

      };

    //~DefaultEventWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SyntheticCDOWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mBasket;
    string mBuyerSeller;
    string mPremiumSchedule;
    double mUpfront;
    double mSpread;
    string mDayCounter;
    string mPaymentConvention;

    string mReturnValue;

    string mError;

    SyntheticCDOWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Basket
      ,string BuyerSeller
      ,string PremiumSchedule
      ,double Upfront
      ,double Spread
      ,string DayCounter
      ,string PaymentConvention
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBasket(Basket)
      ,mBuyerSeller(BuyerSeller)
      ,mPremiumSchedule(PremiumSchedule)
      ,mUpfront(Upfront)
      ,mSpread(Spread)
      ,mDayCounter(DayCounter)
      ,mPaymentConvention(PaymentConvention)
      {

      };

    //~SyntheticCDOWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MidPointCDOEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    MidPointCDOEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~MidPointCDOEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class NthToDefaultWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mBasket;
    long mOrder;
    string mBuyerSeller;
    string mPremiumSchedule;
    double mUpfront;
    double mSpread;
    string mDayCounter;
    double mNotional;
    bool mSettlesAccrual;

    string mReturnValue;

    string mError;

    NthToDefaultWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Basket
      ,long Order
      ,string BuyerSeller
      ,string PremiumSchedule
      ,double Upfront
      ,double Spread
      ,string DayCounter
      ,double Notional
      ,bool SettlesAccrual
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBasket(Basket)
      ,mOrder(Order)
      ,mBuyerSeller(BuyerSeller)
      ,mPremiumSchedule(PremiumSchedule)
      ,mUpfront(Upfront)
      ,mSpread(Spread)
      ,mDayCounter(DayCounter)
      ,mNotional(Notional)
      ,mSettlesAccrual(SettlesAccrual)
      {

      };

    //~NthToDefaultWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IntegralNtdEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mIntegrationStep;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    IntegralNtdEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string IntegrationStep
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIntegrationStep(IntegrationStep)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~IntegralNtdEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackCdsOptionEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mDefaultCurve;
    double mRecoveryRate;
    ObjectHandler::property_t mYieldCurve;
    ObjectHandler::property_t mBlackVol;

    string mReturnValue;

    string mError;

    BlackCdsOptionEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t DefaultCurve
      ,double RecoveryRate
      ,ObjectHandler::property_t YieldCurve
      ,ObjectHandler::property_t BlackVol
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDefaultCurve(DefaultCurve)
      ,mRecoveryRate(RecoveryRate)
      ,mYieldCurve(YieldCurve)
      ,mBlackVol(BlackVol)
      {

      };

    //~BlackCdsOptionEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CDSOptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mUnderlyingCDS;
    string mExercise;

    string mReturnValue;

    string mError;

    CDSOptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string UnderlyingCDS
      ,string Exercise
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mUnderlyingCDS(UnderlyingCDS)
      ,mExercise(Exercise)
      {

      };

    //~CDSOptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BaseCorrelationTermStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mInterpolatorType;
    long mSettlementDays;
    string mCalendar;
    string mConvention;
    std::vector<ObjectHandler::property_t> mTenors;
    std::vector<double> mLossLevel;
    std::vector< std::vector<ObjectHandler::property_t> > mCorrelations;
    string mDayCounter;

    string mReturnValue;

    string mError;

    BaseCorrelationTermStructureWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string InterpolatorType
      ,long SettlementDays
      ,string Calendar
      ,string Convention
      ,std::vector<ObjectHandler::property_t> Tenors
      ,std::vector<double> LossLevel
      ,std::vector< std::vector<ObjectHandler::property_t> > Correlations
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mInterpolatorType(InterpolatorType)
      ,mSettlementDays(SettlementDays)
      ,mCalendar(Calendar)
      ,mConvention(Convention)
      ,mTenors(Tenors)
      ,mLossLevel(LossLevel)
      ,mCorrelations(Correlations)
      ,mDayCounter(DayCounter)
      {

      };

    //~BaseCorrelationTermStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CdsCouponLegNPVWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CdsCouponLegNPVWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CdsCouponLegNPVWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CdsDefaultLegNPVWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CdsDefaultLegNPVWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CdsDefaultLegNPVWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CdsFairSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CdsFairSpreadWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CdsFairSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CdsFairUpfrontWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CdsFairUpfrontWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CdsFairUpfrontWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HRDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    HRDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HRDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    HRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CdsOptionImpliedVolWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mPrice;
    ObjectHandler::property_t mYieldCurve;
    ObjectHandler::property_t mDefaultCurve;
    double mRecoveryRate;

    double mReturnValue;

    string mError;

    CdsOptionImpliedVolWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Price
      ,ObjectHandler::property_t YieldCurve
      ,ObjectHandler::property_t DefaultCurve
      ,double RecoveryRate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPrice(Price)
      ,mYieldCurve(YieldCurve)
      ,mDefaultCurve(DefaultCurve)
      ,mRecoveryRate(RecoveryRate)
      {

      };

    //~CdsOptionImpliedVolWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BaseCorrelationValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mDate;
    double mLossLevel;

    double mReturnValue;

    string mError;

    BaseCorrelationValueWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Date
      ,double LossLevel
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDate(Date)
      ,mLossLevel(LossLevel)
      {

      };

    //~BaseCorrelationValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
