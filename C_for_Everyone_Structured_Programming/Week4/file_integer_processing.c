#include <stdio.h>

#define MAX_SIZE 100

int main() {
    FILE *file;
    int size, i;
    int data[MAX_SIZE];
    int sum = 0, max = 0;
    double average;

    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the first integer to determine the size of the array
    fscanf(file, "%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        fclose(file);
        return 1;
    }

    // Read the integers into the array and compute sum and max
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &data[i]);
        sum += data[i];
        if (data[i] > max) {
            max = data[i];
        }
    }

    // Compute the average
    average = (double)sum / size;

    // Close the file
    fclose(file);

    // Print the result to the screen
    printf("Array size: %d\n", size);
    printf("Array elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Average: %.2f\n", average);
    printf("Max: %d\n", max);

    // Open the output file for writing
    file = fopen("answer-hw3.txt", "w");
    if (file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write the result to the output file
    fprintf(file, "Array size: %d\n", size);
    fprintf(file, "Array elements: ");
    for (i = 0; i < size; i++) {
        fprintf(file, "%d ", data[i]);
    }
    fprintf(file, "\n");
    fprintf(file, "Average: %.2f\n", average);
    fprintf(file, "Max: %d\n", max);

    // Close the output file
    fclose(file);

    return 0;
}
