class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        table = {}
        ret = 0
        for i, c in enumerate(s):
            if i == 0:
                start = 0
            elif c in table and table[c] >= start:
                start = table[c]+1
            table[c] = i
            ret = max(ret, i-start+1)
        return ret
