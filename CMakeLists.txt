cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME task_about_circles)
project(${PROJECT_NAME})

set(CircleLib CircleLib)
set(CircleTest CircleTest)


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release)
endif()

#file(GLOB hdrs "*.h*")
#file(GLOB srcs "*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/CircleLib)
add_subdirectory(CircleLib)
add_subdirectory(CircleTest)
