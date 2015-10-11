class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s0 = []
        self.s1 = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.s0.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        self.peek()
        self.s1.pop()

    def peek(self):
        """
        :rtype: int
        """
        if len(self.s1) == 0:
            while len(self.s0) > 0:
                self.s1.append(self.s0.pop())
        return self.s1[-1]

    def empty(self):
        """
        :rtype: bool
        """
        if len(self.s0) == 0 and len(self.s1) == 0:
            return True
        return False
