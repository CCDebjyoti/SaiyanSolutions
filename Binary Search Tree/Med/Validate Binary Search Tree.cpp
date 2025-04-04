class Solution {
public:
    bool solve(TreeNode*root,long long mini,long long maxi){
        if(root==NULL)return true;
        if(root->val>=maxi || root->val<=mini)return false;
        return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);
    }/
    bool isValidBST(TreeNode* root) {
       return solve(root,LLONG_MIN,LLONG_MAX);
    }
};
