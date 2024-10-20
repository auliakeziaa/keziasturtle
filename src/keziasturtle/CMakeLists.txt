cmake_minimum_required(VERSION 3.0.2)
project(keziasturtle)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  turtlesim
)

catkin_package(
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)

INCLUDE_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(/usr/local/lib)

add_executable(go_to_name src/go_to_name.cpp)
target_link_libraries(go_to_name ${catkin_LIBRARIES})