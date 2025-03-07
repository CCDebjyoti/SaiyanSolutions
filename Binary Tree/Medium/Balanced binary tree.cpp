class Solution {
public:
     int depth(TreeNode*root,bool &ans){
        if(root==NULL){
           return 0;
        }
        int l=depth(root->left,ans);
        int r=depth(root->right,ans);
        if(abs(l-r)>1)ans=false;//checking for every node subtree
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        int call=depth(root,ans);
        return ans;
    }
};
