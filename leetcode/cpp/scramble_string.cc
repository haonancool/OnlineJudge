class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length())
			return false;
		int len = s1.length();
		if (len == 0)
			return true;
		else if (len == 1)
			return s1[0] == s2[0];
		string s11 = s1, s22 = s2;
		sort(s11.begin(), s11.end());
		sort(s22.begin(), s22.end());
		if (s11 != s22)
			return false;
		for (int i = 1; i < len; i++) {
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
				isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len - i)) &&
				isScramble(s1.substr(i), s2.substr(0, len - i)))
				return true;
		}
		return false;
	}
};