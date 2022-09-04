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
    
   
    
    static bool compare(pair<int, int> &a, pair<int, int>& b)
    {
        if(a.first == b.first)
            return a.second < b.second;
        else
            return a.first < b.first;
    }
    
   
    
    map<int, vector<pair<int, int>>> mp;
    
  
    
    void dfs(TreeNode* root, int row, int col)
    {
        if(root == NULL)
            return;
        
     
        
        mp[col].push_back({row, root -> val});
        
        
        dfs(root -> left, row + 1, col - 1);
        
   
        
        dfs(root -> right, row + 1, col + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
       
        
        dfs(root, 0, 0);
        
        vector<vector<int>> res;
        
     
        
        for(auto x : mp)
        {
            vector<pair<int, int>> arr = x.second;
            
           
            
            sort(arr.begin(), arr.end(), compare);
            
           
            
            vector<int> temp;
            
            for(int i = 0; i < arr.size(); i++)
            {
                temp.push_back(arr[i].second);
            }
            
           
            res.push_back(temp);
        }
        
        return res;
    }
};
