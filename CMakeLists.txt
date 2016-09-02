cmake_minimum_required(VERSION 2.8.3)
project(mrsd_ros_part3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
set(CMAKE_BUILD_TYPE Release) 

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  sensor_msgs
  tf
  pcl_conversions
  pcl_ros
)

# Node: catkin_package macro is required
catkin_package(
    CATKIN_DEPENDS
    )


find_package(PCL 1.7 REQUIRED)


###########
## Build ##
###########

include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(robot_transform_node 
	src/robot_transform_node.cpp)

target_link_libraries(robot_transform_node ${catkin_LIBRARIES} )

add_executable(camera_frame_node src/camera_frame_node.cpp)
target_link_libraries(camera_frame_node ${catkin_LIBRARIES})

add_executable(pointcloud_node src/pointcloud_node.cpp)
target_link_libraries(pointcloud_node ${catkin_LIBRARIES}) 
