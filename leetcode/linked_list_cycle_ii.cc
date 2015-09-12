class Solution {
public:
	ListNode* detectCycle(ListNode *head) {
		if (!head) return 0;
		ListNode *p = head, *q = head;
		while (1) {
			p = p->next;
			q = q->next;
			if (!q) return 0;
			q = q->next;
			if (!q) return 0;
			if (p == q) break;
		}
		p = head;
		while (p != q) {
			p = p->next;
			q = q->next;
		}
		return p;
	}
};
