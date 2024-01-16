#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h> // For directory manipulation

#include "backEnd.h"

void PrintMenu(const char *directory);
void AddFile(const char *directory);
void ViewFile(const char *directory);
void SearchFile(const char *directory);
void DeleteFile(const char *directory);

int main(void)
{
    const char *directory = "/fileFolder"; // Ensure this directory exists
    PrintMenu(directory);
    return EXIT_SUCCESS;
}

