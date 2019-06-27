/*
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

示例:

输入: 13
输出: 6 
解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
*/

//解答：直接暴力做如下会超时
/*
class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++)
            count += countOne(i);
        
        return count;
    }
    
    int countOne(int n)
    {
        int count = 0;
        while(n > 0)
        {
            int temp = n % 10;
            if(temp == 1)
                count++;
            
            n /= 10;
        }
        
        return count;
    }
};

*/

//解答：分别计算每位的1的个数。然后对当前位是0、1、>1分别处理。 综合就是  result += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1) 
//a为高位，当其个位大于等于2时，对1的贡献再多加i个。 而个位为1时，则多加低位个数 + 1个1。 比如求百位的1，后三位是192，则 100 到 192为百位贡献了93个1。 若大于等于2，则直接是100个1
class Solution {
public:
    int countDigitOne(int n) {
        int result = 0;
        for(long i = 1; i <= n; i *= 10)
        {
            long a = n / i;
            int b = n % i;
            result += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
        }
        
        return result;
    }
    
};