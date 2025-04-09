class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {//initializee the call 
        pushAll(root);
    }
    void pushAll(TreeNode*root){//push all elements of current node left to the stack 
        while(root!=NULL){//we actually get the inorder traversal like this 
            st.push(root);
            root=root->left;
        }
        return;
    }
    int next() {// pop the value from top of stack then just check if right present of current if present add them to node
        TreeNode*temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {//if stack is empty at anytime meaning we dont have any next present 
       if(!st.empty())return true;
       return false;
    }
};
