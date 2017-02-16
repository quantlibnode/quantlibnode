/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef leg_h
#define leg_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class LegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mAmounts;
    std::vector<ObjectHandler::property_t> mDates;
    bool mToBeSorted;

    string mReturnValue;

    string mError;

    LegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> Amounts
      ,std::vector<ObjectHandler::property_t> Dates
      ,bool ToBeSorted
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAmounts(Amounts)
      ,mDates(Dates)
      ,mToBeSorted(ToBeSorted)
      {

      };

    //~LegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegFromCapFloorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCapFloor;

    string mReturnValue;

    string mError;

    LegFromCapFloorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CapFloor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCapFloor(CapFloor)
      {

      };

    //~LegFromCapFloorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegFromSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSwap;
    long mLegNumber;

    string mReturnValue;

    string mError;

    LegFromSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Swap
      ,long LegNumber
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwap(Swap)
      ,mLegNumber(LegNumber)
      {

      };

    //~LegFromSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MultiPhaseLegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mLegIDs;
    bool mToBeSorted;

    string mReturnValue;

    string mError;

    MultiPhaseLegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> LegIDs
      ,bool ToBeSorted
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLegIDs(LegIDs)
      ,mToBeSorted(ToBeSorted)
      {

      };

    //~MultiPhaseLegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mRate;
    string mDayCounter;
    string mCompounding;
    string mFrequency;

    string mReturnValue;

    string mError;

    InterestRateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Rate
      ,string DayCounter
      ,string Compounding
      ,string Frequency
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRate(Rate)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      {

      };

    //~InterestRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegFlowAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    LegFlowAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAfterDate(AfterDate)
      {

      };

    //~LegFlowAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegSetCouponPricersWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mFloatingRateCouponPricer;

    string mError;

    LegSetCouponPricersWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> FloatingRateCouponPricer
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFloatingRateCouponPricer(FloatingRateCouponPricer)
      {

      };

    //~LegSetCouponPricersWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    InterestRateRateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterestRateRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateDayCounterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    InterestRateDayCounterWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterestRateDayCounterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateCompoundingWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    InterestRateCompoundingWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterestRateCompoundingWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateFrequencyWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    InterestRateFrequencyWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterestRateFrequencyWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateDiscountFactorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mEndDate;
    ObjectHandler::property_t mRefPeriodStart;
    ObjectHandler::property_t mRefPeriodEnd;

    double mReturnValue;

    string mError;

    InterestRateDiscountFactorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t EndDate
      ,ObjectHandler::property_t RefPeriodStart
      ,ObjectHandler::property_t RefPeriodEnd
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mRefPeriodStart(RefPeriodStart)
      ,mRefPeriodEnd(RefPeriodEnd)
      {

      };

    //~InterestRateDiscountFactorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateCompoundFactorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mEndDate;
    ObjectHandler::property_t mRefPeriodStart;
    ObjectHandler::property_t mRefPeriodEnd;

    double mReturnValue;

    string mError;

    InterestRateCompoundFactorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t EndDate
      ,ObjectHandler::property_t RefPeriodStart
      ,ObjectHandler::property_t RefPeriodEnd
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mRefPeriodStart(RefPeriodStart)
      ,mRefPeriodEnd(RefPeriodEnd)
      {

      };

    //~InterestRateCompoundFactorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateEquivalentRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mEndDate;
    ObjectHandler::property_t mRefPeriodStart;
    ObjectHandler::property_t mRefPeriodEnd;

    double mReturnValue;

    string mError;

    InterestRateEquivalentRateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t EndDate
      ,ObjectHandler::property_t RefPeriodStart
      ,ObjectHandler::property_t RefPeriodEnd
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mRefPeriodStart(RefPeriodStart)
      ,mRefPeriodEnd(RefPeriodEnd)
      {

      };

    //~InterestRateEquivalentRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegStartDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;

    long mReturnValue;

    string mError;

    LegStartDateWorker(
      Nan::Callback *callback
      ,string ObjectId
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      {

      };

    //~LegStartDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegMaturityDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;

    long mReturnValue;

    string mError;

    LegMaturityDateWorker(
      Nan::Callback *callback
      ,string ObjectId
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      {

      };

    //~LegMaturityDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegIsExpiredWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    bool mReturnValue;

    string mError;

    LegIsExpiredWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegIsExpiredWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegPreviousCashFlowDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    LegPreviousCashFlowDateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegPreviousCashFlowDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegNextCashFlowDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    LegNextCashFlowDateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegNextCashFlowDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegPreviousCashFlowAmountWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    LegPreviousCashFlowAmountWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegPreviousCashFlowAmountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegNextCashFlowAmountWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    LegNextCashFlowAmountWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegNextCashFlowAmountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegPreviousCouponRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    LegPreviousCouponRateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegPreviousCouponRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegNextCouponRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    LegNextCouponRateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegNextCouponRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegNominalWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    LegNominalWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegNominalWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegAccrualStartDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    LegAccrualStartDateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegAccrualStartDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegAccrualEndDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    LegAccrualEndDateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegAccrualEndDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegReferencePeriodStartWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    LegReferencePeriodStartWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegReferencePeriodStartWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegReferencePeriodEndWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    LegReferencePeriodEndWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegReferencePeriodEndWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegAccrualPeriodWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    LegAccrualPeriodWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegAccrualPeriodWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegAccrualDaysWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    LegAccrualDaysWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegAccrualDaysWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegAccruedPeriodWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    LegAccruedPeriodWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegAccruedPeriodWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegAccruedDaysWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    long mReturnValue;

    string mError;

    LegAccruedDaysWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegAccruedDaysWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegAccruedAmountWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;

    double mReturnValue;

    string mError;

    LegAccruedAmountWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      {

      };

    //~LegAccruedAmountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegNPVWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    string mDiscountCurve;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    double mReturnValue;

    string mError;

    LegNPVWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,string DiscountCurve
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mDiscountCurve(DiscountCurve)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~LegNPVWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegBPSWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    string mDiscountCurve;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    double mReturnValue;

    string mError;

    LegBPSWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,string DiscountCurve
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mDiscountCurve(DiscountCurve)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~LegBPSWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegAtmRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    string mDiscountCurve;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;
    double mNPV;

    double mReturnValue;

    string mError;

    LegAtmRateWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,string DiscountCurve
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
      ,double NPV
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mDiscountCurve(DiscountCurve)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      ,mNPV(NPV)
      {

      };

    //~LegAtmRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegNPVFromYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    double mReturnValue;

    string mError;

    LegNPVFromYieldWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~LegNPVFromYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegBPSFromYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    double mReturnValue;

    string mError;

    LegBPSFromYieldWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~LegBPSFromYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mNPV;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;
    double mAccuracy;
    long mMaxIterations;
    double mGuess;

    double mReturnValue;

    string mError;

    LegYieldWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double NPV
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
      ,double Accuracy
      ,long MaxIterations
      ,double Guess
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mNPV(NPV)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      ,mAccuracy(Accuracy)
      ,mMaxIterations(MaxIterations)
      ,mGuess(Guess)
      {

      };

    //~LegYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegDurationWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    string mDurationType;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    double mReturnValue;

    string mError;

    LegDurationWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,string DurationType
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mDurationType(DurationType)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~LegDurationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegConvexityWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    double mReturnValue;

    string mError;

    LegConvexityWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~LegConvexityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegBasisPointValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    double mReturnValue;

    string mError;

    LegBasisPointValueWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~LegBasisPointValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegYieldValueBasisPointWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mYield;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    double mReturnValue;

    string mError;

    LegYieldValueBasisPointWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double Yield
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mYield(Yield)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~LegYieldValueBasisPointWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegNPVFromZSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    string mDiscountCurve;
    double mZSpread;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;

    double mReturnValue;

    string mError;

    LegNPVFromZSpreadWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,string DiscountCurve
      ,double ZSpread
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mDiscountCurve(DiscountCurve)
      ,mZSpread(ZSpread)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      {

      };

    //~LegNPVFromZSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LegZSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectId;
    double mNPV;
    string mDiscountCurve;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    bool mIncludeSettlDate;
    ObjectHandler::property_t mSettlementDate;
    ObjectHandler::property_t mNpvDate;
    double mAccuracy;
    long mMaxIterations;
    double mGuess;

    double mReturnValue;

    string mError;

    LegZSpreadWorker(
      Nan::Callback *callback
      ,string ObjectId
      ,double NPV
      ,string DiscountCurve
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,bool IncludeSettlDate
      ,ObjectHandler::property_t SettlementDate
      ,ObjectHandler::property_t NpvDate
      ,double Accuracy
      ,long MaxIterations
      ,double Guess
    ):
      Nan::AsyncWorker(callback)
      ,mObjectId(ObjectId)
      ,mNPV(NPV)
      ,mDiscountCurve(DiscountCurve)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mIncludeSettlDate(IncludeSettlDate)
      ,mSettlementDate(SettlementDate)
      ,mNpvDate(NpvDate)
      ,mAccuracy(Accuracy)
      ,mMaxIterations(MaxIterations)
      ,mGuess(Guess)
      {

      };

    //~LegZSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateImpliedRateWorker : public Nan::AsyncWorker {
  public:
    double mCompound;
    string mDayCounter;
    string mCompounding;
    string mFrequency;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mEndDate;
    ObjectHandler::property_t mRefPeriodStart;
    ObjectHandler::property_t mRefPeriodEnd;

    double mReturnValue;

    string mError;

    InterestRateImpliedRateWorker(
      Nan::Callback *callback
      ,double Compound
      ,string DayCounter
      ,string Compounding
      ,string Frequency
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t EndDate
      ,ObjectHandler::property_t RefPeriodStart
      ,ObjectHandler::property_t RefPeriodEnd
    ):
      Nan::AsyncWorker(callback)
      ,mCompound(Compound)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mRefPeriodStart(RefPeriodStart)
      ,mRefPeriodEnd(RefPeriodEnd)
      {

      };

    //~InterestRateImpliedRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
