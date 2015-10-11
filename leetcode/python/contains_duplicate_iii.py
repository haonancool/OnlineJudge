class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if k == 0:
            return False
        buckets = {}
        for i, num in enumerate(nums):
            if t > 0:
                bucket_num, offset = num / t, 1
            else:
                bucket_num, offset = num, 0
            for j in xrange(bucket_num-offset, bucket_num+offset+1):
                if j in buckets and abs(buckets[j]-num) <= t:
                    return True
            if i >= k:
                if t > 0:
                    del buckets[nums[i-k]/t]
                else:
                    del buckets[nums[i-k]]
            buckets[bucket_num] = num
        return False
