/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef capletvolstructure_h
#define capletvolstructure_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class RelinkableHandleOptionletVolatilityStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurrentLink;

    string mReturnValue;

    string mError;

    RelinkableHandleOptionletVolatilityStructureWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurrentLink
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurrentLink(CurrentLink)
      {

      };

    //~RelinkableHandleOptionletVolatilityStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ConstantOptionletVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mNDays;
    string mCalendar;
    string mBusinessDayConvention;
    ObjectHandler::property_t mVolatility;
    string mDayCounter;

    string mReturnValue;

    string mError;

    ConstantOptionletVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long NDays
      ,string Calendar
      ,string BusinessDayConvention
      ,ObjectHandler::property_t Volatility
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNDays(NDays)
      ,mCalendar(Calendar)
      ,mBusinessDayConvention(BusinessDayConvention)
      ,mVolatility(Volatility)
      ,mDayCounter(DayCounter)
      {

      };

    //~ConstantOptionletVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SpreadedOptionletVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mBaseVolStructure;
    ObjectHandler::property_t mSpread;

    string mReturnValue;

    string mError;

    SpreadedOptionletVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t BaseVolStructure
      ,ObjectHandler::property_t Spread
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBaseVolStructure(BaseVolStructure)
      ,mSpread(Spread)
      {

      };

    //~SpreadedOptionletVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletAdapterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mStrippedOptionletBase;

    string mReturnValue;

    string mError;

    StrippedOptionletAdapterWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string StrippedOptionletBase
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mStrippedOptionletBase(StrippedOptionletBase)
      {

      };

    //~StrippedOptionletAdapterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mSettlementDays;
    string mCalendar;
    string mBusinessDayConvention;
    string mIborIndex;
    std::vector<ObjectHandler::property_t> mOptionletDates;
    std::vector<double> mStrikes;
    std::vector< std::vector<ObjectHandler::property_t> > mVolatilities;
    string mDayCounter;

    string mReturnValue;

    string mError;

    StrippedOptionletWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long SettlementDays
      ,string Calendar
      ,string BusinessDayConvention
      ,string IborIndex
      ,std::vector<ObjectHandler::property_t> OptionletDates
      ,std::vector<double> Strikes
      ,std::vector< std::vector<ObjectHandler::property_t> > Volatilities
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlementDays(SettlementDays)
      ,mCalendar(Calendar)
      ,mBusinessDayConvention(BusinessDayConvention)
      ,mIborIndex(IborIndex)
      ,mOptionletDates(OptionletDates)
      ,mStrikes(Strikes)
      ,mVolatilities(Volatilities)
      ,mDayCounter(DayCounter)
      {

      };

    //~StrippedOptionletWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripper1Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mTermVolSurface;
    string mIborIndex;
    double mSwitchStrike;
    double mAccuracy;
    ObjectHandler::property_t mMaxIter;

    string mReturnValue;

    string mError;

    OptionletStripper1Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string TermVolSurface
      ,string IborIndex
      ,double SwitchStrike
      ,double Accuracy
      ,ObjectHandler::property_t MaxIter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTermVolSurface(TermVolSurface)
      ,mIborIndex(IborIndex)
      ,mSwitchStrike(SwitchStrike)
      ,mAccuracy(Accuracy)
      ,mMaxIter(MaxIter)
      {

      };

    //~OptionletStripper1Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripper2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionletStripper1;
    ObjectHandler::property_t mTermVolCurve;

    string mReturnValue;

    string mError;

    OptionletStripper2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionletStripper1
      ,ObjectHandler::property_t TermVolCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionletStripper1(OptionletStripper1)
      ,mTermVolCurve(TermVolCurve)
      {

      };

    //~OptionletStripper2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTermVolCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mSettlementDays;
    string mCalendar;
    string mBusinessDayConvention;
    std::vector<ObjectHandler::property_t> mOptionTenors;
    std::vector<ObjectHandler::property_t> mVolatilities;
    string mDayCounter;

    string mReturnValue;

    string mError;

    CapFloorTermVolCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long SettlementDays
      ,string Calendar
      ,string BusinessDayConvention
      ,std::vector<ObjectHandler::property_t> OptionTenors
      ,std::vector<ObjectHandler::property_t> Volatilities
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlementDays(SettlementDays)
      ,mCalendar(Calendar)
      ,mBusinessDayConvention(BusinessDayConvention)
      ,mOptionTenors(OptionTenors)
      ,mVolatilities(Volatilities)
      ,mDayCounter(DayCounter)
      {

      };

    //~CapFloorTermVolCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTermVolSurfaceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mSettlementDays;
    string mCalendar;
    string mBusinessDayConvention;
    std::vector<ObjectHandler::property_t> mOptionTenors;
    std::vector<double> mStrikes;
    std::vector< std::vector<ObjectHandler::property_t> > mVolatilities;
    string mDayCounter;

    string mReturnValue;

    string mError;

    CapFloorTermVolSurfaceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long SettlementDays
      ,string Calendar
      ,string BusinessDayConvention
      ,std::vector<ObjectHandler::property_t> OptionTenors
      ,std::vector<double> Strikes
      ,std::vector< std::vector<ObjectHandler::property_t> > Volatilities
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlementDays(SettlementDays)
      ,mCalendar(Calendar)
      ,mBusinessDayConvention(BusinessDayConvention)
      ,mOptionTenors(OptionTenors)
      ,mStrikes(Strikes)
      ,mVolatilities(Volatilities)
      ,mDayCounter(DayCounter)
      {

      };

    //~CapFloorTermVolSurfaceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletVTSVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    std::vector<double> mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    OptionletVTSVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,std::vector<double> Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~OptionletVTSVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletVTSVolatility2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionTenor;
    std::vector<double> mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    OptionletVTSVolatility2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionTenor
      ,std::vector<double> Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~OptionletVTSVolatility2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletVTSBlackVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mOptionDate;
    double mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    OptionletVTSBlackVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> OptionDate
      ,double Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~OptionletVTSBlackVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletVTSBlackVariance2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mOptionTenor;
    double mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    OptionletVTSBlackVariance2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> OptionTenor
      ,double Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~OptionletVTSBlackVariance2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletBaseStrikesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    std::vector<double> mReturnValue;

    string mError;

    StrippedOptionletBaseStrikesWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~StrippedOptionletBaseStrikesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletBaseOptionletVolatilitiesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    std::vector<double> mReturnValue;

    string mError;

    StrippedOptionletBaseOptionletVolatilitiesWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~StrippedOptionletBaseOptionletVolatilitiesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletBaseOptionletFixingDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    StrippedOptionletBaseOptionletFixingDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StrippedOptionletBaseOptionletFixingDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletBaseOptionletFixingTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    StrippedOptionletBaseOptionletFixingTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StrippedOptionletBaseOptionletFixingTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletBaseAtmOptionletRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    StrippedOptionletBaseAtmOptionletRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StrippedOptionletBaseAtmOptionletRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletBaseDayCounterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    StrippedOptionletBaseDayCounterWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StrippedOptionletBaseDayCounterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletBaseCalendarWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    StrippedOptionletBaseCalendarWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StrippedOptionletBaseCalendarWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletBaseSettlementDaysWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    StrippedOptionletBaseSettlementDaysWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StrippedOptionletBaseSettlementDaysWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StrippedOptionletBaseBusinessDayConventionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    StrippedOptionletBaseBusinessDayConventionWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~StrippedOptionletBaseBusinessDayConventionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripperOptionletFixingTenorsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    OptionletStripperOptionletFixingTenorsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripperOptionletFixingTenorsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripperOptionletPaymentDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    OptionletStripperOptionletPaymentDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripperOptionletPaymentDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripperOptionletAccrualPeriodsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    OptionletStripperOptionletAccrualPeriodsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripperOptionletAccrualPeriodsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripper1CapFloorPricesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    OptionletStripper1CapFloorPricesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripper1CapFloorPricesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripper1CapFloorVolatilitiesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    OptionletStripper1CapFloorVolatilitiesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripper1CapFloorVolatilitiesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripper1OptionletPricesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    OptionletStripper1OptionletPricesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripper1OptionletPricesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripper1SwitchStrikeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    OptionletStripper1SwitchStrikeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripper1SwitchStrikeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripper2SpreadsVolWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    OptionletStripper2SpreadsVolWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripper2SpreadsVolWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripper2AtmCapFloorPricesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    OptionletStripper2AtmCapFloorPricesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripper2AtmCapFloorPricesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class OptionletStripper2AtmCapFloorStrikesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    OptionletStripper2AtmCapFloorStrikesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~OptionletStripper2AtmCapFloorStrikesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTermVTSVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    std::vector<double> mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    CapFloorTermVTSVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,std::vector<double> Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~CapFloorTermVTSVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTermVTSVolatility2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionTenor;
    std::vector<double> mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    CapFloorTermVTSVolatility2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionTenor
      ,std::vector<double> Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~CapFloorTermVTSVolatility2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTermVolCurveOptionTenorsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    CapFloorTermVolCurveOptionTenorsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorTermVolCurveOptionTenorsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTermVolCurveOptionDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    CapFloorTermVolCurveOptionDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorTermVolCurveOptionDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTermVolSurfaceOptionTenorsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    CapFloorTermVolSurfaceOptionTenorsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorTermVolSurfaceOptionTenorsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTermVolSurfaceOptionDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    CapFloorTermVolSurfaceOptionDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorTermVolSurfaceOptionDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CapFloorTermVolSurfaceStrikesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CapFloorTermVolSurfaceStrikesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CapFloorTermVolSurfaceStrikesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
