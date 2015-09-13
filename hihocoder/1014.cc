#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Node {
	int count = 0;
	Node *children[36] = {};
};

void addWord(Node *root, const string &word) {
	root->count++;
	Node *p = root;
	for (char c : word) {
		int i = c - 'a';
		if (!p->children[i])
			p->children[i] = new Node;
		p = p->children[i];
		p->count++;
	}
}

int queryWord(Node *root, const string &word) {
	Node *p = root;
	for (char c : word) {
		int i = c - 'a';
		if (!p->children[i])
			return 0;
		p = p->children[i];
	}
	return p->count;
}

int main() {
	string line;
	getline(cin, line);
	istringstream ss(line);
	int n;
	ss >> n;
	Node *root = new Node;
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		addWord(root, line);	
	}
	getline(cin, line);
	ss.clear();
	ss.str(line);
	int m;
	ss >> m;
	for (int i = 0; i < m; i++) {
		getline(cin, line);
		int count = queryWord(root, line);
		cout << count << "\n";
	}
	return 0;
}
