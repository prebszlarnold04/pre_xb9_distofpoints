cmake_minimum_required(VERSION 3.8)
project(pre_xb9_distofpoints)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

set(ament_dependencies
  rclcpp
  std_msgs
  geometry_msgs
)

add_executable(coordpublisher src/coordpublisher.cpp)
ament_target_dependencies(coordpublisher rclcpp geometry_msgs)
add_executable(coordsubscriber src/coordsubscriber.cpp)
ament_target_dependencies(coordsubscriber rclcpp geometry_msgs)
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(TARGETS
coordpublisher
coordsubscriber
DESTINATION lib/${PROJECT_NAME})

ament_package()