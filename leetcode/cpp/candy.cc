class Solution {
public:
	int candy(vector<int> &ratings) {
		vector<int> count;
		count.push_back(1);
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1]) 
				count.push_back(count.back() + 1);
			else 
				count.push_back(1);
		}
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1] && count[i] <= count[i + 1])
				count[i] = count[i + 1] + 1;
		}
		int ret = 0;
		for (int i = 0; i < ratings.size(); i++)
			ret += count[i];
		return ret;
	}
};
