#include <stdio.h>
#include <stdlib.h>

int main() {
    // Get the home directory path from the HOME environment variable
    const char *homeDir = getenv("HOME");

    // Check if the home directory path is retrieved successfully
    if (homeDir == NULL) {
        fprintf(stderr, "Error: Could not find the home directory.\n");
        return 1;
    }

    // Define the full path for the test file
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/testfile.txt", homeDir);

    // Create and open the file in write mode
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not create the file at %s\n", filePath);
        return 1;
    }

    // Write some test content to the file
    fprintf(file, "This is a test file.\n");

    // Close the file
    fclose(file);

    printf("File created successfully at %s\n", filePath);
    return 0;
}
