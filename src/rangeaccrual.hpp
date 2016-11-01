// This is a generated file, modify: generate/templates/class_header.h

#ifndef rangeaccrual_h
#define rangeaccrual_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class RangeAccrualFloatersCouponWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mNominal;
    ObjectHandler::property_t mPaymentDate;
    string mIborIndex;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mEndDate;
    long mFixingDays;
    string mDayCountID;
    double mGearings;
    double mSpreads;
    ObjectHandler::property_t mRefPeriodStart;
    ObjectHandler::property_t mRefPeriodEnd;
    string mObserSchedID;
    double mLowerTrigger;
    double mUpperTrigger;

    string mReturnValue;

    string mError;

    RangeAccrualFloatersCouponWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Nominal
      ,ObjectHandler::property_t PaymentDate
      ,string IborIndex
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t EndDate
      ,long FixingDays
      ,string DayCountID
      ,double Gearings
      ,double Spreads
      ,ObjectHandler::property_t RefPeriodStart
      ,ObjectHandler::property_t RefPeriodEnd
      ,string ObserSchedID
      ,double LowerTrigger
      ,double UpperTrigger
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNominal(Nominal)
      ,mPaymentDate(PaymentDate)
      ,mIborIndex(IborIndex)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mFixingDays(FixingDays)
      ,mDayCountID(DayCountID)
      ,mGearings(Gearings)
      ,mSpreads(Spreads)
      ,mRefPeriodStart(RefPeriodStart)
      ,mRefPeriodEnd(RefPeriodEnd)
      ,mObserSchedID(ObserSchedID)
      ,mLowerTrigger(LowerTrigger)
      ,mUpperTrigger(UpperTrigger)
      {

      };

    //~RangeAccrualFloatersCouponWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RangeAccrualFloatersCouponFromLegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mRangeAccrualLeg;
    long mPosition;

    string mReturnValue;

    string mError;

    RangeAccrualFloatersCouponFromLegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string RangeAccrualLeg
      ,long Position
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRangeAccrualLeg(RangeAccrualLeg)
      ,mPosition(Position)
      {

      };

    //~RangeAccrualFloatersCouponFromLegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RangeAccrualPricerByBgmWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mCorrelation;
    string mSmileOnStartDateID;
    string mSmileOnEndDateID;
    bool mWithSmile;
    bool mByCallSpread;

    string mReturnValue;

    string mError;

    RangeAccrualPricerByBgmWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Correlation
      ,string SmileOnStartDateID
      ,string SmileOnEndDateID
      ,bool WithSmile
      ,bool ByCallSpread
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCorrelation(Correlation)
      ,mSmileOnStartDateID(SmileOnStartDateID)
      ,mSmileOnEndDateID(SmileOnEndDateID)
      ,mWithSmile(WithSmile)
      ,mByCallSpread(ByCallSpread)
      {

      };

    //~RangeAccrualPricerByBgmWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RangeAccrualFloatersCouponSetPricerWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mRangeAccrualPricer;

    string mError;

    RangeAccrualFloatersCouponSetPricerWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string RangeAccrualPricer
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRangeAccrualPricer(RangeAccrualPricer)
      {

      };

    //~RangeAccrualFloatersCouponSetPricerWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RangeAccrualFloatersCouponObservationDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    RangeAccrualFloatersCouponObservationDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RangeAccrualFloatersCouponObservationDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RangeAccrualFloatersCouponStarDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    RangeAccrualFloatersCouponStarDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RangeAccrualFloatersCouponStarDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RangeAccrualFloatersCouponEndDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    RangeAccrualFloatersCouponEndDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RangeAccrualFloatersCouponEndDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RangeAccrualFloatersCouponObservationsNoWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    RangeAccrualFloatersCouponObservationsNoWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RangeAccrualFloatersCouponObservationsNoWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RangeAccrualFloatersPriceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;

    double mReturnValue;

    string mError;

    RangeAccrualFloatersPriceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~RangeAccrualFloatersPriceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SimpleFloaterPriceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;

    double mReturnValue;

    string mError;

    SimpleFloaterPriceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~SimpleFloaterPriceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
