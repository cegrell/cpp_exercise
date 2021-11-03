#include <iostream>
#include <vector>
#include <stack>

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

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        help(root, ans);
        return ans;
    }   

    std::vector<int> itertiveTraversal(TreeNode* root) {
        // itertive approach make use of a stack
        std::vector<int> ans;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* x = s.top();
            if (x->left != NULL)
            {
                s.push(x->left);
                x->left = NULL;
            }
            else
            {
                ans.push_back(x->val);
                s.pop();
                if (x->right)
                {
                    s.push(x->right);
                }
            }

        }
        return ans;
    }

private:
    void help(TreeNode* root, std::vector<int>& ans)
    {
        if (root == NULL) return;
        help(root->left, ans);
        ans.push_back(root->val);
        help(root->right, ans);
    }
};

int main()
{
    Solution s;

    std::vector<int> vect = s.inorderTraversal();
    std::cout << "Length of last word is " << l << std::endl;
}
