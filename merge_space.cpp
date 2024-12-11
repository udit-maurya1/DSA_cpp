#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeSortedArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    // Start from the end of the first array and the beginning of the second array
    int i = n - 1, j = 0;

    // Swap elements if necessary to maintain the sorted order
    while (i >= 0 && j < m) {
        if (a[i] > b[j]) {
            swap(a[i], b[j]);
        }
        i--;
        j++;
    }

    // Sort both vectors to ensure they are in sorted order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main() {
    // Example input
    vector<int> a = {2, 4, 7, 10};
    vector<int> b = {2, 3};

    // Merge the arrays
    mergeSortedArrays(a, b);

    // Print the modified arrays
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    for (int num : b) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
