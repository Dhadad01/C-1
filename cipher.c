#include "cipher.h"
#include <string.h>
#include <stdio.h>
const int HIGHEST_LOWERCASE = 123;
const int NUM_OF_ALPHA_BET = 26;
const int HIGHEST_SIGN = 96;
const int LOWEST_SIGN = 91;
const int LOWEST_UPPERCASE = 64;
/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.


// See full documentation in header file
void encode (char s[], int k)
{
  int mod_k = k % 26;
  unsigned int ln = strlen (s);
  for (int i = 0; i < ln; i++)
  {
    if (LOWEST_UPPERCASE < s[i] && s[i] < HIGHEST_LOWERCASE
        && (s[i] < LOWEST_SIGN ||
            s[i] > HIGHEST_SIGN))
    {
      s[i] = s[i] + mod_k;
      if (s[i] >= HIGHEST_LOWERCASE)
      {
        s[i] = s[i] - NUM_OF_ALPHA_BET;
      }
      else if (s[i] < LOWEST_UPPERCASE)
      {
        s[i] = s[i] + NUM_OF_ALPHA_BET;
      }
      else if (s[i] >= LOWEST_SIGN && s[i] <= HIGHEST_SIGN)
      {
        if (mod_k > 0)
        { s[i] = s[i] - NUM_OF_ALPHA_BET; }
        else
        { s[i] = s[i] + NUM_OF_ALPHA_BET; }

      }
      else if (s[i] - mod_k < LOWEST_SIGN && s[i] > HIGHEST_SIGN)
      {
        s[i] = s[i] - NUM_OF_ALPHA_BET;
      }
    }

  }

}

// See full documentation in header file
void decode (char s[], int k)
{
  unsigned int ln = strlen (s);
  int mod_k = k % NUM_OF_ALPHA_BET;
  for (int i = 0; i < ln; i++)
  {
    if (LOWEST_UPPERCASE < s[i] && s[i] < HIGHEST_LOWERCASE
        && (s[i] < LOWEST_SIGN ||
            s[i] > HIGHEST_SIGN))
    {
      s[i] = s[i] - mod_k;
      if (s[i] >= HIGHEST_LOWERCASE)
      {
        s[i] = s[i] - NUM_OF_ALPHA_BET;
      }
      else if (s[i] < LOWEST_UPPERCASE)
      {
        s[i] = s[i] + NUM_OF_ALPHA_BET;
      }
      else if (s[i] >= LOWEST_SIGN && s[i] <= HIGHEST_SIGN)
      {
        if (mod_k > 0)
        {
          s[i] = s[i] + NUM_OF_ALPHA_BET;
        }
        else
        {
          s[i] = s[i] - NUM_OF_ALPHA_BET;
        }

      }
      else if (s[i] - mod_k < LOWEST_SIGN && s[i] > HIGHEST_SIGN)
      {
        s[i] = s[i] - NUM_OF_ALPHA_BET;
      }
    }
  }
}
