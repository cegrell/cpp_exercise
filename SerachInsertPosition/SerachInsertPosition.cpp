#include <iostream>
#include <vector>

class Solution {
public:
    int recursiveSearch(std::vector<int>& nums, int lower_bound, int upper_bound, int target) {

        //std::cout << "Searching between " << lower_bound << " and " << upper_bound << std::endl;
        // Base case
        if (lower_bound >= upper_bound)
        {
            if (nums[lower_bound] < target)
            {
                return lower_bound + 1;
            }
            else
            {
                return lower_bound;
            }
        }

        int midpoint;
        if ((upper_bound - lower_bound) % 2 == 0)
        {
            midpoint = lower_bound + (upper_bound - lower_bound) / 2;
        }
        else
        {
            midpoint = lower_bound + (upper_bound - lower_bound - 1) / 2;
        }
        //std::cout << "Midpoint is " << midpoint << std::endl;        

        int pos;
        if (nums[midpoint] == target)
        {
            return midpoint;
        }
        else if (nums[midpoint] < target)
        {
            pos = recursiveSearch(nums, midpoint + 1, upper_bound, target);
        }
        else
        {
            pos = recursiveSearch(nums, lower_bound, midpoint - 1, target);
        }

        return pos;
    }

    int searchInsert(std::vector<int>& nums, int target) {

        int lower_bound = 0;
        int upper_bound = nums.size() - 1;


        int midpoint;
        if (upper_bound % 2 == 0)
        {
            midpoint = upper_bound / 2;
        }
        else
        {
            midpoint = (upper_bound - 1) / 2;
        }

        int pos;
        //std::cout << "First midpoint is " << midpoint << std::endl; 
        if (nums[midpoint] < target)
        {
            pos = recursiveSearch(nums, midpoint, upper_bound, target);
        }
        else
        {
            pos = recursiveSearch(nums, lower_bound, midpoint , target);
        }

        return pos;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = { 1, 3, 5, 6 };
    int target = 5;
    int pos = s.searchInsert(nums, target);
    
    std::cout << pos;
    return 0;
}