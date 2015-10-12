class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        table = {}
        for L, R, H in buildings:
            if L in table:
                table[L] = (0, max(H, table[L]))
            else:
                table[L] = (0, H)
            if R in table:
                table[R] = (1, max(H, table[R]))
            else:
                table[R] = (1, H)
        pre = 0
        for k in sorted(table):
            if table[k][]
