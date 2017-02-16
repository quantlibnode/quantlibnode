/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef index_h
#define index_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class IborIndexWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mFamilyName;
    string mTenor;
    ObjectHandler::property_t mFixingDays;
    string mCurrency;
    string mCalendar;
    string mBDayConvention;
    bool mEndOfMonth;
    string mDayCounter;
    ObjectHandler::property_t mFwdCurve;

    string mReturnValue;

    string mError;

    IborIndexWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string FamilyName
      ,string Tenor
      ,ObjectHandler::property_t FixingDays
      ,string Currency
      ,string Calendar
      ,string BDayConvention
      ,bool EndOfMonth
      ,string DayCounter
      ,ObjectHandler::property_t FwdCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFamilyName(FamilyName)
      ,mTenor(Tenor)
      ,mFixingDays(FixingDays)
      ,mCurrency(Currency)
      ,mCalendar(Calendar)
      ,mBDayConvention(BDayConvention)
      ,mEndOfMonth(EndOfMonth)
      ,mDayCounter(DayCounter)
      ,mFwdCurve(FwdCurve)
      {

      };

    //~IborIndexWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OvernightIndexWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mFamilyName;
    ObjectHandler::property_t mFixingDays;
    string mCurrency;
    string mCalendar;
    string mDayCounter;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    OvernightIndexWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string FamilyName
      ,ObjectHandler::property_t FixingDays
      ,string Currency
      ,string Calendar
      ,string DayCounter
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFamilyName(FamilyName)
      ,mFixingDays(FixingDays)
      ,mCurrency(Currency)
      ,mCalendar(Calendar)
      ,mDayCounter(DayCounter)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~OvernightIndexWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EuriborWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mTenor;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    EuriborWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Tenor
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTenor(Tenor)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~EuriborWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class Euribor365Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mTenor;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    Euribor365Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Tenor
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTenor(Tenor)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~Euribor365Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EoniaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    EoniaWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~EoniaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LiborWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurrency;
    string mTenor;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    LiborWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Currency
      ,string Tenor
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurrency(Currency)
      ,mTenor(Tenor)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~LiborWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SoniaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    SoniaWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~SoniaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapIndexWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mFamilyName;
    string mTenor;
    ObjectHandler::property_t mFixingDays;
    string mCurrency;
    string mCalendar;
    string mFixedLegTenor;
    string mFixedLegBDC;
    string mFixedLegDayCounter;
    string mIborIndex;
    ObjectHandler::property_t mDiscCurve;

    string mReturnValue;

    string mError;

    SwapIndexWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string FamilyName
      ,string Tenor
      ,ObjectHandler::property_t FixingDays
      ,string Currency
      ,string Calendar
      ,string FixedLegTenor
      ,string FixedLegBDC
      ,string FixedLegDayCounter
      ,string IborIndex
      ,ObjectHandler::property_t DiscCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFamilyName(FamilyName)
      ,mTenor(Tenor)
      ,mFixingDays(FixingDays)
      ,mCurrency(Currency)
      ,mCalendar(Calendar)
      ,mFixedLegTenor(FixedLegTenor)
      ,mFixedLegBDC(FixedLegBDC)
      ,mFixedLegDayCounter(FixedLegDayCounter)
      ,mIborIndex(IborIndex)
      ,mDiscCurve(DiscCurve)
      {

      };

    //~SwapIndexWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EuriborSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mFixingType;
    string mTenor;
    ObjectHandler::property_t mFwdCurve;
    ObjectHandler::property_t mDiscCurve;

    string mReturnValue;

    string mError;

    EuriborSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string FixingType
      ,string Tenor
      ,ObjectHandler::property_t FwdCurve
      ,ObjectHandler::property_t DiscCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFixingType(FixingType)
      ,mTenor(Tenor)
      ,mFwdCurve(FwdCurve)
      ,mDiscCurve(DiscCurve)
      {

      };

    //~EuriborSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LiborSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurrency;
    string mFixingType;
    string mTenor;
    ObjectHandler::property_t mFwdCurve;
    ObjectHandler::property_t mDiscCurve;

    string mReturnValue;

    string mError;

    LiborSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Currency
      ,string FixingType
      ,string Tenor
      ,ObjectHandler::property_t FwdCurve
      ,ObjectHandler::property_t DiscCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurrency(Currency)
      ,mFixingType(FixingType)
      ,mTenor(Tenor)
      ,mFwdCurve(FwdCurve)
      ,mDiscCurve(DiscCurve)
      {

      };

    //~LiborSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EuriborSwapIsdaFixAWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mTenor;
    ObjectHandler::property_t mFwdCurve;
    ObjectHandler::property_t mDiscCurve;

    string mReturnValue;

    string mError;

    EuriborSwapIsdaFixAWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Tenor
      ,ObjectHandler::property_t FwdCurve
      ,ObjectHandler::property_t DiscCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTenor(Tenor)
      ,mFwdCurve(FwdCurve)
      ,mDiscCurve(DiscCurve)
      {

      };

    //~EuriborSwapIsdaFixAWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BMAIndexWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    BMAIndexWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~BMAIndexWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ProxyIborWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mFamilyName;
    string mTenor;
    ObjectHandler::property_t mFixingDays;
    string mCurrency;
    string mCalendar;
    string mBDayConvention;
    bool mEndOfMonth;
    string mDayCounter;
    ObjectHandler::property_t mGearing;
    string mIborIndex;
    ObjectHandler::property_t mSpread;

    string mReturnValue;

    string mError;

    ProxyIborWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string FamilyName
      ,string Tenor
      ,ObjectHandler::property_t FixingDays
      ,string Currency
      ,string Calendar
      ,string BDayConvention
      ,bool EndOfMonth
      ,string DayCounter
      ,ObjectHandler::property_t Gearing
      ,string IborIndex
      ,ObjectHandler::property_t Spread
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFamilyName(FamilyName)
      ,mTenor(Tenor)
      ,mFixingDays(FixingDays)
      ,mCurrency(Currency)
      ,mCalendar(Calendar)
      ,mBDayConvention(BDayConvention)
      ,mEndOfMonth(EndOfMonth)
      ,mDayCounter(DayCounter)
      ,mGearing(Gearing)
      ,mIborIndex(IborIndex)
      ,mSpread(Spread)
      {

      };

    //~ProxyIborWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IndexNameWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    IndexNameWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~IndexNameWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IndexFixingCalendarWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    IndexFixingCalendarWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~IndexFixingCalendarWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IndexIsValidFixingDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mFixingDate;

    std::vector<bool> mReturnValue;

    string mError;

    IndexIsValidFixingDateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> FixingDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFixingDate(FixingDate)
      {

      };

    //~IndexIsValidFixingDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IndexFixingWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mFixingDate;
    bool mForecastToday;

    std::vector<double> mReturnValue;

    string mError;

    IndexFixingWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> FixingDate
      ,bool ForecastToday
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFixingDate(FixingDate)
      ,mForecastToday(ForecastToday)
      {

      };

    //~IndexFixingWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IndexAddFixingsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mFixingDates;
    std::vector<double> mFixingValues;
    bool mForceOverwrite;

    string mError;

    IndexAddFixingsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> FixingDates
      ,std::vector<double> FixingValues
      ,bool ForceOverwrite
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFixingDates(FixingDates)
      ,mFixingValues(FixingValues)
      ,mForceOverwrite(ForceOverwrite)
      {

      };

    //~IndexAddFixingsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IndexAddFixings2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mTimeSeriesID;
    bool mForceOverwrite;

    string mError;

    IndexAddFixings2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> TimeSeriesID
      ,bool ForceOverwrite
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTimeSeriesID(TimeSeriesID)
      ,mForceOverwrite(ForceOverwrite)
      {

      };

    //~IndexAddFixings2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IndexClearFixingsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mError;

    IndexClearFixingsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~IndexClearFixingsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateIndexFamilyNameWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    InterestRateIndexFamilyNameWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterestRateIndexFamilyNameWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateIndexTenorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    InterestRateIndexTenorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterestRateIndexTenorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateIndexFixingDaysWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    InterestRateIndexFixingDaysWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterestRateIndexFixingDaysWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateIndexCurrencyWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    InterestRateIndexCurrencyWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterestRateIndexCurrencyWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateIndexDayCounterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    InterestRateIndexDayCounterWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterestRateIndexDayCounterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateIndexValueDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mFixingDate;

    std::vector<long> mReturnValue;

    string mError;

    InterestRateIndexValueDateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> FixingDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mFixingDate(FixingDate)
      {

      };

    //~InterestRateIndexValueDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateIndexFixingDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mValueDate;

    std::vector<long> mReturnValue;

    string mError;

    InterestRateIndexFixingDateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> ValueDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mValueDate(ValueDate)
      {

      };

    //~InterestRateIndexFixingDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterestRateIndexMaturityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mValueDate;

    std::vector<long> mReturnValue;

    string mError;

    InterestRateIndexMaturityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> ValueDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mValueDate(ValueDate)
      {

      };

    //~InterestRateIndexMaturityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IborIndexBusinessDayConvWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    IborIndexBusinessDayConvWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~IborIndexBusinessDayConvWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IborIndexEndOfMonthWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    IborIndexEndOfMonthWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~IborIndexEndOfMonthWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapIndexFixedLegTenorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SwapIndexFixedLegTenorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwapIndexFixedLegTenorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapIndexFixedLegBDCWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SwapIndexFixedLegBDCWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwapIndexFixedLegBDCWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
