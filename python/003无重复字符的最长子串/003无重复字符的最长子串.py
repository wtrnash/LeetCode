"""
题目：
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
"""
"""
解答：
遍历整个字符串，每遍历一个元素，都将其值和下标存入字典，并判断该元素在不在字典内，如果在，并且下标在子串的开始位置之后，说明有重复，
修改开始位置为前面一个重复字符的后一个。每次循环，比较当前长度（当前i减去开始的位置+1）和历史最长长度，记录最长值。
"""
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_length = 0
        d = {}
        length = len(s)
        start = 0
        for i in range(length):
            if s[i] in d and d[s[i]] >= start:
                start = d[s[i]] + 1 # 新开始的子串位置在重复的字符后一个
            temp = i - start + 1
            max_length = max(max_length, temp)
            d[s[i]] = i
        
        return max_length


a = Solution()
print(a.lengthOfLongestSubstring("abcabcbb"))