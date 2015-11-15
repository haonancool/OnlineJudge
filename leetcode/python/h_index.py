class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        ret = 0
        for i, citation in enumerate(sorted(citations, reverse=True), 1):
            if i > citation:
                ret = i - 1
                break
        else:
            ret = len(citations)
        return ret
