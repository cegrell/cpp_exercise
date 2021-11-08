#include <iostream>
#include <vector>

class Solution {
public:
    int numTrees(int n) {
        /// This is called the Nth-Catalan number.

        std::vector<int> res(n + 1, 0);

        res[0] = 1;
        res[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                res[i] += res[j] * res[i - j - 1];
            }

        }
        return res[n];
    }
};

int main()
{
    Solution s;
    int num = 5;
    int res = s.numTrees(num);
    std::cout << res;
}
