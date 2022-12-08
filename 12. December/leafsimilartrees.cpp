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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafOne;
        vector<int> leafTwo;
        
        preOrder(root1, leafOne);
        preOrder(root2, leafTwo);
        
        return (leafOne == leafTwo);
    }
    
    void preOrder(TreeNode* root, vector<int>& leafNumbers){
        
        if(root){
            if(root->left == NULL && root->right == NULL){
                leafNumbers.push_back(root->val);
            }
        
            preOrder(root->left, leafNumbers);
            preOrder(root->right, leafNumbers);
        }
    }
};
