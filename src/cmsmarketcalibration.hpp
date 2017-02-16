/* 
  Copyright (C) 2016 -2017 Jerry Jin
*/

#ifndef cmsmarketcalibration_h
#define cmsmarketcalibration_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class CmsMarketCalibrationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mVolCube;
    string mCmsMarket;
    std::vector< std::vector<double> > mWeights;
    string mCalibrationType;

    string mReturnValue;

    string mError;

    CmsMarketCalibrationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t VolCube
      ,string CmsMarket
      ,std::vector< std::vector<double> > Weights
      ,string CalibrationType
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mVolCube(VolCube)
      ,mCmsMarket(CmsMarket)
      ,mWeights(Weights)
      ,mCalibrationType(CalibrationType)
      {

      };

    //~CmsMarketCalibrationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsMarketCalibrationComputeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mEndCriteria;
    string mOptimizationMethod;
    std::vector<double> mGuess;
    bool mIsMeanRevFixed;

    std::vector<double> mReturnValue;

    string mError;

    CmsMarketCalibrationComputeWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string EndCriteria
      ,string OptimizationMethod
      ,std::vector<double> Guess
      ,bool IsMeanRevFixed
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEndCriteria(EndCriteria)
      ,mOptimizationMethod(OptimizationMethod)
      ,mGuess(Guess)
      ,mIsMeanRevFixed(IsMeanRevFixed)
      {

      };

    //~CmsMarketCalibrationComputeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsMarketCalibrationErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CmsMarketCalibrationErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CmsMarketCalibrationErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsMarketCalibrationEndCriteriaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    string mReturnValue;

    string mError;

    CmsMarketCalibrationEndCriteriaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CmsMarketCalibrationEndCriteriaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsMarketCalibrationElapsedWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CmsMarketCalibrationElapsedWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CmsMarketCalibrationElapsedWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsMarketCalibrationSparseSabrParametersWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    CmsMarketCalibrationSparseSabrParametersWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CmsMarketCalibrationSparseSabrParametersWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CmsMarketCalibrationDenseSabrParametersWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    CmsMarketCalibrationDenseSabrParametersWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CmsMarketCalibrationDenseSabrParametersWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class SimultaneousCalibrationBrowseCmsMarketWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector< std::vector<string> > mReturnValue;

    string mError;

    SimultaneousCalibrationBrowseCmsMarketWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~SimultaneousCalibrationBrowseCmsMarketWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
