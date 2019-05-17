"""
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0

"""
# 解答：相当于找到不相同的高位位置，后面的都是0，因为按位与有一个是0就是0，而后面不同的一定会有0
# 所以先m和n左移，直到相等为止，再将m进行右移，相当于低位全补0
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        count = 0
        while m != n:
            m = m >> 1
            n = n >> 1
            count += 1
        
        return m << count