class Solution(object):
    def getIntersectionNode(self, headA, headB):
        m = self.getLength(headA)
        n = self.getLength(headB)
        if m > n:
            for i in xrange(m-n):
                headA = headA.next
        elif m < n:
            for i in xrange(n-m):
                headB = headB.next
        while headA and headB:
            if headA is headB:
                return headA
            else:
                headA = headA.next
                headB = headB.next
    
    def getLength(self, root):
        ret = 0
        while root:
            ret += 1
            root = root.next
        return ret
