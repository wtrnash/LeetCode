"""
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
"""
# 解答：利用字典，由于每个字母异位词排序后都是一样的，所以可以将其作为key，value即为字符串数组

class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        result = []
        m = {}
        for i in strs:
            a = "".join(sorted(i))
            if a in m:
                m[a].append(i)
            else:
                m[a] = [i]
        
        for i in m.values():
            result.append(i)
        
        return result
            