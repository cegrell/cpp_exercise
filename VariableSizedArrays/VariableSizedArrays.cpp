#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>


int main() {
    int n;
    int q;
    std::cin >> n;
    std::cin >> q;

    std::vector<std::vector<int>> vect;
    int num_elements;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        
        std::cin >> num_elements;
        std::vector<int> row_v;

        for (int j = 0; j < num_elements; j++)
        {
            
            std::cin >> tmp;
            row_v.push_back(tmp);
        }

        vect.push_back(row_v);
    }

    // Queries
    std::vector<int> q_vect;
    int row;
    int col;
    for (int i = 0; i < q; i++)
    {
        std::cin >> row;
        std::cin >> col;

        std::cout << vect[row][col] << std::endl;        
    }

    return 0;
}