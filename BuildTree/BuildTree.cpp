#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::unordered_map<int, int>mp; // Stores (node -> index in inorder array)

    TreeNode* make_tree(int start, int end, int& idx, std::vector<int>& postorder, std::vector<int>& inorder) {

        // If range for inorder is NOT valid then return NULL
        if (start > end) return NULL;

        // Create a node for our root node of current subtree
        TreeNode* root = new TreeNode(postorder[idx]);

        // Find position of current root in inorder array
        int i = mp[root->val];

        // Decrement our pointer to postorder array for our next upcoming root if any
        idx--;

        // Make a call to create right subtree, inorder range [i+1, end]
        root->right = make_tree(i + 1, end, idx, postorder, inorder);

        // Make a call to create left subtree, inorder range [start, i-1]
        root->left = make_tree(start, i - 1, idx, postorder, inorder);

        return root;
    }

    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        int idx = postorder.size() - 1;

        // Create (nodes -> index of inorder array) mapping
        for (int i{}; i < inorder.size(); ++i) {

            mp[inorder[i]] = i;
        }
        // Create tree starting from root at position (n-1) in postorder array
        // Range for current inirder array : [0, n-1]
        return make_tree(0, inorder.size() - 1, idx, postorder, inorder);
    }
};

int main()
{
    std::vector<int> inorder{ 9, 3, 15, 20, 7 };
    std::vector<int> postorder{ 9, 15, 7, 20, 3 };
    Solution s;
    TreeNode* node = s.buildTree(inorder, postorder);
};
