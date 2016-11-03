/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef alphaform_h
#define alphaform_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class AlphaFormInverseLinearWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;
    double mAlpha;

    string mReturnValue;

    string mError;

    AlphaFormInverseLinearWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
      ,double Alpha
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      ,mAlpha(Alpha)
      {

      };

    //~AlphaFormInverseLinearWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AlphaFormLinearHyperbolicWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<double> mRateTimes;
    double mAlpha;

    string mReturnValue;

    string mError;

    AlphaFormLinearHyperbolicWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<double> RateTimes
      ,double Alpha
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRateTimes(RateTimes)
      ,mAlpha(Alpha)
      {

      };

    //~AlphaFormLinearHyperbolicWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AlphaFormOperatorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mTime;

    double mReturnValue;

    string mError;

    AlphaFormOperatorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Time
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mTime(Time)
      {

      };

    //~AlphaFormOperatorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AlphaFormSetAlphaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    double mAlpha;

    string mError;

    AlphaFormSetAlphaWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,double Alpha
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mAlpha(Alpha)
      {

      };

    //~AlphaFormSetAlphaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
