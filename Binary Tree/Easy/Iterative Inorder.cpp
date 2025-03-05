vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;//tc-O(N) sc - O(Height)
        if(root==NULL)return ans;
        stack<TreeNode*>st;
        TreeNode*node=root;
        while(true){
          if(node!=NULL){// traverse till u reach left of all nodes then if null update answer and check for right if null update else traverse right 
            st.push(node);//store nodes in stack
            node=node->left;//first traversal to left as node intially null 
          }
          else {//if NULL
           if(st.empty()==true)break;//break out of loop condition if stack empty and node is null
           ans.push_back(st.top()->val);
           node=st.top();
           node=node->right;//traverse right
           st.pop();
          }
        }
        return ans;
    }
