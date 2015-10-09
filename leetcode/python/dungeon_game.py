class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m, n = len(dungeon), len(dungeon[0])
        table = [0]*n
        for j in xrange(n-1, -1, -1):
            if j == n-1:
                table[j] = max(1-dungeon[m-1][j], 1)
            else:
                table[j] = max(table[j+1]-dungeon[m-1][j], 1)
        for i in xrange(m-2, -1, -1):
            tmp = [0]*n
            for j in xrange(n-1, -1, -1):
                if j == n-1:
                    tmp[j] = max(table[j]-dungeon[i][j], 1)
                else:
                    right = max(table[j]-dungeon[i][j], 1)
                    down = max(tmp[j+1]-dungeon[i][j], 1)
                    tmp[j] = min(right, down)
            table = tmp
        return table[0]