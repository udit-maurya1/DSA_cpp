#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to implement Kadane's algorithm
int kadane(const vector<int>& arr) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];

    for (size_t i = 1; i < arr.size(); i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

// Function to find the maximum circular subarray sum
int maxCircularSubarraySum(const vector<int>& arr) {
    // Step 1: Find the maximum subarray sum using Kadane's algorithm
    int max_kadane = kadane(arr);

    // Step 2: Find the total sum of the array and the minimum subarray sum
    int total_sum = 0;
    int min_ending_here = arr[0];
    int min_so_far = arr[0];

    for (size_t i = 0; i < arr.size(); i++) {
        total_sum += arr[i];
        min_ending_here = min(arr[i], min_ending_here + arr[i]);
        min_so_far = min(min_so_far, min_ending_here);
    }

    // Step 3: Calculate the maximum circular subarray sum
    int max_circular = total_sum - min_so_far; // min_so_far is negative, so we effectively add it

    // Step 4: Return the maximum of the two
    return max(max_kadane, max_circular);
}

int main() {
    vector<int> arr = {8, -1, 3, 4};
    int result = maxCircularSubarraySum(arr);
    cout << "Maximum Circular Subarray Sum: " << result << endl;
    return 0;
}