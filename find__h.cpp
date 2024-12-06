#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateHIndex(vector<int>& citations) {
    // Step 1: Sort the citations in descending order
    sort(citations.begin(), citations.end(), greater<int>());

    // Step 2: Find the maximum H-Index
    int hIndex = 0;
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] >= i + 1) {
            hIndex = i + 1;
        } else {
            break;
        }
    }

    return hIndex;
}

int main() {
    // Test case 1
    vector<int> citations1 = {3, 0, 5, 3, 0};
    cout << "H-Index: " << calculateHIndex(citations1) << endl;

    // Test case 2
    vector<int> citations2 = {5, 1, 2, 4, 1};
    cout << "H-Index: " << calculateHIndex(citations2) << endl;

    return 0;
}