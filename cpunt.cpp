#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countPairs(vector<int> &arr, int target) {
    unordered_map<int, int> freqMap;
    int count = 0;

    // Traverse through the array
    for (int num : arr) {
        // Check if the complement exists in the map
        int complement = target - num;
        if (freqMap.find(complement) != freqMap.end()) {
            count += freqMap[complement];
        }

        // Update the frequency map
        freqMap[num]++;
    }

    return count;
}

int main() {
    vector<int> arr1 = {1, 5, 7, -1, 5};
    int target1 = 6;
    cout << "Output: " << countPairs(arr1, target1) << endl;

    vector<int> arr2 = {1, 1, 1, 1};
    int target2 = 2;
    cout << "Output: " << countPairs(arr2, target2) << endl;

    vector<int> arr3 = {10, 12, 10, 15, -1};
    int target3 = 125;
    cout << "Output: " << countPairs(arr3, target3) << endl;

    return 0;
}
