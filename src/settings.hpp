/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef settings_h
#define settings_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class SettingsEvaluationDateWorker : public Nan::AsyncWorker {
  public:

    long mReturnValue;

    string mError;

    SettingsEvaluationDateWorker(
      Nan::Callback *callback
    ):
      Nan::AsyncWorker(callback)
      {

      };

    //~SettingsEvaluationDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SettingsSetEvaluationDateWorker : public Nan::AsyncWorker {
  public:
    ObjectHandler::property_t mEvalDate;

    string mError;

    SettingsSetEvaluationDateWorker(
      Nan::Callback *callback
      ,ObjectHandler::property_t EvalDate
    ):
      Nan::AsyncWorker(callback)
      ,mEvalDate(EvalDate)
      {

      };

    //~SettingsSetEvaluationDateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SettingsEnforceTodaysHistoricFixingsWorker : public Nan::AsyncWorker {
  public:

    bool mReturnValue;

    string mError;

    SettingsEnforceTodaysHistoricFixingsWorker(
      Nan::Callback *callback
    ):
      Nan::AsyncWorker(callback)
      {

      };

    //~SettingsEnforceTodaysHistoricFixingsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SettingsSetEnforceTodaysHistoricFixingsWorker : public Nan::AsyncWorker {
  public:
    bool mBoolean;

    string mError;

    SettingsSetEnforceTodaysHistoricFixingsWorker(
      Nan::Callback *callback
      ,bool Boolean
    ):
      Nan::AsyncWorker(callback)
      ,mBoolean(Boolean)
      {

      };

    //~SettingsSetEnforceTodaysHistoricFixingsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
