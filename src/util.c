#include <stdio.h>
#include "util.h"

/*
 * The C standard requires a minimum of 4096 characters on a logical source
 * line be permitted.
 * 
 * https://gcc.gnu.org/onlinedocs/cpp/Implementation-limits.html
 */
#define MAX_LINE_SIZE       4096

FILE *__infile = NULL;
char __line_buffer[MAX_LINE_SIZE];

void pr_error(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap); 
}

int infile_open(char *path)
{
    __infile = fopen(path, "r");
    return (__infile == NULL);
}

char *infile_getline(void)
{
    return fgets(__line_buffer, MAX_LINE_SIZE, __infile);
}

void infile_close(void)
{
    if (__infile)
        fclose(__infile);
}
