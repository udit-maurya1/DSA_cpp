#include <iostream>
#include <vector>

using namespace std;

// Function to merge two halves and count inversions
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = 0;       // Starting index to be sorted
    int invCount = 0;

    vector<int> temp(right - left + 1); // Temporary array

    // Merge the two halves while counting inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // There are mid - i inversions, because all remaining elements in the left subarray
            // (arr[i], arr[i+1], ..., arr[mid]) are greater than arr[j]
            invCount += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray back to the original array
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return invCount;
}

// Function to use merge sort and count inversions
int mergeSortAndCount(vector<int>& arr, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, left, mid);   // Count inversions in left half
        invCount += mergeSortAndCount(arr, mid + 1, right); // Count inversions in right half
        invCount += mergeAndCount(arr, left, mid, right); // Count inversions while merging
    }
    return invCount;
}

// Main function to count inversions in the array
int inversionCount(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

// Example usage
int main() {
    vector<int> arr1 = {2, 4, 1, 3, 5};
    cout << "Inversion Count for arr1: " << inversionCount(arr1) << endl; // Output: 3

    vector<int> arr2 = {2, 3, 4, 5, 6};
    cout << "Inversion Count for arr2: " << inversionCount(arr2) << endl; // Output: 0

    return 0;
}