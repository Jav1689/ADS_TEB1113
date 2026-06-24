#include <iostream>

// size of matrix
#define M 3
#define N 3

using namespace std;

// function to rotate matrix by k times
void rotateMatrix(int matrix[][M], int k) {
    // temporary array of size M
    int temp[M];

    // within the size of matrix
    k = k % M;

    for (int i = 0; i < N; i++) {

        // copy first M-k elements to temporary array
        for (int t = 0; t < M - k; t++)
            temp[t] = matrix[i][t];

        // copy the elements from k to end to starting
        for (int j = M - k; j < M; j++)
            matrix[i][j - M + k] = matrix[i][j];

        // copy elements from temporary array to end
        for (int j = k; j < M; j++)
            matrix[i][j] = temp[j - k];
    }
}

// function to display the matrix
void displayMatrix(int matrix[][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// Driver's code
int main() {
    int matrix[N][M] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
    int k = 7;

    // rotate matrix by k
    rotateMatrix(matrix, k);

    // display rotated matrix
    displayMatrix(matrix);

    return 0;
}