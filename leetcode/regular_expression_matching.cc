#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::vector;
using std::set;
using std::queue;

struct Edge {
	bool black;
	int next;
};

struct State {
	char c;
	vector<Edge> edges;
};

set<int> walk(vector<State> &nfa, set<int> &states) {
	set<int> ret;
	queue<int> q;
	for (set<int>::iterator it = states.begin(); it != states.end(); it++) 
		q.push(*it);
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		if (ret.find(s) == ret.end()) {
			ret.insert(s);
			if (s < nfa.size()) {
				for (int i = 0; i < nfa[s].edges.size(); i++) {
					if (!nfa[s].edges[i].black)
						q.push(nfa[s].edges[i].next);
				}
			}
		}
	}
	return ret;
}

class Solution {
public:
	bool isMatch(string s, string p) {
		// build nfa
		int size = static_cast<int>(p.length());
		vector<State> nfa(size);
		for (int i = 0; i < size; i++) {
			char c = p[i];
			// add state
			nfa[i].c = c;
			Edge edge;
			edge.next = i + 1;
			if ('*' == c) {       // red edge
				edge.black = false;
				nfa[i].edges.push_back(edge);
				edge.next = i - 1;
				nfa[i].edges.push_back(edge);
				edge.next = i;
				nfa[i - 1].edges.push_back(edge);
			} else {             // black edge
				edge.black = true;
				nfa[i].edges.push_back(edge);
			}
		}
		// match
		set<int> states;
		states.insert(0);
		states = walk(nfa, states);
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			set<int> next_states;
			for (set<int>::iterator j = states.begin(); j != states.end(); j++) {
				int state = *j;
				if (state < nfa.size() && ('.' == nfa[state].c || c == nfa[state].c))
					next_states.insert(state + 1);
			}		
			if (next_states.empty())
				return false;
			states = walk(nfa, next_states);
		}
		bool ret = false;
		if (states.find(size) != states.end())
			ret = true;
		return ret;
	}
};

int main() {
	string s, p;
	cin >> s >> p;
	Solution sol;
	bool match = sol.isMatch(s, p);
	cout << match << endl;
	return 0;
}
