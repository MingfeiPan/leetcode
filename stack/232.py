class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = []
        self.size = 0
        

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self.queue.append(x)
        self.size += 1
        

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        temp = self.queue[0]
        del self.queue[0]
        self.size -= 1
        return temp
        

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        return self.queue[0]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return self.size == 0
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
