#  NODE_GYP_DIR   - where to find node.h, etc.
#  NODE_GYP_VER   - version of node
#  NAN_DIR        - nan module
#  NODE_GYP_FOUND - True if node found.

#  Read environment variables to find node_gyp include/lib directories
SET(NODE_GYP_VER "4.4.5")
MESSAGE( STATUS "NODE_GYP_VER:         " ${NODE_GYP_VER} )
SET(NODE_GYP_DIR $ENV{NODE_GYP_DIR}/${NODE_GYP_VER})
MESSAGE( STATUS "NODE_GYP_DIR:         " ${NODE_GYP_DIR} )

SET(NAN_DIR $ENV{NAN_DIR})
MESSAGE( STATUS "NAN_DIR:         " ${NAN_DIR} )

FIND_PATH(NODE_GYP_DIR installVersion)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NODE DEFAULT_MSG NODE_GYP_DIR NAN_DIR)

MARK_AS_ADVANCED(NODE_GYP_DIR NAN_DIR)
