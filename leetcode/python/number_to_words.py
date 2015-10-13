class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return 'Zero'
        a = []
        while num:
            a.append(num % 1000)
            num /= 1000
        b = ['', 'Thousand', 'Million', 'Billion']
        c = []
        table = [
            ['One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine'],
            ['Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen'],
            ['Ten', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
        ]
        for i, j in zip(a, b):
            if i > 0:
                c.append(self.help(i, j, table))
        c.reverse()
        return ' '.join(c)

    def help(self, n, postfix, table):
        if n == 0:
            return ''

        ret = []
        if 10 < n % 100 <= 19:
            ret.append(table[1][n%100-11])
            n /= 100
        else:
            if n % 10 > 0:
                ret.append(table[0][n%10-1])
            n /= 10
            if n % 10 > 0:
                ret.append(table[2][n%10-1])
            n /= 10
        if n > 0:
            ret.append(table[0][n-1]+' Hundred')
        ret.reverse()
        if postfix != '':
            ret.append(postfix)
        return ' '.join(ret)
