#include <iostream>
#include <vector>
using namespace std;

int findMin(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if the mid element is greater than the rightmost element
        if (arr[mid] > arr[right]) {
            // Minimum must be in the right half
            left = mid + 1;
        } else {
            // Minimum could be at mid or in the left half
            right = mid;
        }
    }

    // The left pointer will point to the minimum element
    return arr[left];
}

int main() {
    vector<int> arr1 = {5, 6, 1, 2, 3, 4};
    vector<int> arr2 = {3, 1, 2};

    cout << "The minimum element in arr1 is: " << findMin(arr1) << endl;
    cout << "The minimum element in arr2 is: " << findMin(arr2) << endl;

    // Additional test cases
    vector<int> arr3 = {2, 3, 4, 5, 6, 7, 1};
    vector<int> arr4 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr5 = {10};

    cout << "The minimum element in arr3 is: " << findMin(arr3) << endl;
    cout << "The minimum element in arr4 is: " << findMin(arr4) << endl;
    cout << "The minimum element in arr5 is: " << findMin(arr5) << endl;

    return 0;
}
