class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        	return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int area = 0;
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		if (matrix[i][j] == '0')
        			height[j] = 0;
        		else
        			height[j]++;
        	}
        	int temp = largestRectangleArea(height);
        	area = (temp > area) ? temp : area;
        }
        return area;
    }
    int largestRectangleArea(vector<int> &height) {
		vector<int> s;
		int ret = 0, i = 0;
		while (i < height.size()) {
			if (s.empty() || height[s.back()] <= height[i]) {
				s.push_back(i);
				i++;
			} else {
				int j = s.back();
				s.pop_back();
				int w = i;
				if (!s.empty())
					w = i - s.back() - 1;
				int tmp = height[j] * w;
				if (tmp > ret)
					ret = tmp;
			}
		}
		while (!s.empty()) {
			int j = s.back();
			s.pop_back();
			int w = i;
			if (!s.empty())
				w = i - s.back() - 1;
			int tmp = height[j] * w;
			if (tmp > ret)
				ret = tmp;
		}
		return ret;
	}
};