#pragma once

#include <vector>

#include "LV2Plugin.h"

class TestClass2 : public LV2Plugin<TestClass2> 
{
public:
    typedef enum {
        AMP_GAIN   = 0,
        AMP_INPUT  = 1,
        AMP_OUTPUT = 2
    } PortIndex;

    TestClass2(double dSampleRate);

    void ConnectPort(uint32_t port, void* buffer);
    void Activate(void);
    void Run(uint32_t uSamples);
    void Deactivate(void);

    static const LV2_Descriptor descriptor;

private:
    double m_dSampleRate = -1;

    const float* m_fGain;
 	const float* m_fInput;
 	float*       m_fOutput;
};

