class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        if size < 2:
            return 0
        max_num = max(nums)
        exp = 1
        aux = [0] * size
        while max_num >= exp:
            count = [0] * 10
            for num in nums:
                digit = (num / exp) % 10
                count[digit] += 1
            for i in xrange(1, 10):
                count[i] += count[i-1]
            for num in reversed(nums):
                digit = (num / exp) % 10
                count[digit] -= 1
                aux[count[digit]] = num
            nums, aux = aux, nums
            exp *= 10
        ret = 0
        for i in xrange(1, size):
            ret = max(ret, nums[i] - nums[i-1])
        return ret
