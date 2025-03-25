int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
     
    // Your code here
    int ceilx=-1;
    while(root){
        if(root->data==input){
            ceilx=root->data;
            return ceilx;
        }
        else if(root->data>input){
            ceilx=root->data;//this frist as dont move root first
            root=root->left;
        }
        else {
            root=root->right;
        }
    }
    return ceilx;
}
