class Solution {
public:
	ListNode* insertionSortList(ListNode *head) {
		if (!head) return 0;
		ListNode *ret = head;
		head = head->next;
		ret->next = 0;
		while (head) {
			ListNode *p = ret, *q = head;
			head = head->next;
			if (p->val > q->val) {
				q->next = p;
				ret = q;
			} else {
				while (p->next && p->next->val < q->val)
					p = p->next;
				q->next = p->next;
				p->next = q;
			}
		}
		return ret;
	}
};
