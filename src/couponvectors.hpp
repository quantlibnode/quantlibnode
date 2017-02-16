/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef couponvectors_h
#define couponvectors_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class FixedRateLegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPaymentBDC;
    std::vector<double> mNominals;
    string mScheduleID;
    std::vector<double> mCoupons;
    string mDayCounter;

    string mReturnValue;

    string mError;

    FixedRateLegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PaymentBDC
      ,std::vector<double> Nominals
      ,string ScheduleID
      ,std::vector<double> Coupons
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPaymentBDC(PaymentBDC)
      ,mNominals(Nominals)
      ,mScheduleID(ScheduleID)
      ,mCoupons(Coupons)
      ,mDayCounter(DayCounter)
      {

      };

    //~FixedRateLegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FixedRateLeg2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPaymentBDC;
    std::vector<double> mNominals;
    string mScheduleID;
    std::vector<string> mCoupons;

    string mReturnValue;

    string mError;

    FixedRateLeg2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PaymentBDC
      ,std::vector<double> Nominals
      ,string ScheduleID
      ,std::vector<string> Coupons
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPaymentBDC(PaymentBDC)
      ,mNominals(Nominals)
      ,mScheduleID(ScheduleID)
      ,mCoupons(Coupons)
      {

      };

    //~FixedRateLeg2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IborLegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPaymentBDC;
    std::vector<double> mNominals;
    string mScheduleID;
    std::vector<ObjectHandler::property_t> mFixingDays;
    bool mIsInArrears;
    string mDayCounter;
    std::vector<double> mFloors;
    std::vector<double> mGearings;
    string mIborIndex;
    std::vector<double> mSpreads;
    std::vector<double> mCaps;

    string mReturnValue;

    string mError;

    IborLegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PaymentBDC
      ,std::vector<double> Nominals
      ,string ScheduleID
      ,std::vector<ObjectHandler::property_t> FixingDays
      ,bool IsInArrears
      ,string DayCounter
      ,std::vector<double> Floors
      ,std::vector<double> Gearings
      ,string IborIndex
      ,std::vector<double> Spreads
      ,std::vector<double> Caps
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPaymentBDC(PaymentBDC)
      ,mNominals(Nominals)
      ,mScheduleID(ScheduleID)
      ,mFixingDays(FixingDays)
      ,mIsInArrears(IsInArrears)
      ,mDayCounter(DayCounter)
      ,mFloors(Floors)
      ,mGearings(Gearings)
      ,mIborIndex(IborIndex)
      ,mSpreads(Spreads)
      ,mCaps(Caps)
      {

      };

    //~IborLegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DigitalIborLegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPaymentBDC;
    std::vector<double> mNominals;
    string mScheduleID;
    std::vector<ObjectHandler::property_t> mFixingDays;
    bool mIsInArrears;
    string mDayCounter;
    std::vector<double> mGearings;
    string mIborIndex;
    std::vector<double> mSpreads;
    std::vector<double> mCallStrikes;
    string mCallSpecs;
    std::vector<double> mCallPayoff;
    std::vector<double> mPutStrikes;
    string mPutSpecs;
    std::vector<double> mPutPayoff;
    string mReplication;

    string mReturnValue;

    string mError;

    DigitalIborLegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PaymentBDC
      ,std::vector<double> Nominals
      ,string ScheduleID
      ,std::vector<ObjectHandler::property_t> FixingDays
      ,bool IsInArrears
      ,string DayCounter
      ,std::vector<double> Gearings
      ,string IborIndex
      ,std::vector<double> Spreads
      ,std::vector<double> CallStrikes
      ,string CallSpecs
      ,std::vector<double> CallPayoff
      ,std::vector<double> PutStrikes
      ,string PutSpecs
      ,std::vector<double> PutPayoff
      ,string Replication
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPaymentBDC(PaymentBDC)
      ,mNominals(Nominals)
      ,mScheduleID(ScheduleID)
      ,mFixingDays(FixingDays)
      ,mIsInArrears(IsInArrears)
      ,mDayCounter(DayCounter)
      ,mGearings(Gearings)
      ,mIborIndex(IborIndex)
      ,mSpreads(Spreads)
      ,mCallStrikes(CallStrikes)
      ,mCallSpecs(CallSpecs)
      ,mCallPayoff(CallPayoff)
      ,mPutStrikes(PutStrikes)
      ,mPutSpecs(PutSpecs)
      ,mPutPayoff(PutPayoff)
      ,mReplication(Replication)
      {

      };

    //~DigitalIborLegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsLegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPaymentBDC;
    std::vector<double> mNominals;
    string mScheduleID;
    std::vector<ObjectHandler::property_t> mFixingDays;
    bool mIsInArrears;
    string mDayCounter;
    std::vector<double> mFloors;
    std::vector<double> mGearings;
    string mSwapIndex;
    std::vector<double> mSpreads;
    std::vector<double> mCaps;

    string mReturnValue;

    string mError;

    CmsLegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PaymentBDC
      ,std::vector<double> Nominals
      ,string ScheduleID
      ,std::vector<ObjectHandler::property_t> FixingDays
      ,bool IsInArrears
      ,string DayCounter
      ,std::vector<double> Floors
      ,std::vector<double> Gearings
      ,string SwapIndex
      ,std::vector<double> Spreads
      ,std::vector<double> Caps
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPaymentBDC(PaymentBDC)
      ,mNominals(Nominals)
      ,mScheduleID(ScheduleID)
      ,mFixingDays(FixingDays)
      ,mIsInArrears(IsInArrears)
      ,mDayCounter(DayCounter)
      ,mFloors(Floors)
      ,mGearings(Gearings)
      ,mSwapIndex(SwapIndex)
      ,mSpreads(Spreads)
      ,mCaps(Caps)
      {

      };

    //~CmsLegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DigitalCmsLegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPaymentBDC;
    std::vector<double> mNominals;
    string mScheduleID;
    std::vector<ObjectHandler::property_t> mFixingDays;
    bool mIsInArrears;
    string mDayCounter;
    std::vector<double> mGearings;
    string mSwapIndex;
    std::vector<double> mSpreads;
    std::vector<double> mCallStrikes;
    string mCallSpecs;
    std::vector<double> mCallPayoff;
    std::vector<double> mPutStrikes;
    string mPutSpecs;
    std::vector<double> mPutPayoff;
    string mReplication;

    string mReturnValue;

    string mError;

    DigitalCmsLegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PaymentBDC
      ,std::vector<double> Nominals
      ,string ScheduleID
      ,std::vector<ObjectHandler::property_t> FixingDays
      ,bool IsInArrears
      ,string DayCounter
      ,std::vector<double> Gearings
      ,string SwapIndex
      ,std::vector<double> Spreads
      ,std::vector<double> CallStrikes
      ,string CallSpecs
      ,std::vector<double> CallPayoff
      ,std::vector<double> PutStrikes
      ,string PutSpecs
      ,std::vector<double> PutPayoff
      ,string Replication
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPaymentBDC(PaymentBDC)
      ,mNominals(Nominals)
      ,mScheduleID(ScheduleID)
      ,mFixingDays(FixingDays)
      ,mIsInArrears(IsInArrears)
      ,mDayCounter(DayCounter)
      ,mGearings(Gearings)
      ,mSwapIndex(SwapIndex)
      ,mSpreads(Spreads)
      ,mCallStrikes(CallStrikes)
      ,mCallSpecs(CallSpecs)
      ,mCallPayoff(CallPayoff)
      ,mPutStrikes(PutStrikes)
      ,mPutSpecs(PutSpecs)
      ,mPutPayoff(PutPayoff)
      ,mReplication(Replication)
      {

      };

    //~DigitalCmsLegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RangeAccrualLegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPaymentBDC;
    std::vector<double> mNominals;
    string mScheduleID;
    std::vector<ObjectHandler::property_t> mFixingDays;
    string mDayCounter;
    std::vector<double> mLowerStrikes;
    std::vector<double> mGearings;
    string mIborIndex;
    std::vector<double> mSpreads;
    std::vector<double> mUpperStrikes;
    string mObservationsTenor;
    string mObservationsBDC;

    string mReturnValue;

    string mError;

    RangeAccrualLegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PaymentBDC
      ,std::vector<double> Nominals
      ,string ScheduleID
      ,std::vector<ObjectHandler::property_t> FixingDays
      ,string DayCounter
      ,std::vector<double> LowerStrikes
      ,std::vector<double> Gearings
      ,string IborIndex
      ,std::vector<double> Spreads
      ,std::vector<double> UpperStrikes
      ,string ObservationsTenor
      ,string ObservationsBDC
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPaymentBDC(PaymentBDC)
      ,mNominals(Nominals)
      ,mScheduleID(ScheduleID)
      ,mFixingDays(FixingDays)
      ,mDayCounter(DayCounter)
      ,mLowerStrikes(LowerStrikes)
      ,mGearings(Gearings)
      ,mIborIndex(IborIndex)
      ,mSpreads(Spreads)
      ,mUpperStrikes(UpperStrikes)
      ,mObservationsTenor(ObservationsTenor)
      ,mObservationsBDC(ObservationsBDC)
      {

      };

    //~RangeAccrualLegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsZeroLegWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPaymentBDC;
    std::vector<double> mNominals;
    string mScheduleID;
    std::vector<ObjectHandler::property_t> mFixingDays;
    bool mIsInArrears;
    string mDayCounter;
    std::vector<double> mFloors;
    std::vector<double> mGearings;
    string mSwapIndex;
    std::vector<double> mSpreads;
    std::vector<double> mCaps;

    string mReturnValue;

    string mError;

    CmsZeroLegWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PaymentBDC
      ,std::vector<double> Nominals
      ,string ScheduleID
      ,std::vector<ObjectHandler::property_t> FixingDays
      ,bool IsInArrears
      ,string DayCounter
      ,std::vector<double> Floors
      ,std::vector<double> Gearings
      ,string SwapIndex
      ,std::vector<double> Spreads
      ,std::vector<double> Caps
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPaymentBDC(PaymentBDC)
      ,mNominals(Nominals)
      ,mScheduleID(ScheduleID)
      ,mFixingDays(FixingDays)
      ,mIsInArrears(IsInArrears)
      ,mDayCounter(DayCounter)
      ,mFloors(Floors)
      ,mGearings(Gearings)
      ,mSwapIndex(SwapIndex)
      ,mSpreads(Spreads)
      ,mCaps(Caps)
      {

      };

    //~CmsZeroLegWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IborCouponPricerWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mVolatility;
    string mIborCouponPricerType;

    string mReturnValue;

    string mError;

    IborCouponPricerWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Volatility
      ,string IborCouponPricerType
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mVolatility(Volatility)
      ,mIborCouponPricerType(IborCouponPricerType)
      {

      };

    //~IborCouponPricerWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsCouponPricerWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mVolatility;
    string mCmsCouponPricerType;
    string mYieldCurveModel;
    ObjectHandler::property_t mMeanReversion;

    string mReturnValue;

    string mError;

    CmsCouponPricerWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Volatility
      ,string CmsCouponPricerType
      ,string YieldCurveModel
      ,ObjectHandler::property_t MeanReversion
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mVolatility(Volatility)
      ,mCmsCouponPricerType(CmsCouponPricerType)
      ,mYieldCurveModel(YieldCurveModel)
      ,mMeanReversion(MeanReversion)
      {

      };

    //~CmsCouponPricerWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ConundrumPricerByNumericalIntegrationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSwaptionVol;
    string mYieldCurveModel;
    ObjectHandler::property_t mMeanReversion;
    double mLowerLimit;
    double mUpperLimit;
    double mPrecision;

    string mReturnValue;

    string mError;

    ConundrumPricerByNumericalIntegrationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SwaptionVol
      ,string YieldCurveModel
      ,ObjectHandler::property_t MeanReversion
      ,double LowerLimit
      ,double UpperLimit
      ,double Precision
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwaptionVol(SwaptionVol)
      ,mYieldCurveModel(YieldCurveModel)
      ,mMeanReversion(MeanReversion)
      ,mLowerLimit(LowerLimit)
      ,mUpperLimit(UpperLimit)
      ,mPrecision(Precision)
      {

      };

    //~ConundrumPricerByNumericalIntegrationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DigitalReplicationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mReplication;
    double mGap;

    string mReturnValue;

    string mError;

    DigitalReplicationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Replication
      ,double Gap
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mReplication(Replication)
      ,mGap(Gap)
      {

      };

    //~DigitalReplicationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ConundrumPricerByNumericalIntegrationUpperLimitWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    ConundrumPricerByNumericalIntegrationUpperLimitWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ConundrumPricerByNumericalIntegrationUpperLimitWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
