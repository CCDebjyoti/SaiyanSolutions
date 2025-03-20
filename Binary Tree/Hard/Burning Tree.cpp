class Solution {
  public://M-2 You can find the height  of tree  using dfs cosidering target node as root node and also taking the help of visited map. 
    Node* parent(Node*root,unordered_map<Node*,Node*>&mParnt,int target){//find dist from target to leftmost rightmost and root then max of all
        queue<Node*>q;
        q.push(root);
        Node*T;
        while(!q.empty()){
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
            Node*temp=q.front();
            if(temp->data==target)T=temp;
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
        return T;
    }
    int minTime(Node* root, int target) {
        // code here
        if(root==NULL)return 0;
        unordered_map<Node*,Node*>Par;
        queue<Node*>q;
        unordered_map<Node*,bool>visited;
        Node*T=parent(root,Par,target);
        visited[T]=true;
        q.push(T);
        int ans=0;
        while(!q.empty()){
         int fl=0;//not always we will burn some nodes like leaf wont burn anyone and they themselves are already burned 
         int qsize=q.size();//so we use flag to check if any node burned or then ans ++
         for(int i=0;i<qsize;i++){
            Node*temp=q.front();
            q.pop();
            if(temp->left && visited[temp->left]==false){
                q.push(temp->left);
                visited[temp->left]=true;
                fl=1;
            }
            if(temp->right && visited[temp->right]==false){
                q.push(temp->right);
                visited[temp->right]=true;
                fl=1;
            }
            if(Par[temp] && visited[Par[temp]]==false){
                q.push(Par[temp]);
                visited[Par[temp]]=true;
                fl=1;
            }
         }
         if(fl)ans++;
        }
        return ans;
    }
};
