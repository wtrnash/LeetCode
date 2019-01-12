"""
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
"""

# 解答：最后每位相加，处理好进位，从后往前遍历直到其中一个到头为止。然后再处理没到头的。以及可能的最后一个进位。
class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        n = len(a)
        m = len(b)
        result = []
        i = n - 1
        j = m - 1
        carry = 0
        while i >= 0 and j >= 0:
            number = int(a[i]) + int(b[j]) + carry
            if number > 1:
                carry = 1
                number = number - 2
            else:
                carry = 0
            result.insert(0, str(number))            
            i = i - 1
            j = j - 1
        
        while i >= 0:
            number = int(a[i]) + carry
            if number > 1:
                carry = 1
                number = number - 2
            else:
                carry = 0
            result.insert(0, str(number))            
            i = i - 1
            
        while j >= 0:
            number = int(b[j]) + carry
            if number > 1:
                carry = 1
                number = number - 2
            else:
                carry = 0
            result.insert(0, str(number))            
            j = j - 1
        
        if carry == 1:
            result.insert(0, '1')
        
        return "".join(result)
        