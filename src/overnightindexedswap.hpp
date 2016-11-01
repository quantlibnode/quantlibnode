// This is a generated file, modify: generate/templates/class_header.h

#ifndef overnightindexedswap_h
#define overnightindexedswap_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class OvernightIndexedSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPayerReceiver;
    std::vector<double> mNominal;
    string mSchedule;
    double mFixedRate;
    string mFixDayCounter;
    string mOvernightIndex;
    double mSpread;

    string mReturnValue;

    string mError;

    OvernightIndexedSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PayerReceiver
      ,std::vector<double> Nominal
      ,string Schedule
      ,double FixedRate
      ,string FixDayCounter
      ,string OvernightIndex
      ,double Spread
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayerReceiver(PayerReceiver)
      ,mNominal(Nominal)
      ,mSchedule(Schedule)
      ,mFixedRate(FixedRate)
      ,mFixDayCounter(FixDayCounter)
      ,mOvernightIndex(OvernightIndex)
      ,mSpread(Spread)
      {

      };

    //~OvernightIndexedSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MakeOISWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSettlDays;
    string mSwapTenor;
    string mOvernightIndex;
    double mFixedRate;
    string mForwardStart;
    string mFixDayCounter;
    double mSpread;

    string mReturnValue;

    string mError;

    MakeOISWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SettlDays
      ,string SwapTenor
      ,string OvernightIndex
      ,double FixedRate
      ,string ForwardStart
      ,string FixDayCounter
      ,double Spread
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlDays(SettlDays)
      ,mSwapTenor(SwapTenor)
      ,mOvernightIndex(OvernightIndex)
      ,mFixedRate(FixedRate)
      ,mForwardStart(ForwardStart)
      ,mFixDayCounter(FixDayCounter)
      ,mSpread(Spread)
      {

      };

    //~MakeOISWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MakeDatedOISWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mEndDate;
    string mOvernightIndex;
    double mFixedRate;
    string mFixDayCounter;
    double mSpread;

    string mReturnValue;

    string mError;

    MakeDatedOISWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t EndDate
      ,string OvernightIndex
      ,double FixedRate
      ,string FixDayCounter
      ,double Spread
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mOvernightIndex(OvernightIndex)
      ,mFixedRate(FixedRate)
      ,mFixDayCounter(FixDayCounter)
      ,mSpread(Spread)
      {

      };

    //~MakeDatedOISWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapFromOISRateHelperWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOISRateHelper;

    string mReturnValue;

    string mError;

    OvernightIndexedSwapFromOISRateHelperWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OISRateHelper
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOISRateHelper(OISRateHelper)
      {

      };

    //~OvernightIndexedSwapFromOISRateHelperWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapFixedLegBPSWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OvernightIndexedSwapFixedLegBPSWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapFixedLegBPSWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapFixedLegNPVWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OvernightIndexedSwapFixedLegNPVWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapFixedLegNPVWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapFairRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OvernightIndexedSwapFairRateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapFairRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapOvernightLegBPSWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OvernightIndexedSwapOvernightLegBPSWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapOvernightLegBPSWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapOvernightLegNPVWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OvernightIndexedSwapOvernightLegNPVWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapOvernightLegNPVWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapFairSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OvernightIndexedSwapFairSpreadWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapFairSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapTypeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    OvernightIndexedSwapTypeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapTypeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapNominalWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OvernightIndexedSwapNominalWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapNominalWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapFixedRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OvernightIndexedSwapFixedRateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapFixedRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapFixedDayCountWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    OvernightIndexedSwapFixedDayCountWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapFixedDayCountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OvernightIndexedSwapSpreadWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OvernightIndexedSwapSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapFixedLegAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    OvernightIndexedSwapFixedLegAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAfterDate(AfterDate)
      {

      };

    //~OvernightIndexedSwapFixedLegAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexedSwapOvernightLegAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    OvernightIndexedSwapOvernightLegAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAfterDate(AfterDate)
      {

      };

    //~OvernightIndexedSwapOvernightLegAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
