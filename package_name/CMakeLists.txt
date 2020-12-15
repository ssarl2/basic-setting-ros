cmake_minimum_required(VERSION 3.0.2)
project(package_name)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pthread")

INCLUDE(FindPkgConfig)

## Find catkin
find_package(catkin REQUIRED)

set(CATKIN_DEPS
    roscpp
)

find_package(catkin REQUIRED COMPONENTS ${CATKIN_DEPS})

catkin_package(
    # INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS ${CATKIN_DEPS}
    # DEPENDS system_lib
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

set(SOURCE
    src/main.cpp
)

set(LIBS
    ${catkin_LIBRARIES}
)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} ${LIBS})

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY
    launch
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
