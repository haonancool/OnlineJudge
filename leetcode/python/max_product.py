class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i, num in enumerate(nums):
            if i == 0:
                ret = min_local = max_local = num
            else:
                temp = max_local
                max_local = max(num, max_local*num, min_local*num)
                min_local = min(num, temp*num, min_local*num);
                ret = max(ret, max_local)
        return ret
