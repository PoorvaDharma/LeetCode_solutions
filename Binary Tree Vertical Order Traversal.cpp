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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        vector<vector<int>> v1;
        //vector<int> v;
        map<int, vector<int>> m;
        queue<pair<TreeNode *,int>> q;
        
        if(!root)
            return v1;
        
        q.push(make_pair(root,0));
        
        while(!q.empty())
        {
            TreeNode *T = q.front().first;
            int l = q.front().second;
            q.pop();
            
            m[l].push_back(T->val);
            
            if(T->left)
                q.push(make_pair(T->left,l-1));
            if(T->right)
                q.push(make_pair(T->right,l+1));
        }
        
        for(auto i=m.begin();i!=m.end();i++)
          v1.push_back(i->second);
        
        return v1;
    }
    /* In dfs the order is not correct 3,9,8,4,0,1,7,null,null,null,2
    
     void HD(TreeNode *r,map<int, vector<int>> &m,int l)
    {
       if(!r)
          return;
    
       m[l].push_back(r->val);
    
       HD(r->left,m,l-1);
       HD(r->right,m,l+1);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        vector<vector<int>> v1;
        vector<int> v;
        map<int, vector<int>> m;
        
        HD(root,m,0);
        
        //int j = 0;
        for(auto i=m.begin();i!=m.end();i++)
        {
          for( auto it  = i->second.begin(); it!=i->second.end(); ++it)
               v.push_back(*it);
          v1.push_back(v);
          v.clear();  
        }
        
        return v1;
    }*/
};
