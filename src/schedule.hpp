/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef schedule_h
#define schedule_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class ScheduleWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mEffectiveDate;
    ObjectHandler::property_t mTerminationDate;
    string mTenor;
    string mCalendar;
    string mConvention;
    string mTermDateConv;
    string mGenRule;
    bool mEndOfMonth;
    ObjectHandler::property_t mFirstDate;
    ObjectHandler::property_t mNextToLastDate;

    string mReturnValue;

    string mError;

    ScheduleWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t EffectiveDate
      ,ObjectHandler::property_t TerminationDate
      ,string Tenor
      ,string Calendar
      ,string Convention
      ,string TermDateConv
      ,string GenRule
      ,bool EndOfMonth
      ,ObjectHandler::property_t FirstDate
      ,ObjectHandler::property_t NextToLastDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEffectiveDate(EffectiveDate)
      ,mTerminationDate(TerminationDate)
      ,mTenor(Tenor)
      ,mCalendar(Calendar)
      ,mConvention(Convention)
      ,mTermDateConv(TermDateConv)
      ,mGenRule(GenRule)
      ,mEndOfMonth(EndOfMonth)
      ,mFirstDate(FirstDate)
      ,mNextToLastDate(NextToLastDate)
      {

      };

    //~ScheduleWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleFromDateVectorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mEffectiveDate;

    string mReturnValue;

    string mError;

    ScheduleFromDateVectorWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> EffectiveDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEffectiveDate(EffectiveDate)
      {

      };

    //~ScheduleFromDateVectorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleTruncatedWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mOriginalSchedule;
    ObjectHandler::property_t mTruncationDate;

    string mReturnValue;

    string mError;

    ScheduleTruncatedWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string OriginalSchedule
      ,ObjectHandler::property_t TruncationDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mOriginalSchedule(OriginalSchedule)
      ,mTruncationDate(TruncationDate)
      {

      };

    //~ScheduleTruncatedWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleSizeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    ScheduleSizeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleSizeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SchedulePreviousDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mRefDate;

    long mReturnValue;

    string mError;

    SchedulePreviousDateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t RefDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRefDate(RefDate)
      {

      };

    //~SchedulePreviousDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleNextDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mRefDate;

    long mReturnValue;

    string mError;

    ScheduleNextDateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t RefDate
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mRefDate(RefDate)
      {

      };

    //~ScheduleNextDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    ScheduleDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleIsRegularWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    bool mReturnValue;

    string mError;

    ScheduleIsRegularWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~ScheduleIsRegularWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleEmptyWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    ScheduleEmptyWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleEmptyWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleCalendarWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    ScheduleCalendarWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleCalendarWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleStartDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    ScheduleStartDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleStartDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleEndDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    ScheduleEndDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleEndDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleTenorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    ScheduleTenorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleTenorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleBDCWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    ScheduleBDCWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleBDCWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleTerminationDateBDCWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    ScheduleTerminationDateBDCWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleTerminationDateBDCWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleRuleWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    ScheduleRuleWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleRuleWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ScheduleEndOfMonthWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    ScheduleEndOfMonthWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ScheduleEndOfMonthWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
