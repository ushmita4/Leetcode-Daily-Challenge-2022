class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return root;
        // if root is less than low its mean all its left childs  than low so discard them
        if(root -> val < low){
            return trimBST(root -> right,low,high);
            
        }
         // if root is greater than high its mean all its right childs greater than it so discard them
        if(root -> val > high)
            return trimBST(root -> left,low,high);
        //recursively o with left or right childs
        root -> left = trimBST(root -> left,low,high);
        root -> right = trimBST(root -> right,low,high);
        return root;
    }
};
