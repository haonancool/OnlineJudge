class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p = 0, *q = head, *r = head;
		for (int i = 0; i < n; i++)
			r = r->next;
		while (r) {
			p = q;
			q = q->next;
			r = r->next;
		}
		if (!p)
			head = head->next;
		else
			p->next = q->next;
		return head;
	}
};
