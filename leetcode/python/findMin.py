class Solution(object):
    def findMin(self, nums):
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        low, high = 0, n-1
        while low <= high:
            mid = (low+high)/2
            if nums[mid-1] > nums[mid]:
                return nums[mid]
            elif nums[mid] > nums[high]:
                low = mid+1
            else:
                high = mid-1

