#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int x) {
    if (mat.empty() || mat[0].empty()) {
        return false;
    }

    int n = mat.size();
    int m = mat[0].size();
    int left = 0, right = n * m - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int row = mid / m;
        int col = mid % m;

        if (mat[row][col] == x) {
            return true;
        } else if (mat[row][col] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> mat1 = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x1 = 14;
    cout << (searchMatrix(mat1, x1) ? "true" : "false") << endl; // Output: true

    vector<vector<int>> mat2 = {{1, 5, 9, 11}, {14, 20, 21, 26}, {30, 34, 43, 50}};
    int x2 = 42;
    cout << (searchMatrix(mat2, x2) ? "true" : "false") << endl; // Output: false

    vector<vector<int>> mat3 = {{87, 96, 99}, {101, 103, 111}};
    int x3 = 101;
    cout << (searchMatrix(mat3, x3) ? "true" : "false") << endl; // Output: true

    return 0;
}
