#include <stdio.h>
#include "atm.h"

void display_notes(unsigned int notes)
{
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  for (int i = 0; i < 8; i++)
  {
    int count = notes >> 28;
    count &&printf("%d %s of rs %d\n", count, count == 1 ? "note" : "notes", denominations[i]);
    notes = notes << 4;
  }
}

int main(void)
{
  unsigned short int amounts[] = {1, 10, 39, 589, 2590, 31999};
  for (int i = 0; i < 6; i++)
  {
    unsigned int notes = get_money(amounts[i]);
    // printf("%5u %08x\n", amounts[i], notes);
    printf("Amount is %u\n", amounts[i]);
    display_notes(notes);
  }

  return 0;
}
