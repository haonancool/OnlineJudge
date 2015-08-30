class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre = 0, *cur = root, *last = 0, *first = 0, *second = 0;
        while (cur) {
        	if (cur->left) {
        		pre = cur->left;
        		while (pre->right && pre->right != cur)
        			pre = pre->right;
        		if (pre->right) {
        			pre->right = 0;
        			if (last && last->val > cur->val) {
        				if (!first)
        					first = last;
        				second = cur;
        			}
        			last = cur;
        			cur = cur->right;
        		} else {
        			pre->right = cur;
        			cur = cur->left;
        		}
        	} else {
        		if (last && last->val > cur->val) {
    				if (!first)
    					first = last;
    				second = cur;
    			}
    			last = cur;
        		cur = cur->right;
        	}
        }
        if (first && second) {
        	int temp = first->val;
        	first->val = second->val;
        	second->val = temp;
        }
    }
};