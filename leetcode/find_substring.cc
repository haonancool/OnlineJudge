#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string> &words) {
		vector<int> ret;
		if (s.empty() || words.empty())
			return ret;
		unordered_map<string, int> map;
		for (string &w : words)
			map[w]++;
		int len = words[0].length();
		for (int i = 0; i < len; i++) {
			unordered_map<string, int> currentMap;
			int start = i;
			int count = 0;
			for (int j = i; j <= s.length() - len; j += len) {
				string sub = s.substr(j, len);
				if (map.find(sub) != map.end()) {
					currentMap[sub]++;
					count++;
					while (currentMap[sub] > map[sub]) {
						string left = s.substr(start, len);
						currentMap[left]--;
						count--;
						start += len;
					}
					if (count == words.size()) {
						ret.push_back(start);
						string left = s.substr(start, len);
						currentMap[left]--;
						count--;
						start += len;
					}

				} else {
					currentMap.clear();
					start = j + len;
					count = 0;
				}
			}
		}
		return ret;
	}
};

int main() {
	string s;
	cin >> s;
	vector<string> words;
	string tmp;
	while (cin >> tmp)
		words.push_back(tmp);
	Solution sol;
	vector<int> result = sol.findSubstring(s, words);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
