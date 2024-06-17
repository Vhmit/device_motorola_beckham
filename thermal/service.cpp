/*
 * Copyright (C) 2026 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>
#include "Thermal.h"

using android::sp;
using android::status_t;
using android::OK;

// libhwbinder:
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

// Generated HIDL files
using android::hardware::thermal::V1_1::IThermal;
using android::hardware::thermal::V1_1::implementation::Thermal;

int main() {

    status_t status;
    android::sp<IThermal> service = nullptr;

    LOG(INFO) << "Thermal HAL Service 1.1 is starting";

    service = new Thermal();
    if (service == nullptr) {
        LOG(ERROR) << "Can not create an instance of Thermal HAL Iface, exiting";

        goto shutdown;
    }

    configureRpcThreadpool(1, true /*callerWillJoin*/);

    status = service->registerAsService();
    if (status != OK) {
        LOG(ERROR) << "Could not register service for Thermal HAL Iface (" << status << ")";
        goto shutdown;
    }

    LOG(INFO) << "Thermal Service is ready";
    joinRpcThreadpool();
    // Should not pass this line

shutdown:
    // In normal operation, we don't expect the thread pool to exit
    LOG(ERROR) << "Thermal Service is shutting down";
    return 1;
}
