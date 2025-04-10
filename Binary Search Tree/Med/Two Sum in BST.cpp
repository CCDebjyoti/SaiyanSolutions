class BSTIterator {//TC-O(N) SC-2*O(H) as two stacks one for before one for next
public://false-- next //true - before
    stack<TreeNode*>st;
    bool reverse=true;
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }
    bool hasNext() {
       if(st.empty())return false;
       return true;
    }
    int next() {
        TreeNode*temp=st.top();
        st.pop();
        if(!reverse)pushAll(temp->right);//for next 
        else pushAll(temp->left);//for before
        return temp->val;
    }
    private:
    void pushAll(TreeNode*root){
        while(root!=NULL){
            st.push(root);
            if(reverse==true)root=root->right;
            else root=root->left;
        }
        return;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        BSTIterator l(root,false);//object 1 
        //l for next 
        BSTIterator r(root,true);//object 2
        //r for before 
        int i=l.next();
        int j=r.next();
        while(i<j){//iterate till array sorted of monotonically increasing //i<j
            if((i+j)==k)return true;
            else if((i+j)<k)i=l.next();
            else j=r.next();
        }
        return false;
    }
};
