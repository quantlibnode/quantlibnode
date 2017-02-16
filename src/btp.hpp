/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef btp_h
#define btp_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class CCTEUWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDescription;
    ObjectHandler::property_t mMaturityDate;
    double mSpread;
    ObjectHandler::property_t mFwdCurve;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mIssueDate;

    string mReturnValue;

    string mError;

    CCTEUWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Description
      ,ObjectHandler::property_t MaturityDate
      ,double Spread
      ,ObjectHandler::property_t FwdCurve
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t IssueDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDescription(Description)
      ,mMaturityDate(MaturityDate)
      ,mSpread(Spread)
      ,mFwdCurve(FwdCurve)
      ,mStartDate(StartDate)
      ,mIssueDate(IssueDate)
      {

      };

    //~CCTEUWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BTPWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDescription;
    ObjectHandler::property_t mMaturityDate;
    double mCoupon;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mIssueDate;

    string mReturnValue;

    string mError;

    BTPWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Description
      ,ObjectHandler::property_t MaturityDate
      ,double Coupon
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t IssueDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDescription(Description)
      ,mMaturityDate(MaturityDate)
      ,mCoupon(Coupon)
      ,mStartDate(StartDate)
      ,mIssueDate(IssueDate)
      {

      };

    //~BTPWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BTP2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDescription;
    ObjectHandler::property_t mMaturityDate;
    double mCoupon;
    double mRedemption;
    ObjectHandler::property_t mStartDate;
    ObjectHandler::property_t mIssueDate;

    string mReturnValue;

    string mError;

    BTP2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Description
      ,ObjectHandler::property_t MaturityDate
      ,double Coupon
      ,double Redemption
      ,ObjectHandler::property_t StartDate
      ,ObjectHandler::property_t IssueDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDescription(Description)
      ,mMaturityDate(MaturityDate)
      ,mCoupon(Coupon)
      ,mRedemption(Redemption)
      ,mStartDate(StartDate)
      ,mIssueDate(IssueDate)
      {

      };

    //~BTP2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoBasketWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mBTPs;
    std::vector<double> mOutstandings;
    std::vector<ObjectHandler::property_t> mPrices;

    string mReturnValue;

    string mError;

    RendistatoBasketWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> BTPs
      ,std::vector<double> Outstandings
      ,std::vector<ObjectHandler::property_t> Prices
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mBTPs(BTPs)
      ,mOutstandings(Outstandings)
      ,mPrices(Prices)
      {

      };

    //~RendistatoBasketWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mRendistatoBasket;
    string mEuribor;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    RendistatoCalculatorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string RendistatoBasket
      ,string Euribor
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRendistatoBasket(RendistatoBasket)
      ,mEuribor(Euribor)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~RendistatoCalculatorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoEquivalentSwapLengthQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mRendistatoCalculator;

    string mReturnValue;

    string mError;

    RendistatoEquivalentSwapLengthQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string RendistatoCalculator
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRendistatoCalculator(RendistatoCalculator)
      {

      };

    //~RendistatoEquivalentSwapLengthQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoEquivalentSwapSpreadQuoteWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mRendistatoCalculator;

    string mReturnValue;

    string mError;

    RendistatoEquivalentSwapSpreadQuoteWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string RendistatoCalculator
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRendistatoCalculator(RendistatoCalculator)
      {

      };

    //~RendistatoEquivalentSwapSpreadQuoteWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoBasketSizeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    RendistatoBasketSizeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoBasketSizeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoBasketOutstandingWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RendistatoBasketOutstandingWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoBasketOutstandingWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoBasketOutstandingsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    RendistatoBasketOutstandingsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoBasketOutstandingsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoBasketWeightsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    RendistatoBasketWeightsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoBasketWeightsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RendistatoCalculatorYieldWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorDurationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RendistatoCalculatorDurationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorDurationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorYieldsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    RendistatoCalculatorYieldsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorYieldsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorDurationsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    RendistatoCalculatorDurationsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorDurationsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorSwapLengthsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    RendistatoCalculatorSwapLengthsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorSwapLengthsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorSwapRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    RendistatoCalculatorSwapRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorSwapRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorSwapYieldsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    RendistatoCalculatorSwapYieldsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorSwapYieldsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorSwapDurationsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    RendistatoCalculatorSwapDurationsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorSwapDurationsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorEquivalentSwapRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RendistatoCalculatorEquivalentSwapRateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorEquivalentSwapRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorEquivalentSwapYieldWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RendistatoCalculatorEquivalentSwapYieldWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorEquivalentSwapYieldWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorEquivalentSwapDurationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RendistatoCalculatorEquivalentSwapDurationWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorEquivalentSwapDurationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorEquivalentSwapSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RendistatoCalculatorEquivalentSwapSpreadWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorEquivalentSwapSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RendistatoCalculatorEquivalentSwapLengthWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    RendistatoCalculatorEquivalentSwapLengthWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~RendistatoCalculatorEquivalentSwapLengthWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
