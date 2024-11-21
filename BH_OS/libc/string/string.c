
#include <string.h>

size_t strlen(const char* str)
{
    size_t len = 0;
    while(str[len])
        len++;
    return len;
}

int strcmp(const char* str1, const char* str2)
{
  int i;
  for (i = 0; str1[i] == str2[i]; i++) {
    if (str1[i] == '\0') return 0;
  }
  return str1[i] - str2[i];
} 

void itoa(int n, char str[]) {
  int i, sign;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    str[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) str[i++] = '-';
  str[i] = '\0';

  reverse(str);
}

void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void append(char s[], char n) {
  int len = strlen(s);
  s[len] = n;
  s[len+1] = '\0';
}

int backspace(char s[]) {
  int len = strlen(s);
  if(len > 0)
  {
    s[len-1] = '\0';
    return 1;
  }
  return 0;
}

