class Solution {
public:
	vector<vector<int>> ret;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<int> temp;
        helper(root, temp, sum);
        return ret;
    }
    void helper(TreeNode* root, vector<int> &temp, int sum) {
    	if (!root)
        	return;
        temp.push_back(root->val);
        if (!root->left && !root->right) {
        	if (root->val == sum)
        		ret.push_back(temp);
        } else if (!root->left) {
        	helper(root->right, temp, sum - root->val);
        } else if (!root->right) {
        	helper(root->left, temp, sum - root->val);
        } else {
        	helper(root->left, temp, sum - root->val);
        	helper(root->right, temp, sum - root->val);
        }
        temp.pop_back();
    }
};