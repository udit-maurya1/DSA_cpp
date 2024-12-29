#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> findIntersection(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> setA(a.begin(), a.end());
    unordered_set<int> result;

    for (int num : b) {
        if (setA.find(num) != setA.end()) {
            result.insert(num);
        }
    }

    return vector<int>(result.begin(), result.end());
}

int main() {
    // Example input
    vector<int> a = {1, 2, 1, 3, 1};
    vector<int> b = {3, 1, 3, 4, 1};

    vector<int> intersection = findIntersection(a, b);

    // Sort the result before printing
    sort(intersection.begin(), intersection.end());

    // Print the output
    cout << "[";
    for (size_t i = 0; i < intersection.size(); ++i) {
        cout << intersection[i];
        if (i < intersection.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
