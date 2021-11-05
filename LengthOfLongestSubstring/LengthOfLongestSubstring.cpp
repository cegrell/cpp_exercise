#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {

        std::string sub = "";
        int len = 0;
        for (char c : s)
        {
            if (sub.find(c) == std::string::npos)
            {
                sub += c;
            }
            else
            {
                if (sub.length() > len) len = sub.length();
                if (sub.length() >= sub.find(c) + 1) sub = sub.substr(sub.find(c) + 1, sub.length() + 1) + c;
                else sub = c;
            }
        }
        if (sub.length() > len) len = sub.length();
        return len;
    }
};

int main()
{
    Solution s;
    std::string str = "dvdf";
    int len = s.lengthOfLongestSubstring(str);
    std::cout << len << std::endl;
}
