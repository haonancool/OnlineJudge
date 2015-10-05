class Solution {
public:
	bool first;
	int ret;
    int maxPathSum(TreeNode* root) {
    	ret = 0;
    	first = true;
        helper(root);
        return ret;
    }
    int helper(TreeNode* root) {
    	if (!root)
    		return 0;
		int left = helper(root->left), right = helper(root->right);
		int temp = root->val;
		if (left > 0)
			temp += left;
		if (right > 0)
			temp += right;
		if (first) {
			ret = temp;
			first = false;
		} else if (temp > ret) {
			ret = temp;
		}
		if (left < 0 && right < 0)
			return root->val;
		else if (left > right)
			return root->val + left;
		else
			return root->val + right;
	}
};