#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "util.h"

struct alias_list *aliases = NULL;


/*
 * Pre-process one given line of the input file by writing the desired output
 * to stdout (use printf), and any errors to stderr (use pr_error).
 *
 * TODO Current dummy implementation only handles whitespace.
 * Your job is to implement the desired preprocessing functionality, as
 * described in the assignment PDF.
 *
 */
void process_line(char *line)
{

    char *token = strtok(line, " \t");

    while (token)
    {
        if (token[strlen(token)-1] == '\n') {
             printf("%s", token);
        }
        else
	{
             printf("%s ", token);
        }

        token = strtok(NULL, " \t");
    }

}

/*
 * Process a single-char "-C" command line option.
 *
 * TODO add your own single-char options here
 *  (e.g., "-v" for printing author and version information)
 */
void option(char c)
{
    switch (c) 
    {
        case 'h':
            printf("cpp-iw: The awesome IW C preprocessor\n");
            printf("\nUsage: cpp-iw [-h -e] file.c\n");
            printf("\nRecognized options:\n");
            printf("-h\tdisplay this help message\n");
            printf("-e\tterminate preprocessing on #error\n");
            exit(0);
            break;
        default:
            pr_error("Unrecognized option '%c'\n", c);
            exit(1);
    }
}

int main(int argc, char *argv[])
{
    int i;
    char *s;

    /* Process command line options */
	for (i = 1; i < argc && *argv[i] == '-'; i++)
        option(*(argv[i]+1));

    if (argv[i] == NULL)
    {
        pr_error("No input C file provided\n");
        return 1;
    }

    /* Open the input file */
    if ( infile_open(argv[i]) )
    {
        pr_error("Could not open input file '%s'\n", argv[i]);
        return 1;
    }

    /* First pass the list test suite (make sure to add your own tests!) */
	if (alias_list_test() == 0)
        return 1;

    /* Do the actual preprocessing work line by line */
    aliases = alias_list_create();

    while ((s = infile_getline()))
    {
        process_line(s);
    }

    infile_close();
	return 0;
}
