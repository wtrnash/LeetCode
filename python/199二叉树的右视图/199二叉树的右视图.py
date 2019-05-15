"""

给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
"""
# 解答:层序遍历，每层最后一个放入结果中
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rightSideView(self, root: TreeNode):
        result = []
        q = []
        if not root:
            return result
        q.append(root)
        while q:
            count = len(q)
            while count > 0:
                t = q.pop(0)
                count -= 1
                if t.left:
                    q.append(t.left)
                if t.right:
                    q.append(t.right)
                
                if count == 0:
                    result.append(t.val)
        
        return result