# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# CMake require "project(Project)" command on the first after cmake_minimum_required
project(myalgorithm)

aux_source_directory( . NATIVE_SRC )
aux_source_directory( ./mylib/ MYLIB )

set(TEST_MATH ${NATIVE_SRC})

file(GLOB CPP_LIB_FILES "mylib/*.cpp")
file(GLOB CPP_FILES "*.cpp")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    MESSAGE(STATUS "${PROJECT_NAME} Now is Clang.")
    list(APPEND NATIVE_SRC ${MYLIB})
    add_library(nativelib SHARED ${CPP_LIB_FILES} ${CPP_FILES} ${NATIVE_SRC})
    find_library(log-lib log)
    target_link_libraries(nativelib ${log-lib})
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    MESSAGE(STATUS "${PROJECT_NAME} Now is GNU.")
    add_executable(myalgorithm ${TEST_MATH})
endif()