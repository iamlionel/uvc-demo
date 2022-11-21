cmake_minimum_required(VERSION 3.18.1)

project("jni")

include_directories(./libuvc/include)
set(uvc
        libuvc/src/ctrl.c
        libuvc/src/ctrl-gen.c
        libuvc/src/device.c
        libuvc/src/frame.c
        libuvc/src/init.c
        libuvc/src/stream.c
        libuvc/src/misc.c)

set(libs ${CMAKE_SOURCE_DIR}/libusb)
add_library(libusb100 SHARED IMPORTED)
set_target_properties(libusb100 PROPERTIES IMPORTED_LOCATION ${libs}/libusb100.so)

add_library(jni-demo SHARED hello.cpp ${uvc})

find_library(log-lib log)

target_link_libraries(
        jni-demo
        libusb100
        ${log-lib})
