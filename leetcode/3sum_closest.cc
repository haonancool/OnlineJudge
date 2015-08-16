#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <limits.h> 

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::sort;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int closest = target;
		int min_dist = INT_MAX;
		if (nums.size() < 3)
			return closest;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			int j = i + 1, k = nums.size() - 1;
			int last_dist = INT_MAX;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				int diff = sum - target;
				int dist = (diff > 0) ? diff : -diff;
				if (dist < min_dist) {
					min_dist = dist;
					closest = sum;
				}
				if (0 == min_dist)
					return closest;
				if (dist >= last_dist)
					break;
				if (diff < 0)
					j++;
				else
					k--;
			}
		}
		return closest;
	}
};

int main() {
	Solution sol;
	int target;
	cin >> target;
	vector<int> nums;
	int n = 0;
	while (cin >> n)
		nums.push_back(n);
	int result = sol.threeSumClosest(nums, target);
	cout << result << endl;
	return 0;
}
