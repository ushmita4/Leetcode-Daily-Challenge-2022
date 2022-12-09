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
    void find(TreeNode* root,int mx,int mn,int& ans)
    {
        if(root==NULL) return;

      
        if(mx < root->val) mx = root->val;
        
        if(mn > root->val) mn = root->val;

       
        ans = max(ans,abs(mx-mn));

        find(root->left,mx,mn,ans);         
        find(root->right,mx,mn,ans);        
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        int ans = INT_MIN;
        find(root,root->val,root->val,ans);
        return ans;
    }
};
