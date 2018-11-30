#ifndef UTIL_H_INC
#define UTIL_H_INC

#include <stdarg.h>

/*
 * Use this function to print on the stderror shell output stream (pass
 * arguments and format string just like with normal printf).
 */
void pr_error(const char *fmt, ...);

/*
 * Open the input file with C source code.
 *
 * Returns non-zero value on failure.
 */
int infile_open(char *path);

/*
 * Read one line of input from the infile.
 *
 * Returns NULL on error, or if all lines have been read.
 */
char *infile_getline(void);

/*
 * Close the input file before exiting the program.
 */
void infile_close(void);

#endif
