class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        table = {}
        for i, num in enumerate(nums):
            if num in table:
                if i - table[num] <= k:
                    return True
            table[num] = i
        return False
