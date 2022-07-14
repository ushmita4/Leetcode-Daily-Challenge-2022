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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root,*newnode,*trav;
        
        int n = preorder.size();
        
        newnode = new TreeNode(preorder[0]);
        root = newnode;
        trav = newnode;
        
        
        //map of inorder traversals 
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[ inorder[i]] =i;
        
        
        for(int i=1 ; i<n ; i++)
        {
            newnode = new TreeNode(preorder[i]);
            
        //from root comparision
            trav  = root;
            bool flag = false;
            while(!flag)
            {
                    if(mp[trav->val] < mp[newnode->val])
                    {
                        //node at right side
                        if(trav->right)
                            trav = trav->right;
                        else
                          {  trav->right = newnode;
                                flag = true;
                          }
                    }
                    else
                    {
                        //node at left size;
                        if(trav->left)
                            trav = trav->left;
                        else
                        {
                            trav->left = newnode;
                            flag = true;
                        }
                    }
            } 
        }
        return root;
    }
};
