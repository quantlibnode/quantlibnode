/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef payoffs_h
#define payoffs_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class StrikedTypePayoffWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mPayoffID;
    string mOptionType;
    double mStrike;
    double mThirdParameter;

    string mReturnValue;

    string mError;

    StrikedTypePayoffWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string PayoffID
      ,string OptionType
      ,double Strike
      ,double ThirdParameter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mPayoffID(PayoffID)
      ,mOptionType(OptionType)
      ,mStrike(Strike)
      ,mThirdParameter(ThirdParameter)
      {

      };

    //~StrikedTypePayoffWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DoubleStickyRatchetPayoffWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mType1;
    double mType2;
    double mGearing1;
    double mGearing2;
    double mGearing3;
    double mSpread1;
    double mSpread2;
    double mSpread3;
    double mInitialValue1;
    double mInitialValue2;
    double mAccrualFactor;

    string mReturnValue;

    string mError;

    DoubleStickyRatchetPayoffWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Type1
      ,double Type2
      ,double Gearing1
      ,double Gearing2
      ,double Gearing3
      ,double Spread1
      ,double Spread2
      ,double Spread3
      ,double InitialValue1
      ,double InitialValue2
      ,double AccrualFactor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mType1(Type1)
      ,mType2(Type2)
      ,mGearing1(Gearing1)
      ,mGearing2(Gearing2)
      ,mGearing3(Gearing3)
      ,mSpread1(Spread1)
      ,mSpread2(Spread2)
      ,mSpread3(Spread3)
      ,mInitialValue1(InitialValue1)
      ,mInitialValue2(InitialValue2)
      ,mAccrualFactor(AccrualFactor)
      {

      };

    //~DoubleStickyRatchetPayoffWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RatchetPayoffWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mGearing1;
    double mGearing2;
    double mSpread1;
    double mSpread2;
    double mInitialValue;
    double mAccrualFactor;

    string mReturnValue;

    string mError;

    RatchetPayoffWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Gearing1
      ,double Gearing2
      ,double Spread1
      ,double Spread2
      ,double InitialValue
      ,double AccrualFactor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mGearing1(Gearing1)
      ,mGearing2(Gearing2)
      ,mSpread1(Spread1)
      ,mSpread2(Spread2)
      ,mInitialValue(InitialValue)
      ,mAccrualFactor(AccrualFactor)
      {

      };

    //~RatchetPayoffWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StickyPayoffWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mGearing1;
    double mGearing2;
    double mSpread1;
    double mSpread2;
    double mInitialValue;
    double mAccrualFactor;

    string mReturnValue;

    string mError;

    StickyPayoffWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Gearing1
      ,double Gearing2
      ,double Spread1
      ,double Spread2
      ,double InitialValue
      ,double AccrualFactor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mGearing1(Gearing1)
      ,mGearing2(Gearing2)
      ,mSpread1(Spread1)
      ,mSpread2(Spread2)
      ,mInitialValue(InitialValue)
      ,mAccrualFactor(AccrualFactor)
      {

      };

    //~StickyPayoffWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RatchetMaxPayoffWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mGearing1;
    double mGearing2;
    double mGearing3;
    double mSpread1;
    double mSpread2;
    double mSpread3;
    double mInitialValue1;
    double mInitialValue2;
    double mAccrualFactor;

    string mReturnValue;

    string mError;

    RatchetMaxPayoffWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Gearing1
      ,double Gearing2
      ,double Gearing3
      ,double Spread1
      ,double Spread2
      ,double Spread3
      ,double InitialValue1
      ,double InitialValue2
      ,double AccrualFactor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mGearing1(Gearing1)
      ,mGearing2(Gearing2)
      ,mGearing3(Gearing3)
      ,mSpread1(Spread1)
      ,mSpread2(Spread2)
      ,mSpread3(Spread3)
      ,mInitialValue1(InitialValue1)
      ,mInitialValue2(InitialValue2)
      ,mAccrualFactor(AccrualFactor)
      {

      };

    //~RatchetMaxPayoffWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RatchetMinPayoffWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mGearing1;
    double mGearing2;
    double mGearing3;
    double mSpread1;
    double mSpread2;
    double mSpread3;
    double mInitialValue1;
    double mInitialValue2;
    double mAccrualFactor;

    string mReturnValue;

    string mError;

    RatchetMinPayoffWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Gearing1
      ,double Gearing2
      ,double Gearing3
      ,double Spread1
      ,double Spread2
      ,double Spread3
      ,double InitialValue1
      ,double InitialValue2
      ,double AccrualFactor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mGearing1(Gearing1)
      ,mGearing2(Gearing2)
      ,mGearing3(Gearing3)
      ,mSpread1(Spread1)
      ,mSpread2(Spread2)
      ,mSpread3(Spread3)
      ,mInitialValue1(InitialValue1)
      ,mInitialValue2(InitialValue2)
      ,mAccrualFactor(AccrualFactor)
      {

      };

    //~RatchetMinPayoffWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StickyMaxPayoffWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mGearing1;
    double mGearing2;
    double mGearing3;
    double mSpread1;
    double mSpread2;
    double mSpread3;
    double mInitialValue1;
    double mInitialValue2;
    double mAccrualFactor;

    string mReturnValue;

    string mError;

    StickyMaxPayoffWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Gearing1
      ,double Gearing2
      ,double Gearing3
      ,double Spread1
      ,double Spread2
      ,double Spread3
      ,double InitialValue1
      ,double InitialValue2
      ,double AccrualFactor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mGearing1(Gearing1)
      ,mGearing2(Gearing2)
      ,mGearing3(Gearing3)
      ,mSpread1(Spread1)
      ,mSpread2(Spread2)
      ,mSpread3(Spread3)
      ,mInitialValue1(InitialValue1)
      ,mInitialValue2(InitialValue2)
      ,mAccrualFactor(AccrualFactor)
      {

      };

    //~StickyMaxPayoffWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class StickyMinPayoffWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mGearing1;
    double mGearing2;
    double mGearing3;
    double mSpread1;
    double mSpread2;
    double mSpread3;
    double mInitialValue1;
    double mInitialValue2;
    double mAccrualFactor;

    string mReturnValue;

    string mError;

    StickyMinPayoffWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Gearing1
      ,double Gearing2
      ,double Gearing3
      ,double Spread1
      ,double Spread2
      ,double Spread3
      ,double InitialValue1
      ,double InitialValue2
      ,double AccrualFactor
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mGearing1(Gearing1)
      ,mGearing2(Gearing2)
      ,mGearing3(Gearing3)
      ,mSpread1(Spread1)
      ,mSpread2(Spread2)
      ,mSpread3(Spread3)
      ,mInitialValue1(InitialValue1)
      ,mInitialValue2(InitialValue2)
      ,mAccrualFactor(AccrualFactor)
      {

      };

    //~StickyMinPayoffWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PayoffNameWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    PayoffNameWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PayoffNameWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PayoffDescriptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    PayoffDescriptionWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PayoffDescriptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PayoffValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mUnderlying;

    double mReturnValue;

    string mError;

    PayoffValueWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Underlying
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mUnderlying(Underlying)
      {

      };

    //~PayoffValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PayoffOptionTypeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    PayoffOptionTypeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PayoffOptionTypeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PayoffStrikeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    PayoffStrikeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PayoffStrikeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PayoffThirdParameterWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    PayoffThirdParameterWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PayoffThirdParameterWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
