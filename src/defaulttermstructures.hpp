/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef defaulttermstructures_h
#define defaulttermstructures_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class RelinkableHandleDefaultProbabilityTermStructureWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurrentLink;

    string mReturnValue;

    string mError;

    RelinkableHandleDefaultProbabilityTermStructureWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurrentLink
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurrentLink(CurrentLink)
      {

      };

    //~RelinkableHandleDefaultProbabilityTermStructureWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FlatHazardRateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mNDays;
    string mCalendar;
    ObjectHandler::property_t mRate;
    string mDayCounter;

    string mReturnValue;

    string mError;

    FlatHazardRateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long NDays
      ,string Calendar
      ,ObjectHandler::property_t Rate
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNDays(NDays)
      ,mCalendar(Calendar)
      ,mRate(Rate)
      ,mDayCounter(DayCounter)
      {

      };

    //~FlatHazardRateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DefaultTSDefaultProbabilityWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mDates;
    bool mAllowExtrapolation;

    std::vector<double> mReturnValue;

    string mError;

    DefaultTSDefaultProbabilityWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> Dates
      ,bool AllowExtrapolation
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDates(Dates)
      ,mAllowExtrapolation(AllowExtrapolation)
      {

      };

    //~DefaultTSDefaultProbabilityWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ProbabilityToHRWorker : public Nan::AsyncWorker {
  public:
    double mProbability;
    ObjectHandler::property_t mDate;
    string mDayCounter;

    double mReturnValue;

    string mError;

    ProbabilityToHRWorker(
      Nan::Callback *callback
      ,double Probability
      ,ObjectHandler::property_t Date
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mProbability(Probability)
      ,mDate(Date)
      ,mDayCounter(DayCounter)
      {

      };

    //~ProbabilityToHRWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
