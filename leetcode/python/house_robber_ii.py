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
            a, b = nums[0], max(nums[0], nums[1])
            for num in nums[2:n-1]:
                tmp = max(a+num, b)
                a, b = b, tmp
            c = b
            a, b = nums[1], max(nums[1], nums[2])
            for num in nums[3:]:
                tmp = max(a+num, b)
                a, b = b, tmp
            return max(b, c)