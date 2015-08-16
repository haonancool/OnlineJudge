class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		vector<vector<int>> ret;
		if (candidates.empty() || target <= 0)
			return ret;
		sort(candidates.begin(), candidates.end());
		vector<int> counts;
		for (int i = 0, j = -1; i < candidates.size(); i++) {
			if (j >= 0 && candidates[i] == candidates[j]) {
				counts[j]++;
			} else {
				j++;
				candidates[j] = candidates[i];
				counts.push_back(1);
			}
		}
		candidates.resize(counts.size());
		vector<int> result;
		helper(ret, candidates, counts, result, 0, target);
		return ret;
	}
	void helper(vector<vector<int>> &results, vector<int> &candidates, vector<int> &counts, vector<int> &result, int start, int target) {
		if (target == 0) {
			results.push_back(result);
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			if (target >= candidates[i]) {
				if (counts[i] > 0) {
					counts[i]--;				
					result.push_back(candidates[i]);
					helper(results, candidates, counts, result, i, target - candidates[i]);
					result.pop_back();
					counts[i]++;
				}
			} else {
				break;
			}
		} 
	}
};
