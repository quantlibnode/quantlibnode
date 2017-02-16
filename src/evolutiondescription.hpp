/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef evolutiondescription_h
#define evolutiondescription_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class EvolutionDescriptionWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;
    std::vector<double> mEvolutionTimes;

    string mReturnValue;

    string mError;

    EvolutionDescriptionWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
      ,std::vector<double> EvolutionTimes
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      ,mEvolutionTimes(EvolutionTimes)
      {

      };

    //~EvolutionDescriptionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EvolutionDescriptionFromProductWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mProduct;

    string mReturnValue;

    string mError;

    EvolutionDescriptionFromProductWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Product
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mProduct(Product)
      {

      };

    //~EvolutionDescriptionFromProductWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EvolutionDescriptionRateTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    EvolutionDescriptionRateTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EvolutionDescriptionRateTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EvolutionDescriptionRateTausWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    EvolutionDescriptionRateTausWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EvolutionDescriptionRateTausWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EvolutionDescriptionEvolutionTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    EvolutionDescriptionEvolutionTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EvolutionDescriptionEvolutionTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EvolutionDescriptionFirstAliveRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    EvolutionDescriptionFirstAliveRateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EvolutionDescriptionFirstAliveRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EvolutionDescriptionNumberOfRatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    EvolutionDescriptionNumberOfRatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EvolutionDescriptionNumberOfRatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EvolutionDescriptionNumberOfStepsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    EvolutionDescriptionNumberOfStepsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~EvolutionDescriptionNumberOfStepsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TerminalMeasureWorker : public Nan::AsyncWorker {
  public:
    string mEvolutionDescription;

    std::vector<long> mReturnValue;

    string mError;

    TerminalMeasureWorker(
      Nan::Callback *callback
      ,string EvolutionDescription
    ):
      Nan::AsyncWorker(callback)
      ,mEvolutionDescription(EvolutionDescription)
      {

      };

    //~TerminalMeasureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MoneyMarketMeasureWorker : public Nan::AsyncWorker {
  public:
    string mEvolutionDescription;

    std::vector<long> mReturnValue;

    string mError;

    MoneyMarketMeasureWorker(
      Nan::Callback *callback
      ,string EvolutionDescription
    ):
      Nan::AsyncWorker(callback)
      ,mEvolutionDescription(EvolutionDescription)
      {

      };

    //~MoneyMarketMeasureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MoneyMarketPlusMeasureWorker : public Nan::AsyncWorker {
  public:
    string mEvolutionDescription;
    long mOffset;

    std::vector<long> mReturnValue;

    string mError;

    MoneyMarketPlusMeasureWorker(
      Nan::Callback *callback
      ,string EvolutionDescription
      ,long Offset
    ):
      Nan::AsyncWorker(callback)
      ,mEvolutionDescription(EvolutionDescription)
      ,mOffset(Offset)
      {

      };

    //~MoneyMarketPlusMeasureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IsInTerminalMeasureWorker : public Nan::AsyncWorker {
  public:
    string mEvolutionDescription;
    std::vector<long> mNumeraires;

    bool mReturnValue;

    string mError;

    IsInTerminalMeasureWorker(
      Nan::Callback *callback
      ,string EvolutionDescription
      ,std::vector<long> Numeraires
    ):
      Nan::AsyncWorker(callback)
      ,mEvolutionDescription(EvolutionDescription)
      ,mNumeraires(Numeraires)
      {

      };

    //~IsInTerminalMeasureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IsInMoneyMarketMeasureWorker : public Nan::AsyncWorker {
  public:
    string mEvolutionDescription;
    std::vector<long> mNumeraires;

    bool mReturnValue;

    string mError;

    IsInMoneyMarketMeasureWorker(
      Nan::Callback *callback
      ,string EvolutionDescription
      ,std::vector<long> Numeraires
    ):
      Nan::AsyncWorker(callback)
      ,mEvolutionDescription(EvolutionDescription)
      ,mNumeraires(Numeraires)
      {

      };

    //~IsInMoneyMarketMeasureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IsInMoneyMarketPlusMeasureWorker : public Nan::AsyncWorker {
  public:
    string mEvolutionDescription;
    std::vector<long> mNumeraires;
    long mOffset;

    bool mReturnValue;

    string mError;

    IsInMoneyMarketPlusMeasureWorker(
      Nan::Callback *callback
      ,string EvolutionDescription
      ,std::vector<long> Numeraires
      ,long Offset
    ):
      Nan::AsyncWorker(callback)
      ,mEvolutionDescription(EvolutionDescription)
      ,mNumeraires(Numeraires)
      ,mOffset(Offset)
      {

      };

    //~IsInMoneyMarketPlusMeasureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
