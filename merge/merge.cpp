#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> tmp(nums1.begin(), nums1.begin() + m);
        int x = 0, y = 0;
        if (nums2.size() > 0)
        {
            for (int i = 0; i < nums1.size(); i++)
            {
                if (x < tmp.size() && y >= nums2.size() ||
                    x < tmp.size() && y < nums2.size() && tmp[x] < nums2[y])
                {
                    nums1[i] = tmp[x];
                    x++;
                }
                else
                {
                    nums1[i] = nums2[y];
                    y++;
                }
            }
        }
        
        for (int i = 0; i < nums1.size(); i++)
        {
            std::cout << nums1[i];
        }
    }
    void mergeOptimal(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int i = m + n - 1; i >= 0; i--)
        {
            if (nums2.size() == 0 || 
                n < 1 || 
                m > 0 && n > 0 && nums1[m-1] > nums2[n-1]
                )
            {
                nums1[i] = nums1[m-1];
                m--;
            }
            else
            {
                nums1[i] = nums2[n-1];
                n--;
            }
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            std::cout << nums1[i];
        }
    }
    void mergeOptimalFurther(std::vector<int>& nums1, int m, std::vector<int> nums2, int n) {
        int i = m - 1, j = n - 1, index = n + m - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[index--] = nums1[i--];
            }
            else
            {
                nums1[index--] = nums2[j--];
            }
        }
        while (j >= 0)
        {
            nums1[index--] = nums2[j--];
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            std::cout << nums1[i];
        }
    }
};

int main()
{
    Solution s;
    std::vector<int> nums1{ 1};
    std::vector<int> nums2{};
    int m = 1;
    int n = 0;    
    s.mergeOptimal(nums1, m, nums2, n);
}
