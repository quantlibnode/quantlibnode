/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef vanillaswap_h
#define vanillaswap_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class VanillaSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPayerReceiver;
    double mNominal;
    string mFixSchedule;
    double mFixedRate;
    string mFixDayCounter;
    string mFloatingLegSchedule;
    string mIborIndex;
    double mSpread;
    string mFloatingLegDayCounter;
    string mPaymentConvention;

    string mReturnValue;

    string mError;

    VanillaSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PayerReceiver
      ,double Nominal
      ,string FixSchedule
      ,double FixedRate
      ,string FixDayCounter
      ,string FloatingLegSchedule
      ,string IborIndex
      ,double Spread
      ,string FloatingLegDayCounter
      ,string PaymentConvention
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayerReceiver(PayerReceiver)
      ,mNominal(Nominal)
      ,mFixSchedule(FixSchedule)
      ,mFixedRate(FixedRate)
      ,mFixDayCounter(FixDayCounter)
      ,mFloatingLegSchedule(FloatingLegSchedule)
      ,mIborIndex(IborIndex)
      ,mSpread(Spread)
      ,mFloatingLegDayCounter(FloatingLegDayCounter)
      ,mPaymentConvention(PaymentConvention)
      {

      };

    //~VanillaSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MakeVanillaSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSettlDays;
    string mSwapTenor;
    string mIborIndex;
    double mFixedRate;
    string mForwardStart;
    string mFixDayCounter;
    double mSpread;
    string mPricingEngineID;

    string mReturnValue;

    string mError;

    MakeVanillaSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SettlDays
      ,string SwapTenor
      ,string IborIndex
      ,double FixedRate
      ,string ForwardStart
      ,string FixDayCounter
      ,double Spread
      ,string PricingEngineID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlDays(SettlDays)
      ,mSwapTenor(SwapTenor)
      ,mIborIndex(IborIndex)
      ,mFixedRate(FixedRate)
      ,mForwardStart(ForwardStart)
      ,mFixDayCounter(FixDayCounter)
      ,mSpread(Spread)
      ,mPricingEngineID(PricingEngineID)
      {

      };

    //~MakeVanillaSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MakeIMMSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSwapTenor;
    string mIborIndex;
    double mFixedRate;
    ObjectHandler::property_t mFirstImmDate;
    string mFixDayCounter;
    double mSpread;
    string mPricingEngineID;

    string mReturnValue;

    string mError;

    MakeIMMSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string SwapTenor
      ,string IborIndex
      ,double FixedRate
      ,ObjectHandler::property_t FirstImmDate
      ,string FixDayCounter
      ,double Spread
      ,string PricingEngineID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwapTenor(SwapTenor)
      ,mIborIndex(IborIndex)
      ,mFixedRate(FixedRate)
      ,mFirstImmDate(FirstImmDate)
      ,mFixDayCounter(FixDayCounter)
      ,mSpread(Spread)
      ,mPricingEngineID(PricingEngineID)
      {

      };

    //~MakeIMMSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFromSwapIndexWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSwapIndex;
    ObjectHandler::property_t mFixingDate;

    string mReturnValue;

    string mError;

    VanillaSwapFromSwapIndexWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string SwapIndex
      ,ObjectHandler::property_t FixingDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwapIndex(SwapIndex)
      ,mFixingDate(FixingDate)
      {

      };

    //~VanillaSwapFromSwapIndexWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFromSwapRateHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSwapRateHelper;

    string mReturnValue;

    string mError;

    VanillaSwapFromSwapRateHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string SwapRateHelper
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwapRateHelper(SwapRateHelper)
      {

      };

    //~VanillaSwapFromSwapRateHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFixedLegBPSWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VanillaSwapFixedLegBPSWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapFixedLegBPSWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFixedLegNPVWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VanillaSwapFixedLegNPVWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapFixedLegNPVWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFairRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VanillaSwapFairRateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapFairRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFloatingLegBPSWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VanillaSwapFloatingLegBPSWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapFloatingLegBPSWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFloatingLegNPVWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VanillaSwapFloatingLegNPVWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapFloatingLegNPVWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFairSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VanillaSwapFairSpreadWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapFairSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapTypeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    VanillaSwapTypeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapTypeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapNominalWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VanillaSwapNominalWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapNominalWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFixedRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VanillaSwapFixedRateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapFixedRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFixedDayCountWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    VanillaSwapFixedDayCountWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapFixedDayCountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VanillaSwapSpreadWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFloatingDayCountWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    VanillaSwapFloatingDayCountWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapFloatingDayCountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapPaymentConventionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    VanillaSwapPaymentConventionWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VanillaSwapPaymentConventionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFixedLegAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    VanillaSwapFixedLegAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAfterDate(AfterDate)
      {

      };

    //~VanillaSwapFixedLegAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VanillaSwapFloatingLegAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    VanillaSwapFloatingLegAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAfterDate(AfterDate)
      {

      };

    //~VanillaSwapFloatingLegAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
