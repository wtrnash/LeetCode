/*
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"
*/

//解答：即每次对上一个字符串进行判断，记录每个连续相同数字的个数，形成新的字符串，以此类推
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        vector<string> nums = {"1"};
        int count;
        string current, temp;
        for(int i = 1; i <= n - 1; i++)
        {
            count = 1;
            current = nums[nums.size() - 1];
            for(int j = 1; j < current.length(); j++)
            {
                if(current[j] == current[j - 1])
                {
                    count++;
                }
                else
                {
                    temp += to_string(count) + current[j - 1];
                    count = 1;
                }
            }
            
            temp += to_string(count) + current[current.length() - 1];
            nums.push_back(temp);
            temp = "";
        }
        
        return nums[n - 1];
        
        
    }
};