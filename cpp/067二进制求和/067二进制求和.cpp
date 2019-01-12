/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/

//解答：最后每位相加，处理好进位，从后往前遍历直到其中一个到头为止。然后再处理没到头的。以及可能的最后一个进位。
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int n = a.length();
        int m = b.length();
        int carry = 0;
        int number;
        int i, j;
        for(i = n - 1, j = m -1; i >= 0 && j >= 0; i--, j--)
        {
            number = a[i] - '0' + b[j] - '0' + carry;
            if(number > 1)
            {
                number -= 2;
                carry = 1;
            }
            else
                carry = 0;
            result = to_string(number) + result;
        }
        
        while(i >= 0)
        {
            number = a[i--] - '0' + carry;
            if(number > 1)
            {
                number -= 2;
                carry = 1;
            }
            else
                carry = 0;
            result = to_string(number) + result;
        }
        
         while(j >= 0)
        {
            number = b[j--] - '0' + carry;
            if(number > 1)
            {
                number -= 2;
                carry = 1;
            }
            else
                carry = 0;
            result = to_string(number) + result;
        }
        
        if(carry == 1)
            result = "1" + result;
        
        return result;
    }
};