// product ID 
// name
// qty 
// price

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fptr;

    // Create a file
    fptr = fopen("test.txt", "w");

    // Close the file
    fclose(fptr);
    return 0;
}