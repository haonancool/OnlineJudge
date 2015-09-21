#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<int> table;
vector<int> common;

void helper(int k) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (k > 0) {
			if (table.find(num) != table.end())
				common.push_back(num);
		} else {
			table.insert(num);
		}
	}
	if (k == 1) {
		table.clear();
		for (int i = 0; i < common.size(); i++)
			table.insert(common[i]);
		common.clear();
	} else if (k == 2) {
		sort(common.begin(), common.end());
	}
}

int main() {
	helper(0);
	helper(1);
	helper(2);
	for (int i = 0; i < common.size(); i++) {
		if (i > 0)
			cout << " ";
		cout << common[i];
	}
	return 0;
}
