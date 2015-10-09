class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        for i in xrange(16):
            a = (n >> i) & 1
            b = (n >> (31-i)) & 1
            if a:
                n |= 1 << (31-i)
            else:
                n &= ~(1 << (31-i))
            if b:
                n |= 1 << i
            else:
                n &= ~(1 << i)
        return n

if __name__ == '__main__':
    sol = Solution()
    sol.reverseBits(1)