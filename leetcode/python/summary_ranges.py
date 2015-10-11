class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        ret = []
        if len(nums) == 0:
            return ret
        left = right = nums[0]
        for num in nums[1:]:
            if num > right + 1:
                if left == right:
                    ret.append(str(left))
                else:
                    ret.append(str(left)+'->'+str(right))
                left = right = num
            else:
                right += 1
        if left == right:
            ret.append(str(left))
        else:
            ret.append(str(left)+'->'+str(right))
        return ret
