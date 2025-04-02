class Solution {
public:
//pass the map refernce...when we pass map without refernce it start to copy all the value..if we pass the reference it only take base address
    TreeNode*solve(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>&Map){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        
        TreeNode*root=new TreeNode(preorder[preStart]);//make preorder root a node 

        int inRoot=Map[root->val];//location of root in inorder

        int numsleft=inRoot-inStart;//how many elements in left tree

        root->left=solve(preorder,preStart+1,preStart+numsleft,inorder,inStart,inRoot-1,Map);
        //preStart+1 as next root ending at prest+leftofinorderno's(left tree)
        root->right=solve(preorder,preStart+numsleft+1,preEnd,inorder,inRoot+1,inEnd,Map);
        //prest+numsleft coz next root needed of right tree 
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>Map;
        for(int i=0;i<inorder.size();i++){
            Map[inorder[i]]=i;//storing all inorder vals index in map
        }//for easy acess of roots location to divide left and right subtree
        TreeNode*root=solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,Map);
        return root;
    }
};
/*//for better understanding and pointers(indexes)
IN-[40,20,50,10,60,30]
PRE-[10,20,40,50,30,60]
                                       10
                                    /      \
                              IN-40,20,50   60,30
                              PRE-20,40,50  30,60
                               20               30
                              /  \             /  \ 
                 IN & PRE    40  50           60   X
                              
                              
*/
