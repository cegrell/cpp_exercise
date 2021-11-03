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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool cont = true;
        help(p, q, cont);
        return cont;
    }
private:
    void help(TreeNode* left_node, TreeNode* right_node, bool& cont) {
        if (cont == false) return;
        if (left_node == NULL && right_node == NULL) return;
        if (left_node == NULL && right_node != NULL || left_node != NULL && right_node == NULL)
        {
            cont = false;
            std::cout << "Turned false HERE." << std::endl;
            return;
        }
        help(left_node->left, right_node->left, cont);
        if (left_node->val != right_node->val)
        {
            cont = false;
            std::cout << "Turned false herherer." << std::endl;
            return;
        }
        help(left_node->right, right_node->right, cont);
    }
};