/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef calendar_h
#define calendar_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class CalendarHolidayListWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    ObjectHandler::property_t mFromDate;
    ObjectHandler::property_t mToDate;
    bool mIncludeWeekEnds;

    std::vector<long> mReturnValue;

    string mError;

    CalendarHolidayListWorker(
      Nan::Callback *callback
      ,string Calendar
      ,ObjectHandler::property_t FromDate
      ,ObjectHandler::property_t ToDate
      ,bool IncludeWeekEnds
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mFromDate(FromDate)
      ,mToDate(ToDate)
      ,mIncludeWeekEnds(IncludeWeekEnds)
      {

      };

    //~CalendarHolidayListWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarNameWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;

    string mReturnValue;

    string mError;

    CalendarNameWorker(
      Nan::Callback *callback
      ,string Calendar
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      {

      };

    //~CalendarNameWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarIsBusinessDayWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    std::vector<ObjectHandler::property_t> mDate;

    std::vector<bool> mReturnValue;

    string mError;

    CalendarIsBusinessDayWorker(
      Nan::Callback *callback
      ,string Calendar
      ,std::vector<ObjectHandler::property_t> Date
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mDate(Date)
      {

      };

    //~CalendarIsBusinessDayWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarIsHolidayWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    std::vector<ObjectHandler::property_t> mDate;

    std::vector<bool> mReturnValue;

    string mError;

    CalendarIsHolidayWorker(
      Nan::Callback *callback
      ,string Calendar
      ,std::vector<ObjectHandler::property_t> Date
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mDate(Date)
      {

      };

    //~CalendarIsHolidayWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarIsEndOfMonthWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    std::vector<ObjectHandler::property_t> mDate;

    std::vector<bool> mReturnValue;

    string mError;

    CalendarIsEndOfMonthWorker(
      Nan::Callback *callback
      ,string Calendar
      ,std::vector<ObjectHandler::property_t> Date
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mDate(Date)
      {

      };

    //~CalendarIsEndOfMonthWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarEndOfMonthWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    std::vector<ObjectHandler::property_t> mDate;

    std::vector<long> mReturnValue;

    string mError;

    CalendarEndOfMonthWorker(
      Nan::Callback *callback
      ,string Calendar
      ,std::vector<ObjectHandler::property_t> Date
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mDate(Date)
      {

      };

    //~CalendarEndOfMonthWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarAddHolidayWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    ObjectHandler::property_t mDate;

    string mError;

    CalendarAddHolidayWorker(
      Nan::Callback *callback
      ,string Calendar
      ,ObjectHandler::property_t Date
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mDate(Date)
      {

      };

    //~CalendarAddHolidayWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarRemoveHolidayWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    ObjectHandler::property_t mDate;

    string mError;

    CalendarRemoveHolidayWorker(
      Nan::Callback *callback
      ,string Calendar
      ,ObjectHandler::property_t Date
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mDate(Date)
      {

      };

    //~CalendarRemoveHolidayWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarAdjustWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    std::vector<ObjectHandler::property_t> mDate;
    string mBusinessDayConvention;

    std::vector<long> mReturnValue;

    string mError;

    CalendarAdjustWorker(
      Nan::Callback *callback
      ,string Calendar
      ,std::vector<ObjectHandler::property_t> Date
      ,string BusinessDayConvention
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mDate(Date)
      ,mBusinessDayConvention(BusinessDayConvention)
      {

      };

    //~CalendarAdjustWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarAdvanceWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    ObjectHandler::property_t mStartDate;
    std::vector<ObjectHandler::property_t> mPeriod;
    string mBusinessDayConvention;
    bool mEndOfMonth;

    std::vector<long> mReturnValue;

    string mError;

    CalendarAdvanceWorker(
      Nan::Callback *callback
      ,string Calendar
      ,ObjectHandler::property_t StartDate
      ,std::vector<ObjectHandler::property_t> Period
      ,string BusinessDayConvention
      ,bool EndOfMonth
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mStartDate(StartDate)
      ,mPeriod(Period)
      ,mBusinessDayConvention(BusinessDayConvention)
      ,mEndOfMonth(EndOfMonth)
      {

      };

    //~CalendarAdvanceWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CalendarBusinessDaysBetweenWorker : public Nan::AsyncWorker {
  public:
    string mCalendar;
    std::vector<ObjectHandler::property_t> mFirstDate;
    ObjectHandler::property_t mLastDate;
    bool mIncludeFirst;
    bool mIncludeLast;

    std::vector<long> mReturnValue;

    string mError;

    CalendarBusinessDaysBetweenWorker(
      Nan::Callback *callback
      ,string Calendar
      ,std::vector<ObjectHandler::property_t> FirstDate
      ,ObjectHandler::property_t LastDate
      ,bool IncludeFirst
      ,bool IncludeLast
    ):
      Nan::AsyncWorker(callback)
      ,mCalendar(Calendar)
      ,mFirstDate(FirstDate)
      ,mLastDate(LastDate)
      ,mIncludeFirst(IncludeFirst)
      ,mIncludeLast(IncludeLast)
      {

      };

    //~CalendarBusinessDaysBetweenWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
