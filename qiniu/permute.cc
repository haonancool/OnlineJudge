#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void helper(vector<int> &table) {
	vector<int> s;
	while (1) {
		if (s.size() < table.size()) {
			int i = s.size();
			s.push_back(i);
		} else {
			for (int i : table)
				cout << i << " ";
			cout << endl;
			int j, k;
			do {
				j = s.back();
				s.pop_back();
				swap(table[s.size()], table[j]);
				k = j + 1;
				while (k < table.size() && table[k] == table[j])
					k++;
			} while (!s.empty() && (j == table.size() - 1 || k == table.size()));
			if (k == table.size()) {
				break;
			} else {
				swap(table[s.size()], table[k]);
				s.push_back(k);
			} 
		}
	}
}

void permute(vector<int> &table) {
	sort(table.begin(), table.end());
	helper(table);
}

int main() {
	int n;
	cin >> n;
	vector<int> table;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		table.push_back(tmp);
	}
	permute(table);
	return 0;
}
