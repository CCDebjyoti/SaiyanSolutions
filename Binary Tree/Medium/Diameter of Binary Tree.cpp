class Solution {
public:
    int depth(TreeNode*root,int &dia){//passing max dia via address 
        if(root==NULL){
           return 0;
        }
        int l=depth(root->left,dia);
        int r=depth(root->right,dia);
        dia=max(dia,l+r);//storing maximum diameter for each node 
        return 1+max(l,r);
        }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        depth(root,dia);
        return dia;
    }
};
