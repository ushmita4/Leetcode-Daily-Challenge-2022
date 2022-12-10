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
    const int MOD = pow(10, 9) + 7;
public:
   
    long long preOrder(TreeNode *root) {
        if(root) {
            return root->val + preOrder(root->left) 
                + preOrder(root->right);
        }    
        return 0;
    }
    
    long long maxSplit(TreeNode *root, long long prev_sum,
                 long long &max_prod) {
        if(!root)
            return 0;
        
       
        long long left = maxSplit(root->left, prev_sum, max_prod);
        long long right = maxSplit(root->right, prev_sum, max_prod);
       
        long long remaining_sum = prev_sum  - left - right;
     
        long long cmb1 = left * (remaining_sum + right);
        long long cmb2 = right * (remaining_sum + left);
        max_prod = max({max_prod, cmb1, cmb2});
        
        return root->val + (left + right);
    }
    
    int maxProduct(TreeNode* root) {
        long long max_prod = 0;
       
        long long sum = preOrder(root);
        
        maxSplit(root, sum, max_prod);
        return max_prod % MOD;
    }
};
