class Solution {
public:
	int lengthOfLastWord(string s) {
		bool flag = false;
		int ret = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				flag = false;
			} else {
				if (flag)
					ret++;
				else
					ret = 1;
				flag = true;
			}
		}
		return ret;
	}
};
