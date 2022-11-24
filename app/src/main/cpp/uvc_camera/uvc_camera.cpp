#include <jni.h>
#include "libuvc/libuvc.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_lionel_jni_UVCCamera_uvc_1init(JNIEnv *env, jclass clazz) {
    uvc_context_t *context;
    uvc_error_t res = uvc_init(&context, NULL);
    return res;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_lionel_jni_UVCCamera_uvc_1find_1device(JNIEnv *env, jclass clazz) {

}