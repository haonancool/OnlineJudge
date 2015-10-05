class Solution {
public:
	vector<vector<int>> ret;
	vector<int> cur;
	vector<int> table;
	vector<vector<int>> combine(int n, int k) {
		if (n == 0 || k == 0 || n < k)
			return ret;
		table.resize(n);
		fill(table.begin(), table.end(), 0);
		helper(n, k);
		return ret;
	}
	void helper(int n, int k) {
		if (cur.size() == k) {
			ret.push_back(cur);
			return;
		}
		int i = 0;
		if (!cur.empty())
		    i = cur.back();
		for (; i < n - k + 1 + cur.size(); i++) {
			if (!table[i]) {
				table[i] = 1;
				cur.push_back(i + 1);
				helper(n, k);
				cur.pop_back();
				table[i] = 0;
			}
		}
	}
};
