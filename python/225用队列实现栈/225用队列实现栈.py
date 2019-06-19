"""
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

"""

# 解答：利用队列实现。push时将前面的元素都弹出加入到最后一个元素的后面，达成效果。
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.s = []
        

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.s.append(x)
        for i in range(len(self.s) - 1):
            self.s.append(self.s.pop(0))
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.s.pop(0)

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.s[0]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.s) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
