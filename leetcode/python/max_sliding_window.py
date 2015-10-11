from collections import deque

class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        ret = []
        q = deque()
        for i, num in enumerate(nums):
            while q and nums[q[-1]] <= num:
                q.pop()
            q.append(i)
            if q[0] == i - k:
                q.popleft()
            if i >= k-1:
                ret.append(nums[q[0]])
        return ret
