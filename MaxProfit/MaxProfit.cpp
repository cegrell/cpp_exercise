#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        const int n = prices.size();
        int buy_price;
        bool holding = false;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 && holding == true) sum += prices[i] - buy_price;
            else if (i < n - 1)
            {
                if (holding == false && prices[i + 1] > prices[i])
                {
                    holding = true;
                    buy_price = prices[i];
                }
                else if (holding == true && prices[i + 1] < prices[i])
                {
                    holding = false;
                    sum += prices[i] - buy_price;
                    buy_price = 0;
                }
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;
    std::vector<int> prices{ 7, 1, 5, 3, 6, 4 };
    int sum = s.maxProfit(prices);
    std::cout << sum;
}
