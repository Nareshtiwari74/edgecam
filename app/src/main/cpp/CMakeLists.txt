cmake_minimum_required(VERSION 3.22.1)

project("edgedetectorapp")

# Set path to your OpenCV SDK here, adjust as needed:
set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/../../../OpenCV-android-sdk/sdk/native/jni)

find_package(OpenCV REQUIRED)

add_library(
        native-lib  # This is your native library name
        SHARED
        native-lib.cpp  # Make sure this matches your C++ file name exactly
)

target_include_directories(
        native-lib PRIVATE ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(
        native-lib
        ${OpenCV_LIBS}
        log
)
