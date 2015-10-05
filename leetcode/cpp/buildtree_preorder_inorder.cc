class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() && inorder.empty())
        	return 0;
        return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int i, int left, int right) {
    	TreeNode *root = new TreeNode(preorder[i]);
    	int j;
    	for (j = left; j <= right; j++) {
    		if (inorder[j] == preorder[i])
    			break;
    	}
    	if (j > left)
    		root->left = buildTree(preorder, inorder, i + 1, left, j - 1);
    	else
    		root->left = 0;
    	if (j < right)
    		root->right = buildTree(preorder, inorder, i + j - left + 1, j + 1, right);
    	else
    		root->right = 0;
    	return root;
    }
};