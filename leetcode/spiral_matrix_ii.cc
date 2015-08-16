class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix;
		matrix.resize(n);
		for (int i = 0; i < matrix.size(); i++)
		    matrix[i].resize(n);
		int i = 0, j = 0, k = 0;
		while (i < (n + 1) / 2 && j < (n + 1) / 2) {
			for (int x = j; x < n - j; x++)
				matrix[i][x] = ++k;
			for (int y = i + 1; y < n - i; y++)
				matrix[y][n - 1 - j] = ++k;
			if (i < n / 2 && j < n / 2) {
				for (int x = n - 2 - j; x >= j; x--)
					matrix[n - 1 - i][x] = ++k;
				for (int y = n - 2 - i; y > i; y--)
					matrix[y][j] = ++k;
			}
			i++;
			j++;
		}
		return matrix;
	}
};
