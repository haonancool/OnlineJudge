#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int index;
	int weight;
	Edge(int i, int w) : index(i), weight(w) {}
};

int main() {
	int N, M, S, T;
	cin >> N >> M >> S >> T;
	vector<vector<Edge>> graph(N);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u - 1].emplace_back(v - 1, w);
		graph[v - 1].emplace_back(u - 1, w);
	}
	vector<int> dists(N, -1);
	vector<int> flags(N, 0);
	dists[S - 1] = 0;
	queue<int> q;
	q.push(S - 1);
	flags[S - 1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		flags[u] = 0;
		for (Edge edge : graph[u]) {
			int v = edge.index, w = edge.weight;
			if (dists[v] < 0 || dists[v] > dists[u] + w) {
				dists[v] = dists[u] + w;
				if (!flags[v]) {
					q.push(v);
					flags[v] = 1;
				}
			}
		}	
	}
	cout << dists[T - 1];
	return 0;
}
