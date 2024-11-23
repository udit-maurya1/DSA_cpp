#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

    
    int result = arr[n - 1] - arr[0];

    
    for (int i = 1; i < n; ++i) {
        
        if (arr[i] - k < 0) continue;

        
        int newMax = max(arr[i - 1] + k, arr[n - 1] - k);
        int newMin = min(arr[0] + k, arr[i] - k);

   
        result = min(result, newMax - newMin);
    }

    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        cout << '~' << endl;
    }
    return 0;
}
