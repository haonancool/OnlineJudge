class Solution {
public:
	int ret;
    int sumNumbers(TreeNode* root) {
        if (!root)
        	return 0;
        ret = 0;
        helper(root, 0);
        return ret;
    }
    void helper(TreeNode* root, int sum) {
    	sum *= 10;
    	sum += root->val;
    	if (!root->left && !root->right) {
    		ret += sum;
    	} else {
    		if (root->left)
    			helper(root->left, sum);
    		if (root->right)
    			helper(root->right, sum);
    	}
    }
};