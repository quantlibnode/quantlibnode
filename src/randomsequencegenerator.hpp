// This is a generated file, modify: generate/templates/class_header.h

#ifndef randomsequencegenerator_h
#define randomsequencegenerator_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class MersenneTwisterRsgWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mDimension;
    long mSeed;

    string mReturnValue;

    string mError;

    MersenneTwisterRsgWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Dimension
      ,long Seed
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDimension(Dimension)
      ,mSeed(Seed)
      {

      };

    //~MersenneTwisterRsgWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class FaureRsgWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mDimension;

    string mReturnValue;

    string mError;

    FaureRsgWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Dimension
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDimension(Dimension)
      {

      };

    //~FaureRsgWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class HaltonRsgWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mDimension;
    long mSeed;

    string mReturnValue;

    string mError;

    HaltonRsgWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Dimension
      ,long Seed
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDimension(Dimension)
      ,mSeed(Seed)
      {

      };

    //~HaltonRsgWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SobolRsgWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mDimension;
    long mSeed;

    string mReturnValue;

    string mError;

    SobolRsgWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Dimension
      ,long Seed
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mDimension(Dimension)
      ,mSeed(Seed)
      {

      };

    //~SobolRsgWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class VariatesWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mSamples;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    VariatesWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Samples
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mSamples(Samples)
      {

      };

    //~VariatesWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RandWorker : public Nan::AsyncWorker {
  public:

    double mReturnValue;

    string mError;

    RandWorker(
      Nan::Callback *callback
    ):
      Nan::AsyncWorker(callback)
      {

      };

    //~RandWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class RandomizeWorker : public Nan::AsyncWorker {
  public:
    long mSeed;

    string mError;

    RandomizeWorker(
      Nan::Callback *callback
      ,long Seed
    ):
      Nan::AsyncWorker(callback)
      ,mSeed(Seed)
      {

      };

    //~RandomizeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
