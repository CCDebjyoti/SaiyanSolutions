class Solution {
public:
    bool solve(TreeNode*p,TreeNode*q,bool & ans){
        if(p==NULL){
            if(q!=NULL)return false;//if null!=null
            return true;
        }
        if(q==NULL){//call func for right left and left right to verify
            if(p!=NULL)return false;
            return true;
        }
        if(p->val!=q->val)return false;//check val
        return solve(p->left,q->right,ans) && solve(p->right,q->left,ans);//AND operation return if even one false all false
    }
    bool isSymmetric(TreeNode* root) {
      bool ans=true;
      return solve(root->left,root->right,ans);
    }
};
