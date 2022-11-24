cmake_minimum_required(VERSION 3.18.1)

project("uvc_camera")

#include_directories(libusb/android/examples)
set(libs ${CMAKE_SOURCE_DIR}/libusb/android/libs/${CMAKE_ANDROID_ARCH_ABI})

add_library(libusb1.0 SHARED IMPORTED)
set_target_properties(libusb1.0 PROPERTIES IMPORTED_LOCATION ${libs}/libusb1.0.so)

include_directories(libuvc/include)
set(uvc
        libuvc/src/ctrl.c
        libuvc/src/ctrl-gen.c
        libuvc/src/device.c
        libuvc/src/frame.c
        libuvc/src/init.c
        libuvc/src/stream.c
        libuvc/src/misc.c)

add_library(uvc_camera SHARED uvc_camera/uvc_camera.cpp ${uvc})

find_library(log-lib log)

target_link_libraries(
        uvc_camera
        libusb1.0
        ${log-lib})
