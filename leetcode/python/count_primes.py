class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0
        table = [1]*n
        table[0] = table[1] = 0
        for i in xrange(2, n):
            if table[i]:
                j = 2 * i
                while j < n:
                    table[j] = 0
                    j += i
        return sum(table)