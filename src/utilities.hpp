// This is a generated file, modify: generate/templates/class_header.h

#ifndef utilities_h
#define utilities_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class xlVersionWorker : public Nan::AsyncWorker {
  public:
    bool mVerbose;

    string mReturnValue;

    string mError;

    xlVersionWorker(
      Nan::Callback *callback
      ,bool Verbose
    ):
      Nan::AsyncWorker(callback)
      ,mVerbose(Verbose)
      {

      };

    //~xlVersionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class AddinVersionWorker : public Nan::AsyncWorker {
  public:

    string mReturnValue;

    string mError;

    AddinVersionWorker(
      Nan::Callback *callback
    ):
      Nan::AsyncWorker(callback)
      {

      };

    //~AddinVersionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VersionWorker : public Nan::AsyncWorker {
  public:

    string mReturnValue;

    string mError;

    VersionWorker(
      Nan::Callback *callback
    ):
      Nan::AsyncWorker(callback)
      {

      };

    //~VersionWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FunctionCountWorker : public Nan::AsyncWorker {
  public:

    long mReturnValue;

    string mError;

    FunctionCountWorker(
      Nan::Callback *callback
    ):
      Nan::AsyncWorker(callback)
      {

      };

    //~FunctionCountWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
