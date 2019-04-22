"""
实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

调用 next() 将返回二叉搜索树中的下一个最小的数。

示例：

BSTIterator iterator = new BSTIterator(root);
iterator.next();    // 返回 3
iterator.next();    // 返回 7
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 9
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 15
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 20
iterator.hasNext(); // 返回 false
 

提示：

next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。
"""
# 解答：中序遍历获得升序数字串，记录当前访问到第几个即可
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root):
        self.tree = []
        self.current = 0
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            
            if stack:
                temp = stack[-1]
                self.tree.append(temp.val)
                root = temp.right
                stack.pop()
        

    def next(self) -> int:
        """
        @return the next smallest number
        """
        result = self.tree[self.current]
        self.current += 1
        return result

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        if self.current >= len(self.tree):
            return False
        else:
            return True
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
