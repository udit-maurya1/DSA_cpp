#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    bool firstRow = false, firstCol = false;

    // Check if the first row or first column has any zero
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstCol = true;
            break;
        }
    }
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            firstRow = true;
            break;
        }
    }

    // Use the first row and first column to mark zeros
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set matrix cells to zero based on markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle the first row and first column
    if (firstRow) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (firstCol) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    setZeroes(mat);

    // Output the modified matrix
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
