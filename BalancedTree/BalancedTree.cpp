#include <iostream>

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
        
    };

    int checkHeight(TreeNode* root) {
        if (root == nullptr)return 0;
        return 1 + std::max(checkHeight(root->left), checkHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
        return checkBalance(root);

    }

    bool checkBalance(TreeNode* root) {
        if (root == nullptr) return true;

        int l = checkHeight(root->left);
        int r = checkHeight(root->right);

        bool rightCheck = isBalanced(root->right);
        bool leftCheck = isBalanced(root->left);

        return abs(l - r) <= 1 and rightCheck and leftCheck;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
