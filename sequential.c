#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10000
#define COLS 10000

void sequential_matrix_vector_addition(float **matrix, const float *vector, float **result) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[j][i] = matrix[j][i] + vector[j];
        }
    }
}

int main() {
    float **matrix = (float **)malloc(ROWS * sizeof(float *));
    float **result = (float **)malloc(ROWS * sizeof(float *));
    float *vector = (float *)malloc(COLS * sizeof(float));

    if (matrix == NULL || vector == NULL || result == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (float *)malloc(COLS * sizeof(float));
        result[i] = (float *)malloc(COLS * sizeof(float));
    }

    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (float)(rand() % 100);
        }
    }

    for (int j = 0; j < COLS; j++) {
        vector[j] = (float)(rand() % 100);
    }

    double start_seq = clock();
    sequential_matrix_vector_addition(matrix, vector, result);
    double end_seq = clock();

    printf("Sequential Execution Time: %f seconds\n", (end_seq - start_seq) / CLOCKS_PER_SEC);

    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);
    free(vector);

    return 0;
}
