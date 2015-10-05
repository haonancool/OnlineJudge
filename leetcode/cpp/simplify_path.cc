class Solution {
public:
	string simplifyPath(string path) {
		vector<string> levels;
		int last = 0;
		while (last < path.length()) {
			int cur = path.find('/', last);
			if (cur == last) {
				if (levels.empty())
				    levels.push_back("/");
			} else {
				string level;
				if (cur >= 0)
					level = path.substr(last, cur - last);
				else
					level = path.substr(last, -1);
				if (level == ".") {
					if (levels.empty())
						levels.push_back(".");
				} else if (level == "..") {
					if (!levels.empty() && levels.back() != "/")
						levels.pop_back();
				} else {
					levels.push_back(level);
				}
				if (cur == -1)
				    break;
			}
			last = cur + 1;
		}
		string ret;
		for (int i = 0; i < levels.size(); i++) {
			if (i > 0 && levels[i - 1] != "/")
				ret += '/';
			ret += levels[i];
		}
		return ret;
	}
};
