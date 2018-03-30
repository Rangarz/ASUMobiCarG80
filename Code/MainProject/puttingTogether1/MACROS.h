#ifndef MACROS_H
#define MACROS_H

/*ORing with 0001 for example would change the first bit to 1 and keep all others*/
#define SET_BIT(REG, BIT) (REG |= (1<<BIT)) 

/*1<<BIT -> 0010, ~(0010) -> 1101  -> ANDing with a register would mean setting the second bit to 0*/
#define CLEAR_BIT(REG , BIT) ( REG &= (~(1<<BIT)))

/*XOR = Exclusive OR, 1<< BIT -> 0010 XORed with a register will result in toggling of the bit's value  */
#define TOGGLE_BIT(REG , BIT) (REG ^= (1<<BIT))

/* register ANDed with 1 in place of bit inspected, result is 1 if bit is set*/
#define IS_BIT_SET(REG , BIT) (REG & (1<<BIT))

/* inverting of register ANDed with 1 in place of bit inspected, result is 1 if bit is clear*/
#define IS_BIT_CLEAR(REG , BIT) (!(REG & (1<<BIT)))


#endif
