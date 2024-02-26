#include "include/io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* get_file_contents(const char* filepath)
{
    const char* extension = strrchr(filepath, '.');

    if(extension && strcmp(extension, ".syn") == 0)
    {
        char* buffer = 0;
        long length;

        FILE* f = fopen(filepath, "r");

        if(f)
        {
            fseek(f, 0, SEEK_END);
            length = ftell(f);
            fseek(f, 0, SEEK_SET);

            buffer = calloc(length, length);

            if (buffer)
            {
                fread(buffer, 1, length, f);
            }

            fclose(f);
            return buffer;
        }

        printf("Error reading file %s\n", filepath);
        exit(2);
    }
    printf("Error: %s is not a Syn file\n", filepath);
    exit(3);
}