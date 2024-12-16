#include <iostream>
#include <vector>
using namespace std;

int findKthElement(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    int m = b.size();

    int i = 0, j = 0, count = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            count++;
            if (count == k) {
                return a[i];
            }
            i++;
        } else {
            count++;
            if (count == k) {
                return b[j];
            }
            j++;
        }
    }

    // If elements are left in array a
    while (i < n) {
        count++;
        if (count == k) {
            return a[i];
        }
        i++;
    }

    // If elements are left in array b
    while (j < m) {
        count++;
        if (count == k) {
            return b[j];
        }
        j++;
    }

    return -1; // If k is out of bounds
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << "The " << k << "th element is " << findKthElement(a, b, k) << endl;

    vector<int> a2 = {100, 112, 256, 349, 770};
    vector<int> b2 = {72, 86, 113, 119, 265, 445, 892};
    k = 7;

    cout << "The " << k << "th element is " << findKthElement(a2, b2, k) << endl;

    return 0;
}
