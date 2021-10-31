#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxSum = 0, tmp = nums[0];
        for (int& x : nums)
        {
            tmp = std::max(tmp + x, x);
            maxSum = std::max(maxSum, tmp);
        }
        return maxSum;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    int sum = s.maxSubArray(nums);
    std::cout << sum;
}
