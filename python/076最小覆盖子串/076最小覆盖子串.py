"""
给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
"""

# 解答：首先我自己想的方法是，遍历所有元素，如果当前元素不在t中则continue,如果在t中，则以该元素为起始，找到剩下t中所有元素在s的下标，当前元素和最远的下标组成合法子串
# 每次比较，记录最短子串再返回，结果时间超限
"""
class Solution:
    def minWindow(self, s, t):
        if len(t) > len(s):
            return ""

        isFind = False
        minSub = ""
        for i in range(len(s)):
            isContinue = False
            if not s[i] in t:
                continue
            else:
                index_list = []
                temp = s[i:]
                for j in range(len(t)):
                    index = temp.find(t[j])
                    if index == -1:
                        if not isFind:
                            return ""
                        else:
                            isContinue = True
                            break
                    else:
                        while index in index_list:
                            if index == len(temp) - 1:
                                if not isFind:
                                    return ""
                                else:
                                    isContinue = True
                                    break
                            index = temp[index + 1:].find(t[j]) + index + 1
                            if index == -1:
                                if not isFind:
                                    return ""
                                else:
                                    isContinue = True
                                    break
                        index_list.append(index)

                if isContinue:
                    continue
                last = i + max(index_list)
                if not isFind:
                    isFind = True
                    minSub = s[i:last + 1]
                else:
                    currentSub = s[i:last + 1]
                    if len(currentSub) < len(minSub):
                        minSub = currentSub
                if len(minSub) == len(t):
                    return minSub

        return minSub
"""

# 解答：用两个指针来指向子串的左右，用滑动窗口法来找最小子串。用字典来判断是否包含所有字符
class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if s == "" or len(s) < len(t):  # s为空或s比t短则直接返回空
            return ""
        
        t_dict = {}
        for key in t:   # 记录每个字符出现的次数
            t_dict[key] = t_dict.get(key, 0) + 1
        
        result = ""
        left = 0
        right = 0
        count = 0
        temp_min = len(s) + 1
        while right < len(s):   # 右边没有遍历到末尾时
            if s[right] in t_dict:      # 如果右边的字符出现在t里面
                t_dict[s[right]] -= 1   # 字典里减1
                if t_dict[s[right]] >= 0:   # 仍然大于等于0说明s中的该字符对于t来说不多余，说明是有用的，所以count记录有效子串长度的则+1
                    count += 1
                while count == len(t):      # 如果有效子串长度和t长度一致，说明找到了符合要求的子串
                    if right - left + 1 < temp_min:     # 如果长度比最小值小则更新
                        temp_min = right - left + 1
                        result = s[left:right + 1]
                    if s[left] in t_dict:               # 此时把left往右移，为了找到最短的子串。如果出现在t中，则增加字典里的值，如果大于了0，说明去除了count里有用的一个字符，所以count - 1
                        t_dict[s[left]] += 1            # 不在的话说明是无用字符，去除掉后也没关系
                        if t_dict[s[left]] > 0:         
                            count -= 1
                    left += 1
            right += 1      # right往右移
            
        return result