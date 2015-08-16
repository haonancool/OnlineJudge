class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		if (matrix.empty() || matrix.front().empty())
			return false;
		int m = matrix.size(), n = matrix.front().size();
		int left = 0, right = m - 1, row = 0, column = 0;
		while (left <= right) {
			row = (left + right) / 2;
			if (matrix[row][n - 1] < target)
				left = row + 1;
			else if (matrix[row][0] > target)
				right = row - 1;
			else
				break;
		}
		if (left > right)
			return false;
		left = 0;
		right = n - 1;
		while (left <= right) {
			column = (left + right) / 2;
			if (matrix[row][column] < target)
				left = column + 1;
			else if (matrix[row][column] > target)
				right = column - 1;
			else
				break;
		}
		if (left > right)
			return false;
		return true;
	}
};
