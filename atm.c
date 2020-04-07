#include "atm.h"
#define MAX_AMOUNT 31999

unsigned int get_money(unsigned short int amount)
{
  unsigned int notes = 0x0;
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1}; //each byte represents the note

  if (amount > MAX_AMOUNT)
  {
    return notes;
  }

  for (int i = 0; i < 8; i++)
  {
    notes = notes << 4;                          // one byte = 4 bits ; in which each previous byte is shifted left
    notes = notes | (amount / denominations[i]); // keeping the previous bits along with new bits
    amount = amount % denominations[i];
  }
  return notes;
}
