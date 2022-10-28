#include "cipher.h"
#include <string.h>
#include <stdio.h>
/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.


// See full documentation in header file
void encode (char s[], int k)
{
  int mod_k = k % 26;
  unsigned int ln = strlen (s);
  for (int i = 0; i < ln; i++)
  {
    if (64 < s[i] && s[i] < 123 && (s[i] < 91 || s[i] > 96))
    {
      s[i] = s[i] + mod_k;
      if (s[i] >= 123)
      {
        s[i] = s[i] - 26;
      }
      else if (s[i] < 65)
      {
        s[i] = s[i] + 26;
      }
      else if (s[i] >= 91 && s[i] <= 96)
      {
        if (mod_k > 0)
        { s[i] = s[i] - 26; }
        else
        { s[i] = s[i] + 26; }

      }
      else if (s[i] - mod_k < 91 && s[i] > 96)
      {
        s[i] = s[i] - 26;
      }
    }

  }

}

// See full documentation in header file
void decode (char s[], int k)
{
  unsigned int ln = strlen (s);
  int mod_k = k % 26;
  for (int i = 0; i < ln; i++)
  {
    if (64 < s[i] && s[i] < 123 && (s[i] < 91 || s[i] > 96))
    {
      s[i] = s[i] - mod_k;
      if (s[i] >= 123)
      {
        s[i] = s[i] - 26;
      }
      else if (s[i] < 65)
      {
        s[i] = s[i] + 26;
      }
      else if (s[i] >= 91 && s[i] <= 96)
      {
        if (mod_k > 0)
        {
          s[i] = s[i] + 26;
        }
        else
        {
          s[i] = s[i] - 26;
        }

      }
      else if (s[i] - mod_k < 91 && s[i] > 96)
      {
        s[i] = s[i] - 26;
      }
    }
  }
}
