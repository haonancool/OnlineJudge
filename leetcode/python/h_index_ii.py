class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        count = len(citations)
        left, right = 0, count - 1
        while left <= right:
            mid = (left + right) / 2
            if count - mid <= citations[mid]:
                right = mid - 1
            elif mid < count - 1 and count - mid -1 > citations[mid+1]:
                left = mid + 1
            else:
                return count - mid - 1
        return count

if __name__ == '__main__':
    sol = Solution()
    print sol.hIndex([0])
