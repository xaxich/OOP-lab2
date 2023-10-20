#include <iostream>  
#include <ctime>  
#include <cstdlib>  
#include <string> 

int M, N;

void printMatrix(int** matrix) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %-2d ", matrix[i][j]);
        }
        std::cout << '\n';
    }
    std::cout << std::string(N * 4, '-') << '\n';
}

void createMatrix(int** matrix) {
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {
    std::cout << "Enter M,N" << "\n";
    std::cin >> M >> N;
    srand(time(0));
    int** matrix = new int* [M];
    createMatrix(matrix);
    printMatrix(matrix);

    int* B = new int[M];

    for (int i = 0; i < M; i++) {
        B[i] = 1;

        for (int j = 1; j < N; j++) {
            if (matrix[i][j] >= matrix[i][j - 1]) {
                B[i] = 0;
                break;
            }
        }
    }

    std::cout << "massive B: ";
    for (int i = 0; i < M; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;
    delete[] B;

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}