      string result;
    int carry = 0;
    int i = s1.size() - 1;
    int j = s2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry; 

    
        if (i >= 0) {
            sum += s1[i] - '0'; 
            i--;
        }

    
        if (j >= 0) {
            sum += s2[j] - '0'; 
            j--;
        }


        result.push_back((sum % 2) + '0'); 
        carry = sum / 2;
    }

    // The result is currently reversed
    reverse(result.begin(), result.end());

    // Remove leading zeros (if any)
    size_t start = result.find_first_not_of('0');
    if (start != string::npos) {
        return result.substr(start); // Return the string without leading zeros
    }
    return "0";
    