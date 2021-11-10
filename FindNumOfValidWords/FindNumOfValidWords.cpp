#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findNumOfValidWords(std::vector<std::string>& words, std::vector<std::string>& puzzles) {

        const int n = words.size();
        const int m = puzzles.size();
        std::vector<int> result{ m, 0 };

        for (int i = 0; i < m; i++)
        {
            int numWords = 0;
            for (int j = 0; j < n; j++)
            {
                // first letter of puzzle in word
                if (words[j].find(puzzles[i][0]) == std::string::npos) continue;

                std::cout << words[j] << std::endl;

                // each letter in word in puzzle
                std::sort(words[j].begin(), words[j].end());

                std::cout << words[j] << std::endl;

                bool allLetters = false;

                for (int k = 0; k < words[j].length(); k++)
                {

                    if (k > 0 && words[j][k - 1] == words[j][k - 1]) continue;
                    if (puzzles[i].find(words[j][k]) != std::string::npos) break;

                    std::cout << words[j][k] << " is in " << puzzles[i]  << std::endl;

                    if (k == words[j].length() - 1) allLetters = true;
                }
                if (allLetters) numWords++;
            }
            result.push_back(numWords);
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> words = { "aaaa","asas","able","ability","actt","actor","access" };
    std::vector<std::string> puzzles = { "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz" };
    std::vector<int> res = s.findNumOfValidWords(words, puzzles);

    for (int i : res)
        std::cout << i << std::endl;
}
