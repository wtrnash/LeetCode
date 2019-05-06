"""
所有 DNA 由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来查找 DNA 分子中所有出现超多一次的10个字母长的序列（子串）。

示例:

输入: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

输出: ["AAAAACCCCC", "CCCCCAAAAA"]
"""

# 解答:使用dict记录每个子串出现的次数，当当期子串已经出现1次时，加入result
class Solution:
    def findRepeatedDnaSequences(self, s: str):
        result = []
        m = {}
        for i in range(0, len(s) - 9):
            t = s[i : i + 10]
            if t in m.keys():
                if m[t] == 1:
                    result.append(t)
                m[t] += 1
            else:
                m[t] = 1
        
        return result
        