// This is a generated file, modify: generate/templates/class_header.h

#ifndef daycounter_h
#define daycounter_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class DayCounterNameWorker : public Nan::AsyncWorker {
  public:
    string mDayCounter;

    string mReturnValue;

    string mError;

    DayCounterNameWorker(
      Nan::Callback *callback
      ,string DayCounter
    ):
      Nan::AsyncWorker(callback)
      ,mDayCounter(DayCounter)
      {

      };

    //~DayCounterNameWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DayCounterDayCountWorker : public Nan::AsyncWorker {
  public:
    string mDayCounter;
    ObjectHandler::property_t mStartDate;
    std::vector<ObjectHandler::property_t> mEndDate;

    std::vector<long> mReturnValue;

    string mError;

    DayCounterDayCountWorker(
      Nan::Callback *callback
      ,string DayCounter
      ,ObjectHandler::property_t StartDate
      ,std::vector<ObjectHandler::property_t> EndDate
    ):
      Nan::AsyncWorker(callback)
      ,mDayCounter(DayCounter)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      {

      };

    //~DayCounterDayCountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DayCounterYearFractionWorker : public Nan::AsyncWorker {
  public:
    string mDayCounter;
    ObjectHandler::property_t mStartDate;
    std::vector<ObjectHandler::property_t> mEndDate;
    ObjectHandler::property_t mRefPeriodStart;
    ObjectHandler::property_t mRefPeriodEnd;

    std::vector<double> mReturnValue;

    string mError;

    DayCounterYearFractionWorker(
      Nan::Callback *callback
      ,string DayCounter
      ,ObjectHandler::property_t StartDate
      ,std::vector<ObjectHandler::property_t> EndDate
      ,ObjectHandler::property_t RefPeriodStart
      ,ObjectHandler::property_t RefPeriodEnd
    ):
      Nan::AsyncWorker(callback)
      ,mDayCounter(DayCounter)
      ,mStartDate(StartDate)
      ,mEndDate(EndDate)
      ,mRefPeriodStart(RefPeriodStart)
      ,mRefPeriodEnd(RefPeriodEnd)
      {

      };

    //~DayCounterYearFractionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
