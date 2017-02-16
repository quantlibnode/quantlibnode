/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef defaultbasket_h
#define defaultbasket_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class CreditBasketWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<string> mIssuerNames;
    std::vector<string> mIssuers;
    std::vector<double> mNotionals;
    ObjectHandler::property_t mReferenceDate;
    double mAttachmentRatio;
    double mDettachmentRatio;
    bool mAmortizing;

    string mReturnValue;

    string mError;

    CreditBasketWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<string> IssuerNames
      ,std::vector<string> Issuers
      ,std::vector<double> Notionals
      ,ObjectHandler::property_t ReferenceDate
      ,double AttachmentRatio
      ,double DettachmentRatio
      ,bool Amortizing
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIssuerNames(IssuerNames)
      ,mIssuers(Issuers)
      ,mNotionals(Notionals)
      ,mReferenceDate(ReferenceDate)
      ,mAttachmentRatio(AttachmentRatio)
      ,mDettachmentRatio(DettachmentRatio)
      ,mAmortizing(Amortizing)
      {

      };

    //~CreditBasketWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketSetLossModelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mDefaultLossModel;

    string mError;

    CreditBasketSetLossModelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string DefaultLossModel
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDefaultLossModel(DefaultLossModel)
      {

      };

    //~CreditBasketSetLossModelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketSizeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    CreditBasketSizeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CreditBasketSizeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketLiveNotionalWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CreditBasketLiveNotionalWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CreditBasketLiveNotionalWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketLossWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CreditBasketLossWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CreditBasketLossWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CrediBasketAttachLiveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CrediBasketAttachLiveWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CrediBasketAttachLiveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CrediBasketDetachLiveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CrediBasketDetachLiveWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CrediBasketDetachLiveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ExpectedTrancheLossWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mDateForLoss;

    double mReturnValue;

    string mError;

    ExpectedTrancheLossWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t DateForLoss
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDateForLoss(DateForLoss)
      {

      };

    //~ExpectedTrancheLossWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketPercentileWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mDateForLoss;
    double mPercentileValue;

    double mReturnValue;

    string mError;

    CreditBasketPercentileWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t DateForLoss
      ,double PercentileValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDateForLoss(DateForLoss)
      ,mPercentileValue(PercentileValue)
      {

      };

    //~CreditBasketPercentileWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketESFWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mDateForLoss;
    double mPercentileValue;

    double mReturnValue;

    string mError;

    CreditBasketESFWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t DateForLoss
      ,double PercentileValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDateForLoss(DateForLoss)
      ,mPercentileValue(PercentileValue)
      {

      };

    //~CreditBasketESFWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketNthEventPWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mEventOrder;
    ObjectHandler::property_t mDateForLoss;

    std::vector<double> mReturnValue;

    string mError;

    CreditBasketNthEventPWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long EventOrder
      ,ObjectHandler::property_t DateForLoss
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEventOrder(EventOrder)
      ,mDateForLoss(DateForLoss)
      {

      };

    //~CreditBasketNthEventPWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketProbLossWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mDateForLoss;
    double mLossFractionValue;

    double mReturnValue;

    string mError;

    CreditBasketProbLossWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t DateForLoss
      ,double LossFractionValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDateForLoss(DateForLoss)
      ,mLossFractionValue(LossFractionValue)
      {

      };

    //~CreditBasketProbLossWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketSplitLossWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mDateForLoss;
    double mLossValue;

    std::vector<double> mReturnValue;

    string mError;

    CreditBasketSplitLossWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t DateForLoss
      ,double LossValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDateForLoss(DateForLoss)
      ,mLossValue(LossValue)
      {

      };

    //~CreditBasketSplitLossWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CreditBasketDefaulCorrelWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mDateCorrel;
    long mIndexIssuer1;
    long mIndexIssuer2;

    double mReturnValue;

    string mError;

    CreditBasketDefaulCorrelWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t DateCorrel
      ,long IndexIssuer1
      ,long IndexIssuer2
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDateCorrel(DateCorrel)
      ,mIndexIssuer1(IndexIssuer1)
      ,mIndexIssuer2(IndexIssuer2)
      {

      };

    //~CreditBasketDefaulCorrelWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
