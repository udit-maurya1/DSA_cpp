#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element index
int peakElement(vector<int>& arr) {
    int n = arr.size();

    // Handle edge cases explicitly
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    // Binary search for peak element
    int left = 1, right = n - 2; // Skip first and last elements since they are handled above

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid is a peak element
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        // Move to the side that has a higher neighbor
        if (arr[mid - 1] > arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1; // This case should not occur if input guarantees at least one peak
}

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 4, 5, 7, 8, 3},
        {10, 20, 15, 2, 23, 90, 80},
        {1, 2, 3},
        {3, 2, 1},
        {1, 3, 20, 4, 1}
    };

    for (const auto& testCase : testCases) {
        int peakIndex = peakElement(const_cast<vector<int>&>(testCase));
        bool isValid = (peakIndex != -1 && 
                        (peakIndex == 0 || testCase[peakIndex] > testCase[peakIndex - 1]) &&
                        (peakIndex == testCase.size() - 1 || testCase[peakIndex] > testCase[peakIndex + 1]));
        cout << "Array: [ ";
        for (int num : testCase) cout << num << " ";
        cout << "]\n";
        cout << "Peak Index: " << peakIndex << "\n";
        cout << "Output: " << (isValid ? "true" : "false") << "\n\n";
    }

    return 0;
}
