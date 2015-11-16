class Solution {
public:
    bool rows[9][9];
    bool cols[9][9];
    bool sqrs[9][9];
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                rows[i][j] = cols[i][j] = sqrs[i][j] = true;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '0';
                    int sq_id = (i / 3) * 3 + j / 3;
                    rows[i][k-1] = cols[j][k-1] = sqrs[sq_id][k-1] = false;
                }
            }
        }
        dfs(board, 0, 0);
    }
    bool dfs(vector<vector<char>>& board, int i, int j) {
        if (i == 9)
            return true;
        int sq_id = (i / 3) * 3 + j / 3;
        int ni = i, nj = j + 1;
        if (nj == 9) {
            ni++;
            nj = 0;
        }
        bool flag = false;
        if (board[i][j] == '.') {
            for (int k = 1; k <= 9; k++) {
                if (rows[i][k-1] && cols[j][k-1] && sqrs[sq_id][k-1]) {
                    rows[i][k-1] = cols[j][k-1] = sqrs[sq_id][k-1] = false;
                    board[i][j] = k + '0';
                    if (dfs(board, ni, nj))
                        return true;
                    board[i][j] = '.';
                    rows[i][k-1] = cols[j][k-1] = sqrs[sq_id][k-1] = true;
                }
            }
        } else {
            if (dfs(board, ni, nj))
                return true;
        }
        return false;
    }
};