#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        // With a linear search, find the value that is highest 
        // that still accept the requirement, e.g. that 
        // x suared equals y, e.g. 4^2 is <= 64, 6^2 <= 64, 
        // 8^2 <= etc.
        // Space complexity is constant - not using any extra variables
        // time complexity: Squareroot of X
        long long y = 0;
        while (y * y <= x)
        {
            y++;
        }
        return y - 1;
    }

    int mySecondSqrt(int x) {
        /// Do a binary serach instead. 
        long long s = 0, e = INT_MAX, ans=0;
        while (s <= e)
        {
            long long m = s + (e - s) / 2;
            if (m * m <= x)
            {
                ans = m;
                s = m + 1;
            }
            else
            {
                e = m - 1; 
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int x = 64;
    int y = s.mySecondSqrt(x);
    std::cout << y;
}
