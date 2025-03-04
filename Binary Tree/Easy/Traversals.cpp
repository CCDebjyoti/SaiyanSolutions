   void preorder(TreeNode*root){//pre equals root before
        if(root==NULL)return;
        ans.push_back(root->val);
        bfs(root->left);
        bfs(root->right);
    }
    void Inorder(TreeNode*root){//Inorder equals root in middle 
        if(root==NULL)return;
        bfs(root->left);
        ans.push_back(root->val);
        bfs(root->right);
    }
   void postrder(TreeNode*root){//post equals root after left right root
        if(root==NULL)return;
        bfs(root->left);
        bfs(root->right);
        ans.push_back(root->val);
    }
