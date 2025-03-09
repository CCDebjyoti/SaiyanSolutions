class Solution {
public:
    int sumdepth(TreeNode*root,int &ans){
        if(root==NULL)return 0;//travel to the node end null
        int l=max(0,sumdepth(root->left,ans));//ignore negative sum as they will never give us the answer we want so max of 0
        int r=max(0,sumdepth(root->right,ans));
         ans=max(ans,root->val+l+r);//store ans of curr node
        return max(l,r)+root->val;//return only max of l and r 
        }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int x=sumdepth(root,ans);
        return ans;
    }
};
