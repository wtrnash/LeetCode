/*
题目：
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

你可以假设 nums1 和 nums2 均不为空。

 

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
*/
/*
解答：
一开始最简单的想法是因为两个数组是有序的，所以顺次比较，将小的放入新的数组，以此类推，两个数组合成新的数组后取中位数，但这样时间
复杂度是O(max(m, n)), 如下：

*/

#include <vector>
using namespace std;
/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sum;
        int i, j;
        for(i = 0, j = 0; i < nums1.size() && j < nums2.size();)
        {
            if(nums1[i] < nums2[j])
            {
                sum.push_back(nums1[i++]);
            }
            else
            {
                sum.push_back(nums2[j++]);
            }
        }

        while(i < nums1.size())
        {
            sum.push_back(nums1[i++]);
        }

        while(j < nums2.size())
        {
            sum.push_back(nums2[j++]);
        }

        if(sum.size() % 2 == 0)
        {
            return 1.0 * (sum[sum.size() / 2 - 1] + sum[sum.size() / 2]) / 2; 
        }
        else
        {
            return sum[sum.size() / 2];  
        }
    }
};
*/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		double median1, median2;
		if (n == 0)
		{
			if (m % 2)
				return nums2[m / 2];
			else
				return 1.0 * (nums2[m / 2 - 1] + nums2[m / 2]) / 2;
		}

		if (m == 0)
		{
			if (n % 2)
				return nums1[n / 2];
			else
				return 1.0 * (nums1[n / 2 - 1] + nums1[n / 2]) / 2;
		}

		if (n == 1 && m == 1)
			return 1.0 * (nums1[0] + nums2[0]) / 2;

		if (n % 2)
		{
			median1 = nums1[n / 2];
		}
		else
		{
			median1 = 1.0 * (nums1[n / 2 - 1] + nums1[n / 2]) / 2;
		}

		if (m % 2)
		{
			median2 = nums2[m / 2];
		}
		else
		{
			median2 = 1.0 * (nums2[m / 2 - 1] + nums2[m / 2]) / 2;
		}

		if (median1 > median2)
		{
			if (n % 2 && m % 2)
				return findMedian(nums1, nums2, 0, (n - 1) / 2 - 1, m / 2 + 1, m - 1);
			else if (n % 2 && (m % 2 == 0))
				return findMedian(nums1, nums2, 0, (n - 1) / 2 - 1, m / 2, m - 1);
			else if ((n % 2 == 0) && m % 2)
				return findMedian(nums1, nums2, 0, (n - 1) / 2, m / 2 + 1, m - 1);
			else
			{
				//处理 输入为 [1, 2], [-1, 3]的情况
				if (nums1[n / 2 - 1] >= nums2[m / 2])
					return findMedian(nums1, nums2, 0, (n - 1) / 2, m / 2, m - 1);
				else
					return median1;
			}


		}
		else if (median1 < median2)
		{
			if (n % 2 && m % 2)
				return findMedian(nums1, nums2, n / 2 + 1, n - 1, 0, (m - 1) / 2 - 1);
			else if (n % 2 && (m % 2 == 0))
				return findMedian(nums1, nums2, n / 2 + 1, n - 1, 0, (m - 1) / 2);
			else if ((n % 2 == 0) && m % 2)
				return findMedian(nums1, nums2, n / 2, n - 1, 0, (m - 1) / 2 - 1);
			else
			{
				if (nums2[m / 2 - 1] >= nums1[n / 2])
					return findMedian(nums1, nums2, n / 2, n - 1, 0, (m - 1) / 2);
				else
					return median2;
			}

		}
		else
			return median1;
	}

	double findMedian(vector<int>& nums1, vector<int>& nums2, int nums1_low, int nums1_high, int nums2_low, int nums2_high) {
		int n = nums1_high - nums1_low + 1;
		int m = nums2_high - nums2_low + 1;
		double median1, median2;

		if (n == 0)
		{
			if (m % 2)
				return nums2[nums2_low + m / 2];
			else
				return 1.0 * (nums2[nums2_low + m / 2 - 1] + nums2[nums2_low + m / 2]) / 2;
		}

		if (m == 0)
		{
			if (n % 2)
				return nums1[nums1_low + n / 2];
			else
				return 1.0 * (nums1[nums1_low + n / 2 - 1] + nums1[nums1_low + n / 2]) / 2;
		}

		if (n == 1 && m == 1)
			return 1.0 * (nums1[nums1_low] + nums2[nums2_low]) / 2;

		if (n % 2)
		{
			median1 = nums1[nums1_low + n / 2];
		}
		else
		{
			median1 = 1.0 * (nums1[nums1_low + n / 2 - 1] + nums1[nums1_low + n / 2]) / 2;
		}

		if (m % 2)
		{
			median2 = nums2[nums2_low + m / 2];
		}
		else
		{
			median2 = 1.0 * (nums2[nums2_low + m / 2 - 1] + nums2[nums2_low + m / 2]) / 2;
		}

		if (median1 > median2)
		{
			if (n % 2 && m % 2)
				return findMedian(nums1, nums2, nums1_low, nums1_low + (n - 1) / 2 - 1, nums2_low + m / 2 + 1, nums2_high);
			else if (n % 2 && (m % 2 == 0))
				return findMedian(nums1, nums2, nums1_low, nums1_low + (n - 1) / 2 - 1, nums2_low + m / 2, nums2_high);
			else if ((n % 2 == 0) && m % 2)
				return findMedian(nums1, nums2, nums1_low, nums1_low + (n - 1) / 2, nums2_low + m / 2 + 1, nums2_high);
			else
			{
				if (nums1[nums1_low + n / 2 - 1] >= nums2[nums2_low + m / 2])
					return findMedian(nums1, nums2, nums1_low, nums1_low + (n - 1) / 2, nums2_low + m / 2, nums2_high);
				else
					return median1;
			}

		}
		else if (median1 < median2)
		{
			if (n % 2 && m % 2)
				return  findMedian(nums1, nums2, nums1_low + n / 2 + 1, nums1_high, nums2_low, nums2_low + (m - 1) / 2 - 1);
			else if (n % 2 && (m % 2 == 0))
				return  findMedian(nums1, nums2, nums1_low + n / 2 + 1, nums1_high, nums2_low, nums2_low + (m - 1) / 2);
			else if ((n % 2 == 0) && m % 2)
				return  findMedian(nums1, nums2, nums1_low + n / 2, nums1_high, nums2_low, nums2_low + (m - 1) / 2 - 1);
			else
			{
				if (nums2[nums2_low + m / 2 - 1] >= nums1[nums1_low + n / 2])
					return  findMedian(nums1, nums2, nums1_low + n / 2, nums1_high, nums2_low, nums2_low + (m - 1) / 2);
				else
					return median2;
			}


		}
		else
			return median1;
	}
};