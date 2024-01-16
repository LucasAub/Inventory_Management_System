#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function to search for a file in a directory
void searchFile(const char *path, const char *fileName)
{
    // Open the directory
    DIR *dir = opendir(path);
    
    // Check if the directory was successfully opened
    if (!dir) {
        printf("Error: Unable to open directory.\n");
        return;
    }

    int found = 0;

    // Iterate over each file in the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if the file name matches the file to search for
        if (strcmp(entry->d_name, fileName) == 0) {
            found = 1;
            break;
        }
    }

    // Print the result based on whether the file was found or not
    if (found) {
        printf("File '%s' found in the directory.\n", fileName);
    } else {
        printf("File '%s' not found in the directory.\n", fileName);
    }

    // Close the directory
    closedir(dir);
}

int main(void)
{
    char fileName[BUFFER_SIZE]; // Buffer for the file name

    // Prompt user for file name
    printf("Enter the name of the file to search: ");
    if (fgets(fileName, sizeof(fileName), stdin) == NULL) {
        printf("Error: Unable to read file name.\n");
        return 1;
    }

    // Remove newline character from the file name
    fileName[strcspn(fileName, "\n")] = '\0';

    // Search for the specified file in the current directory
    searchFile(".", fileName);

    return 0;
}