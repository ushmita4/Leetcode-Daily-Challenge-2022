class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q;
        q.push(cloned);
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
            if(temp->val==target->val)
                return temp;
        }
    return NULL;
    }
};
