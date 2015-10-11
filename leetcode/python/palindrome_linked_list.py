# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        n = self.get_length(head)
        if n <= 1:
            return True
        p, q, r = None, head, head.next
        for i in xrange((n+1)/2):
            p = q
            q = r
            r = r.next
        p.next = None
        p = None
        while q:
            q.next = p
            p, q = q, r
            if r:
                r = r.next
        while p:
            if p.val != head.val:
                return False
            else:
                p = p.next
                head = head.next
        return True

    def get_length(self, head):
        ret = 0
        while head:
            ret += 1
            head = head.next
        return ret
