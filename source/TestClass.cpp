#include <math.h>

#include "TestClass.h"

const LV2_Descriptor TestClass2::descriptor = {MAKE_DESCRIPTOR("http://lv2plug.in/plugins/simple-test")};

#define DB_CO(g) ((g) > -90.0f ? powf(10.0f, (g) * 0.05f) : 0.0f)

TestClass2::TestClass2(double dSampleRate)
{
    m_dSampleRate = dSampleRate;
}

void TestClass2::ConnectPort(uint32_t port, void *pBuffer)
{
	switch ((PortIndex)port) 
    {
        case AMP_GAIN:
            m_fGain = (const float*)pBuffer;
            break;
        case AMP_INPUT:
            m_fInput = (const float*)pBuffer;
            break;
        case AMP_OUTPUT:
            m_fOutput = (float*)pBuffer;
            break;
	}
}

void TestClass2::Activate(void)
{
}

void TestClass2::Run(uint32_t uSamples)
{
	const float coef = DB_CO(*m_fGain);

	for (uint32_t pos = 0; pos < uSamples; pos++) 
    {
		m_fOutput[pos] = m_fInput[pos] * coef;
	}
}

void TestClass2::Deactivate(void)
{
}


