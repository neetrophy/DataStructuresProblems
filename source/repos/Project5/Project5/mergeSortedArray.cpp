﻿/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.
Example :

	Input :
	nums1 = [1, 2, 3, 0, 0, 0], m = 3
	nums2 = [2, 5, 6], n = 3

	Output : [1, 2, 2, 3, 5, 6]
*/
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int k = nums1.size() - 1;
		m--; n--;
		if (m < 0) {
			while (n >= 0 && k >= 0) {
				nums1[k--] = nums2[n--];
			}
			return;
		}
		while (m >= 0 && n >= 0) {
			nums1[k--] = nums1[m] >= nums2[n] ? nums1[m--] : nums2[n--];
		}
		while (m >= 0) {
			nums1[k--] = nums1[m--];
		}
		while (n >= 0) {
			nums1[k--] = nums2[n--];
		}
	}
};