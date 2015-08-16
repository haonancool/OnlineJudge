class Solution {
public:
	int trap(vector<int> &height) {
		if (height.size() < 2)
			return 0;
		int ret = 0;
		vector<int> max_left(height.size(), 0);
		max_left[0] = 0;
		int max_h = height[0];
		for (int i = 1; i < height.size(); i++) {
			max_left[i] = max_h;
			if (max_h < height[i])
				max_h = height[i];
		}
		max_h = height.back();
		for (int i = height.size() - 2; i > 0; i--) {
			int min_h = (max_left[i] < max_h) ? max_left[i] : max_h;
			if (min_h > height[i])
			    ret += min_h - height[i];
			if (max_h < height[i])
				max_h = height[i];
		}
		return ret;
	}
};
