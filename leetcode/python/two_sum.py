class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        table = {}
        ret = []
        for i, num in enumerate(nums, 1):
            if target-num in table:
                ret.append(table[target-num])
                ret.append(i)
                break
            else:
                table[num] = i
        return ret

if __name__ == "__main__":
	sol = Solution()
	print sol.twoSum([3, 2, 4], 6)
