// week5_task1_file_io.c
// Author: Mehmet Taha Ünal
// Student ID: 231AMB077
// Week 5 – Files & Modular Programming
// Task 1: File writing and reading example (custom version)

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fileptr;
    char fname[] = "data.txt";
    char buffer[200];

    // Write section
    fileptr = fopen(fname, "w");
    if (!fileptr) {
        fprintf(stderr, "Cannot create file: %s\n", fname);
        return EXIT_FAILURE;
    }

    printf(">>> Creating and writing to '%s'\n", fname);
    fprintf(fileptr, "C programming with files.\n");
    fprintf(fileptr, "Testing file writing using fprintf.\n");
    fprintf(fileptr, "End of text block.\n");
    fclose(fileptr);

    // Read section
    fileptr = fopen(fname, "r");
    if (!fileptr) {
        fprintf(stderr, "Cannot open file for reading: %s\n", fname);
        return EXIT_FAILURE;
    }

    printf("\n>>> Now displaying file content:\n");
    int line_no = 1;
    while (fgets(buffer, sizeof(buffer), fileptr) != NULL) {
        printf("[%d] %s", line_no++, buffer);
    }

    fclose(fileptr);
    printf("\n>>> Reading complete.\n");

    return EXIT_SUCCESS;
}
