#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        int n=arr.size();
        if(n<2) return arr;
        int first = arr[0];
        int second =arr[1];
        int fc =1;
        int sc =0;
        for (int i=1;i<n;i++){
            if(first == arr[i]){
                first = arr[i];
                fc++;
            }
            else if(second ==arr[i]){
                second = arr[i];
                sc++;
            }
            else if(fc ==0){
                first =arr[i];
                fc=1;
            }
            else if(sc ==0){
                second = arr[i];
                sc=1;
            }
            else {
                fc--;
                sc--;
            }
        }
        
        fc =0;
        sc = 0;
        for (int i =0;i<n;i++){
            if (arr[i] ==first) fc++;
           else  if (arr[i] == second )  sc++;
        }
        vector<int> res;
        if (fc>(n/3)) res.push_back(first);
         if (sc>(n/3)) res.push_back(second);
         sort(res.begin(),res.end());
         return res;
       
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}