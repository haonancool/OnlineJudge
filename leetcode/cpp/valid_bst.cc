class Solution {
public:
	bool isValidBST(TreeNode *root) {
		return helper(root, INT_MIN, INT_MAX, false, false);
	}
	bool helper(TreeNode *root, int low, int high, bool checkLow, bool checkHigh) {
		if (!root)
			return true;
		if (checkLow && root->val <= low || checkHigh && root->val >= high)
			return false;
		if (root->left && root->left->val > root->val)
			return false;
		if (root->right && root->right->val < root->val)
			return false;
		return helper(root->left, low, root->val, checkLow, true) && helper(root->right, root->val, high, true, checkHigh);
	}
};
