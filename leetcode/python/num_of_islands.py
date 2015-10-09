from collections import deque

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        m = len(grid)
        if m == 0: return 0
        n = len(grid[0])
        if n == 0: return 0
        table = [[0] * n for i in xrange(m)]
        ret = 0
        for i in xrange(m):
            for j in xrange(n):
                if grid[i][j] == '1' and not table[i][j]:
                    ret += 1
                    self.bfs(grid, table, i, j)
        return ret

    def bfs(self, grid, table, x, y):
        m, n = len(grid), len(grid[0])
        q = deque()
        q.append((x, y))
        table[x][y] = 1
        while len(q) > 0:
            x, y = q.popleft()
            if x > 0 and grid[x-1][y] == '1' and not table[x-1][y]:
                q.append((x-1, y))
                table[x-1][y] = 1
            if x < m-1 and grid[x+1][y] == '1' and not table[x+1][y]:
                q.append((x+1, y))
                table[x+1][y] = 1
            if y > 0 and grid[x][y-1] == '1' and not table[x][y-1]:
                q.append((x, y-1))
                table[x][y-1] = 1
            if y < n-1 and grid[x][y+1] == '1' and not table[x][y+1]:
                q.append((x, y+1))
                table[x][y+1] = 1