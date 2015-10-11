class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        if k == 0 or n < k or n > 9*k:
            return res
        tmp = []
        self.dfs(1, k, n, tmp, res)
        return res

    def dfs(self, num, k, n, tmp, res):
        if k == 0 and n == 0:
            res.append(tmp[:])
            return
        if n > 9*(k-1):
            low = n - 9*(k-1)
        else:
            low = 1
        low = max(low, num)
        high = min(n / k, 9)
        for i in xrange(low, high+1):
            tmp.append(i)
            self.dfs(i+1, k-1, n-i, tmp, res)
            tmp.pop()

if __name__ == '__main__':
    sol = Solution()
    print sol.combinationSum3(2, 6)
