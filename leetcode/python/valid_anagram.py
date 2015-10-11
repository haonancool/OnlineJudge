class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        a = list(sorted(s))
        b = list(sorted(t))
        return a == b
