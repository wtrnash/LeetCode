/*
所有 DNA 由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来查找 DNA 分子中所有出现超多一次的10个字母长的序列（子串）。

示例:

输入: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

输出: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

//解答L使用unordered_set依次存储所有子串，如果当前子串已经在set中存在，则将其存入放结果的set中，最后将set转为vector
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set <string> result;
        unordered_set <string> a;
        for(int i = 0; i <= (int)s.length() - 10; i++)
        {
            string temp = s.substr(i, 10);
            if(a.find(temp) != a.end())
            {
                result.insert(temp);
            }
            else
            {
                a.insert(temp);
            }
        }
        
        vector<string> t;
        if(result.empty())
            return t;
        
        return vector<string>(result.begin(), result.end());
    }
};