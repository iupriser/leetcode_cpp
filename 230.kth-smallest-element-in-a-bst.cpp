/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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

// iterative approach

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root)
        {
            return 0;
        }
        stack<TreeNode *> stk;
        while (root != NULL || !stk.empty())
        {
            while (root != NULL)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (--k == 0)
            {
                break;
            }
            root = root->right;
        }
        return root->val;
    }
};

/*
// recursive approach

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = 0;
        kthInorder(root, k, count, result);
        return result;
        
    }
    
    void kthInorder(TreeNode* root, int k, int& count, int& result)
    {
        if(root->left)
            kthInorder(root->left, k, count, result);
        count++;
        if(count == k)
        {
            result = root->val;
            return;
        }
        if(root->right)
            kthInorder(root->right, k, count, result);
    }
};
*/

/*
// naive approach

class Solution {
private:
    void inorder(TreeNode *root, int k, vector<int>& heap)
    {
        if(heap.size() >= k)
            return;
        
        if(root == NULL)
            return;
        
        inorder(root->left, k, heap);
        heap.push_back(root->val);
        inorder(root->right, k, heap);        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> heap;
        inorder(root, k, heap);
        for(auto i : heap)
            cout << i << endl;
        return heap[k - 1];       
    }
};
*/
// @lc code=end
