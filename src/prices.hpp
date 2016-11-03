/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef prices_h
#define prices_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class MidEquivalentWorker : public Nan::AsyncWorker {
  public:
    double mBid;
    double mAsk;
    double mLast;
    double mClose;

    double mReturnValue;

    string mError;

    MidEquivalentWorker(
      Nan::Callback *callback
      ,double Bid
      ,double Ask
      ,double Last
      ,double Close
    ):
      Nan::AsyncWorker(callback)
      ,mBid(Bid)
      ,mAsk(Ask)
      ,mLast(Last)
      ,mClose(Close)
      {

      };

    //~MidEquivalentWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class MidSafeWorker : public Nan::AsyncWorker {
  public:
    double mBid;
    double mAsk;

    double mReturnValue;

    string mError;

    MidSafeWorker(
      Nan::Callback *callback
      ,double Bid
      ,double Ask
    ):
      Nan::AsyncWorker(callback)
      ,mBid(Bid)
      ,mAsk(Ask)
      {

      };

    //~MidSafeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
