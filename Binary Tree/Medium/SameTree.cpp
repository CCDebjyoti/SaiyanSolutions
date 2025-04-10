class Solution {
public:
    bool solve(TreeNode*p,TreeNode*q){
        if(p==NULL){
          if(q!=NULL)return false;
          return true;
        }
        if(q==NULL){
            if(p!=NULL)return false;
            return true;
        }
        if(p->val!=q->val)return false;
        return solve(p->left,q->left)&&solve(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
