vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;//edge case 
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            int sizeq=q.size();//qsize will give us the no of nodes of above level so we can run lopp that many timess and collect children nodes 
            vector<int>level;
            for(int i=0;i<sizeq;i++){
                temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);//if child exist for current nodes store in queue as we are going to pop it 
                if(temp->right)q.push(temp->right);
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
