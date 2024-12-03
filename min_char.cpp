#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to find the minimum characters to add at the front to make the string a palindrome
int minCharsToAdd(string s) {
    int n = s.size();
    int start = 0, end = n - 1;
    int charsToAdd = 0;

    while (start < end) {
        if (s[start] == s[end]) {
            // If characters match, move inward
            start++;
            end--;
        } else {
            // If characters don't match, add a character at the front
            charsToAdd++;
            start = 0; // Reset start to recheck for palindromic suffix
            end = n - charsToAdd - 1; // Adjust end
        }
    }

    return charsToAdd;
}

int main() {
    string s = "abc";
    cout << "Minimum characters to add: " << minCharsToAdd(s) << endl;
    return 0;
}
