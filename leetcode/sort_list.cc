#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode *head) {
		int len = 0;
		for (ListNode *p = head; p; p = p->next)
			len++;
		return mergeSort(head, len);
	}
	ListNode *mergeSort(ListNode *head, int len) {
		if (len <= 1) return head;
		int leftLen = len / 2, rightLen = len - leftLen;
		ListNode *left = head, *right = head, *p = 0;
		for (int i = 0; i < leftLen; i++) {
			p = right;
			right = right->next;
		}
		p->next = 0;
		left = mergeSort(left, leftLen);
		right = mergeSort(right, rightLen);
		head = merge(left, right);
		return head;
	}
	ListNode *merge(ListNode *left, ListNode *right) {
		ListNode *p = left, *q = right, *head = 0, *tail = 0;
		while (p && q) {
			ListNode *r = 0;
			if (p->val < q->val) {
				r = p;
				p = p->next;
			} else {
				r = q;
				q = q->next;
			}
			r->next = 0;
			if (!head) {
				head = tail = r;
			} else {
				tail->next = r;
				tail = r;
			}
		}
		while (p) {
			ListNode *r = p;
			p = p->next;
			r->next = 0;
			tail->next = r;
			tail = r;
		}
		while (q) {
			ListNode *r = q;
			q = q->next;
			r->next = 0;
			tail->next = r;
			tail = r;
		}
		return head;
	}
};

int main() {
	int n;
	ListNode *head = 0, *tail = 0;
	while (cin >> n) {
		ListNode *p = new ListNode(n);
		if (!head) {
			head = tail = p;
		} else {
			tail->next = p;
			tail = p;
		}
	}
	Solution sol;
	head = sol.sortList(head);
	for (ListNode *p = head; p; p = p->next)
		cout << p->val << " ";
	cout << endl;
	return 0;
}
