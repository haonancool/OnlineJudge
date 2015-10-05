class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        queue<int> levels;
        if (root) {
        	q.push(root);
        	levels.push(0);
        }
        vector<int> temp;
        int last_level = 0;
        while (!q.empty()) {
        	TreeNode *node = q.front();
        	q.pop();
        	int level = levels.front();
        	levels.pop();
        	if (level > last_level) {
        		ret.push_back(temp);
        		temp.clear();
        	}
        	temp.push_back(node->val);
        	last_level = level;
        	if (node->left) {
        		q.push(node->left);
        		levels.push(level + 1);
        	}
        	if (node->right) {
        		q.push(node->right);
        		levels.push(level + 1);
        	}
        }
        if (!temp.empty())
        	ret.push_back(temp);
        return ret;
    }
};