class Solution {
public:
	vector<vector<string>> ret;
	vector<vector<int>> table;
	vector<vector<string>> partition(string s) {
		int len = s.length();
		if (0 == len) {
			return ret;
		}
		table.resize(len);
		for (int i = 0; i < len; i++)
			table[i].resize(len, 0);
		for (int k = 1; k <= len; k++) {
			for (int i = 0; i < len - k + 1; i++) {
				int j = i + k - 1;
				if (s[i] == s[j]) {
					if (1 == k || 2 == k)
						table[i][j] = 1;
					else
						table[i][j] = table[i + 1][j - 1];
				}
			}
		}
		vector<string> result;
		dfs(result, s, 0);
		return ret;
	}
	void dfs(vector<string> &result, const string &s, int start) {
		if (start == s.length()) {
			ret.push_back(result);
			return;
		}
		for (int j = s.length() - 1; j >= start; j--) {
			if (table[start][j]) {
				result.push_back(s.substr(start, j - start + 1));
				dfs(result, s, j + 1);
				result.pop_back();
			}
		}
	}
};