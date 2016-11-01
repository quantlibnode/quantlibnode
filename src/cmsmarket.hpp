// This is a generated file, modify: generate/templates/class_header.h

#ifndef cmsmarket_h
#define cmsmarket_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class CmsMarketWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mSwapLengths;
    std::vector<string> mSwapIndexes;
    string mIborIndex;
    std::vector< std::vector<ObjectHandler::property_t> > mBidAskSpreads;
    std::vector<string> mCmsCouponPricers;
    ObjectHandler::property_t mYieldCurve;

    string mReturnValue;

    string mError;

    CmsMarketWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> SwapLengths
      ,std::vector<string> SwapIndexes
      ,string IborIndex
      ,std::vector< std::vector<ObjectHandler::property_t> > BidAskSpreads
      ,std::vector<string> CmsCouponPricers
      ,ObjectHandler::property_t YieldCurve
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwapLengths(SwapLengths)
      ,mSwapIndexes(SwapIndexes)
      ,mIborIndex(IborIndex)
      ,mBidAskSpreads(BidAskSpreads)
      ,mCmsCouponPricers(CmsCouponPricers)
      ,mYieldCurve(YieldCurve)
      {

      };

    //~CmsMarketWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BrowseCmsMarketWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    BrowseCmsMarketWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~BrowseCmsMarketWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
