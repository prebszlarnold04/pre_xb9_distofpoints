# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_pre_xb9_distofpoints_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED pre_xb9_distofpoints_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(pre_xb9_distofpoints_FOUND FALSE)
  elseif(NOT pre_xb9_distofpoints_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(pre_xb9_distofpoints_FOUND FALSE)
  endif()
  return()
endif()
set(_pre_xb9_distofpoints_CONFIG_INCLUDED TRUE)

# output package information
if(NOT pre_xb9_distofpoints_FIND_QUIETLY)
  message(STATUS "Found pre_xb9_distofpoints: 0.0.0 (${pre_xb9_distofpoints_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'pre_xb9_distofpoints' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${pre_xb9_distofpoints_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(pre_xb9_distofpoints_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${pre_xb9_distofpoints_DIR}/${_extra}")
endforeach()
