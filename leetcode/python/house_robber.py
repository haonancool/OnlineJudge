class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        elif n == 2:
            return max(nums)
        else:
            a, b = nums[0], max(nums[0:2])
            for num in nums[2:]:
                c = max(a+num, b)
                a, b = b, c
            return b