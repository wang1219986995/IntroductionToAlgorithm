// IntroductionToAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include "src/Algorithms/sort_algorithms/insert_sort.h"
#include "src/Algorithms/sort_algorithms/selection_sort.h"
#include "src/Algorithms/sort_algorithms/merge_sort.h"
using namespace std;

static int count = 0;

void merge(vector<int> nums, int left, int mid, int right) {
	vector<int> temp(right - left + 1);
	int current = 0;
	int left_current = left, right_current = mid + 1;
	while (left_current <= mid && right_current <= right) {
		if (nums[left_current] <= nums[right_current])  temp[current++] = nums[left_current++];
		else {
			count += mid - left_current + 1;
			temp[current++] = nums[right_current++];
		}
	}
	if (left_current != mid && right_current == right) {
		while (left_current != mid)  temp[current++] = nums[left_current++];
	}
	if (right_current != right && left_current == mid) {
		while (right_current != right)  temp[current++] = nums[right_current++];
	}
	cout << left << "  " << right << "  " << count << endl;
	cout << count;
	copy(temp.begin(), temp.end(), nums.begin() + left);
}

void merge_sort(vector<int> nums, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(nums, left, mid);
		merge_sort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}


int reversePairs(vector<int>& nums) {
	merge_sort(nums, 0, nums.size() - 1);
	return count;
}

int main()
{
	vector<int> a{ 2,4,5,8,1,80,45,73,17 };
	reversePairs(a);
	cout << count << endl;
}

