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
        res.push_back(node->val);
        help(node->left, res);
        help(node->right, res);
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if (root == nullptr) return {};
        res.push_back(root->val);

        help(root->left, res);
        help(root->right, res);

        return res;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
