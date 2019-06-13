"""
在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。

每个矩形由其左下顶点和右上顶点坐标表示，如图所示。

示例:

输入: -3, 0, 3, 4, 0, -1, 9, 2
输出: 45
说明: 假设矩形面积不会超出 int 的范围。

"""

# 求出两个矩形的面积。 判断是否相交，相交后求出交的面积，然后总面积减交的面积即可
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        s1, s2 = (C - A) * (D - B), (G - E) * (H - F)
        w = min(C, G) - max(A, E) if min(C, G) - max(A, E) > 0 else 0
        h = min(D, H) - max(B, F) if min(D, H) - max(B, F) > 0 else 0
        return s1 + s2 - w * h