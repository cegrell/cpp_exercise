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

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL & root->right == NULL) return 1;
        int left = 1, right = 1;

        helper(root->left, left);
        helper(root->right, right);

        return std::max(left, right);
    }
private:
    void helper(TreeNode* node, int& counter) {
        if (node == NULL) {
            return;
        }
        int left = counter + 1;
        helper(node->left, left);
        int right = counter + 1;
        helper(node->right, right);
        counter = std::max(left, right);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
