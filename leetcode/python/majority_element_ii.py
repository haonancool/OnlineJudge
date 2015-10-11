class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n1 = n2 = None
        c1 = c2 = 0
        for num in nums:
            if n1 == num:
                c1 += 1
            elif n2 == num:
                c2 += 1
            elif c1 == 0:
                n1 = num
                c1 = 1
            elif c2 == 0:
                n2 = num
                c2 = 1
            else:
                c1 -= 1
                c2 -= 1
        c1 = c2 = 0
        for num in nums:
            if n1 == num:
                c1 += 1
            elif n2 == num:
                c2 += 1
        ret = []
        n = len(nums)
        if c1 > n/3:
            ret.append(n1)
        if c2 > n/3:
            ret.append(n2)
        return ret

if __name__ == '__main__':
    sol = Solution()
    print sol.majorityElement([8, 8, 7, 7, 7])
