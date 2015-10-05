class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m == n)
        	return head;
        ListNode *p = 0, *q = head, *r = head->next, *pre = 0, *first = 0;
        for (int i = 1; i <= n; i++) {
        	if (i >= m) {
        		q->next = p;
        		if (i == m) {
        			pre = p;
        			first = q;
        		}
        		if (i == n) {
        			first->next = r;
        			if (pre)
        				pre->next = q;
        			else
        				head = q;
        		}
        	}
        	p = q;
        	q = r;
        	if (r)
        		r = r->next;
        }
        return head;
    }
};