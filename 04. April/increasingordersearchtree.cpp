class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* nxt=NULL) {
        if(!root) return nxt;
        root->right=increasingBST(root->right,nxt);
        TreeNode* temp=increasingBST(root->left,root);
        root->left=NULL;
        return temp;
    }
};
