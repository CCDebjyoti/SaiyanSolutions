class Solution {
public:
    TreeNode*findlastright(TreeNode*root){//last right points to left child
        if(root->right==NULL)return root;//we connect root to key->left 
        return findlastright(root->right);
    }
    TreeNode*helper(TreeNode*root){
        if(root->right==NULL)return root->left;//just point root to left
        else if(root->left==NULL)return root->right;
        TreeNode*rightchild=root->right;
        TreeNode*Lastright=findlastright(root->left);//last right of left subtree smaller than entire right sibtree
        Lastright->right=rightchild;
        return root->left;//as we have connected lastright of left subtree to right child 
    }
    TreeNode* deleteNode(TreeNode* root, int key) {//O(height of tree)
        if(root==NULL)return root;
        if(root->val==key)return helper(root);
        TreeNode*curr=root;
        while(curr!=NULL){
            if(curr->val>key){
             if(curr->left!=NULL && curr->left->val==key){
              curr->left=helper(curr->left);
              break;
             }
             else curr=curr->left;
            }
            else {
                if(curr->right!=NULL && curr->right->val==key){
                    curr->right=helper(curr->right);
                    break;
                }
                else curr=curr->right;
            }
        }
        return root;
    }
};
