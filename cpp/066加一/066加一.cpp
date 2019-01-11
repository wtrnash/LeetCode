/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

//解答：从后往前遍历，处理好进位即可。注意第一位如果进位成10，要在最前面插入1。
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool isCarry = true;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            if(isCarry)
            {
                digits[i]++;
                if(digits[i] == 10)
                {
                    digits[i] = 0;
                }
                else
                {
                    isCarry = false;
                }
            }
            else
                break;
        }
        
        if(isCarry)
        {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
