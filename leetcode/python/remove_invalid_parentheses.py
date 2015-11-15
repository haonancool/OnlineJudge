from collections import deque


class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        def help(ss):
            stack = []
            for i, c in enumerate(ss):
                if c == '(':
                    stack.append(i)
                elif c == ')':
                    if stack:
                        stack.pop()
                    else:
                        return i
            if stack:
                return stack.pop()
            else:
                return -1

        ret = []
        q = deque([s])
        visited = set([s])
        while q:
            cur = q.popleft()
            i = help(cur)
            if i == -1:
                ret.append(cur)
                continue
            left, right = 0, len(cur) - 1
            if cur[i] == '(':
                left = i
            else:
                right = i
            for j in xrange(left, right + 1):
                if cur[j] != cur[i] or (j > left and cur[j] == cur[j - 1]):
                    continue
                tmp = cur[:j] + cur[j + 1:]
                if tmp not in visited:
                    visited.add(tmp)
                    q.append(tmp)
        return ret


if __name__ == '__main__':
    sol = Solution()
    print sol.removeInvalidParentheses('((')
