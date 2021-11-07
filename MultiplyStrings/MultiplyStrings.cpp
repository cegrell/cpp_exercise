#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        std::vector<int> res(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        int i = 0;
        std::string ans = "";
        while (res[i] == 0) i++; // skip the first zeros, if any
        while (i < res.size()) ans += std::to_string(res[i++]);

        return ans;
    }
};

int main()
{
    Solution s;
    std::string num1 = "123";
    std::string num2 = "345";
    std::string ans = s.multiply(num1, num2);
    for (char c : ans)
    {
        std::cout << c;
    }
    std::cout << std::endl;
}
