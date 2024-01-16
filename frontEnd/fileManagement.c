#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <fileAdd.h>
#include <ListFiles.h>
#include <removeFile.h>

#define FILE_NUMBER 10

void PrintMenu(const char *directory);
void AddFile(const char* directory);
void ViewFile(const char* directory);
void SearchFile(const char* directory);
void UpdateFile(const char* directory);
void DeleteFile(const char* directory);

int main(void)
{
    const char *directory = "files"; // Ensure this directory exists
    PrintMenu(directory);
    return EXIT_SUCCESS;
}

void PrintMenu(const char *directory)
{
    char input[10];
    int choice;

    while (1) 
    {
        printf("\n----------------\n");
        printf("File Management\n");
        printf("----------------\n");
        printf("\n1. Add File\n2. View File\n3. Search File\n4. Update File\n5. Delete File\n6. Exit\n\nEnter your choice (Only Number): ");

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
            UpdateFile(directory);
            break;
        case 5:
            DeleteFile(directory);
            break;
        case 6:
            printf("Exit!\n");
            printf("\n----------------\n");
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}

void AddFile(const char* directory) {
    char filename[100];
    printf("Enter file name: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    char filepath[150];
    sprintf(filepath, "%s/%s", directory, filename);

    FILE* file = fopen(filepath, "w");
    if (file == NULL) {
        printf("Failed to create file.\n");
        return;
    }
    
    // Here, you can add more details to the file as needed
    fprintf(file, "File details here...\n");

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

void SearchFile(const char* directory) {
    char searchName[100];
    printf("Enter file name to search: ");
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline character

    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory)) == NULL) {
        perror("opendir() error");
    } else {
        int found = 0;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, searchName) == 0) {
                printf("File '%s' found.\n", searchName);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("File not found.\n");
        }
        closedir(dir);
    }
}

void UpdateFile(const char* directory) {
    char filename[100];
    printf("Enter file name to update: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    char filepath[150];
    sprintf(filepath, "%s/%s", directory, filename);

    // Check if the file exists
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        printf("File does not exist.\n");
        return;
    }
    fclose(file); // Close the file as we only wanted to check its existence

    // Open the file again, this time for writing (this will clear existing content)
    file = fopen(filepath, "w");
    if (file == NULL) {
        printf("Failed to open file for updating.\n");
        return;
    }

    // Get new content for the file
    printf("Enter new content for the file:\n");
    char content[1024]; // Adjust size as needed
    fgets(content, 1024, stdin);
    content[strcspn(content, "\n")] = 0; // Remove newline character

    // Write the new content to the file
    fprintf(file, "%s\n", content);

    fclose(file);
    printf("File '%s' updated successfully.\n", filename);
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