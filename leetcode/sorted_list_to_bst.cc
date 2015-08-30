class Solution {
public:
	ListNode *p = 0;
    TreeNode* sortedListToBST(ListNode* head) {
    	int len = 0;
    	for (ListNode *q = head; q; q = q->next)
    		len++;
    	p = head;
        return helper(0, len - 1);
    }
    TreeNode* helper(int start, int end) {
    	if (start > end)
    		return 0;
    	int mid = (start + end) / 2;
    	TreeNode *left = helper(start, mid - 1);
    	TreeNode *root = new TreeNode(p->val);
    	p = p->next;
    	TreeNode *right = helper(mid + 1, end);
    	root->left = left;
    	root->right = right;
    	return root;
    }
};