/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef quotes_h
#define quotes_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class SimpleQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mValue;
    double mTickValue;

    string mReturnValue;

    string mError;

    SimpleQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Value
      ,double TickValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mValue(Value)
      ,mTickValue(TickValue)
      {

      };

    //~SimpleQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ForwardValueQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mIborIndex;
    ObjectHandler::property_t mFixingDate;

    string mReturnValue;

    string mError;

    ForwardValueQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string IborIndex
      ,ObjectHandler::property_t FixingDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIborIndex(IborIndex)
      ,mFixingDate(FixingDate)
      {

      };

    //~ForwardValueQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ForwardSwapQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSwapIndex;
    ObjectHandler::property_t mSpread;
    string mForwardStart;

    string mReturnValue;

    string mError;

    ForwardSwapQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string SwapIndex
      ,ObjectHandler::property_t Spread
      ,string ForwardStart
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwapIndex(SwapIndex)
      ,mSpread(Spread)
      ,mForwardStart(ForwardStart)
      {

      };

    //~ForwardSwapQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ImpliedStdDevQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOptionType;
    ObjectHandler::property_t mAtmForwardValue;
    ObjectHandler::property_t mOptionPrice;
    double mStrike;
    double mGuess;
    double mAccuracy;

    string mReturnValue;

    string mError;

    ImpliedStdDevQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OptionType
      ,ObjectHandler::property_t AtmForwardValue
      ,ObjectHandler::property_t OptionPrice
      ,double Strike
      ,double Guess
      ,double Accuracy
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOptionType(OptionType)
      ,mAtmForwardValue(AtmForwardValue)
      ,mOptionPrice(OptionPrice)
      ,mStrike(Strike)
      ,mGuess(Guess)
      ,mAccuracy(Accuracy)
      {

      };

    //~ImpliedStdDevQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EurodollarFuturesImpliedStdDevQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAtmForwardValue;
    ObjectHandler::property_t mCallPrice;
    ObjectHandler::property_t mPutPrice;
    double mStrike;
    double mGuess;
    double mAccuracy;

    string mReturnValue;

    string mError;

    EurodollarFuturesImpliedStdDevQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AtmForwardValue
      ,ObjectHandler::property_t CallPrice
      ,ObjectHandler::property_t PutPrice
      ,double Strike
      ,double Guess
      ,double Accuracy
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAtmForwardValue(AtmForwardValue)
      ,mCallPrice(CallPrice)
      ,mPutPrice(PutPrice)
      ,mStrike(Strike)
      ,mGuess(Guess)
      ,mAccuracy(Accuracy)
      {

      };

    //~EurodollarFuturesImpliedStdDevQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CompositeQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mElement1;
    ObjectHandler::property_t mElement2;
    string mOperator;

    string mReturnValue;

    string mError;

    CompositeQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t Element1
      ,ObjectHandler::property_t Element2
      ,string Operator
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mElement1(Element1)
      ,mElement2(Element2)
      ,mOperator(Operator)
      {

      };

    //~CompositeQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesConvAdjustmentQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mIborIndex;
    string mImmCode;
    ObjectHandler::property_t mFuturesQuote;
    ObjectHandler::property_t mVolatility;
    ObjectHandler::property_t mMeanReversion;

    string mReturnValue;

    string mError;

    FuturesConvAdjustmentQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string IborIndex
      ,string ImmCode
      ,ObjectHandler::property_t FuturesQuote
      ,ObjectHandler::property_t Volatility
      ,ObjectHandler::property_t MeanReversion
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIborIndex(IborIndex)
      ,mImmCode(ImmCode)
      ,mFuturesQuote(FuturesQuote)
      ,mVolatility(Volatility)
      ,mMeanReversion(MeanReversion)
      {

      };

    //~FuturesConvAdjustmentQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LastFixingQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mIndex;

    string mReturnValue;

    string mError;

    LastFixingQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~LastFixingQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RelinkableHandleQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurrentLink;

    string mReturnValue;

    string mError;

    RelinkableHandleQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurrentLink
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurrentLink(CurrentLink)
      {

      };

    //~RelinkableHandleQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class QuoteValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    QuoteValueWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~QuoteValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class QuoteIsValidWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    QuoteIsValidWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~QuoteIsValidWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SimpleQuoteResetWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mError;

    SimpleQuoteResetWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SimpleQuoteResetWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SimpleQuoteSetValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mValue;

    double mReturnValue;

    string mError;

    SimpleQuoteSetValueWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Value
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mValue(Value)
      {

      };

    //~SimpleQuoteSetValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SimpleQuoteSetTickValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mValue;

    string mError;

    SimpleQuoteSetTickValueWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Value
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mValue(Value)
      {

      };

    //~SimpleQuoteSetTickValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SimpleQuoteTickValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    SimpleQuoteTickValueWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SimpleQuoteTickValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesConvAdjustmentQuoteVolatilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    FuturesConvAdjustmentQuoteVolatilityWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FuturesConvAdjustmentQuoteVolatilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesConvAdjustmentQuoteMeanReversionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    FuturesConvAdjustmentQuoteMeanReversionWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FuturesConvAdjustmentQuoteMeanReversionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesConvAdjustmentQuoteImmDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    FuturesConvAdjustmentQuoteImmDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FuturesConvAdjustmentQuoteImmDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FuturesConvAdjustmentQuoteFuturesValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    FuturesConvAdjustmentQuoteFuturesValueWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~FuturesConvAdjustmentQuoteFuturesValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class LastFixingQuoteReferenceDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    LastFixingQuoteReferenceDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~LastFixingQuoteReferenceDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BucketAnalysisWorker : public Nan::AsyncWorker {
  public:
    std::vector< std::vector<ObjectHandler::property_t> > mSimpleQuote;
    std::vector<string> mInstruments;
    std::vector<double> mQuantities;
    double mShift;
    string mSensitivityAnalysis;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    BucketAnalysisWorker(
      Nan::Callback *callback
      ,std::vector< std::vector<ObjectHandler::property_t> > SimpleQuote
      ,std::vector<string> Instruments
      ,std::vector<double> Quantities
      ,double Shift
      ,string SensitivityAnalysis
    ):
      Nan::AsyncWorker(callback)
      ,mSimpleQuote(SimpleQuote)
      ,mInstruments(Instruments)
      ,mQuantities(Quantities)
      ,mShift(Shift)
      ,mSensitivityAnalysis(SensitivityAnalysis)
      {

      };

    //~BucketAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BucketAnalysisDeltaWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mSimpleQuote;
    std::vector<ObjectHandler::property_t> mParameters;
    double mShift;
    string mSensitivityAnalysis;

    std::vector<double> mReturnValue;

    string mError;

    BucketAnalysisDeltaWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t SimpleQuote
      ,std::vector<ObjectHandler::property_t> Parameters
      ,double Shift
      ,string SensitivityAnalysis
    ):
      Nan::AsyncWorker(callback)
      ,mSimpleQuote(SimpleQuote)
      ,mParameters(Parameters)
      ,mShift(Shift)
      ,mSensitivityAnalysis(SensitivityAnalysis)
      {

      };

    //~BucketAnalysisDeltaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BucketAnalysisDelta2Worker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mSimpleQuote;
    std::vector<ObjectHandler::property_t> mParameters;
    double mShift;
    string mSensitivityAnalysis;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    BucketAnalysisDelta2Worker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> SimpleQuote
      ,std::vector<ObjectHandler::property_t> Parameters
      ,double Shift
      ,string SensitivityAnalysis
    ):
      Nan::AsyncWorker(callback)
      ,mSimpleQuote(SimpleQuote)
      ,mParameters(Parameters)
      ,mShift(Shift)
      ,mSensitivityAnalysis(SensitivityAnalysis)
      {

      };

    //~BucketAnalysisDelta2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
