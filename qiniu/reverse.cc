#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode *head) {
	if (!head) return head;
	ListNode *p = nullptr, *q = head, *r = head->next;
	while (q) {
		q->next = p;
		p = q;
		q = r;
		if (r)
			r = r->next;
	}
	return p;
}

int main() {
	int n;
	ListNode *head = nullptr, *tail = nullptr;
	while (cin >> n) {
		ListNode *p = new ListNode(n);
		if (head) {
			tail->next = p;
			tail = p;
		} else {
			head = tail = p;
		}
	}
	head = reverse(head);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}
