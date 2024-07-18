cmake_minimum_required(VERSION 3.8)
project(rqt_sm_gui)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()



include_directories(
  include/rqt_sm_gui
  src/rqt_sm_gui
  ${Qt5Widgets_INCLUDE_DIRS}
)

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(rclcpp REQUIRED)
find_package(qt_gui_cpp REQUIRED)
find_package(rqt_gui_cpp REQUIRED)
find_package(image_transport REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(ament_cmake_python REQUIRED)
# find_package(rqt_image_view REQUIRED)

# include_directories(
#   ${rqt_image_view_INCLUDE_DIRS}
# )

set(rqt_sm_gui_SRCS
  src/rqt_sm_gui/sm_gui.cpp
  src/rqt_sm_gui/ratio_layouted_frame.cpp
)

set(rqt_sm_gui_HDRS
  include/rqt_sm_gui/sm_gui.h
  include/rqt_sm_gui/ratio_layouted_frame.h

)

set(rqt_sm_gui_UIS
  src/rqt_sm_gui/sm_gui.ui
)

qt5_wrap_cpp(rqt_sm_gui_MOCS ${rqt_sm_gui_HDRS})

qt5_wrap_ui(rqt_sm_gui_UIS_H ${rqt_sm_gui_UIS})



add_library(${PROJECT_NAME} SHARED
  ${rqt_sm_gui_SRCS}
  ${rqt_sm_gui_MOCS}
  ${rqt_sm_gui_UIS_H}
)

target_include_directories(${PROJECT_NAME} PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
)

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${rclcpp_TARGETS}
  ${qt_gui_cpp_TARGETS}
  ${rqt_gui_cpp_TARGETS}
  image_transport::image_transport
  ${sensor_msgs_TARGETS}
  ${geometry_msgs_TARGETS}
  Qt5::Widgets
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  cv_bridge::cv_bridge)


install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib/${PROJECT_NAME}
  LIBRARY DESTINATION lib/${PROJECT_NAME}
  RUNTIME DESTINATION bin/${PROJECT_NAME}
)
  
# install(PROGRAMS scripts/rqt_sm_gui
#   DESTINATION lib/${PROJECT_NAME}
# )
  
# install(PROGRAMS scripts/image_publisher
#   DESTINATION lib/${PROJECT_NAME}
# )
  
install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)
  
install(FILES plugin.xml
  DESTINATION share/${PROJECT_NAME}
)
  
# install(DIRECTORY resource
#   DESTINATION share/${PROJECT_NAME}
# )

pluginlib_export_plugin_description_file(rqt_gui "plugin.xml")

# Export old-style CMake variables
ament_export_include_directories("include/${PROJECT_NAME}")
ament_export_libraries(${PROJECT_NAME})

# Export new-style CMake variables
ament_export_targets(${PROJECT_NAME})





ament_package()
