//
//  Unpublished work. Copyright 2019 Siemens
//
//

#include "fir.h"
#include "decimator.h"

class top {

  ac_channel<ac_int<8> > connect0;
  ac_channel<ac_int<8> > connect1;

  fir block0;
  fir block1;
  decimator block2;

  public :

  top () {}


  #pragma hls_design interface top
  void CCS_BLOCK(run) (ac_channel<ac_int<8> > &din,
                       ac_int<8> coeffs[8],
                       ac_channel<ac_int<8> > &dout) {
 
    block0.run(din,coeffs,connect0);
    block1.run(connect0,coeffs,connect1);
    block2.run(connect1,dout);
  }
};
