#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool hasPairWithTarget(const vector<int>& arr, int target) {
    unordered_map<int, int> seen; // Map to store seen elements and their indices.

    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];

        // Check if the complement exists in the map and is not the same index.
        if (seen.find(complement) != seen.end()) {
            return true;
        }

        // Add the current element to the map.
        seen[arr[i]] = i;
    }

    return false;
}

int main() {
    vector<int> arr1 = {1, 4, 45, 6, 10, 8};
    int target1 = 16;
    cout << (hasPairWithTarget(arr1, target1) ? "true" : "false") << endl;

    vector<int> arr2 = {1, 2, 4, 3, 6};
    int target2 = 11;
    cout << (hasPairWithTarget(arr2, target2) ? "true" : "false") << endl;

    vector<int> arr3 = {11};
    int target3 = 11;
    cout << (hasPairWithTarget(arr3, target3) ? "true" : "false") << endl;

    return 0;
}
