class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        vers1, vers2 = version1.split('.'), version2.split('.')
        m, n = len(vers1), len(vers2)
        for i in xrange(max(m, n)):
            if i < m and i < n:
                a, b = int(vers1[i]), int(vers2[i])
                if a < b:
                    return -1
                elif a > b:
                    return 1
            elif i < m and int(vers1[i]) > 0:
                return 1
            elif i < n and int(vers2[i]) > 0:
                return -1
        return 0
