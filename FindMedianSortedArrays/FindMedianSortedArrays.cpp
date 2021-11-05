#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

        // Concatenate the two vectors
        std::vector<int> nums3;
        nums3.reserve(nums1.size() + nums2.size());
        nums3.insert(nums3.end(), nums1.begin(), nums1.end());
        nums3.insert(nums3.end(), nums2.begin(), nums2.end());

        // sort
        std::sort(nums3.begin(), nums3.end());

        // median
        if (nums3.size() % 2 == 0)
        {
            return ((double)nums3[(nums3.size() / 2) - 1] + (double)nums3[nums3.size() / 2]) / 2;
        }
        else return (double)nums3[nums3.size() / 2];
    }
};

int main()
{
    Solution s;
    std::vector<int> nums1{ 1, 2 };
    std::vector<int> nums2{ 3, 4 };
    double d = s.findMedianSortedArrays(nums1, nums2);   
    std::cout << d << std::endl;
}
