#pragma once

#include <stddef.h>
#include <stdbool.h>


#define EOF (-1)


int puts(const char* str);
static bool print(const char* data, size_t length);
int printf(const char* restrict format, ...);
