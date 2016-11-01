// This is a generated file, modify: generate/templates/class_header.h

#ifndef handles_h
#define handles_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class HandleCurrentLinkWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    HandleCurrentLinkWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HandleCurrentLinkWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HandleEmptyWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    bool mReturnValue;

    string mError;

    HandleEmptyWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~HandleEmptyWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RelinkableHandleLinkToWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mCurrentLink;

    string mError;

    RelinkableHandleLinkToWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string CurrentLink
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mCurrentLink(CurrentLink)
      {

      };

    //~RelinkableHandleLinkToWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
