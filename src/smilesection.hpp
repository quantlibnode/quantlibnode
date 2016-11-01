// This is a generated file, modify: generate/templates/class_header.h

#ifndef smilesection_h
#define smilesection_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class FlatSmileSectionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    double mVolatility;
    string mDayCounter;
    ObjectHandler::property_t mRefDate;
    double mAtmValue;

    string mReturnValue;

    string mError;

    FlatSmileSectionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,double Volatility
      ,string DayCounter
      ,ObjectHandler::property_t RefDate
      ,double AtmValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mVolatility(Volatility)
      ,mDayCounter(DayCounter)
      ,mRefDate(RefDate)
      ,mAtmValue(AtmValue)
      {

      };

    //~FlatSmileSectionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrInterpolatedSmileSectionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    double mForwardRate;
    std::vector<double> mStrike;
    bool mFloatingStrike;
    double mAtmVolatility;
    std::vector<double> mVolatilitySpreads;
    double mAlpha;
    double mBeta;
    double mNu;
    double mRho;
    bool mAlphaIsFixed;
    bool mBetaIsFixed;
    bool mNuIsFixed;
    bool mRhoIsFixed;
    bool mVegaWeighted;
    string mEndCriteria;
    string mMethod;
    string mDayCounter;

    string mReturnValue;

    string mError;

    SabrInterpolatedSmileSectionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,double ForwardRate
      ,std::vector<double> Strike
      ,bool FloatingStrike
      ,double AtmVolatility
      ,std::vector<double> VolatilitySpreads
      ,double Alpha
      ,double Beta
      ,double Nu
      ,double Rho
      ,bool AlphaIsFixed
      ,bool BetaIsFixed
      ,bool NuIsFixed
      ,bool RhoIsFixed
      ,bool VegaWeighted
      ,string EndCriteria
      ,string Method
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mForwardRate(ForwardRate)
      ,mStrike(Strike)
      ,mFloatingStrike(FloatingStrike)
      ,mAtmVolatility(AtmVolatility)
      ,mVolatilitySpreads(VolatilitySpreads)
      ,mAlpha(Alpha)
      ,mBeta(Beta)
      ,mNu(Nu)
      ,mRho(Rho)
      ,mAlphaIsFixed(AlphaIsFixed)
      ,mBetaIsFixed(BetaIsFixed)
      ,mNuIsFixed(NuIsFixed)
      ,mRhoIsFixed(RhoIsFixed)
      ,mVegaWeighted(VegaWeighted)
      ,mEndCriteria(EndCriteria)
      ,mMethod(Method)
      ,mDayCounter(DayCounter)
      {

      };

    //~SabrInterpolatedSmileSectionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrInterpolatedSmileSection1Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    ObjectHandler::property_t mForwardRate;
    std::vector<double> mStrike;
    bool mFloatingStrike;
    ObjectHandler::property_t mAtmVolatility;
    std::vector<ObjectHandler::property_t> mVolatilitySpreads;
    double mAlpha;
    double mBeta;
    double mNu;
    double mRho;
    bool mAlphaIsFixed;
    bool mBetaIsFixed;
    bool mNuIsFixed;
    bool mRhoIsFixed;
    bool mVegaWeighted;
    string mEndCriteria;
    string mMethod;
    string mDayCounter;

    string mReturnValue;

    string mError;

    SabrInterpolatedSmileSection1Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,ObjectHandler::property_t ForwardRate
      ,std::vector<double> Strike
      ,bool FloatingStrike
      ,ObjectHandler::property_t AtmVolatility
      ,std::vector<ObjectHandler::property_t> VolatilitySpreads
      ,double Alpha
      ,double Beta
      ,double Nu
      ,double Rho
      ,bool AlphaIsFixed
      ,bool BetaIsFixed
      ,bool NuIsFixed
      ,bool RhoIsFixed
      ,bool VegaWeighted
      ,string EndCriteria
      ,string Method
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mForwardRate(ForwardRate)
      ,mStrike(Strike)
      ,mFloatingStrike(FloatingStrike)
      ,mAtmVolatility(AtmVolatility)
      ,mVolatilitySpreads(VolatilitySpreads)
      ,mAlpha(Alpha)
      ,mBeta(Beta)
      ,mNu(Nu)
      ,mRho(Rho)
      ,mAlphaIsFixed(AlphaIsFixed)
      ,mBetaIsFixed(BetaIsFixed)
      ,mNuIsFixed(NuIsFixed)
      ,mRhoIsFixed(RhoIsFixed)
      ,mVegaWeighted(VegaWeighted)
      ,mEndCriteria(EndCriteria)
      ,mMethod(Method)
      ,mDayCounter(DayCounter)
      {

      };

    //~SabrInterpolatedSmileSection1Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrSmileSectionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mOptionTime;
    std::vector<double> mStrikes;
    std::vector<ObjectHandler::property_t> mStdDevs;
    ObjectHandler::property_t mForward;
    double mAlpha;
    double mBeta;
    double mNu;
    double mRho;
    bool mAlphaIsFixed;
    bool mBetaIsFixed;
    bool mNuIsFixed;
    bool mRhoIsFixed;
    bool mVegaWeighted;
    string mEndCriteria;
    string mMethod;

    string mReturnValue;

    string mError;

    SabrSmileSectionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double OptionTime
      ,std::vector<double> Strikes
      ,std::vector<ObjectHandler::property_t> StdDevs
      ,ObjectHandler::property_t Forward
      ,double Alpha
      ,double Beta
      ,double Nu
      ,double Rho
      ,bool AlphaIsFixed
      ,bool BetaIsFixed
      ,bool NuIsFixed
      ,bool RhoIsFixed
      ,bool VegaWeighted
      ,string EndCriteria
      ,string Method
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTime(OptionTime)
      ,mStrikes(Strikes)
      ,mStdDevs(StdDevs)
      ,mForward(Forward)
      ,mAlpha(Alpha)
      ,mBeta(Beta)
      ,mNu(Nu)
      ,mRho(Rho)
      ,mAlphaIsFixed(AlphaIsFixed)
      ,mBetaIsFixed(BetaIsFixed)
      ,mNuIsFixed(NuIsFixed)
      ,mRhoIsFixed(RhoIsFixed)
      ,mVegaWeighted(VegaWeighted)
      ,mEndCriteria(EndCriteria)
      ,mMethod(Method)
      {

      };

    //~SabrSmileSectionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class InterpolatedSmileSectionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    std::vector<double> mStrikes;
    std::vector<ObjectHandler::property_t> mStdDevs;
    ObjectHandler::property_t mAtmLevel;
    string mDayCounter;

    string mReturnValue;

    string mError;

    InterpolatedSmileSectionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,std::vector<double> Strikes
      ,std::vector<ObjectHandler::property_t> StdDevs
      ,ObjectHandler::property_t AtmLevel
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mStrikes(Strikes)
      ,mStdDevs(StdDevs)
      ,mAtmLevel(AtmLevel)
      ,mDayCounter(DayCounter)
      {

      };

    //~InterpolatedSmileSectionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SmileSectionFromSabrVolSurfaceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSabrVolSurface;
    double mOptionTime;

    string mReturnValue;

    string mError;

    SmileSectionFromSabrVolSurfaceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SabrVolSurface
      ,double OptionTime
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSabrVolSurface(SabrVolSurface)
      ,mOptionTime(OptionTime)
      {

      };

    //~SmileSectionFromSabrVolSurfaceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SmileSectionVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mStrike;

    double mReturnValue;

    string mError;

    SmileSectionVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Strike
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mStrike(Strike)
      {

      };

    //~SmileSectionVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SmileSectionVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mStrike;

    double mReturnValue;

    string mError;

    SmileSectionVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Strike
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mStrike(Strike)
      {

      };

    //~SmileSectionVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SmileSectionAtmLevelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SmileSectionAtmLevelWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SmileSectionAtmLevelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SmileSectionExerciseDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    SmileSectionExerciseDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SmileSectionExerciseDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SmileSectionDayCounterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SmileSectionDayCounterWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SmileSectionDayCounterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrInterpolatedSmileSectionAlphaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SabrInterpolatedSmileSectionAlphaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SabrInterpolatedSmileSectionAlphaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrInterpolatedSmileSectionBetaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SabrInterpolatedSmileSectionBetaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SabrInterpolatedSmileSectionBetaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrInterpolatedSmileSectionNuWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SabrInterpolatedSmileSectionNuWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SabrInterpolatedSmileSectionNuWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrInterpolatedSmileSectionRhoWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SabrInterpolatedSmileSectionRhoWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SabrInterpolatedSmileSectionRhoWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrInterpolatedSmileSectionErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SabrInterpolatedSmileSectionErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SabrInterpolatedSmileSectionErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrInterpolatedSmileSectionMaxErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SabrInterpolatedSmileSectionMaxErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SabrInterpolatedSmileSectionMaxErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SabrInterpolatedSmileSectionEndCriteriaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SabrInterpolatedSmileSectionEndCriteriaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SabrInterpolatedSmileSectionEndCriteriaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
