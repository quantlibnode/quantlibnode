/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef swaptionvolstructure_h
#define swaptionvolstructure_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class RelinkableHandleSwaptionVolatilityStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurrentLink;

    string mReturnValue;

    string mError;

    RelinkableHandleSwaptionVolatilityStructureWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurrentLink
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurrentLink(CurrentLink)
      {

      };

    //~RelinkableHandleSwaptionVolatilityStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ConstantSwaptionVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mNDays;
    string mCalendar;
    string mBusinessDayConvention;
    ObjectHandler::property_t mVolatility;
    string mDayCounter;

    string mReturnValue;

    string mError;

    ConstantSwaptionVolatilityWorker(
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

    //~ConstantSwaptionVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SpreadedSwaptionVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mBaseVolStructure;
    ObjectHandler::property_t mSpread;

    string mReturnValue;

    string mError;

    SpreadedSwaptionVolatilityWorker(
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

    //~SpreadedSwaptionVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSMatrixWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCalendar;
    string mBusinessDayConvention;
    std::vector<ObjectHandler::property_t> mOptionTenors;
    std::vector<ObjectHandler::property_t> mSwapTenors;
    std::vector< std::vector<ObjectHandler::property_t> > mVolatilities;
    string mDayCounter;

    string mReturnValue;

    string mError;

    SwaptionVTSMatrixWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Calendar
      ,string BusinessDayConvention
      ,std::vector<ObjectHandler::property_t> OptionTenors
      ,std::vector<ObjectHandler::property_t> SwapTenors
      ,std::vector< std::vector<ObjectHandler::property_t> > Volatilities
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCalendar(Calendar)
      ,mBusinessDayConvention(BusinessDayConvention)
      ,mOptionTenors(OptionTenors)
      ,mSwapTenors(SwapTenors)
      ,mVolatilities(Volatilities)
      ,mDayCounter(DayCounter)
      {

      };

    //~SwaptionVTSMatrixWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVolCube2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAtmVolStructure;
    std::vector<ObjectHandler::property_t> mOptionTenor;
    std::vector<ObjectHandler::property_t> mSwapTenor;
    std::vector<double> mStrikeSpreads;
    std::vector< std::vector<ObjectHandler::property_t> > mSpreadVols;
    string mSwapIndexBase;
    string mShortSwapIndexBase;
    bool mVegaWeightedSmileFit;

    string mReturnValue;

    string mError;

    SwaptionVolCube2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AtmVolStructure
      ,std::vector<ObjectHandler::property_t> OptionTenor
      ,std::vector<ObjectHandler::property_t> SwapTenor
      ,std::vector<double> StrikeSpreads
      ,std::vector< std::vector<ObjectHandler::property_t> > SpreadVols
      ,string SwapIndexBase
      ,string ShortSwapIndexBase
      ,bool VegaWeightedSmileFit
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAtmVolStructure(AtmVolStructure)
      ,mOptionTenor(OptionTenor)
      ,mSwapTenor(SwapTenor)
      ,mStrikeSpreads(StrikeSpreads)
      ,mSpreadVols(SpreadVols)
      ,mSwapIndexBase(SwapIndexBase)
      ,mShortSwapIndexBase(ShortSwapIndexBase)
      ,mVegaWeightedSmileFit(VegaWeightedSmileFit)
      {

      };

    //~SwaptionVolCube2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVolCube1Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAtmVolStructure;
    std::vector<ObjectHandler::property_t> mOptionTenors;
    std::vector<ObjectHandler::property_t> mSwapTenors;
    std::vector<double> mStrikeSpreads;
    std::vector< std::vector<ObjectHandler::property_t> > mSpreadVols;
    string mSwapIndexBase;
    string mShortSwapIndexBase;
    bool mVegaWeightedSmileFit;
    std::vector< std::vector<ObjectHandler::property_t> > mGuess;
    std::vector<bool> mIsFixed;
    bool mIsAtmCalibrated;
    string mEndCriteria;
    double mMaxErrorTol;
    string mOptMethod;

    string mReturnValue;

    string mError;

    SwaptionVolCube1Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AtmVolStructure
      ,std::vector<ObjectHandler::property_t> OptionTenors
      ,std::vector<ObjectHandler::property_t> SwapTenors
      ,std::vector<double> StrikeSpreads
      ,std::vector< std::vector<ObjectHandler::property_t> > SpreadVols
      ,string SwapIndexBase
      ,string ShortSwapIndexBase
      ,bool VegaWeightedSmileFit
      ,std::vector< std::vector<ObjectHandler::property_t> > Guess
      ,std::vector<bool> IsFixed
      ,bool IsAtmCalibrated
      ,string EndCriteria
      ,double MaxErrorTol
      ,string OptMethod
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAtmVolStructure(AtmVolStructure)
      ,mOptionTenors(OptionTenors)
      ,mSwapTenors(SwapTenors)
      ,mStrikeSpreads(StrikeSpreads)
      ,mSpreadVols(SpreadVols)
      ,mSwapIndexBase(SwapIndexBase)
      ,mShortSwapIndexBase(ShortSwapIndexBase)
      ,mVegaWeightedSmileFit(VegaWeightedSmileFit)
      ,mGuess(Guess)
      ,mIsFixed(IsFixed)
      ,mIsAtmCalibrated(IsAtmCalibrated)
      ,mEndCriteria(EndCriteria)
      ,mMaxErrorTol(MaxErrorTol)
      ,mOptMethod(OptMethod)
      {

      };

    //~SwaptionVolCube1Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SmileSectionByCubeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mVolCube;
    ObjectHandler::property_t mOptionDate;
    string mSwapTenor;

    string mReturnValue;

    string mError;

    SmileSectionByCubeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string VolCube
      ,ObjectHandler::property_t OptionDate
      ,string SwapTenor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mVolCube(VolCube)
      ,mOptionDate(OptionDate)
      ,mSwapTenor(SwapTenor)
      {

      };

    //~SmileSectionByCubeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SmileSectionByCube2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mVolCube;
    string mOptionDate;
    string mSwapTenor;

    string mReturnValue;

    string mError;

    SmileSectionByCube2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string VolCube
      ,string OptionDate
      ,string SwapTenor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mVolCube(VolCube)
      ,mOptionDate(OptionDate)
      ,mSwapTenor(SwapTenor)
      {

      };

    //~SmileSectionByCube2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    string mSwapTenor;
    std::vector<double> mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    SwaptionVTSVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,string SwapTenor
      ,std::vector<double> Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mSwapTenor(SwapTenor)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~SwaptionVTSVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSVolatility2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionTenor;
    string mSwapTenor;
    std::vector<double> mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    SwaptionVTSVolatility2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionTenor
      ,string SwapTenor
      ,std::vector<double> Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      ,mSwapTenor(SwapTenor)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~SwaptionVTSVolatility2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSBlackVarianceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mOptionDate;
    string mSwapTenor;
    double mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    SwaptionVTSBlackVarianceWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> OptionDate
      ,string SwapTenor
      ,double Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mSwapTenor(SwapTenor)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~SwaptionVTSBlackVarianceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSBlackVariance2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mOptionTenor;
    string mSwapTenor;
    double mStrike;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    SwaptionVTSBlackVariance2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> OptionTenor
      ,string SwapTenor
      ,double Strike
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      ,mSwapTenor(SwapTenor)
      ,mStrike(Strike)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~SwaptionVTSBlackVariance2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSMaxSwapTenorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SwaptionVTSMaxSwapTenorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwaptionVTSMaxSwapTenorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSBusinessDayConventionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    SwaptionVTSBusinessDayConventionWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwaptionVTSBusinessDayConventionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSOptionDateFromTenorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mOptionTenor;

    std::vector<long> mReturnValue;

    string mError;

    SwaptionVTSOptionDateFromTenorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> OptionTenor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      {

      };

    //~SwaptionVTSOptionDateFromTenorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSSwapLengthWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mSwapTenor;

    std::vector<double> mReturnValue;

    string mError;

    SwaptionVTSSwapLengthWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> SwapTenor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwapTenor(SwapTenor)
      {

      };

    //~SwaptionVTSSwapLengthWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSSwapLength2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mSwapStart;
    ObjectHandler::property_t mSwapEnd;

    double mReturnValue;

    string mError;

    SwaptionVTSSwapLength2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t SwapStart
      ,ObjectHandler::property_t SwapEnd
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwapStart(SwapStart)
      ,mSwapEnd(SwapEnd)
      {

      };

    //~SwaptionVTSSwapLength2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSMatrixOptionDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    SwaptionVTSMatrixOptionDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwaptionVTSMatrixOptionDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSMatrixOptionTenorsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    SwaptionVTSMatrixOptionTenorsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwaptionVTSMatrixOptionTenorsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSMatrixSwapTenorsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    SwaptionVTSMatrixSwapTenorsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwaptionVTSMatrixSwapTenorsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSMatrixLocateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mOptionDate;
    string mSwapTenor;

    std::vector<long> mReturnValue;

    string mError;

    SwaptionVTSMatrixLocateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t OptionDate
      ,string SwapTenor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mSwapTenor(SwapTenor)
      {

      };

    //~SwaptionVTSMatrixLocateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSatmStrikeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mOptionDate;
    string mSwapTenor;

    std::vector<double> mReturnValue;

    string mError;

    SwaptionVTSatmStrikeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> OptionDate
      ,string SwapTenor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionDate(OptionDate)
      ,mSwapTenor(SwapTenor)
      {

      };

    //~SwaptionVTSatmStrikeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwaptionVTSatmStrike2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mOptionTenor;
    string mSwapTenor;

    std::vector<double> mReturnValue;

    string mError;

    SwaptionVTSatmStrike2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> OptionTenor
      ,string SwapTenor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionTenor(OptionTenor)
      ,mSwapTenor(SwapTenor)
      {

      };

    //~SwaptionVTSatmStrike2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SparseSabrParametersWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    SparseSabrParametersWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SparseSabrParametersWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DenseSabrParametersWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    DenseSabrParametersWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~DenseSabrParametersWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketVolCubeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    MarketVolCubeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketVolCubeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VolCubeAtmCalibratedWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    VolCubeAtmCalibratedWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~VolCubeAtmCalibratedWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
