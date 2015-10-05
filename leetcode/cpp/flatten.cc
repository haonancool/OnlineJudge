class Solution {
public:
	TreeNode *last;
    void flatten(TreeNode* root) {
    	if (!root)
    		return;
    	last = 0;
    	helper(root);
    }
    void helper(TreeNode* root) {
    	TreeNode *left = root->left, *right = root->right;
    	root->left = root->right = 0;
    	if (last)
    		last->right = root;
    	last = root;
    	if (left)
    		helper(left);
    	if (right)
    		helper(right);
    }
};