class Solution {
public:
	bool isValidSudoku(vector<vector<char>> &board) {
		int temp[9];
		for (int i = 0; i < 9; i++) {
			fill(temp, temp + 9, 0);
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int n = board[i][j] - '1';
					if (temp[n])
						return false;
					else
						temp[n] = 1;
				}
			}
		}	
		for (int i = 0; i < 9; i++) {
			fill(temp, temp + 9, 0);
			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.') {
					int n = board[j][i] - '1';
					if (temp[n])
						return false;
					else
						temp[n] = 1;
				}
			}
		}	
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				fill(temp, temp + 9, 0);
				for (int x = 3 * i; x < 3 * i + 3; x++) {
					for (int y = 3 * j; y < 3 * j + 3; y++) {
						if (board[x][y] != '.') {
							int n = board[x][y] - '1';
							if (temp[n])
								return false;
							else
								temp[n] = 1;
						}
					}
				}
			}
		}
		return true;
	}
};
