class Solution {
  public:
     vector<vector<int>>ans;
     void solve(Node*root,vector<int>&op){
         if(root==NULL){//if you add answer here then u will return and go back for the leafs right node
             return;//and cause duplicate answers for the ans variable so return from leaf node only
         }
         op.push_back(root->data);
         if(root->left==NULL && root->right==NULL)ans.push_back(op);
         if(root->left)solve(root->left,op);
         if(root->right)solve(root->right,op);
         op.pop_back();
         
     }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int>op;
        solve(root,op);
        return ans;
    }
};
