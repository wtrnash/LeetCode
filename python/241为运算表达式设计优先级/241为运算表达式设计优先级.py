"""
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:

输入: "2-1-1"
输出: [0, 2]
解释: 
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2:

输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

""""
# 解答：用递归，把每个符号分成左右两部分，然后分别按符号运算结果
class Solution:
    def diffWaysToCompute(self, input: str):
        result = []
        for i in range(len(input)):
            if input[i] == '+' or input[i] == '-' or input[i] == '*':
                r1 = self.diffWaysToCompute(input[0:i])
                r2 = self.diffWaysToCompute(input[i + 1:])
                for r in r1:
                    for q in r2:
                        if input[i] == '+':
                            result.append(r + q)
                        elif input[i] == '*':
                            result.append(r * q)
                        else:
                            result.append(r - q)
        
        if not result:
            result.append(int(input))
        return result
                