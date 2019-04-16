"""

给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:

输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:

输入: numerator = 2, denominator = 1
输出: "2"
示例 3:

输入: numerator = 2, denominator = 3
输出: "0.(6)"
"""

# 解答：模拟除法。用map记录余数，如果余数重复出现，则为循环节。用Long Long防止溢出，处理好负号。
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator % denominator == 0:
            return str(numerator // denominator)
        
        result = ""
        if numerator * denominator < 0:
            result += '-'
        
        numerator = abs(numerator)
        denominator = abs(denominator)
        result += str(numerator // denominator) + "."
        a = numerator % denominator
        m = {}
        while a != 0:
            a *= 10
            b = a // denominator
            if a in m.keys():
                result = result[0:m[a]] + '(' + result[m[a]:] + ')'
                return result
            else:
                m[a] = len(result)
                result += str(b)
            
            a = a % denominator
        
        return result