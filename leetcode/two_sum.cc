class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int size = numbers.size();
    unordered_map<int, int> hash;
    vector<int> ret;
    for (int i = 0; i < size; i++) {
      int diff = target - numbers[i];
      if (hash.find(diff) != hash.end()) {
	ret.push_back(hash[diff]);
	ret.push_back(i+1);
        return ret;
      }
      hash[numbers[i]] = i+1;
    }
    return ret;
  }
};
