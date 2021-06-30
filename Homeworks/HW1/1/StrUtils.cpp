#include "./StrUtils.hpp"

unsigned int getStrLength(const char *str) {
  if (str == nullptr) {
    // Exception placeholder
    return 0;
  }

  unsigned int length = 0;
  while (str[length] != '\0') {
    ++length;
  }
  return length;
}

void strCopy(const char *src, char *dest) {
  if (src == nullptr) {
    // Exception placeholder
    return;
  }

  // Size validation is missing because
  // constructors are allocating enough size
  unsigned int srcLength = getStrLength(src);

  for (int char_i = 0; char_i < srcLength; ++char_i) {
    dest[char_i] = src[char_i];
  }
  dest[srcLength] = '\0';
}

/* Two strings are lexicographically equal if they are
 * the same length and contain the same characters in the same positions.
 * If both strings are lexicographically same result is 0.
 * Otherwise, result would be a positive or a negative number
 * depending on the lexicographical order
*/
int strCompare(const char *str1, const char *str2) {
  while ((*str1 != '\0' && *str2 != '\0') && (*str1 == *str2)) {
    ++str1;
    ++str2;
  }

  return *str1 - *str2;
}