package com.lionel.jni;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface UnRootedSample extends Library {
    public static final UnRootedSample INSTANCE = Native.load("uvc_camera", UnRootedSample.class);

    public int unrooted_usb_description(int fileDescriptor);
}
