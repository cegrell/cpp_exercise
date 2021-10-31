#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int buy = prices[0], profit = 0;
        for (int i = 1; i < n; i++)
        {
            if (buy > prices[i])buy = prices[i];
            if (prices[i] > buy)profit = std::max(profit, prices[i] - buy);
        }
        return profit > 0 ? profit : 0;
    }
};

int main()
{
    Solution s;
    std::vector<int> prices = { 7, 5, 6, 1, 0 };
    int profit = s.maxProfit(prices);
    std::cout << profit;
}
