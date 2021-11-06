#include <iostream>
#include <string>

class Solution {
public:
    void GetPalindromeLength(std::string& s, int& max_len, int& l, int& r, int& n, int& st) {
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                l--; r++;
            }
            else break;
        }
        int len = r - l - 1;
        if (len > max_len)
        {
            max_len = len;
            st = l + 1;
        }
    }
    
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) return s;
        int max_len = 1, n = s.length();
        int st = 0, end = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            int l = i, r = i + 1;
            GetPalindromeLength(s, max_len, l, r, n, st);
        }

        for (int i = 0; i < n - 1; ++i)
        {
            int l = i, r = i;
            GetPalindromeLength(s, max_len, l, r, n, st);
        }
        return s.substr(st, max_len);
    }
};

int main()
{
    Solution s;
    std::string p = "edgabbaje";
    std::string palin = s.longestPalindrome(p);
    std::cout << palin;
}
