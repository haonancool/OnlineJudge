class Solution {
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> ret;
		if (candidates.empty() || target <= 0)
			return ret;
		sort(candidates.begin(), candidates.end());
		vector<int> result;
		helper(ret, candidates, result, 0, target);
		return ret;
	}
	void helper(vector<vector<int>> &results, vector<int> &candidates, vector<int> &result, int start, int target) {
		if (target == 0) {
			results.push_back(result);
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			if (target >= candidates[i]) {
				result.push_back(candidates[i]);
				helper(results, candidates, result, i, target - candidates[i]);
				result.pop_back();
			} else {
				break;
			}
		} 
	}
};
