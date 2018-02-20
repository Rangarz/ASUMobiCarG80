#include "Macros/MICROCONFIG.h"
#include "Macros/MACROS.h"
#include "Macros/STD_TYPES.h"
int main(void)
{   
    SET_BIT(DDRA,PA0); //sets PA0 to output
    while(1)
    {
        SET_BIT(PORTA,PA0);
        _delay_ms(500);
        ClEAR_BIT(PORTA,PA0);
        _delay_ms(1500);
    }
    return 0;
}
