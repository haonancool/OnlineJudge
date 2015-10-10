class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0: return 0
        left = right = 0
        sum = 0
        ret = n+1
        while right < n:
            sum += nums[right]
            while left <= right and sum >= s:
                if left == right:
                    return 1
                ret = min(ret, right-left+1)
                sum -= nums[left]
                left += 1
            right += 1
        if ret == n+1:
            return 0
        else:
            return ret

if __name__ == '__main__':
    sol = Solution()
    print sol.minSubArrayLen(5, [2, 3, 1, 1, 1, 1, 1])
