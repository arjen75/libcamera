LOCAL_PATH := $(call my-dir)
MY_PATH := $(LOCAL_PATH)
include $(call all-subdir-makefiles)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_CFLAGS := -g -fPIC
LOCAL_PATH := $(MY_PATH)
LOCAL_LDLIBS := -llog -ldl
LOCAL_MODULE    := camera.swift
LOCAL_SRC_FILES := QualcommCameraHardware.cpp
LOCAL_PRELINK_MODULE := false
LOCAL_SHARED_LIBRARIES:= liblog libdl libutils libcamera_client liboemcamera libbinder libcutils



LOCAL_C_INCLUDES := frameworks/base/services/ frameworks/base/services/camera/libcameraservice/

include $(BUILD_SHARED_LIBRARY)
