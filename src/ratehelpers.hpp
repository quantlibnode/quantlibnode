/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef ratehelpers_h
#define ratehelpers_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class DepositRateHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mRate;
    string mIborIndex;

    string mReturnValue;

    string mError;

    DepositRateHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Rate
      ,string IborIndex
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRate(Rate)
      ,mIborIndex(IborIndex)
      {

      };

    //~DepositRateHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DepositRateHelper2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mRate;
    string mTenor;
    ObjectHandler::property_t mFixingDays;
    string mCalendar;
    string mConvention;
    bool mEndOfMonth;
    string mDayCounter;

    string mReturnValue;

    string mError;

    DepositRateHelper2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Rate
      ,string Tenor
      ,ObjectHandler::property_t FixingDays
      ,string Calendar
      ,string Convention
      ,bool EndOfMonth
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRate(Rate)
      ,mTenor(Tenor)
      ,mFixingDays(FixingDays)
      ,mCalendar(Calendar)
      ,mConvention(Convention)
      ,mEndOfMonth(EndOfMonth)
      ,mDayCounter(DayCounter)
      {

      };

    //~DepositRateHelper2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapRateHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mRate;
    string mSwapIndex;
    ObjectHandler::property_t mSpread;
    string mForwardStart;
    ObjectHandler::property_t mDiscountingCurve;
    string mPillarDate;
    ObjectHandler::property_t mCustomPillarDate;

    string mReturnValue;

    string mError;

    SwapRateHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Rate
      ,string SwapIndex
      ,ObjectHandler::property_t Spread
      ,string ForwardStart
      ,ObjectHandler::property_t DiscountingCurve
      ,string PillarDate
      ,ObjectHandler::property_t CustomPillarDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRate(Rate)
      ,mSwapIndex(SwapIndex)
      ,mSpread(Spread)
      ,mForwardStart(ForwardStart)
      ,mDiscountingCurve(DiscountingCurve)
      ,mPillarDate(PillarDate)
      ,mCustomPillarDate(CustomPillarDate)
      {

      };

    //~SwapRateHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapRateHelper2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mRate;
    ObjectHandler::property_t mSettlDays;
    string mTenor;
    string mCalendar;
    string mFixedLegFrequency;
    string mFixedLegConvention;
    string mFixedLegDayCounter;
    string mIborIndex;
    ObjectHandler::property_t mSpread;
    string mForwardStart;
    ObjectHandler::property_t mDiscountingCurve;
    string mPillarDate;
    ObjectHandler::property_t mCustomPillarDate;

    string mReturnValue;

    string mError;

    SwapRateHelper2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Rate
      ,ObjectHandler::property_t SettlDays
      ,string Tenor
      ,string Calendar
      ,string FixedLegFrequency
      ,string FixedLegConvention
      ,string FixedLegDayCounter
      ,string IborIndex
      ,ObjectHandler::property_t Spread
      ,string ForwardStart
      ,ObjectHandler::property_t DiscountingCurve
      ,string PillarDate
      ,ObjectHandler::property_t CustomPillarDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRate(Rate)
      ,mSettlDays(SettlDays)
      ,mTenor(Tenor)
      ,mCalendar(Calendar)
      ,mFixedLegFrequency(FixedLegFrequency)
      ,mFixedLegConvention(FixedLegConvention)
      ,mFixedLegDayCounter(FixedLegDayCounter)
      ,mIborIndex(IborIndex)
      ,mSpread(Spread)
      ,mForwardStart(ForwardStart)
      ,mDiscountingCurve(DiscountingCurve)
      ,mPillarDate(PillarDate)
      ,mCustomPillarDate(CustomPillarDate)
      {

      };

    //~SwapRateHelper2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OISRateHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSettlDays;
    string mTenor;
    ObjectHandler::property_t mFixedRate;
    string mONIndex;
    ObjectHandler::property_t mDiscountingCurve;

    string mReturnValue;

    string mError;

    OISRateHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SettlDays
      ,string Tenor
      ,ObjectHandler::property_t FixedRate
      ,string ONIndex
      ,ObjectHandler::property_t DiscountingCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlDays(SettlDays)
      ,mTenor(Tenor)
      ,mFixedRate(FixedRate)
      ,mONIndex(ONIndex)
      ,mDiscountingCurve(DiscountingCurve)
      {

      };

    //~OISRateHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DatedOISRateHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mEndDate;
    ObjectHandler::property_t mFixedRate;
    string mONIndex;
    ObjectHandler::property_t mDiscountingCurve;

    string mReturnValue;

    string mError;

    DatedOISRateHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t EndDate
      ,ObjectHandler::property_t FixedRate
      ,string ONIndex
      ,ObjectHandler::property_t DiscountingCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mFixedRate(FixedRate)
      ,mONIndex(ONIndex)
      ,mDiscountingCurve(DiscountingCurve)
      {

      };

    //~DatedOISRateHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FraRateHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mRate;
    string mPeriodToStart;
    string mIborIndex;
    string mPillarDate;
    ObjectHandler::property_t mCustomPillarDate;

    string mReturnValue;

    string mError;

    FraRateHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Rate
      ,string PeriodToStart
      ,string IborIndex
      ,string PillarDate
      ,ObjectHandler::property_t CustomPillarDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRate(Rate)
      ,mPeriodToStart(PeriodToStart)
      ,mIborIndex(IborIndex)
      ,mPillarDate(PillarDate)
      ,mCustomPillarDate(CustomPillarDate)
      {

      };

    //~FraRateHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FraRateHelper2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mRate;
    string mPeriodToStart;
    ObjectHandler::property_t mLengthInMonths;
    ObjectHandler::property_t mFixingDays;
    string mCalendar;
    string mConvention;
    bool mEndOfMonth;
    string mDayCounter;
    string mPillarDate;
    ObjectHandler::property_t mCustomPillarDate;

    string mReturnValue;

    string mError;

    FraRateHelper2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Rate
      ,string PeriodToStart
      ,ObjectHandler::property_t LengthInMonths
      ,ObjectHandler::property_t FixingDays
      ,string Calendar
      ,string Convention
      ,bool EndOfMonth
      ,string DayCounter
      ,string PillarDate
      ,ObjectHandler::property_t CustomPillarDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRate(Rate)
      ,mPeriodToStart(PeriodToStart)
      ,mLengthInMonths(LengthInMonths)
      ,mFixingDays(FixingDays)
      ,mCalendar(Calendar)
      ,mConvention(Convention)
      ,mEndOfMonth(EndOfMonth)
      ,mDayCounter(DayCounter)
      ,mPillarDate(PillarDate)
      ,mCustomPillarDate(CustomPillarDate)
      {

      };

    //~FraRateHelper2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mPrice;
    string mBond;
    bool mUseCleanPrice;

    string mReturnValue;

    string mError;

    BondHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Price
      ,string Bond
      ,bool UseCleanPrice
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPrice(Price)
      ,mBond(Bond)
      ,mUseCleanPrice(UseCleanPrice)
      {

      };

    //~BondHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FixedRateBondHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mPrice;
    long mSettlementDays;
    double mFaceAmount;
    string mScheduleID;
    std::vector<double> mCoupons;
    string mDayCounter;
    string mPaymentBDC;
    double mRedemption;
    ObjectHandler::property_t mIssueDate;
    string mPaymentCalendar;
    string mExCouponPeriod;
    string mExCouponCalendar;
    string mExCouponBDC;
    bool mExCouponEndOfMonth;
    bool mUseCleanPrice;

    string mReturnValue;

    string mError;

    FixedRateBondHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Price
      ,long SettlementDays
      ,double FaceAmount
      ,string ScheduleID
      ,std::vector<double> Coupons
      ,string DayCounter
      ,string PaymentBDC
      ,double Redemption
      ,ObjectHandler::property_t IssueDate
      ,string PaymentCalendar
      ,string ExCouponPeriod
      ,string ExCouponCalendar
      ,string ExCouponBDC
      ,bool ExCouponEndOfMonth
      ,bool UseCleanPrice
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPrice(Price)
      ,mSettlementDays(SettlementDays)
      ,mFaceAmount(FaceAmount)
      ,mScheduleID(ScheduleID)
      ,mCoupons(Coupons)
      ,mDayCounter(DayCounter)
      ,mPaymentBDC(PaymentBDC)
      ,mRedemption(Redemption)
      ,mIssueDate(IssueDate)
      ,mPaymentCalendar(PaymentCalendar)
      ,mExCouponPeriod(ExCouponPeriod)
      ,mExCouponCalendar(ExCouponCalendar)
      ,mExCouponBDC(ExCouponBDC)
      ,mExCouponEndOfMonth(ExCouponEndOfMonth)
      ,mUseCleanPrice(UseCleanPrice)
      {

      };

    //~FixedRateBondHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesRateHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mPrice;
    string mFuturesType;
    ObjectHandler::property_t mFuturesDate;
    string mIborIndex;
    ObjectHandler::property_t mConvexityAdjQuote;

    string mReturnValue;

    string mError;

    FuturesRateHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Price
      ,string FuturesType
      ,ObjectHandler::property_t FuturesDate
      ,string IborIndex
      ,ObjectHandler::property_t ConvexityAdjQuote
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPrice(Price)
      ,mFuturesType(FuturesType)
      ,mFuturesDate(FuturesDate)
      ,mIborIndex(IborIndex)
      ,mConvexityAdjQuote(ConvexityAdjQuote)
      {

      };

    //~FuturesRateHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesRateHelper2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mPrice;
    string mFuturesType;
    ObjectHandler::property_t mFuturesDate;
    long mLengthInMonths;
    string mCalendar;
    string mConvention;
    bool mEndOfMonth;
    string mDayCounter;
    ObjectHandler::property_t mConvexityAdjQuote;

    string mReturnValue;

    string mError;

    FuturesRateHelper2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Price
      ,string FuturesType
      ,ObjectHandler::property_t FuturesDate
      ,long LengthInMonths
      ,string Calendar
      ,string Convention
      ,bool EndOfMonth
      ,string DayCounter
      ,ObjectHandler::property_t ConvexityAdjQuote
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPrice(Price)
      ,mFuturesType(FuturesType)
      ,mFuturesDate(FuturesDate)
      ,mLengthInMonths(LengthInMonths)
      ,mCalendar(Calendar)
      ,mConvention(Convention)
      ,mEndOfMonth(EndOfMonth)
      ,mDayCounter(DayCounter)
      ,mConvexityAdjQuote(ConvexityAdjQuote)
      {

      };

    //~FuturesRateHelper2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesRateHelper3Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mPrice;
    string mFuturesType;
    ObjectHandler::property_t mFuturesDate;
    ObjectHandler::property_t mEndDate;
    string mDayCounter;
    ObjectHandler::property_t mConvexityAdjQuote;

    string mReturnValue;

    string mError;

    FuturesRateHelper3Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Price
      ,string FuturesType
      ,ObjectHandler::property_t FuturesDate
      ,ObjectHandler::property_t EndDate
      ,string DayCounter
      ,ObjectHandler::property_t ConvexityAdjQuote
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPrice(Price)
      ,mFuturesType(FuturesType)
      ,mFuturesDate(FuturesDate)
      ,mEndDate(EndDate)
      ,mDayCounter(DayCounter)
      ,mConvexityAdjQuote(ConvexityAdjQuote)
      {

      };

    //~FuturesRateHelper3Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FxSwapRateHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mFwdPoint;
    ObjectHandler::property_t mSpotFx;
    string mTenor;
    ObjectHandler::property_t mFixingDays;
    string mCalendar;
    string mConvention;
    bool mEndOfMonth;
    bool mIsFxBaseCurrencyCollateralCurrency;
    ObjectHandler::property_t mCollateralCurve;

    string mReturnValue;

    string mError;

    FxSwapRateHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t FwdPoint
      ,ObjectHandler::property_t SpotFx
      ,string Tenor
      ,ObjectHandler::property_t FixingDays
      ,string Calendar
      ,string Convention
      ,bool EndOfMonth
      ,bool IsFxBaseCurrencyCollateralCurrency
      ,ObjectHandler::property_t CollateralCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFwdPoint(FwdPoint)
      ,mSpotFx(SpotFx)
      ,mTenor(Tenor)
      ,mFixingDays(FixingDays)
      ,mCalendar(Calendar)
      ,mConvention(Convention)
      ,mEndOfMonth(EndOfMonth)
      ,mIsFxBaseCurrencyCollateralCurrency(IsFxBaseCurrencyCollateralCurrency)
      ,mCollateralCurve(CollateralCurve)
      {

      };

    //~FxSwapRateHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperEarliestDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    RateHelperEarliestDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RateHelperEarliestDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperLatestRelevantDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    RateHelperLatestRelevantDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RateHelperLatestRelevantDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperPillarDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    RateHelperPillarDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RateHelperPillarDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperMaturityDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    RateHelperMaturityDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RateHelperMaturityDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperQuoteNameWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    RateHelperQuoteNameWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RateHelperQuoteNameWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperQuoteValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RateHelperQuoteValueWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RateHelperQuoteValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperQuoteIsValidWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RateHelperQuoteIsValidWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RateHelperQuoteIsValidWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperImpliedQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RateHelperImpliedQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RateHelperImpliedQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperQuoteErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RateHelperQuoteErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RateHelperQuoteErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapRateHelperSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SwapRateHelperSpreadWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwapRateHelperSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapRateHelperForwardStartWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SwapRateHelperForwardStartWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwapRateHelperForwardStartWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesRateHelperConvexityAdjustmentWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    FuturesRateHelperConvexityAdjustmentWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FuturesRateHelperConvexityAdjustmentWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FxSwapRateHelperSpotValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    FxSwapRateHelperSpotValueWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FxSwapRateHelperSpotValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FxSwapRateHelperTenorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    FxSwapRateHelperTenorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FxSwapRateHelperTenorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FxSwapRateHelperFixingDaysWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    FxSwapRateHelperFixingDaysWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FxSwapRateHelperFixingDaysWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FxSwapRateHelperCalendarWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    FxSwapRateHelperCalendarWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FxSwapRateHelperCalendarWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FxSwapRateHelperBDCWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    FxSwapRateHelperBDCWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FxSwapRateHelperBDCWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FxSwapRateHelperEOMWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    FxSwapRateHelperEOMWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FxSwapRateHelperEOMWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FxSwapRateHelperIsBaseCurrencyCollateralCurrencyWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    FxSwapRateHelperIsBaseCurrencyCollateralCurrencyWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FxSwapRateHelperIsBaseCurrencyCollateralCurrencyWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperSelectionWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mRateHelpers;
    std::vector<ObjectHandler::property_t> mPriority;
    ObjectHandler::property_t mNImmFutures;
    ObjectHandler::property_t mNSerialFutures;
    ObjectHandler::property_t mFutureRollDays;
    string mDepoInclusion;
    std::vector<ObjectHandler::property_t> mMinDistance;

    std::vector<string> mReturnValue;

    string mError;

    RateHelperSelectionWorker(
      Nan::Callback *callback
      ,std::vector<string> RateHelpers
      ,std::vector<ObjectHandler::property_t> Priority
      ,ObjectHandler::property_t NImmFutures
      ,ObjectHandler::property_t NSerialFutures
      ,ObjectHandler::property_t FutureRollDays
      ,string DepoInclusion
      ,std::vector<ObjectHandler::property_t> MinDistance
    ):
      Nan::AsyncWorker(callback)
      ,mRateHelpers(RateHelpers)
      ,mPriority(Priority)
      ,mNImmFutures(NImmFutures)
      ,mNSerialFutures(NSerialFutures)
      ,mFutureRollDays(FutureRollDays)
      ,mDepoInclusion(DepoInclusion)
      ,mMinDistance(MinDistance)
      {

      };

    //~RateHelperSelectionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RateHelperRateWorker : public Nan::AsyncWorker {
  public:
    string mRateHelper;

    double mReturnValue;

    string mError;

    RateHelperRateWorker(
      Nan::Callback *callback
      ,string RateHelper
    ):
      Nan::AsyncWorker(callback)
      ,mRateHelper(RateHelper)
      {

      };

    //~RateHelperRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
