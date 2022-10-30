#include "cipher.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE_LINE 1024
#define NUM_OF_ARGS 5
// your code goes here

int main (int argc, char *argv[])
{
  if (argc != NUM_OF_ARGS && argc != 2)
  {
    fprintf (stderr,"The program receives 1 or 4 arguments only.\n");
    return EXIT_FAILURE;
  }
  else if (strcmp (argv[1], "test") != 0 && argc == 2)
  {
    fprintf (stderr, "Usage: cipher test\n");
    return EXIT_FAILURE;
  }
  else if
      (argc == NUM_OF_ARGS && strcmp (argv[1], "encode") != 0 && strcmp

                                              (argv[1], "decode")
                                                                 != 0)
  {
    fprintf (stderr, "The given command is invalid.\n");
    return EXIT_FAILURE;
  }
  else if (argc == NUM_OF_ARGS)
  {

    char *end;
    int new_k = strtol (argv[2], &end,10);
    if (strcmp (end,"")!=0){
      fprintf (stderr, "The given shift value is invalid.\n");
      return EXIT_FAILURE;
    }

    FILE *in = fopen (argv[3], "r");
    FILE *out = fopen (argv[4], "w");
    if (in == NULL || out == NULL)
    {
      fprintf (stderr, "The given file is invalid.\n");
    }
    //all good
    char line[MAX_SIZE_LINE];
    while (fgets (line, MAX_SIZE_LINE, in))
    {
      if (strcmp (argv[1], "encode") == 0)
      {
        encode (line, (int) new_k);
        fputs (line, out);
      }
      else if (strcmp (argv[1], "decode") == 0)
      {
        decode (line, (int) new_k);
        fputs (line, out);
      }
    }
    fclose (in);
    fclose (out);
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
        || test_decode_cyclic_upper_case_positive_k ()!=0)
    {
      return EXIT_FAILURE;
    }
    else
    {
      return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}


