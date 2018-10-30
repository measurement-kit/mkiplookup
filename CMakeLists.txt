cmake_minimum_required(VERSION 3.1.0)
project(mkiplookup LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")
include(MkUtils)

# Download dependencies
# ---------------------

MkDownloadMeasurementKitMkData()
MkDownloadMeasurementKitMkCurl()
MkDownloadCABundle()

if("${MSVC}")
  MkDownloadMeasurementKitPrebuiltWindowsCurl()
  list(APPEND CMAKE_INCLUDE_PATH "${MK_WINDOWS_CURL_INCLUDE_PATH}")
  list(APPEND CMAKE_LIBRARY_PATH "${MK_WINDOWS_CURL_LIBRARY_PATH}")
  add_definitions(${MK_WINDOWS_CURL_DEFINITIONS})
  list(APPEND MKIPLOOKUP_LIBS ${MK_WINDOWS_CURL_EXTRA_LINK_LIBS})
endif()

# Checks
# ------

find_package(CURL REQUIRED)

# Compiler flags
# --------------

MkSetCompilerFlags()

# Library and binary
# ------------------

set(MKIPLOOKUP_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
    ${CURL_INCLUDE_DIRS} ${CMAKE_REQUIRED_INCLUDES})

add_library(mkiplookup mkiplookup.cpp)
add_executable(mkiplookup-client mkiplookup-client.cpp)
target_include_directories(mkiplookup-client PUBLIC ${MKIPLOOKUP_INCLUDES})
list (APPEND MKIPLOOKUP_LIBS ${CURL_LIBRARIES})
install(FILES mkiplookup.h DESTINATION include/measurement-kit)
install(TARGETS mkiplookup-client DESTINATION bin)
if("${WIN32}" OR "${MINGW}")
  list(APPEND MKIPLOOKUP_LIBS "ws2_32")
  if ("${MINGW}")
      list(APPEND MKIPLOOKUP_LIBS -static-libgcc -static-libstdc++)
  endif()
endif()
list(APPEND MKIPLOOKUP_LIBS Threads::Threads)
target_link_libraries(mkiplookup-client "${MKIPLOOKUP_LIBS}" mkiplookup)

# Testing
# -------

set(BUILD_TESTING "ON" CACHE BOOL "Whether to build tests")
if(${BUILD_TESTING})
  enable_testing()
  add_test(NAME basic_test COMMAND mkiplookup-client)
endif()
