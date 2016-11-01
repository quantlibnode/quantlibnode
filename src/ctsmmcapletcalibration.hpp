// This is a generated file, modify: generate/templates/class_header.h

#ifndef ctsmmcapletcalibration_h
#define ctsmmcapletcalibration_h
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "../quantlibnode.hpp"

#include <oh/objecthandler.hpp>

using namespace node;
using namespace v8;
using namespace std;


class CTSMMCapletOriginalCalibrationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mEvolution;
    string mCorrelations;
    std::vector<string> mSwapPiecewiseConstantVariances;
    std::vector<double> mCapletVols;
    string mCurveState;
    double mDisplacement;
    std::vector<double> mAlphas;
    bool mLowestRoot;
    bool mUseFullApprox;

    string mReturnValue;

    string mError;

    CTSMMCapletOriginalCalibrationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Evolution
      ,string Correlations
      ,std::vector<string> SwapPiecewiseConstantVariances
      ,std::vector<double> CapletVols
      ,string CurveState
      ,double Displacement
      ,std::vector<double> Alphas
      ,bool LowestRoot
      ,bool UseFullApprox
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEvolution(Evolution)
      ,mCorrelations(Correlations)
      ,mSwapPiecewiseConstantVariances(SwapPiecewiseConstantVariances)
      ,mCapletVols(CapletVols)
      ,mCurveState(CurveState)
      ,mDisplacement(Displacement)
      ,mAlphas(Alphas)
      ,mLowestRoot(LowestRoot)
      ,mUseFullApprox(UseFullApprox)
      {

      };

    //~CTSMMCapletOriginalCalibrationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletAlphaFormCalibrationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mEvolution;
    string mCorrelations;
    std::vector<string> mSwapPiecewiseConstantVariances;
    std::vector<double> mCapletVols;
    string mCurveState;
    double mDisplacement;
    std::vector<double> mAlphaInitial;
    std::vector<double> mAlphaMax;
    std::vector<double> mAlphaMin;
    bool mMaximizeHomogeneity;
    string mAlphaForm;

    string mReturnValue;

    string mError;

    CTSMMCapletAlphaFormCalibrationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Evolution
      ,string Correlations
      ,std::vector<string> SwapPiecewiseConstantVariances
      ,std::vector<double> CapletVols
      ,string CurveState
      ,double Displacement
      ,std::vector<double> AlphaInitial
      ,std::vector<double> AlphaMax
      ,std::vector<double> AlphaMin
      ,bool MaximizeHomogeneity
      ,string AlphaForm
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEvolution(Evolution)
      ,mCorrelations(Correlations)
      ,mSwapPiecewiseConstantVariances(SwapPiecewiseConstantVariances)
      ,mCapletVols(CapletVols)
      ,mCurveState(CurveState)
      ,mDisplacement(Displacement)
      ,mAlphaInitial(AlphaInitial)
      ,mAlphaMax(AlphaMax)
      ,mAlphaMin(AlphaMin)
      ,mMaximizeHomogeneity(MaximizeHomogeneity)
      ,mAlphaForm(AlphaForm)
      {

      };

    //~CTSMMCapletAlphaFormCalibrationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletMaxHomogeneityCalibrationWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    string mEvolution;
    string mCorrelations;
    std::vector<string> mSwapPiecewiseConstantVariances;
    std::vector<double> mCapletVols;
    string mCurveState;
    double mDisplacement;
    double mCaplet0Swaption1Priority;

    string mReturnValue;

    string mError;

    CTSMMCapletMaxHomogeneityCalibrationWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,string Evolution
      ,string Correlations
      ,std::vector<string> SwapPiecewiseConstantVariances
      ,std::vector<double> CapletVols
      ,string CurveState
      ,double Displacement
      ,double Caplet0Swaption1Priority
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mEvolution(Evolution)
      ,mCorrelations(Correlations)
      ,mSwapPiecewiseConstantVariances(SwapPiecewiseConstantVariances)
      ,mCapletVols(CapletVols)
      ,mCurveState(CurveState)
      ,mDisplacement(Displacement)
      ,mCaplet0Swaption1Priority(Caplet0Swaption1Priority)
      {

      };

    //~CTSMMCapletMaxHomogeneityCalibrationWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationCalibrateWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    ObjectHandler::property_t mNumberOfFactors;
    ObjectHandler::property_t mMaxIter;
    double mTol;
    ObjectHandler::property_t mInnerMaxIter;
    double mInnerTol;

    bool mReturnValue;

    string mError;

    CTSMMCapletCalibrationCalibrateWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,ObjectHandler::property_t NumberOfFactors
      ,ObjectHandler::property_t MaxIter
      ,double Tol
      ,ObjectHandler::property_t InnerMaxIter
      ,double InnerTol
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mNumberOfFactors(NumberOfFactors)
      ,mMaxIter(MaxIter)
      ,mTol(Tol)
      ,mInnerMaxIter(InnerMaxIter)
      ,mInnerTol(InnerTol)
      {

      };

    //~CTSMMCapletCalibrationCalibrateWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationFailuresWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    long mReturnValue;

    string mError;

    CTSMMCapletCalibrationFailuresWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationFailuresWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationDeformationSizeWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CTSMMCapletCalibrationDeformationSizeWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationDeformationSizeWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationMarketCapletVolsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CTSMMCapletCalibrationMarketCapletVolsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationMarketCapletVolsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationModelCapletVolsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CTSMMCapletCalibrationModelCapletVolsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationModelCapletVolsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationCapletRmsErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CTSMMCapletCalibrationCapletRmsErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationCapletRmsErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationCapletMaxErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CTSMMCapletCalibrationCapletMaxErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationCapletMaxErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationMarketSwaptionVolsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CTSMMCapletCalibrationMarketSwaptionVolsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationMarketSwaptionVolsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationModelSwaptionVolsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CTSMMCapletCalibrationModelSwaptionVolsWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationModelSwaptionVolsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationSwaptionRmsErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CTSMMCapletCalibrationSwaptionRmsErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationSwaptionRmsErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationSwaptionMaxErrorWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    double mReturnValue;

    string mError;

    CTSMMCapletCalibrationSwaptionMaxErrorWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletCalibrationSwaptionMaxErrorWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationSwapPseudoRootWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    std::vector< std::vector<double> > mReturnValue;

    string mError;

    CTSMMCapletCalibrationSwapPseudoRootWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~CTSMMCapletCalibrationSwapPseudoRootWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVolsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    std::vector<double> mReturnValue;

    string mError;

    CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVolsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~CTSMMCapletCalibrationTimeDependentCalibratedSwaptionVolsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVolsWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;
    long mIndex;

    std::vector<double> mReturnValue;

    string mError;

    CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVolsWorker(
      Nan::Callback *callback
      ,string ObjectID
      ,long Index
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      ,mIndex(Index)
      {

      };

    //~CTSMMCapletCalibrationTimeDependentUnCalibratedSwaptionVolsWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};

class CTSMMCapletAlphaFormCalibrationAlphaWorker : public Nan::AsyncWorker {
  public:
    string mObjectID;

    std::vector<double> mReturnValue;

    string mError;

    CTSMMCapletAlphaFormCalibrationAlphaWorker(
      Nan::Callback *callback
      ,string ObjectID
    ):
      Nan::AsyncWorker(callback)
      ,mObjectID(ObjectID)
      {

      };

    //~CTSMMCapletAlphaFormCalibrationAlphaWorker();

    //void Destroy();

    void Execute();

    void HandleOKCallback();

};
 
#endif
