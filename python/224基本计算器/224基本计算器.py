"""
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例 1:

输入: "1 + 1"
输出: 2
示例 2:

输入: " 2-1 + 2 "
输出: 3
示例 3:

输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

"""
# 解答：维护一个数字栈一个符号栈，遇到数字则遍历到不是数字后将其加入数字栈， 遇到符号则先判断符号栈有无符号，有的话则弹出两个数字和符号进行运算
# 遇到右括号则一直运算到左括号为止
class Solution:
    def calculate(self, s: str) -> int:
        nums = []
        signs = []
        n = len(s)
        i = 0
        while i < n:
            if s[i] == ' ':
                i += 1
            elif '0' <= s[i] <= '9':
                j = i
                while j < n and '0' <= s[j] <= '9':
                    j += 1
                
                nums.append(int(s[i:j]))
                i = j
            elif s[i] == '(':
                signs.append(s[i])
                i += 1
            elif s[i] == ')':
                while signs[-1] != '(':
                    temp = signs.pop()
                    num2 = nums.pop()
                    num1 = nums.pop()
                    if temp == '+':
                        nums.append(num1 + num2)
                    else:
                        nums.append(num1 - num2)
                signs.pop()
                i += 1
            else:
                if signs and signs[-1] != '(':
                    temp = signs.pop()
                    num2 = nums.pop()
                    num1 = nums.pop()
                    if temp == '+':
                        nums.append(num1 + num2)
                    else:
                        nums.append(num1 - num2)
                signs.append(s[i])
                i += 1
        
        if signs:
            temp = signs.pop()
            num2 = nums.pop()
            num1 = nums.pop()
            if temp == '+':
                nums.append(num1 + num2)
            else:
                nums.append(num1 - num2)
        return nums[0]