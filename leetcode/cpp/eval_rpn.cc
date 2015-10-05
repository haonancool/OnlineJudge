class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		if (tokens.empty()) return 0;
		vector<int> s;
		for (const auto &str : tokens) {
			if (1 == str.length()) {
				int lhs, rhs;
				switch (str[0]) {
					case '+':
						rhs = s.back();
						s.pop_back();
						lhs = s.back();
						s.pop_back();
						s.push_back(lhs + rhs);
						break;
					case '-':
						rhs = s.back();
						s.pop_back();
						lhs = s.back();
						s.pop_back();
						s.push_back(lhs - rhs);
						break;
					case '*':
						rhs = s.back();
						s.pop_back();
						lhs = s.back();
						s.pop_back();
						s.push_back(lhs * rhs);
						break;
					case '/':
						rhs = s.back();
						s.pop_back();
						lhs = s.back();
						s.pop_back();
						s.push_back(lhs / rhs);
						break;
					default:
						s.push_back(str[0] - '0');
						break;
				} 
			} else {
				s.push_back(stoi(str));
			}
		}
		return s.back();
	}
};
