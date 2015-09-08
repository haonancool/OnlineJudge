class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head) return false;
		ListNode *p = head, *q = head;
		while (1) {
			p = p->next;
			q = q->next;
			if (!q) return false;
			q = q->next;
			if (!q) return false;
			if (p == q) return true;
		}
		return false;
	}
};
