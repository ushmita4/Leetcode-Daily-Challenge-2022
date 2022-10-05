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
    void helper(TreeNode * root , int val , int depth , int d)
    {
        if(!root)
            return;
        else if(d == depth)
        {
            auto itl = root->left , itr = root->right;
            root->left = new TreeNode (val);
            root->left->left = itl;
            root->right = new TreeNode (val);
            root->right->right = itr;
            return;
        }
        else if(d < depth)
        {    
        helper(root->left , val , depth , d+1);
        helper(root->right , val , depth , d+1);
        }
        else return;
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            auto newHead = new TreeNode(val);
            newHead->left = root;
            return newHead;
        }
        helper(root , val , depth-1 , 1);
        return root;
    }
};
