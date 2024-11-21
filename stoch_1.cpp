 int n = prices.size();
    if (n < 2) return 0; // No profit can be made with less than 2 prices

    int profit = 0;
    // Traverse the array and accumulate profit when the price increases
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;