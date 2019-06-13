/*
在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。

每个矩形由其左下顶点和右上顶点坐标表示，如图所示。

示例:

输入: -3, 0, 3, 4, 0, -1, 9, 2
输出: 45
说明: 假设矩形面积不会超出 int 的范围。

*/

//求出两个矩形的面积。 判断是否相交，相交后求出交的面积，然后总面积减交的面积即可
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area1 = (C - A) * (D - B);
        long long area2 = (G - E) * (H - F);
        
        long long height, width;
        if(C <= E || G <= A || F >= D || B >= H)
            return area1 + area2;
        
        if(A <= E)
        {
            if(G <= C)
            {
                width = G - E;
            }
            else
            {
                width = C - E;
            }
                
        }
        else
        {
            if(C <= G)
            {
                width = C - A;
            }
            else
            {
                 width = G - A;
            }
               
        }
        
        if(B <= F)
        {
            if(H <= D)
            {
                height = H - F;
            }
            else
            {
                height = D - F;
            }
            
        }
        else
        {
            if(D <= H)
            {
                height = D - B;
            }
            else
            {
                height = H - B;
            }
        }
        
        return area1 + area2 - height * width;
        
    }
};