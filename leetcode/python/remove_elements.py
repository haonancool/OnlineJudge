# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        cur = head
        head = tail = None
        while cur:
            if cur.val != val:
                if head:
                    tail.next = cur
                    tail = cur
                else:
                    head = tail = cur
            cur = cur.next
        if tail: tail.next = None
        return head