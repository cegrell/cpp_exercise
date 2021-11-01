#include <iostream>
#include <string>
#include <bitset>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {        
        int m = a.size() - 1;// start from the end of a, ie right-most index
        int n = b.size() - 1;// same as above.

        std::string ans = "";
        int carry = 0;
        
        // As long as there's elements to add in either m 
        // or n or both, then keep iterating.
        while ( m >= 0 || n >= 0)
        {
            // if m is greater or equal to zero, then that means 
            // that we're currently in-bound, ie there's more elements to
            // add. Taking the - '0' to convert it to a digit. '0' has the
            // decimal value of 48, and '1' has value of 49, so '1' - '0' = 1
            // Since done with this iteration on a, the value of m is reduced with 1. 
            // with `m--`. 
            // if m is less than 0, then we are out-of-bounds, thus v1 becomes 0 instead.
            int v1 = m >= 0 ? a[m--] - '0' : 0;
            // Same is done for v2 as v1. 
            int v2 = n >= 0 ? b[n--] - '0' : 0;

            // This is a temporary sum, which will conclude if there's going to be 
            // a remainder passed on to the next iteration or not. 
            int sum = v1 + v2 + carry;
            
            // It is only the remainder that is inserted to the answer-string, 
            // and it's placed at index 0, ie at the beginning of the string.
            ans = std::to_string(sum % 2) + ans;
            
            // The carry is if the sum is equal to or larger than 2. 
            // Since carry is an int, the decimals are dropped automatically. 
            carry = sum / 2;
        }
        // All iterations are done, if there is a carry left, place it at the 
        // index 0 of the string, otherwise return the string as-is.
        return carry == 1 ? ans = std::to_string(1) + ans : ans;
    }
};

int main()
{
    std::string a = "11", b = "1";
    Solution s;
    std::string ret = s.addBinary(a, b);
    std::cout << ret << std::endl;
}
