class Solution {//every node must be in some range 
public://for left it cannot have a val greater than root
    bool solve(TreeNode*root,long long mini,long long maxi){//for right it cant have any val lessser than min
        if(root==NULL)return true;
        if(root->val>=maxi || root->val<=mini)return false;//for left the root->val is the max element allowed 
        return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);//for right the min val of the subtree must be greater than mini root->val
    }
    bool isValidBST(TreeNode* root) {
       return solve(root,LLONG_MIN,LLONG_MAX);

    }
};
