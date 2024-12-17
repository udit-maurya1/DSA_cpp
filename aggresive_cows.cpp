#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestMinDistance(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end()); // Sort stalls in ascending order
    
    int low = 1; // Minimum possible distance
    int high = stalls[stalls.size() - 1] - stalls[0]; // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Middle distance
        int cowsPlaced = 1, lastPosition = stalls[0]; // Place the first cow

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= mid) {
                cowsPlaced++; // Place the next cow
                lastPosition = stalls[i];
            }
        }

        if (cowsPlaced >= k) { // If all cows are placed successfully
            result = mid; // Update result
            low = mid + 1; // Search for a larger minimum distance
        } else {
            high = mid - 1; // Reduce the search space
        }
    }

    return result;
}

int main() {
    // Test cases
    vector<int> stalls1 = {1, 2, 4, 8, 9};
    int k1 = 3;
    cout << "Output: " << largestMinDistance(stalls1, k1) << endl;

    vector<int> stalls2 = {10, 1, 2, 7, 5};
    int k2 = 3;
    cout << "Output: " << largestMinDistance(stalls2, k2) << endl;

    vector<int> stalls3 = {2, 12, 11, 3, 26, 7};
    int k3 = 5;
    cout << "Output: " << largestMinDistance(stalls3, k3) << endl;

    return 0;
}
