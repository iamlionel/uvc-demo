#include <jni.h>
#include "libuvc/libuvc.h"
#include "libusb.h"
#include  <android/log.h>

#define  TAG    "uvc_camera"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)

int unrooted_usb_description(int fileDescriptor)
{
    libusb_context *ctx = NULL;
    libusb_device_handle *devh = NULL;
    libusb_device *device;
    int r = 0;
    int verbose = 1;
    r = libusb_set_option(NULL, LIBUSB_OPTION_NO_DEVICE_DISCOVERY, NULL);
    if (r != LIBUSB_SUCCESS) {
        LOGD("libusb_set_option failed: %d\n", r);
        return -1;
    }
    r = libusb_init(&ctx);
    if (r < 0) {
        LOGD("libusb_init failed: %d\n", r);
        return r;
    }
    r = libusb_wrap_sys_device(ctx, (intptr_t)fileDescriptor, &devh);
    if (r < 0) {
        LOGD("libusb_wrap_sys_device failed: %d\n", r);
        return r;
    } else if (devh == NULL) {
        LOGD("libusb_wrap_sys_device returned invalid handle\n");
        return r;
    }
    device = libusb_get_device(devh);
    if (device) {
        LOGD("get device ok %d");
    }
    return r;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_lionel_jni_UVCCamera_uvc_1init(JNIEnv *env, jclass clazz) {

}

extern "C"
JNIEXPORT jint JNICALL
Java_com_lionel_jni_UVCCamera_uvc_1find_1device(JNIEnv *env, jclass clazz) {

}
extern "C"
JNIEXPORT jint JNICALL
Java_com_lionel_jni_UVCCamera_connect(JNIEnv *env, jclass clazz, jint pid, jint vid,jint fd) {
    uvc_context_t *context;
    uvc_error_t res = uvc_init(&context, NULL);
    if (res < 0) {
        LOGE("init error:%d", res);
    }
    uvc_device_t *device;

    unrooted_usb_description(fd);
//    res = uvc_find_device(context, &device, vid, pid, nullptr);
//    if (res < 0) {
//        LOGE("find device error:%d", res);
//        return res;
//    }
//    LOGI("connect success");
    return res;
}

