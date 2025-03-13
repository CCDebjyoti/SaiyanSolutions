vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        queue<pair<TreeNode*,int>>q;//level and node
        map<int,int>Map;//level,value
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front().first;
            TreeNode*temp=q.front().first;
            int level=q.front().second;
            q.pop();
            if(Map.find(level)==Map.end()){
                Map[level]=temp->val;
            }
            if(temp->right){
                q.push({temp->right,level+1});
            }
            if(temp->left)q.push({temp->left,level+1});
        }
        for(auto it:Map){
            ans.push_back(it.second);
        }
        return ans;
    }
