class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if k >= n/2:
            ret = 0
            for i in xrange(1, n):
                ret += max(prices[i]-prices[i-1], 0)
            return ret
        local_table = [0] * (k+1)
        global_table = [0] * (k+1)
        for i in xrange(1, n):
            diff = prices[i]-prices[i-1]
            for j in xrange(k, 0, -1):
                local_table[j] = max(global_table[j-1]+max(diff, 0), local_table[j]+diff)
                global_table[j] = max(global_table[j], local_table[j])
        return global_table[-1]