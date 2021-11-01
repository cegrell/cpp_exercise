#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        bool remainder = true;
        for (int i = digits.size() - 1; i >= 0; i--)
        {            
            
            if (digits[i] != 9 && remainder)
            {
                digits[i] += 1;
                remainder = false;
            }
            else if (remainder)
            {
                digits[i] = 0;
            }
        }
        if (remainder)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main()
{
    Solution s;
    std::vector<int> digits{ 9, 9, 9 };
    digits = s.plusOne(digits);

    for (int i : digits)
    {
        std::cout << i << std::endl;
    }
}
