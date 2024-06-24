//
//  Unpublished work. Copyright 2019 Siemens
//
//

#include "fir_ref.h"
#include "fir.h"

CCS_MAIN(int argc, char *argv[])
{
  int8 coeffs[8];
  ac_channel<int8> in_chn;
  ac_channel<int8> out_chn;  
  int8 din ,dout;

  int coeffs_ref[8];
  int din_ref;
  int dout_ref;

  fir     dut;
  fir_ref ref_model;

  int pass_cnt = 0;
  int fail_cnt = 0;
  
  // Test Impulse
  for (int i=0; i < 8; i++)
    coeffs_ref[i] = coeffs[i] = -128 + rand()%256;

  for (int i = 0; i < 100; i++ ) {
    din_ref = din = -128 + rand()%256;
    in_chn.write(din);
    dut.run(in_chn, coeffs, out_chn);
    ref_model.run(din_ref, coeffs_ref, dout_ref);
    dout = out_chn.read();
    if (dout.to_int()!=dout_ref) {
      printf("fail @ %3d: %4d != %4d \n", i, dout.to_int(), dout_ref);
      fail_cnt ++;
    } else {
      printf("pass @ %3d: %4d == %4d \n", i, dout.to_int(), dout_ref);
      pass_cnt ++;
    }
  }
  printf("\n");
  printf("total pass count %d\n", pass_cnt);
  printf("total fail count %d\n", fail_cnt);

  CCS_RETURN(0);
}

