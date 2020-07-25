/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        stack<TreeNode *> stk;
        TreeNode *pre = NULL;
        while (root != NULL || !stk.empty())
        {
            while (root != NULL)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pre != NULL && root->val <= pre->val)
            {
                return false;
            }
            pre = root;
            root = root->right;
        }
        return true;
    }
};
// @lc code=end
