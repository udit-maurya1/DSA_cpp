#include <iostream>
#include <vector>
using namespace std;

// Function to rotate the matrix 90 degrees anti-clockwise
void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each column
    for (int j = 0; j < n; j++) {
        for (int i = 0, k = n - 1; i < k; i++, k--) {
            swap(mat[i][j], mat[k][j]);
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example input
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> mat2 = {
        {1, 2},
        {3, 4}
    };

    // Rotate and display the results
    cout << "Original Matrix 1:" << endl;
    printMatrix(mat1);
    rotateMatrix(mat1);
    cout << "Rotated Matrix 1:" << endl;
    printMatrix(mat1);

    cout << "Original Matrix 2:" << endl;
    printMatrix(mat2);
    rotateMatrix(mat2);
    cout << "Rotated Matrix 2:" << endl;
    printMatrix(mat2);

    return 0;
}
