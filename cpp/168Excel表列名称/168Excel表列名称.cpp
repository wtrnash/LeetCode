/*

给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
示例 1:

输入: 1
输出: "A"
示例 2:

输入: 28
输出: "AB"
示例 3:

输入: 701
输出: "ZY"
*/

//解答：相当于是把10进制数转换成26进制数，只是转换后要-1
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        vector<char> c;
        for(int i = 0; i < 26; i++)
            c.push_back('A' + i);
        
        string result = "";
        while(n != 0)
        {
            n -= 1;
            int a = n % 26;
            n /= 26;
            result = c[a] + result;
        }
        
        return result;
    }
};