#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // Sort the intervals based on their end time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int count = 0; // To count the number of overlapping intervals
    int prevEnd = intervals[0][1]; // The end time of the previous interval

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < prevEnd) {
            // Overlap detected, increment the count
            count++;
        } else {
            // Update the end time of the last non-overlapping interval
            prevEnd = intervals[i][1];
        }
    }

    return count;
}

int main() {
    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> intervals2 = {{1, 3}, {1, 3}, {1, 3}};
    vector<vector<int>> intervals3 = {{1, 2}, {5, 10}, {18, 35}, {40, 45}};

    cout << "Output 1: " << eraseOverlapIntervals(intervals1) << endl;
    cout << "Output 2: " << eraseOverlapIntervals(intervals2) << endl;
    cout << "Output 3: " << eraseOverlapIntervals(intervals3) << endl;

    return 0;
}
