#include <iostream>
#include <string>
using namespace std;

bool isRotatedVersion(string s1, string s2) {
    // Check if the lengths of the strings are the same
    if (s1.length() != s2.length()) {
        return false;
    }

    // Concatenate s1 with itself
    string concatenated = s1 + s1;

    // Check if s2 is a substring of concatenated
    return concatenated.find(s2) != string::npos;
}

int main() {
    string s1 = "abcd", s2 = "cdab";

    if (isRotatedVersion(s1, s2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
