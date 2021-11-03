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

    bool isSymmetric(TreeNode* root) {

        if (root->left == NULL && root->right == NULL) return true;
        if (root->left != NULL && root->right == NULL ||
            root->left == NULL && root->right != NULL) return false;

        bool cont = true;
        help(root->left, root->right, cont);
        return cont;
    }

private:
    void help(TreeNode* left_node, TreeNode* right_node, bool& cont) {
        if (cont == false) return;
        if (left_node == NULL && right_node == NULL) return;
        if (left_node == NULL && right_node != NULL || left_node != NULL && right_node == NULL)
        {
            cont = false;
            return;
        }

        help(left_node->left, right_node->right, cont);
        if (left_node->val != right_node->val)
        {
            cont = false;
            return;
        }
        help(left_node->right, right_node->left, cont);
    }

int main()
{
    std::cout << "Hello World!\n";
}
