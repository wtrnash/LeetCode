/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/

//解答：模仿乘法的方式，用字符串的每一位乘以另一个字符串的每一位并最后相加即可。处理好对应的进位。
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) { 
        string result = "0";
        int carry;
        int number;
        string temp = "";
        for(int i = num2.size() - 1; i >= 0; i--)
        {
            if(num2[i] == '0')
                continue;
            temp = "";
            carry = 0;
            for(int j = num1.size() - 1; j >= 0; j--)   //处理num2当前一位与整个Num1的乘积
            {
                number = (num2[i] - '0') * (num1[j] - '0') + carry;
                carry = number / 10;
                number = number - carry * 10;
                temp = to_string(number) + temp;
            }
            if(carry > 0)   //处理最后一个进位
                temp = to_string(carry) + temp;
            
            for(int k = num2.size() - 1 - i; k > 0; k--)    //处理当前乘积的后置0个数
                if(temp != "" && temp != "0")
                    temp += "0";
            
            int j, k;
            carry = 0;
            for(j = temp.size() - 1, k = result.size() - 1; j >= 0, k >= 0; j--, k--)   //将结果加在原先的result上
            {
               number = (temp[j] - '0') + (result[k] - '0') + carry;
               if(number > 9)
               {
                   number -= 10;
                   carry = 1;
               }
               else
                   carry = 0;
               result[k] = '0' + number;
            }
            
            if(k >= 0 && j < 0)
            {
                result[k] += carry;
            }
            
            while(j >= 0 && k < 0)
            {
                number = (temp[j] - '0') + carry;
                if(number > 9)
                {
                    number -= 10;
                    carry = 1;
                }
                else
                    carry = 0;
                result =  to_string(number) + result;
                j--;
            }
            //处理最后一个进位
            if(carry > 0)
                result = to_string(carry) + result;
            
            
        }
        
        return result;
    }
};