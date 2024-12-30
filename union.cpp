#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the count of elements in the union of two vectors
int findUnion(vector<int>& a, vector<int>& b) {
    unordered_set<int> unionSet;

    // Insert elements of vector a into the set
    for (int num : a) {
        unionSet.insert(num);
    }

    // Insert elements of vector b into the set
    for (int num : b) {
        unionSet.insert(num);
    }

    // The size of the set is the count of distinct elements in the union
    return unionSet.size();
}

int main() {
    vector<int> a = {85, 25, 1, 32, 54, 6};
    vector<int> b = {85, 2};

    int result = findUnion(a, b);
    cout << "Count of elements in the union: " << result << endl;

    return 0;
}
