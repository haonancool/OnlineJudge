#include <iostream>

using namespace std;

struct Node {
	int val;
	Node *next;
};

void arrangeList(Node *head) {
	// compute length
	Node *p = head;
	int len = 0;
	while (p) {
		p = p->next;
		len++;
	}
	if (len <= 1) return;
	// split list
	Node *q = head;
	for (int i = 0; i < (len + 1) / 2; i++)
		q = q->next;
	p = 0;
	Node *r = q->next;
	// reverse second half
	while (q) {
		q->next = p;
		p = q;
		q = r;
		if (r) r = r->next;
	}
	// merge list
	q = p;
	p = head;
	for (int i = 0; i < len / 2; i++) {
		Node *m = p->next, *n = q->next;
		p->next = q;
		q->next = m;
		p = m;
		q = n;
	}
	if (p)
		p->next = 0;
}

int main() {
	Node list[5];
	for (int i = 0; i < 5; i++) {
		list[i].val = i + 1;
		if (i < 4)
			list[i].next = &list[i + 1];
		else
			list[i].next = 0;
	}
	arrangeList(list);
	Node *p = list;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}
