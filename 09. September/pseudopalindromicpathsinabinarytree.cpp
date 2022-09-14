class Solution {
public:
    int ans = 0;
    
   
	
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return ans;
    }
    
  
    void preorder(TreeNode* node, int cnt) {
      
        if (node == NULL) return;
        
        cnt ^= (1 << node->val);
        
        if (!node->left && !node->right) {
           
            ans += (cnt & (cnt - 1)) == 0;
        }
        
        preorder(node->left, cnt);
     
        preorder(node->right, cnt);
    }
};
