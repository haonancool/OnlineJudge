class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        m = len(board)
        if m > 0:
            n = len(board[0])
        if m == 0 or n == 0:
            return
        dxs = [1, 1, 0, -1, -1, -1, 0, 1]
        dys = [0, 1, 1, 1, 0, -1, -1, -1]
        for i in xrange(m):
            for j in xrange(n):
                cnt = 0
                for dx, dy in zip(dxs, dys):
                    x, y = i + dx, j + dy
                    if x < 0 or x >= m or y < 0 or y >= n:
                        continue
                    if board[x][y] == 1 or board[x][y] == 2:
                        cnt += 1
                if board[i][j] == 1 and (cnt < 2 or cnt > 3):
                    board[i][j] = 2
                elif board[i][j] == 0 and cnt == 3:
                    board[i][j] = 3
        for i in xrange(m):
            for j in xrange(n):
                board[i][j] %= 2
