class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ret = []
        hash = {}
        table = {'A':0, 'C':1, 'G':2, 'T':3}
        val = 0
        for i, c in enumerate(s):
            val &= ~(0x3<<18)
            val <<= 2
            val |= table[c]
            if i < 9:
                continue
            if val in hash and not hash[val]:
                ret.append(s[i-9:i+1])
                hash[val] = True
            elif val not in hash:
                hash[val] = False
        return ret

if __name__ == '__main__':
    sol = Solution()
    print sol.findRepeatedDnaSequences("AAAAAAAAAAAAA")