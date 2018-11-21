/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/

// 解答： 遍历第一个字符串，每个元素都当做第二个字符串的起始元素进行比较，然后遍历完第二个字符串，如果碰到不相同直接跳出，全部相同则返回第一个字符串遍历的当前元素
// 遍历第一个字符串只要遍历到第一个字符串长度减去第二个字符串长度的位置即可，因为后面的由于第二个字符串比较长，一定不会相等，所以不用遍历，这样能提高很多速度
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length())
            return -1;
        if(needle.length() == 0)
            return 0;
        
        int j;
        for(int i = 0; i <= haystack.length() - needle.length(); i++)
        {
            for(j = 0; j < needle.length(); j++)
            {
                if(haystack[i + j] != needle[j])
                {
                    break; 
                }
            }
            
            if(j == needle.length())
                return i;
        }
        
        return -1;
    }
};