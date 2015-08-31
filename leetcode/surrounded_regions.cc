struct Coord {
	int x;
	int y;
	Coord(int xx, int yy) : x(xx), y(yy) {}
};

class Solution {
public:
	int m, n;
	vector<vector<int>> table;
	void solve(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty())
			return;
		m = board.size();
		n = board[0].size();
		table.resize(m);
		for (int i = 0; i < m; i++)
			table[i].resize(n, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'O' && !table[i][j]) {
					bfs(board, i, j);
				}
			}
		}
	}
	void bfs(vector<vector<char>>& board, int i, int j) {
		bool flag = true;
		queue<Coord> q;
		q.push(Coord(i, j));
		table[i][j] = 1;
		while (!q.empty()) {
			Coord p = q.front();
			q.pop();
			if (0 == p.x || m - 1 == p.x || 0 == p.y || n - 1 == p.y) {
				flag = false;
			}
			if (p.x > 0 && board[p.x - 1][p.y] == 'O' && !table[p.x - 1][p.y]) {
				q.push(Coord(p.x - 1, p.y));
				table[p.x - 1][p.y] = 1;
			}
			if (p.x < m - 1 && board[p.x + 1][p.y] == 'O' && !table[p.x + 1][p.y]) {
				q.push(Coord(p.x + 1, p.y));
				table[p.x + 1][p.y] = 1;
			}
			if (p.y > 0 && board[p.x][p.y - 1] == 'O' && !table[p.x][p.y - 1]) {
				q.push(Coord(p.x, p.y - 1));
				table[p.x][p.y - 1] = 1;
			}
			if (p.y < n - 1 && board[p.x][p.y + 1] == 'O' && !table[p.x][p.y + 1]) {
				q.push(Coord(p.x, p.y + 1));
				table[p.x][p.y + 1] = 1;
			}
		}
		if (flag)
			fill(board, i, j);
	}
	void fill(vector<vector<char>>& board, int i, int j) {
		queue<Coord> q;
		board[i][j] = 'X';
		q.push(Coord(i, j));
		while (!q.empty()) {
			Coord p = q.front();
			q.pop();
			if (board[p.x - 1][p.y] == 'O') {
				board[p.x - 1][p.y] = 'X';
				q.push(Coord(p.x - 1, p.y));
			}
			if (board[p.x + 1][p.y] == 'O') {
				board[p.x + 1][p.y] = 'X';
				q.push(Coord(p.x + 1, p.y));
			}
			if (board[p.x][p.y - 1] == 'O') {
				board[p.x][p.y - 1] = 'X';
				q.push(Coord(p.x, p.y - 1));
			}
			if (board[p.x][p.y + 1] == 'O') {
				board[p.x][p.y + 1] = 'X';
				q.push(Coord(p.x, p.y + 1));
			}
		}
	}
};