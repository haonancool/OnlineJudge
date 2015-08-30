class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
        	return true;
        int depth = 0;
        return helper(root, depth);
    }
    bool helper(TreeNode *root, int &depth) {
    	if (!root) {
    		depth = 0;
    		return true;
    	}
    	int left = 0, right = 0;
    	bool ret = false;
    	if (helper(root->left, left) && helper(root->right, right) &&
    		left - right >= -1 && left - right <= 1)
    		ret = true;
    	depth = left;
    	if (depth < right)
    		depth = right;
    	depth++;
    	return ret;
    }
};