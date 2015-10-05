class Solution {
public:
	string minWindow(string s, string t) {
		if (t.empty())
			return "";
		unordered_map<char, int> table;
		int num = 0;
		for (int i = 0; i < t.length(); i++)
			table[t[i]]--;
		int start = -1, end = -1, minStart = -1, minEnd = -1;
		for (int i = 0; i < s.length(); i++) {
			if (table.find(s[i]) != table.end()) {
				end = i;
				table[s[i]]++;
				if (table[s[i]] == 0)
					num++;
				if (start >= 0) {
					if (s[start] == s[i]) {
						while (1) {
							if (table.find(s[start]) == table.end()) {
								start++;
							} else if (table[s[start]] > 0) {
								table[s[start]]--;
								start++;
							} else {
								break;
							}
						}
					}
				} else {
					start = i;
				}
				if (num == table.size() && (minStart == -1 || minEnd - minStart > end - start)) {
				    minStart = start;
				    minEnd = end;
			    }
			}
		}
		if (num == table.size())
			return s.substr(minStart, minEnd - minStart + 1);
		else
		    return "";
	}
};
