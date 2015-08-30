class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int start, int end) {
    	if (start > end)
    		return 0;
    	int mid = (start + end) / 2;
    	TreeNode *root = new TreeNode(nums[mid]);
    	root->left = helper(nums, start, mid - 1);
    	root->right = helper(nums, mid + 1, end);
    	return root;
    }
};