class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret = generateTrees(1, n);
        return ret;
    }
    vector<TreeNode*> generateTrees(int start, int end) {
    	vector<TreeNode*> ret;
    	if (start > end) {
    		ret.push_back(0);
    		return ret;
    	}
    	for (int i = start; i <= end; i++) {
    		vector<TreeNode*> left_subtrees = generateTrees(start, i - 1);
    		vector<TreeNode*> right_subtrees = generateTrees(i + 1, end);
    		for (int j = 0; j < left_subtrees.size(); j++) {
    			for (int k = 0; k < right_subtrees.size(); k++) {
    				TreeNode *root = new TreeNode(i);
    				root->left = left_subtrees[j];
    				root->right = right_subtrees[k];
    				ret.push_back(root);
    			}
    		}
    	}
    	return ret;
    }
};