class MinStack(object):
    def __init__(self):
        self.s0 = []
        self.s1 = []

    def push(self, x):
        if len(self.s1) > 0 and self.s1[-1] < x:
            n = self.s1[-1]
        else:
            n = x
        self.s0.append(x)
        self.s1.append(n)

    def pop(self):
        self.s0.pop()
        self.s1.pop()

    def top(self):
        return self.s0[-1]

    def getMin(self):
        return self.s1[-1]
