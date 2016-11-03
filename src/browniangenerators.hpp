/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef browniangenerators_h
#define browniangenerators_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class MTBrownianGeneratorFactoryWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mSeed;

    string mReturnValue;

    string mError;

    MTBrownianGeneratorFactoryWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Seed
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSeed(Seed)
      {

      };

    //~MTBrownianGeneratorFactoryWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
