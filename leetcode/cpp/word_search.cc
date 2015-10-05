class Solution {
public:
	vector<vector<int>> table;
	bool exist(vector<vector<char>> &board, string word) {
		if (word.empty())
			return true;
		int m = board.size(), n = board.front().size();
		table.resize(m);
		for (int i = 0; i < m; i++) {
			table[i].resize(n);
			for (int j = 0; j < n; j++)
				table[i][j] = 0;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == word[0]) {
					bool flag = dfs(i, j, 0, board, word);
					if (flag)
						return true;
				}
			}
		}
		return false;
	}
	bool dfs(int i, int j, int k, vector<vector<char>> &board, string &word) {
		if (k == word.size() - 1)
			return true;
		table[i][j] = 1;
		bool flag = false;
		int m = board.size(), n = board.front().size();
		if (!flag && i > 0 && !table[i - 1][j] && board[i - 1][j] == word[k + 1])
			flag = dfs(i - 1, j, k + 1, board, word);
		if (!flag && i < m - 1 && !table[i + 1][j] && board[i + 1][j] == word[k + 1])
			flag = dfs(i + 1, j, k + 1, board, word);
		if (!flag && j > 0 && !table[i][j - 1] && board[i][j - 1] == word[k + 1])
			flag = dfs(i, j - 1, k + 1, board, word);
		if (!flag && j < n - 1 && !table[i][j + 1] && board[i][j + 1] == word[k + 1])
			flag = dfs(i, j + 1, k + 1, board, word);
		table[i][j] = 0;
		return flag;
	}
};
