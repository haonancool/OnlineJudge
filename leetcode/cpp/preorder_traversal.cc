class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ret;
		if (!root) return ret;
		vector<TreeNode*> s;
		s.push_back(root);
		while (!s.empty()) {
			TreeNode *cur = s.back();
			s.pop_back();
			ret.push_back(cur->val);
			if (cur->right)
				s.push_back(cur->right);
			if (cur->left)
				s.push_back(cur->left);
		}
		return ret;
	}
};
