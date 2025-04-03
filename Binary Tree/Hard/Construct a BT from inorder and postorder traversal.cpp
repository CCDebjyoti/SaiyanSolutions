class Solution {
public:
    TreeNode*solve(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>&Map){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        
        TreeNode*root=new TreeNode(preorder[preEnd]);//make preorder root a node 

        int inRoot=Map[root->val];//location of root in inorder

        int numsleft=inRoot-inStart;//how many elements in left tree

        root->left=solve(preorder,preStart,preStart+numsleft-1,inorder,inStart,inRoot-1,Map);
        
        root->right=solve(preorder,preStart+numsleft,preEnd-1,inorder,inRoot+1,inEnd,Map);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>Map;
        for(int i=0;i<inorder.size();i++){
            Map[inorder[i]]=i;
        }
        TreeNode*root=solve(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,Map);
        return root;
    }
};
