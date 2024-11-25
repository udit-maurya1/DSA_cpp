#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:

    int maxProduct(vector<int> &arr) {
      int n = arr.size();
    int max_product = arr[0];
    int current_max = arr[0];
    int current_min = arr[0];
    
    for (int i = 1; i < n; ++i) {
        if (arr[i] < 0) {
            swap(current_max, current_min); 
        }

    
        current_max = max(arr[i], current_max * arr[i]);
        current_min = min(arr[i], current_min * arr[i]);

    
        max_product = max(max_product, current_max);
    }

    return max_product;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
       
        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}