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
    
    void inorder(TreeNode *root, vector<TreeNode *> &v)
    {
        if(!root)
            return;
        
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        if(!root)
            return root;
        
        vector<TreeNode *> v;
        
        TreeNode *r = nullptr;
        inorder(root,v);
        
        for(int i =0;i<v.size();i++)
        {
            if(v[i]->val==p->val)
            {
                //cout<<i;
                if(i == v.size()-1)
                    r = nullptr;
                else
                {
                    //cout<<"else";
                    r = v[i+1];
                }
                    
                
                break;
            }
        }
        
        return r;
        
    }
};






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    
    void inorder(TreeNode *root, int p,int &f,TreeNode *&ans)//, int& prev, TreeNode* &ans)
    {
        if(!root)
            return;
        
        inorder(root->left,p,f,ans);
        if(f)
        {
            f = 0;
            ans = root;
        }
        
        if(root->val == p)
            f = 1;
        
        
        inorder(root->right,p,f,ans);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        if(!root)
            return root;
        
        
        TreeNode *r = nullptr; 
        
        int f =0;
        inorder(root, p->val,f,r);//, root->val, r);
        
        return r;
    }
};*/
