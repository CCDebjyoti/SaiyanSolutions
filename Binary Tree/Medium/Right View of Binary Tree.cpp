vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;//edge case 
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            int sizeq=q.size();
            vector<int>level;
            for(int i=0;i<sizeq;i++){//just level order traversal add first node and add right first 
                temp=q.front();
                q.pop();
                if(temp->right)q.push(temp->right);
                if(temp->left)q.push(temp->left);
                if(i==0)ans.push_back(temp->val);
            }
        }
        return ans;
    }
