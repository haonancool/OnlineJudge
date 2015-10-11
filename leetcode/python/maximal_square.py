class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        table = []
        ret = 0
        for i, row in enumerate(matrix):
            tmp = []
            for j, v in enumerate(row):
                if v == '0':
                    edge = 0
                elif i == 0 or j == 0:
                    edge = 1
                else:
                    edge = min(tmp[j-1], table[j], table[j-1])+1
                ret = max(ret, edge)
                tmp.append(edge)
            table = tmp
        return ret * ret
