"""
给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

下图是字符串 s1 = "great" 的一种可能的表示形式。

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续将其节点 "eat" 和 "at" 进行交换，将会产生另一个新的扰乱字符串 "rgtae" 。

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

示例 1:

输入: s1 = "great", s2 = "rgeat"
输出: true
示例 2:

输入: s1 = "abcde", s2 = "caebd"
输出: false
"""

# 解答：如果两个字符串互为扰乱字符串，那么有可能直接相等，就返回true；如果长度不等，一定不是，返回false；对其进行排序，由于其的字符一定是一一对应的，所以排完序如果不相等，也为false
# 然后由于扰乱字符串的特性，一定能找到一个长度i，对两个字符串分别切分，然后s1的两个子串和s2的两个子串分别对应为扰乱字符串
# 所以可以采用递归的方式进行
class Solution:
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if s1 == s2:
            return True
        if not len(s1) == len(s2):
            return False
        temp1 = "".join(sorted(s1[:]))
        temp2 = "".join(sorted(s2[:]))
        if not temp1 == temp2:
            return False
        
        for i in range(1, len(s1)):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True
            
            if self.isScramble(s1[:i], s2[-i:]) and self.isScramble(s1[i:], s2[:-i]):
                return True
        
        return False