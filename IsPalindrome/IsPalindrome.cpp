#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.length() <= 1) return true;
        int start = 0, end = s.length() - 1;

        while (start < end)
        {
            while (start < end && !std::isalnum(s[start]))
            {
                start++;
            }
            while (start < end && !std::isalnum(s[end]))
            {
                end--;
            }
            if (start < end && std::tolower(s[start]) != std::tolower(s[end])) return false;
            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    Solution s; 
    std::string str = "A man, a plan, a canal: Panama";
    bool isPal = s.isPalindrome(str);
    std::cout << isPal << std::endl;
    
    //std::cout << "Hello World!\n";
}
