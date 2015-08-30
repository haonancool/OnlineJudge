class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
        	return 0;
        int left = minDepth(root->left), right = minDepth(root->right);
        if (0 == left)
        	return right + 1;
        else if (0 == right)
        	return left + 1;
        else if (left < right)
        	return left + 1;
        else
        	return right + 1;
    }
};