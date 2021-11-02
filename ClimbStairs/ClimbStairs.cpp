#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        int combos = 0;
        std::vector<int> dp{};
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[n] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int climbStairsOptSpaceComplexity(int n) {
        if (n == 1) return 1;

        int one = 1;
        int two = 1;
        int tmp = 0;
        for (int i = 2; i < n; i++)
        {
            tmp = two;
            two = two + one;
            one = tmp;
        }
        return two + one;
    }
};

int main()
{
    Solution s;
    int n = 5;
    int steps = s.climbStairs(n);
    std::cout << steps;
}
