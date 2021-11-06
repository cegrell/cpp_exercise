#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int area_max = 0, n = height.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int lp = std::min(height[i], height[j]);
                int area = lp * (j - i);
                if (area > area_max)
                {
                    area_max = area;
                }
            }
        }
        return area_max;
    }
    int moreOptimisedMaxArea(std::vector<int>& height) {
        int min_h = height[0], n = height.size();
        int max_h = height[n - 1];
        int min_idx = 0, max_idx = n - 1;

        if (min_h > max_h)
        {
            max_h = min_h;
            max_idx = min_idx;
            min_h = height[n - 1];
            min_idx = n - 1;
        }

        int w = n - 1;
        int max_area = min_h * w;

        while (w > 0)
        {
            int idx = min_idx;
            while (height[idx] <= min_h)
            {
                if (min_idx < max_idx) idx++;
                else idx--;
                w--;
                if (w < 1) break;
            }
            if (height[idx] > max_h)
            {
                min_h = max_h;
                min_idx = max_idx;
                max_idx = idx;
                max_h = height[idx];
            }
            else
            {
                min_idx = idx;
                min_h = height[idx];
            }
            max_area = std::max(max_area, w * min_h);
        }
        return max_area;
    }
};

int main()
{
    Solution s;
    std::vector<int> height{ 5, 4, 2, 6, 2 };
    int area = s.moreOptimisedMaxArea(height);
    std::cout << area;
}
