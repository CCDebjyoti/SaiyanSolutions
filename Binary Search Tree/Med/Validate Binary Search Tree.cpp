class Solution {
public:
    bool solve(TreeNode*root,long long mini,long long maxi){
        if(root==NULL)return true;
        if(root->val>=maxi || root->val<=mini)return false;//Must lie in the range of maxi to mini
        return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);//for left the root->val is the max element allowed 
    }//for right the min val of the subtree must be greater than mini root->val
    bool isValidBST(TreeNode* root) {
       return solve(root,LLONG_MIN,LLONG_MAX);
    }
};
