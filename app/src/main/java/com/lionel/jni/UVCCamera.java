package com.lionel.jni;

public class UVCCamera {
    static {
        System.loadLibrary("uvc_camera");
    }

    public static native int connect(int pid,int vid,int fd);

    public static native int uvc_init();

    public static native int uvc_find_device();
}
