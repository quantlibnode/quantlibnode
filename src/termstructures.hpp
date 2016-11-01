// This is a generated file, modify: generate/templates/class_header.h

#ifndef termstructures_h
#define termstructures_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class RelinkableHandleYieldTermStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurrentLink;

    string mReturnValue;

    string mError;

    RelinkableHandleYieldTermStructureWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurrentLink
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurrentLink(CurrentLink)
      {

      };

    //~RelinkableHandleYieldTermStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DiscountCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mCurveDates;
    std::vector<double> mCurveDiscounts;
    string mDayCounter;

    string mReturnValue;

    string mError;

    DiscountCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> CurveDates
      ,std::vector<double> CurveDiscounts
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveDates(CurveDates)
      ,mCurveDiscounts(CurveDiscounts)
      ,mDayCounter(DayCounter)
      {

      };

    //~DiscountCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ZeroCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mCurveDates;
    std::vector<double> mCurveYields;
    string mDayCounter;

    string mReturnValue;

    string mError;

    ZeroCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> CurveDates
      ,std::vector<double> CurveYields
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveDates(CurveDates)
      ,mCurveYields(CurveYields)
      ,mDayCounter(DayCounter)
      {

      };

    //~ZeroCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ForwardCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mCurveDates;
    std::vector<double> mForwardYields;
    string mDayCounter;

    string mReturnValue;

    string mError;

    ForwardCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> CurveDates
      ,std::vector<double> ForwardYields
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurveDates(CurveDates)
      ,mForwardYields(ForwardYields)
      ,mDayCounter(DayCounter)
      {

      };

    //~ForwardCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FlatForwardWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mNDays;
    string mCalendar;
    ObjectHandler::property_t mRate;
    string mDayCounter;
    string mCompounding;
    string mFrequency;

    string mReturnValue;

    string mError;

    FlatForwardWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long NDays
      ,string Calendar
      ,ObjectHandler::property_t Rate
      ,string DayCounter
      ,string Compounding
      ,string Frequency
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNDays(NDays)
      ,mCalendar(Calendar)
      ,mRate(Rate)
      ,mDayCounter(DayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      {

      };

    //~FlatForwardWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ForwardSpreadedTermStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mBaseYieldCurve;
    ObjectHandler::property_t mSpread;

    string mReturnValue;

    string mError;

    ForwardSpreadedTermStructureWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t BaseYieldCurve
      ,ObjectHandler::property_t Spread
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBaseYieldCurve(BaseYieldCurve)
      ,mSpread(Spread)
      {

      };

    //~ForwardSpreadedTermStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ImpliedTermStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mBaseYieldCurve;
    ObjectHandler::property_t mReferenceDate;

    string mReturnValue;

    string mError;

    ImpliedTermStructureWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t BaseYieldCurve
      ,ObjectHandler::property_t ReferenceDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBaseYieldCurve(BaseYieldCurve)
      ,mReferenceDate(ReferenceDate)
      {

      };

    //~ImpliedTermStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolatedYieldCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mDates;
    std::vector<double> mData;
    string mCalendar;
    string mDayCounter;
    std::vector<ObjectHandler::property_t> mJumps;
    std::vector<ObjectHandler::property_t> mJumpDates;
    string mTraitsID;
    string mInterpolatorID;

    string mReturnValue;

    string mError;

    InterpolatedYieldCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> Dates
      ,std::vector<double> Data
      ,string Calendar
      ,string DayCounter
      ,std::vector<ObjectHandler::property_t> Jumps
      ,std::vector<ObjectHandler::property_t> JumpDates
      ,string TraitsID
      ,string InterpolatorID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDates(Dates)
      ,mData(Data)
      ,mCalendar(Calendar)
      ,mDayCounter(DayCounter)
      ,mJumps(Jumps)
      ,mJumpDates(JumpDates)
      ,mTraitsID(TraitsID)
      ,mInterpolatorID(InterpolatorID)
      {

      };

    //~InterpolatedYieldCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TermStructureDayCounterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    TermStructureDayCounterWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TermStructureDayCounterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TermStructureMaxDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    TermStructureMaxDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TermStructureMaxDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TermStructureReferenceDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    TermStructureReferenceDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TermStructureReferenceDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TermStructureTimeFromReferenceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mDate;

    std::vector<double> mReturnValue;

    string mError;

    TermStructureTimeFromReferenceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> Date
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDate(Date)
      {

      };

    //~TermStructureTimeFromReferenceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TermStructureCalendarWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    TermStructureCalendarWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TermStructureCalendarWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TermStructureSettlementDaysWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    TermStructureSettlementDaysWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TermStructureSettlementDaysWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class YieldTSDiscountWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mDfDates;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    YieldTSDiscountWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> DfDates
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDfDates(DfDates)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~YieldTSDiscountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class YieldTSForwardRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mD1;
    std::vector<ObjectHandler::property_t> mD2;
    string mResultDayCounter;
    string mCompounding;
    string mFrequency;
    bool mAllowExtrapolation;

    std::vector<string> mReturnValue;

    string mError;

    YieldTSForwardRateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t D1
      ,std::vector<ObjectHandler::property_t> D2
      ,string ResultDayCounter
      ,string Compounding
      ,string Frequency
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mD1(D1)
      ,mD2(D2)
      ,mResultDayCounter(ResultDayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~YieldTSForwardRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class YieldTSForwardRate2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mDate;
    string mPeriod;
    string mResultDayCounter;
    string mCompounding;
    string mFrequency;
    bool mAllowExtrapolation;

    std::vector<string> mReturnValue;

    string mError;

    YieldTSForwardRate2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> Date
      ,string Period
      ,string ResultDayCounter
      ,string Compounding
      ,string Frequency
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDate(Date)
      ,mPeriod(Period)
      ,mResultDayCounter(ResultDayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~YieldTSForwardRate2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class YieldTSZeroRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mDates;
    string mResultDayCounter;
    string mCompounding;
    string mFrequency;
    bool mAllowExtrapolation;

    std::vector<string> mReturnValue;

    string mError;

    YieldTSZeroRateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> Dates
      ,string ResultDayCounter
      ,string Compounding
      ,string Frequency
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDates(Dates)
      ,mResultDayCounter(ResultDayCounter)
      ,mCompounding(Compounding)
      ,mFrequency(Frequency)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~YieldTSZeroRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolatedYieldCurveTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    InterpolatedYieldCurveTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterpolatedYieldCurveTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolatedYieldCurveDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    InterpolatedYieldCurveDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterpolatedYieldCurveDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolatedYieldCurveDataWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    InterpolatedYieldCurveDataWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterpolatedYieldCurveDataWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolatedYieldCurveJumpTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    InterpolatedYieldCurveJumpTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterpolatedYieldCurveJumpTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolatedYieldCurveJumpDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    InterpolatedYieldCurveJumpDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~InterpolatedYieldCurveJumpDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
