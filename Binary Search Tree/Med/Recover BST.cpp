class Solution {
private://we actually do inorder traversal 
TreeNode*first;//stores the node of the 1st violation node 
TreeNode*prev;//stores prev values to check sorted order in inorder traversal
TreeNode*middle;//stores the next node of first violation(used for adjacent nodes case)
TreeNode*last;//stores the 2nd violation
private:
void inorder(TreeNode*root){
    if(root==NULL)return;
    inorder(root->left);//normal inorder traversal
    if(prev!=NULL &&(prev->val>root->val)){
        if(first==NULL){
            first=prev;//1st violation
            middle=root;
        }
        else last=root;
    }
    prev=root;//inorder so root go 
    inorder(root->right);
}
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last){//if first and last !NULL (NOT adjacent case)
            swap(first->val,last->val);
        }
        else swap(first->val,middle->val);//adjacent case swap middle and first
    }
};
