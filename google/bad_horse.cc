#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using std::cout; using std::cin;
using std::vector; using std::queue; using std::unordered_map;
using std::string;

bool test() {
	int M;
	cin >> M;
	unordered_map<string, int> table;
	vector<vector<int>> graph;
	vector<int> vertices;
	for (int i = 0; i < M; i++) {
		string left, right;
		cin >> left >> right;
		if (table.find(left) == table.end()) {
			table[left] = graph.size();
			graph.emplace_back();
			vertices.push_back(0);
		}
		if (table.find(right) == table.end()) {
			table[right] = graph.size();
			graph.emplace_back();
			vertices.push_back(0);
		}
		int l = table[left], r = table[right];
		graph[l].push_back(r);
		graph[r].push_back(l);
	}
	bool flag = true;
	for (int i = 0; flag && i < vertices.size(); i++) {
		if (0 == vertices[i]) {
			vertices[i] = 1;
			queue<int> q;
			q.push(i);
			while (flag && !q.empty()) {
				int j = q.front();
				q.pop();
				for (int k : graph[j]) {
					if (0 == vertices[k]) {
						if (1 == vertices[j]) 
							vertices[k] = 2;
						else
							vertices[k] = 1;
						q.push(k);
					} else if (vertices[j] == vertices[k]) {
						flag = false;
						break;
					}
				}
			}
		}
	}
	return flag;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		bool result = test();
		cout << "Case #" << i << ": ";
		if (result)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
