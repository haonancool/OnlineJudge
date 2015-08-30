class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty() && inorder.empty())
        	return 0;
        return buildTree(postorder, inorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int i, int left, int right) {
    	TreeNode *root = new TreeNode(postorder[i]);
    	int j;
    	for (j = left; j <= right; j++) {
    		if (inorder[j] == postorder[i])
    			break;
    	}
    	if (j > left)
    		root->left = buildTree(postorder, inorder, i - (right - j) - 1, left, j - 1);
    	else
    		root->left = 0;
    	if (j < right)
    		root->right = buildTree(postorder, inorder, i - 1, j + 1, right);
    	else
    		root->right = 0;
    	return root;
    }
};