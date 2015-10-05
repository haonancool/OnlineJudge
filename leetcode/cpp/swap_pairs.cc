class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *ret = 0, *p = 0, *q = head;
		if (!head || !head->next)
			return head;
		while (q && q->next) {
			ListNode *r = q->next;
			q->next = r->next;
			r->next = q;
			if (p)
				p->next = r;
			p = q;
			q = q->next;
			if (!ret)
				ret = r;
		}
		return ret;
	}
};
