class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        if len(num) == 0:
            return []
        ret = []
        self.dfs(num, target, 0, 0, 0, [], ret)
        return ret

    def dfs(self, num, target, i, cur, pre, tmp, ret):
        if i >= len(num):
            if cur == target:
                ret.append(''.join(tmp))
            return
        for j in xrange(i+1, len(num)+1):
            if num[i] == '0' and j > i+1:
                break
            n = int(num[i:j])
            if i > 0:
                tmp.append('+')
                tmp.append(num[i:j])
                self.dfs(num, target, j, cur+n, n, tmp, ret)
                tmp.pop()
                tmp.pop()
                tmp.append('-')
                tmp.append(num[i:j])
                self.dfs(num, target, j, cur-n, -n, tmp, ret)
                tmp.pop()
                tmp.pop()
                tmp.append('*')
                tmp.append(num[i:j])
                self.dfs(num, target, j, (cur-pre)+pre*n, pre*n, tmp, ret)
                tmp.pop()
                tmp.pop()
            else:
                tmp.append(num[i:j])
                self.dfs(num, target, j, n, n, tmp, ret)
                tmp.pop()

if __name__ == '__main__':
    sol = Solution()
    print sol.addOperators('123', 6)
