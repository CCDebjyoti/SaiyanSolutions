class Solution {//0(N) TC O(N) SC avg is O(H)
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       stack<TreeNode*> st;//monotonic stack
        TreeNode*curr=new TreeNode(preorder[0]);//store root 
        st.push(curr);
        for(int i=1;i<preorder.size();i++){
         if(st.top()->val>preorder[i]){//as bst root<right but root>left so breakpoint is after right 
            TreeNode*leftptr=new TreeNode(preorder[i]);
            st.top()->left=leftptr;
            st.push(leftptr);
         }
         else {
         TreeNode*prev;
         while(!st.empty() && st.top()->val<preorder[i]){//maintain monotonically inc stack
            prev=st.top();//prev->right =node
            st.pop();
         }
            TreeNode*rightptr=new TreeNode(preorder[i]);
            prev->right=rightptr;
            st.push(rightptr);
         }
        }
        return curr;
    }
};
