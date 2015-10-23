LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

MY_CLASS_FILES :=$(shell find $(LOCAL_PATH)/../../Classes -name *.cpp)
MY_ANDROID_CLASS_FILES :=$(shell find $(LOCAL_PATH)/../../native -name *.cpp)

LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(MY_CLASS_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_ANDROID_CLASS_FILES:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(shell find $(LOCAL_PATH)/../../Classes -type d)
LOCAL_C_INCLUDES += $(shell find $(LOCAL_PATH)/../../native -type d)

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
