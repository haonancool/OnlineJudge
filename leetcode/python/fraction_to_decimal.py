class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        ret = str(numerator/denominator)
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
                digits[carry:] = ['(']+digits[carry:]+[')']
                break
            else:
                table[carry] = i
            digit = carry / denominator
            digits.append(str(digit))
            carry %= denominator
            i += 1
        ret = ret + '.' + ''.join(digits)
