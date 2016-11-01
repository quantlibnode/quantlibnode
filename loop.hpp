#ifndef ohn_loop_hpp
#define ohn_loop_hpp

namespace ObjectHandler {

    //! Invoke the contained function once for each item in the input vector.
    template<class LoopFunction, class InputType, class OutputType>
    void loop(
              LoopFunction &loopFunction,
              std::vector<InputType> &xIn,
              std::vector<OutputType> &xOut) {
  			for (unsigned int i = 0; i < xIn.size(); i++) {
  				xOut.push_back(loopFunction(xIn[i]));
  			}
    }

    template<class LoopFunction, class InputType>
    void loop(
              LoopFunction &loopFunction,
              std::vector<InputType> &xIn) {
  			for (unsigned int i = 0; i < xIn.size(); i++) {
  				loopFunction(xIn[i]);
  			}
    }
}

#endif
