class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        ret = []
        for i, c in enumerate(input):
            if c < '0' or c > '9':
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i+1:])
                for a in left:
                    for b in right:
                        if c == '+':
                            ret.append(a + b)
                        elif c == '-':
                            ret.append(a - b)
                        elif c == '*':
                            ret.append(a * b)
        if len(ret) == 0:
            ret.append(int(input))
        return ret
