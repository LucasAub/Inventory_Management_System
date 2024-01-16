#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
    int choice;
    while(1)
        {
            printf("\n");
            printf("----------------\n");
            printf("File Management\n");
            printf("----------------\n");
            printf("\n1. Add File\n2. View File\n3. Search File\n4. Update File\n5. Delete File\n6. Exit\n\nEnter your choice: ");
            scanf("%d", &choice);
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
                break;
            }
        }
}