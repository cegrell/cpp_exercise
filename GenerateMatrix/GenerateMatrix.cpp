#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {

        std::vector<std::vector<int>> m;
        if (numRows == 0) return m;
        for (int i = 0; i < numRows; i++)
        {
            std::vector<int> n;

            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0) n.push_back(1);
                else if (j == i) n.push_back(1);
                else
                {
                    n.push_back(m[i - 1][j - 1] + m[i - 1][j]);
                }
            }
            m.push_back(n);
        }
        return m;
    }
};

int main()
{
    Solution s;
    int num = 5;
    std::vector<std::vector<int>> m = s.generate(num);

    for (std::vector<int> v : m)
    {
        for (int i : v)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}
