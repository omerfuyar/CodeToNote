#include <stdio.h>
#include <string.h>
#include "composer.c"

#define FILE_NAME_LENGTH 64
#define FILE_READ_BUFFER_LENGTH 512

int main(int argc, char **argv)
{
    if (argc < 1)
    {
        goto errArgs;
    }

    const char *inputFileName = argv[1];
    const size_t inputFileLen = strlen(inputFileName);

    if (strncmp(inputFileName + inputFileLen - 2, ".c", 2) != 0)
    {
        goto errFileType;
    }

    FILE *codeFile = fopen(inputFileName, "r");

    if (codeFile == NULL)
    {
        goto errFile;
    }

    char outputFileName[FILE_NAME_LENGTH] = {0};
    snprintf(outputFileName, FILE_NAME_LENGTH, "%.*s.musicxml", inputFileLen - 1, inputFileName);

    FILE *musicFile = fopen(outputFileName, "w+");

    if (musicFile == NULL)
    {
        fclose(codeFile);
        goto errFile;
    }

    int result = composeFile(codeFile, musicFile);

    if (result != 0)
    {
        fprintf(stderr, "Error : Composing code to music file : %d", result);
        fclose(codeFile);
        fclose(musicFile);
        return result;
    }

    fclose(codeFile);
    fclose(musicFile);

    printf("Successfully created music notation %s.", outputFileName);
    return 0;

errArgs:
    fprintf(stderr, "Error : Enter one input file name to create musicxml.");
    return 1;

errFileType:
    fprintf(stderr, "Error : Enter a input file that is a type of C source code.");
    return 2;

errFile:
    fprintf(stderr, "Error : Reading or writing a file. Be sure your input file exists or not.");
    return 3;
}