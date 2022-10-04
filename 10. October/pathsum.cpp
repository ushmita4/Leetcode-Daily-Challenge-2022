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
private:
    void sum(TreeNode* root, int targetSum, int s, bool &ans){
        if(root->left == NULL && root ->right == NULL){
            if(s + root->val == targetSum){
                ans = true;    
            }
            
            return;
            
        }
        if(root->left != NULL){
            sum(root ->left, targetSum, s+ root->val, ans);    
        }
        if(root -> right != NULL){
            sum(root->right, targetSum, s+root->val, ans);
        }
        
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        int s = 0;
        if(root == NULL){
            return false;
        }
        sum(root, targetSum, s, ans);
        return ans;
        
    }
};
