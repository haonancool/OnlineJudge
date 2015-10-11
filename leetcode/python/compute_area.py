class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        ret = (C-A)*(D-B) + (G-E)*(H-F)
        x = min(C, G) - max(A, E)
        if x < 0:
            x = 0
        y = min(D, H) - max(B, F)
        if y < 0:
            y = 0
        ret -= x * y
        return ret

if __name__ == '__main__':
    sol = Solution()
    print sol.computeArea(-2, -2, 2, 2, -2, -2, 2, 2)
