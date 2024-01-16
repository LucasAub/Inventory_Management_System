#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void PrintMenu(char *input, int choice);

int main(void)
{
    char input[10];
    int choice;
    PrintMenu(&input, choice);
    return EXIT_SUCCESS;
}

void PrintMenu(char *input, int choice)
{
    while (1) 
    {
        printf("\n----------------\n");
        printf("File Management\n");
        printf("----------------\n");
        printf("\n1. Add File\n2. View File\n3. Search File\n4. Update File\n5. Delete File\n6. Exit\n\nEnter your choice (Only Number) : ");

        // Read input as a string
        fgets(input, 10, stdin);

        // Check if input is a number
        int isNumber = 1;
        for (int i = 0; i < strlen(input) - 1; i++)
        { // -1 to ignore newline character
            if (!isdigit(input[i]))
            {
                isNumber = 0;
                break;
            }
        }

        if (isNumber)
        {
            // Convert string to integer
            choice = atoi(input);
        }
        else
        {
            printf("\nInvalid input. Please enter a number.\n");
            continue;
        }

        printf("\n----------------\n");
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Add File:\n");
            break;
        case 2:
            printf("View File:\n");
            break;
        case 3:
            printf("Search File:\n");
            break;
        case 4:
            printf("Update File:\n");
            break;
        case 5:
            printf("Delete File:\n");
            break;
        case 6:
            printf("Exit !\n");
            printf("\n----------------\n");
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}