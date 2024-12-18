#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int findPages(vector<int> &arr, int k) {
    int n = arr.size();
    if (k > n) {
        return -1; // Not enough books to allocate
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int studentsRequired = 1;
        int currentPages = 0;
        bool isValid = true;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                isValid = false;
                break; // A single book has more pages than mid
            }

            if (currentPages + arr[i] > mid) {
                studentsRequired++;
                currentPages = arr[i];

                if (studentsRequired > k) {
                    isValid = false;
                    break;
                }
            } else {
                currentPages += arr[i];
            }
        }

        if (isValid) {
            result = mid;
            high = mid - 1; // Try for a smaller maximum
        } else {
            low = mid + 1; // Increase the maximum
        }
    }

    return result;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;

    cout << "Minimum of the maximum pages: " << findPages(arr, k) << endl;

    vector<int> arr2 = {15, 17, 20};
    k = 5;

    cout << "Minimum of the maximum pages: " << findPages(arr2, k) << endl;

    return 0;
}
