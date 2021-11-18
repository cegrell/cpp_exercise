#include <iostream>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::unordered_set<int> s(begin(nums), end(nums));
        std::vector<int> ans(size(nums) - size(s));
        for (int i = 1, j = 0; i <= size(nums); i++)
            if (!s.count(i)) ans[j++] = i;
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<int> vect{ 1, 2, 3, 4, 2, 5, 3, 4 };
    std::vector<int> ret = s.findDisappearedNumbers(vect);
    for (int i : ret)
        std::cout << i;
}
