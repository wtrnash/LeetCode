/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
2:abc
3:def
4:ghi
5:jkl
6:mno
7:pqrs
8:tuv
9:wxyz
示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

//根据输入的字符不同，分别使得原先的string数量乘以对应的倍数，每组后缀加上相同的字符即可

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> v;
		string temp;
		for (int i = 0; i < digits.length(); i++)
		{
			int num = digits[i] - '0';
			switch (num)
			{
			case 2:
				temp =  "abc";
				add(v, temp, 3);
				break;
			case 3:
				temp = "def";
				add(v, temp, 3);
				break;
			case 4:
				temp = "ghi";
				add(v, temp, 3);
				break;
			case 5:
				temp = "jkl";
				add(v, temp, 3);
				break;
			case 6:
				temp = "mno";
				add(v, temp, 3);
				break;
			case 7:
				temp = "pqrs";
				add(v, temp, 4);
				break;
			case 8:
				temp = "tuv";
				add(v, temp, 3);
				break;
			case 9:
				temp = "wxyz";
				add(v, temp, 4);
				break;
			}
		}

		return v;
	}

	void add(vector<string>& v, string temp, int size)  //将该字符分别加入v后缀
	{
		if (v.size() == 0)  //如果v为空则直接初始化对应数目的字符串
		{
			for (int i = 0; i < size; i++)
				v.push_back(string("") + temp[i]);
		}
		else
		{
			int vSize = v.size();
			for (int j = 0; j < size - 1; j++)  //将原有v中string的数量变成原先的size倍
			{
				for (int k = 0; k < vSize; k++)
				{
					v.push_back(v[k]);
				}
			}

			for (int j = 0; j < size; j++)  //每一组Vsize大小的string后缀加上同一个字符
			{
				for (int k = j * vSize; k < j * vSize + vSize; k++)
				{
					v[k] += temp[j];
				}
			}

		}
	}
};