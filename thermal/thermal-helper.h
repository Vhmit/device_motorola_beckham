/*
 * Copyright (C) 2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __THERMAL_HELPER_H__
#define __THERMAL_HELPER_H__

#include <android/hardware/thermal/1.1/IThermal.h>

namespace android {
namespace hardware {
namespace thermal {
namespace V1_1 {
namespace implementation {

using ::android::hardware::thermal::V1_0::CpuUsage;
using ::android::hardware::thermal::V1_0::Temperature;

constexpr const char *kCpuUsageFile = "/proc/stat";
constexpr const char *kTemperatureFileFormat = "/sys/class/thermal/thermal_zone%d/temp";
constexpr const char *kCpuOnlineFileFormat = "/sys/devices/system/cpu/cpu%d/online";

// thermal-engine.conf
constexpr unsigned int kSkinSensorNum = 8;
constexpr auto         kSkinSensorType = "quiet_therm";
constexpr unsigned int kTsensOffset = 9;
constexpr unsigned int kSkinThrottlingThreshold = 41;
constexpr unsigned int kSkinShutdownThreshold = 47;
constexpr unsigned int kVrThrottledBelowMin = 44;

constexpr unsigned int kBatterySensorNum = 0;
constexpr unsigned int kGpuTsensOffset = 11;
constexpr unsigned int kCpuNum = 8;

constexpr const char *kGpuLabel = "GPU";
constexpr const char *kBatteryLabel = "battery";
constexpr const char *kSkinLabel = "skin";
constexpr const char *kCpuLabel[kCpuNum] = {"CPU0", "CPU1", "CPU2", "CPU3", "CPU4", "CPU5", "CPU6", "CPU7"};
constexpr int kCpuTsensOffset[kCpuNum] = {1, 2, 4, 3, 5, 6, 7, 8};

// Sum of kCpuNum + 3 for GPU, BATTERY, and SKIN.
constexpr unsigned int kTemperatureNum = 3 + kCpuNum;

// qcom, therm-reset-temp
constexpr unsigned int kCpuShutdownThreshold = 115;
// qcom,freq-mitigation-temp
constexpr unsigned int kCpuThrottlingThreshold = 95;

// config_shutdownBatteryTemperature in overlay/frameworks/base/core/res/res/values/config.xml
constexpr unsigned int kBatteryShutdownThreshold = 60;


bool initThermal();
ssize_t fillTemperatures(hidl_vec<Temperature> *temperatures);
ssize_t fillCpuUsages(hidl_vec<CpuUsage> *cpuUsages);
std::string getTargetSkinSensorType();

}  // namespace implementation
}  // namespace V1_1
}  // namespace thermal
}  // namespace hardware
}  // namespace android

#endif //__THERMAL_HELPER_H__
