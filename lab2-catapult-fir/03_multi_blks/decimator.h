//
//  Unpublished work. Copyright 2019 Siemens
//
//

#ifndef _DECIMATOR__H
#define _DECIMATOR__H

#include <ac_int.h>
#include <ac_channel.h>
#include <mc_scverify.h>

class decimator {

  int count;
  public :
  decimator () {
    count = 0;
  }

  #pragma hls_design interface
  void CCS_BLOCK(run) (ac_channel<ac_int<8> > &din,
                       ac_channel<ac_int<8> > &dout) {
  
    if (count==4) 
      {count = 0;} 
    ac_int<8> temp = din.read();
    if (count==0) 
      {dout.write(temp);}
    
    count++;
  }
};
#endif
