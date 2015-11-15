class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        pattern2 = str.split()
        if len(pattern) != len(pattern2):
            return False
        table1 = {}
        table2 = {}
        for a, b in zip(pattern, pattern2):
            if a in table1:
                if table1[a] != b:
                    return False
            else:
                table1[a] = b
            if b in table2:
                if table2[b] != a:
                    return False
            else:
                table2[b] = a
        return True
