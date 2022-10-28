#include "cipher.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// your code goes here

int main (int argc, char *argv[])
{
  if (argc != 5 && argc != 2)
  {
    fprintf (stderr, "The program receives 1 or 4 arguments only.\n");
    return EXIT_FAILURE;
  }
  else if (strcmp (argv[1], "test") != 0 && argc == 2)
  {
    fprintf (stderr, "Usage: cipher test\n");
    return EXIT_FAILURE;
  }
  else if (argc == 5 && strcmp (argv[1], "encode") != 0 && strcmp
                                                               (argv[1], "decode")
                                                           != 0)
  {
    fprintf (stderr, "The given command is invalid.\n");
    return EXIT_FAILURE;
  }
  else if (argc == 5)
  {
    int is_k_0 = 1;
    if (strcmp ("0", argv[2]) != 0)
    {
      is_k_0 = 0;
    }

    int new_k = atoi (argv[2]);
    if (new_k == 0)
    {
      fprintf (stderr, "The given shift value is invalid.\n");
      return EXIT_FAILURE;
    }
    else if (is_k_0 == 0)
    {
      new_k = 0;
    }
    FILE *in = fopen (argv[3], "r");
    FILE *out = fdopen (argv[4], "w");
    if (in == NULL || out == NULL)
    {
      fprintf (stderr, "The given file is invalid.\n");
    }
    //all good

    char line[1024];
    while (fgets (line, 1024, in))
    {
      if (strcmp (argv[1], "encode") == 0)
      {
        encode (line, new_k);
        fputs (line, out);
      }
      else if (strcmp (argv[1], "decode") == 0)
      {
        decode (line, new_k);
      }
    }
    if (strcmp (argv[1], "test") == 0)
    {
      if (test_encode_non_cyclic_lower_case_positive_k ()
          || test_encode_cyclic_lower_case_special_char_positive_k ()
          || test_encode_non_cyclic_lower_case_special_char_negative_k ()
          || test_encode_cyclic_lower_case_negative_k ()
          || test_encode_cyclic_upper_case_positive_k ()
          || test_decode_non_cyclic_lower_case_positive_k ()
          || test_decode_cyclic_lower_case_special_char_positive_k ()
          || test_decode_non_cyclic_lower_case_special_char_negative_k ()
          || test_decode_cyclic_lower_case_negative_k ()
          || test_decode_cyclic_upper_case_positive_k ())
      {
        return EXIT_FAILURE;
      }
      else
      {
        return EXIT_SUCCESS;
      }
    }
  }
  return EXIT_SUCCESS;
}



