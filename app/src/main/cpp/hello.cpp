#include <jni.h>
#include <string>
#include "libuvc/libuvc.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_lionel_jni_NativeJava_hello(JNIEnv *env, jclass clazz) {

    return 123;
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_lionel_jni_NativeJava_uvc_1init(JNIEnv *env, jclass clazz) {
    uvc_context_t *context;
    uvc_error_t res = uvc_init(&context, nullptr);
    return res;
}