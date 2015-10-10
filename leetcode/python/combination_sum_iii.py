class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        if k == 0:
            return res
        elif n < k:
            return res


    def dfs(self, tmp, res):