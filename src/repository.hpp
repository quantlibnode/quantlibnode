// This is a generated file, modify: generate/templates/class_header.h

#ifndef repository_h
#define repository_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class ObjectPropertyNamesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<string> mReturnValue;

    string mError;

    ObjectPropertyNamesWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~ObjectPropertyNamesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DeleteObjectWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mError;

    DeleteObjectWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~DeleteObjectWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DeleteObjectsWorker : public Nan::AsyncWorker {
  public:
    std::vector<string> mObjectID;

    string mError;

    DeleteObjectsWorker(
      Nan::Callback *callback
      ,std::vector<string> ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~DeleteObjectsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class DeleteAllObjectsWorker : public Nan::AsyncWorker {
  public:
    bool mDeletePermanent;

    string mError;

    DeleteAllObjectsWorker(
      Nan::Callback *callback
      ,bool DeletePermanent
    ):
      Nan::AsyncWorker(callback)
      ,mDeletePermanent(DeletePermanent)
      {

      };

    //~DeleteAllObjectsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class ListObjectIDsWorker : public Nan::AsyncWorker {
  public:
    string mRegex;

    std::vector<string> mReturnValue;

    string mError;

    ListObjectIDsWorker(
      Nan::Callback *callback
      ,string Regex
    ):
      Nan::AsyncWorker(callback)
      ,mRegex(Regex)
      {

      };

    //~ListObjectIDsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
