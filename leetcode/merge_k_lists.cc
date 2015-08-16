struct HeapNode {
	int index;
	ListNode *node;
	HeapNode(int i, ListNode *n) : index(i), node(n) {}
};
bool compareHeapNode(const HeapNode &lhs, const HeapNode &rhs) {
	return lhs.node->val < rhs.node->val;
}

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*> &lists) {
		priority_queue<HeapNode, vector<HeapNode>, bool (*)(const HeapNode&, const HeapNode&)> heap(&compareHeapNode);
		int k = lists.size();
		ListNode *ret = 0, *p = 0;
		for (int i = 0; i < k; i++) {
			if (lists[i]) {
				heap.push(HeapNode(i, lists[i]));
				lists[i] = lists[i]->next;
			}
		}
		while (!heap.empty()) {
			HeapNode node = heap.top();
			heap.pop();
			if (p) {
				p->next = node.node;
				p = node.node;
			} else {
				p = node.node;
				ret = p;
			}
			int index = node.index;
			if (lists[index]) {
				heap.push(HeapNode(index, lists[index]));
				lists[index] = lists[index]->next;
			}
		}
		if (p)
			p->next = 0;
		return ret;
	}
};
