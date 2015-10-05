class Solution {
public:
	string countAndSay(int n) {
		string ret = "1";
		for (int i = 1; i < n; i++) {
			string tmp;
			char last = '\0';
			int count = 0;
			for (int j = 0; j < ret.length(); j++) {
				if (j > 0 && ret[j] != last) {
					tmp += to_string(count);
					tmp += last;
					count = 0;
				}
				last = ret[j];
				count++;
			}
			tmp += to_string(count);
			tmp += last;
			ret = tmp;
		}
		return ret;
	}
};
