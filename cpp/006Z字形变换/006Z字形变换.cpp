/*
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
*/

/*
解答：把每个字符放入对应的行，到最下面或最上面就更改方向，最后按行输出
*/
#include <vector>
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string result = "";
      
        vector<string> v;
        for(int i = 0; i < numRows; i++)
        {
            string temp = "";
            v.push_back(temp);
        }
        
        int j = 0;
        bool add = true;
        for(int i = 0; i < s.length(); i++)
        {
            if(add)
            {
                v[j] += s[i];
                j++;
            }
            else
            {
                v[j] += s[i];
                j--;
            }
            
            if(j == numRows)
            {
                j = j - 2;
                add = false;
            }
            else if(j < 0)
            {
                
                j = 1; 
                add = true;
            }
            
        }
        
        for(int i = 0; i < v.size(); i++)
        {
            for(int k = 0; k < v[i].length(); k++)
                result += v[i][k];
        }
        
        return result;
    }
};