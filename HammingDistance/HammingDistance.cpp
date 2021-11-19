#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int num = x ^ y;
        while (num) {
            res += num % 2;
            num >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int x = 5, y = 7;
    int res = s.hammingDistance(x, y);
    std::cout << res;
}
