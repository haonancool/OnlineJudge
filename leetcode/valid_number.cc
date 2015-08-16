class Solution {
public:
	bool isNumber(string s) {
		int state = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				if (state == 0)
					state = 0;
				else if (state == 2 || state == 4 || state == 5 || state == 8 || state == 9)
					state = 9;
				else
					return false;
			} else if (s[i] >= '0' && s[i] <= '9') {
				if (state == 0 || state == 1 || state == 2)
					state = 2;
				else if (state == 3 || state == 4)
					state = 4;
				else if (state == 5)
					state = 5;
				else if (state == 6 || state == 7 || state == 8)
				    state = 8;
				else
					return false;
			} else if (s[i] == '.') {
				if (state == 0 || state == 1)
					state = 3;
				else if (state == 2)
				    state = 5;
				else
					return false;
			} else if (s[i] == 'e' || s[i] == 'E') {
				if (state == 2 || state == 4 || state == 5)
					state = 6;
				else
					return false;
			} else if (s[i] == '+' || s[i] == '-') {
				if (state == 0)
					state = 1;
				else if (state == 6)
				    state = 7;
				else
					return false;
			} else {
				return false;
			}
		}
		return state == 2 || state == 4 || state == 5 || 
			state == 8 || state == 9;
	}
};
