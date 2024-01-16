#include <stdio.h>
#include <stdlib.h>
#include<dirent.h>

void listFiles(const char *path)
{
    struct dirent *dp;
    DIR *dir = opendir(path);

    if (!dir){
        // Unable to open directory
        printf("Error: Unable to open directory.\n");
        return 0;
    }

    while ((dp = readdir(dir)) != NULL){
        printf("%s\n", dp->d_name);
    }

    closedir(dir);
}

int main(void)
{
    FILE *fptr;

    // Create a file
    fptr = fopen("test.txt", "w");

    // Close the file
    fclose(fptr);

    // List files in the current directory
    printf("Files in the current directory:\n");
    listFiles(".");

    return 0;
}