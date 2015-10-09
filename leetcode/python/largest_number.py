class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        ret = ''.join(sorted([str(num) for num in nums], cmp=lambda x,y: cmp(x+y,y+x), reverse=True))
        if ret.startswith('0'):
            return '0'
        else:
            return ret