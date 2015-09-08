class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return 0;
		UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> table;
		table[node] = ret;
		queue<UndirectedGraphNode*> q0, q1;
		q0.push(node);
		q1.push(ret);
		while (!q0.empty() && !q1.empty()) {
			UndirectedGraphNode *p0  = q0.front(), *p1 = q1.front();
			q0.pop();
			q1.pop();
			for (auto j : p0->neighbors) {
				if (table.find(j) == table.end()) {
					UndirectedGraphNode	*copy = new UndirectedGraphNode(j->label);
					table[j] = copy;
					p1->neighbors.push_back(copy);
					q0.push(j);
					q1.push(copy);
				} else {
					p1->neighbors.push_back(table[j]);
				}
			}
		}
		return ret;
	}
};
