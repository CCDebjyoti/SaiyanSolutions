class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {//find leaf position to insert
        if(root==NULL)return new TreeNode(val);//edge case 
        TreeNode*curr=root;
        while(true){
            if(curr->val<=val){//go right
            if(curr->right!=NULL)curr=curr->right;
            else {//if null make new node we found our leaf position to insert
                curr->right=new TreeNode(val);
                break;
                }
            }
            else {
                if(curr->left!=NULL)curr=curr->left;
                else {
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
