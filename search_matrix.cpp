#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size();    // Number of rows
    int m = mat[0].size(); // Number of columns

    // Start from the top-right corner
    int row = 0, col = m - 1;

    while (row < n && col >= 0) {
        if (mat[row][col] == x) {
            return true; // Element found
        } else if (mat[row][col] > x) {
            col--; // Move left
        } else {
            row++; // Move down
        }
    }

    return false; // Element not found
}

int main() {
    vector<vector<int>> mat1 = {{3, 30, 38}, {20, 52, 54}, {35, 60, 69}};
    int x1 = 62;

    vector<vector<int>> mat2 = {{18, 21, 27}, {38, 55, 67}};
    int x2 = 55;

    cout << (searchMatrix(mat1, x1) ? "true" : "false") << endl; // Output: false
    cout << (searchMatrix(mat2, x2) ? "true" : "false") << endl; // Output: true

    return 0;
}
