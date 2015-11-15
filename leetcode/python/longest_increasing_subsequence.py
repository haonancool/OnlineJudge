class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        table = []
        for num in nums:
            if len(table) == 0:
                table.append(num)
            else:
                left, right = 0, len(table) - 1
                while True:
                    mid = (left + right) / 2
                    if mid < 0:
                        table[0] = num
                        break
                    elif table[mid] < num:
                        if mid == len(table) - 1:
                            table.append(num)
                            break
                        elif table[mid + 1] >= num:
                            table[mid + 1] = num
                            break
                        else:
                            left = mid + 1
                    else:
                        right = mid - 1
        return len(table)


if __name__ == '__main__':
    sol = Solution()
    print sol.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18])
