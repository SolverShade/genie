#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nanovg::nanovg" for configuration "Release"
set_property(TARGET nanovg::nanovg APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nanovg::nanovg PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libnanovg.a"
  )

list(APPEND _cmake_import_check_targets nanovg::nanovg )
list(APPEND _cmake_import_check_files_for_nanovg::nanovg "${_IMPORT_PREFIX}/lib/libnanovg.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
