"""
给定一个字符串 s 和一些长度相同的单词 words。在 s 中找出可以恰好串联 words 中所有单词的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

示例 1:

输入:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出: [0,9]
解释: 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2:

输入:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
输出: []
"""

# 解答：用一个map记录每个字串和对应出现的次数，然后遍历s，以s的每一个元素作为起始，直到以某一个元素作为起始，但后面的长度不够包含所有字串为止
# 然后取出s中和字串同样长度的子串，先看map中有没有，如果没有则跳出当前循环，直接从s的下一个元素当起始继续，如果有
# 则加入一个新的map，并且比较两个map中同一个字串的数量，如果第二个map中的数量超出了，也跳出该循环

class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        result = []
        if len(s) == 0 or len(words) == 0:
            return result
    
        dict1 = {}
        for i in range(len(words)):
            if not words[i] in dict1:
                dict1[words[i]] = 1
            else:
                dict1[words[i]] = dict1[words[i]] + 1
        
        m = len(words)
        n = len(words[0])
        for i in range(len(s) - m * n + 1):
            dict2 = {}
            j = 0
            while j < m:
                temp = s[i + j * n: i + (j + 1) * n]
                if not temp in dict1:
                    break
                if not temp in dict2:
                    dict2[temp] = 1
                else:
                    dict2[temp] = dict2[temp] + 1
                
                if dict2[temp] > dict1[temp]:
                    break
                j = j + 1
            if j  == m:
                result.append(i)
        
        return result
                