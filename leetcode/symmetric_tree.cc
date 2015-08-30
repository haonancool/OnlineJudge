class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if (!root)
    		return true;
        if (root->left && root->right)
        	return helper(root->left, root->right);
        else if (!root->left && !root->right)
        	return true;
        return false;
    }
	bool helper(TreeNode* p, TreeNode* q) {
		if (p && q) {
			if (p->val != q->val)
        		return false;
        	return helper(p->left, q->right) && helper(p->right, q->left);
		} else if (!p && !q) {
			return true;
		}
		return false;
    }
};