class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        table = set()
        for num in nums:
            if num in table:
                return True
            else:
                table.add(num)
        return False
