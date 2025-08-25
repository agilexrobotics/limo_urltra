cmake_minimum_required(VERSION 3.8)
project(limo_urltra_base)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(limo_urltra_msgs REQUIRED)
find_package(tf2_geometry_msgs)
find_package(turtlesim)

include_directories(
  include
)

set(DEPENDENCIES
  "geometry_msgs"
  "nav_msgs"
  "rclcpp"
  "std_msgs"
  "tf2"
  "tf2_ros"
  "limo_urltra_msgs"
  "sensor_msgs"
)

add_executable(limo_urltra_base 
    src/limo_urltra_base_node.cpp
    src/limo2_urltra_driver.cpp
    src/serial_port.cpp)
ament_target_dependencies(limo_urltra_base  rclcpp std_msgs tf2 tf2_ros nav_msgs sensor_msgs limo_urltra_msgs tf2_geometry_msgs )

install(TARGETS  
  limo_urltra_base  
  DESTINATION lib/${PROJECT_NAME})
  
install(DIRECTORY launch src 
  DESTINATION share/${PROJECT_NAME}/)
  
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
