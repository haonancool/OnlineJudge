class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        ret = 0
        while n >= 5:
            n /= 5
            ret += n
        return ret

if __name__ == '__main__':
    sol = Solution()
    print sol.trailingZeroes(30)