"""
验证给定的字符串是否为数字。

例如:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。
"""
# 解答：将字符分成 正负号、e、数字、小数点、空格和其他字符六类，分别处理即可。
class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        num = False
        num_after_e = True
        sign = False
        dot = False
        exp = False
        n = len(s)
        for i in range(n):
            if s[i] == ' ':
                if (num or sign or dot or exp) and i < n - 1 and not s[i + 1] == ' ':
                    return False
            elif s[i] == '+' or s[i] == '-':
                if i > 0 and not s[i - 1] == 'e' and not s[i - 1] == ' ':
                    return False
                sign = True
            elif s[i] == 'e':
                if exp or not num:
                    return False
                num_after_e = False
                exp = True
            elif s[i] == '.':
                if exp or dot:
                    return False
                dot = True
            elif s[i].isdigit():
                num = True
                num_after_e = True
            else:
                return False
        
        return num and num_after_e
                