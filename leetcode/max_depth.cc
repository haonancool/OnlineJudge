class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
        	return 0;
        int left = maxDepth(root->left), right = maxDepth(root->right);
        int depth = 1 + ((left > right) ? left : right);
        return depth;
    }
};