class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        tmp = 1
        for num in nums:
            ret.append(tmp)
            tmp *= num
        tmp = 1
        for i in xrange(len(nums)-1, -1, -1):
            ret[i] *= tmp
            tmp *= nums[i]
        return ret
