class Solution {
public:
    void parent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mParnt){
        queue<TreeNode*>q;//this function makes a map which points to the parents of each and every node 
        q.push(root);//so we can traverse up and above 
        while(!q.empty()){//normal level traversal BFS we just add parent node to map - child --> parent 
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
            TreeNode*temp=q.front();//current head or parent
            q.pop();
            if(temp->left){
                q.push(temp->left);
                mParnt[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                mParnt[temp->right]=temp;
            }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>Par;
        parent(root,Par);
        queue<TreeNode*>q;//we travel in 3 direction on left one right and one above in parent side 
        unordered_map<TreeNode*,bool>visited;//visited array created to make sure we dont come back to original node from where we traversed
        visited[target]=true;//we start traversal from target and go 3 ways visited helps us not to come back at target again
        q.push(target);
        int currdist=0;
        while(!q.empty()){//normal level traversal starting from target 
         if(currdist==k)break;
         currdist++;
         int qsize=q.size();
         for(int i=0;i<qsize;i++){
          TreeNode*temp=q.front();
            q.pop();
            if(temp->left && visited[temp->left]==false){
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && visited[temp->right]==false){
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(Par[temp] && visited[Par[temp]]==false){//if parent exists and if not visited 
                q.push(Par[temp]);
                visited[Par[temp]]=true;
            }
         }
        }
        vector<int>ans;
        while(!q.empty()){//what ever is left at queue is our ans
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
