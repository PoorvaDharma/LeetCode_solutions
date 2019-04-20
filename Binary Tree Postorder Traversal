/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* r) {
        
        stack<TreeNode *> s;
        vector<int> v;
        
        TreeNode *root = r;
        
        if(!root)
            return v;
        
        while(root || !s.empty())
        {
            while(root)
            {
                if(root->right)
                    s.push(root->right);
                s.push(root);
                root = root->left;
            }
            
            if(!s.empty())
            {
                root = s.top();
                s.pop();
                if(root->right && !s.empty() &&root->right==s.top())
                {
                    s.pop();
                    s.push(root);
                    root = root->right;
                }
                else
                {
                    v.push_back(root->val);
                    root = nullptr;
                }  
            }
        }
        
        return v;
    }
};
