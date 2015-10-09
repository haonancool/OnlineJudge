class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        table = set()
        while n != 1:
            if n in table:
                return False
            else:
                table.add(n)
            sum = 0
            while n > 0:
                digit = n % 10
                n /= 10
                sum += digit*digit
            n = sum
        return True