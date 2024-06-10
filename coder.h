#include <stdio.h>
#include <string.h>

void cipher(char *text, int mode)
{
   switch (mode)
   {
   case 0:
      for (int i = 0; i<strlen(text); i++)
      { 
         text[i] += 4;
      }
    break;
    case 1:
    for (int i = 0; i<strlen(text); i++)
      { 
         text[i] -= 4;
      }
    break;
   default:
    break;
   }
}