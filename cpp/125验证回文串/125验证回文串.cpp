/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/

//解答：用i，j记录遍历的开始、末尾元素，将其他符号跳过，将大写转为小写，然后比较，如果不相等则返回false，遍历完后返回true

#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(n == 0)
            return true;
        int i = 0, j = n - 1;
        while(i < j)
        {
            
            while(!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z') && i < n)
            {
                i++;
            }
            
            if(i == n)
                return true;
            
          while(!(s[j] >= 'a' && s[j] <= 'z' || s[j] >= '0' && s[j] <= '9' || s[j] >= 'A' && s[j] <= 'Z') && j > -1)
            {
                j--;
            }
            
            if(j == -1)
                return true;
                
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
            
             if(s[j] >= 'A' && s[j] <= 'Z')
                s[j] = s[j] - 'A' + 'a';
            
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};