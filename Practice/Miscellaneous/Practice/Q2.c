#include "Macros/MICROCONFIG.h"
#include "Macros/MACROS.h"
#include "Macros/STD_TYPES.h"

int main(void)
{   
   /*
    int i;
    for(i = 4; i < 8; i++)
    {
        SET_BIT(DDRA, i);
    }
   */
    
    DDRA = 0xF0;
    uint8 currBit = 4; /*Current Bit*/
    uint8 isIncreasing = 1; /*1 increasing, 0 decreasing*/
    while(1)
    {
        SET_BIT(PORTA, currBit);
        _delay_ms(1000);
        CLEAR_BIT(PORTA, currBit);
        if(currBit == 7)
        {
            isIncreasing = 0;
        }
        if(currBit == 4)
        {
            isIncreasing = 1;
        }
        if(isIncreasing)
        {
            currBit++;
        }
        else
        {
            currBit--;
        }
    }
    
    /*
    Alternative code:
    DDRA=0XF0;
    uint8 count = 4;
    
    while(1)
    {
        for (count=4;count<8;count++)
        {
             SET_BIT(PORTA,count);
             _delay_ms(1000);
            CLEAR_BIT(PORTA,count);
        }
        for (count=6;count>4;count--)
        {
             SET_BIT(PORTA,count);
             _delay_ms(1000);
            CLEAR_BIT(PORTA,count);
        }
    }
    */
    return 0;
}
