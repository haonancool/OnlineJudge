class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        ret = 0
        factor = 1
        tmp = n
        while tmp > 0:
            ret += tmp / 10 * factor
            if tmp % 10 == 1:
                ret += n % factor + 1
            elif tmp % 10 > 1:
                ret += factor
            tmp /= 10
            factor *= 10
        return ret

if __name__ == '__main__':
    sol = Solution()
    print sol.countDigitOne(10)
