class Solution {
public:
	void reverseWords(string &s) {
		removeSpaces(s);
		reverse(s, 0, s.length() - 1);
		bool flag = false, start = -1, end = -1;
		int i = 0, j = s.length() - 1;
		while (i < s.length()) {
			while (s[i] == ' ')
				i++;
			int j = i;
			while (j + 1 < s.length() && s[j + 1] != ' ')
			    j++;
			reverse(s, i, j);
			i = j + 1;
		}
	}
	void removeSpaces(string &s) {
		int i = -1, j = 0;
		while (s[j] == ' ')
			j++;
		bool flag = false;
		while (j < s.length()) {
			if (s[j] == ' ') {
				if (flag)
					s[++i] = ' ';
				flag = false;
			} else {
				s[++i] = s[j];
				flag = true;
			}
			j++;
		}
		if (i >= 0 && s[i] == ' ')
			i--;
		s.resize(i + 1);
	}
	void reverse(string &s, int start, int end) {
		int i = start, j = end;
		while (i < j) {
			char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
			i++;
			j--;
		}
	}
};
