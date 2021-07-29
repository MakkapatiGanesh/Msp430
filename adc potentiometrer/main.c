//!***####2 ADC conversion Msp430
#include <msp430.h>
#include<math.h>
volatile float results;
int main(void)
{
 volatile unsigned int i;
  WDTCTL = WDTPW+WDTHOLD;                   // Stop watchdog timer
  P6SEL |= BIT0;                            // Enable A/D channel A0
  REFCTL0 &= ~REFMSTR;                      // Reset REFMSTR to hand over control to
                                            // ADC12_A ref control registers
  ADC12CTL0 = ADC12ON+ADC12SHT02+ADC12REFON+ADC12REF2_5V;//using internal reference module with 2.5 as vref
                                            // Turn on ADC12, Sampling time in 4x multiples as 02 16x multiples of adcclk.
                                            // On Reference Generator and set to
                                            // 2.5V
  ADC12CTL1 = ADC12SHP;                     // Use sampling timer
  ADC12MCTL0 = ADC12SREF1;                 // Vr+=Vref+ and Vr-=AVss

  for ( i=0; i<0x30; i++);                  // Delay for reference start-up

  ADC12CTL0 |= ADC12ENC;                    // Enable conversions
  volatile int k;
  while (1)
  {

    ADC12CTL0 |= ADC12SC;
    k=ADC12MEM0;// Start conversion
   results = (ADC12MEM0 *0.00061)-0.0246;

                          // SET BREAKPOINT HERE

  }
}
