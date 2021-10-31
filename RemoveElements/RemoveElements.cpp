#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    auto removeElement(std::vector<int>& nums, int val) {
        // This will return a iterator
        auto it = std::remove_if(nums.begin(), nums.end(), [=](int num) {return num == val; });

        // The result of subtracting one iterator fr another is to get an int
        return it;// -nums.begin();
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = { 3, 2, 3, 2 };
    int rm_int = 3;
    auto a = s.removeElement(nums, rm_int);

    //for (char i: a)
    //    std::cout << i << std::endl;
}