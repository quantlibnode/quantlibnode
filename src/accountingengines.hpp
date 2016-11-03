/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef accountingengines_h
#define accountingengines_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class AccountingEngineWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mMarketModelEvolver;
    string mProduct;
    double mInitialNumeraireValue;

    string mReturnValue;

    string mError;

    AccountingEngineWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string MarketModelEvolver
      ,string Product
      ,double InitialNumeraireValue
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mMarketModelEvolver(MarketModelEvolver)
      ,mProduct(Product)
      ,mInitialNumeraireValue(InitialNumeraireValue)
      {

      };

    //~AccountingEngineWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AccountingEngineMultiplePathValuesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mSequenceStats;
    long mPaths;

    string mError;

    AccountingEngineMultiplePathValuesWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string SequenceStats
      ,long Paths
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSequenceStats(SequenceStats)
      ,mPaths(Paths)
      {

      };

    //~AccountingEngineMultiplePathValuesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
