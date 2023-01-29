/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int direction=0;//0 means right 1 means left
        vector<vector<int>>ans;
        vector<int>temp;
        while(!q.empty()){
            vector<TreeNode*>nodevec;
            while(!q.empty()){
                nodevec.push_back(q.front());q.pop();
            }
            if(direction==1) reverse(nodevec.begin(), nodevec.end());
            
            for(auto element : nodevec){
                ans.push_back(element->val);
                if(direction==0){
                    if(element->left!=NULL){
                        q.push(element->left);
                    }
                    if(element->right!=NULL){
                        q.push(element->right);
                    }
                }
                if(direction==1){
                    if(element->right!=NULL){
                        q.push(element->right);
                    }
                    if(element->left!=NULL){
                        q.push(element->left);
                    }
                }
            }
        }
        return ans;
        
    }
};
// @lc code=end

