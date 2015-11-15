# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator(object):
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator(object):
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.flag = False
        self.cache = None
        self.iter = iterator

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if not self.flag:
            self.cache = self.iter.next()
            self.flag = True
        return self.cache

    def next(self):
        """
        :rtype: int
        """
        if self.flag:
            self.flag = False
            return self.cache
        else:
            return self.iter.next()

    def hasNext(self):
        """
        :rtype: bool
        """
        if not self.flag:
            try:
                self.cache = self.iter.next()
                self.flag = True
            except StopIteration:
                self.flag = False
        return self.flag

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].

if __name__ == '__main__':
    it = PeekingIterator(iter([1,2,3,4]))
    res = []
    for i in [0,1,1,2,2,1,1,2,0,1,0,2,0]:
        if i == 0:
            res.append(it.hasNext())
        elif i == 1:
            res.append(it.peek())
        elif i == 2:
            res.append(it.next())
    print res
