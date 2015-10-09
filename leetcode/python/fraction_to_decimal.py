class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator * denominator < 0:
            sign = '-'
        else:
            sign = ''
        numerator, denominator = abs(numerator), abs(denominator)
        ret = sign+str(numerator/denominator)
        carry = numerator%denominator
        if carry == 0:
            return ret
        table = {}
        digits = []
        i = 0
        while carry > 0:
            carry *= 10
            if carry in table:
                i = table[carry]
                digits[i:] = ['(']+digits[i:]+[')']
                break
            else:
                table[carry] = i
            digit = carry / denominator
            digits.append(str(digit))
            carry %= denominator
            i += 1
        ret = ret + '.' + ''.join(digits)
        return ret

if __name__ == '__main__':
    sol = Solution()
    print sol.fractionToDecimal(-50, 8)