#pragma once

#include "lv2/lv2plug.in/ns/lv2core/lv2.h"

#define MAKE_DESCRIPTOR(uri) uri, sInstantiate, sConnectPort, sActivate, sRun, sDeactivate, sCleanup, sExtensionData

template <class Derived>
class LV2Plugin
{
public:
    static LV2_Handle sInstantiate(const LV2_Descriptor*     descriptor,
                                  double                    rate,
                                  const char*               bundle_path,
                                  const LV2_Feature* const* features)
    {
        Derived* t = new Derived(rate);
        return reinterpret_cast<LV2_Handle>(t);
    }

    static void sConnectPort(LV2_Handle instance, uint32_t port, void* buffer)
    {
      	reinterpret_cast<Derived*>(instance)->ConnectPort(port, buffer);
    }

    static void sActivate(LV2_Handle instance)
    {
      	reinterpret_cast<Derived*>(instance)->Activate();
    }

    static void sRun(LV2_Handle instance, uint32_t uSamples)
    {
      	reinterpret_cast<Derived*>(instance)->Run(uSamples);
    }

    static void sDeactivate(LV2_Handle instance)
    {
      	reinterpret_cast<Derived*>(instance)->Deactivate();
    }

    static void sCleanup(LV2_Handle instance)
    {
        delete reinterpret_cast<Derived*>(instance);
    }

    static const void* sExtensionData(const char *uri)
    {
    	return nullptr;
    }
};
