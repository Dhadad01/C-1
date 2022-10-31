#include "tests.h"
#include <string.h>
#define BIGGER_THAN_26_K 29
#define K_1 3


// See full documentation in header file
int test_encode_non_cyclic_lower_case_positive_k ()
{
  char in[] = "abde";
  char out[] = "degh";
  encode (in, K_1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_encode_cyclic_lower_case_special_char_positive_k ()
{
    char in[] = "xyz";
    char out[] = "abc";
    encode (in, 3);
    return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_encode_non_cyclic_lower_case_special_char_negative_k ()
{
    char in[] = "xyz!";
    char out[] = "vwx!";
    encode (in, -2);
    return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_encode_cyclic_lower_case_negative_k ()
{
    char in[] = "abc";
    char out[] = "xyz";
    encode (in, -3);
    return strcmp (in, out) != 0;

}

// See full documentation in header file
int test_encode_cyclic_upper_case_positive_k ()
{
    char in[] = "XYZA";
    char out[] = "ABCD";
    encode (in, BIGGER_THAN_26_K);
    return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_non_cyclic_lower_case_positive_k ()
{
  char in[] = "degh";
  char out[] = "abde";
  decode (in, K_1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "abc!";
  char out[] = "yza!";
  decode (in, 2);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "abc!";
  char out[] = "bcd!";
  decode (in, -1);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_cyclic_lower_case_negative_k ()
{
  char in[] = "xyza";
  char out[] = "abcd";
  decode (in, -3);
  return strcmp (in, out) != 0;
}

// See full documentation in header file
int test_decode_cyclic_upper_case_positive_k ()
{
  char in[] = "ABC!";
  char out[] = "XYZ!";
  decode (in, BIGGER_THAN_26_K);
  return strcmp (in, out) != 0;
}
