class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1)
            return head;
        ListNode *ret = 0, *p = head, *q = p->next, *r = q->next;
        ListNode *last_group_tail = 0;
        while (true) {
            ListNode *temp = p;
            int i;
            for (i = 0; i < k - 1; i++) {
                if (temp->next)
                    temp = temp->next;
                else
                    break;
            }
            if (i < k - 1) {
                if (last_group_tail)
                    last_group_tail->next = p;
                break;
            }
            ListNode *group_tail = p;
            for (i = 0; i < k - 1; i++) {
                q->next = p;
                p = q;
                q = r;
                if (r)
                    r = r->next;
            }
            if (last_group_tail)
                last_group_tail->next = p;
            last_group_tail = group_tail;
            if (!ret)
                ret = p;
            if (!q) {
                group_tail->next = 0;
                break;
            } else {
                p = q;
                q = r;
                if (r)
                    r = r->next;
            }
        }
        if (!ret)
            ret = head;
        return ret;
    }
};