/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
class Solution {
int ans=INT_MIN;
    int f(TreeNode* root){
        //base case
        if(root==NULL) return 0;

        int left=f(root->left);
        
        int right=f(root->right);
        
        //for covering all the edge cases
        if(root->val+left+right>ans) ans=root->val+left+right;
        if(root->val+max(left,right)>ans) ans=root->val+max(left,right);
        if(root->val>ans) ans=root->val;

        //for covering the both side negative returning cases and the root is positive
        if(root->val>root->val+max(left,right)) return root->val;
        
        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        
        f(root);
        return ans ;
        
    }
};
// @lc code=end

