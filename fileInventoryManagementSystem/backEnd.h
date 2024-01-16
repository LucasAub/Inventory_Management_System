#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

void PrintMenu(const char *directory)
{
    char input[10];
    int choice;

    while (1) 
    {
        printf("\n----------------\n");
        printf("File Management\n");
        printf("----------------\n");
        printf("\n1. Add File\n2. View File\n3. Search File\n4. Delete File\n5. Exit\n\nEnter your choice (Only Number): ");

        // Read input as a string
        fgets(input, 10, stdin);

        // Check if input is a number
        int isNumber = 1;
        for (int i = 0; i < strlen(input) - 1; i++)
        {
            if (!isdigit(input[i]))
            {
                isNumber = 0;
                break;
            }
        }

        if (isNumber)
        {
            choice = atoi(input);
        }
        else
        {
            printf("\nInvalid input. Please enter a number.\n");
            continue;
        }

        printf("\n----------------\n\n");

        switch (choice)
        {
        case 1:
            AddFile(directory);
            break;
        case 2:
            ViewFile(directory);
            break;
        case 3:
            SearchFile(directory);
            break;
        case 4:
            DeleteFile(directory);
            break;
        case 5:
            printf("Exit!\n");
            printf("\n----------------\n");
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}

void AddFile(const char *directory) {
    char filename[100];
    int id, quantity;
    float price;
    char productName[100];

    // Get details from the user
    printf("Enter product name: ");
    fgets(productName, 100, stdin);
    productName[strcspn(productName, "\n")] = 0; // Remove newline character

    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);
    getchar(); // Consume the newline character left by scanf

    // Create the file name based on product name
    sprintf(filename, "%s/%s.txt", directory, productName);

    // Create and open the file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create file.\n");
        return;
    }

    // Write the details to the file
    fprintf(file, "ID: %d\nProduct Name: %s\nQuantity: %d\nPrice: %.2f\n", id, productName, quantity, price);

    // Close the file
    fclose(file);
    printf("File '%s' created successfully.\n", filename);
}


void ViewFile(const char* directory) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory)) == NULL) {
        perror("opendir() error");
    } else {
        puts("Contents of directory:");
        while ((entry = readdir(dir)) != NULL) {
            printf("  %s\n", entry->d_name);
        }
        closedir(dir);
    }
}

void SearchFile(const char *directory) {
    char searchName[100];
    printf("Enter file name to search: ");
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    char filepath[150];
    sprintf(filepath, "%s/%s.txt", directory, searchName);

    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("File '%s' not found.\n", searchName);
        return;
    }

    printf("Contents of '%s':\n", searchName);
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}


void DeleteFile(const char* directory) {
    char filename[100];
    printf("Enter file name to delete: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    char filepath[150];
    sprintf(filepath, "%s/%s", directory, filename);

    if (remove(filepath) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }
}
