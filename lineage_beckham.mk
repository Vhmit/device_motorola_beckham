#
# Copyright (C) 2026 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Inherit from beckham device
$(call inherit-product, $(LOCAL_PATH)/device.mk)

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Define boot animation
TARGET_BOOT_ANIMATION_RES := 1080

# Device identifiers
PRODUCT_DEVICE := beckham
PRODUCT_NAME := lineage_beckham
PRODUCT_BRAND := motorola
PRODUCT_MODEL := Moto Z3 Play
PRODUCT_MANUFACTURER := Motorola

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_NAME=beckham \
    PRIVATE_BUILD_DESC="beckham-user 9 PPWS29.131-27-1-15 4d8b92 release-keys"

BUILD_FINGERPRINT := motorola/beckham/beckham:9/PPWS29.131-27-1-15/4d8b92:user/release-keys
