#include "atm.h"

unsigned int get_money(unsigned short int amount)
{
  unsigned int notes = 0x0;
  if (amount <= 31999)
  {
    int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
    unsigned short int balance = amount;
    for (int i = 0; i < 8; i++)
    {
      notes = notes << 4;
      notes = notes | (balance / denominations[i]);
      balance = balance % denominations[i];
    }
  }
  return notes;
}
