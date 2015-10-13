class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        q = [1]
        i2 = i3 = i5 = 0
        for i in xrange(n-1):
            m2, m3, m5 = q[i2]*2, q[i3]*3, q[i5]*5
            m = min(m2, m3, m5)
            if m == m2:
                i2 += 1
            if m == m3:
                i3 += 1
            if m == m5:
                i5 += 1
            q.append(m)
        return q[-1]

if __name__ == '__main__':
    sol = Solution()
    print sol.nthUglyNumber(7)
