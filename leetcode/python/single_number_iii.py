class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        a = 0
        for num in nums:
            a ^= num
        i = 0
        while a & 0x1 == 0:
            a >>= 1
            i += 1
        a &= 0x1
        a <<= i
        b = c = 0
        for num in nums:
            if num & a:
                b ^= num
            else:
                c ^= num
        return [b, c]

if __name__ == '__main__':
    sol = Solution()
    print sol.singleNumber([1,2,1,3,5,2])
