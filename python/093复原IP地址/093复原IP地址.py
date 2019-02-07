"""
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
"""

# 解答：用递归去处理，每次根据当前长度处理 1~3个字符。处理4次结束，如果此时s还有字符，则不加入结果。 要注意第一次处理不用前面加'.'，以及0开头的话就不能加两个或三个的字符
class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        temp = ''
        self.recursion(result, temp, s, 0)
        return result
    def recursion(self, result, temp, s, index):
        if index == 4:
            if len(s) == 0:
                result.append(temp[:])
            return
        
        if len(s) == 0:
            return
        
        if index == 0:
            temp = temp + s[0]
            self.recursion(result, temp, s[1:], index + 1)
            if s[0] == '0':
                return
            
            temp = temp + s[1]
            self.recursion(result, temp, s[2:], index + 1)
            
            if int(s[0]) * 100 + int(s[1]) * 10 + int(s[2]) < 256:
                temp = temp + s[2]
                self.recursion(result, temp, s[3:], index + 1)
                
        else:
            temp = temp + '.' + s[0]
            self.recursion(result, temp, s[1:], index + 1)
            if len(s) < 2 or s[0] == '0':
                return
            
            temp = temp + s[1]
            self.recursion(result, temp, s[2:], index + 1)
            
            if len(s) < 3:
                return 
            if int(s[0]) * 100 + int(s[1]) * 10 + int(s[2]) < 256:
                temp = temp + s[2]
                self.recursion(result, temp, s[3:], index + 1)
        