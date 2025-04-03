void solve(TreeNode*root,TreeNode*&prev){//Recursive sol
        if(root==NULL)return;
        solve(root->right,prev);//reverse postorder traversal
        solve(root->left,prev);//left child will point to right child 
        root->right=prev;//backtracking so root->right=any node below
        root->left=NULL;
        prev=root;//update prev
    }
    void flatten(TreeNode* root) {
        TreeNode*prev=NULL;
        solve(root,prev);
        return;
    }
    void flatten(TreeNode* root) {//stack sol
        if(root==NULL)return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){//stack push right left (similar to preorder iterative)
        TreeNode*temp=st.top();
        st.pop();
        if(temp->right)st.push(temp->right);
        if(temp->left)st.push(temp->left);
        if(!st.empty())temp->right=st.top();//root right points to whatever is top of stack
        temp->left=NULL;//make left null
        }
        return;
    }
    void flatten(TreeNode* root) {//Morris sol O(1) space 
        if(root==NULL)return;//last guy of left subtree(rightmost) points to root->right 1st guy similar to preorder
        TreeNode*curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
             TreeNode*prev=curr->left;
             while(prev->right)prev=prev->right;
             prev->right=curr->right;
             curr->right=curr->left;
             curr->left=NULL;
            }
            curr=curr->right;
        }
        return ;
    }
