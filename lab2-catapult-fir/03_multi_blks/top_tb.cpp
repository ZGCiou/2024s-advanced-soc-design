//
//  Unpublished work. Copyright 2019 Siemens
//
//

#include "top.h"

CCS_MAIN(int argc, char *argv[])
{
  ac_int<8> coeffs[8];
  ac_channel<ac_int<8>> input;
  ac_channel<ac_int<8>> output;  
  ac_int<8> data;
  top inst;
  
  // Test Impulse
  for (int i=0; i < 8; i++)
    coeffs[i] = rand();
  for (int i = 0; i < 10; i++ ) {
    data = rand();
    input.write(data);
    inst.run(input, coeffs, output);
  }
  while (output.available(1))
    printf("Output = %3d\n",output.read().to_int());
  CCS_RETURN(0);
}
