//
//  Unpublished work. Copyright 2019 Siemens
//
//

#include "fir.h"

CCS_MAIN(int argc, char *argv[])
{
  ac_int<8> coeffs[32][8];
  ac_channel<ac_int<8>> input;
  ac_channel<ac_int<5,false>> coeff_addr;
  ac_channel<ac_int<8>> output;  
  ac_int<8> data;
  ac_int<5,false> addr;
  fir inst;
  
  // Test Impulse
  for (int j=0; j < 32; j++)
    for (int i=0; i < 8; i++)
      coeffs[j][i] = rand();
  for (int i = 0; i < 10; i++ ) {
    data = rand();
    input.write(data);
    addr = rand();
    coeff_addr.write(addr);
    inst.run(input, coeffs, coeff_addr, output);
  }
  while (output.available(1))
    printf("Output = %3d\n",output.read().to_int());
  CCS_RETURN(0);
}
