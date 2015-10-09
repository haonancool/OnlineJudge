class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        table0 = {}
        table1 = {}
        for a, b in zip(s, t):
            if a in table0:
                if table0[a] != b:
                    return False
            else:
                table0[a] = b
            if b in table1:
                if table1[b] != a:
                    return False
            else:
                table1[b] = a
        return True