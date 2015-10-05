#include <iostream>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::vector;

class Solution {
public:
	int maxArea(vector<int> &height) {
		int ret = 0;
		int i = 0, j = height.size() - 1;
		while (i < j) {
			int h = (height[i] < height[j]) ? height[i] : height[j];
			int area = h * (j - i);
			ret = (area > ret) ? area : ret;
			if (height[i] < height[j])
				i++;
			else
				j--;
		}
		return ret;
	}
};

int main() {
	Solution sol;
	vector<int> height;
	int a = 0;
	while (cin >> a)
		height.push_back(a);
	int area = sol.maxArea(height);
	cout << area << endl;
	return 0;
}
