#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minStartValue(std::vector<int>& nums) {
        std::vector<int> nums_c(nums);
        for (int i = 1; i < nums_c.size(); i++) {
            nums_c[i] += nums_c[i - 1];
        }
        int min_val = *std::min_element(nums_c.begin(), nums_c.end());
        int ret = min_val > 0 ? 1 : min_val * -1 + 1;
        return ret;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = { 2, 3, 5 - 5, -1 };
    int min_val = s.minStartValue(nums);
    std::cout << min_val;
}
