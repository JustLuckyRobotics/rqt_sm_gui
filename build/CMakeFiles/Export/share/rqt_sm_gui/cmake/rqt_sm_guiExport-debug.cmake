#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rqt_sm_gui::rqt_sm_gui" for configuration "Debug"
set_property(TARGET rqt_sm_gui::rqt_sm_gui APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(rqt_sm_gui::rqt_sm_gui PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "cv_bridge::cv_bridge"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/rqt_sm_gui/librqt_sm_gui.so"
  IMPORTED_SONAME_DEBUG "librqt_sm_gui.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rqt_sm_gui::rqt_sm_gui )
list(APPEND _IMPORT_CHECK_FILES_FOR_rqt_sm_gui::rqt_sm_gui "${_IMPORT_PREFIX}/lib/rqt_sm_gui/librqt_sm_gui.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
