class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bulls = cows = 0
        table = {}
        for digit in secret:
            if digit in table:
                table[digit] += 1
            else:
                table[digit] = 1
        for a, b in zip(secret, guess):
            if a == b:
                bulls += 1
                table[a] -= 1
                if table[a] == 0:
                    del table[a]
        for i, digit in enumerate(guess):
            if digit != secret[i] and digit in table:
                cows += 1
                table[digit] -= 1
                if table[digit] == 0:
                    del table[digit]
        return str(bulls) + 'A' + str(cows) + 'B'

if __name__ == '__main__':
    sol = Solution()
    print sol.getHint('011', '011')
