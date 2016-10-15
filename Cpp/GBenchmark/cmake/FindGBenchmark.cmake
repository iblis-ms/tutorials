# Locate the Google C++ Benchmark Framework.
# (This file was written based on FindGMock: https://github.com/triglav/cmake-findgmock)
#
#
# Defines the following variables:
#
#   GMOCK_FOUND - Found the Google Testing framework
#   GMOCK_INCLUDE_DIRS - Include directories
#
# Also defines the library variables below as normal
# variables. These contain debug/optimized keywords when
# a debugging library is found.
#
#   GMOCK_BOTH_LIBRARIES - Both libgmock & libgmock-main
#   GMOCK_LIBRARIES - libgmock
#   GMOCK_MAIN_LIBRARIES - libgmock-main
#
# Accepts the following variables as input:
#
#   GMOCK_ROOT - (as a CMake or environment variable)
#                The root directory of the gmock install prefix
#
#   GMOCK_MSVC_SEARCH - If compiling with MSVC, this variable can be set to
#                       "MD" or "MT" to enable searching a gmock build tree
#                       (defaults: "MD")
#
#-----------------------
# Example Usage:
#
#    find_package(GMock REQUIRED)
#    include_directories(${GMOCK_INCLUDE_DIRS})
#
#    add_executable(foo foo.cc)
#    target_link_libraries(foo ${GMOCK_BOTH_LIBRARIES})
#
#=============================================================================
# This file is released under the MIT licence:
#
# Copyright (c) 2011 Marcin Serwach
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#=============================================================================


function(_gbenchmark_append_debugs _endvar _library)
  if(${_library} AND ${_library}_DEBUG)
    set(_output optimized ${${_library}} debug ${${_library}_DEBUG})
  else()
    set(_output ${${_library}})
  endif()
  set(${_endvar} ${_output} PARENT_SCOPE)
endfunction()

function(_gbenchmark_find_library _name)
  find_library(${_name}
    NAMES ${ARGN}
    HINTS
      $ENV{GBENCHMARK_ROOT}
      ${GBENCHMARK_ROOT}
    PATH_SUFFIXES ${_gbenchmark_libpath_suffixes}
  )
  mark_as_advanced(${_name})
endfunction()


if(NOT DEFINED GBENCHMARK_MSVC_SEARCH)
  set(GBENCHMARK_MSVC_SEARCH MD)
endif()

set(_gbenchmark_libpath_suffixes lib)
if(MSVC)
  if(GBENCHMARK_MSVC_SEARCH STREQUAL "MD")
    list(APPEND _gbenchmark_libpath_suffixes
      msvc/gbenchmark-md/Debug
      msvc/gbenchmark-md/Release)
  elseif(GMOCK_MSVC_SEARCH STREQUAL "MT")
    list(APPEND _gbenchmark_libpath_suffixes
      msvc/gbenchmark/Debug
      msvc/gbenchmark/Release)
  endif()
endif()

find_path(GBENCHMARK_INCLUDE_DIR benchmark/benchmark.h
  HINTS
    $ENV{GBENCHMARK_ROOT}/include
    ${GBENCHMARK_ROOT}/include
)
mark_as_advanced(GBENCHMARK_INCLUDE_DIR)

if(MSVC AND GBENCHARK_MSVC_SEARCH STREQUAL "MD")
  # The provided /MD project files for Google Mock add -md suffixes to the
  # library names.
  _gbenchmark_find_library(GBENCHMARK_LIBRARY            benchmark-md  benchmark)
  _gbenchmark_find_library(GBENCHMARK_LIBRARY_DEBUG      benchmark-mdd benchmarkd)
else()
  _gbenchmark_find_library(GBENCHMARK_LIBRARY            benchmark)
  _gbenchmark_find_library(GBENCHMARK_LIBRARY_DEBUG      benchmarkd)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GBENCHMARK DEFAULT_MSG GBENCHMARK_LIBRARY GBENCHMARK_INCLUDE_DIR)

if(GBENCHMARK_FOUND)
  set(GBENCHMARK_INCLUDE_DIRS ${GBENCHMARK_INCLUDE_DIR})
  _gbenchmark_append_debugs(GBENCHMARK_LIBRARIES      GBENCHMARK_LIBRARY)
endif()


