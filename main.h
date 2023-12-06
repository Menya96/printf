#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024


int _printf(const char *format,...);
int binary(int num);
int octal(int num);

#endif