"""
将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：

P   A   H   N
A P L S I I G
Y   I   R
之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:

string convert(string s, int numRows);
示例 1:

输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"
示例 2:

输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P     I    N
A   L S  I G
Y A   H R
P     I
"""

# 按行进行处理， 第一行和最后一行的下一个离当前的差2 * numRows - 2个，而不是第一行和最后一行的索引位置是 j + i 以及 j + 2 * numRows - 2 - i
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        
        result = ""
        for i in range(numRows):
            j = 0
            while i + j < len(s):
                result = result + s[i + j]
                if i != 0 and i != numRows - 1 and j + 2 * numRows - 2 - i < len(s):
                    result = result + s[j + 2 * numRows - 2 - i]

                j = j + 2 * numRows - 2
        
        
        return result



# s = Solution()

# print(s.convert("PAYPALISHIRING", 3))