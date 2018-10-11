"""
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
"""

# 解答， 先对正负进行处理，统一化成正的进行转换， 然后对值进行判断范围，在范围之外输出0

class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = True
        if x < 0:
            x = -x
            flag = False

        result = 0
        while x > 0:
            result = result * 10 + x % 10
            x = (x - x % 10)/ 10
        
        if not flag:
            result = -result
        
        if result < -2**31 or result > 2**31 - 1:
            result = 0
        return int(result)


s = Solution()
print(s.reverse(-123))