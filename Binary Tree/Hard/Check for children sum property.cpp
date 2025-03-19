void changeTree(TreeNode* root) {//while going down left/right change childs values to root then while coming back up add 2 child to get 2x of root 
        if (root == NULL) return;//another if child is bigger then make root = sum of child 
        int child = 0;
        if (root->left) {//calc sum of child nodes 
            child += root->left->val;
        }
        if (root->right) {
            child += root->right->val;
        }
        // Compare the sum of children with the current node's value and update
        if (child >= root->val) {
            root->val = child;
        } else {
            // If the sum is smaller, update the child with the current node's value.
            if (root->left) {
                root->left->val = root->val;
            } else if (root->right) {
                root->right->val = root->val;
            }
        }
        changeTree(root->left);
        changeTree(root->right);
        // Calculate the total sum of the  values of the left and right  children, if they exist.
        int tot = 0;
        if (root->left) {
            tot += root->left->val;
        }
        if (root->right) {
            tot += root->right->val;
        }
        // If either left or right childexists, update the current node's value with the total sum.
        if (root->left or root->right) {
            root->val = tot;
        }
    }
