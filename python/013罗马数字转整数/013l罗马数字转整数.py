"""
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
"""

# 解答 类似12题的思路，从最大的开始判断即可

class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        i = 0
        while i < len(s) :
            if s[i] == 'M':
                result =  result + 1000
            elif s[i] == 'C' and i + 1 < len(s) and s[i + 1] == 'M':
                result = result + 900
                i = i + 1
            elif s[i] == 'D':
                result = result + 500
            elif s[i] == 'C' and i + 1 < len(s) and s[i + 1] == 'D':
                result = result + 400
                i = i + 1
            elif s[i] == 'C':
                result = result + 100
            elif s[i] == 'X' and i + 1 < len(s) and s[i + 1] == 'C':
                result = result + 90
                i = i + 1
            elif s[i] == 'L':
                result = result + 50
            elif s[i] == 'X' and i + 1 < len(s) and s[i + 1] == 'L':
                result = result + 40
                i = i + 1
            elif s[i] == 'X':
                result = result + 10
            elif s[i] == 'I' and i + 1 < len(s) and s[i + 1] == 'X':
                result = result + 9
                i = i + 1
            elif s[i] == 'V':
                result = result + 5
            elif s[i] == 'I' and i + 1 < len(s) and s[i + 1] == 'V':
                result =  result + 4
                i = i + 1
            else:
                result = result + 1
            
            i = i + 1
        return result