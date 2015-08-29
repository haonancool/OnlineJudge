class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<TreeNode*> s;
        if (root)
            s.push_back(root);
        while (!s.empty()) {
            if (s.back()->left) {
                s.push_back(s.back()->left);
            } else {
                while (!s.empty()) {
                    TreeNode *top = s.back();
                    ret.push_back(top->val);
                    s.pop_back();
                    if (top->right) {
                        s.push_back(top->right);
                        break;
                    }
                }
            }
        }
        return ret;
    }
};