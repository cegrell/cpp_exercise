// PostorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Solution {
public:    
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    void help(TreeNode* node, std::vector<int>& res) {
        if (node == nullptr) return;

        help(node->left, res);
        help(node->right, res);
        res.push_back(node->val);
    }

    std::vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        std::vector<int> res;

        help(root->left, res);
        help(root->right, res);

        res.push_back(root->val);
        return res;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
