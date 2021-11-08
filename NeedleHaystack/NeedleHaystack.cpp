#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (haystack == "" && needle == "") return 0;
        if (haystack.find(needle) == std::string::npos) return -1;
        else return haystack.find(needle);
    }
};

int main()
{
    Solution s;
    std::string haystack = "hello";
    std::string needle = "ll";
    int pos = s.strStr(haystack, needle);
    std::cout << pos;
}
