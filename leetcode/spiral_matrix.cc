class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if (matrix.empty() || matrix.front().empty())
			return ret;
		int m = matrix.size(), n = matrix.front().size();
		int i = 0, j = 0;
		while (i < (m + 1) / 2 && j < (n + 1) / 2) {
			for (int x = j; x < n - j; x++)
				ret.push_back(matrix[i][x]);
			for (int y = i + 1; y < m - i; y++)
				ret.push_back(matrix[y][n - 1 - j]);
			if (i < n / 2 && j < m / 2) {
				for (int x = n - 2 - j; x >= j; x--)
					ret.push_back(matrix[m - 1 - i][x]);
				for (int y = m - 2 - i; y > i; y--)
					ret.push_back(matrix[y][j]);
			}
			i++;
			j++;
		}
		return ret;
	}
};
