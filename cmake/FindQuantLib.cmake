#  QUANTLIB_DIR   - where to find quantlib.hpp, etc.
#  QUANTLIB_FOUND - True if QuantLib found.

#  Read environment variables to find node_gyp include/lib directories
SET(QUANTLIB_DIR $ENV{QUANTLIB_ROOT})
MESSAGE( STATUS "QUANTLIB_DIR:         " ${QUANTLIB_DIR} )

FIND_PATH(QUANTLIB_DIR QuantLib)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(QUANTLIB DEFAULT_MSG QUANTLIB_DIR)

MARK_AS_ADVANCED(QUANTLIB_DIR)
