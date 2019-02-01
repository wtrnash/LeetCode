/*
给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。

下图是字符串 s1 = "great" 的一种可能的表示形式。

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续将其节点 "eat" 和 "at" 进行交换，将会产生另一个新的扰乱字符串 "rgtae" 。

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

示例 1:

输入: s1 = "great", s2 = "rgeat"
输出: true
示例 2:

输入: s1 = "abcde", s2 = "caebd"
输出: false
*/

//解答：如果两个字符串互为扰乱字符串，那么有可能直接相等，就返回true；如果长度不等，一定不是，返回false；对其进行排序，由于其的字符一定是一一对应的，所以排完序如果不相等，也为false
//然后由于扰乱字符串的特性，一定能找到一个长度i，对两个字符串分别切分，然后s1的两个子串和s2的两个子串分别对应为扰乱字符串
//所以可以采用递归的方式进行
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)    //直接相等就返回true
            return true;
        if(s1.length() != s2.length())  //长度不同一定不是扰乱字符串
            return false;   
        
        string temp1 = s1;
        string temp2 = s2;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if(temp1 != temp2)  //判断里面的字符是否都一一对应
            return false;
        
        string s11, s12, s21, s22;
        for(int i = 1; i < s1.length(); i++)    //按长度i进行切分，如果是扰乱字符串。一定能找到子串互为扰乱字符串的
        {
            s11 = s1.substr(0, i);
            s12 = s1.substr(i);
            s21 = s2.substr(0, i);
            s22 = s2.substr(i);
            
            if(isScramble(s11, s21) && isScramble(s12, s22))    //子串是否互为扰乱字符串
                return true;
            
            s21 = s2.substr(0, s2.length() - i);
            s22 = s2.substr(s2.length() - i);
            
             if(isScramble(s11, s22) && isScramble(s12, s21))   //另一种切分方式
                return true;
             
        }
        
        return false;
    }
};