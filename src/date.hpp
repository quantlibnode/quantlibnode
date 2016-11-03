/* 
  Copyright (C) 2016 Jerry Jin
*/

#ifndef date_h
#define date_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class PeriodFromFrequencyWorker : public Nan::AsyncWorker {
  public:
    string mFrequency;

    string mReturnValue;

    string mError;

    PeriodFromFrequencyWorker(
      Nan::Callback *callback
      ,string Frequency
    ):
      Nan::AsyncWorker(callback)
      ,mFrequency(Frequency)
      {

      };

    //~PeriodFromFrequencyWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FrequencyFromPeriodWorker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mPeriod;

    std::vector<string> mReturnValue;

    string mError;

    FrequencyFromPeriodWorker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> Period
    ):
      Nan::AsyncWorker(callback)
      ,mPeriod(Period)
      {

      };

    //~FrequencyFromPeriodWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PeriodLessThanWorker : public Nan::AsyncWorker {
  public:
    string mPeriod1;
    string mPeriod2;

    bool mReturnValue;

    string mError;

    PeriodLessThanWorker(
      Nan::Callback *callback
      ,string Period1
      ,string Period2
    ):
      Nan::AsyncWorker(callback)
      ,mPeriod1(Period1)
      ,mPeriod2(Period2)
      {

      };

    //~PeriodLessThanWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class PeriodEquivalentWorker : public Nan::AsyncWorker {
  public:
    string mPeriod;

    string mReturnValue;

    string mError;

    PeriodEquivalentWorker(
      Nan::Callback *callback
      ,string Period
    ):
      Nan::AsyncWorker(callback)
      ,mPeriod(Period)
      {

      };

    //~PeriodEquivalentWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DateMinDateWorker : public Nan::AsyncWorker {
  public:

    long mReturnValue;

    string mError;

    DateMinDateWorker(
      Nan::Callback *callback
    ):
      Nan::AsyncWorker(callback)
      {

      };

    //~DateMinDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DateMaxDateWorker : public Nan::AsyncWorker {
  public:

    long mReturnValue;

    string mError;

    DateMaxDateWorker(
      Nan::Callback *callback
    ):
      Nan::AsyncWorker(callback)
      {

      };

    //~DateMaxDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DateIsLeapWorker : public Nan::AsyncWorker {
  public:
    std::vector<long> mYear;

    std::vector<bool> mReturnValue;

    string mError;

    DateIsLeapWorker(
      Nan::Callback *callback
      ,std::vector<long> Year
    ):
      Nan::AsyncWorker(callback)
      ,mYear(Year)
      {

      };

    //~DateIsLeapWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DateEndOfMonthWorker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mDate;

    std::vector<long> mReturnValue;

    string mError;

    DateEndOfMonthWorker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> Date
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      {

      };

    //~DateEndOfMonthWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DateIsEndOfMonthWorker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mDate;

    std::vector<bool> mReturnValue;

    string mError;

    DateIsEndOfMonthWorker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> Date
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      {

      };

    //~DateIsEndOfMonthWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DateNextWeekdayWorker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mDate;
    string mWeekday;

    std::vector<long> mReturnValue;

    string mError;

    DateNextWeekdayWorker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> Date
      ,string Weekday
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      ,mWeekday(Weekday)
      {

      };

    //~DateNextWeekdayWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DateNthWeekdayWorker : public Nan::AsyncWorker {
  public:
    long mNth;
    string mWeekday;
    string mMonth;
    long mYear;

    long mReturnValue;

    string mError;

    DateNthWeekdayWorker(
      Nan::Callback *callback
      ,long Nth
      ,string Weekday
      ,string Month
      ,long Year
    ):
      Nan::AsyncWorker(callback)
      ,mNth(Nth)
      ,mWeekday(Weekday)
      ,mMonth(Month)
      ,mYear(Year)
      {

      };

    //~DateNthWeekdayWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IMMIsIMMdateWorker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mDate;
    bool mMainCycle;

    std::vector<bool> mReturnValue;

    string mError;

    IMMIsIMMdateWorker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> Date
      ,bool MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      ,mMainCycle(MainCycle)
      {

      };

    //~IMMIsIMMdateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IMMIsIMMcodeWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mCode;
    bool mMainCycle;

    std::vector<bool> mReturnValue;

    string mError;

    IMMIsIMMcodeWorker(
      Nan::Callback *callback
      ,std::vector<string> Code
      ,bool MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mCode(Code)
      ,mMainCycle(MainCycle)
      {

      };

    //~IMMIsIMMcodeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IMMcodeWorker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mIMMdate;

    std::vector<string> mReturnValue;

    string mError;

    IMMcodeWorker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> IMMdate
    ):
      Nan::AsyncWorker(callback)
      ,mIMMdate(IMMdate)
      {

      };

    //~IMMcodeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IMMNextCodeWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mRefDate;
    bool mMainCycle;

    string mReturnValue;

    string mError;

    IMMNextCodeWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t RefDate
      ,bool MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mRefDate(RefDate)
      ,mMainCycle(MainCycle)
      {

      };

    //~IMMNextCodeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IMMNextCodesWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mRefDate;
    std::vector<bool> mMainCycle;

    std::vector<string> mReturnValue;

    string mError;

    IMMNextCodesWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t RefDate
      ,std::vector<bool> MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mRefDate(RefDate)
      ,mMainCycle(MainCycle)
      {

      };

    //~IMMNextCodesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IMMdateWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mIMMcode;
    ObjectHandler::property_t mRefDate;

    std::vector<long> mReturnValue;

    string mError;

    IMMdateWorker(
      Nan::Callback *callback
      ,std::vector<string> IMMcode
      ,ObjectHandler::property_t RefDate
    ):
      Nan::AsyncWorker(callback)
      ,mIMMcode(IMMcode)
      ,mRefDate(RefDate)
      {

      };

    //~IMMdateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IMMNextDateWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mRefDate;
    bool mMainCycle;

    long mReturnValue;

    string mError;

    IMMNextDateWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t RefDate
      ,bool MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mRefDate(RefDate)
      ,mMainCycle(MainCycle)
      {

      };

    //~IMMNextDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class IMMNextDatesWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mRefDate;
    std::vector<bool> mMainCycle;

    std::vector<long> mReturnValue;

    string mError;

    IMMNextDatesWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t RefDate
      ,std::vector<bool> MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mRefDate(RefDate)
      ,mMainCycle(MainCycle)
      {

      };

    //~IMMNextDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ASXIsASXdateWorker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mDate;
    bool mMainCycle;

    std::vector<bool> mReturnValue;

    string mError;

    ASXIsASXdateWorker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> Date
      ,bool MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      ,mMainCycle(MainCycle)
      {

      };

    //~ASXIsASXdateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ASXIsASXcodeWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mCode;
    bool mMainCycle;

    std::vector<bool> mReturnValue;

    string mError;

    ASXIsASXcodeWorker(
      Nan::Callback *callback
      ,std::vector<string> Code
      ,bool MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mCode(Code)
      ,mMainCycle(MainCycle)
      {

      };

    //~ASXIsASXcodeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ASXcodeWorker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mASXdate;

    std::vector<string> mReturnValue;

    string mError;

    ASXcodeWorker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> ASXdate
    ):
      Nan::AsyncWorker(callback)
      ,mASXdate(ASXdate)
      {

      };

    //~ASXcodeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ASXNextCodeWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mRefDate;
    bool mMainCycle;

    string mReturnValue;

    string mError;

    ASXNextCodeWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t RefDate
      ,bool MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mRefDate(RefDate)
      ,mMainCycle(MainCycle)
      {

      };

    //~ASXNextCodeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ASXNextCodesWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mRefDate;
    std::vector<bool> mMainCycle;

    std::vector<string> mReturnValue;

    string mError;

    ASXNextCodesWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t RefDate
      ,std::vector<bool> MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mRefDate(RefDate)
      ,mMainCycle(MainCycle)
      {

      };

    //~ASXNextCodesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ASXdateWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mASXcode;
    ObjectHandler::property_t mRefDate;

    std::vector<long> mReturnValue;

    string mError;

    ASXdateWorker(
      Nan::Callback *callback
      ,std::vector<string> ASXcode
      ,ObjectHandler::property_t RefDate
    ):
      Nan::AsyncWorker(callback)
      ,mASXcode(ASXcode)
      ,mRefDate(RefDate)
      {

      };

    //~ASXdateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ASXNextDateWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mRefDate;
    bool mMainCycle;

    long mReturnValue;

    string mError;

    ASXNextDateWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t RefDate
      ,bool MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mRefDate(RefDate)
      ,mMainCycle(MainCycle)
      {

      };

    //~ASXNextDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ASXNextDatesWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mRefDate;
    std::vector<bool> mMainCycle;

    std::vector<long> mReturnValue;

    string mError;

    ASXNextDatesWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t RefDate
      ,std::vector<bool> MainCycle
    ):
      Nan::AsyncWorker(callback)
      ,mRefDate(RefDate)
      ,mMainCycle(MainCycle)
      {

      };

    //~ASXNextDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBKnownDatesWorker : public Nan::AsyncWorker {
  public:

    std::vector<long> mReturnValue;

    string mError;

    ECBKnownDatesWorker(
      Nan::Callback *callback
    ):
      Nan::AsyncWorker(callback)
      {

      };

    //~ECBKnownDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBAddDateWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mDate;

    string mError;

    ECBAddDateWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t Date
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      {

      };

    //~ECBAddDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBRemoveDateWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mDate;

    string mError;

    ECBRemoveDateWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t Date
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      {

      };

    //~ECBRemoveDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBdate2Worker : public Nan::AsyncWorker {
  public:
    string mMonth;
    long mYear;

    long mReturnValue;

    string mError;

    ECBdate2Worker(
      Nan::Callback *callback
      ,string Month
      ,long Year
    ):
      Nan::AsyncWorker(callback)
      ,mMonth(Month)
      ,mYear(Year)
      {

      };

    //~ECBdate2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBdateWorker : public Nan::AsyncWorker {
  public:
    string mECBcode;
    ObjectHandler::property_t mRefDate;

    long mReturnValue;

    string mError;

    ECBdateWorker(
      Nan::Callback *callback
      ,string ECBcode
      ,ObjectHandler::property_t RefDate
    ):
      Nan::AsyncWorker(callback)
      ,mECBcode(ECBcode)
      ,mRefDate(RefDate)
      {

      };

    //~ECBdateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBcodeWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mECBdate;

    string mReturnValue;

    string mError;

    ECBcodeWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t ECBdate
    ):
      Nan::AsyncWorker(callback)
      ,mECBdate(ECBdate)
      {

      };

    //~ECBcodeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBNextDateWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mDate;

    long mReturnValue;

    string mError;

    ECBNextDateWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t Date
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      {

      };

    //~ECBNextDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBNextDate2Worker : public Nan::AsyncWorker {
  public:
    string mCode;

    long mReturnValue;

    string mError;

    ECBNextDate2Worker(
      Nan::Callback *callback
      ,string Code
    ):
      Nan::AsyncWorker(callback)
      ,mCode(Code)
      {

      };

    //~ECBNextDate2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBNextDatesWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mDate;

    std::vector<long> mReturnValue;

    string mError;

    ECBNextDatesWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t Date
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      {

      };

    //~ECBNextDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBIsECBdateWorker : public Nan::AsyncWorker {
  public:
    std::vector<ObjectHandler::property_t> mDate;

    std::vector<bool> mReturnValue;

    string mError;

    ECBIsECBdateWorker(
      Nan::Callback *callback
      ,std::vector<ObjectHandler::property_t> Date
    ):
      Nan::AsyncWorker(callback)
      ,mDate(Date)
      {

      };

    //~ECBIsECBdateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBIsECBcodeWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mCode;

    std::vector<bool> mReturnValue;

    string mError;

    ECBIsECBcodeWorker(
      Nan::Callback *callback
      ,std::vector<string> Code
    ):
      Nan::AsyncWorker(callback)
      ,mCode(Code)
      {

      };

    //~ECBIsECBcodeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBNextCodeWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mRefDate;

    string mReturnValue;

    string mError;

    ECBNextCodeWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t RefDate
    ):
      Nan::AsyncWorker(callback)
      ,mRefDate(RefDate)
      {

      };

    //~ECBNextCodeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ECBNextCode2Worker : public Nan::AsyncWorker {
  public:
    string mCode;

    string mReturnValue;

    string mError;

    ECBNextCode2Worker(
      Nan::Callback *callback
      ,string Code
    ):
      Nan::AsyncWorker(callback)
      ,mCode(Code)
      {

      };

    //~ECBNextCode2Worker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
