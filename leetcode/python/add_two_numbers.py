class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1:
        	return l2
        elif not l2:
            return l1
        carry = 0
        head = tail = None
        while l1 and l2:
            num = l1.val+l2.val+carry
            carry = num/10
            num %= 10
            node = ListNode(num)
            if not head:
            	head = tail = node
            else:
            	tail.next = node
            	tail = node
            l1, l2 = l1.next, l2.next
        while l1:
            num = l1.val+carry
            carry = num / 10
            num %= 10
            node = ListNode(num)
            tail.next = node
            tail = node
            l1 = l1.next
        while l2:
            num = l2.val+carry
            carry = num / 10
            num %= 10
            node = ListNode(num)
            tail.next = node
            tail = node
            l2= l2.next
        if carry > 0:
            node = ListNode(carry)
            tail.next = node
       	    tail = node
        return head
