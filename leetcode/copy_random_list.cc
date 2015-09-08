class Solution {
public:
	RandomListNode* copyRandomList(RandomListNode *head) {
		if (!head) return 0;
		unordered_map<RandomListNode*, RandomListNode*> table;
		RandomListNode *ret = new RandomListNode(head->label);
		table[head] = ret;
		RandomListNode *p = head, *q = ret;
		while (p && q) {
			if (p->next) {
				if (table.find(p->next) != table.end()) {
					q->next = table[p->next];
				} else {
					q->next = new RandomListNode(p->next->label);
					table[p->next] = q->next;
				}
			} else {
				q->next = 0;
			}
			if (p->random) {
				if (table.find(p->random) != table.end()) {
					q->random = table[p->random];
				} else {
					q->random = new RandomListNode(p->random->label);
					table[p->random] = q->random;
				}
			} else {
				q->random = 0;
			}
			p = p->next;
			q = q->next;
		}
		return ret;
	}
};
