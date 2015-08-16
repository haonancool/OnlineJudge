class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid.front().size();
		vector<int> table(m * n);
		if (obstacleGrid[0][0])
		    table[0] = 0;
		else
		    table[0] = 1;
		for (int i = 1; i < m; i++) {
			if (obstacleGrid[i][0])
				table[i * n] = 0;
			else
				table[i * n] = table[(i - 1) * n];
		}
		for (int j = 1; j < n; j++) {
			if (obstacleGrid[0][j])
				table[j] = 0;
			else
				table[j] = table[j - 1];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++)
				if (obstacleGrid[i][j])
					table[i * n + j] = 0;
				else
					table[i * n + j] = table[i * n + j - 1] + table[(i - 1) * n + j];
		}
		return table[(m - 1) * n + (n - 1)];
	}
};
