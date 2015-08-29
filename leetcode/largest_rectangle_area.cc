#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		vector<int> s;
		int ret = 0, i = 0;
		while (i < height.size()) {
			if (s.empty() || height[s.back()] <= height[i]) {
				s.push_back(i);
				i++;
			} else {
				int j = s.back();
				s.pop_back();
				int w = i;
				if (!s.empty())
					w = i - s.back() - 1;
				int tmp = height[j] * w;
				if (tmp > ret)
					ret = tmp;
			}
		}
		while (!s.empty()) {
			int j = s.back();
			s.pop_back();
			int w = i;
			if (!s.empty())
				w = i - s.back() - 1;
			int tmp = height[j] * w;
			if (tmp > ret)
				ret = tmp;
		}
		return ret;
	}
};

int main() {
	int n;
	vector<int> height;
	while (cin >> n)
		height.push_back(n);
	Solution sol;
	int area = sol.largestRectangleArea(height);
	cout << area << endl;
	return 0;
}
