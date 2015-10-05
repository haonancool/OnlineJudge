class Solution {
public:
	int minPathSum(vector<vector<int>> &grid) {
		int m = grid.size(), n = grid.front().size();
		vector<int> table(m * n);
		table[0] = grid[0][0];
		for (int i = 1; i < m; i++) {
			table[i * n] = table[(i - 1) * n] + grid[i][0];
		}
		for (int j = 1; j < n; j++) {
			table[j] = table[j - 1] + grid[0][j];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++)
				if (table[i * n + j - 1] < table[(i - 1) * n + j])
					table[i * n + j] = table[i * n + j - 1] + grid[i][j];
				else
					table[i * n + j] = table[(i - 1) * n + j] + grid[i][j];
		}
		return table[(m - 1) * n + (n - 1)];
	}
};
