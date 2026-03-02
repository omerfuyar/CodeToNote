#include <stdio.h>

#define KEYWORD_TABLE \
    KEYWORD_ENTRY(if, "")

#define KEYWORD_ENTRY(a, b) KEYWORD_##a,
enum
{
    KEYWORD_TABLE
        KEYWORD_COUNT
};
#undef KEYWORD_ENTRY

int composeFile(FILE *inputFile, FILE *outputFile)
{
    return 0;
}
