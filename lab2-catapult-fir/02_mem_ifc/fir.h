//
//  Unpublished work. Copyright 2019 Siemens
//
//

#ifndef _FIR__H
#define _FIR__H

#include <ac_int.h>
#include <ac_channel.h>
#include <mc_scverify.h>

class fir {
  ac_int<8> regs[8];

  public:
  fir() {      // Required constructor
    for (int i = 7; i>=0; i--)
    { regs[i] = 0; }  // Initialization of taps
  }

  #pragma hls_design interface
  void CCS_BLOCK(run)(ac_channel<ac_int<8>> &input,
                      ac_int<8> coeffs[32][8],
                      ac_channel<ac_int<5,false>> &coeff_addr,
                      ac_channel<ac_int<8>> &output) {
    ac_int<19> temp = 0;
    ac_int<5,false> addr = coeff_addr.read();

    SHIFT:for (int i = 7; i>=0; i--) {
      if ( i == 0 ) {
        regs[i] = input.read();
      } else {
        regs[i] = regs[i-1];
      }
    }
    MAC:for (int i = 7; i>=0; i--) {
      temp += coeffs[addr][i]*regs[i];
    }
    output.write(temp>>11);
  }
};
#endif
