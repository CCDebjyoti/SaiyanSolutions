class Solution {//for kth largest just do reverse inorder right root left
public:
     int ans=0;
     void solve(TreeNode*root,int & cnt,int k){//cnt as refernce not by value 
        if(root==NULL)return ;//normal inorder in bst will give left(smallest) root(in middle) right (largest)
        solve(root->left,cnt,k);//so inorder of bst will give us sorted 
        cnt++;//increase cnt for each node so for inorder after left traversal
        if(cnt==k)ans=root->val;//check for if equals k 
        solve(root->right,cnt,k);
     }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        solve(root,cnt,k);
        return ans;
    }
};
