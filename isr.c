#include <xc.h>
#include "main.h"

extern unsigned char min,sec;

void __interrupt() isr(void)

// __interrupt()  specifier used by the compiler
{
    static unsigned int count = 0;
    
    if (TMR2IF == 1)
    {    
        if (++count == 20000) // 1sec  NO OF OVFLS=200000 =1 SEC
        {
            count = 0;
            if(sec>0)
            {
                sec--;
            }
            else if(sec == 0 && min>0)
            {
                min--;
                sec=59;
            }
                    
            
        }
        
        TMR2IF = 0;
    }
    
    
    
    
}