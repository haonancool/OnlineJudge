class Solution {
public:
	vector<int> num_table;
	vector<int> count_table;
	vector<vector<int>> ret;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	if (nums.empty()) {
    		ret.emplace_back();
    		return ret;
    	}
    	sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
        	if (num_table.empty() || num_table.back() != nums[i]) {
        		num_table.push_back(nums[i]);
        		count_table.push_back(1);
        	} else {
        		count_table.back()++;
        	}
        }
        vector<int> temp;
        helper(temp, 0);
        return ret;
    }
    void helper(vector<int> &temp, int i) {
    	if (i == num_table.size()) {
    		ret.push_back(temp);
    		return;
    	}
    	helper(temp, i + 1);
    	for (int j = 0; j < count_table[i]; j++) {
    		temp.push_back(num_table[i]);
    		helper(temp, i + 1);
    	}
    	for (int j = 0; j < count_table[i]; j++)
    		temp.pop_back();
    }
};