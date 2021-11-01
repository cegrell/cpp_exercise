#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        std::vector<std::string> result{};
        std::string space_delimiter = " ";

        std::size_t pos = 0;
        while ((pos = s.find(space_delimiter)) != std::string::npos)
        {
            
            std::string tmp = s.substr(0, pos);
            if (s.substr(0, pos).size() > 0)
            {
                result.push_back(tmp);
            }
            s.erase(0, pos + space_delimiter.length());
        }
        
        if (s.compare(space_delimiter) == 1)
        {
            result.push_back(s);
        }        

        for (const auto& str : result)
        {
            std::cout << str << std::endl;
        }
        return result[result.size() - 1].size();        
    }
    int newLengthOfLastWord(std::string s) {
        int length = 0;
        bool prev_space = true; 
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                if (prev_space)
                {
                    length = 1;
                }
                else
                {
                    length++;
                }
                prev_space = false;
            }
            else
            {
                prev_space = true;
            }
        }
        return length;
    }
};

int main()
{
    std::string text = "luffy is still joyboy ";
    Solution s;
    //int l = s.lengthOfLastWord(text);
    int l = s.newLengthOfLastWord(text);

    std::cout << "Length of last word is " << l << std::endl;
}
