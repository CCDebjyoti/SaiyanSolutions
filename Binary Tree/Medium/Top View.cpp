vector<int> topView(Node *root) {
        vector<int>ans;
        map<int,int>Map;
        queue<pair<Node*,int>>q;//level and node
        q.push({root,0});
        while(!q.empty()){//as we traverse one level at a time so we dont need to store levels
            auto it=q.front();//first in map level always above the nodes we traverse later 
            Node*temp=q.front().first;
            int level=q.front().second;
            q.pop();
            if(Map.find(level)==Map.end()){//normal level traversal
                Map[level]=temp->data;
            }
            if(temp->left){
                q.push({temp->left,level-1});
            }
            if(temp->right){
                q.push({temp->right,level+1});
            }
        }
        for(auto it:Map){
            ans.push_back(it.second);
        }
        return ans;
    }
