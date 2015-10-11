from collections import deque

class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.q0 = deque()
        self.q1 = deque()
        self.last = None

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.q0.append(x)
        self.last = x

    def pop(self):
        """
        :rtype: nothing
        """
        x = self.q0.popleft()
        self.last = None
        while len(self.q0) > 0:
            self.q1.append(x)
            self.last = x
            x = self.q0.popleft()
        self.q0, self.q1 = self.q1, self.q0
        return x

    def top(self):
        """
        :rtype: int
        """
        return self.last

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.q0) == 0
