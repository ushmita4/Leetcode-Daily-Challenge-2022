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
    int c=1;
    void find(TreeNode* root)
    {
        if(root->left!=NULL)
        {
            c++;
            find(root->left);
        }
        if(root->right!=NULL)
        {
            c++;
            find(root->right);
        }
    }
    int countNodes(TreeNode* root) {
       if(root==NULL)
           return 0;
        else
        {
            find(root);
            return c;
        }
    }
};
