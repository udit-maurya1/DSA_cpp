#include <iostream>
#include <unordered_map>
using namespace std;

char firstNonRepeating(string s) {
    // Create a map to store the count of each character
    unordered_map<char, int> charCount;

    // Count the occurrences of each character
    for (char ch : s) {
        charCount[ch]++;
    }

    // Find the first character with a count of 1
    for (char ch : s) {
        if (charCount[ch] == 1) {
            return ch;
        }
    }

    // If no non-repeating character is found, return '$'
    return '$';
}

int main() {
    string s = "sawan";
    char result = firstNonRepeating(s);
    if (result == '$') {
        cout << -1 << endl; // Driver code outputs -1 for '$'
    } else {
        cout << result << endl;
    }
    return 0;
}
