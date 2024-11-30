#include <iostream>
#include <algorithm> // For sort function
using namespace std;

bool areAnagrams(string s1, string s2) {
    // If lengths of the strings are not equal, they cannot be anagrams
    if (s1.length() != s2.length())
        return false;

    // Sort both strings
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // Compare sorted strings
    return s1 == s2;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";

    if (areAnagrams(s1, s2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
