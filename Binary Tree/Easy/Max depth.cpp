class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)//TC-O(N) SC-O(N)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return max(lh, rh) + 1;
    }
};
