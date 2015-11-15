class NumMatrix(object):
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        m = len(matrix)
        if m == 0:
            self.table = [0]
            return
        n = len(matrix[0])
        self.table = [[0]*(n+1)]
        for i in xrange(1, m+1):
            row = [0]
            tmp = 0
            for j in xrange(1, n+1):
                tmp += matrix[i-1][j-1]
                row.append(self.table[i-1][j]+tmp)
            self.table.append(row)

    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        a = self.table[row1][col1]
        b = self.table[row1][col2+1]
        c = self.table[row2+1][col1]
        d = self.table[row2+1][col2+1]
        return a + d - b - c

# Your NumMatrix object will be instantiated and called as such:
# numMatrix = NumMatrix(matrix)
# numMatrix.sumRegion(0, 1, 2, 3)
# numMatrix.sumRegion(1, 2, 3, 4)
