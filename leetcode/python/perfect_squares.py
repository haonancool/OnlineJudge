import math

class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        visited1 = {n: 0}
        q1 = [n]
        visited2 = {0: 0}
        q2 = [0]
        while q1 or q2:
            new_q1 = []
            for v in q1:
                if v in visited2:
                    return visited1[v] + visited2[v]
                depth = visited1[v]
                for i in xrange(1, int(math.sqrt(v)) + 1):
                    u = v - i * i
                    if u not in visited1:
                        visited1[u] = depth + 1
                        new_q1.append(u)
            q1 = new_q1
            new_q2 = []
            for v in q2:
                if v in visited1:
                    return visited1[v] + visited2[v]
                depth = visited2[v]
                for i in xrange(1, int(math.sqrt(n - v)) + 1):
                    u = v + i * i
                    if u not in visited2:
                        visited2[u] = depth + 1
                        new_q2.append(u)
            q2 = new_q2

if __name__ == '__main__':
    sol = Solution()
    print sol.numSquares(2)
