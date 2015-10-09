class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        arr = []
        while n > 0:
            n -= 1
            rem = n % 26
            arr.append(chr(ord('A')+rem))
            n /= 26
        return ''.join(reversed(arr))

if __name__ == '__main__':
    sol = Solution()
    print sol.convertToTitle(703)