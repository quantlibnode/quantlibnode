/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef exercise_h
#define exercise_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class AmericanExerciseWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mEarliestDate;
    ObjectHandler::property_t mLatestDate;
    bool mPayoffAtExpiry;

    string mReturnValue;

    string mError;

    AmericanExerciseWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t EarliestDate
      ,ObjectHandler::property_t LatestDate
      ,bool PayoffAtExpiry
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEarliestDate(EarliestDate)
      ,mLatestDate(LatestDate)
      ,mPayoffAtExpiry(PayoffAtExpiry)
      {

      };

    //~AmericanExerciseWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class EuropeanExerciseWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mExpiryDate;

    string mReturnValue;

    string mError;

    EuropeanExerciseWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t ExpiryDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mExpiryDate(ExpiryDate)
      {

      };

    //~EuropeanExerciseWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class BermudanExerciseWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mDates;
    bool mPayoffAtExpiry;

    string mReturnValue;

    string mError;

    BermudanExerciseWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> Dates
      ,bool PayoffAtExpiry
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDates(Dates)
      ,mPayoffAtExpiry(PayoffAtExpiry)
      {

      };

    //~BermudanExerciseWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ExerciseDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    ExerciseDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ExerciseDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ExerciseLastDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    ExerciseLastDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ExerciseLastDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
