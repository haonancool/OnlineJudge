# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n
        while left <= right:
            mid = (left + right) / 2
            if not isBadVersion(mid):
                left = mid + 1
            elif mid > 1 and isBadVersion(mid - 1):
                right = mid - 1
            else:
                return mid
