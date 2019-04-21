/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x =[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:

    int MaxPath(TreeNode *root,int &sum)
    {
        if(!root)
            return 0;
        
        int lft = MaxPath(root->left,sum);
        int rght = MaxPath(root->right,sum);
        
        
        int one = max(root->val, max(lft,rght)+root->val);
        int two = max(lft+rght+root->val,one);    
        
        sum = max(sum,two);
        
        return one;
    }
    
    int maxPathSum(TreeNode* root) {
        
        int sum = INT_MIN;
        if(!root)
          return 0;
        
        MaxPath(root,sum);
        
        return sum;
        
    }
};
