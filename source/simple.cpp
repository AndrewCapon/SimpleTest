#include "TestClass.h"

extern "C" 
{
  __attribute__((__visibility__("default"))) const LV2_Descriptor* lv2_descriptor(uint32_t index) 
  {
      if (index < 1)
         return &TestClass2::descriptor;
      else
         return NULL;
  }
  
}
