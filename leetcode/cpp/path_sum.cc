class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        	return false;
        if (!root->left && !root->right)
        	return root->val == sum;
        else if (!root->left)
        	return hasPathSum(root->right, sum - root->val);
        else if (!root->right)
        	return hasPathSum(root->left, sum - root->val);
        else
        	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};