class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *p_head = 0, *q_head = 0, *p_tail = 0, *q_tail = 0;
        for (ListNode *cur = head; cur; cur = cur->next) {
        	if (cur->val < x) {
        		if (p_head) {
        			p_tail->next = cur;
        			p_tail = cur;
        		} else {
        			p_head = p_tail = cur;
        		}
        	} else {
        		if (q_head) {
        			q_tail->next = cur;
        			q_tail = cur;
        		} else {
        			q_head = q_tail = cur;
        		}
        	}
        }
        if (p_tail)
        	p_tail->next = q_head;
        if (q_tail)
        	q_tail->next = 0;
        if (p_head)
        	head = p_head;
        else
        	head = q_head;
        return head;
    }
};