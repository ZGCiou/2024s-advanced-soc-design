#ifndef _FIR_REF__H
#define _FIR_REF__H

class fir_ref {
  private:
  int regs[8];

  public:
  fir_ref() {
    for (int i = 7; i>=0; i--)
    { regs[i] = 0; }  
  }

  void run(int input, int coeffs[8], int &output) {
    int temp = 0;
    
    for (int i = 7; i>=0; i--) {
      if ( i == 0 ) {
        regs[i] = input;
      } else {
        regs[i] = regs[i-1];
      }
    }
   
    for(int i = 0; i < 8; i++)
      temp += regs[i] * coeffs[i];

    output = temp >> 11;
  }
};
#endif
