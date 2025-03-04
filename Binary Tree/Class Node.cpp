class TreeNode{
    public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int v){
        this->val=v;
        this->left=nullptr;
        this->right=nullptr;
    }
};
int main(){
    TreeNode *root=new TreeNode(1);
    TreeNode *leftx=new TreeNode(2);
    TreeNode *rightx=new TreeNode(3);
    root->left=leftx;
    root->right=rightx;
    bfs(root);
    return 0;
}
