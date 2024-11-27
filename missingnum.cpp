#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the smallest missing positive number
int findMissingPositive(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Segregate positive numbers and non-positive numbers
    int j = 0; // Pointer for segregation
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    // Now arr[j...n-1] contains all positive numbers
    int size = n - j;

    // Step 2: Mark indices corresponding to the values as visited
    for (int i = j; i < n; i++) {
        int absVal = abs(arr[i]);
        if (absVal - 1 < size && arr[j + absVal - 1] > 0) {
            arr[j + absVal - 1] = -arr[j + absVal - 1];
        }
    }

    // Step 3: Find the first positive index which is unmarked
    for (int i = j; i < n; i++) {
        if (arr[i] > 0) {
            return i - j + 1;
        }
    }

    // If all indices are marked, the missing number is size + 1
    return size + 1;
}

// Main function
int main() {
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    int missing = findMissingPositive(arr);
    cout << "The smallest missing positive number is: " << missing << endl;
    return 0;
}
