#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> ThreeSum(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                int j = i + 1, k = n - 1;
                while (j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0)
                    {
                        result.push_back({ nums[i], nums[j], nums[k] });
                        while (j < k && nums[j] == nums[j + 1]) j++; // jump over the elements that are equal
                        while (j < k && nums[k] == nums[k - 1]) k--; // same as above
                        j++; k--;
                    }
                    else if (sum > 0) k--;
                    else j++;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{ -1, 0, 1, 2, -1, -4 };
    std::vector<std::vector<int>> res = s.ThreeSum(nums);
    
    for (std::vector<int> v : res)
    {
        std::cout << "[ ";
        for (int i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
    }
}
