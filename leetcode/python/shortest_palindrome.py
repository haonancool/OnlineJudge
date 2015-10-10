class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return ''
        p = s[::-1]
        i = Solution.kmp_matcher(p, s)
        return s[len(s)-1:i-1:-1] + s

    @staticmethod
    def kmp_matcher(s, p):
        i = 0
        table = Solution.compute_prefix_function(p)
        for c in s:
            while i > 0 and p[i] != c:
                i = table[i-1]
            if p[i] == c:
                i += 1
        return i

    @staticmethod
    def compute_prefix_function(s):
        table = [0]
        k = 0
        n = len(s)
        for i in xrange(1, n):
            while k > 0 and s[k] != s[i]:
                k = table[k-1]
            if s[k] == s[i]:
                k += 1
            table.append(k)
        return table


if __name__ == '__main__':
    sol = Solution()
    print sol.shortestPalindrome('a')