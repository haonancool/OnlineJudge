#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		ListNode *p = head;
		int len = 0;
		while (p) {
			p = p->next;
			len++;
		}
		if (len <= 1) return;
		ListNode *q = head;
		for (int i = 0; i < (len + 1) / 2; i++)
			q = q->next;
		p = 0;
		ListNode *r = q->next;
		while (q) {
			q->next = p;
			p = q;
			q = r;
			if (r) r = r->next;
		}
		q = p;
		p = head;
		for (int i = 0; i < len / 2; i++) {
			ListNode *m = p->next, *n = q->next;
			p->next = q;
			q->next = m;
			p = m;
			q = n;
		}
		if (p)
			p->next = 0;
	}
};

int main() {
	int tmp;
	ListNode *head = 0, *p = 0;
	while (cin >> tmp) {
		ListNode *q = new ListNode(tmp);
		if (!head)
			head = q;
		else
			p->next = q;
		p = q;
	}
	Solution sol;
	sol.reorderList(head);
	p = head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
