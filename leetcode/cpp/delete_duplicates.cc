class Solution {
public:
	ListNode* deleteDuplicates(ListNode *head) {
		if (!head) return 0;
		ListNode *p = head;
		for (ListNode *q = head->next; q; q = q->next) {
			if (p->val != q->val) {
				p->next = q;
				p = q;
			}
		}
		if (p) p->next = 0;
		return head;
	}
};
