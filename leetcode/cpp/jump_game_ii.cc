#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int> &nums) {
		if (nums.empty())
			return 0;
		int lastReach = 0, reach = 0, step = 0;
		for (int i = 0; i <= reach && i < nums.size(); i++) {
			if (i > lastReach) {
				step++;
				lastReach = reach;
			}
			if (reach < nums[i] + i)
				reach = nums[i] + i;
		}
		if (reach < nums.size() - 1)
			return 0;
		return step;
	}
};

int main() {
	int n;
	vector<int> nums;
	while (cin >> n)
		nums.push_back(n);
	Solution sol;
	int step = sol.jump(nums);
	cout << step << endl;
	return 0;
}
