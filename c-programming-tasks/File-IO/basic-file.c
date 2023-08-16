#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char input;
    char *buffer = NULL; // Initialize buffer pointer
    int size = 0, capacity = 0;

    /* Open file for both reading and writing */
    fp = fopen("greetings.txt", "w+");
    
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (scanf("%c", &input) == 1 && input != '0') {
        if (size == capacity) {
            capacity = capacity == 0 ? 1 : capacity * 2;
            buffer = realloc(buffer, capacity * sizeof(char));
         
        }

        buffer[size++] = input;
    }

    /* Write data to the file */
    fwrite(buffer, sizeof(char), size, fp);

    /* Seek to the beginning of the file */
    fseek(fp, 0, SEEK_SET);

    /* Read and display data */
    fread(buffer, sizeof(char), size, fp);
    printf("%.*s\n", size, buffer);

    fclose(fp);
    free(buffer);

    return 0;
}
