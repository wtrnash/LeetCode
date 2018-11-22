"""
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
"""
# 解答：考虑到时间因素，这里使用了左移操作，将被除数看成除数*（2^n + 2^x + ……）,看成除数和若干个2的几次方相乘，这样使用左移和减法一起，每次减去 比被除数小的
# 且是最大的除数乘以2的几次方，然后更新被除数，以此类推直到被除数小于除数为止
class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        int_max = 2 ** 31 - 1
        int_min = - 2 ** 31
        if divisor == 1:
            return dividend
        if divisor == -1:
            if dividend == int_min:
                return int_max
            else:
                return -dividend
        flag = True
        if dividend < 0:
            dividend = -dividend
            flag = not flag
        
        if divisor < 0:
            divisor = -divisor
            flag = not flag
        
        result = 0
        while dividend >= divisor:
            temp = divisor
            cur = 1
            while dividend >= (temp << 1):
                temp = temp << 1
                cur = cur << 1
            
            dividend = dividend - temp
            result = result + cur
        
        if not flag:
            result = -result
        
        if result < int_min or result > int_max:
            return int_max
        
        return result
            