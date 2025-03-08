class Solution {//or just do pre order but root right left and then just reverse it at last M-2
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>post;
        TreeNode*curr=root;
        TreeNode*temp;
        while(!st.empty() || curr!=NULL){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else {//ifNULL
            temp=st.top()->right;
            if(temp==NULL){
             temp=st.top();
             st.pop();
             post.push_back(temp->val);
             while(!st.empty()&&temp==st.top()->right){
                temp=st.top();//when stack top equal to right of whats below it 
                st.pop();
                post.push_back(temp->val);
             }
            }
            else {
                curr=temp;
            }
            }
        }
        return post;
    }
};
