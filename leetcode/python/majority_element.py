class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i, num in enumerate(nums):
            if i == 0:
                ret = num
                count = 1
            elif ret == num:
                count += 1
            else:
                count -= 1
                if count == 0:
                    ret = num
                    count = 1
        return ret