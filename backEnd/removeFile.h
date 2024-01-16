#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fptr;

    // Delete the file
    fptr = fopen("test.txt", "w");
    fclose(fptr);
    remove("test.txt");
}