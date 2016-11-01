// This is a generated file, modify: generate/templates/class_header.h

#ifndef piecewiseyieldcurve_h
#define piecewiseyieldcurve_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class PiecewiseYieldCurveWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mNDays;
    string mCalendar;
    std::vector<string> mRateHelpers;
    string mDayCounter;
    std::vector<ObjectHandler::property_t> mJumps;
    std::vector<ObjectHandler::property_t> mJumpDates;
    double mAccuracy;
    string mTraitsID;
    string mInterpolatorID;

    string mReturnValue;

    string mError;

    PiecewiseYieldCurveWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t NDays
      ,string Calendar
      ,std::vector<string> RateHelpers
      ,string DayCounter
      ,std::vector<ObjectHandler::property_t> Jumps
      ,std::vector<ObjectHandler::property_t> JumpDates
      ,double Accuracy
      ,string TraitsID
      ,string InterpolatorID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNDays(NDays)
      ,mCalendar(Calendar)
      ,mRateHelpers(RateHelpers)
      ,mDayCounter(DayCounter)
      ,mJumps(Jumps)
      ,mJumpDates(JumpDates)
      ,mAccuracy(Accuracy)
      ,mTraitsID(TraitsID)
      ,mInterpolatorID(InterpolatorID)
      {

      };

    //~PiecewiseYieldCurveWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseYieldCurveTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    PiecewiseYieldCurveTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseYieldCurveTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseYieldCurveDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    PiecewiseYieldCurveDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseYieldCurveDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseYieldCurveDataWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    PiecewiseYieldCurveDataWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseYieldCurveDataWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseYieldCurveJumpTimesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    PiecewiseYieldCurveJumpTimesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseYieldCurveJumpTimesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PiecewiseYieldCurveJumpDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    PiecewiseYieldCurveJumpDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~PiecewiseYieldCurveJumpDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
