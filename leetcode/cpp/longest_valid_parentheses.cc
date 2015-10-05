class Solution {
public:
	int longestValidParentheses(string s) {
		int ret = 0, cur = 0;
		int count = 0, start = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				count++;
			} else {
				if (count > 0) {
					count--;
					cur += 2;
				} else {
					if (ret < cur)
						ret = cur;
					cur = 0;
					start = i + 1;
				}
			}
		}
		if (count > 0) {
			count = 0;
			cur = 0;
			for (int i = s.length() - 1; i >= start; i--) {
				if (s[i] == ')') {
					count++;
				} else {
					if (count > 0) {
						count--;
						cur += 2;
					} else {
						if (ret < cur)
							ret = cur;
						cur = 0;
					}
				}
			}	
			if (ret < cur)
				ret = cur;
		} else if (count == 0) {
			if (ret < cur)
				ret = cur;
		}
		return ret;
	}
};
