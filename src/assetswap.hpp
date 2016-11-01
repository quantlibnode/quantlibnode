// This is a generated file, modify: generate/templates/class_header.h

#ifndef assetswap_h
#define assetswap_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class AssetSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    bool mPayBondCoupon;
    string mBond;
    double mCleanPrice;
    string mIborIndex;
    double mSpread;
    string mFloatingLegSchedule;
    string mFloatingLegDayCounter;
    bool mParAssetSwap;

    string mReturnValue;

    string mError;

    AssetSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,bool PayBondCoupon
      ,string Bond
      ,double CleanPrice
      ,string IborIndex
      ,double Spread
      ,string FloatingLegSchedule
      ,string FloatingLegDayCounter
      ,bool ParAssetSwap
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayBondCoupon(PayBondCoupon)
      ,mBond(Bond)
      ,mCleanPrice(CleanPrice)
      ,mIborIndex(IborIndex)
      ,mSpread(Spread)
      ,mFloatingLegSchedule(FloatingLegSchedule)
      ,mFloatingLegDayCounter(FloatingLegDayCounter)
      ,mParAssetSwap(ParAssetSwap)
      {

      };

    //~AssetSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AssetSwap2Worker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    bool mParAssetSwap;
    string mBond;
    double mCleanPrice;
    double mNonParRepayment;
    double mGearing;
    string mIborIndex;
    double mSpread;
    string mFloatingLegDayCounter;
    ObjectHandler::property_t mDealMaturity;
    bool mPayBondCoupon;

    string mReturnValue;

    string mError;

    AssetSwap2Worker(
      Nan::Callback *callback
      ,string ObjectID
      ,bool ParAssetSwap
      ,string Bond
      ,double CleanPrice
      ,double NonParRepayment
      ,double Gearing
      ,string IborIndex
      ,double Spread
      ,string FloatingLegDayCounter
      ,ObjectHandler::property_t DealMaturity
      ,bool PayBondCoupon
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mParAssetSwap(ParAssetSwap)
      ,mBond(Bond)
      ,mCleanPrice(CleanPrice)
      ,mNonParRepayment(NonParRepayment)
      ,mGearing(Gearing)
      ,mIborIndex(IborIndex)
      ,mSpread(Spread)
      ,mFloatingLegDayCounter(FloatingLegDayCounter)
      ,mDealMaturity(DealMaturity)
      ,mPayBondCoupon(PayBondCoupon)
      {

      };

    //~AssetSwap2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AssetSwapBondLegAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    AssetSwapBondLegAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAfterDate(AfterDate)
      {

      };

    //~AssetSwapBondLegAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AssetSwapFloatingLegAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    AssetSwapFloatingLegAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAfterDate(AfterDate)
      {

      };

    //~AssetSwapFloatingLegAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AssetSwapFairSpreadWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AssetSwapFairSpreadWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AssetSwapFairSpreadWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AssetSwapFloatingLegBPSWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AssetSwapFloatingLegBPSWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AssetSwapFloatingLegBPSWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AssetSwapFairCleanPriceWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AssetSwapFairCleanPriceWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AssetSwapFairCleanPriceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AssetSwapFairNonParRepaymentWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    AssetSwapFairNonParRepaymentWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AssetSwapFairNonParRepaymentWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AssetSwapParSwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    AssetSwapParSwapWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AssetSwapParSwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AssetSwapPayBondCouponWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    AssetSwapPayBondCouponWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~AssetSwapPayBondCouponWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
