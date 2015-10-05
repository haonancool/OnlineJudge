class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int ret = 0;
		unordered_map<int, int> left_table, right_table;
		unordered_set<int> visited;
		for (int i = 0; i < nums.size(); i++) {
			if (visited.find(nums[i]) != visited.end())
				continue;
			visited.insert(nums[i]);
			auto left = left_table.find(nums[i] - 1),
				right = right_table.find(nums[i] + 1);
			int w = 0;
			if (left != left_table.end() && right != right_table.end()) {
				left_table[right->second] = left->second;
				right_table[left->second] = right->second;
				w = right->second - left->second + 1;
				left_table.erase(left);
				right_table.erase(right);
			} else if (left != left_table.end()) {
				left_table[nums[i]] = left->second;
				right_table[left->second] = nums[i];
				w = nums[i] - left->second + 1;
				left_table.erase(left);
			} else if (right != right_table.end()) {
				right_table[nums[i]] = right->second;
				left_table[right->second] = nums[i];
				w = right->second - nums[i] + 1;
				right_table.erase(right);
			} else {
				left_table[nums[i]] = nums[i];
				right_table[nums[i]] = nums[i];
				w = 1;
			}
			if (w > ret)
				ret = w;
		}
		return ret;
	}
};