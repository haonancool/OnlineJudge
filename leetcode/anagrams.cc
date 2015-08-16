class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> ret;
		if (strs.empty())
			return ret;
		unordered_map<string, vector<int>> table;
		for (int i = 0; i < strs.size(); i++) {
			string s = strs[i];
			sort(s.begin(), s.end());
			table[s].push_back(i);
		}
		for (const auto &i : table) {
			if (i.second.size() > 1) {
				for (int j : i.second)
					ret.push_back(strs[j]);
			}
		}
		return ret;
	}
};
