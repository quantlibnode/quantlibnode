// This is a generated file, modify: generate/templates/class_header.h

#ifndef products_h
#define products_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class MarketModelMultiProductCompositeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    MarketModelMultiProductCompositeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelMultiProductCompositeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelOneStepForwardsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;
    std::vector<double> mAccruals;
    std::vector<double> mPaymentTimes;
    std::vector<double> mStrikes;

    string mReturnValue;

    string mError;

    MarketModelOneStepForwardsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
      ,std::vector<double> Accruals
      ,std::vector<double> PaymentTimes
      ,std::vector<double> Strikes
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      ,mAccruals(Accruals)
      ,mPaymentTimes(PaymentTimes)
      ,mStrikes(Strikes)
      {

      };

    //~MarketModelOneStepForwardsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelMultiStepRatchetWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;
    std::vector<double> mAccruals;
    std::vector<double> mPaymentTimes;
    double mGearingOfFloor;
    double mGearingOfFixing;
    double mSpreadOfFloor;
    double mSpreadOfFixing;
    double mInitialFloor;
    bool mPayer;

    string mReturnValue;

    string mError;

    MarketModelMultiStepRatchetWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
      ,std::vector<double> Accruals
      ,std::vector<double> PaymentTimes
      ,double GearingOfFloor
      ,double GearingOfFixing
      ,double SpreadOfFloor
      ,double SpreadOfFixing
      ,double InitialFloor
      ,bool Payer
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      ,mAccruals(Accruals)
      ,mPaymentTimes(PaymentTimes)
      ,mGearingOfFloor(GearingOfFloor)
      ,mGearingOfFixing(GearingOfFixing)
      ,mSpreadOfFloor(SpreadOfFloor)
      ,mSpreadOfFixing(SpreadOfFixing)
      ,mInitialFloor(InitialFloor)
      ,mPayer(Payer)
      {

      };

    //~MarketModelMultiStepRatchetWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelOneStepOptionletsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;
    std::vector<double> mAccruals;
    std::vector<double> mPaymentTimes;
    std::vector<string> mPayoffs;

    string mReturnValue;

    string mError;

    MarketModelOneStepOptionletsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
      ,std::vector<double> Accruals
      ,std::vector<double> PaymentTimes
      ,std::vector<string> Payoffs
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      ,mAccruals(Accruals)
      ,mPaymentTimes(PaymentTimes)
      ,mPayoffs(Payoffs)
      {

      };

    //~MarketModelOneStepOptionletsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelMultiProductCompositeAddWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mProduct;

    string mError;

    MarketModelMultiProductCompositeAddWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Product
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mProduct(Product)
      {

      };

    //~MarketModelMultiProductCompositeAddWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelMultiProductCompositeFinalizeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mError;

    MarketModelMultiProductCompositeFinalizeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelMultiProductCompositeFinalizeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelMultiProductSuggestedNumerairesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    MarketModelMultiProductSuggestedNumerairesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelMultiProductSuggestedNumerairesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelMultiProductPossibleCashFlowTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    MarketModelMultiProductPossibleCashFlowTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelMultiProductPossibleCashFlowTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelMultiProductNumberOfProductsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    MarketModelMultiProductNumberOfProductsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelMultiProductNumberOfProductsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStepWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStepWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~MarketModelMultiProductMaxNumberOfCashFlowsPerProductPerStepWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
