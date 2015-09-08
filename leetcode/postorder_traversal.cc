class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ret;
		if (!root) return ret;
		vector<TreeNode*> s;
		TreeNode *last = 0;
		s.push_back(root);
		while (!s.empty()) {
			TreeNode *top = s.back();
			if (!last || last->left == top || last->right == top) {
				if (top->left) {
					s.push_back(top->left);
				} else if (top->right) {
					s.push_back(top->right);
				} else {
					ret.push_back(top->val);
					s.pop_back();
				}
			} else if (top->left == last) {
				if (top->right) {
					s.push_back(top->right);
				} else {
					ret.push_back(top->val);
					s.pop_back();
				}
			} else {
				ret.push_back(top->val);
				s.pop_back();
			}
			last = top;
		}	
		return ret;
	}
};
