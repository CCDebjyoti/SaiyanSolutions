//TC-O(H)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//RECURSIVE SOL
        if(root==NULL)return NULL;
        if(root->val<p->val && root->val<q->val)return lowestCommonAncestor(root->right,p,q);//if both lie to right go right
        if(root->val>p->val && root->val>q->val)return lowestCommonAncestor(root->left,p,q);//if both lie to left go left
        return root;//if one to left and one to right we got our answer as this is the lowest point of split btw the two nodes 
    }//even if p parent of q or vice  versa still as we need to return p then and their no more need of traversal
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//ITERATIVE SOL
        TreeNode*curr=root;
        while(curr!=NULL){
        if(curr->val > p->val && curr->val>q->val)curr=curr->left;
        else if(curr->val < p->val && curr->val<q->val)curr=curr->right;
        else break;
        }
        return curr;
    }
