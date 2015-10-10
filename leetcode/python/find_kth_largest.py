class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        i, j = 0, len(nums)-1
        while i <= j:
            p = self.partition(nums, i, j)
            if p-i+1 < k:
                k -= p-i+1
                i = p+1
            elif p-i+1 > k:
                j = p - 1
            else:
                return nums[p]

    def partition(self, nums, i, j):
        p = i
        for k in xrange(i, j):
            if nums[k] > nums[j]:
                nums[p], nums[k] = nums[k], nums[p]
                p += 1
        nums[p], nums[j] = nums[j], nums[p]
        return p

if __name__ == '__main__':
    sol = Solution()
    print sol.findKthLargest([-1, -1], 2)
