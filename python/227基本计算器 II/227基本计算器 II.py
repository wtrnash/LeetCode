"""
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:

输入: "3+2*2"
输出: 7
示例 2:

输入: " 3/2 "
输出: 1
示例 3:

输入: " 3+5 / 2 "
输出: 5
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

"""

# 解答：只用数字栈，用一个字符记录上一个符号。然后先计算完乘除法，最后统一加一遍即可。
class Solution:
    def calculate(self, s: str) -> int:
        nums = []
        d = 0
        sign = '+'
        for i in range(len(s)):
            if '0' <= s[i] <= '9':
                d = 10 * d + int(s[i])
            
            if (s[i] < '0' and s[i] != ' ') or i == len(s) - 1:
                if sign == '+':
                    nums.append(d)
                elif sign == '-':
                    nums.append(-d)
                else:
                    if sign == '*':
                        temp = nums[-1] * d
                    else:
                        if nums[-1] < 0:
                            temp = -((-nums[-1]) // d)  # python的//为向下取整，比如- 3/2，需要的是-1，直接//是-2
                        else:
                            temp = nums[-1] // d
                    nums.pop()
                    nums.append(temp)
                    
                d = 0
                sign = s[i]
        
        result = 0
        for i in nums:
            result += i
        return result
                        