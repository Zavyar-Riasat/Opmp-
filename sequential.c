#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10000
#define COLS 10000

void sequential_matrix_vector_addition(float matrix[ROWS][COLS], const float vector[COLS], float result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix[i][j] + vector[j];
        }
    }
}

int main() {
    float matrix[ROWS][COLS];
    float result[ROWS][COLS];
    float vector[COLS];

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

    return 0;
}
