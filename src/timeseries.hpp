// This is a generated file, modify: generate/templates/class_header.h

#ifndef timeseries_h
#define timeseries_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class TimeSeriesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mDates;
    std::vector<double> mValues;

    string mReturnValue;

    string mError;

    TimeSeriesWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> Dates
      ,std::vector<double> Values
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDates(Dates)
      ,mValues(Values)
      {

      };

    //~TimeSeriesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TimeSeriesFromIndexWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mIndex;

    string mReturnValue;

    string mError;

    TimeSeriesFromIndexWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~TimeSeriesFromIndexWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TimeSeriesFirstDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    TimeSeriesFirstDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TimeSeriesFirstDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TimeSeriesLastDateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    TimeSeriesLastDateWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TimeSeriesLastDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TimeSeriesSizeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    TimeSeriesSizeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TimeSeriesSizeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TimeSeriesEmptyWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    TimeSeriesEmptyWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TimeSeriesEmptyWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TimeSeriesDatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<long> mReturnValue;

    string mError;

    TimeSeriesDatesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TimeSeriesDatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TimeSeriesValuesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    TimeSeriesValuesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~TimeSeriesValuesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class TimeSeriesValueWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    std::vector<ObjectHandler::property_t> mDates;

    std::vector<double> mReturnValue;

    string mError;

    TimeSeriesValueWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,std::vector<ObjectHandler::property_t> Dates
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDates(Dates)
      {

      };

    //~TimeSeriesValueWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
