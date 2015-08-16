class Solution {
public:
	void setZeroes(vector<vector<int>> &matrix) {
		if (matrix.empty() || matrix.front().empty())
			return;
		int m = matrix.size(), n = matrix.front().size();
		bool clearFirstRow = false, clearFirstColumn = false;
		for (int j = 0; j < n; j++) {
			if (matrix[0][j] == 0) {
				clearFirstRow = true;
				break;
			}
		}
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == 0) {
				clearFirstColumn = true;
				break;
			}
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		for (int j = 1; j < n; j++) {
			if (matrix[0][j] == 0) {
				for (int i = 1; i < m; i++)
					matrix[i][j] = 0;
			}
		}
		for (int i = 1; i < m; i++) {
			if (matrix[i][0] == 0) {
				for (int j = 1; j < n; j++)
					matrix[i][j] = 0;
			}
		}
		if (clearFirstRow) {
			for (int j = 0; j < n; j++)
				matrix[0][j] = 0;
		}
		if (clearFirstColumn) {
			for (int i = 0; i < m; i++)
				matrix[i][0] = 0;
		}
	}
};
