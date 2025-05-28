# Path to OpenCV headers
include_directories(src/main/cpp/opencv/jni/include)

# Specify your native source files
add_library(native-lib SHARED
        src/main/cpp/native-lib.cpp)

# Load OpenCV shared libraries
add_library(opencv_java4 SHARED IMPORTED)
set_target_properties(opencv_java4 PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java4.so)

# Link your native-lib with OpenCV library and log (for Android logs)
target_link_libraries(native-lib
        opencv_java4
        log)
