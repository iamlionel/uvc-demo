package com.lionel.jni;

public class NativeJava {
    static {
        System.loadLibrary("jni-demo");
    }

    public static native int hello();

    public static native int uvc_init();
}
