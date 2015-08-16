class Solution {
public:
	int uniquePaths(int m, int n) {
		if (1 == m) return 1;
		if (1 == n) return 1;
		vector<int> table(m * n);
		for (int i = 0; i < m; i++)
			table[i * n] = 1;
		for (int j = 0; j < n; j++)
			table[j] = 1;
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++)
				table[i * n + j] = table[i * n + j - 1] + table[(i - 1) * n + j];
		}
		return table[(m - 1) * n + (n - 1)];
	}
};
