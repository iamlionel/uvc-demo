package com.lionel.jni

import android.hardware.usb.UsbDevice
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.lionel.jni.usb.USBMonitor

class MainActivity : AppCompatActivity() {
    private var usbMonitor: USBMonitor? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        usbMonitor = USBMonitor(this, object : USBMonitor.OnDeviceConnectListener {
            override fun onAttach(device: UsbDevice) {
                usbMonitor!!.requestPermission(device)
            }

            override fun onDetach(device: UsbDevice?) {
            }

            override fun onConnect(
                device: UsbDevice,
                ctrlBlock: USBMonitor.UsbControlBlock,
                createNew: Boolean
            ) {
                if (device.productId == 53385 && device.vendorId == 3141) {
                    val res = UVCCamera.connect(device.productId, device.productId,ctrlBlock.fileDescriptor)
//                    UnRootedSample.INSTANCE.unrooted_usb_description(ctrlBlock.fileDescriptor)
                }
            }

            override fun onDisconnect(device: UsbDevice, ctrlBlock: USBMonitor.UsbControlBlock) {
            }

            override fun onCancel(device: UsbDevice) {
            }
        })
        usbMonitor!!.register()
    }

    private fun testUnRootedSample() {

    }

    override fun onDestroy() {
        super.onDestroy()
        usbMonitor?.destroy()
    }
}