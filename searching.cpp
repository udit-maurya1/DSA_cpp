#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArray(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid is the key
        if (arr[mid] == key) {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[left] <= arr[mid]) {
            // Check if the key lies in the left half
            if (key >= arr[left] && key < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else { // Right half must be sorted
            // Check if the key lies in the right half
            if (key > arr[mid] && key <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1; // Key not found
}

int main() {
    vector<int> arr1 = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key1 = 3;
    cout << "Index of " << key1 << ": " << searchInRotatedArray(arr1, key1) << endl;

    vector<int> arr2 = {3, 5, 1, 2};
    int key2 = 6;
    cout << "Index of " << key2 << ": " << searchInRotatedArray(arr2, key2) << endl;

    vector<int> arr3 = {33, 42, 72, 99};
    int key3 = 42;
    cout << "Index of " << key3 << ": " << searchInRotatedArray(arr3, key3) << endl;

    return 0;
}
