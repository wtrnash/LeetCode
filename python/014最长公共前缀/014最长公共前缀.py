"""
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
"""

#解答 以第一个字符串作为基准，每个字符都和剩余字符串组对应位置的字符串进行比较，相等则继续，不相等则直接返回结果，注意判空和数组越界即可
class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        result = ""
        if len(strs) == 0:  # 判空
            return result
        for i in range(len(strs[0])):
            c = strs[0][i]
            for j in range(1, len(strs)):
                if len(strs[j]) <= i:   # 数组是否越界
                    return result
                
                if strs[j][i] != c:     # 判等
                    return result
            
            result = result + c
        
        return result