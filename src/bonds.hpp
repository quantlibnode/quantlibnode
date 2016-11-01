// This is a generated file, modify: generate/templates/class_header.h

#ifndef bonds_h
#define bonds_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class FixedRateBondWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDescription;
    string mCurrency;
    long mSettlementDays;
    double mFaceAmount;
    string mScheduleID;
    std::vector<double> mCoupons;
    string mDayCounter;
    string mPaymentBDC;
    double mRedemption;
    ObjectHandler::property_t mIssueDate;
    string mPaymentCalendar;

    string mReturnValue;

    string mError;

    FixedRateBondWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Description
      ,string Currency
      ,long SettlementDays
      ,double FaceAmount
      ,string ScheduleID
      ,std::vector<double> Coupons
      ,string DayCounter
      ,string PaymentBDC
      ,double Redemption
      ,ObjectHandler::property_t IssueDate
      ,string PaymentCalendar
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDescription(Description)
      ,mCurrency(Currency)
      ,mSettlementDays(SettlementDays)
      ,mFaceAmount(FaceAmount)
      ,mScheduleID(ScheduleID)
      ,mCoupons(Coupons)
      ,mDayCounter(DayCounter)
      ,mPaymentBDC(PaymentBDC)
      ,mRedemption(Redemption)
      ,mIssueDate(IssueDate)
      ,mPaymentCalendar(PaymentCalendar)
      {

      };

    //~FixedRateBondWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FixedRateBond2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDescription;
    string mCurrency;
    long mSettlementDays;
    double mFaceAmount;
    string mScheduleID;
    std::vector<string> mCoupons;
    string mPaymentBDC;
    double mRedemption;
    ObjectHandler::property_t mIssueDate;
    string mPaymentCalendar;

    string mReturnValue;

    string mError;

    FixedRateBond2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Description
      ,string Currency
      ,long SettlementDays
      ,double FaceAmount
      ,string ScheduleID
      ,std::vector<string> Coupons
      ,string PaymentBDC
      ,double Redemption
      ,ObjectHandler::property_t IssueDate
      ,string PaymentCalendar
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDescription(Description)
      ,mCurrency(Currency)
      ,mSettlementDays(SettlementDays)
      ,mFaceAmount(FaceAmount)
      ,mScheduleID(ScheduleID)
      ,mCoupons(Coupons)
      ,mPaymentBDC(PaymentBDC)
      ,mRedemption(Redemption)
      ,mIssueDate(IssueDate)
      ,mPaymentCalendar(PaymentCalendar)
      {

      };

    //~FixedRateBond2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FloatingRateBondWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDescription;
    string mCurrency;
    long mSettlementDays;
    string mPaymentBDC;
    double mFaceAmount;
    string mScheduleID;
    ObjectHandler::property_t mFixingDays;
    bool mIsInArrears;
    string mDayCounter;
    std::vector<double> mFloors;
    std::vector<double> mGearings;
    string mIborIndex;
    std::vector<double> mSpreads;
    std::vector<double> mCaps;
    double mRedemption;
    ObjectHandler::property_t mIssueDate;

    string mReturnValue;

    string mError;

    FloatingRateBondWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Description
      ,string Currency
      ,long SettlementDays
      ,string PaymentBDC
      ,double FaceAmount
      ,string ScheduleID
      ,ObjectHandler::property_t FixingDays
      ,bool IsInArrears
      ,string DayCounter
      ,std::vector<double> Floors
      ,std::vector<double> Gearings
      ,string IborIndex
      ,std::vector<double> Spreads
      ,std::vector<double> Caps
      ,double Redemption
      ,ObjectHandler::property_t IssueDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDescription(Description)
      ,mCurrency(Currency)
      ,mSettlementDays(SettlementDays)
      ,mPaymentBDC(PaymentBDC)
      ,mFaceAmount(FaceAmount)
      ,mScheduleID(ScheduleID)
      ,mFixingDays(FixingDays)
      ,mIsInArrears(IsInArrears)
      ,mDayCounter(DayCounter)
      ,mFloors(Floors)
      ,mGearings(Gearings)
      ,mIborIndex(IborIndex)
      ,mSpreads(Spreads)
      ,mCaps(Caps)
      ,mRedemption(Redemption)
      ,mIssueDate(IssueDate)
      {

      };

    //~FloatingRateBondWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsRateBondWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDescription;
    string mCurrency;
    long mSettlementDays;
    string mPaymentBDC;
    double mFaceAmount;
    string mScheduleID;
    ObjectHandler::property_t mFixingDays;
    bool mIsInArrears;
    string mDayCounter;
    std::vector<double> mFloors;
    std::vector<double> mGearings;
    string mSwapIndex;
    std::vector<double> mSpreads;
    std::vector<double> mCaps;
    double mRedemption;
    ObjectHandler::property_t mIssueDate;

    string mReturnValue;

    string mError;

    CmsRateBondWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Description
      ,string Currency
      ,long SettlementDays
      ,string PaymentBDC
      ,double FaceAmount
      ,string ScheduleID
      ,ObjectHandler::property_t FixingDays
      ,bool IsInArrears
      ,string DayCounter
      ,std::vector<double> Floors
      ,std::vector<double> Gearings
      ,string SwapIndex
      ,std::vector<double> Spreads
      ,std::vector<double> Caps
      ,double Redemption
      ,ObjectHandler::property_t IssueDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDescription(Description)
      ,mCurrency(Currency)
      ,mSettlementDays(SettlementDays)
      ,mPaymentBDC(PaymentBDC)
      ,mFaceAmount(FaceAmount)
      ,mScheduleID(ScheduleID)
      ,mFixingDays(FixingDays)
      ,mIsInArrears(IsInArrears)
      ,mDayCounter(DayCounter)
      ,mFloors(Floors)
      ,mGearings(Gearings)
      ,mSwapIndex(SwapIndex)
      ,mSpreads(Spreads)
      ,mCaps(Caps)
      ,mRedemption(Redemption)
      ,mIssueDate(IssueDate)
      {

      };

    //~CmsRateBondWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ZeroCouponBondWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDescription;
    string mCurrency;
    long mSettlementDays;
    string mCalendar;
    double mFaceAmount;
    ObjectHandler::property_t mMaturity;
    string mPaymentBDC;
    double mRedemption;
    ObjectHandler::property_t mIssueDate;

    string mReturnValue;

    string mError;

    ZeroCouponBondWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Description
      ,string Currency
      ,long SettlementDays
      ,string Calendar
      ,double FaceAmount
      ,ObjectHandler::property_t Maturity
      ,string PaymentBDC
      ,double Redemption
      ,ObjectHandler::property_t IssueDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDescription(Description)
      ,mCurrency(Currency)
      ,mSettlementDays(SettlementDays)
      ,mCalendar(Calendar)
      ,mFaceAmount(FaceAmount)
      ,mMaturity(Maturity)
      ,mPaymentBDC(PaymentBDC)
      ,mRedemption(Redemption)
      ,mIssueDate(IssueDate)
      {

      };

    //~ZeroCouponBondWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDescription;
    string mCurrency;
    long mSettlementDays;
    string mCalendar;
    double mFaceAmount;
    ObjectHandler::property_t mMaturityDate;
    ObjectHandler::property_t mIssueDate;
    string mLegID;

    string mReturnValue;

    string mError;

    BondWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Description
      ,string Currency
      ,long SettlementDays
      ,string Calendar
      ,double FaceAmount
      ,ObjectHandler::property_t MaturityDate
      ,ObjectHandler::property_t IssueDate
      ,string LegID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDescription(Description)
      ,mCurrency(Currency)
      ,mSettlementDays(SettlementDays)
      ,mCalendar(Calendar)
      ,mFaceAmount(FaceAmount)
      ,mMaturityDate(MaturityDate)
      ,mIssueDate(IssueDate)
      ,mLegID(LegID)
      {

      };

    //~BondWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondSettlementDaysWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    BondSettlementDaysWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondSettlementDaysWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondCalendarWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    BondCalendarWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondCalendarWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondNotionalsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    BondNotionalsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondNotionalsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondNotionalWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondNotionalWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondNotionalWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondMaturityDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    BondMaturityDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondMaturityDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondIssueDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    BondIssueDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondIssueDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondIsTradableWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSettlementDate;

    bool mReturnValue;

    string mError;

    BondIsTradableWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondIsTradableWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondSettlementDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mEvaluationDate;

    long mReturnValue;

    string mError;

    BondSettlementDateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t EvaluationDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEvaluationDate(EvaluationDate)
      {

      };

    //~BondSettlementDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondCleanPriceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BondCleanPriceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondCleanPriceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondDescriptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    BondDescriptionWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondDescriptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondCurrencyWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    BondCurrencyWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondCurrencyWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondRedemptionAmountWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    BondRedemptionAmountWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondRedemptionAmountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondRedemptionDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    BondRedemptionDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BondRedemptionDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondFlowAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    BondFlowAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAfterDate(AfterDate)
      {

      };

    //~BondFlowAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondSetCouponPricerWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mFloatingRateCouponPricer;

    string mError;

    BondSetCouponPricerWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string FloatingRateCouponPricer
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFloatingRateCouponPricer(FloatingRateCouponPricer)
      {

      };

    //~BondSetCouponPricerWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondSetCouponPricersWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mFloatingRateCouponPricer;

    string mError;

    BondSetCouponPricersWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> FloatingRateCouponPricer
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFloatingRateCouponPricer(FloatingRateCouponPricer)
      {

      };

    //~BondSetCouponPricersWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondStartDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;

    long mReturnValue;

    string mError;

    BondStartDateWorker(
      Nan::Callback *callback
      ,string ObjectId
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      {

      };

    //~BondStartDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondPreviousCashFlowDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    BondPreviousCashFlowDateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondPreviousCashFlowDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondNextCashFlowDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    BondNextCashFlowDateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondNextCashFlowDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondPreviousCashFlowAmountWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondPreviousCashFlowAmountWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondPreviousCashFlowAmountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondNextCashFlowAmountWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondNextCashFlowAmountWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondNextCashFlowAmountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondPreviousCouponRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondPreviousCouponRateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondPreviousCouponRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondNextCouponRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondNextCouponRateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondNextCouponRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondAccrualStartDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    BondAccrualStartDateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondAccrualStartDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondAccrualEndDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    BondAccrualEndDateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondAccrualEndDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondReferencePeriodStartWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    BondReferencePeriodStartWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondReferencePeriodStartWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondReferencePeriodEndWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    BondReferencePeriodEndWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondReferencePeriodEndWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondAccrualPeriodWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondAccrualPeriodWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondAccrualPeriodWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondAccrualDaysWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    BondAccrualDaysWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondAccrualDaysWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondAccruedPeriodWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondAccruedPeriodWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondAccruedPeriodWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondAccruedDaysWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    BondAccruedDaysWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondAccruedDaysWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondAccruedAmountWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondAccruedAmountWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondAccruedAmountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondCleanPriceFromYieldTermStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    string mYieldCurve;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondCleanPriceFromYieldTermStructureWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,string YieldCurve
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYieldCurve(YieldCurve)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondCleanPriceFromYieldTermStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondBpsFromYieldTermStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    string mYieldCurve;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondBpsFromYieldTermStructureWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,string YieldCurve
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYieldCurve(YieldCurve)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondBpsFromYieldTermStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondAtmRateFromYieldTermStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    string mYieldCurve;
    ObjectHandler::property_t mSettlementDate;
    double mCleanPrice;

    double mReturnValue;

    string mError;

    BondAtmRateFromYieldTermStructureWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,string YieldCurve
      ,ObjectHandler::property_t SettlementDate
      ,double CleanPrice
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYieldCurve(YieldCurve)
      ,mSettlementDate(SettlementDate)
      ,mCleanPrice(CleanPrice)
      {

      };

    //~BondAtmRateFromYieldTermStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondCleanPriceFromYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondCleanPriceFromYieldWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondCleanPriceFromYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondDirtyPriceFromYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondDirtyPriceFromYieldWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondDirtyPriceFromYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondBpsFromYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondBpsFromYieldWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondBpsFromYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondYieldFromCleanPriceWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mCleanPrice;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    ObjectHandler::property_t mSettlementDate;
    double mAccuracy;
    long mMaxIterations;
    double mGuess;

    double mReturnValue;

    string mError;

    BondYieldFromCleanPriceWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double CleanPrice
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,ObjectHandler::property_t SettlementDate
      ,double Accuracy
      ,long MaxIterations
      ,double Guess
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mCleanPrice(CleanPrice)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mSettlementDate(SettlementDate)
      ,mAccuracy(Accuracy)
      ,mMaxIterations(MaxIterations)
      ,mGuess(Guess)
      {

      };

    //~BondYieldFromCleanPriceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondDurationFromYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    string mDurationType;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondDurationFromYieldWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,string DurationType
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mDurationType(DurationType)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondDurationFromYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondConvexityFromYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondConvexityFromYieldWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondConvexityFromYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondCleanPriceFromZSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    string mYieldCurve;
    double mZSpread;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    BondCleanPriceFromZSpreadWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,string YieldCurve
      ,double ZSpread
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYieldCurve(YieldCurve)
      ,mZSpread(ZSpread)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~BondCleanPriceFromZSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondZSpreadFromCleanPriceWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mCleanPrice;
    string mYieldCurve;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    ObjectHandler::property_t mSettlementDate;
    double mAccuracy;
    long mMaxIterations;
    double mGuess;

    double mReturnValue;

    string mError;

    BondZSpreadFromCleanPriceWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double CleanPrice
      ,string YieldCurve
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,ObjectHandler::property_t SettlementDate
      ,double Accuracy
      ,long MaxIterations
      ,double Guess
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mCleanPrice(CleanPrice)
      ,mYieldCurve(YieldCurve)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mSettlementDate(SettlementDate)
      ,mAccuracy(Accuracy)
      ,mMaxIterations(MaxIterations)
      ,mGuess(Guess)
      {

      };

    //~BondZSpreadFromCleanPriceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondAliveWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mBonds;
    ObjectHandler::property_t mRefDate;

    std::vector<string> mReturnValue;

    string mError;

    BondAliveWorker(
      Nan::Callback *callback
      ,std::vector<string> Bonds
      ,ObjectHandler::property_t RefDate
    ):
      Nan::AsyncWorker(callback)
      ,mBonds(Bonds)
      ,mRefDate(RefDate)
      {

      };

    //~BondAliveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondMaturityLookupWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mBonds;
    ObjectHandler::property_t mMaturity;

    string mReturnValue;

    string mError;

    BondMaturityLookupWorker(
      Nan::Callback *callback
      ,std::vector<string> Bonds
      ,ObjectHandler::property_t Maturity
    ):
      Nan::AsyncWorker(callback)
      ,mBonds(Bonds)
      ,mMaturity(Maturity)
      {

      };

    //~BondMaturityLookupWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BondMaturitySortWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mBonds;

    std::vector<string> mReturnValue;

    string mError;

    BondMaturitySortWorker(
      Nan::Callback *callback
      ,std::vector<string> Bonds
    ):
      Nan::AsyncWorker(callback)
      ,mBonds(Bonds)
      {

      };

    //~BondMaturitySortWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
