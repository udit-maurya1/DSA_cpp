#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mat) {
    vector<int> result;
    if (mat.empty() || mat[0].empty()) {
        return result;
    }

    int top = 0, bottom = mat.size() - 1;
    int left = 0, right = mat[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; ++i) {
            result.push_back(mat[top][i]);
        }
        ++top;

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; ++i) {
            result.push_back(mat[i][right]);
        }
        --right;

        // Traverse from right to left along the bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                result.push_back(mat[bottom][i]);
            }
            --bottom;
        }

        // Traverse from bottom to top along the left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                result.push_back(mat[i][left]);
            }
            ++left;
        }
    }

    return result;
}

// Example usage
int main() {
    vector<vector<int>> mat1 = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};

    vector<int> result1 = spiralOrder(mat1);
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    vector<vector<int>> mat2 = {{1, 2, 3, 4, 5, 6},
                                {7, 8, 9, 10, 11, 12},
                                {13, 14, 15, 16, 17, 18}};

    vector<int> result2 = spiralOrder(mat2);
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    vector<vector<int>> mat3 = {{32, 44, 27, 23},
                                {54, 28, 50, 62}};

    vector<int> result3 = spiralOrder(mat3);
    for (int val : result3) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
