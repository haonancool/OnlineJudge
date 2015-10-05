class Solution {
public:
	int numDistinct(string s, string t) {
		int len1 = s.length(), len2 = t.length();
		if (len1 == 0 || len2 == 0 || len1 < len2)
			return 0;
		vector<int> table(len1, 1), temp;
		for (int j = 0; j < len2; j++) {
			temp.clear();
			for (int i = 0; i < len1; i++) {
				if (i < j) {
					temp.push_back(0);
				} else {
					if (0 == i) {
						if (s[0] == t[0])
							temp.push_back(1);
						else
							temp.push_back(0);
					} else {
						int n = temp.back();
						if (s[i] == t[j])
							n += table[i - 1];
						temp.push_back(n);
					}
				}
			}
			table = temp;
		}
		return table.back();
	}
};