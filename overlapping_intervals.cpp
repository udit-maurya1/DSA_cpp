#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // If the intervals list is empty, return an empty list
    if (intervals.empty()) return {};

    // Sort intervals based on the start time
    sort(intervals.begin(), intervals.end());

    // Vector to store the merged intervals
    vector<vector<int>> merged;

    // Initialize the first interval
    merged.push_back(intervals[0]);

    // Traverse through the intervals
    for (size_t i = 1; i < intervals.size(); i++) {
        // Get the last interval in the merged list
        vector<int>& last = merged.back();

        // If the current interval overlaps with the last interval, merge them
        if (intervals[i][0] <= last[1]) {
            last[1] = max(last[1], intervals[i][1]);
        } else {
            // Otherwise, add the current interval as a new interval
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {
    // Example 1
    vector<vector<int>> intervals1 = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    vector<vector<int>> result1 = mergeIntervals(intervals1);
    cout << "Merged intervals (Example 1): ";
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> intervals2 = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    vector<vector<int>> result2 = mergeIntervals(intervals2);
    cout << "Merged intervals (Example 2): ";
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
