// This is a generated file, modify: generate/templates/class_header.h

#ifndef swap_h
#define swap_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class SwapWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mLegIDs;
    std::vector<bool> mPayer;

    string mReturnValue;

    string mError;

    SwapWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> LegIDs
      ,std::vector<bool> Payer
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLegIDs(LegIDs)
      ,mPayer(Payer)
      {

      };

    //~SwapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MakeCmsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSwapTenor;
    string mSwapIndex;
    string mIborIndex;
    double mIborSpread;
    string mForwardStart;
    string mCmsCouponPricer;

    string mReturnValue;

    string mError;

    MakeCmsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string SwapTenor
      ,string SwapIndex
      ,string IborIndex
      ,double IborSpread
      ,string ForwardStart
      ,string CmsCouponPricer
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSwapTenor(SwapTenor)
      ,mSwapIndex(SwapIndex)
      ,mIborIndex(IborIndex)
      ,mIborSpread(IborSpread)
      ,mForwardStart(ForwardStart)
      ,mCmsCouponPricer(CmsCouponPricer)
      {

      };

    //~MakeCmsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapLegBPSWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mLegNumber;

    double mReturnValue;

    string mError;

    SwapLegBPSWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long LegNumber
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLegNumber(LegNumber)
      {

      };

    //~SwapLegBPSWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapLegNPVWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mLegNumber;

    double mReturnValue;

    string mError;

    SwapLegNPVWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long LegNumber
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLegNumber(LegNumber)
      {

      };

    //~SwapLegNPVWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapStartDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    SwapStartDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwapStartDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapMaturityDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    SwapMaturityDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SwapMaturityDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SwapLegAnalysisWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mLegNumber;
    ObjectHandler::property_t mAfterDate;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    SwapLegAnalysisWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long LegNumber
      ,ObjectHandler::property_t AfterDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mLegNumber(LegNumber)
      ,mAfterDate(AfterDate)
      {

      };

    //~SwapLegAnalysisWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
