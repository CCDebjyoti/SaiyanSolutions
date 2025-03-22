class Solution {//O(logN)^2 logN is height of the tree so going left or right (at max we traverse)
public:
    int leftheight(TreeNode*root){//all nodes of complete binary tree completely filled except leaf nodes 
        int ans=0;//no of nodes 2^N -1 
        while(root){
            root=root->left;
            ans++;
        }
        return ans;
    }
    int rightheight(TreeNode*root){
        int ans=0;
        while(root){
            root=root->right;
            ans++;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        int lh=leftheight(root);//left height of subtree 
        int rh=rightheight(root);
        if(lh==rh)return pow(2,lh)-1;//if lh==rh then no of nodes is 2^N-1 
        return 1+countNodes(root->left)+countNodes(root->right);//else traverse deeper in tree to find root(1) + left + right recursively 
    }
};
