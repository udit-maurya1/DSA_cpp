#include <iostream>
#include <vector>

bool searchInMatrix(const std::vector<std::vector<int>>& mat, int x) {
    if (mat.empty() || mat[0].empty()) {
        return false; // Handle empty matrix case
    }

    int n = mat.size();      // Number of rows
    int m = mat[0].size();   // Number of columns

    for (int i = 0; i < n; i++) {
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow
            if (mat[i][mid] == x) {
                return true; // Element found
            } else if (mat[i][mid] < x) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
    }

    return false; // Element not found
}

int main() {
    // Define test cases
    std::vector<std::pair<std::vector<std::vector<int>>, int>> testCases = {
        {{{3, 4, 9}, {2, 5, 6}, {9, 25, 27}}, 9},
        {{{19, 22, 27, 38, 55, 67}}, 56},
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 5},
        {{{10, 20, 30}, {15, 25, 35}, {27, 29, 37}}, 29},
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 10} // Not present
    };

    // Iterate through each test case
    for (const auto& testCase : testCases) {
        const auto& mat = testCase.first;
        int x = testCase.second;

        if (searchInMatrix(mat, x)) {
            std::cout << "Output: true for x = " << x << std::endl;
        } else {
            std::cout << "Output: false for x = " << x << std::endl;
        }
    }

    return 0;
}