vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>st;
        st.push(root);
        TreeNode*node;
        while(!st.empty()){//push root then push its children 
            node=st.top();
            st.pop();
            ans.push_back(node->val);//push root 
            if(node->right)st.push(node->right);//right first as lifo and we want left to come first 
            if(node->left)st.push(node->left);
        }
        return ans;
    }
