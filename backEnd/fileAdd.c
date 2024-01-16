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
    fptr = fopen("/Inventory_Management_System/data/test.txt", "w");

    // Close the file
    fclose(fptr);
    return 0;
}