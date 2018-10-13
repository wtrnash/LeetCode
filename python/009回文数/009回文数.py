"""
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？
"""

# 解答：只反转后半部分的代码如下，要注意位数只有奇数位时，反转的后半部分如果除以10和前半部分相等也是回文数，这样速度会比较快
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or (x != 0 and x % 10 == 0):   # 排除负数和以0结尾的情况
            return False
        
        result = 0
        while x > result:
            result = result * 10 + x % 10
            x = int(x / 10)
        
        if x == result:
            return True
        elif int(result / 10) == x:
            return True
        else:
            return False


# 转成字符串做速度更快
"""
class Solution:
    def isPalindrome(self, x):
      
        if x < 0:
            return False
        
        x = str(x)
        i = 0
        length = len(x) - 1
        while i < length:
            if x[i] != x[length]:
                return False
            i = i + 1
            length = length - 1
        return True
"""