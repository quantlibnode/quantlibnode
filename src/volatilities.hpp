/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef volatilities_h
#define volatilities_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class BlackConstantVolWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSettlementDate;
    string mCalendar;
    double mVolatility;
    string mDayCounter;

    string mReturnValue;

    string mError;

    BlackConstantVolWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SettlementDate
      ,string Calendar
      ,double Volatility
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlementDate(SettlementDate)
      ,mCalendar(Calendar)
      ,mVolatility(Volatility)
      ,mDayCounter(DayCounter)
      {

      };

    //~BlackConstantVolWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackVarianceSurfaceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSettlementDate;
    string mCalendar;
    std::vector<ObjectHandler::property_t> mDates;
    std::vector<double> mStrikes;
    std::vector< std::vector<double> > mVolatilities;
    string mDayCounter;

    string mReturnValue;

    string mError;

    BlackVarianceSurfaceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SettlementDate
      ,string Calendar
      ,std::vector<ObjectHandler::property_t> Dates
      ,std::vector<double> Strikes
      ,std::vector< std::vector<double> > Volatilities
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlementDate(SettlementDate)
      ,mCalendar(Calendar)
      ,mDates(Dates)
      ,mStrikes(Strikes)
      ,mVolatilities(Volatilities)
      ,mDayCounter(DayCounter)
      {

      };

    //~BlackVarianceSurfaceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSettlementDays;
    string mCalendar;
    std::vector<ObjectHandler::property_t> mOptionTenors;
    std::vector<ObjectHandler::property_t> mVolatilitiesQuotes;
    std::vector<bool> mInclusionInInterpolation;
    string mConvention;
    string mDayCounter;

    string mReturnValue;

    string mError;

    AbcdAtmVolCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SettlementDays
      ,string Calendar
      ,std::vector<ObjectHandler::property_t> OptionTenors
      ,std::vector<ObjectHandler::property_t> VolatilitiesQuotes
      ,std::vector<bool> InclusionInInterpolation
      ,string Convention
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSettlementDays(SettlementDays)
      ,mCalendar(Calendar)
      ,mOptionTenors(OptionTenors)
      ,mVolatilitiesQuotes(VolatilitiesQuotes)
      ,mInclusionInInterpolation(InclusionInInterpolation)
      ,mConvention(Convention)
      ,mDayCounter(DayCounter)
      {

      };

    //~AbcdAtmVolCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrVolSurfaceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mInterestRateIndex;
    ObjectHandler::property_t mBlackAtmVolCurve;
    std::vector<ObjectHandler::property_t> mOptionTenors;
    std::vector<double> mAtmRateSpreads;
    std::vector< std::vector<ObjectHandler::property_t> > mVolatilitiesQuotes;

    string mReturnValue;

    string mError;

    SabrVolSurfaceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string InterestRateIndex
      ,ObjectHandler::property_t BlackAtmVolCurve
      ,std::vector<ObjectHandler::property_t> OptionTenors
      ,std::vector<double> AtmRateSpreads
      ,std::vector< std::vector<ObjectHandler::property_t> > VolatilitiesQuotes
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mInterestRateIndex(InterestRateIndex)
      ,mBlackAtmVolCurve(BlackAtmVolCurve)
      ,mOptionTenors(OptionTenors)
      ,mAtmRateSpreads(AtmRateSpreads)
      ,mVolatilitiesQuotes(VolatilitiesQuotes)
      {

      };

    //~SabrVolSurfaceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VolatilityTermStructureBusinessDayConventionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    VolatilityTermStructureBusinessDayConventionWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VolatilityTermStructureBusinessDayConventionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VolatilityTermStructureOptionDateFromTenorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mTenor;

    long mReturnValue;

    string mError;

    VolatilityTermStructureOptionDateFromTenorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Tenor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTenor(Tenor)
      {

      };

    //~VolatilityTermStructureOptionDateFromTenorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VolatilityTermStructureMinStrikeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VolatilityTermStructureMinStrikeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VolatilityTermStructureMinStrikeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VolatilityTermStructureMaxStrikeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    VolatilityTermStructureMaxStrikeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VolatilityTermStructureMaxStrikeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackAtmVolCurveAtmVolWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackAtmVolCurveAtmVolWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~BlackAtmVolCurveAtmVolWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackAtmVolCurveAtmVol2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionTenor;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackAtmVolCurveAtmVol2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionTenor
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~BlackAtmVolCurveAtmVol2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackAtmVolCurveAtmVol3Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mOptionTime;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackAtmVolCurveAtmVol3Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,double OptionTime
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTime(OptionTime)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~BlackAtmVolCurveAtmVol3Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackAtmVolCurveAtmVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackAtmVolCurveAtmVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~BlackAtmVolCurveAtmVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackAtmVolCurveAtmVariance2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionTenor;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackAtmVolCurveAtmVariance2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionTenor
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~BlackAtmVolCurveAtmVariance2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackAtmVolCurveAtmVariance3Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mOptionTime;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackAtmVolCurveAtmVariance3Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,double OptionTime
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTime(OptionTime)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~BlackAtmVolCurveAtmVariance3Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackVolTermStructureBlackVolWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    double mStrike;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackVolTermStructureBlackVolWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
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

    //~BlackVolTermStructureBlackVolWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackVolTermStructureBlackVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    double mStrike;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackVolTermStructureBlackVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
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

    //~BlackVolTermStructureBlackVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackVolTermStructureBlackForwardVolWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mForwardDate;
    ObjectHandler::property_t mOptionDate;
    double mStrike;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackVolTermStructureBlackForwardVolWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t ForwardDate
      ,ObjectHandler::property_t OptionDate
      ,double Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mForwardDate(ForwardDate)
      ,mOptionDate(OptionDate)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~BlackVolTermStructureBlackForwardVolWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BlackVolTermStructureBlackForwardVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mForwardDate;
    ObjectHandler::property_t mOptionDate;
    double mStrike;
    bool mAllowExtrapolation;

    double mReturnValue;

    string mError;

    BlackVolTermStructureBlackForwardVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t ForwardDate
      ,ObjectHandler::property_t OptionDate
      ,double Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mForwardDate(ForwardDate)
      ,mOptionDate(OptionDate)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~BlackVolTermStructureBlackForwardVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveOptionTenorsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    AbcdAtmVolCurveOptionTenorsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveOptionTenorsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveOptionTenorsInInterpolationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    AbcdAtmVolCurveOptionTenorsInInterpolationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveOptionTenorsInInterpolationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveOptionDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    AbcdAtmVolCurveOptionDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveOptionDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveOptionTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    AbcdAtmVolCurveOptionTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveOptionTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveRmsErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdAtmVolCurveRmsErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveRmsErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveMaxErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdAtmVolCurveMaxErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveMaxErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveAWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdAtmVolCurveAWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveAWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveBWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdAtmVolCurveBWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveBWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveCWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdAtmVolCurveCWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveCWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveDWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AbcdAtmVolCurveDWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveDWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveKatOptionTenorsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    AbcdAtmVolCurveKatOptionTenorsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AbcdAtmVolCurveKatOptionTenorsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AbcdAtmVolCurveKWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mTime;

    double mReturnValue;

    string mError;

    AbcdAtmVolCurveKWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Time
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTime(Time)
      {

      };

    //~AbcdAtmVolCurveKWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VolatilitySpreadsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;

    std::vector<double> mReturnValue;

    string mError;

    VolatilitySpreadsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      {

      };

    //~VolatilitySpreadsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VolatilitySpreads2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionTenor;

    std::vector<double> mReturnValue;

    string mError;

    VolatilitySpreads2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionTenor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      {

      };

    //~VolatilitySpreads2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AtmCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    AtmCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AtmCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrVolatilityWorker : public Nan::AsyncWorker {
  public:
    double mStrike;
    double mForward;
    double mExpTime;
    double mAlpha;
    double mBeta;
    double mNu;
    double mRho;

    double mReturnValue;

    string mError;

    SabrVolatilityWorker(
      Nan::Callback *callback
      ,double Strike
      ,double Forward
      ,double ExpTime
      ,double Alpha
      ,double Beta
      ,double Nu
      ,double Rho
    ):
      Nan::AsyncWorker(callback)
      ,mStrike(Strike)
      ,mForward(Forward)
      ,mExpTime(ExpTime)
      ,mAlpha(Alpha)
      ,mBeta(Beta)
      ,mNu(Nu)
      ,mRho(Rho)
      {

      };

    //~SabrVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
