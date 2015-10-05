class Solution {
public:
	vector<vector<int>> table;
	vector<string> ret;
	vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
		table.resize(s.length());
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j <= i; j++) {
				if (wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()
					&& (0 == j || !table[j - 1].empty())) {
					table[i].push_back(j - 1);
				}
			}
		}
		vector<int> tmp;
		helper(s, tmp, s.length() - 1);
		return ret;
	}
	void helper(const string &s, vector<int> &tmp, int i) {
		if (i < 0) {
			string str;
			for (int j = tmp.size() - 1; j >= 0; j--) {
				if (j > 0) {
					str += s.substr(tmp[j] + 1, tmp[j - 1] - tmp[j]);
					str += ' ';
				} else {
					str += s.substr(tmp[j] + 1, -1);
				}
			}	
			ret.push_back(str);
			return;
		}
		for (int j = 0; j < table[i].size(); j++) {
			tmp.push_back(table[i][j]);
			helper(s, tmp, table[i][j]);
			tmp.pop_back();
		}
	}
};
