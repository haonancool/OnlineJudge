class Solution {
public:
	ListNode* deleteDuplicates(ListNode *head) {
		if (!head) return 0;
		ListNode *newHead = 0, *p = head, *r = 0;
		bool flag = false;
		for (ListNode *q = head->next; ; q = q->next) {
			if (!q || p->val != q->val) {
				if (!flag) {
					if (newHead) {
						r->next = p;
						r = p;
					} else {
						newHead = p;
						r = p;
					}
				}
				flag = false;
				p = q;
			} else {
				flag = true;
			}
			if (!q) break;
		}
		if (r) r->next = 0;
		return newHead;
	}
};
