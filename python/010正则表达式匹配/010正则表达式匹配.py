"""
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
"""
# 解答：我一开始以为*前的所有都能不断重复，所以走了很多弯路，后来发现*只对前一个字符起作用
# 要注意可能前面带*能匹配但实际上不用去匹配，要用后面的去匹配，所以需要用到栈来处理，这里使用递归函数来做
# 每次实际上最多处理两位，先判断p是否为空，再判断p是否为1位，再判断p两位时第二位是不是*,不是*则直接匹配前一位
# 是*时先要看看当前直接置空，用后面去匹配能不能行，不行再直接用当前这个去匹配s第一个，s往后移，一直到s为空或匹配不上为止
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        # p为空时
        if len(p) == 0:
            if len(s) == 0:
                return True
            else:
                return False
        
        # p是一位时
        if len(p) == 1:
            if len(s) == 1 and (s[0] == p[0] or p[0] == '.'):
                return True
            else:
                return False
        
        # p是两位且第二位不是*时
        if p[1] != '*':
            if len(s) != 0 and (s[0] == p[0] or p[0] == '.'):
                return self.isMatch(s[1:], p[1:])
            else:
                return False
        
        # p是两位且第二位是*
        while len(s) != 0 and (s[0] == p[0] or p[0] == '.'):
            if self.isMatch(s, p[2:]):
                return True
            else:
                s = s[1:]
        
        return self.isMatch(s, p[2:])