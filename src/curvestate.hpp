/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef curvestate_h
#define curvestate_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class CMSwapCurveStateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;
    long mSpanningForwards;

    string mReturnValue;

    string mError;

    CMSwapCurveStateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
      ,long SpanningForwards
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      ,mSpanningForwards(SpanningForwards)
      {

      };

    //~CMSwapCurveStateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CoterminalSwapCurveStateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;

    string mReturnValue;

    string mError;

    CoterminalSwapCurveStateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      {

      };

    //~CoterminalSwapCurveStateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMCurveStateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;

    string mReturnValue;

    string mError;

    LMMCurveStateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      {

      };

    //~LMMCurveStateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CurveStateRateTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CurveStateRateTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CurveStateRateTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CurveStateRateTausWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CurveStateRateTausWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CurveStateRateTausWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CurveStateForwardRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CurveStateForwardRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CurveStateForwardRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CurveStateCoterminalSwapRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CurveStateCoterminalSwapRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CurveStateCoterminalSwapRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CurveStateCMSwapRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mSpanningForwards;

    std::vector<double> mReturnValue;

    string mError;

    CurveStateCMSwapRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long SpanningForwards
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSpanningForwards(SpanningForwards)
      {

      };

    //~CurveStateCMSwapRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CMSwapCurveStateSetOnCMSwapRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mCMSwapRates;

    string mError;

    CMSwapCurveStateSetOnCMSwapRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> CMSwapRates
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCMSwapRates(CMSwapRates)
      {

      };

    //~CMSwapCurveStateSetOnCMSwapRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CoterminalSwapCurveStateSetOnCoterminalSwapRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mCoterminalSwaps;

    string mError;

    CoterminalSwapCurveStateSetOnCoterminalSwapRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> CoterminalSwaps
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCoterminalSwaps(CoterminalSwaps)
      {

      };

    //~CoterminalSwapCurveStateSetOnCoterminalSwapRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMCurveStateSetOnForwardRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRates;

    string mError;

    LMMCurveStateSetOnForwardRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> Rates
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRates(Rates)
      {

      };

    //~LMMCurveStateSetOnForwardRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LMMCurveStateSetOnDiscountRatiosWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mDiscountRatios;

    string mError;

    LMMCurveStateSetOnDiscountRatiosWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> DiscountRatios
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDiscountRatios(DiscountRatios)
      {

      };

    //~LMMCurveStateSetOnDiscountRatiosWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ForwardsFromDiscountRatiosWorker : public Nan::AsyncWorker {
  public:
    long mFirstValidIndex;
    std::vector<double> mDiscountRatios;
    std::vector<double> mTaus;

    std::vector<double> mReturnValue;

    string mError;

    ForwardsFromDiscountRatiosWorker(
      Nan::Callback *callback
      ,long FirstValidIndex
      ,std::vector<double> DiscountRatios
      ,std::vector<double> Taus
    ):
      Nan::AsyncWorker(callback)
      ,mFirstValidIndex(FirstValidIndex)
      ,mDiscountRatios(DiscountRatios)
      ,mTaus(Taus)
      {

      };

    //~ForwardsFromDiscountRatiosWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CoterminalSwapRatesFromDiscountRatiosWorker : public Nan::AsyncWorker {
  public:
    long mFirstValidIndex;
    std::vector<double> mDiscountRatios;
    std::vector<double> mTaus;

    std::vector<double> mReturnValue;

    string mError;

    CoterminalSwapRatesFromDiscountRatiosWorker(
      Nan::Callback *callback
      ,long FirstValidIndex
      ,std::vector<double> DiscountRatios
      ,std::vector<double> Taus
    ):
      Nan::AsyncWorker(callback)
      ,mFirstValidIndex(FirstValidIndex)
      ,mDiscountRatios(DiscountRatios)
      ,mTaus(Taus)
      {

      };

    //~CoterminalSwapRatesFromDiscountRatiosWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CoterminalSwapAnnuitiesFromDiscountRatiosWorker : public Nan::AsyncWorker {
  public:
    long mFirstValidIndex;
    std::vector<double> mDiscountRatios;
    std::vector<double> mTaus;

    std::vector<double> mReturnValue;

    string mError;

    CoterminalSwapAnnuitiesFromDiscountRatiosWorker(
      Nan::Callback *callback
      ,long FirstValidIndex
      ,std::vector<double> DiscountRatios
      ,std::vector<double> Taus
    ):
      Nan::AsyncWorker(callback)
      ,mFirstValidIndex(FirstValidIndex)
      ,mDiscountRatios(DiscountRatios)
      ,mTaus(Taus)
      {

      };

    //~CoterminalSwapAnnuitiesFromDiscountRatiosWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ConstantMaturitySwapRatesFromDiscountRatiosWorker : public Nan::AsyncWorker {
  public:
    long mSpanningForwards;
    long mFirstValidIndex;
    std::vector<double> mDiscountRatios;
    std::vector<double> mTaus;

    std::vector<double> mReturnValue;

    string mError;

    ConstantMaturitySwapRatesFromDiscountRatiosWorker(
      Nan::Callback *callback
      ,long SpanningForwards
      ,long FirstValidIndex
      ,std::vector<double> DiscountRatios
      ,std::vector<double> Taus
    ):
      Nan::AsyncWorker(callback)
      ,mSpanningForwards(SpanningForwards)
      ,mFirstValidIndex(FirstValidIndex)
      ,mDiscountRatios(DiscountRatios)
      ,mTaus(Taus)
      {

      };

    //~ConstantMaturitySwapRatesFromDiscountRatiosWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ConstantMaturitySwapAnnuitiesFromDiscountRatiosWorker : public Nan::AsyncWorker {
  public:
    long mSpanningForwards;
    long mFirstValidIndex;
    std::vector<double> mDiscountRatios;
    std::vector<double> mTaus;

    std::vector<double> mReturnValue;

    string mError;

    ConstantMaturitySwapAnnuitiesFromDiscountRatiosWorker(
      Nan::Callback *callback
      ,long SpanningForwards
      ,long FirstValidIndex
      ,std::vector<double> DiscountRatios
      ,std::vector<double> Taus
    ):
      Nan::AsyncWorker(callback)
      ,mSpanningForwards(SpanningForwards)
      ,mFirstValidIndex(FirstValidIndex)
      ,mDiscountRatios(DiscountRatios)
      ,mTaus(Taus)
      {

      };

    //~ConstantMaturitySwapAnnuitiesFromDiscountRatiosWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
