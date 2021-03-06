﻿/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1*/

class Solution {
public:
	int search(vector<int>& nums, int target)
	{

		int n = nums.size();
		if (n == 0)
			return -1;

		int start = 0;
		int end = n - 1;
		int mid;
		while (start < end)
		{
			mid = start + (end - start) / 2;

			if (nums[mid] > nums[end])
				start = mid + 1;
			else
				end = mid;
		}

		int i = 0;
		int j = n - 1;

		if (target >= nums[start] && target <= nums[j])
			i = start;
		else
			j = start;

		while (i <= j)
		{
			mid = i + (j - i) / 2;
			if (target == nums[mid])
				return mid;
			else if (target > nums[mid])
				i = mid + 1;
			else
				j = mid - 1;
		}
		return -1;
	}
};