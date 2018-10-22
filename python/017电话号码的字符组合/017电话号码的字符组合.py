"""
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
2:abc
3:def
4:ghi
5:jkl
6:mno
7:pqrs
8:tuv
9:wxyz
示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

"""

# 遍历当前数字对应字符串的长度，每次都在之前的result的所有结果后加上当前字符串下标对应的字母
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        # 判空
        if len(digits) == 0:
            return []
        
        # 下标和字符值的对应数组
        digits_to_str = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        result = [""]
        for i in range(len(digits)):
            temp = []
            letter = digits_to_str[int(digits[i])]
            # 遍历字符串
            for j in range(len(letter)):
                # 遍历之前的结果
                for k in range(len(result)):
                    temp.append(result[k] + letter[j])
            result = temp
            
        return result