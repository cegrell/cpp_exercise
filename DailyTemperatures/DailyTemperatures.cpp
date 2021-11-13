#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        const int n = temperatures.size();
        std::vector<int> answer(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (temperatures[i] < temperatures[j])
                {
                    answer[i] = j - i;
                    break;
                }
            }

        }
        return answer;
    }

    std::vector<int> optimalDailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> temps;
        std::stack<int> idxs;
        const int n = temperatures.size();
        temps.push(temperatures[0]);
        idxs.push(0);
        std::vector<int> answer(n, 0);
        for (int i = 1; i < n; i++)
        {            
            while(temps.size() > 0 && temperatures[i] > temps.top())
            {
                answer[idxs.top()] = i - idxs.top();
                // Remove top
                idxs.pop();
                temps.pop();
            }
            temps.push(temperatures[i]);
            idxs.push(i);
        }
        return answer;
    }
};

int main()
{
    Solution s;
    std::vector<int> temperatures{ 73,74,75,71,69,72,76,73 };

    std::vector<int> answer = s.optimalDailyTemperatures(temperatures);

    for (int i : answer)
        std::cout << i << " ";
    std::cout << std::endl;
}
