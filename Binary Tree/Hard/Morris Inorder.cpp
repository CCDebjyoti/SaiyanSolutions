class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode*curr=root;
        while(curr!=NULL){
         if(curr->left==NULL){//if left null we got our node print it
            inorder.push_back(curr->val);
            curr=curr->right;//now go right
         }
         else {
            TreeNode*prev=curr->left;
            while(prev->right && prev->right!=curr){//2nd  cond for a case where prev points to curr
                prev=prev->right;//go to the rightmost element of that left subtree
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else {
                prev->right=NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
         }
        }
        return inorder;
    }
};
