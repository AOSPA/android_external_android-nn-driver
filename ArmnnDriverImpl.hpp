//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "DriverOptions.hpp"
#include "NamespaceAdaptor.hpp"

#include <HalInterfaces.h>


#ifdef ARMNN_ANDROID_NN_V1_2 // Using ::android::hardware::neuralnetworks::V1_2
namespace V1_2 = ::android::hardware::neuralnetworks::V1_2;
#endif

namespace armnn_driver
{

template<typename HalPolicy>
class ArmnnDriverImpl
{
public:
    using HalModel                     = typename HalPolicy::Model;
    using HalGetSupportedOperations_cb = typename HalPolicy::getSupportedOperations_cb;

    static Return<void> getSupportedOperations(
            const armnn::IRuntimePtr& runtime,
            const DriverOptions& options,
            const HalModel& model,
            HalGetSupportedOperations_cb);

    static Return<V1_0::ErrorStatus> prepareModel(
            const armnn::IRuntimePtr& runtime,
            const armnn::IGpuAccTunedParametersPtr& clTunedParameters,
            const DriverOptions& options,
            const HalModel& model,
            const android::sp<V1_0::IPreparedModelCallback>& cb,
            bool float32ToFloat16 = false);

    static Return<V1_0::DeviceStatus> getStatus();

};

} // namespace armnn_driver
