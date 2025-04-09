class NodeValue {
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class Solution{
    public:
    NodeValue largestBSTSubtreeHelper(Node* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);//root NULL so return size 0 and normal parameters
        } 
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
    
        if (left.maxNode < root->data && root->data < right.minNode) {//if bst return boundary post order traversal checking while backtracking
            return NodeValue(min(root->data, left.minNode),max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);//l+r+1
        }      
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));//if not bst swap int min and max no other bst ever will be true
    }
    int largestBst(Node *root)
    {
    	return largestBSTSubtreeHelper(root).maxSize;
    }
};
