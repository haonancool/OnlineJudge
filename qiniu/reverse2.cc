#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode *head) {
	if (!head) return nullptr;
	if (!head->next) return head;
	ListNode *p = head->next;
	ListNode *ret = reverse(p);
	p->next = head;
	head->next = nullptr;
	return ret;
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
