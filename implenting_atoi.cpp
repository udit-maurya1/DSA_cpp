#include <iostream>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

int myAtoi(char* s) {
    // Initialize variables
    int i = 0;
    int sign = 1;  // Default sign is positive
    long result = 0;  // Use long to handle overflow during computation

    // Step 1: Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // Step 2: Handle optional '+' or '-' sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // Step 3: Convert the digits into an integer
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';  // Convert character to integer
        result = result * 10 + digit;

        // Step 4: Handle overflow cases
        if (sign * result > INT_MAX) {
            return INT_MAX;
        } else if (sign * result < INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    return static_cast<int>(sign * result);
}

// Example usage
int main() {
    char s[] = "   -12345";
    cout << myAtoi(s) << endl;  // Output: -12345
    return 0;
}
