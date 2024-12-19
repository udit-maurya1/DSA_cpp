#include <iostream>
#include <vector>
using namespace std;

// Function to find the k-th missing positive number
int findKthMissing(vector<int>& arr, int k) {
    int missingCount = 0;  // Counter for missing numbers
    int current = 1;      // Start checking from 1
    int index = 0;        // Index to iterate through the array
    
    while (true) {
        if (index < arr.size() && arr[index] == current) {
            // If current number is in the array, move to the next number
            index++;
        } else {
            // If current number is missing, increment missing count
            missingCount++;
            if (missingCount == k) {
                return current; // Found the k-th missing number
            }
        }
        current++; // Move to the next number
    }
}

int main() {
    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << "Output: " << findKthMissing(arr1, k1) << endl; // Expected Output: 9

    vector<int> arr2 = {1, 2, 3};
    int k2 = 2;
    cout << "Output: " << findKthMissing(arr2, k2) << endl; // Expected Output: 5

    vector<int> arr3 = {3, 5, 9, 10, 11, 12};
    int k3 = 2;
    cout << "Output: " << findKthMissing(arr3, k3) << endl; // Expected Output: 2

    return 0;
}
