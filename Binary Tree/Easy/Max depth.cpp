int ans=0;
    void depth(TreeNode*root,int height){
        if(root==NULL){
            ans=max(ans,height);
            return ;
        }
        depth(root->left,height+1);
        depth(root->right,height+1);
    }
    int maxDepth(TreeNode* root) {
        depth(root,0);
        return ans;
    }
